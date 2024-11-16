#include <stdio.h>

// Function Prototypes
void twr_hanoi(int, char, char, char);

int main()
{
    int num_disks;
    char aux_rod = 'A', src_rod = 'B', dest_rod = 'C';

    printf("Tower of Hanoi - Solution Steps\n\n");
    
    printf("Auxiliary-Rod: %c | Source-Rod: %c | Destination-Rod: %c\n\n", aux_rod, src_rod, dest_rod);

    printf("Enter the number of disks: "); scanf("%d", &num_disks);
    printf("\n");

    if (1 <= num_disks)
        twr_hanoi(num_disks, aux_rod, src_rod, dest_rod);
    else
        printf("Invalid Number of Disks!!\n");

    return 0;
}

void twr_hanoi(int num_disks, char aux_rod, char src_rod, char dest_rod)
{
    if (num_disks == 0)
        return;

    twr_hanoi(num_disks - 1, dest_rod, src_rod, aux_rod);
    printf("Step: Move DISK #%d FROM Rod[%c] TO Rod[%c]\n", num_disks, src_rod, dest_rod);
    twr_hanoi(num_disks - 1, src_rod, aux_rod, dest_rod);
}
