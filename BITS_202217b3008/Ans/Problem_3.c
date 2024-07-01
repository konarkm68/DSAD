#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global Declarations
#define STACKSIZE 3
int count = 0, *rear = &count, arr[STACKSIZE];

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
        printf("Array-based Stack (L.I.F.O.) [Size: %d]\n", STACKSIZE);
        printf("\n");
        printf("Choices:\n1. Push Element\n2.  Pop Element\n3. Show Array-based Stack\n4. Exit\n"); //5. Search Element\n");
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
                int popped_elem = delete_elem();
                if (popped_elem != -11111)
                    printf("The popped element is: %d\n", popped_elem);
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
        printf("Array-based Stack is empty. .. ...");
    else
        for (int i = 0; i < count; i++)
        {
            printf("%d", arr[i]);
            if (i != count - 1)
                printf(", ");
        }

    printf("\n\n");
}

void search_elem(int elem_2_search)
{
    for (int ind = 0; ind < count; ind++)
    {
        if (arr[ind] == elem_2_search)
        {
            printf("Searched Element: (%d) FOUND at index [%d] in the Array-based Stack.\n", elem_2_search, ind);
            return;
        }
    }

    printf("Searched Element: (%d) NOT FOUND in the Array-based Stack.\n", elem_2_search);

}

int delete_elem()
{
    int popped_elem;
    if (0 < count && count <= STACKSIZE)
    {
        count--;
        popped_elem = arr[*rear];
        arr[*rear] = 0;
        return popped_elem;
    }
    else
    {
        printf("Array-based Stack is empty. (Under-Flow NOT-ALLOWED)\n");
        return -11111;
    }
}

void insert_elem(int elem_2_insert)
{
    if (0 <= count && count < STACKSIZE)
    {
        arr[*rear] = elem_2_insert;
        count++;

    }
    else
        printf("Array-based Stack is at Capacity. (Over-Flow NOT-ALLOWED)\n");
}
