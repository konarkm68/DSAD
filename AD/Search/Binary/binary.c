#include <stdbool.h>
#include <stdio.h>

// Binary Search Implementation
void binary_search(int num_elems, int list[], int elem)
{
    int left = 0, right = num_elems - 1;
    bool is_ascending = list[left] < list[right];

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Base Condition
        if (list[mid] == elem)
        {
            printf("Found element (%d) at index - %d.\n", elem, mid);
            return;
        }

        // Iterative Condition
        if (is_ascending)
            // Ignore  Left-Half only if list-element at mid-index is  lesser than the searched
            // element.
            if (list[mid] < elem)
                left = mid + 1;
            // Ignore Right-Half only if list-element at mid-index is greater than the searched
            // element.
            else
                right = mid - 1;
        else
            // Ignore  Left-Half only if list-element at mid-index is greater than the searched
            // element.
            if (list[mid] > elem)
                left = mid + 1;
            // Ignore Right-Half only if list-element at mid-index is  lesser than the searched
            // element.
            else
                right = mid - 1;
    }

    printf("Not found!\n");
    return;
}

int main()
{
    int num_elems, elem;

    printf("Enter no. of list elements: ");
    scanf("%d", &num_elems);
    printf("\n");

    int list[num_elems];

    for (int i = 0; i < num_elems; i++)
    {
        printf("Enter element #%d: ", i);
        scanf("%d", &list[i]);
    }

    printf("\nEnter element to binary-search: ");
    scanf("%d", &elem);
    printf("\n");

    // int num_elems = 10;
    // int list[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    // int elem = 30;
    binary_search(num_elems, list, elem);

    return 0;
}
