// This file includes an implementation of the quicksort algorithm
// Created by Steven Diniz
#include <stdio.h>

void quicksort(int a[], int n);
int partition(int a[], int n);
void printArray(int a[], int n);

int main() {
    int rand_nums[] = {17, 38, 25, 3, 9, 172, 42};
    int n = 7;
    printArray(rand_nums, n);
    quicksort(rand_nums, n);
    printArray(rand_nums, n);
    return 0;
}

// Implementation of the quicksort algorithm
// Parameters:
//  int a[]: array to sort
//  int n: size of array to sort
// Returns: nothing
void quicksort(int a[], int n) {
    if (n <= 1) return;
    int m;
    m = partition(a,n);
    quicksort(a,m);
    quicksort(a+(m+1), n-(m+1));
    return;
}

// Split array into 2 smaller subarrays
// Parameters:
//  int a[]: array to split
//  int n: size of array to split
// Returns: location of the partition
int partition(int a[], int n) {
    int i = -1, j = n - 1;
    int p = a[n-1];
    int tmp;
    do {
        while (a[++i] < p);
        while ((p < a[--j]) && (j > 0));
        if (i <= j) {
            tmp = a[i]; a[i] = a[j]; a[j] = tmp;
        }
    } while (i < j);
    tmp = a[i]; a[i] = a[n-1]; a[n-1] = tmp;
    return i;
}

// Print an array
// Arguments:
//  int a[]: array to print
//  int n: size of array to print
// Returns: nothing
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}