#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// For the Colors
#define CYAN    "\033[1;36m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define RESET   "\033[0m"

// Function prototypes
void printmenu();
void clearscreen();
void pause();
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
float divide(float x, float y);
int modulos(int x, int y);
int getInteger() {
    int num;
    while (1) {
        if (scanf("%d", &num) == 1) {
            while (getchar() != '\n'); // clear buffer
            return num;
        } else {
            printf("Invalid input! Enter a valid integer: ");
            while (getchar() != '\n'); // clear buffer
        }
    }
}

// Main function
int main(){
    int choice;
   
    do {
        clearscreen(); // Clear the console screen
        printmenu();
        printf("Choose an operation (1-6): ");
        choice = getInteger();

        if (choice > 6 || choice < 1) {
            printf("Invalid choice! Please select between 1 and 6.\n");
            pause();
            continue;
        }

        if (choice == 6) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        
        int num1, num2;
        printf("Enter first number: ");
        num1 = getInteger();

        printf("Enter second number: ");
        num2 = getInteger();

        switch (choice) {
            case 1:
                printf("Sum: %d\n", add(num1, num2));
                break;
            case 2:
                printf("Difference: %d\n", subtract(num1, num2));
                break;
            case 3:
                printf("Product: %d\n", multiply(num1, num2));
                break;
            case 4:
                printf("Quotient: %.2f\n", divide(num1, num2));
                break;
            case 5:
                printf("Remainder: %d\n", modulos(num1, num2));
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        pause(); // Wait for user input before clearing the screen
    } while (choice != 6);
}

// Function to clear the console screen
void clearscreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to pause execution and wait for user input
void pause() {
    printf("Press ENTER key to continue...");
    getchar(); // Read a character (the newline left by scanf)
    getchar(); // Read the actual key pressed
}

// Function definitions
int add(int x, int y) {
    return x + y;
}
int subtract(int x, int y) {
    return x - y;
}
int multiply(int x, int y) {
    return x * y;
}
float divide(float x, float y) {
    while (x > 0 && y == 0) {
        printf("Error: Undefined, Division by zero is not allowed.\n");
        printf("Please enter a non-zero divisor: ");
        scanf("%f", &y);
        return x / y; // Return the result after getting a valid divisor
    }

    while (x == 0 && y == 0) {
        printf("Error: Indeterminate form (0/0) is not allowed.\n");
        printf("Please enter a non-zero divisor: ");
        scanf("%f", &y);
        return x / y; // Return the result after getting valid inputs
    }

    return x / y;
}
int modulos(int x, int y) {
    while (y == 0) {
        printf("Error: Modulo by zero is not allowed.\n");
        printf("Please enter a non-zero divisor: ");
        scanf("%d", &y);
        return x % y; // Return the result after getting a valid divisor
    }
    return x % y;
}

void printmenu() {
    printf(CYAN "\n==================================================================\n" RESET);
    printf(CYAN "II            Simple Calculator (Procedural Paradigm)           II\n" RESET);
    printf(CYAN "==================================================================\n" RESET);
    printf(YELLOW "II       [1] Addition                                           II\n" RESET);
    printf(YELLOW "II       [2] Subtraction                                        II\n" RESET);
    printf(YELLOW "II       [3] Multiplication                                     II\n" RESET);
    printf(YELLOW "II       [4] Division                                           II\n" RESET);
    printf(YELLOW "II       [5] Modulus                                            II\n" RESET);
    printf(YELLOW "II       [6] Exit                                               II\n" RESET);
    printf(CYAN "==================================================================\n" RESET);
}