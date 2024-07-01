#include <stdio.h>

// Linear Search Implementation
void linear_search(int num_elems, int list[], int elem)
{
    for (int i = 0; i < num_elems; i++)
        if (list[i] == elem)
        {
            printf("Searched Element: (%d) FOUND at index [%d] in the array.\n", elem, i);
            return;
        }

    printf("Searched Element: (%d) NOT FOUND in the array.\n", elem);
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

    printf("\nEnter element to linear-search: ");
    scanf("%d", &elem);
    printf("\n");

    //int num_elems = 5;
    //int list[] = {20, 90, 50, 70, 40};
    //int elem = 90;
    linear_search(num_elems, list, elem);

    return 0;
}
