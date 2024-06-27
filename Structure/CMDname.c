#include <stdio.h>

int main(int argc, char *argv[]) {
    // Check if the program is provided with the full name as a command line argument
    if (argc != 2) {
        printf("Usage: %s <full_name>\n", argv[0]);
        return 1;
    }

    // Display the full name
    printf("Your full name is: %s\n", argv[1]);

    return 0;
}
