#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//clearing the file
int remove(FILE *file) {
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "w"); 

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    fclose(file);

    printf("Contents of '%s' deleted successfully.\n", filename);

    return 0;
}


//picks number from each line in increasing index, store each one in buffer
int main(){
    //open input file, set up buffer
    FILE* fileptr;
    fileptr = fopen("input.txt", "r");
    char line[400];
    int array[100]; 
    remove(fileptr);

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
        //pick random index from 1-99
        int index = rand()%100;

        //initialize current index on current line, and current character var 
        int currind = 0;
        char ch;

        //just read the whole line
        //store it in the line
        fgets(line, sizeof(line), fileptr);
        int i = 0;

        // while (line[i]!='\n' & i<400){
        //     printf("%c", line[i]);
        //     fflush(stdout);
        //     i++;
        // }

        //tokenize the line (it will give first pointer)
        char* num = strtok(line, " ");

        //keep incrementing pointer, until correct index is encoutnered 
        //then just pick the chosen index
        while (((num != NULL) & (currind != index))){
            // printf("%s ", num);
            num = strtok(NULL, " ");
            currind++;
        }

        //write that element to output file 
        while (*num!='\0'){
            fputc(*num, output);
            num++;
        }
        //go to next line

        
        
        //keep reading every number until new line (end of line) is reached 
        // fscanf(fileptr, "%c", &ch);
        // while (ch != '\n')
        // {
        //     //write to output when number with chosen index is reached and it is not space 
        //     if (currind==index & ch!=' '){
        //         fputc(ch, output);
        //     }
            
        //     //when space is reached, new number or index has started 
        //     if (ch==' '){
        //         currind++;
        //     }
        //     fscanf(fileptr, "%c", &ch);
            
        // }

        
    }

    fclose(fileptr);
    fclose(output);
    return 0;
}