#include <iostream>
#include "Array/Array.h"
#include "Layers/Con2d/Con2d.h"
#include "Layers/MaxPooling/MaxPooling.h"

using namespace std;


int main() {
//    float array[IMAGE_SIZE][IMAGE_SIZE] = {
//            {0, 0, 0, 0, 0, 0},
//            {0, 7, 8, 9, 2, 0},
//            {0, 4, 1, 3, 1, 0},
//            {0, 2, 4, 2, 4, 0},
//            {0, 8, 5, 1, 3, 0},
//            {0, 0, 0, 0, 0, 0}
//    };

//    MaxPooling maxPooling(2);
//    float ** result = maxPooling.pool(array);

//    Con2d con2d;
//    float kernel[KERNEL_SIZE] = { 0, 0, 0, 0, 1, 0, 0, 0, 0 };
//    float *kernelPtr = kernel;
//    float *arrayPtr = &array;
//
//    float** convResult = con2d.convolution(array, kernelPtr);
//    cout << convResult[0][0];

    float arr[6] = { 1, 2, 3, 4, 5, 6};
    Array array(
            arr,
            2,
            3
    );

//    c_float result[4];
//    testArray.getArea(0, 1, 0, 1, result);

//    for (float i : result) {
//        cout << i << " ";
//    }

    array.print();

    return 0;
}
