#ifndef NANCY_CON2D_H
#define NANCY_CON2D_H

#include "../../Array/Array.h"

class Con2d {
private:
    int padding;

public:
    Con2d(c_int padding);
    void convolution(Array image, Array kernel, Array result);
};


#endif //NANCY_CON2D_H
