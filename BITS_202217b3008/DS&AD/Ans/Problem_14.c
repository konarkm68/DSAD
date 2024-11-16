#include <stdio.h>

// Global Declarations
#define INDEX 1
#define MAX_NODES 15
char bin_tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};

// Function Prototypes
int get_l_child(int);
int get_r_child(int);
void  pre_order(int);
void   in_order(int);
void post_order(int);

int main(void)
{
    printf("Binary Tree Traversals: ");
    printf("\n      PRE-Order: ");  pre_order(INDEX);
    printf("\n       IN-Order: ");   in_order(INDEX);
    printf("\n     POST-Order: "); post_order(INDEX);
    printf("\n");

    return 0;
}

int get_l_child(int index)
{
    if (bin_tree[index] != '\0' &&  (2 * index)      <= MAX_NODES)
        return (2 * index);
    return -1;
}

int get_r_child(int index)
{
    if (bin_tree[index] != '\0' && ((2 * index) + 1) <= MAX_NODES)
        return (2 * index) + 1;
    return -1;
}

void  pre_order(int index)
{
    if (index > 0 && bin_tree[index] != '\0')
    {
        printf(" %c ", bin_tree[index]);
        pre_order(get_l_child(index));
        pre_order(get_r_child(index));
    }
}

void   in_order(int index)
{
    if (index > 0 && bin_tree[index] != '\0')
    {
        in_order(get_l_child(index));
        printf(" %c ", bin_tree[index]);
        in_order(get_r_child(index));
    }
}

void post_order(int index)
{
    if (index > 0 && bin_tree[index] != '\0')
    {
        post_order(get_l_child(index));
        post_order(get_r_child(index));
        printf(" %c ", bin_tree[index]);
    }
}
