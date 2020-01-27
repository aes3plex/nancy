#include <iostream>
#include "Array/Array.h"
#include "Layers/Con2d/Con2d.h"
#include "Layers/MaxPooling/MaxPooling.h"

using namespace std;


int main() {
    c_float imageArray[36] = {
            0, 0, 0, 0, 0, 0,
            0, 7, 8, 9, 2, 0,
            0, 4, 1, 3, 1, 0,
            0, 2, 4, 2, 4, 0,
            0, 8, 5, 1, 3, 0,
            0, 0, 0, 0, 0, 0
    };

    c_float kernelArray[9] = {
            0, 0, 0,
            0, 1, 0,
            0, 0, 0
    };

    c_float resultArray[16] = {0};

    Array image(imageArray,6, 6);
    Array kernel(kernelArray, 3, 3);
    Array result(resultArray, 4, 4);

    Con2d con2d(1);
    con2d.convolution(image, kernel, result);
    result.print();

    return 0;
}
