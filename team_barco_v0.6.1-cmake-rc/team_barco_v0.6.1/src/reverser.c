#include <stdio.h>
#include <string.h>
#include "defines.h"
#include "functions.h"

int reverseCheck(char *tempString) {
    if (strcmp(tempString, SIX) == 0) {
            return EXIT_FAILURE;
    } else {
        return EXIT_SUCCESS;
    }
}

void decodedArrReverse(int *finalBarcode, int sizeFinalBarcode) {
    for (int low = 0, high = sizeFinalBarcode - 1; low < high; low++, high--) {
        int temp = finalBarcode[low];
        finalBarcode[low] = finalBarcode[high];
        finalBarcode[high] = temp;
    }
}

char *strrev(char *str) {
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}