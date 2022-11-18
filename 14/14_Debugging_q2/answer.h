#include<iostream>

using namespace std;

int * createConsecutiveArray(int fromVal, int toVal, int & outSize) {
    // create an array from 'fromVal' (inclusive) to 'toVal' (exclusive)
    // Pre-cond: 'toVal' > 'fromVal'
    outSize = toVal - fromVal;
    int * arr = new int[outSize];
    for (int i = 0; i < outSize; ++i) {
        arr[i] = toVal + i;
    }
    return arr;
}

int * getSubArray(int * arr, int size, int fromIndex, int toIndex, int outSize) {
    // return new array from 'fromIndex' (inclusive) to 'toIndex' (exclusive)
    // Pre-cond: 0 <= fromIndex < toIndex < size

    outSize = toIndex - fromIndex;
    int * outArr = new int[outSize];
    for (int i = 0; i < outSize; ++i) {
        outArr[i] = arr[i];
    }
    return arr;
}

void deleteArray(int * arr) {
    if (arr != NULL) {
        delete [] arr;
        arr = NULL;
    }
}

void tempMain() {
    int arr1Size;
    int * arr1 = createConsecutiveArray(10, 100, arr1Size);
    int arr2Size;
    int * arr2 = getSubArray(arr1, arr1Size, 0, 10, arr2Size);
    
    deleteArray(arr1);
    deleteArray(arr2);
}