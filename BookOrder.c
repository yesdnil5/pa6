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
    int i = 0;
    int numClients = numLines(clientFile);
    Node *clients = (Node *)malloc(sizeof(Node)*numClients);
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

void createClients(FILE *cf, Node *clients){

    char temp[200];
    while(fgets(temp, 200, cf)!=NULL){
        char *token;
        int item = 1;
        int ids;
        Node *cl = (Node *)malloc(sizeof(Node));
        temp[strlen(temp)-1]='\0';
        token = strtok(temp, "|");
        while(token!=NULL){
            if(item==1){
                char* tk = (char*)malloc(sizeof(char)*strlen(token));
                tk = strcpy(tk, token);
                cl->name = tk;
            }
            if(item == 2)
                cl->id = atoi(token);
            if(item == 3){
                float n = atof(token);
                cl->total = n;
                cl->nextSucc = NULL;
                cl->nextFail = NULL;
            }
            item++;
            token = strtok(NULL, "|");
        }
        clients[(cl->id)-1] = *cl;
        free(cl);
    }

    return;
}

void destroyClient(Node clients[], int num){
    int i;
    for(i = 0; i<num; i++){
        free(clients[i].name);
    }
    free(clients);

    return;
}
