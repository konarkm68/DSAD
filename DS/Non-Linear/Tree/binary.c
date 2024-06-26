#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void insert_elem(struct node *head, int data);
void in_order();
void pre_order();
void post_order();

// Node Structure
struct node
{
  struct node *left_st;
  int data;
  struct node *right_st;
};
// Root
struct node *root = NULL;

int main()
{
  insert_elem(root, 50);
  insert_elem(root, 30);
  insert_elem(root, 20);
  insert_elem(root, 40);
  insert_elem(root, 70);
  insert_elem(root, 60);
  insert_elem(root, 80);

  printf("In-Order traversal: ");
  in_order();
  printf("\n");

  printf("Pre-Order traversal: ");
  pre_order();
  printf("\n");

  printf("Post-Order traversal: ");
  post_order();
  printf("\n");

  return 0;
}

void insert_elem(struct node *head, int insert_value)
{
    if (head == NULL)
    {
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = insert_value;
        new_node->left_st = NULL;
        new_node->right_st = NULL;
        head = new_node;
    }
    else
    {
        if (insert_value < current->data)
            insert_elem(current->left_st, insert_value);  // Recursive call on left subtree
        else
            insert_elem(current->right_st, insert_value);  // Recursive call on right subtree
    }
}

void in_order()
{
    // Left sub-tree, Root, Right sub-tree
    if (root != NULL)
    {
        in_order(root->left_st);
        printf("%c ", root->data);
        in_order(root->right_st);
    }
}

void pre_order()
{
    // Root, Left sub-tree, Right sub-tree
    if (root != NULL)
    {
        printf("%c ", root->data);
        pre_order(root->left_st);
        pre_order(root->right_st);
    }
}

void post_order()
{
    // Left sub-tree, Right sub-tree, Root
    if (root != NULL)
    {
        post_order(root->left_st);
        post_order(root->right_st);
        printf("%c ", root->data);
    }
}
