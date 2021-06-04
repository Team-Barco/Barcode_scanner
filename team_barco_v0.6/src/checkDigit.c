#include <stdio.h>
#include <stdbool.h>
#include "defines.h"
#include "functions.h"

bool checkC(int *finalBarcode, int sizeFinalBarcode){
    int sum = 0;
    int lastElemArr = sizeFinalBarcode;
    // printf("lastElement: %d\n", lastElemArr);
    int checkC = finalBarcode[lastElemArr - 2];
    int n = (lastElemArr - 2) - 1;
    // printf("nC: %d\n", checkC);

    for(int i = 1; i <= n; i++) {
        // sum += (((n - i + 1)%10)+1) * (finalBarcode[i - 1]);

            sum += (((n - i) % 10 + 1) * (finalBarcode[i]));
    }
    // printf("sumC: %d\n", (sum % 11));
    return sum % 11 == checkC ? "Valid" : "Invalid";
}

bool checkK(int *finalBarcode, int sizeFinalBarcode){
    int sum = 0;
    int lastElemArr = sizeFinalBarcode;
    int checkC = finalBarcode[lastElemArr - 2];
    int checkK = finalBarcode[lastElemArr - 1];
    int n = (lastElemArr - 2) - 1;
    // printf("nK: %d\n", checkK);
    for(int i = 1; i <= n; i++){
            sum += (((n - i + 1) % 9 + 1) * (checkC));
    }
    // printf("sumK: %d\n", (sum % 11) - 1);
    return (sum % 11) - 1 == checkK ? "Valid" : "Invalid";
}