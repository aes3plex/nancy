#include "cnn.h"
#include "Data/constants.h"


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

    Con2d con2d(IMAGE_PADDING, kernels, FEATURES_MAPS_NUMBER, biases);
    con2d.getOutput(image, convolutionResult);

    MaxPooling maxPooling(POOL_KERNEL_HEIGHT, POOL_KERNEL_WIDTH, FEATURES_MAPS_NUMBER);
    maxPooling.getOutput(convolutionResult, poolResult);

    Flatten::flatten(poolResult, FEATURES_MAPS_NUMBER, POOL_KERNEL_HEIGHT * POOL_KERNEL_WIDTH, flattenResult);

    Dense dense(DENSE_SIZE, weights, biases);
    dense.getOutput(flattenResult, denseResult);

    for(c_int i = 0; i < denseResult.getSize(); i++) {
        output[i] = denseResult.getElement(i);
    }

    denseResult.print();
}