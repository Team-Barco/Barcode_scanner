#include <stdio.h>
#include "functions.h"
#include "defines.h"


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

        char *finalBarcode = NULL;
        finalBarcode = (char *)malloc((counter) * sizeof(char));
        if (binArr == NULL) {
            exit(1);
        }

        decodeBinary(binArr, finalBarcode);

        if (strlen(finalBarcode) < 3) {
            printf("Invalid barcode. Try to move the scanner to left or right.\n");
        } else {
            printf("Barcode: %s \n", finalBarcode);
            printf("The barcode is correct: %d\n", checkC(finalBarcode));
            printf("The barcode is correct K: %d\n", checkK(finalBarcode));
        }
        
        free(binArr);
        free(numArr);
        free(finalBarcode);

    }
    

    // free(buffer);
    
    
    // printf("\n");
    // for (int i = 0; i < counter; i++) {
    //     printf("%c", binArr[i]);
    // }
    // printf("\n");

    
    
    
    return 0;
}






