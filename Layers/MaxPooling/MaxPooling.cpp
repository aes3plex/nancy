#include "MaxPooling.h"
#include "../../Array/Array.h"


MaxPooling::MaxPooling(int kernelSize) {
    this -> kernelSize = kernelSize;
}

float** MaxPooling::pool(float image[POOL_IMAGE_SIZE][POOL_IMAGE_SIZE]) {
    const int RESULT_SIZE = POOL_IMAGE_SIZE / 2;
    float** result = Array::initialize2dArray(RESULT_SIZE, RESULT_SIZE);
    int resultRowIndex, resultColumnIndex = 0;

    for (int rowIndex = 0; rowIndex < POOL_IMAGE_SIZE; rowIndex += kernelSize) {
        resultRowIndex = 0;
        for (int columnIndex = 0; columnIndex < POOL_IMAGE_SIZE; columnIndex += kernelSize) {
                // todo: getArea + arrayMax functions
                float rowMax = std::max(image[rowIndex][columnIndex], image[rowIndex + 1][columnIndex]);
                float columnMax = std::max(image[rowIndex][columnIndex + 1], image[rowIndex + 1][columnIndex + 1]);
                float max = std::max(rowMax, columnMax);

                result[resultRowIndex][resultColumnIndex] = max;
            resultRowIndex++;
        }
        resultColumnIndex++;
    }

    return result;
}

