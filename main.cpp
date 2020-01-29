#include "Array/Array.h"
#include "Data/data.h"
#include "cnn.h"


int main() {
    // inputs
    Array image(imageArray, IMAGE_HEIGHT, IMAGE_WIDTH);
    Array biases(biasesArray, FEATURES_MAPS_NUMBER);
    Array weights(denseWeightsArray, DENSE_SIZE);
    Array kernels[FEATURES_MAPS_NUMBER] = {
            Array(kernelsArray[0], CONVOLUTION_KERNEL_HEIGHT, CONVOLUTION_KERNEL_WIDTH),
            Array(kernelsArray[1], CONVOLUTION_KERNEL_HEIGHT, CONVOLUTION_KERNEL_WIDTH)
    };

    // results
    Array convolutionResult[FEATURES_MAPS_NUMBER] = {
            Array(convolutionResultsArray[0], CONVOLUTION_RESULT_HEIGHT, CONVOLUTION_RESULT_WIDTH),
            Array(convolutionResultsArray[1], CONVOLUTION_RESULT_HEIGHT, CONVOLUTION_RESULT_WIDTH),
    };
    Array poolResult[FEATURES_MAPS_NUMBER] = {
            Array(poolResultsArray[0], POOL_RESULT_HEIGHT, POOL_RESULT_WIDTH),
            Array(poolResultsArray[1], POOL_RESULT_HEIGHT, POOL_RESULT_WIDTH)
    };
    Array flattenResult(flattenResultArray, FLATTEN_SIZE);
    Array denseResult(denseResultArray, DENSE_SIZE);


    // CNN
    c_float output[DENSE_SIZE];
    cnn(image, kernels, biases, weights, convolutionResult, poolResult, flattenResult, denseResult, output);

    return 0;
}
