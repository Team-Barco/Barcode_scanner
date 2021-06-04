#include <stdio.h>
#include <string.h>
#include "defines.h"
#include "functions.h"

int numOfRuns = 0;

void sensorsBinaryParser(char *binArr, char *numArr) {
    /* transform sensor data to binary format */
    int j = 0;

    for (unsigned int i = 0; i < strlen(numArr); i++) {
        if (i + 2 == strlen(numArr)) {
            break;
        }
        if (numArr[i] == '1' && numArr[i+1] == '1' && numArr[i+2] == '1') {
            continue;
        }

        if (numArr[i] == '1' && numArr[i+1] == '0' && numArr[i+2] == '0' && numArr[i+3] == '1') {
            binArr[j] = '1';
            j++;
        }
        if (numArr[i] == '1' && numArr[i+1] == '0' && numArr[i+2] == '1') {
            binArr[j] = '0';
            j++;
        }
    }
    binArr[j] = '\0';

    printf("BinArr string: %s \n", binArr);
}

void decodeBinary(char *binArr, int *tempBarcode) {
    /* splits the binary data in groups of 5 */

    static int splitValue = 5;
    int start, end = 0;
    int sizeOfBinGroup = 6;
    unsigned int i = 0;

    char *tempString = NULL;
    tempString = (char *)malloc(sizeOfBinGroup * sizeof(char));
    if (tempString == NULL) {
        perror("Error handling memory for tempString!!\n");
        exit(EXIT_FAILURE);
    }

    counter = 0;

    for (i = 1; i <= strlen(binArr); i++) {
        if (i % splitValue == 0) {
            end = i;
            decoderStringBuilder(tempString, binArr, start, end);
            tempString[i+1] = '\0';
            start = end;

            if (counter == 0) {
                reverseCheckFlag = reverseCheck(tempString);
            }
            if (reverseCheckFlag == 1) {
                strrev(tempString);
            }
            decoder(tempString, tempBarcode);
        }
    }

    free(tempString);
}

void decoderStringBuilder(char *tempString, char *binArr, int start, int end) {
    int i = 0;

    for(; start + 1 <= end; start++) {
        tempString[i] = binArr[start];
        i++;
    }
}

void decoder(char *tempString, int *tempBarcode) {
    printf("Temp String: %s \n", tempString);

    if ((strcmp(tempString, ZERO) == 0)) {
        tempBarcode[counter] = 0;
        counter++;
    } else if (strcmp(tempString, ONE) == 0) {
        tempBarcode[counter] = 1;
        counter++;
    } else if (strcmp(tempString, TWO) == 0) {
        tempBarcode[counter] = 2;
        counter++;
    } else if (strcmp(tempString, THREE) == 0) {
        tempBarcode[counter] = 3;
        counter++;
    } else if (strcmp(tempString, FOUR) == 0) {
        tempBarcode[counter] = 4;
        counter++;
    } else if (strcmp(tempString, FIVE) == 0) {
        tempBarcode[counter] = 5;
        counter++;
    } else if (strcmp(tempString, SIX) == 0) {
        tempBarcode[counter] = 6;
        counter++;
    } else if (strcmp(tempString, SEVEN) == 0) {
        tempBarcode[counter] = 7;
        counter++;
    } else if (strcmp(tempString, EIGHT) == 0) {
        tempBarcode[counter] = 8;
        counter++;
    } else if (strcmp(tempString, NINE) == 0) {
        tempBarcode[counter] = 9;
        counter++;
    } else if (strcmp(tempString, SLASH_TEN) == 0) {
        tempBarcode[counter] = 10;
        counter++;
    } else if (strcmp(tempString, START_STOP) == 0) {
        tempBarcode[counter] = -1;
        counter++;
    }
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