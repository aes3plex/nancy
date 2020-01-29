#ifndef NANCY_ACTIVATIONS_H
#define NANCY_ACTIVATIONS_H

#include "../Array/Array.h"


class Activations {
public:
    static c_float ReLU(c_float arg);
    static void softmax(Array array);
};

#endif //NANCY_ACTIVATIONS_H
