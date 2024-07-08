#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global Declarations
#define MAX_QNODES 100
typedef struct node {
    struct node *l_child;
    int data;
    struct node *r_child;
} node;
node *root = NULL, *Q[MAX_QNODES];
int front = 0, rear = 0, count = 0, bin_tree_level = 0;

// Function Prototypes
// 1. Helpers
void reset_Q(node *);
void level_order_ops(node *);
// 2. Operations
node *ins_node(node *, int);
node *del_node(node *, int);
bool search_bin_tree(node *, int);
//    -- Traversals
void   pre_order(node *);
void    in_order(node *);
void  post_order(node *);
//    -- Display Binary Tree
void display_bin_tree(node *);

int main(void)
{
    int choice;

    while (true)
    {
        printf("Binary Search Tree (BST) Operations\n");
        printf("\n");
        printf("Choices:\n1. Insert Node\n2. Delete Node\n3. Display BST Traversals\n4. Exit\n5. Search BST\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int value;

                printf("Enter integer value to insert: ");
                scanf("%d",&value);

                root = ins_node(root, value);
                display_bin_tree(root);
                break;
            }
            case 2:
            {
                int value;

                printf("Enter integer value to delete: ");
                scanf("%d",&value);

                root = del_node(root, value);
                display_bin_tree(root);
                break;
            }
            case 3:
                display_bin_tree(root);
                break;
            case 4:
                exit(0);
                break;
            case 5:
            {
                int value, flag;

                printf("Enter integer value to delete: ");
                scanf("%d",&value);

                flag = search_bin_tree(root, value);
                if (flag == true)
                    printf("Searched Node: %d FOUND in the BST at Level [%d].\n\n", value, bin_tree_level);
                else
                    printf("Searched Node: %d NOT FOUND in the BST.\n\n", value);
                bin_tree_level = 0;
                break;
            }
            default:
                printf("Invalid Choice...!!\n\n");
        }
    }

    return 0;
}

void reset_Q(node *bin_tree)
{
    front = rear = count = 0;
    Q[rear++] = bin_tree;
}

void level_order_ops(node *bin_tree)
{
    node *deepest_rightmost_node;

    reset_Q(bin_tree);

    while (front != rear)
    {
        deepest_rightmost_node = Q[front++];
        if (bin_tree != NULL)
        {
            printf("%d ", deepest_rightmost_node->data);
            if (deepest_rightmost_node->l_child)
                Q[rear++] = deepest_rightmost_node->l_child;
            if (deepest_rightmost_node->r_child)
                Q[rear++] = deepest_rightmost_node->r_child;
        }
        else
            printf("None - ZERO Binary Tree nodes");
    }
}

node *ins_node(node *bin_tree, int val_2_insert)
{
    // New Node
    node* new_node = (node *) malloc(sizeof(node));
    new_node->l_child = NULL;
    new_node->data = val_2_insert;
    new_node->r_child = NULL;

    if (bin_tree == NULL)
        bin_tree = new_node;
    else if (val_2_insert > bin_tree->data)
        bin_tree->r_child = ins_node(bin_tree->r_child, val_2_insert);
    else
        bin_tree->l_child = ins_node(bin_tree->l_child, val_2_insert);

    return bin_tree;
}

bool search_bin_tree(node *bin_tree, int val_2_search)
{
    bool flag = false;

    if (bin_tree == NULL)
        return flag;
    else if (val_2_search == bin_tree->data)
    {
        flag = true;
        return flag;
    }
    else
    {
        bin_tree_level++;
        if (val_2_search > bin_tree->data)
            return search_bin_tree(bin_tree->r_child, val_2_search);
        else
            return search_bin_tree(bin_tree->l_child, val_2_search);
    }
}

node *find_minimum(node *bin_tree)
{
    if (bin_tree == NULL)
        return NULL;
    else if (bin_tree->l_child != NULL)
        return find_minimum(bin_tree->l_child);
    return bin_tree;
}

node *del_node(node *bin_tree, int val_2_del)
{
    node *deepest_rightmost_node = NULL, *node_2_del = NULL;

    if (bin_tree == NULL)
        return NULL;
    else if (val_2_del > bin_tree->data)
        bin_tree->r_child = del_node(bin_tree->r_child, val_2_del);
    else if (val_2_del < bin_tree->data)
        bin_tree->l_child = del_node(bin_tree->l_child, val_2_del);
    else
    {
        if (bin_tree->l_child == NULL || bin_tree->r_child == NULL)
        {
            if (bin_tree->l_child == NULL)
                node_2_del = bin_tree->r_child;
            else if (bin_tree->r_child == NULL)
                node_2_del = bin_tree->l_child;
            free(bin_tree);
            return node_2_del;
        }
        else
        {
            node_2_del = find_minimum(bin_tree->r_child);
            bin_tree->data = node_2_del->data;
            bin_tree->r_child = del_node(bin_tree->r_child, node_2_del->data);
        }
    }
    return bin_tree;
}

void pre_order(node *bin_tree)
{
    // Data >> Left-SubTree >> Right-SubTree
    if (bin_tree != NULL)
    {
        printf("%d ", bin_tree->data);
        pre_order(bin_tree->l_child);
        pre_order(bin_tree->r_child);
    }
}

void in_order(node *bin_tree)
{
    // Left-SubTree >> Data >> Right-SubTree
    if (bin_tree != NULL)
    {
        in_order(bin_tree->l_child);
        printf("%d ", bin_tree->data);
        in_order(bin_tree->r_child);
    }
}

void post_order(node *bin_tree)
{
    // Left-SubTree >> Right-SubTree >> Data
    if (bin_tree != NULL)
    {
        post_order(bin_tree->l_child);
        post_order(bin_tree->r_child);
        printf("%d ", bin_tree->data);
    }
}

void display_bin_tree(node *bin_tree)
{
    printf("Binary Search Tree Traversals: ");
    printf("\n      PRE-Order: ");   pre_order(bin_tree);
    printf("\n       IN-Order: ");    in_order(bin_tree);
    printf("\n     POST-Order: ");  post_order(bin_tree);
    printf("\n    LEVEL-Order: "); level_order_ops(bin_tree);
    printf("\n\n\n");
}
