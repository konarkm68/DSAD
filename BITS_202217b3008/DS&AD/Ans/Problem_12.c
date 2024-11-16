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
node *bin_tree = NULL, *Q[MAX_QNODES];
int front = 0, rear = 0, count = 0;

// Function Prototypes
// 1. Helpers
void reset_Q(node *);
void level_order_ops(node *, bool, bool, node *, bool, node *);
// 2. Operations
node *ins_node(node *, int);
node *del_node(node *, int);
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
        printf("Binary Tree Operations\n");
        printf("\n");
        printf("Choices:\n1. Insert Node\n2. Delete Node\n3. Display Binary Tree Traversals\n4. Exit\n");
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

                bin_tree = ins_node(bin_tree, value);
                display_bin_tree(bin_tree);
                break;
            }
            case 2:
            {
                int value;

                printf("Enter integer value to delete: ");
                scanf("%d",&value);

                bin_tree = del_node(bin_tree, value);
                display_bin_tree(bin_tree);
                break;
            }
            case 3:
                display_bin_tree(bin_tree);
                break;
            case 4:
                exit(0);
                break;
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

void level_order_ops(node *bin_tree, bool en_trvrs, bool en_ins, node *node_2_ins, bool en_del, node *node_2_del)
{
    node *deepest_rightmost_node;

    reset_Q(bin_tree);

    while (front != rear)
    {
        deepest_rightmost_node = Q[front++];
        if (en_trvrs == true)
        {
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

        else if (en_ins == true)
        {
            if (deepest_rightmost_node->l_child == NULL)
            {
                deepest_rightmost_node->l_child = node_2_ins;
                break;
            }
            else
                Q[rear++] = deepest_rightmost_node->l_child;
            if (deepest_rightmost_node->r_child == NULL)
            {
                deepest_rightmost_node->r_child = node_2_ins;
                break;
            }
            else
                Q[rear++] = deepest_rightmost_node->r_child;
        }

        else if (en_del == true)
        {
            if (deepest_rightmost_node == node_2_del)
            {
                deepest_rightmost_node = NULL;
                free(node_2_del);
                return;
            }
            if (deepest_rightmost_node->r_child)
            {
                if (deepest_rightmost_node->r_child == node_2_del)
                {
                    deepest_rightmost_node->r_child = NULL;
                    free(node_2_del);
                    return;
                }
                else
                    Q[rear++] = deepest_rightmost_node->r_child;
            }
            if (deepest_rightmost_node->l_child)
            {
                if (deepest_rightmost_node->l_child == node_2_del)
                {
                    deepest_rightmost_node->l_child = NULL;
                    free(node_2_del);
                    return;
                }
                else
                    Q[rear++] = deepest_rightmost_node->l_child;
            }
        }
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
    {
        bin_tree = new_node;
        return bin_tree;
    }

    level_order_ops(bin_tree, false, true, new_node, false, NULL);
    return bin_tree;
}

node *del_node(node *bin_tree, int val_2_del)
{
    node *deepest_rightmost_node = NULL, *node_2_del = NULL;

    if (bin_tree == NULL)
        return NULL;

    if (bin_tree->l_child == NULL && bin_tree->r_child == NULL)
    {
        if (bin_tree->data == val_2_del)
        {
            free(bin_tree);
            return NULL;
        }
        else
            return bin_tree;
    }

    reset_Q(bin_tree);
    while (front != rear)
    {
        deepest_rightmost_node = Q[front++];
        if (deepest_rightmost_node->l_child)
            Q[rear++] = deepest_rightmost_node->l_child;
        if (deepest_rightmost_node->r_child)
            Q[rear++] = deepest_rightmost_node->r_child;
        if (deepest_rightmost_node->data == val_2_del)
            node_2_del = deepest_rightmost_node;
    }
    if (node_2_del != NULL)
    {
        int val_2_del = deepest_rightmost_node->data;
        node_2_del->data = val_2_del;
        level_order_ops(bin_tree, false, false, NULL, true, deepest_rightmost_node);
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
    printf("Binary Tree Traversals: ");
    printf("\n      PRE-Order: ");   pre_order(bin_tree);
    printf("\n       IN-Order: ");    in_order(bin_tree);
    printf("\n     POST-Order: ");  post_order(bin_tree);
    printf("\n    LEVEL-Order: "); level_order_ops(bin_tree, true, false, NULL, false, NULL);
    printf("\n\n\n");
}
