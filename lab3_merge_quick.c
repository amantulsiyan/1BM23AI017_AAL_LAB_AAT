#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++) L[i] = arr[l+i];
    for(int j=0; j<n2; j++) R[j] = arr[m+1+j];

    int i=0, j=0, k=l;
    while(i<n1 && j<n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low-1;
    for(int j=low; j<high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    int temp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = temp;
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    printf("Original array:\n");
    printArray(arr1,n);

    mergeSort(arr1, 0, n-1);
    printf("Sorted by Merge Sort:\n");
    printArray(arr1,n);

    int arr2[] = {12, 11, 13, 5, 6};
    quickSort(arr2, 0, n-1);
    printf("Sorted by Quick Sort:\n");
    printArray(arr2,n);

    return 0;
}
