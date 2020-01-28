#include <iostream>
#include "Con2d.h"
#include "../../Array/Array.h"
#include "../../Activations/Activations.h"


Con2d::Con2d(c_int padding, Array* kernels, c_int kernelsNumber, Array biases) {
    // todo: check biases dimension
    if (biases.getSize() != kernelsNumber) {
        std::cout << "Incorrect biases dimension";
    }

    this -> padding = padding;
    this -> kernels = kernels;
    this -> kernelsNumber = kernelsNumber;
    this -> biases = biases;
}

// input image include padding
void Con2d::convolution(Array image, Array kernel, c_int biasIndex, Array result) {
    c_int resultIndex = 0;
    c_int kernelHeight = kernel.getHeight(), kernelWidth = kernel.getWidth();

    // todo: check output dimensions
    if (result.getHeight() != image.getHeight() - 2 * padding || result.getWidth() != image.getWidth() - 2 * padding) {
        std::cout <<  "Incorrect output dimension";
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
            c_float bias = biases.getElement(biasIndex);
            result.setElement(resultIndex, Activations::ReLU(sum + bias));

            resultIndex++;
        }
    }
}

void Con2d::getOutput(Array image, Array* resultFeatureMap) {
    for (c_int i = 0; i < kernelsNumber; i++) {
        convolution(image, kernels[i], i, resultFeatureMap[i]);
    }
}
