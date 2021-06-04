#include <stdio.h>
#include "defines.h"
#include "functions.h"

int reverseCheck(char *tempString) {
    if (strcmp(tempString, SIX) == 0) {
            return 1;
    } else {
        return 0;
    }
}

void decodedArrReverse(int *finalBarcode, int sizeFinalBarcode) {
    for (int low = 0, high = sizeFinalBarcode - 1; low < high; low++, high--) {
        int temp = finalBarcode[low];
        finalBarcode[low] = finalBarcode[high];
        finalBarcode[high] = temp;
    }
}