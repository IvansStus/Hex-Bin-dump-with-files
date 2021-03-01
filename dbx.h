/*Ivan Stus 
 *cssc1943
 *CS530, Spring 2020
 *Assignment #1, hexDump/binDump
 *dbx.h - header file
*/

#ifndef DBX_H
#define DBX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 255

FILE *fp;   //File pointer
char buffer[size];  //buffer to store characters from input file
int i;

int byte_toHex(char *file);
char *binaryConversion (unsigned int conv);
int byte_toBin(char *file);

#endif //DBX_H

