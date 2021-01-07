#include <stdio.h>
#include <stdlib.h>

/**
 * Insertion sort algorithm.
 *
 * @param int input Array to sort
 * @param int n Number of data in search array
 *
 * @return void
 */
void insertion_sort(int *input, int n)
{
    int gap, key;

    for (int i = 1; i < n; i++) {
        key = input[i];
        gap = i - 1;

        while (gap >= 0 && input[gap] > key) {
            input[gap + 1] = input[gap];
            gap--;
        }

        input[gap + 1] = key;
    }
}

int main()
{
    srand((unsigned) time(NULL));
    int n = 1000;

    printf("How many numbers? %d\n", n);

    int *input = (int *) malloc(n * sizeof(int));

    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        input[i] = rand();
    }

    insertion_sort(input, n);

    for (int i = 0; i < n; i++) {
        printf("%d\t", *(input + i));
    }

    free(input);
}
