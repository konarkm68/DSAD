#include <stdio.h>

// Global Declarations
#define MAX_PROCESSES 30
int num_processes;
float arrival_t[MAX_PROCESSES], burst_t[MAX_PROCESSES], cumulative_burst_t[MAX_PROCESSES], wait_t[MAX_PROCESSES], turn_around_t[MAX_PROCESSES];

// Function Prototypes
void get_process_data();
void print_results();

int main()
{
    printf("First-Come, First-Served (FCFS) CPU-Processes Scheduling\n\n");
    printf("Enter the number of processes (Max. 30): ");
    scanf("%d", &num_processes);

    get_process_data();
    print_results();

    return 0;
}

void get_process_data()
{
    for (int i = 0; i < num_processes; i++)
    {
        printf("\nEnter details for Process #%d:\n", i + 1);
        printf("  Arrival Time (in ms): "); scanf("%f", &arrival_t[i]);
        // Validate arrival time to ensure non-decreasing order
        if (i > 0 && arrival_t[i] < arrival_t[i - 1])
        {
            printf("Error: Arrival times must be in non-decreasing order!!\n");
            printf("Please re-enter arrival time for process #%d:\n", i + 1);
            do {
                printf("  Arrival Time (in ms): "); scanf("%f", &arrival_t[i]);
            } while (arrival_t[i] < arrival_t[i - 1]);
        }
        printf("    Burst Time (in ms): "); scanf("%f", &burst_t[i]);
    }
}

void print_results()
{
    cumulative_burst_t[0] = 0; // First process has no waiting time
    for (int i = 0; i < num_processes; i++)
    {
        cumulative_burst_t[i + 1] = cumulative_burst_t[i] + burst_t[i];
        // Calculate Waiting times
        wait_t[i] = cumulative_burst_t[i] - arrival_t[i];
        // Calculate Turn-around times
        turn_around_t[i] = cumulative_burst_t[i + 1] - arrival_t[i];
    }

    printf("\n\nFCFS CPU-Processes Scheduling Results: \n");
    printf("Process #   \t Arrival Time \t Burst Time \t Cumulative Burst Time \t Waiting Time \t Turn-around Time\n");
    for (int i = 0; i < num_processes; i++)
        printf("Process #%-2d \t %10.6f ms \t %10.6f ms \t %10.6f ms \t\t %10.6f ms \t %10.6f ms\n", i + 1, arrival_t[i], burst_t[i], cumulative_burst_t[i], wait_t[i], turn_around_t[i]);

    // Calculate Average Waiting & Turn-around time
    float avg_wait_t = 0, avg_turnaround_t = 0;
    for (int i = 0; i < num_processes; i++)
    {
        avg_wait_t += wait_t[i];
        avg_turnaround_t += turn_around_t[i];
    }
    avg_wait_t /= num_processes;
    avg_turnaround_t /= num_processes;

    printf("\nAverage     Waiting Time: %10.6f ms\n", avg_wait_t);
    printf("Average Turn-around Time: %10.6f ms\n", avg_turnaround_t);
}
