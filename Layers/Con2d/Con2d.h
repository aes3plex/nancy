#ifndef NANCY_CON2D_H
#define NANCY_CON2D_H

#include "../../Array/Array.h"

class Con2d {
private:
    c_int padding;
    Array *kernels;
    c_int kernelsNumber;

    void convolution(Array image, Array kernel, Array result);
public:
    Con2d(c_int padding, Array* kernels, c_int kernelsNumber);
    void getOutput(Array image, Array *resultFeatureMap);
};


#endif //NANCY_CON2D_H
