#include <stdio.h>
#include "functions.h"
#include "defines.h"

void getNumOfTests() {
    printf("Enter the number of tests: ");
    scanf("%d", &numOfTests);
}

void getNumOfSensors() {
    printf("Enter the number of sensors: ");
    scanf("%d", &numOfSensors);
    getchar();
}

void getSensorsData(char *buffer, char *numArr) {
    /* get sensor data from terminal */
    size_t bufsize = 150;
    printf("Type something: ");
    int intArr[bufsize];
    float num;
    characters = getline(&buffer, &bufsize, stdin);

    const char s[2] = " ";
    char *token;
   
    /* get the first token */
    token = strtok(buffer, s);
    float n;
    int i = 0;
   
    /* walk through other tokens */
    for (int j = 0; j < strlen(buffer); j++) {
        while( token != NULL ) {
            n = atof(token);
            if (n > 0.50F) {
                numArr[i] = '1';
                i++;
            }
            if (n <= 0.50F) {
                numArr[i] = '0';
                i++;
            }
            token = strtok(NULL, s);
        }
    }
    int count = i;
    counter = i;

    // for (int j = 0; j < count; j++) {
    //     printf("%c ", numArr[j]);
    // }  
    // printf("\n");
}