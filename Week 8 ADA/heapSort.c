#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void bottom_heapify(int n, int a[]);
void heapsort(int n, int a[]);
void printArray(int a[], int n);

int main() {
    int a[15000], n, i, j, ch, temp;
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
                printf("\nEnter array elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                start = clock();
                heapsort(n, a);
                end = clock();
                printf("\nSorted array: ");
                printArray(a, n);
                printf("\nTime taken to sort %d numbers is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                break;

            case 2:
                n = 500;
                while (n <= 14500) {
                    for (i = 0; i < n; i++) {
                        // a[i] = random(1000);
                        a[i] = n - i;
                    }
                    start = clock();
                    heapsort(n, a);
                    // Dummy loop to create delay
                    for (j = 0; j < 500000; j++) {
                        temp = 38 / 600;
                    }
                    end = clock();
                    printf("\nTime taken to sort %d numbers is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                    n = n + 1000;
                }
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Try again.");
        }
        getchar();
    }
    return 0;
}

// Function to perform heapify on a subtree rooted at index i
void bottom_heapify(int n, int a[]) {
    int p, item, c;
    for (p = (n - 1) / 2; p >= 0; p--) {
        item = a[p];
        c = 2 * p + 1;
        while (c <= n - 1) {
            if (c + 1 <= n - 1 && a[c] < a[c + 1]) {
                c++;
            }
            if (item < a[c]) {
                a[p] = a[c];
                p = c;
            } else {
                break;
            }
            c = 2 * p + 1;
        }
        a[p] = item;
    }
}

// Function to perform heap sort
void heapsort(int n, int a[]) {
    // Step 1: Build heap (rearrange array)
    bottom_heapify(n, a);

    // Step 2: Extract elements one by one from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // Call bottom_heapify on the reduced heap
        bottom_heapify(i, a);
    }
}

// Function to print an array
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
