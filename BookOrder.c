#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "BookOrder.h"

int main(int argc, char** argv){
    if(argc!=4){
        printf("Not the correct amount of arguments");
        return 1;
    }
    FILE *dataFile = fopen(argv[1], "r");
    if(dataFile == NULL){
        printf("Data Base file could not be opened.");
        return 1;
    }
    FILE *bookFile = fopen(argv[2], "r");
    if(bookFile == NULL){
        printf("Book Order file could not be opened.");
        return 1;
    }
    FILE *catFile = fopen(argv[3], "r");
    Node *catNode;
    if(catFile == NULL){
        catNode = createCat(argv[3]);
    }
    else{
        char cat[2000];
        char temp[100];
        char* space = " \0";
        int line = 0;
        //fgets(temp, 100, catFile);
        while(fgets(temp, 100, catFile)!=NULL){
            temp[strlen(temp)-1]='\0';
            strcat(cat, temp);
            strcat(cat, space);
        }
        memmove(cat, cat+2, strlen(cat));
        catNode = createCat(cat);
    }
    destroyList(catNode);
    fclose(bookFile);
    fclose(dataFile);
    return 0;
}

Node* createCat(char* cat){
    char* token;
    Node* head;
    Node* ptr;
    head = NULL;
    token = strtok(cat, " ");
    while(token!=NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->category = token;
        if(head == NULL){
            head = temp;
            ptr=head;
        }
        else{
            ptr->next = temp;
            temp->next=NULL;
            ptr=ptr->next;
        }
        token = strtok(NULL, " ");
    }
    
    return head;
}

void destroyList(Node* ptr){
    Node *temp = ptr;
    while(temp!=NULL){
        Node *tmp = temp;
        temp = temp->next;
        free(temp);
    }
    free(ptr);
}
