#include <cmath>
#include "Activations.h"


c_float Activations::ReLU(c_float arg) {
    return arg > 0 ? arg : 0.0;
}

void Activations::softmax(Array array) {
    c_float sum = 0;
    c_float max = array.max();

    for (c_int i = 0; i < array.getSize(); i++) {
        sum += expf(array.getElement(i) - max);
    }

    for (c_int i = 0; i < array.getSize(); i++) {
        c_float elem = expf(array.getElement(i) - max - logf(sum));
        array.setElement(i, elem);
    }
}

