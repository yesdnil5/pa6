#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "BookOrder.h"

int main(int argc, char** argv){
    if(argc!=4){
        printf("Not the correct amount of arguments");
        return 1;
    }

    FILE *clientFile = fopen(argv[1], "r");
    if(clientFile == NULL){
        printf("Data Base file could not be opened.");
        return 1;
    }
    int numClients = numLines(clientFile);
    Client *clients = (Client *)malloc(sizeof(Client)*numClients);
    fclose(clientFile);
    clientFile = fopen(argv[1], "r");

    FILE *orderFile = fopen(argv[2], "r");
    if(orderFile == NULL){
        printf("Book Order file could not be opened.");
        return 1;
    }

    createClients(clientFile, clients);
    
    produceThread(argv[3], orderFile, clients);

    destroyClient(clients, numClients);
    fclose(clientFile);
    fclose(orderFile);
    return 0;
}

int numLines(FILE *clientFile){
    int lines = 0;
    char c;
    while((c=fgetc(clientFile))!=EOF){
        if(c=='\n')
            lines++;
    }
    return lines;
}

void createClients(FILE *cf, Client *clients){

    char temp[200];
    while(fgets(temp, 200, cf)!=NULL){
        char *token;
        int item = 1;
        int ids;
        Client *cl = (Client *)malloc(sizeof(Client));
        temp[strlen(temp)-1]='\0';
        token = strtok(temp, "|");
        while(token!=NULL){
            if(item==1){
                char* tk = (char*)malloc(sizeof(char)*strlen(token));
                tk = strcpy(tk, token);
                cl->name = tk;
            }
            //memmove(temp, temp+2, strlen(temp));
            if(item == 2)
                cl->id = atoi(token);
            if(item == 3)
                cl->price = atof(token);
            item++;
            token = strtok(NULL, "|");
        }
        clients[(cl->id)-1] = *cl;
        printf("%s", clients[0].name);
        free(cl);
    }

    return;
}

void destroyClient(Client clients[], int num){
    int i;
    for(i = 0; i<num; i++){
        free(clients[i].name);
        free(&clients[i]);
    }
    return;
}
