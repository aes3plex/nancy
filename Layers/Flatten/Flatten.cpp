#include "Flatten.h"

void Flatten::flatten(Array *featureMap, c_int mapSize, c_int featureSize, Array result) {
    c_int resultIndex = 0;

    for (c_int featureIndex = 0; featureIndex < mapSize; featureIndex++) {
        for (c_int elemIndex = 0; elemIndex < featureSize; elemIndex++) {
            c_float insertedElem = featureMap[featureIndex].getElement(elemIndex);
            result.setElement(resultIndex, insertedElem);

            resultIndex++;
        }
    }
}
