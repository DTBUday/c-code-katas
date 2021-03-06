#include <stdio.h>
#include <stdlib.h>

/**
 * Binary search algorithm.
 *
 * @param int a Search array
 * @param int find Data to search
 * @param int n Number of data in search array
 *
 * @return int Index of found data or -1
 */
int binary_search(int *a, int find, int n)
{
    int start = 0;
    int end = n - 1;
    int mid = n / 2;

    while (start <= end) {
        if (a[mid] == find) {
            return mid;
        }

        if (find < a[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }

    return -1;
}

int main()
{
    srand((unsigned) time(NULL));
    int n = 10000, find = 1; 

    printf("How many items? %d\n", n);

    int *input = (int *) malloc(n * sizeof(int));

    printf("Enter numbers:\n");
    for (int i = 0; i < n; i++) {
        input[i] = i;
    }

    printf("Find: %d\n", find);

    int position = binary_search(input, find, n);

    if (position != -1) {
        printf("Data found at position %d", position);
    } else {
        printf("Data not found");
    }

    free(input);

    return 0;
}
