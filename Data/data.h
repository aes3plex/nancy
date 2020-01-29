#ifndef NANCY_DATA_H
#define NANCY_DATA_H

#include "../Array/Array.h"
#include "constants.h"


c_float imageArray[IMAGE_HEIGHT * IMAGE_WIDTH] = {
        0, 0, 0, 0, 0, 0,
        0, 7, 8, 9, 2, 0,
        0, 4, 1, 3, 1, 0,
        0, 2, 4, 2, 4, 0,
        0, 8, 5, 1, 3, 0,
        0, 0, 0, 0, 0, 0
};

c_float kernelsArray[FEATURES_MAPS_NUMBER][CONVOLUTION_KERNEL_HEIGHT * CONVOLUTION_KERNEL_WIDTH] = {
        {
                1, 0, 0,
                0, 1, 0,
                0, 0, 1
        },
        {
                0, 0, 0,
                0, 1, 0,
                0, 0, 0
        }
};


c_float biasesArray[FEATURES_MAPS_NUMBER] = {
        0, 0
};

c_float denseWeightsArray[DENSE_SIZE] {
        1, 2
};

c_float convolutionResultsArray[FEATURES_MAPS_NUMBER][CONVOLUTION_RESULT_HEIGHT * CONVOLUTION_RESULT_WIDTH];
c_float poolResultsArray[FEATURES_MAPS_NUMBER][POOL_RESULT_HEIGHT * POOL_RESULT_WIDTH];
c_float flattenResultArray[FLATTEN_SIZE];
c_float denseResultArray[DENSE_SIZE];

#endif //NANCY_DATA_H
