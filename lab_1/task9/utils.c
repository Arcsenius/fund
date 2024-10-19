#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

ErrorCode fillArray(int* array, int size, int min, int max) {
    if (array == NULL) {
        return ERROR_MEMORY_ALLOCATION;
    }
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = min + rand() % (max - min + 1);
    }

    return SUCCESS;
}

void findAndSwapMinMax(int* array, int size) {
    if (array == NULL || size <= 0) return;

    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }

    int temp = array[minIndex];
    array[minIndex] = array[maxIndex];
    array[maxIndex] = temp;
}

ErrorCode findSumNearestValue(int* arrayA, int sizeA, int* arrayB, int sizeB, int* arrayC) {
    if (arrayA == NULL || arrayB == NULL || arrayC == NULL)
        return ERROR_MEMORY_ALLOCATION;

    qsort(arrayB, sizeB, sizeof(int), compare);

    for (int i = 0; i < sizeA; i++) {
        int nearest = findNearest(arrayB, sizeB, arrayA[i]);
        arrayC[i] = arrayA[i] + nearest;
    }



    return SUCCESS;
}



int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int findNearest(int *arrayB, int sizeB, int target) {
    int left = 0;
    int right = sizeB - 1;

    if (target <= arrayB[0]) {
        return arrayB[0];
    }
    if (target >= arrayB[right]) {
        return arrayB[right];
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arrayB[mid] == target) {
            return arrayB[mid];
        }

        if (arrayB[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    if (abs(arrayB[left] - target) < abs(arrayB[right] - target)) {
        return arrayB[left];
    } else {
        return arrayB[right];
    }
}


