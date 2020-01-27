#include "Activations.h"


c_float Activations::ReLU(c_float arg) {
    return arg > 0 ? arg : 0.0;
}