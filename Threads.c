#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Threads.h"

void produceThread(char* cat, FILE *orderFile, Node clients[]){
    FILE *catFile = fopen(cat, "r");
    char *catString;
    if(catFile!=NULL)
        createCategories(catFile, catString);
    else
        catString = cat;
    scanOrders(orderFile, clients);
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

void scanOrders(FILE *orderFile, Node clients[]){
    char temp[1000];
    while(fgets(temp, 1000, orderFile)!=NULL){
        char *token = strtok(temp, "|");
        int index;
        token = (NULL, "|");
        token = (NULL, "|");
        index = atoi(token);
        index = index-1;
        //this is where the consumer threads will be called
        orders(&clients[index], temp);
    }
}

void orders(Node *client, char* book){
    char *token;
    int info = 0;
    float price;
    Node *currBook = (Node *)malloc(sizeof(Node));
    token = strtok(book, "|");
    while(token!=NULL){
        if(info == 0)
            currBook->name = token;
        if(info == 1){
            price = atof(token);
            currBook->price = price;
        }
        info++;
        token = strtok(NULL, "|");
    }
    Node *ptr;
    free(token);
    float currPrice = client->total;
    if(currPrice-price<0){
        ptr = client;
        while(ptr->nextFail!=NULL){
            ptr = ptr->nextFail;
        }
        ptr->nextFail = currBook;
        ptr = ptr->nextFail;
        ptr->nextFail=NULL;
    }
    else{
        ptr = client;
        currBook->total = currPrice - price;
        client->total = currPrice - price;
        while(ptr->nextSucc!=NULL){
            ptr = ptr->nextSucc;
        }
        ptr->nextSucc = currBook;
        ptr = ptr->nextSucc;
        ptr->nextSucc=NULL;
    }
}





























