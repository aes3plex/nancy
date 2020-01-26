#include <iostream>
#include <algorithm>

#ifndef NANCY_MAXPOOLING_H
#define NANCY_MAXPOOLING_H
#define POOL_IMAGE_SIZE 6

class MaxPooling {
private:
    int kernelSize;
public:
    MaxPooling(int kernelSize);
    float** pool(float image[POOL_IMAGE_SIZE][POOL_IMAGE_SIZE]);
};


#endif //NANCY_MAXPOOLING_H
