#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int first, int m, int sec) {
    int n1 = m - first + 1;
    int n2 = sec - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[first+i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[first..sec]
    int i = 0, j = 0, k = first;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int first, int sec) {
    if (first < sec) {
        int m = first + (sec - first) / 2; // Calculate the middle index
        mergesort(arr, first, m);
        mergesort(arr, m + 1, sec);
        merge(arr, first, m, sec);
    }
}

int main() {
    int n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements of array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
