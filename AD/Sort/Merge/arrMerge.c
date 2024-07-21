#include <stdbool.h>
#include <stdio.h>

// Merge Sort Implementation
void sort_merge(int list[], int left_list[], int left_num_elems, int right_list[], int right_num_elems, bool asc_flag)
{
    int i = 0, j = 0, k = 0;

    while (i < left_num_elems && j < right_num_elems)
    {
        if (asc_flag)
        {
            if (left_list[i] <= right_list[j])
                list[k++] = left_list[i++];
            else
                list[k++] = right_list[j++];
        }
        else
        {
            if (left_list[i] >= right_list[j])
                list[k++] = left_list[i++];
            else
                list[k++] = right_list[j++];
        }
    }
    while (i < left_num_elems)
        list[k++] = left_list[i++];
    while (j < right_num_elems)
        list[k++] = right_list[j++];
}
void merge_sort_partitions(int num_elems, int list[], bool asc_flag)
{
    if (num_elems <= 1)
        return;

    int mid = num_elems / 2;

    int left_list[mid];
    for (int i = 0; i < mid; i++)
        left_list[i] = list[i];

    int right_list[num_elems - mid];
    for (int i = mid; i < num_elems; i++)
        right_list[i - mid] = list[i];

    merge_sort_partitions(            mid,  left_list, asc_flag);
    merge_sort_partitions(num_elems - mid, right_list, asc_flag);
    sort_merge(list, left_list, mid, right_list, num_elems - mid, asc_flag);
}
void merge_sort(int num_elems, int list[], bool asc_flag)
{
    printf("\nOriginal List: ");
    for (int i = 0; i < num_elems; i++)
    {
        printf("%d", list[i]);
        if (i != num_elems - 1)
            printf(", ");
    }

    merge_sort_partitions(num_elems, list, asc_flag);

    printf("\n  Sorted List: ");
    for (int i = 0; i < num_elems; i++)
    {
        printf("%d", list[i]);
        if (i != num_elems - 1)
            printf(", ");
    }
    printf("\n");
}

int main()
{
    int num_elems;

    printf("Enter no. of list elements to merge-sort: ");
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
    merge_sort(num_elems, list, asc_flag);

    return 0;
}
