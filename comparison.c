/*
 * Max Heap vs Linear Search
 * Program: Combined comparison of both approaches
 */

#include <stdio.h>

#define MAX 100

int heap[MAX];
int heapSize = 0;
int heapComparisons = 0;

/* Insert into Max Heap */
void insertMaxHeap(int value)
{
    int i = heapSize;
    heap[heapSize] = value;
    heapSize++;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        heapComparisons++;

        if (heap[parent] >= heap[i])
            break;

        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

/* Find maximum using Linear Search */
int linearSearchMax(int scores[], int n, int *comparisons)
{
    int max = scores[0];
    *comparisons = 0;

    for (int i = 1; i < n; i++)
    {
        (*comparisons)++;

        if (scores[i] > max)
            max = scores[i];
    }

    return max;
}

int main(void)
{
    int scores[] = {78, 92, 65, 88, 95, 72, 84, 90};
    int n = sizeof(scores) / sizeof(scores[0]);

    int linearComparisons;
    int linearMax;

    /* Build Max Heap */
    for (int i = 0; i < n; i++)
        insertMaxHeap(scores[i]);

    /* Linear Search */
    linearMax = linearSearchMax(scores, n, &linearComparisons);

    printf("PERFORMANCE COMPARISON\n");
    printf("======================\n\n");

    printf("Number of students: %d\n\n", n);

    printf("MAX HEAP\n");
    printf("Highest score: %d\n", heap[0]);
    printf("Construction comparisons: %d\n", heapComparisons);
    printf("Maximum retrieval comparisons: 0\n");
    printf("Maximum retrieval complexity: O(1)\n\n");

    printf("LINEAR SEARCH\n");
    printf("Highest score: %d\n", linearMax);
    printf("Maximum search comparisons: %d\n", linearComparisons);
    printf("Maximum search complexity: O(n)\n\n");

    printf("CONCLUSION\n");
    printf("==========\n");
    printf("Max Heap is suitable for continuously maintaining\n");
    printf("and retrieving the highest score.\n");

    return 0;
}
