/*
 * Max Heap vs Linear Search
 * Program: Max Heap insertion and maximum retrieval
 */

#include <stdio.h>

#define MAX 100

int heap[MAX];
int heapSize = 0;
int totalComparisons = 0;

/* Print the current heap */
void printHeap(void)
{
    for (int i = 0; i < heapSize; i++)
    {
        printf("%d", heap[i]);

        if (i < heapSize - 1)
            printf(" ");
    }

    printf("\n");
}

/* Insert an element into the Max Heap */
void insertMaxHeap(int value)
{
    int i = heapSize;
    heap[heapSize] = value;
    heapSize++;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        /* One parent-child comparison */
        totalComparisons++;

        if (heap[parent] >= heap[i])
            break;

        /* Swap */
        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

/* Return the maximum element */
int getMaximum(void)
{
    return heap[0];
}

int main(void)
{
    int scores[] = {78, 92, 65, 88, 95, 72, 84, 90};
    int n = sizeof(scores) / sizeof(scores[0]);

    printf("MAX HEAP INSERTION\n");
    printf("==================\n\n");

    for (int i = 0; i < n; i++)
    {
        insertMaxHeap(scores[i]);

        printf("After inserting %d: ", scores[i]);
        printHeap();
    }

    printf("\nFinal Max Heap: ");
    printHeap();

    printf("Highest Score: %d\n", getMaximum());
    printf("Total parent comparisons during insertion: %d\n",
           totalComparisons);

    return 0;
}
