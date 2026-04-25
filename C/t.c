#include <stdio.h>
#include <stdlib.h>   // for atoi

int main() {

    // ==============================
    // 1. INT ↔ FLOAT
    // ==============================
    int intNum;
    float floatNum;

    printf("\n--- INT ↔ FLOAT ---\n");
    printf("Enter an integer: ");
    scanf("%d", &intNum);

    // int → float
    floatNum = (float)intNum;
    printf("Integer to Float: %f\n", floatNum);

    // float → int
    printf("Enter a float: ");
    scanf("%f", &floatNum);

    intNum = (int)floatNum;   // decimal removed
    printf("Float to Integer: %d\n", intNum);


    // ==============================
    // 2. CHAR ↔ INT (ASCII)
    // ==============================
    char ch;

    printf("\n--- CHAR ↔ INT ---\n");
    printf("Enter a character: ");
    scanf(" %c", &ch);   // space avoids newline issue

    // char → int (ASCII value)
    printf("ASCII value: %d\n", (int)ch);

    // int → char
    int ascii;
    printf("Enter ASCII value: ");
    scanf("%d", &ascii);

    printf("Character: %c\n", (char)ascii);


    // ==============================
    // 3. STRING ↔ INT
    // ==============================
    char str[100];

    printf("\n--- STRING ↔ INT ---\n");
    printf("Enter a numeric string: ");
    scanf("%s", str);

    // string → int
    int num = atoi(str);
    printf("String to Integer: %d\n", num);

    // int → string (manual method)
    int temp = num, i = 0;
    char str2[100];

    while (temp > 0) {
        str2[i++] = (temp % 10) + '0';  // convert digit to char
        temp /= 10;
    }

    str2[i] = '\0';

    // reverse string (since digits stored in reverse)
    for (int j = 0; j < i/2; j++) {
        char t = str2[j];
        str2[j] = str2[i - j - 1];
        str2[i - j - 1] = t;
    }

    printf("Integer to String: %s\n", str2);


    // ==============================
    // 4. STRING ↔ ARRAY (digits)
    // ==============================
    printf("\n--- STRING ↔ ARRAY ---\n");
    printf("Enter a numeric string: ");
    scanf("%s", str);

    int arr[100], len = 0;

    // string → int array
    for (int i = 0; str[i] != '\0'; i++) {
        arr[i] = str[i] - '0';  // char to int
        len++;
    }

    printf("String to Array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    // array → number
    int number = 0;
    for (int i = 0; i < len; i++) {
        number = number * 10 + arr[i];
    }

    printf("\nArray to Number: %d\n", number);


    // ==============================
    // 5. NUMBER ↔ DIGIT ARRAY
    // ==============================
    printf("\n--- NUMBER ↔ DIGITS ---\n");
    printf("Enter a number: ");
    scanf("%d", &num);

    int digits[100], count = 0;

    // number → digits
    int tempNum = num;
    while (tempNum > 0) {
        digits[count++] = tempNum % 10;
        tempNum /= 10;
    }

    printf("Digits: ");
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", digits[i]);
    }

    // digits → number
    int rebuilt = 0;
    for (int i = count - 1; i >= 0; i--) {
        rebuilt = rebuilt * 10 + digits[i];
    }

    printf("\nRebuilt Number: %d\n", rebuilt);


    // ==============================
    // 6. SIMPLE QUEUE USING ARRAY
    // ==============================
    printf("\n--- QUEUE (ARRAY) ---\n");

    int queue[5], front = 0, rear = -1, size;

    printf("Enter number of elements in queue (max 5): ");
    scanf("%d", &size);

    // enqueue operation
    for (int i = 0; i < size; i++) {
        printf("Enter element: ");
        scanf("%d", &queue[++rear]);
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    printf("\n");


    // ==============================
    // END
    // ==============================
    return 0;
}