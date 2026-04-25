#include <stdio.h>

int main() {
    int number = 10;      // normal integer variable
    int *ptr;             // pointer variable

    ptr = &number;        // store address of number in ptr

    printf("Value of number: %d\n", number);
    printf("Address of number: %p\n", &number);

    printf("Value stored in ptr (address): %p\n", ptr);
    printf("Value pointed by ptr: %d\n", *ptr);

    // modifying value using pointer
    *ptr = 25;

    printf("New value of number: %d\n", *ptr);

    return 0;
}
