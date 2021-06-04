#include <stdio.h>
#include "functions.h"
#include "defines.h"

int reverseCheckFlag = 0;

int main(void){

    getNumOfTests();
    for (int i = 0; i < numOfTests; i++) {
        getNumOfSensors();
        char *buffer = NULL;
        buffer = (char *)malloc((2 * numOfSensors) * sizeof(char));
        if (buffer == NULL) {
            exit(1);
        }
        char *numArr = NULL;
        numArr = (char *)malloc(numOfSensors * sizeof(char));
        if (numArr == NULL) {
            exit(1);
        }

        getSensorsData(buffer, numArr); 

        char *binArr = NULL;
        binArr = (char *)malloc((counter) * sizeof(char));
        if (binArr == NULL) {
            exit(1);
        }

        sensorsBinaryParser(binArr, numArr);

        printf("Counter before decodeBinary: %d\n", counter);

        int tempBarcode[counter];

        decodeBinary(binArr, tempBarcode);
        printf("Counter after decodeBinary: %d\n", counter);
        int finalBarcode[counter - 1];
        int sizeFinalBarcode = counter - 1;

        for (int k = 0; k < counter; k++) {
            finalBarcode[k] = tempBarcode[k];
            // printf("%d , %d ZZZ\n", tempBarcode[i], i);
        }

        printf("ReversecheckFlag: %d\n", reverseCheckFlag);

        if (reverseCheckFlag == 1) {
        decodedArrReverse(finalBarcode, sizeFinalBarcode);
        }

        for (int j = 0; j < counter; j++)
        {
            printf("%d FFF  ", finalBarcode[j]);
        }
        printf("\n");

        if (counter < 3 ) {
            if (finalBarcode[0] == -1 && reverseCheckFlag == 0) {
                printf("Barcode truncated. Move scanner to right.\n");
            } else if(finalBarcode[0] == -1 && reverseCheckFlag == 1) {
                printf("Barcode truncated. Move scanner to left.\n");
            } else {
                printf("Invalid barcode!");
            }
        } else if (checkC(finalBarcode, sizeFinalBarcode) && checkK(finalBarcode, sizeFinalBarcode)) {
            printf("Valid barcode.");
            printf("\n");
            printBarcode(finalBarcode, sizeFinalBarcode);
            printf("Barcode C number check: %s \n", checkC(finalBarcode, sizeFinalBarcode));
            printf("Barcode K number check: %d \n", checkK(finalBarcode, sizeFinalBarcode));
        }

        free(binArr);
        free(numArr);
    }
    return 0;
}

void printBarcode(int *finalBarcode, int sizeFinalBarcode) {
    printf("Barcode: ");
    for (int i = 1; i <= sizeFinalBarcode - 3; i++) {
        if (finalBarcode[i] == 10) {
            printf("%c ", '-');
        } else {
            printf("%d ", finalBarcode[i]);
        }
    }
    printf("\n");
}