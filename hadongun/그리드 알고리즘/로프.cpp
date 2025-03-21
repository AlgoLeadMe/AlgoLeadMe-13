#include <stdio.h>


int partition(long int arr[], int low, int high) {
    long int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            long int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    long int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}


void quickSort(long int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int N;
    scanf("%d", &N); 

    long int maxW[100000];

    for (int i = 0; i < N; i++) {
        scanf("%ld", &maxW[i]);  
    }

    
    quickSort(maxW, 0, N - 1);

    
    long int maxWeight = 0;
    for (int i = 0; i < N; i++) {
        long int weight = maxW[i] * (N - i);  
        if (weight > maxWeight) {
            maxWeight = weight;  
        }
    }

    printf("%ld\n", maxWeight);
    return 0;
}