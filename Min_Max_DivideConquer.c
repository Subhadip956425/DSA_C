#include <stdio.h>
#include <limits.h>

void findMinMax(int arr[], int low, int high, int *min, int *max) {
    int mid;
    int min1, max1, min2, max2;

    if (low == high) {
        *min = *max = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    mid = (low + high) / 2;

    findMinMax(arr, low, mid, &min1, &max1);

    findMinMax(arr, mid + 1, high, &min2, &max2);

    if (min1 < min2) {
        *min = min1;
    } else {
        *min = min2;
    }

    if (max1 > max2) {
        *max = max1;
    } else {
        *max = max2;
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min = INT_MAX;
    int max = INT_MIN;

    findMinMax(arr, 0, n - 1, &min, &max);

    printf("The minimum element in the array is: %d\n", min);
    printf("The maximum element in the array is: %d\n", max);

    return 0;
}
