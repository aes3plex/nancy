#ifndef NANCY_FLATTEN_H
#define NANCY_FLATTEN_H


#include "../../Array/Array.h"

class Flatten {
public:
    static void flatten(Array* featureMap, c_int mapSize,  c_int featureSize, Array result);
};


#endif //NANCY_FLATTEN_H
