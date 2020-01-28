#ifndef NANCY_DENSE_H
#define NANCY_DENSE_H


#include "../../Array/Array.h"

class Dense {
private:
    c_int neuronsNumber;
    Array weights;
    Array biases;

    c_float getNeuronOutput(c_int index, Array input);

public:
    Dense(c_int neuronsNumber, Array weights, Array biases);
    void getOutput(Array flatten, Array result);

};


#endif //NANCY_DENSE_H
