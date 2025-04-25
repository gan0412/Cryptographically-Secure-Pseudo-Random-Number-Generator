#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generate(){
    FILE* fileptr;
    fileptr = fopen("input.txt", "wb");

    if (fileptr==NULL){
        perror("Error opening file!");
        exit(1);
    }
    srand(time(NULL));
    for (int i = 0; i<100; i++){
        for (int j = 0; j<100; j++){
            fprintf(fileptr, "%d ", rand()%100 + 1);
        }
        fprintf(fileptr, "\n");
    }
    fclose(fileptr);
}

int main(){
    generate();
}

