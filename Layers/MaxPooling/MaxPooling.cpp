#include "MaxPooling.h"


MaxPooling::MaxPooling(c_int kernelHeight, c_int kernelWidth, c_int kernelsNumber) {
    this -> kernelHeight = kernelHeight;
    this -> kernelWidth = kernelWidth;
    this -> kernelsNumber = kernelsNumber;
}

void MaxPooling::pool(Array image, Array result) {
    c_int resultIndex = 0;
    c_int imageHeight =  image.getHeight();
    c_int imageWidth = image.getWidth();

    // check output dimensions
    if (result.getHeight() != imageHeight / kernelHeight || result.getWidth() == imageWidth / kernelWidth) {
        // handle
    }

    for (c_int rowIndex = 0; rowIndex < imageHeight; rowIndex += kernelHeight) {
        for (c_int columnIndex = 0; columnIndex < imageWidth; columnIndex += kernelWidth) {
            c_int rowStartIndex = rowIndex;
            c_int rowFinishIndex = rowIndex + kernelHeight - 1;
            c_int columnStartIndex = columnIndex;
            c_int columnFinishIndex = columnIndex + kernelWidth - 1;

            c_float areaArray[kernelHeight * kernelWidth];
            Array area(areaArray, kernelHeight, kernelWidth);

            image.getArea(rowStartIndex, rowFinishIndex, columnStartIndex, columnFinishIndex, area);
            result.setElement(resultIndex, area.max());

            resultIndex++;
        }
    }
}

void MaxPooling::getOutput(Array *convolutionFeatureMap, Array *poolFeatureMap) {
    for (c_int i = 0; i < kernelsNumber; i++) {
        pool(convolutionFeatureMap[i], poolFeatureMap[i]);
    }
}


