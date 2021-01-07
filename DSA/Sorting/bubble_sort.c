#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

/**
 * Bubble sort algorithm.
 *
 * @param int input Array to sort
 * @param int n Number of data in search array
 *
 * @return void
 */
void bubble_sort(int *input, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (input[j] > input[j + 1]) {
                swap(input + j, input + j + 1);
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *b;

    *b = *a;
    *a = temp;
}

int main()
{
    srand((unsigned) time(NULL));
    int n = 1000;

    printf("How many numbers? %d", n);

    int *input = (int *) malloc(n * sizeof(int));

    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        input[i] = rand();
    }

    bubble_sort(input, n);

    for (int i = 0; i < n; i++) {
        printf("%d\t", *(input + i));
    }

    free(input);
}
