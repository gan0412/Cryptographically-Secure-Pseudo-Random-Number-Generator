#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



//picks number from each line in increasing index, store each one in buffer
int choose(){
    //open input file, set up buffer
    FILE* fileptr;
    fileptr = fopen("input.txt", "r");
    char line[400];

    const char delimeter = ' ';

    if (fileptr==NULL){
        perror("Error opening input file");
        return 1;
    }

    //open output file
    FILE* output;
    output = fopen("output.txt", "w");

    //read number of index in input using fileptr
    for (int i = 0; i<100; i++){
        srand(time(NULL));

        //pick random index from 1-99
        int index = rand()%100;

        //initialize current index on current line, and current character var 
        int currind = 0;
        char ch;

        //store current line in line
        fgets(line, sizeof(line), fileptr);

        //tokenize the line (it will give first pointer)
        char* num = strtok(line, " ");

        //keep incrementing pointer, until correct index is encoutnered 
        //then just pick the chosen index
        while (((num != NULL) & (currind != index))){
            num = strtok(NULL, " ");
            currind++;
        }

        //write that element to output file 
        while (*num!='\0'){
            fputc(*num, output);
            num++;
        }
    }

    fclose(fileptr);
    fclose(output);
    return 0;
}

int main(){
    choose();
}