#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

bool checkC();

int main(void){
    char *buffer = NULL;
    size_t bufsize = 512;

    buffer = (char *)malloc(bufsize * sizeof(char));

    if (buffer == NULL){
        perror("Error allocating memory!!");
        exit(EXIT_FAILURE);
    }

    char *numArr = NULL;

    numArr = (char *)malloc(bufsize * sizeof(char));

    if (numArr == NULL){
        perror("Error allocating memory!!");
        exit(EXIT_FAILURE);
    }

    getNumOfTests();
    getNumOfSensors();
    printf("\n");
    getSensorsData(buffer, numArr);

    //int binBuf = 512;
    char *binArr = NULL;
    binArr = (char *)malloc((counter) * sizeof(char));

    if (binArr == NULL){
        perror("Error allocating memory!!");
        exit(EXIT_FAILURE);
    }

    sensorsBinaryParser(binArr, numArr);

    printf("\n");
    for (int i = 0; i < counter; i++) {
        printf("%c", binArr[i]);
    }
    printf("\n");

    decodeBinary(binArr);

    printf("Print of the checkC func: %d\n", checkC());

    free(buffer);
    free(binArr);
    free(numArr);

    return EXIT_SUCCESS;
}

bool checkC(void){
    int deciArr[9] = {1,2,3,10,4,5,5,2};
    for (unsigned int k = 0; k < (sizeof(deciArr) / sizeof(deciArr[0])); k++){
        printf("%d\n", deciArr[k]);
        /* code */
    }

    int sum = 0;
    int lastElemArr = (sizeof(deciArr) / sizeof(deciArr[0]));
    printf("total elements: %d\n", lastElemArr);
    int n = deciArr[lastElemArr - 2];
    printf("%d\n", deciArr[8]);

    for(int i = 1;i <= n + 1; i++){
        sum += (((n - i + 1)%9)+1)* deciArr[i - 1];
    }
    return sum % 11 == deciArr[lastElemArr - 1] ? true : false;
}