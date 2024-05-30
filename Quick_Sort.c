#include <stdio.h>

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}

void quick_sort(int array[], int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);

        quick_sort(array, low, pivot - 1);
        quick_sort(array, pivot + 1, high);
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Array before sorting:\n");
    print_array(array, size);

    quick_sort(array, 0, size - 1);

    printf("Array after sorting:\n");
    print_array(array, size);

    return 0;
}