#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACKSIZE 3

// Function Prototypes
void insert_elem(int insert_value);
void display_stack();
void delete_elem();
// Head
int count = 0, *rear = &count, arr[STACKSIZE];

int main(void)
{
    int choice;

    while (true)
    {
        printf("Stack (L.I.F.O.)\n");
        printf("\n");
        printf("Choices:\n1. Insert Element\n2. Delete Latest Element\n3. Show Stack\n4. Exit\n");
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
                display_stack();
                break;
            }
            case 2:
                delete_elem();
                display_stack();
                break;
            case 3:
                display_stack();
                break;
            case 4:
                exit(0);
                break;
        }
    }

    return 0;
}

void display_stack()
{
    if (count == 0)
        printf("Stack is empty. .. ...");
    else
        for (int i = 0; i < STACKSIZE; i++)
            printf("%d, ", arr[i]);

    printf("\n\n");
}

void insert_elem(int insert_value)
{
    if (0 <= count && count < STACKSIZE)
    {
        arr[*rear] = insert_value;
        count++;
    }
    else
        printf("Stack is at Capacity. (Over-Flow NOT-ALLOWED)\n");
}

void delete_elem()
{
    if (0 < count && count <= STACKSIZE)
    {
        count--;
        arr[*rear] = 0;

    }
    else
        printf("Stack is empty. (Under-Flow NOT-ALLOWED)\n");
}
