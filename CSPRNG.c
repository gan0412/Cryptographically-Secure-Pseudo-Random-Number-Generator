#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROWS 100
#define COLUMNS 100
#define FIRST_ASCII 33
#define ASCII_LIMIT 94


void generate(){
    FILE* fileptr;
    fileptr = fopen("input.txt", "wb");

    if (fileptr==NULL){
        perror("Error opening file!");
        exit(1);
    }
    srand(time(NULL));
    for (int i = 0; i<ROWS; i++){
        for (int j = 0; j<COLUMNS; j++){
            fprintf(fileptr, "%c ", rand()%ASCII_LIMIT + FIRST_ASCII);
        }
        fprintf(fileptr, "\n");
    }
    fclose(fileptr);
}

int main(){
    generate();
}

