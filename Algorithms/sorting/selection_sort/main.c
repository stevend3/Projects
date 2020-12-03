// This file includes an implementation of the selection sort algorithm
// Created by Steven Diniz
#include <stdio.h>

void selectionSort(int a[], int n);
void printArray(int a[], int n);

int main() {
    int nums[] = {17, 21, 13, 8, 59, 35};
    int n = 6;
    printArray(nums, n);
    selectionSort(nums, n);
    printArray(nums, n);
    return 0;
}

// Implementation of the selection sort algorithm
// Sorts from smallest to largest
// Arguments:
//  int a[]: array to be sorted
//  int n: size of array to be sorted
// Return: nothing
void selectionSort(int a[], int n) {
    int tmp, min;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i+1; j<n; j++) {
            if (a[j] < a[min]) min = j;
        }
        if (min != i) {
            tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
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
