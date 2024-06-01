#include <stdbool.h>
#include <stdio.h>

// Insertion Sort Implementation
void insertion_sort(int num_elems, int list[], bool asc_flag)
{
    printf("\nOriginal List: ");
    for (int i = 0; i < num_elems; i++)
        printf("%d, ", list[i]);

    for (int i = 1; i < num_elems; i++)
    {
        int key = list[i];
        int j = i - 1;

        /*
        Move elements of list[0..i-1], that are
        greater than key, to one position ahead
        of their current position
        */
        if (asc_flag)
            while (j >= 0 && list[j] > key)
            {
                list[j + 1] = list[j];
                j--;
            }
        else
        {
            while (j >= 0 && list[j] < key)
            {
                list[j + 1] = list[j];
                j--;
            }
        }
        list[j + 1] = key;
    }

    printf("\n  Sorted List: ");
    for (int i = 0; i < num_elems; i++)
        printf("%d, ", list[i]);
    printf("\n");
}

int main()
{
    int num_elems;

    printf("Enter no. of list elements for insertion-sort: ");
    scanf("%d", &num_elems);
    printf("\n");

    int list[num_elems];

    for (int i = 0; i < num_elems; i++)
    {
        printf("Enter element #%d: ", i);
        scanf("%d", &list[i]);
    }

    bool asc_flag = true;

    //int num_elems = 5;
    //int list[] = {20, 90, 50, 70, 40};
    insertion_sort(num_elems, list, asc_flag);

    return 0;
}
