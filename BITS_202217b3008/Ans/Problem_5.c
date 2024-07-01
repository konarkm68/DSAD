#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global Declarations
#define QSIZE 3
int front = 0, rear = -1, count = 0, arr[QSIZE];

// Function Prototypes
void display_arr();
void search_elem(int elem_2_search);
 int delete_elem();
void insert_elem(int elem_2_insert);

int main(void)
{
    int choice;

    while (true)
    {
        printf("Array-based Rotating Queue (F.I.F.O.) [Size: %d]\n", QSIZE);
        printf("\n");
        printf("Choices:\n1. Insert Element\n2. Delete Element\n3. Show Array-based Rotating Queue\n4. Exit\n"); //5. Search Element\n");
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
            {
                int del_elem = delete_elem();
                if (del_elem != -11111)
                    printf("The deleted element is: %d\n", del_elem);
                display_arr();
                break;
            }
            case 3:
                display_arr();
                break;
            case 4:
                exit(0);
                break;
            case 5:
            {
                int value;

                printf("Enter integer value to search: ");
                scanf("%d",&value);

                search_elem(value);
                display_arr();
                break;
            }
            default:
                printf("Invalid Choice...!!\n\n");
        }
    }

    return 0;
}

void display_arr()
{
    if (count == 0)
        printf("Array-based Rotating Queue is empty. .. ...");
    else
    {
        int ind = front;
        for (int i = 0; i < count; i++)
        {
            printf("%d", arr[ind]);
            if (i != count - 1)
                printf(", ");
            ind = (ind + 1) % QSIZE;
        }
    }

    printf("\n\n");
}

void search_elem(int elem_2_search)
{
    int ind = front;
    for (int i = 0; i < count; i++)
    {
        if (arr[ind] == elem_2_search)
        {
            printf("Searched Element: (%d) FOUND at index [%d] in the Array-based Rotating Queue.\n", elem_2_search, ind);
            return;
        }
        ind = (ind + 1) % QSIZE;
    }

    printf("Searched Element: (%d) NOT FOUND in the Array-based Rotating Queue.\n", elem_2_search);

}

int delete_elem()
{
    int del_elem;
    if (0 < count && count <= QSIZE)
    {
        del_elem = arr[front];
        arr[front] = 0;
        front = (front + 1) % QSIZE;
        count--;
        return del_elem;
    }
    else
    {
        printf("Array-based Rotating Queue is empty. (Under-Flow NOT-ALLOWED)\n");
        return -11111;
    }
}

void insert_elem(int elem_2_insert)
{
    if (0 <= count && count < QSIZE)
    {
        rear = (rear + 1) % QSIZE;
        arr[rear] = elem_2_insert;
        count++;
    }
    else
        printf("Array-based Rotating Queue is at Capacity. (Over-Flow NOT-ALLOWED)\n");
}
