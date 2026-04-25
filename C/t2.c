#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // =====================================
    // 1. ARRAY INPUT
    // =====================================
    int arr[100], n;

    printf("\n--- ARRAY OPERATIONS ---\n");
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // =====================================
    // 2. LENGTH OF ARRAY
    // =====================================
    printf("Length of array: %d\n", n);

    // =====================================
    // 3. SUM OF ARRAY
    // =====================================
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Sum of array: %d\n", sum);

    // =====================================
    // 4. REVERSE ARRAY
    // =====================================
    printf("Reversed array: ");
    for(int i = n-1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // =====================================
    // 5. SUBARRAY (FROM INDEX i TO j)
    // =====================================
    int start, end;
    printf("Enter start and end index for subarray: ");
    scanf("%d %d", &start, &end);

    printf("Subarray: ");
    for(int i = start; i <= end && i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // =====================================
    // 6. PRODUCT WITHOUT DUPLICATES
    // =====================================
    int visited[100] = {0};
    int product = 1;

    for(int i = 0; i < n; i++) {
        int isDuplicate = 0;

        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }

        if(!isDuplicate) {
            product *= arr[i];
        }
    }

    printf("Product (without duplicates): %d\n", product);


    // =====================================
    // 7. ARRAY → STRING
    // =====================================
    char str[200] = "";

    for(int i = 0; i < n; i++) {
        char temp[20];
        sprintf(temp, "%d", arr[i]);   // convert int → string
        strcat(str, temp);             // append
        strcat(str, " ");
    }

    printf("Array to String: %s\n", str);


    // =====================================
    // 8. STRING → ARRAY
    // =====================================
    int newArr[100], k = 0;
    char inputStr[200];

    printf("Enter numeric string (space separated): ");
    getchar(); // clear buffer
    fgets(inputStr, sizeof(inputStr), stdin);

    char *token = strtok(inputStr, " ");

    while(token != NULL) {
        newArr[k++] = atoi(token);
        token = strtok(NULL, " ");
    }

    printf("String to Array: ");
    for(int i = 0; i < k; i++) {
        printf("%d ", newArr[i]);
    }
    printf("\n");


    // =====================================
    // 9. NUMERIC STRING DISTINCT DIGIT LOGIC
    // =====================================
    char numStr[100];
    int freq[10] = {0};

    printf("\nEnter numeric string (digits only): ");
    scanf("%s", numStr);

    // count frequency
    for(int i = 0; numStr[i] != '\0'; i++) {
        freq[numStr[i] - '0']++;
    }

    int distinctSum = 0;

    printf("Distinct digits: ");
    for(int i = 0; i < 10; i++) {
        if(freq[i] == 1) {
            printf("%d ", i);
            distinctSum += i;
        }
    }

    printf("\nSum of distinct digits: %d\n", distinctSum);


    // =====================================
    // 10. DIFFERENCE BETWEEN DISTINCT DIGITS
    // =====================================
    int prev = -1, diffSum = 0;

    for(int i = 0; i < 10; i++) {
        if(freq[i] == 1) {
            if(prev != -1) {
                diffSum += abs(i - prev);
            }
            prev = i;
        }
    }

    printf("Sum of differences between distinct digits: %d\n", diffSum);


    // =====================================
    // 11. STRING ↔ DIGIT ARRAY
    // =====================================
    int digitArr[100], len = 0;

    for(int i = 0; numStr[i] != '\0'; i++) {
        digitArr[i] = numStr[i] - '0';
        len++;
    }

    printf("String to Digit Array: ");
    for(int i = 0; i < len; i++) {
        printf("%d ", digitArr[i]);
    }

    printf("\n");


    // digit array → number
    int number = 0;
    for(int i = 0; i < len; i++) {
        number = number * 10 + digitArr[i];
    }

    printf("Digit Array to Number: %d\n", number);


    // =====================================
    // END
    // =====================================
    return 0;
}