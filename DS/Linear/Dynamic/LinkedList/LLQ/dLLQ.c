#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function Prototypes
void insert_elem(int insert_value);
void display_queue();
void delete_elem();

// Node Structure
struct node
{
    struct node *l_nodes;
    int data;
    struct node *r_nodes;
};
// Head
struct node *head = NULL;

int main(void)
{
    int choice;

    while (true)
    {
        printf("Queue (F.I.F.O.)\n");
        printf("\n");
        printf("Choices:\n1. Insert Element\n2. Delete First Element\n3. Show Queue\n4. Exit\n");
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
                display_queue();
                break;
            }
            case 2:
                delete_elem();
                display_queue();
                break;
            case 3:
                display_queue();
                break;
            case 4:
                free(head);
                exit(0);
                break;
        }
    }

    return 0;
}

void display_queue()
{
    if (head == NULL)
        printf("Queue is empty. .. ...");
    else
    {
        int counter = 0;
        struct node *temp = head;

        while((*temp).r_nodes != NULL)
        {
            printf("[%d, ", temp->data);
            temp = (*temp).r_nodes;
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

    (*new_node).l_nodes = NULL;
    (*new_node).data = insert_value;
    (*new_node).r_nodes = NULL;

    if (head == NULL)
        head = new_node;
    else
    {
        struct node *temp = head;

        while ((*temp).r_nodes != NULL)
            temp = (*temp).r_nodes;
        (*temp).r_nodes = new_node;
    }
}

void delete_elem()
{
    if (head != NULL)
    {
        struct node *temp = head;

        head = (*head).r_nodes;
        free(temp);
    }
}
