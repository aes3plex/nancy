#include <iostream>
#include "Array/Array.h"
#include "Layers/Con2d/Con2d.h"

using namespace std;


int main() {
    float array[IMAGE_SIZE][IMAGE_SIZE] = {
            {0, 0, 0, 0, 0, 0},
            {0, 7, 8, 9, 2, 0},
            {0, 4, 1, 3, 1, 0},
            {0, 2, 4, 2, 4, 0},
            {0, 8, 5, 1, 3, 0},
            {0, 0, 0, 0, 0, 0}
    };


//    Con2d con2d;
//    float kernel[KERNEL_SIZE] = { 0, 0, 0, 0, 1, 0, 0, 0, 0 };
//    float *kernelPtr;
//    kernelPtr = kernel;
//
//    float** convResult = con2d.convolution(array, kernelPtr);


    return 0;
}
