#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QSIZE 3

// Function Prototypes
void display_arr();
void delete_elem();
void insert_elem(int elem_2_insert);
// Head
int front = 0, rear = 0, count = 0, arr[QSIZE];

int main(void)
{
    int choice;

    while (true)
    {
        printf("Array-based Rotating Queue (F.I.F.O.) [Size: %d]\n", QSIZE);
        printf("\n");
        printf("Choices:\n1. Insert Element\n2. Delete Element\n3. Show Array-based Rotating Queue\n4. Exit\n");
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
        printf("Array-based Rotating Queue is empty. .. ...");
    else
        for (int i = 0; i < QSIZE; i++)
            printf("%d, ", arr[i]);

    printf("\n\n");
}

void delete_elem()
{
    if (0 < count && count <= QSIZE)
    {
        arr[front] = 0;
        front = (front + 1) % QSIZE;
        count--;
    }
    else
        printf("Array-based Rotating Queue is empty. (Under-Flow NOT-ALLOWED)\n");
}

void insert_elem(int elem_2_insert)
{
    if (0 <= count && count < QSIZE)
    {
        arr[rear] = elem_2_insert;
        rear = (rear + 1) % QSIZE;
        count++;
    }
    else
        printf("Array-based Rotating Queue is at Capacity. (Over-Flow NOT-ALLOWED)\n");
}
