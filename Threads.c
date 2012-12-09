#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Threads.h"

void produceThread(char* cat, FILE *orderFile, Client clients[]){
    FILE *catFile = fopen(cat, "r");
    char *catString;
    if(catFile!=NULL)
        createCategories(catFile, catString);
    else
        catString = cat;
    return;
}

void createCategories(FILE *catFile, char* catString){
    catString[2000];
    char temp[100];
    char* space = " \0";
    while(fgets(temp, 100, catFile)!=NULL){
        temp[strlen(temp)-1]='\0';
        strcat(catString, temp);
        strcat(catString, space);
    }
    memmove(catString, catString+2, strlen(catString));
    fclose(catFile);
    return;
}

void scanOrders(FILE *orderFile){
    char temp[1000];
    while(fgets(temp, 1000, orderFile)!=NULL){
        char token = strtok(temp, "|");
        
    }
}
