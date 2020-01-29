#include "Array.h"
#include <iostream>

Array::Array() {
    this -> array = {};
    this -> height = 0;
    this -> width = 0;
    this -> size = 0;
}

Array::Array(c_float *array, c_int height, c_int width) {
    this -> array = array;
    this -> height = height;
    this -> width = width;
    this -> size = width * height;
}

Array::Array(c_float *array, c_int width) {
    this -> array = array;
    this -> height = 1;
    this -> width = width;
    this -> size = width * height;
}

c_float Array::getElement(c_int i, c_int j) {
    return array[i * width + j];
}

c_float Array::getElement(c_int i) {
    return array[i];
}

c_int Array::getSize() {
    return size;
}

c_int Array::getHeight() {
    return height;
}

c_int Array::getWidth() {
    return width;
}

c_float* Array::getArray() {
    return array;
}

void  Array::setArray(c_float *c_array) {
    this -> array = c_array;
}

void Array::setElement(c_int index, c_float element) {
    array[index] = element;
}

void  Array::setHeight(c_int c_height) {
    this -> height = c_height;
}

void  Array::setWidth(c_int c_width) {
    this -> height = c_width;
}

void  Array::setSize(c_int c_size) {
    this -> size = c_size;
}

c_float Array::sum() {
    c_float result = 0.0;

    for(c_int i = 0; i < size; i++) {
        result += array[i];
    }

    return result;
}

c_float Array::sum(c_int startIndex, c_int stopIndex) {
    c_float result = 0.0;

    for(c_int i = startIndex; i < stopIndex; i++) {
        result += array[i];
    }

    return result;
}

void Array::multiply(Array multiplier, Array result) {
    // todo: check multiplier dimension
    if (size != multiplier.getSize() || size != result.getSize()) {
        std::cout <<  "Incorrect multiplier dimension";
    }

    for (c_int i = 0; i < size; i++) {
        result.setElement(i, getElement(i) * multiplier.getElement(i));
    }
}

void Array::getArea(
        c_int rowStartIndex,
        c_int rowFinishIndex,
        c_int columnStartIndex,
        c_int columnFinishIndex,
        Array result
) {
    c_int resultIndex = 0;

    for (c_int rowIndex = rowStartIndex; rowIndex <= rowFinishIndex; rowIndex++) {
        for (c_int columnIndex = columnStartIndex; columnIndex <= columnFinishIndex; columnIndex++) {
            result.setElement(resultIndex, getElement(rowIndex, columnIndex));

            resultIndex++;
        }
    }
}

c_float Array::max() {
    c_float max = array[0];
    for (c_int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}
void Array::print() {

    std::cout << std::endl << "array: [ ";
    for (c_int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]";

    std::cout << std::endl << "size: " << size;
    std::cout << std::endl << "height: " << height;
    std::cout << std::endl << "width: " << width;
}





