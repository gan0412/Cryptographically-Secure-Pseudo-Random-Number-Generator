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


    //get index
    // int* bufpoint = buffer;

    //read number of index in input using fileptr
    for (int i = 0; i<100; i++){
        //pick random index from 1-99
        int index = rand()%100;
        // printf("%d\n", index);

        int currind = 0;
        char ch;
        //keep reading number until reaching index in line
        while (fscanf(fileptr, "%c", &ch) == 1)
        {
            //everytime currind = index, write the read character to output 
            //everytime a space is encountered, add one to currind 
            
            // printf("%d\n", ch);
            if (currind==index){
                // *bufpoint = currint;
                fputc(ch, output);
            }
            
            if (ch==' '){
                currind++;
            }
            
        }
        // bufpoint++;

        //read number of index
        //store in buffer[i]
        //move fileptr to next line 
        
    }

    //add to buffer

    //go to next line 

    //repeat again (100 times)
    fclose(fileptr);
    fclose(output);

    // for (int k=0; k<100; k++){
    //     printf("%d ", buffer[k]);
    // }
    // FILE* output;
    // output = fopen("output.txt", "w");

    // if (output==NULL){
    //     perror("Error opening output file");
    //     return 1;
    // }

    // for (int k=0; k<100; k++){
    //     fprintf(output, "%d ", buffer[k]);
    // }

    // fclose(output);
    return 0;
}