#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char cmd[BUFSIZE] = "wc -c < ";
    
    //check if the file exits
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    else {
        fclose(file);
    }

    //check for over follow
    int allowed_len  = BUFSIZE - strlen(cmd) -1;
    if (allowed_len >= strlen(argv[1])) {
        perror("Invalid file size");
        return EXIT_FAILURE;
    }
    else{
        //copy argument
        strcat(cmd, argv[1]);
    }


    system(cmd);
}
