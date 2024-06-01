#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QSIZE 3

// Function Prototypes
void insert_elem(int insert_value);
void display_queue();
void delete_elem();
// Head
int front = 0, rear = 0, count = 0, arr[QSIZE];

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
                exit(0);
                break;
        }
    }

    return 0;
}

void display_queue()
{
    if (count == 0)
        printf("Queue is empty. .. ...");
    else
        for (int i = 0; i < QSIZE; i++)
            printf("%d, ", arr[i]);
        //printf("\nFront: %d", front);
        //printf("\n Rear: %d", rear);
        //printf("\nCount: %d", count);

    printf("\n\n");
}

void insert_elem(int insert_value)
{
    if (0 <= count && count < QSIZE)
    {
        arr[rear] = insert_value;
        rear = (rear + 1) % QSIZE;
        count++;
    }
    else
        printf("Queue is at Capacity. (Over-Flow NOT-ALLOWED)\n");
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
        printf("Queue is empty. (Under-Flow NOT-ALLOWED)\n");
}
