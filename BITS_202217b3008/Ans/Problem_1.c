#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global Declarations
#define arrSIZE 10
int count = 0, arr[arrSIZE];

// Function Prototypes
void create_arr(int);
void display_arr();
void search_elem(int);
void delete_elem(int);
void insert_elem(int, int);

int main(void)
{
    int choice;

    while (true)
    {
        printf("Array-based List [Size: %d]\n", arrSIZE);
        printf("\n");
        printf("Choices:\n1. Insert/Update Element\n2. Delete Element\n3. Show Array-based List\n4. Exit\n5. Search Element\n6. Create Array-based List\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int pos, value;

                printf("Enter the position value to insert element: "); scanf("%d",&pos);
                printf("Enter integer value to insert: "); scanf("%d",&value);

                insert_elem(pos, value);
                display_arr();
                break;
            }
            case 2:
            {
                int pos;

                printf("Enter the position value to insert element: "); scanf("%d",&pos);

                delete_elem(pos);
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
                break;
            }
            case 6:
            {
                int num_elems;

                printf("Enter the number of elements: ");
                scanf("%d", &num_elems);

                create_arr(num_elems);
                display_arr();
                break;
            }
            default:
                printf("Invalid Choice...!!\n\n");
        }
    }

    return 0;
}

void create_arr(int num_elems)
{
    int value;
    if (count == 0 && 1 < num_elems && num_elems <= arrSIZE)
        for (int i = 0; i < num_elems; i++)
        {
            printf("Enter the element #%d: ", i); scanf("%d", &value);
            arr[i] = value;
            count++;
        }
    else
        printf("Invalid Number of Elements OR somewhat filled array!!\n");
}

void display_arr()
{
    if (count == 0)
        printf("Array-based List is empty. .. ...");
    else
        for (int i = 0; i < arrSIZE; i++)
        {
            printf("%d", arr[i]);
            if (i != arrSIZE - 1)
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
            printf("Searched Element: (%d) FOUND at index [%d] in the array.\n", elem_2_search, ind);
            return;
        }
    }

    printf("Searched Element: (%d) NOT FOUND in the array.\n", elem_2_search);

}

void delete_elem(int pos)
{
    if (0 <= count && count <= arrSIZE && 0 <= pos && pos < arrSIZE)
    {
        count--;
        arr[pos] = 0;

    }
    else
        printf("Invalid position-element for the array!!\n");
}

void insert_elem(int pos, int elem_2_insert)
{
    if (0 <= count && count <= arrSIZE && 0 <= pos && pos < arrSIZE)
    {
        arr[pos] = elem_2_insert;
        count++;

    }
    else
        printf("Invalid element-position for the array!!\n");
}
