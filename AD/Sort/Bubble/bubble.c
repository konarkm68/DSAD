#include <stdbool.h>
#include <stdio.h>

// Bubble Sort Implementation
void bubble_sort(int num_elems, int list[], bool asc_flag)
{
    printf("\nOriginal List: ");
    for (int i = 0; i < num_elems; i++)
        printf("%d, ", list[i]);

    int temp;
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < num_elems - 1; i++)
            if (asc_flag)
            {
                if (list[i] > list[i + 1])
                {
                    temp = list[i];
                    list[i] = list[i + 1];
                    list[i + 1] = temp;
                    swapped = true;
                }
            }
            else
                if (list[i] < list[i + 1])
                {
                    temp = list[i];
                    list[i] = list[i + 1];
                    list[i + 1] = temp;
                    swapped = true;
                }
    }

    printf("\n  Sorted List: ");
    for (int i = 0; i < num_elems; i++)
        printf("%d, ", list[i]);
    printf("\n");
}

int main()
{
    int num_elems;

    printf("Enter no. of list elements to bubble-sort: ");
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
    bubble_sort(num_elems, list, asc_flag);

    return 0;
}
