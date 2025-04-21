#include <stdio.h>
#include <stdlib.h>

//picks number from each line in increasing index, store each one in buffer

int main(){
    //open input file, set up buffer
    FILE* fileptr;
    fileptr = fopen("input.txt", "r");
    int buffer[100]; 

    if (fileptr==NULL){
        perror("Error opening input file");
        return 1;
    }

    //open output file
    FILE* output;
    output = fopen("output.txt", "w");

    //read number of index in input using fileptr
    for (int i = 0; i<100; i++){
        //pick random index from 1-99
        int index = rand()%100;

        //initialize current index on current line, and current character var 
        int currind = 0;
        char ch;

        //keep reading every number until new line (end of line) is reached 
        fscanf(fileptr, "%c", &ch);
        while (ch != '\n')
        {
            //write to output when number with chosen index is reached and it is not space 
            if (currind==index & ch!=' '){
                fputc(ch, output);
            }
            
            //when space is reached, new number or index has started 
            if (ch==' '){
                currind++;
            }
            fscanf(fileptr, "%c", &ch);
            
        }

        
    }

    fclose(fileptr);
    fclose(output);
    return 0;
}