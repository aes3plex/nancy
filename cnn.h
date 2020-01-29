#ifndef NANCY_CNN_H
#define NANCY_CNN_H

#include "Array/Array.h"
#include "Layers/Con2d/Con2d.h"
#include "Layers/MaxPooling/MaxPooling.h"
#include "Layers/Flatten/Flatten.h"
#include "Layers/Dense/Dense.h"

void cnn(
        Array image,
        Array *kernels,
        Array biases,
        Array weights,
        Array *convolutionResult,
        Array *poolResult,
        Array flattenResult,
        Array denseResult,
        c_float *output);

#endif //NANCY_CNN_H
