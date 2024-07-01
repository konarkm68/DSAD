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
int front = 0, rear = 0, count = 0;

// Function Prototypes
void reset_Q();
node *insert_node(node *, int);
node *del_node(node *, int); void del_node_deepest(node *, node *);
void   pre_order(node *);
void    in_order(node *);
void  post_order(node *);
node *level_order(node *, bool, int);
void display_bin_tree(node *);

int main(void)
{
    // Insertion of nodes
    root = insert_node(root, 1);
    root = insert_node(root, 2);
    root = insert_node(root, 3);
    root = insert_node(root, 4);

    printf(" Initial "); display_bin_tree(root);

    printf("\n\n");

    root = del_node(root, 4);

    printf("Terminal "); display_bin_tree(root);

    return 0;
}

void reset_Q()
{
    front = rear = count = 0;
}

node *insert_node(node *parent_node, int val_2_insert)
{
    // New Node
    node* new_node = (node *) malloc(sizeof(node));
    new_node->l_child = NULL;
    new_node->data = val_2_insert;
    new_node->r_child = NULL;

    if (parent_node == NULL)
    {
        parent_node = new_node;
        return parent_node;
    }
    // Queue to traverse the tree and find the position to insert_node the node
    reset_Q();
    Q[rear++] = parent_node;
    while (front != rear)
    {
        node* temp = Q[front++];
        // Insert node as the l_child child of the parent node
        if (temp->l_child == NULL)
        {
            temp->l_child = new_node;
            break;
        }
        // If the l_child child is not null, push it to the Q
        else
            Q[rear++] = temp->l_child;
        // Insert node as the r_child child of parent node
        if (temp->r_child == NULL)
        {
            temp->r_child = new_node;
            break;
        }
        // If the r_child child is not null, push it to the Q
        else
            Q[rear++] = temp->r_child;
        }
        return parent_node;
}
/* Function to delete the given deepest node (d_node) in binary tree */
void del_node_deepest(node* parent_node, node* d_node)
{
    reset_Q();
    Q[rear++] = parent_node;
    // Do level order traversal until last node
    node* temp;
    while (front != rear)
    {
        temp = Q[front++];
        if (temp == d_node)
        {
            temp = NULL;
            free(d_node);
            return;
        }
        if (temp->r_child)
        {
            if (temp->r_child == d_node)
            {
                temp->r_child = NULL;
                free(d_node);
                return;
            }
            else
                Q[rear++] = temp->r_child;
        }
        if (temp->l_child)
        {
            if (temp->l_child == d_node)
            {
                temp->l_child = NULL;
                free(d_node);
                return;
            }
            else
            Q[rear++] = temp->l_child;
        }
    }
}
/* Function to delete element in binary tree */
node* del_node(node* parent_node, int key)
{
    if (!parent_node)
        return NULL;
    if (parent_node->l_child == NULL && parent_node->r_child == NULL)
    {
        if (parent_node->data == key)
            return NULL;
        else
            return parent_node;
    }

    node *temp = NULL, *key_node = NULL;
    // Do level order traversal to find deepest node (temp) and node to be deleted (key_node)
    reset_Q();
    Q[rear++] = parent_node;
    while (front != rear)
    {
        temp = Q[front++];
        if (temp->l_child)
            Q[rear++] = temp->l_child;
        if (temp->r_child)
            Q[rear++] = temp->r_child;
        if (temp->data == key)
            key_node = temp;
    }
    if (key_node != NULL)
    {
        int x = temp->data;
        key_node->data = x;
        del_node_deepest(parent_node, temp);
    }
    return parent_node;
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

node *level_order(node *bin_tree, bool en_del_node, int node_2_del)
{
    node *temp = NULL;

    if (bin_tree != NULL)
    {
        reset_Q();
        Q[rear++] = bin_tree;
        while (front != rear)
        {
            temp = Q[front++];
            printf("%d ", temp->data);
            // Push l_child child in the Q
            if (temp->l_child)
                Q[rear++] = temp->l_child;
            // Push r_child child in the Q
            if (temp->r_child)
                Q[rear++] = temp->r_child;
            if (en_del_node == true)
                if (temp->data == node_2_del)
                    return temp;
        }
    }
    return temp;
}

void display_bin_tree(node *bin_tree)
{
    printf("Binary Tree Traversal: ");
    printf("\n      PRE-Order: ");   pre_order(bin_tree);
    printf("\n       IN-Order: ");    in_order(bin_tree);
    printf("\n     POST-Order: ");  post_order(bin_tree);
    printf("\n    LEVEL-Order: "); level_order(bin_tree, false, 0);
    printf("\n");
}
