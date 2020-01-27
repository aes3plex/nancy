#include <iostream>
#include "Con2d.h"
#include "../../Array/Array.h"


Con2d::Con2d(c_int padding, Array* kernels, c_int kernelsNumber) {
    this -> padding = padding;
    this -> kernels = kernels;
    this -> kernelsNumber = kernelsNumber;
}

// input image include padding
void Con2d::convolution(Array image, Array kernel, Array result) {
    c_int resultIndex = 0;
    c_int kernelHeight = kernel.getHeight(), kernelWidth = kernel.getWidth();

    // check output dimensions
    if (result.getHeight() != image.getHeight() - 2 * padding || result.getWidth() == image.getWidth() - 2 * padding) {
        // handle
    }

    for (c_int rowIndex = padding; rowIndex < image.getHeight() - padding; rowIndex++) {
        for (c_int columnIndex = padding; columnIndex < image.getWidth() - padding; columnIndex++) {
            c_int rowStartIndex = rowIndex - padding;
            c_int rowFinishIndex = rowIndex + padding;
            c_int columnStartIndex = columnIndex - padding ;
            c_int columnFinishIndex = columnIndex + padding;

            c_float areaArray[kernelHeight * kernelWidth];
            Array area(areaArray, kernelHeight, kernelWidth);

            image.getArea(rowStartIndex, rowFinishIndex, columnStartIndex, columnFinishIndex, area);
            area.multiply(kernel, area);

            c_float sum = area.sum();
            result.setElement(resultIndex, sum);

            resultIndex++;
        }
    }
}

void Con2d::getOutput(Array image, Array* resultFeatureMap) {
    for (c_int i = 0; i < kernelsNumber; i++) {
        convolution(image, kernels[i], resultFeatureMap[i]);
    }
}
