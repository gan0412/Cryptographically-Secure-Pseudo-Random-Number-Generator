#include <stdio.h>
#include <stdlib.h>

//picks number from each line in increasing index, store each one in buffer

int main(){
    FILE* fileptr;
    fileptr = fopen("input.txt", "r");
    int buffer[100]; 


    //get index


    //read number of index in input using fileptr
    for (int i = 0; i<100; i++){
        //pick random index from 1-99
        int index = rand()%100;
        char* line = NULL;
        size_t len = 0;
        ssize_t read;

        //keep reading number until reaching index in line
        for (int j = 0; j<index; j++){
            fscanf(fileptr, "%s");
        }
        //read number of index
        //store in buffer[i]
        //move fileptr to next line 

    }

    //add to buffer

    //go to next line 

    //repeat again (100 times)
}