#include <iostream>
#include "Con2d.h"
#include "../../Array/Array.h"

Con2d::Con2d() {
    this->padding = 1;
}


// input image include padding
void Con2d::convolution(Array image, Array kernel, Array result) {
//    int resultIndex = 0;
//
//    for (int rowIndex = padding; rowIndex < image.getHeight() - padding; rowIndex++) {
//        for (int columnIndex = padding; columnIndex < image.getWidth() - padding; columnIndex++) {
//            int rowStartIndex = rowIndex - padding;
//            int rowFinishIndex = rowIndex + padding;
//            int columnStartIndex = columnIndex - padding ;
//            int columnFinishIndex = columnIndex + padding;
//
//            c_float area[kernel.getHeight() * kernel.getWidth()];
//            image.getArea(rowStartIndex, rowFinishIndex, columnStartIndex, columnFinishIndex, area);
//            kernel.multiply(area, area);
//            float sum = Array::sum(multiplied, KERNEL_SIZE);
//
//            result[resultRowIndex][resultColumnIndex] = sum;
//
//            resultRowIndex++;
//        }
//        resultColumnIndex++;
//    }
}
