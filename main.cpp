#include "Array/Array.h"
#include "Data/data.h"
#include "cnn.h"


int main() {
    // inputs
    Array image(imageArray, 6, 6);
    Array biases(biasesArray, 1, 2);
    Array weights(denseWeightsArray, 1, 2);
    Array kernels[2] = {
            Array(kernelsArray[0], 3, 3),
            Array(kernelsArray[1], 3, 3)
    };


    // results
    Array convolutionResult[2] = {
            Array(convolutionResultsArray[0], 4, 4),
            Array(convolutionResultsArray[1], 4, 4),
    };
    Array poolResult[2] = {
            Array(poolResultsArray[0], 2, 2),
            Array(poolResultsArray[1], 2, 2)
    };
    Array flattenResult(flattenResultArray, 1, 8);
    Array denseResult(denseResultArray, 1, 2);


    // CNN
    c_float output[2];
    cnn(image, kernels, biases, weights, convolutionResult, poolResult, flattenResult, denseResult, output);

    return 0;
}
