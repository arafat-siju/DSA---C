#include <stdio.h>
#include <stdlib.h>

int order;
int swap_method;


void swap(int *x, int *y) {
    if (swap_method == 1) {
        // Temp Variable
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    else if (swap_method == 2) {
        //Arithmetic Swap
        if (x != y) {
            *x = *x + *y;
            *y = *x - *y;
            *x = *x - *y;
        }
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (1) {
        if (order == 1) {
            // Ascending Order
            while (i <= high && a[i] <= pivot)
                i++;

            while (j > low && a[j] > pivot)
                j--;
        }
        else {
            // Descending Order
            while (i <= high && a[i] >= pivot)
                i++;

            while (j > low && a[j] < pivot)
                j--;
        }

        if (i >= j)
            break;

        swap(&a[i], &a[j]);
    }

    swap(&a[low], &a[j]);

    return j;
}

void quick_sort(int a[], int low, int high) {
    if (low < high) {
        int mid = partition(a, low, high);

        quick_sort(a, low, mid - 1);
        quick_sort(a, mid + 1, high);
    }
}

int main() {
    int n, i;

    printf("Enter number of Data: ");
    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++) {
        printf("Enter Data: ");
        scanf("%d", &a[i]);
    }

    printf("\n1. Ascending Order");
    printf("\n2. Descending Order");
    printf("\nEnter sorting choice: ");
    scanf("%d", &order);

    if (order != 1 && order != 2) {
        printf("Invalid sorting choice!\n");
        return;
    }

    printf("\nSelect Swap Method:");
    printf("\n1. Temporary Variable");
    printf("\n2. Arithmetic Swap");
    printf("\nEnter swap choice: ");
    scanf("%d", &swap_method);

    if (swap_method != 1 && swap_method != 2) {
        printf("Invalid swap choice!\n");
        return 1;
    }

    quick_sort(a, 0, n - 1);

    printf("\nSorted Array:\n");

    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    return 0;
}
