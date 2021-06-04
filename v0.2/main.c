#include <stdio.h>
#include "functions.h"


int main(void){
    char *buffer = NULL;
    size_t bufsize = 512;

    buffer = (char *)malloc(bufsize * sizeof(char));

    if (buffer == NULL){
        exit(1);
    }

    char *numArr = NULL;

    numArr = (char *)malloc(bufsize * sizeof(char));

    if (numArr == NULL){
        exit(1);
    }


    getNumOfTests();
    getNumOfSensors();
    printf("\n");
    getSensorsData(buffer, numArr);
    
    int binBuf = 512;
    char *binArr = NULL;
    binArr = (char *)malloc((counter) * sizeof(char));

    if (binArr == NULL){
        exit(1);
    }

    sensorsBinaryParser(binArr, numArr);

    printf("\n");
    for (int i = 0; i < counter; i++) {
        printf("%c", binArr[i]);
    }
    printf("\n");

    decodeBinary(binArr);
    
    free(buffer);
    free(binArr);
    free(numArr);
    return 0;
}






