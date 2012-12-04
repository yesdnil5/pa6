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
    char *cat = argv[3];
    Node* catNode = createCat(argv[3]);

    return 0;
}

Node* createCat(char* cat){
    char* token;
    Node* head;
    Node* ptr = head;
    head = NULL;
    token = strtok(cat, " ");
    printf("%s\n", token);
    while(token!=NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->category = token;
        if(head == NULL){
            head = temp;
        }
        else{
            ptr->next = temp;
            ptr=ptr->next;
        }
        token = strtok(cat, NULL);
    }
    
    return head;
}
