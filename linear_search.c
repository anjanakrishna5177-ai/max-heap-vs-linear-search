/*
 * Max Heap vs Linear Search
 * Program: Linear Search for maximum score
 */

#include <stdio.h>

int main(void)
{
    int scores[] = {78, 92, 65, 88, 95, 72, 84, 90};
    int n = sizeof(scores) / sizeof(scores[0]);

    int max = scores[0];
    int comparisons = 0;

    printf("LINEAR SEARCH\n");
    printf("=============\n\n");

    printf("Scores: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d", scores[i]);

        if (i < n - 1)
            printf(" ");
    }

    printf("\n\n");

    for (int i = 1; i < n; i++)
    {
        comparisons++;

        printf("Comparison %d: %d vs %d",
               comparisons, max, scores[i]);

        if (scores[i] > max)
        {
            max = scores[i];
            printf(" -> new maximum = %d", max);
        }

        printf("\n");
    }

    printf("\nHighest Score: %d\n", max);
    printf("Total comparisons: %d\n", comparisons);

    return 0;
}
