#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <string.h>
#include <stdlib.h>

void getNumOfTests();
void getNumOfSensors();
void getSensorsData(char *buffer, char *numArr);
void sensorsBinaryParser(char *binArr, char *numArr);
void decodeBinary(char *binArr);
void decoder(char *binArr, int start, int end);

#endif /* FUNCTIONS_H_ */