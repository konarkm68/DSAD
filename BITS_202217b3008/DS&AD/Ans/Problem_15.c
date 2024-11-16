#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Global Declarations
#define MAX_HASH_MAPPED_DICT_NODES 25
#define MAX_STR_CHARS 64
typedef struct dict_node {
    char *key;
    char *value;
    struct dict_node *addl_dict_nodes;
} dict_node;
typedef struct hash_mapped_dict {
    int num_dict_nodes;
    dict_node **dict_nodes;
} hash_mapped_dict;

// Function Prototypes
 int hash_mapping_func(char *);
void init_hash_mapped_dict(hash_mapped_dict *);
void ins_dict_node(hash_mapped_dict *, char *, char *);
void del_dict_node(hash_mapped_dict *, char *);
void search_dict_node(hash_mapped_dict *, char *);

int main(void)
{
    hash_mapped_dict *dict = (hash_mapped_dict *) malloc(sizeof(hash_mapped_dict));
    init_hash_mapped_dict(dict);

    ins_dict_node(dict, "Active", "Aman");
    ins_dict_node(dict, "Active", "Anjali");
    ins_dict_node(dict, "Dutiful", "Deepak");

    printf("\n");
    search_dict_node(dict, "Active");
    search_dict_node(dict, "Dutiful");
    search_dict_node(dict, "Handsome");

    printf("\n");
    del_dict_node(dict, "Active");
    search_dict_node(dict, "Active");
    search_dict_node(dict, "Dutiful");
    
    return 0;
}

void init_hash_mapped_dict(struct hash_mapped_dict* dict)
{
    dict->num_dict_nodes = 0;
    dict->dict_nodes = (dict_node **) malloc(sizeof(dict_node *) * MAX_HASH_MAPPED_DICT_NODES);
}

int hash_mapping_func(char* key)
{
    int dict_node_ind, sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); i++)
    {
        // sum = sum + (ascii value of char * (primeNumber ^ x))... where x = 1, 2, 3....n
        sum = ((sum % MAX_HASH_MAPPED_DICT_NODES) + (((int)key[i]) * factor) % MAX_HASH_MAPPED_DICT_NODES) % MAX_HASH_MAPPED_DICT_NODES;
        // factor = factor * prime number....(prime number) ^ x
        factor = ((factor % sizeof(int16_t)) * (31 % sizeof(int16_t))) % sizeof(int16_t);
    }
    dict_node_ind = sum;
    return dict_node_ind;
}

void ins_dict_node(hash_mapped_dict *dict, char *key, char *value)
{
    int dict_node_ind = hash_mapping_func(key);

    dict_node *new_dict_node = (dict_node *) malloc(sizeof(dict_node));
    new_dict_node->key = key;
    new_dict_node->value = value;
    new_dict_node->addl_dict_nodes = NULL;

    // Bucket index is empty....no collision
    if (dict->dict_nodes[dict_node_ind] == NULL)
        dict->dict_nodes[dict_node_ind] = new_dict_node;
    else
    {
        new_dict_node->addl_dict_nodes = dict->dict_nodes[dict_node_ind];
        dict->dict_nodes[dict_node_ind] = new_dict_node;
    }
    printf("Hash-Mapped Dictionary Node: dict[\"%s\"] = \"%s\" INSERTED!\n", new_dict_node->key, new_dict_node->value);
    return;
}

void del_dict_node (struct hash_mapped_dict* dict, char* key)
{
    // Getting bucket index for the
    // given key
    int dict_node_ind = hash_mapping_func(key);
    struct dict_node* prevNode = NULL;

    // Allocate memory for a dynamic message string (adjust size as needed)
    int max_msg_len = MAX_STR_CHARS * MAX_STR_CHARS; // Account for key, "Value:" and potential multiple values
    char *msg = (char *) malloc(sizeof(char) * max_msg_len);
    msg[0] = '\0'; // Initialize to empty string
    char value_str[MAX_STR_CHARS];

    // Points to the head of
    // linked list present at
    // bucket index
    struct dict_node* currNode = dict->dict_nodes[dict_node_ind];
    while (currNode != NULL)
    {
        // Key is matched at del_dict_node this
        // dict_node from linked list
        if (strcmp(key, currNode->key) == 0)
        {
            // Head dict_node
            // deletion
            if (currNode == dict->dict_nodes[dict_node_ind])
                dict->dict_nodes[dict_node_ind] = currNode->addl_dict_nodes;
            else
                prevNode->addl_dict_nodes = currNode->addl_dict_nodes;

            snprintf(value_str, sizeof(value_str), "\"%s\", ", currNode->value); // Use snprintf for safer formatting
            strncat(msg, value_str, max_msg_len - strlen(msg) - 1); // Append value with bounds checking
            free(currNode);
        }
        prevNode = currNode;
        currNode = currNode->addl_dict_nodes;
    }
    printf("Hash-Mapped Dictionary Node DELETED!: dict[\"%s\"] = %s\n", key, msg);
    return;
}

void search_dict_node(struct hash_mapped_dict *dict, char *key)
{
    bool flag = false;
    int dict_node_ind = hash_mapping_func(key);

    // Allocate memory for a dynamic message string (adjust size as needed)
    int max_msg_len = MAX_STR_CHARS * MAX_STR_CHARS; // Account for key, "Value:" and potential multiple values
    char *msg = (char *) malloc(sizeof(char) * max_msg_len);
    msg[0] = '\0'; // Initialize to empty string
    char value_str[MAX_STR_CHARS];

    dict_node *dict_head = dict->dict_nodes[dict_node_ind];
    while (dict_head != NULL)
    {
        if (strcmp(dict_head->key, key) == 0)
        {
            if (flag == false)
                printf("Value/s FOUND for dict[\"%s\"] = ", dict_head->key);
            flag = true;
            // Concatenate value(s) to message (limit to a few values)
            snprintf(value_str, sizeof(value_str), "\"%s\", ", dict_head->value); // Use snprintf for safer formatting
            strncat(msg, value_str, max_msg_len - strlen(msg) - 1); // Append value with bounds checking
        }
        dict_head = dict_head->addl_dict_nodes;
    }

    if (flag == false)
        printf("Value NOT FOUND for dict[\"%s\"].\n", key);
    else
        printf("%s\n", msg);
}
