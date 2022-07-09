//my-grep: Made by Anton Helminen

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define buffer_size 2000
//Main
int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[buffer_size]; //getline() is not available for use on my computer, so I had to use fgets with a sufficient buffer.
    int i;
    // If no sufficient amount of arguments are given, the program exits with exit(1)
    if (argc == 1) {
        printf("my-grep: searchterm [file ...]\n");
        exit(1);
    }
    //if no file was given, the program reads stdin and searches for the given search term.
    if (argc == 2) {
        fgets(buffer, buffer_size, stdin);
        if (strstr(buffer, argv[1]) != NULL) {
            puts(buffer);
        }
    }
    /* Main loop for opening and processing files
    Works as long as there are files or an error is encountered*/
    for (i = 2; argv[i] != NULL; i++) {    
        // Opening a given file
        if ((file = fopen(argv[i], "r")) == NULL) {
            printf("my-grep: cannot open file\n");
            exit(1);
        }
        // Printing out relevant lines. If the given search string is empty, no lines are printed.
        while ((fgets(buffer, buffer_size, file)) != NULL) {
            if (strstr(buffer, argv[1]) != NULL) {
                printf("%s", buffer);
            }
        }
        printf("\n");
    }
    return 0;
}