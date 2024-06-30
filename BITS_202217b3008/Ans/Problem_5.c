#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QSIZE 3

// Function Prototypes
void display_arr();
void search_elem(int elem_2_search);
void delete_elem();
void insert_elem(int elem_2_insert);
// Head
int front = 0, rear = -1, count = 0, arr[QSIZE];

int main(void)
{
    int choice;

    while (true)
    {
        printf("Array-based Circular Queue (F.I.F.O.) [Size: %d]\n", QSIZE);
        printf("\n");
        printf("Choices:\n1. Insert Element\n2. Delete Element\n3. Show Array-based Circular Queue\n4. Exit\n5. Search Element\n");
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
        printf("Array-based Circular Queue is empty. .. ...");
    else
        for (int i = 0; i < QSIZE; i++)
            printf("%d, ", arr[i]);

    printf("\n\n");
}

void search_elem(int elem_2_search)
{
    int flag = 0;
    for (int ind = 0; ind < QSIZE; ind++)
    {
        if (arr[ind] == elem_2_search)
        {
            flag = 1;
            printf("Searched Element: %d found at index [%d] in the array.\n", elem_2_search, ind);
        }
    }

    if (flag == 0)
        printf("Searched Element: %d not found in the array.\n", elem_2_search);

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
        printf("Array-based Circular Queue is empty. (Under-Flow NOT-ALLOWED)\n");
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
        printf("Array-based Circular Queue is at Capacity. (Over-Flow NOT-ALLOWED)\n");
}
