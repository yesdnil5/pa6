#include <stdlib.h>
#include <stdio.h>

int main(){
    if(argc!=4){
        printf("Not the correct amount of arguments");
        return 1;
    }
    FILE dataFile = fopen(argv[1], "r");
    if(dataFile == NULL){
        printf("Data Base file could not be opened.");
        return 1;
    }
    FILE bookFile = fopen(argv[2], "r");
    if(bookFile == NULL){
        printf("Book Order file could not be opened.");
        return 1;
    }
    char * cat = argv[3];
    
}

Node createCat(char* cat){
    
}
