#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "defines.h"
#include "functions.h"

int numOfRuns = 0;

void sensorsBinaryParser(char *binArr, char *numArr) {
    /* transform sensor data to binary format */
    int j = 0;
    int index = 0;
    for (int i = 0; i < counter; i++) {
        if (i + 2 == counter) {
            break;
        }
        // if ((numArr[i] == 0) && (numArr[i+1] == 0) && (numArr[i+2] == 0)) {
        //     break;
        // }
        if (numArr[i] == '1' && numArr[i+1] == '1' && numArr[i+2] == '1') {
            continue;
        }

        // if (numArr[i] == 0 && numArr[i+1] == 0 && numArr[i+2] == 0 && numArr[i+3] == 0) {
        //     numArr[j] = 1;
        //     j++;
        //     numArr[j] = 0;
        //     j++;
        //     i++;
        //     // numArr[j] = 1;
        //     // j++;
        //     // i++;
        //     // continue;
        // }
        
        if (numArr[i] == '1' && numArr[i+1] == '0' && numArr[i+2] == '0' && numArr[i+3] == '1') {
            binArr[j] = '1';
            j++;
        } 

        if (numArr[i] == '1' && numArr[i+1] == '0' && numArr[i+2] == '1') {
            binArr[j] = '0';
            j++;
        }    
        index++;
    }
    binArr[j] = '\0';

    printf("BinArr string: %s \n", binArr);
}

void decodeBinary(char *binArr, char *finalBarcode) {
    /* splits the binary data in groups of 5 */
    static int invalidBarcoCheck = 0;   
    if (numOfRuns > 1) {
        invalidBarcoCheck = 0;
    }

    char *invalidBarcoMsg = NULL;
    invalidBarcoMsg = (char *)malloc(sizeof(invalidBarcoMsg));
    if (invalidBarcoMsg == NULL) {
        exit(1);
    }
    
    static int splitValue = 5;
    int start = 0;
    int end = 0;
    int sizeOfBinGroup = 6;
    int i = 0;
    char *tempString = NULL;
    tempString = (char *)malloc(sizeOfBinGroup * sizeof(char));
    if (tempString == NULL) {
        exit(1);
    }
    
    int reverseCheck = 0;
    
    for (i = 1; binArr[i] != '\0'; i++) {
        if (i % splitValue == 0) {
            end = i;
            decoderStringBuilder(tempString, binArr, start, end);
            tempString[i+1] = '\0';
            start = end;
            // if (strcmp(tempString, SIX) && reverseCheck == 0 && start == 0) {
            //     // strrev(tempString);
            //     strrev(binArr);
            //     printf("Reversed binArr: %s \n", binArr);
            //     i = 1;
            //     reverseCheck++;
            //     continue;
            // }
            
            decoder(tempString, finalBarcode, numOfRuns);
            
            reverseCheck++;
        }
               
    }

    for (int i = 0; finalBarcode[i] != '0'; i++) {
        if (strcmp(finalBarcode, "6") != 0 || strcmp(finalBarcode, "START_STOP") != 0){
            invalidBarcoCheck++;
        }
    }
    

    if (invalidBarcoCheck == 0 || strlen(finalBarcode) < 3){
        invalidBarcoMsg = "Invalid barcode. Try to move the scanner to left or right.";
        finalBarcode = NULL;
        finalBarcode = invalidBarcoMsg;
    }
    numOfRuns++;
    free(tempString);

}

void decoderStringBuilder(char *tempString, char *binArr, int start, int end) {
    int i = 0;

    for (; start + 1 <= end; start++) {
        tempString[i] = binArr[start];
        i++;
    }
}

void decoder(char *tempString, char *finalBarcode, int numOfRuns) {
    printf("Temp String: %s \n", tempString);
    static int startStopFlag = 0;

    if (numOfRuns > 1) {
        startStopFlag = 0;
    }

    if ((strcmp(tempString, ZERO) == 0)) {
        strcat(finalBarcode, "0 ");
    } else if (strcmp(tempString, ONE) == 0) {
        strcat(finalBarcode, "1 ");
    } else if (strcmp(tempString, TWO) == 0) {
        strcat(finalBarcode, "2 ");
    } else if (strcmp(tempString, THREE) == 0) {
        strcat(finalBarcode, "3 ");
    } else if (strcmp(tempString, FOUR) == 0) {
        strcat(finalBarcode, "4 ");
    } else if (strcmp(tempString, FIVE) == 0) {
        strcat(finalBarcode, "5 ");
    } else if (strcmp(tempString, SIX) == 0) {
        strcat(finalBarcode, "6 ");
    } else if (strcmp(tempString, SEVEN) == 0) {
        strcat(finalBarcode, "7 ");
    } else if (strcmp(tempString, EIGHT) == 0) {
        strcat(finalBarcode, "8 ");
    } else if (strcmp(tempString, NINE) == 0) {
        strcat(finalBarcode, "9 ");
    } else if (strcmp(tempString, SLASH_TEN) == 0) {
        strcat(finalBarcode, "- ");
    } else if (strcmp(tempString, START_STOP) == 0) {
        strcat(finalBarcode, "START_STOP ");
        startStopFlag++;
    }

}

bool checkC(char* finalBarcode){

    for(int k = 0; finalBarcode[k] != '\0'; k++){
        int num = atoi(finalBarcode++);
        printf("%d\n", num);
    }

    int sum = 0;
    int lastElemArr = ((sizeof(finalBarcode) / sizeof(finalBarcode[0])) - 1);
    int n = finalBarcode[lastElemArr - 2] - '0';
    printf("n: %d\n", n);
    for(int i = 1;i <= n; i++){
        sum += (((n - i + 1)%10)+1) * (finalBarcode[i - 1] - '0');
    }
    printf("%d\n", sum);
    return sum % 11 == finalBarcode[n] ? true : false;
}

bool checkK(char* finalBarcode){
    int sum = 0;
    int lastElemArr = ((sizeof(finalBarcode) / sizeof(finalBarcode[0])) - 1);
    int n = finalBarcode[lastElemArr - 2];

    for(int i = 1;i <= n + 1; i++){
        sum += (((n - i + 1)%9)+1) * finalBarcode[i - 1];
    }
    return sum % 11 == finalBarcode[n + 1] ? true : false;
}