#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sum = 0;

    // Check if 6 command line arguments are provided (including the program name)
    if (argc != 6) {
        printf("Usage: %s <num1> <num2> <num3> <num4> <num5>\n", argv[0]);
        return 1;
    }

    // Sum the integers passed as command line arguments
    for (int i = 1; i < argc; i++) {
        // Convert the string argument to an integer using atoi function
        int num = atoi(argv[i]);
        
        // Add the integer to the sum
        sum += num;
    }

    // Display the sum
    printf("Sum of the 5 integers: %d\n", sum);

    return 0;
}
