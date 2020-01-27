#ifndef NANCY_MAXPOOLING_H
#define NANCY_MAXPOOLING_H

#include "../../Array/Array.h"


class MaxPooling {
private:
    c_int kernelHeight;
    c_int kernelWidth;
public:
    MaxPooling(c_int kernelHeight, c_int kernelWidth);
    void pool(Array image, Array result);
};


#endif //NANCY_MAXPOOLING_H
