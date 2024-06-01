#include <stdbool.h>
#include <stdio.h>

// Selection Sort Implementation
void selection_sort(int num_elems, int list[], bool asc_flag)
{
    printf("\nOriginal List: ");
    for (int i = 0; i < num_elems; i++)
        printf("%d, ", list[i]);

    for (int i = 0; i <= num_elems - 2; i++)
    {
        int pos_elem = list[i];
        int pos = i;
        for (int j = i + 1; j <= num_elems - 1; j++)
        {
            if (asc_flag)
            {
                if (list[j] < pos_elem)
                {
                    pos_elem = list[j];
                    pos = j;
                    // Swap
                    int temp = list[i];
                    list[i] = list[pos];
                    list[pos] = temp;
                }
            }
            else
                if (list[j] > pos_elem)
                {
                    pos_elem = list[j];
                    pos = j;
                    // Swap
                    int temp = list[i];
                    list[i] = list[pos];
                    list[pos] = temp;
                }
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

    printf("Enter no. of list elements for selection-sort: ");
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
    selection_sort(num_elems, list, asc_flag);

    return 0;
}
