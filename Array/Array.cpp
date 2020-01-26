#include "Array.h"
#include <iostream>

float Array::sum(const float* array, int size) {
    float result = 0.0;
    for(int i = 0; i < size; i++) {
        result += array[i];
    }

    return result;
}

float* Array::multiply(float* first, float* second, int size) {
    auto* result = new float[size];

    for (int i = 0; i < size; i++) {
        result[i] = first[i] * second[i];
    }

    return result;
}

float* Array::getArea(
        float array[IMAGE_SIZE][IMAGE_SIZE],
        int rowStartIndex,
        int rowFinishIndex,
        int columnStartIndex,
        int columnFinishIndex
) {
    auto* result = new float[KERNEL_SIZE];
    int resultIndex = 0;

    for (int rowIndex = rowStartIndex; rowIndex <= rowFinishIndex; rowIndex++) {
        for (int columnIndex = columnStartIndex; columnIndex <= columnFinishIndex; columnIndex++) {
            result[resultIndex] = array[rowIndex][columnIndex];
            resultIndex++;
        }
    }

    return result;
}

float** Array::initialize2dArray(int rows, int columns) {
    auto** array = new float*[rows];
    for(int i = 0; i < rows; ++i)
        array[i] = new float[columns];

    return array;
}

