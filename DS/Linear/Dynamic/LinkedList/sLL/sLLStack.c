#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function Prototypes
void display_sLL();
void delete_elem();
void insert_elem(int elem_2_insert);

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
        printf("Singly-Linked-List OR SLL Stack (L.I.F.O.)\n");
        printf("\n");
        printf("Choices:\n1. Insert Element\n2. Delete Element\n3. Show SLL Stack\n4. Exit\n");
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

                insert_elem(value);
                display_sLL();
                break;
            }
            case 2:
                delete_elem();
                display_sLL();
                break;
            case 3:
                display_sLL();
                break;
            case 4:
                free(head);
                exit(0);
                break;
        }
    }

    return 0;
}

void display_sLL()
{
    if (head == NULL)
        printf("SLL Stack is empty. .. ...");
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

void delete_elem()
{
    if (head != NULL)
    {
        struct node *temp = head;
        head = (*head).addl_nodes;

        free(temp);
    }
}

void insert_elem(int elem_2_insert)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    (*new_node).data = elem_2_insert;
    (*new_node).addl_nodes = NULL;

    if (head == NULL)
        head = new_node;
    else
    {
        (*new_node).addl_nodes = head;
        head = new_node;
    }
}
