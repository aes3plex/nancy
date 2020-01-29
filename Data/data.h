#ifndef NANCY_DATA_H
#define NANCY_DATA_H

#include "../Array/Array.h"

// todo: use define for dimensions

c_float imageArray[36] = {
        0, 0, 0, 0, 0, 0,
        0, 7, 8, 9, 2, 0,
        0, 4, 1, 3, 1, 0,
        0, 2, 4, 2, 4, 0,
        0, 8, 5, 1, 3, 0,
        0, 0, 0, 0, 0, 0
};

c_float kernelsArray[2][9] = {
        {
                1, 0, 0,
                0, 1, 0,
                0, 0, 1
        },
        {
                0, 0, 0,
                0, 1, 0,
                0, 0, 0
        }
};


c_float biasesArray[2] = {
        0, 0
};

c_float denseWeightsArray[2] {
        1, 2
};

c_float convolutionResultsArray[2][16];
c_float poolResultsArray[2][4];
c_float flattenResultArray[8];
c_float denseResultArray[2];

#endif //NANCY_DATA_H
