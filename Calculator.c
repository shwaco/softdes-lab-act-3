#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
float divide(float x, float y) { return x / y; }
int modulos(int x, int y) { return x % y; }

int main(int argc, char *argv[]) {
    if (argc < 4) return 1;

    int num1 = atoi(argv[1]);
    char *op = argv[2];
    int num2 = atoi(argv[3]);

    if (strcmp(op, "+") == 0) printf("%d", add(num1, num2));
    else if (strcmp(op, "-") == 0) printf("%d", subtract(num1, num2));
    else if (strcmp(op, "*") == 0) printf("%d", multiply(num1, num2));
    else if (strcmp(op, "/") == 0) {
        if (num2 == 0) printf("Error");
        else printf("%.2f", divide((float)num1, (float)num2));
    }
    else if (strcmp(op, "%") == 0) {
        if (num2 == 0) printf("Error");
        else printf("%d", modulos(num1, num2));
    }
    return 0;
}