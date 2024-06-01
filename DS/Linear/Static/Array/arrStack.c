#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACKSIZE 3

// Function Prototypes
void display_arr();
void delete_elem();
void insert_elem(int elem_2_insert);
// Head
int count = 0, *rear = &count, arr[STACKSIZE];

int main(void)
{
    int choice;

    while (true)
    {
        printf("Array-based Circular Stack (L.I.F.O.)\n");
        printf("\n");
        printf("Choices:\n1. Insert Element\n2. Delete Element\n3. Show Array-based Circular Stack\n4. Exit\n");
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
                display_arr();
                break;
            }
            case 2:
                delete_elem();
                display_arr();
                break;
            case 3:
                display_arr();
                break;
            case 4:
                exit(0);
                break;
        }
    }

    return 0;
}

void display_arr()
{
    if (count == 0)
        printf("Array-based Circular Stack is empty. .. ...");
    else
        for (int i = 0; i < STACKSIZE; i++)
            printf("%d, ", arr[i]);

    printf("\n\n");
}

void delete_elem()
{
    if (0 < count && count <= STACKSIZE)
    {
        count--;
        arr[*rear] = 0;

    }
    else
        printf("Array-based Circular Stack is empty. (Under-Flow NOT-ALLOWED)\n");
}

void insert_elem(int elem_2_insert)
{
    if (0 <= count && count < STACKSIZE)
    {
        arr[*rear] = elem_2_insert;
        count++;

    }
    else
        printf("Array-based Circular Stack is at Capacity. (Over-Flow NOT-ALLOWED)\n");
}
