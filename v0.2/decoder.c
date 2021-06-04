#include <stdio.h>
#include "defines.h"
#include "functions.h"


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
        //     numArr[j] = 1;
        //     j++;
        //     i++;
        //     numArr[j] = 1;
        //     j++;
        //     i++;
        //     continue;
        // }
    
        
        if (numArr[i] == '1' && numArr[i+1] == '0' && numArr[i+2] == '0' && numArr[i+3] == '1') {
            binArr[j] = '1';
            j++;
        } 
        if (numArr[i] == '1' && numArr[i+1] == '0' && numArr[i+2] == '1') {
            binArr[j] = '0';
            j++;
        }
        
        
        
        // if ((numArr[i] == 1) && (numArr[i+1] == 0) && (numArr[i+2] == 0)) {
        //     binArr[j] = 1;
        //     j++;
        // } 
        // if ((numArr[i] == 1) && (numArr[i+1] == 0) && (numArr[i+2] == 1)) {
        //     binArr[j] = 0;
        //     j++;
        // }        
        index++;
    }
}

void decodeBinary(char *binArr) {
    static int splitValue = 5;
    int start = 0;
    int end = 0;
    int number;

    for (int i = 1; i < counter; i++) {
        if (i % 5 == 0) {
            end = i;
            decoder(binArr, start, end);
            start = end;
        }
        
    }  

}

void decoder(char *binArr, int start, int end) {
    char *tempString = NULL;
    tempString = (char *)malloc(6 * sizeof(char));
    if (tempString == NULL){
        exit(1);
    }

    int i = 0;

    for (; start + 1 <= end; start++) {
        tempString[i] = binArr[start];
        i++;
                
    }
    tempString[i+1] = '\0';
    i = 0;   

    printf("%s ", tempString);

    if ((strcmp(tempString, ZERO) == 0)) {
        printf("%d ", 0);
    } else if (strcmp(tempString, ONE) == 0) {
        printf("%d ", 1);
    } else if (strcmp(tempString, TWO) == 0) {
        printf("%d ", 2);
    } else if (strcmp(tempString, THREE) == 0) {
        printf("%d ", 3);
    } else if (strcmp(tempString, FOUR) == 0) {
        printf("%d ", 4);
    } else if (strcmp(tempString, FIVE) == 0) {
        printf("%d ", 5);
    } else if (strcmp(tempString, SIX) == 0) {
        printf("%d ", 6);
    } else if (strcmp(tempString, SEVEN) == 0) {
        printf("%d ", 7);
    } else if (strcmp(tempString, EIGHT) == 0) {
        printf("%d ", 8);
    } else if (strcmp(tempString, NINE) == 0) {
        printf("%d ", 9);
    } else if (strcmp(tempString, SLASH_TEN) == 0) {
        printf("%c ", '-');
    } else if (strcmp(tempString, START_STOP) == 0) {
        printf("%s ", "START_STOP");
    } else {
        printf("Unknown");
    }
    printf("\n");
    free(tempString);  

}