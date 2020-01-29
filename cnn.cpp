#include "cnn.h"


void cnn(
        Array image,
        Array *kernels,
        Array biases,
        Array weights,
        Array *convolutionResult,
        Array *poolResult,
        Array flattenResult,
        Array denseResult,
        c_float *output) {

    Con2d con2d(1, kernels, 2, biases);
    con2d.getOutput(image, convolutionResult);

    MaxPooling maxPooling(2, 2, 2);
    maxPooling.getOutput(convolutionResult, poolResult);

    Flatten::flatten(poolResult, 2, 4, flattenResult);

    Dense dense(2, weights, biases);
    dense.getOutput(flattenResult, denseResult);

    for(c_int i = 0; i < denseResult.getSize(); i++) {
        output[i] = denseResult.getElement(i);
    }
}