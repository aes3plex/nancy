#ifndef NANCY_ARRAY_H
#define NANCY_ARRAY_H

typedef float c_float;
typedef int c_int;

class Array {
private:
    c_float* array;
    c_int height;
    c_int width;
    c_int size;

public:
    Array();
    Array(c_float* array, c_int height, c_int width);
    c_int getSize();
    c_int getHeight();
    c_int getWidth();
    c_float *getArray();
    c_float getElement(c_int i);
    c_float getElement(c_int i, c_int j);

    void setArray(c_float *c_array);
    void setHeight(c_int c_height);
    void setWidth(c_int c_width);
    void setSize(c_int c_size);
    void setElement(c_int index, c_float element);

    c_float sum();
    c_float sum(c_int startIndex, c_int stopIndex);

    void multiply(Array multiplier, Array result);
    void getArea(
            c_int rowStartIndex,
            c_int rowFinishIndex,
            c_int columnStartIndex,
            c_int columnFinishIndex,
            Array result
    );

    c_float max();
    void print();
};


#endif //NANCY_ARRAY_H
