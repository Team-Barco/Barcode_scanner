#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <string.h>
#include <stdlib.h>
// #include "defines.h"

void getNumOfTests();
void getNumOfSensors();
void getSensorsData(char *buffer, char *numArr);
void sensorsBinaryParser(char *binArr, char *numArr);
void decodeBinary(char *binArr, int *tempBarcode);
void decoderStringBuilder(char *tempString, char *binArr, int start, int end);
int reverseCheck(char *tempString);
void decodedArrReverse(int *finalBarcode, int sizeFinalBarcode);
void decoder(char *tempString, int *tempBarcode);
char *strrev(char *str);
_Bool checkC(int *finalBarcode, int sizeFinalBarcode);
_Bool checkK(int *finalBarcode, int sizeFinalBarcode);
void printBarcode(int *finalBarcode, int sizeFinalBarcode);

#endif /* FUNCTIONS_H_ */