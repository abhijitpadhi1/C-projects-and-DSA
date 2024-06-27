#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char ch;

    // Check if a file name is provided as a command line argument
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file for reading
    file = fopen(argv[1], "r");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }

    // Read and display the content of the file character by character
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    // Close the file
    fclose(file);

    return 0;
}
