#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *sourceFile, *targetFile;
    char ch;

    // Check if both source and target file names are provided as command line arguments
    if (argc != 3) {
        printf("Usage: %s <source_filename> <target_filename>\n", argv[0]);
        return 1;
    }

    // Open the source file for reading
    sourceFile = fopen(argv[1], "r");

    // Check if the source file opened successfully
    if (sourceFile == NULL) {
        printf("Could not open source file: %s\n", argv[1]);
        return 1;
    }

    // Open the target file for writing
    targetFile = fopen(argv[2], "w");

    // Check if the target file opened successfully
    if (targetFile == NULL) {
        printf("Could not open target file: %s\n", argv[2]);
        fclose(sourceFile);
        return 1;
    }

    // Copy the content of the source file to the target file character by character
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, targetFile);
    }

    // Close the files
    fclose(sourceFile);
    fclose(targetFile);

    printf("File copy successful.\n");

    return 0;
}
