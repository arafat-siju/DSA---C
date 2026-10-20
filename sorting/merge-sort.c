
#include <stdio.h>
#include <stdlib.h>

int order;

void Merge(int a[], int low, int mid, int high) {
    int nL = mid - low + 1;
    int nR = high - mid;

    int aL[nL], aR[nR], i, j;

    for (i = 0; i < nL; i++)
        aL[i] = a[low + i];

    for (j = 0; j < nR; j++)
        aR[j] = a[mid + j + 1];

    i = 0;
    j = 0;
    int k = low;

    while (i < nL && j < nR) {
        if ((order == 1 && aL[i] <= aR[j]) ||
            (order == 2 && aL[i] >= aR[j])) {
            a[k] = aL[i];
            i++;
        }
        else {
            a[k] = aR[j];
            j++;
        }
        k++;
    }

    while (i < nL) {
        a[k] = aL[i];
        i++;
        k++;
    }

    while (j < nR) {
        a[k] = aR[j];
        j++;
        k++;
    }
}

void merge_sort(int a[], int low, int high) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);

    Merge(a, low, mid, high);
}

int main() {
    int n, i;

    printf("Enter number of Data: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int a[n];

    for (i = 0; i < n; i++) {
        printf("Enter Data: ");
        scanf("%d", &a[i]);
    }

    printf("\n1. Ascending Order");
    printf("\n2. Descending Order");
    printf("\nEnter your choice: ");
    scanf("%d", &order);

    if (order != 1 && order != 2) {
        printf("Invalid choice!\n");
        return 1;
    }

    merge_sort(a, 0, n - 1);

    printf("\nSorted Array:\n");

    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    printf("\n");

    return 0;
}
