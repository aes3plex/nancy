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

    c_float kernelArray1[9] = {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
    };

    c_float kernelArray2[9] = {
            0, 0, 0,
            0, 1, 0,
            0, 0, 0
    };

    c_float resultArray1[16];
    c_float resultArray2[16];
    c_float poolResultArray1[4];
    c_float poolResultArray2[4];

    Array image(imageArray,6, 6);

    Array kernel1(kernelArray1, 3, 3);
    Array kernel2(kernelArray2, 3, 3);

    Array kernels[2] = {
            kernel1, kernel2
    };


    Array result1(resultArray1, 4, 4);
    Array result2(resultArray2, 4, 4);
    Array poolResult1(poolResultArray1, 2, 2);
    Array poolResult2(poolResultArray2, 2, 2);

    Array convolutionFeatureMap[2] = {
            result1, result2
    };

    Array poolFeatureMap[2] = {
            poolResult1, poolResult2
    };

    Con2d con2d(1, kernels, 2);
    con2d.getOutput(image, convolutionFeatureMap);

    MaxPooling maxPooling(2, 2, 2);
    maxPooling.getOutput(convolutionFeatureMap, poolFeatureMap);

    poolFeatureMap[0].print();
    poolFeatureMap[1].print();

    return 0;
}
