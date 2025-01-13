#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>


#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char cmd[BUFSIZE] = "wc -c < ";
    char *file_name = argv[1];

    // Use stat instead of system command to get file size
    struct stat st;
    if (stat(file_name, &st) != 0) {
        perror("Error getting file information");
        return EXIT_FAILURE;
    }

    // Print file size
    printf("%ld\n", st.st_size);

    return EXIT_SUCCESS;

/*
    //check if the file exits
    FILE *file = fopen(file_name, "rb");
    if (!file) {
        perror("Files doesn't exist");
        return EXIT_FAILURE;
    }
    else {
        fclose(file);
    }

    //check for over follow
    int allowed_len  = BUFSIZE - strlen(cmd) -1;
    if (allowed_len >= strlen(file_name)) {
        //copy argument
        strncat(cmd, file_name, allowed_len);
    }
    else{
        perror("Invalid file size");
        return EXIT_FAILURE;
    }

    system(cmd);
*/
}
