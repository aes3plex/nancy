#ifndef NANCY_ARRAY_H
#define NANCY_ARRAY_H
#define IMAGE_SIZE 6
#define KERNEL_SIZE 9

class Array {
public:
    static float sum (const float* array, int size);
    static float* multiply(float* first, float* second, int size);
    static float **initialize2dArray(int rows, int columns);
    static float *getArea(float array[IMAGE_SIZE][IMAGE_SIZE], int rowStartIndex, int rowFinishIndex, int columnStartIndex, int columnFinishIndex);
};


#endif //NANCY_ARRAY_H
