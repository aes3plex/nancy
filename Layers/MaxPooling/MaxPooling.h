#ifndef NANCY_MAXPOOLING_H
#define NANCY_MAXPOOLING_H

#include "../../Array/Array.h"


class MaxPooling {
private:
    c_int kernelHeight;
    c_int kernelWidth;
    c_int kernelsNumber;

    void pool(Array image, Array result);

public:
    MaxPooling(c_int kernelHeight, c_int kernelWidth, c_int kernelsNumber);
    void getOutput(Array *convolutionFeatureMap, Array *poolFeatureMap);
};


#endif //NANCY_MAXPOOLING_H
