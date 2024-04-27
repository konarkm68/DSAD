#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function Prototypes
void insert_elem(int insert_value);
void display_stack();
void delete_elem();

// Node Structure
struct node
{
    int data;
    struct node *addl_nodes;
};
// Head
struct node *head = NULL;

int main(void)
{
    int choice;

    while (true)
    {
        printf("Stack (L.I.F.O.)\n\nChoices:\n1. Insert Element\n2. Delete Latest Element\n3. Show Stack\n4. Exit\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int value;

                printf("Enter integer value to insert: ");
                scanf("%d",&value);

                insert_elem(value);
                break;
            }
            case 2:
                delete_elem();
                break;
            case 3:
                display_stack();
                break;
            case 4:
                free(head);
                exit(0);
                break;
        }
    }

    return 0;
}

void display_stack()
{
    if (head == NULL)
        printf("List is empty. .. ...");
    else
    {
        int counter = 0;
        struct node *temp = head;

        while((*temp).addl_nodes != NULL)
        {
            printf("[%d, ", temp->data);
            temp = (*temp).addl_nodes;
            counter++;
        }
        printf("[%d, _", (*temp).data);
        while (counter >= 0)
        {
            printf("]");
            counter--;
        }
    }

    printf("\n\n");
}

void insert_elem(int insert_value)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    (*new_node).data = insert_value;
    (*new_node).addl_nodes = NULL;

    if (head == NULL)
        head = new_node;
    else
    {
        struct node *temp = head;

        while ((*temp).addl_nodes != NULL)
            temp = (*temp).addl_nodes;
        (*temp).addl_nodes = new_node;
    }

    display_stack();
}

void delete_elem()
{
    if (head != NULL)
    {
        struct node *temp = head, *new_head = NULL;

        while ((*temp).addl_nodes != NULL)
        {
            new_head = temp;
            temp = (*temp).addl_nodes;
        }
        if (new_head != NULL)
            (*new_head).addl_nodes = NULL;
        else
            head = NULL;

        free(temp);
    }

    display_stack();
}
