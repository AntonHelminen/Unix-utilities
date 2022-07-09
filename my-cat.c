//my-cat: Made by Anton Helminen

#include <stdio.h>
#include <stdlib.h>

//Main
int main(int argc, char *argv[]) {
    FILE *file;
    char c;
    int i;
    // If no files are given the program simply exits by returning 0 in main()
    if (argc == 1) {
        return 0;
    }
    /* Main loop for opening and processing files
    Works as long as there are files or an error is encountered*/
    for (i = 1; argv[i] != NULL; i++) {    
        // Opening a given file
        if ((file = fopen(argv[i], "r")) == NULL) {
            printf("\nmy-cat: cannot open file\n");
            exit(1);
        }
        // Reading and printing contents one caharacter at a time
        c = fgetc(file);
        while(c != EOF) {
            printf("%c", c);
            c = fgetc(file);
        }

        fclose(file);
    }
    return 0;
}