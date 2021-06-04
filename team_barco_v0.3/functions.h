#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <string.h>
#include <stdlib.h>
// #include "defines.h"

void getNumOfTests();
void getNumOfSensors();
void getSensorsData(char *buffer, char *numArr);
void sensorsBinaryParser(char *binArr, char *numArr);
void decodeBinary(char *binArr, char * finalBarcode);
void decoderStringBuilder(char *tempString, char *binArr, int start, int end);
void decoder(char *tempString, char *finalBarcode, int numOfRuns);
char *strrev(char *str);
_Bool checkC(char* finalBarcode);
_Bool checkK(char* finalBarcode);

#endif /* FUNCTIONS_H_ */