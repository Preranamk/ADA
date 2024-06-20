//Quick Sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high + 1;

    do {
        do {
            i++;
        } while (A[i] < pivot);

        do {
            j--;
        } while (A[j] > pivot);

        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);

    swap(&A[low], &A[j]);
    return j;
}

// Function to perform quicksort
void quicksort(int A[], int low, int high) {
    if (low < high) {
        int split = partition(A, low, high);
        quicksort(A, low, split - 1);
        quicksort(A, split + 1, high);
    }
}

int main() {
    int n, ch;
    clock_t start, end;

    while (1) {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                int* A = (int*)malloc(n * sizeof(int));
                if (A == NULL) {
                    printf("Memory allocation failed\n");
                    exit(1);
                }
                printf("Enter array elements: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &A[i]);
                }
                start = clock();
                quicksort(A, 0, n - 1);
                end = clock();
                printf("\nSorted array is: ");
                for (int i = 0; i < n; i++) {
                    printf("%d\t", A[i]);
                }
                printf("\nTime taken to sort %d numbers is %f seconds\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                free(A);
                break;

            case 2:
                n = 500;
                while (n <= 14500) {
                    int* A = (int*)malloc(n * sizeof(int));
                    if (A == NULL) {
                        printf("Memory allocation failed\n");
                        exit(1);
                    }
                    // Initializing array with reverse order
                    for (int i = 0; i < n; i++) {
                        A[i] = n - i;
                    }
                    start = clock();
                    quicksort(A, 0, n - 1);
                    // Dummy loop to create delay
                    for (int j = 0; j < 500000; j++) {
                        int temp = 38 / 600;
                    }
                    end = clock();
                    printf("Time taken to sort %d numbers is %f seconds\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                    free(A);
                    n += 1000;
                }
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
