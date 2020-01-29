#include <iostream>
#include "Dense.h"
#include "../../Activations/Activations.h"

Dense::Dense(c_int neuronsNumber, Array weights, Array biases) {
    // todo: check weights and biases dimensions
    if (biases.getSize() != neuronsNumber || weights.getSize() != neuronsNumber) {
        std::cout << "Incorrect weights / biases dimension";
    }

    this -> neuronsNumber = neuronsNumber;
    this -> weights = weights;
    this -> biases = biases;
}

c_float Dense::getNeuronOutput(c_int index, Array input) {
    c_float neuronOutput = 0;
    c_float weight = weights.getElement(index);
    c_float bias = biases.getElement(index);

    for (c_int i = 0; i < input.getSize(); i++) {
        neuronOutput += weight * input.getElement(i);
    }

    return neuronOutput + bias;
}

void Dense::getOutput(Array flatten, Array result) {
    c_float resultSize = result.getSize();

    // todo: check weights / biases and result dimension
    if (resultSize != neuronsNumber) {
        std::cout << "Incorrect result dimension";
    }

    for (c_int resultIndex = 0; resultIndex < resultSize; resultIndex++) {
        c_float resultElem = getNeuronOutput(resultIndex, flatten);
        result.setElement(resultIndex, resultElem);
    }

    Activations::softmax(result);
}

