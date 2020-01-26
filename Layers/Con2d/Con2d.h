#ifndef NANCY_CON2D_H
#define NANCY_CON2D_H

#include "../../Array/Array.h"

class Con2d {
private:
    int padding;

public:
    Con2d();
    float** convolution(float image[IMAGE_SIZE + 1][IMAGE_SIZE], float *kernel);
};


#endif //NANCY_CON2D_H
