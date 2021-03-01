/*Ivan Stus 
 *cssc1943
 *CS530, Spring 2020
 *Assignment #1, hexDump/binDump
 *dbx.c - Source File
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbx.h"
#define size 255



FILE *fp;   //File pointer
char buffer[size];  //buffer to store characters from input file
int i;


int byte_toHex(char *file) { //Converting bytes from user file to Hex, outputs Hex  
    unsigned char buffLine[17]; //Initialized as max space for each line, hex accepts 16, Max+1
    int address = 0;
    int counter = 0;
    fp = fopen(file, "rb"); //Open file to read in characters   
    while((counter = fread(buffer, sizeof(unsigned char), 16, fp)) > 0) {   //While characters are still being read in file        
        printf("%07x:  ", address);                    
        address = address + 16;                      
        for (i = 0; i < 16; i++) {            
            if ((i % 16) == 0) {    //checks to see if buffline is finished
            if (i != 0)
                printf ("  %s\n", buffLine);
            if (buffer[i] == 0x00) exit(0);                     
        }        
        printf ("%02x", buffer[i]); //converts character to hex, with correct offset        
        if ((i % 2) == 1) 
            printf (" ");   //prints space after two hex chars are printed 
        if ((buffer[i] < 0x20) || (buffer[i] > 0x7e)){  //checks to see if there is an unreadable character
            buffLine[i % 16] = '.'; //print "." if there is unreadable character
        }
        else{
           buffLine[i % 16] = buffer[i];
        }    
        buffLine[(i % 16) + 1] = '\0';  //clears the line 
    }
    while ((i % 16) != 0) {
        printf ("   ");
        i++;
    }
    printf ("  %s\n", buffLine); 
    }
fclose(fp);  
} 


char *binaryConversion (unsigned int conv) { //Converting buffer[i] into its binary equivalent
    char bin[9] = {};    
    bin[0] = '\0';    
    unsigned int z;
    for (z = 128; z > 0; z >>= 1) {
        strcat(bin, ((conv & z) == z) ? "1" : "0");
    }
    char *array_pointer = bin;
    return array_pointer;
}


int byte_toBin(char *file) { //Converting bytes from user file to Binary, outputs binary
    unsigned char buffLine[7]; //Initialized as max space for each line, binary accepts 6, Max+1
    int address = 0;
    int counter = 0;
    fp = fopen(file, "rb"); //Opening file
    while((counter = fread(buffer, sizeof(unsigned char), 6, fp)) > 0) { //While contents in file 
        printf("%07x:  ", address);  
        address = address + 6; //Address + 6 for every line of iteration     
        for (i = 0; i < 6; i++) {
            if ((i % 6) == 0) {
            if (i != 0)
                printf ("  %s\n", buffLine);
            if (buffer[i] == 0x00) exit(0);
        }
        printf("%s", binaryConversion(buffer[i]));  //Converting buffer[i] to binary equivalent   
        printf (" ");   //print a space after every character is converted 
        if ((buffer[i] < 0x20) || (buffer[i] > 0x7e)){
            buffLine[i % 6] = '.';
        }
        else{
           buffLine[i % 6] = buffer[i];
        }    
        buffLine[(i % 6) + 1] = '\0'; 
    }
    while ((i % 6) != 0) {  //Spacing for readable characters
        printf ("   ");
        i++;
    }
    printf ("  %s\n", buffLine);    //Prints readable characters
    }    
fclose(fp);  
}


int main(int argc, char *argv[]) {    
    if (argc == 3) {    //checks to see if there are 3 statements in command prompt
        if (strcmp(argv[1], "-b") == 0) {   //if 2nd argument is "-b" continue to binary method            
            byte_toBin(argv[2]);
        }
        else {
            printf("Try Again");
        }
    }
    else if (argc == 2) {   //checks to see if there are 2 statements in command prompt     
        byte_toHex(argv[1]);        
    }
    else {
        printf("Try Again");
    }
}










