#include <iostream>
#include "Con2d.h"
#include "../../Array/Array.h"

Con2d::Con2d() {
    this->padding = 1;
}


// input image include padding
float** Con2d::convolution(float image[IMAGE_SIZE + 1][IMAGE_SIZE], float *kernel) {
    float** result = Array::initialize2dArray(IMAGE_SIZE - 2 * padding, IMAGE_SIZE - 2 * padding);
    int resultRowIndex, resultColumnIndex = 0;

    for (int rowIndex = padding; rowIndex < IMAGE_SIZE - padding; rowIndex++) {
        resultRowIndex = 0;
        for (int columnIndex = padding; columnIndex < IMAGE_SIZE - padding; columnIndex++) {
            int rowStartIndex = rowIndex - padding;
            int rowFinishIndex = rowIndex + padding;
            int columnStartIndex = columnIndex - padding ;
            int columnFinishIndex = columnIndex + padding;

            float* workspace = Array::getArea(image, rowStartIndex, rowFinishIndex, columnStartIndex, columnFinishIndex);
            float* multiplied = Array::multiply(workspace, kernel, KERNEL_SIZE);
            float sum = Array::sum(multiplied, KERNEL_SIZE);

            result[resultRowIndex][resultColumnIndex] = sum;

            resultRowIndex++;
        }
        resultColumnIndex++;
    }

    return result;
}
