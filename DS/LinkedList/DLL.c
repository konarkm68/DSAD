#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function Prototypes
void insert_elem(int insert_value);
void display_dll();
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
        printf("Doubly-Linked-List OR DLL (L.I.F.O.)\n");
        printf("\n");
        printf("Choices:\n1. Insert Element\n2. Delete Latest Element\n3. Show SLL\n4. Exit\n");
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
                display_dll();
                break;
            }
            case 2:
                delete_elem();
                display_dll();
                break;
            case 3:
                display_dll();
                break;
            case 4:
                free(head);
                exit(0);
                break;
        }
    }

    return 0;
}

void display_dll()
{
    if (head == NULL)
        printf("SLL is empty. .. ...");
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
        (*new_node).addl_nodes = head;
        head = new_node;
    }
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
