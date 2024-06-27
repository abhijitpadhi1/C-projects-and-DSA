#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int charCount = 0, wordCount = 0, blankCount = 0, tabCount = 0;
    int inWord = 0;  // flag to track if currently in a word

    // Input file name
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");

    // Check if file opened successfully
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        charCount++;

        // Check for word, blank, and tab
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (inWord) {
                inWord = 0;
                wordCount++;
            }

            if (ch == ' ')
                blankCount++;
            else if (ch == '\t')
                tabCount++;
        } else {
            inWord = 1;
        }
    }

    // Check for the last word in the file
    if (inWord) {
        wordCount++;
    }

    // Close the file
    fclose(file);

    // Display the results
    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of blanks: %d\n", blankCount);
    printf("Number of tabs: %d\n", tabCount);

    return 0;
}
