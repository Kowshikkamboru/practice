#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    // =====================================
    // INPUT SECTION
    // =====================================
    int arr[100], n;

    printf("\n===== ARRAY INPUT =====\n");
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    char str[200];
    printf("\n===== STRING INPUT =====\n");
    getchar(); // clear buffer
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';


    // =====================================
    // ARRAY OPERATIONS
    // =====================================
    printf("\n===== ARRAY OPERATIONS =====\n");

    // Traversal
    printf("Traversal: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Sum
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    printf("Sum: %d\n", sum);

    // Max & Min
    int max = arr[0], min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }
    printf("Max: %d, Min: %d\n", max, min);

    // Second Largest
    int second = -99999;
    for(int i = 0; i < n; i++) {
        if(arr[i] != max && arr[i] > second)
            second = arr[i];
    }
    printf("Second Largest: %d\n", second);

    // Reverse
    printf("Reverse: ");
    for(int i = n-1; i >= 0; i--) printf("%d ", arr[i]);
    printf("\n");

    // Frequency
    printf("Frequency:\n");
    for(int i = 0; i < n; i++) {
        int count = 1, printed = 0;
        for(int k = 0; k < i; k++)
            if(arr[k] == arr[i]) printed = 1;

        for(int j = i+1; j < n; j++)
            if(arr[i] == arr[j]) count++;

        if(!printed)
            printf("%d -> %d times\n", arr[i], count);
    }

    // Remove duplicates
    printf("Unique elements: ");
    for(int i = 0; i < n; i++) {
        int dup = 0;
        for(int j = 0; j < i; j++)
            if(arr[i] == arr[j]) dup = 1;

        if(!dup) printf("%d ", arr[i]);
    }
    printf("\n");

    // Product without duplicates
    int product = 1;
    for(int i = 0; i < n; i++) {
        int dup = 0;
        for(int j = 0; j < i; j++)
            if(arr[i] == arr[j]) dup = 1;

        if(!dup) product *= arr[i];
    }
    printf("Product (unique): %d\n", product);
    
    // Sorting (Low->High and High->Low)
    int arr_asc[100], arr_desc[100];
    for(int i = 0; i < n; i++) { arr_asc[i] = arr[i]; arr_desc[i] = arr[i]; }

    // Bubble sort ascending for arr_asc
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr_asc[j] > arr_asc[j+1]) {
                int t = arr_asc[j];
                arr_asc[j] = arr_asc[j+1];
                arr_asc[j+1] = t;
            }

    // Fill arr_desc by reversing arr_asc
    for(int i = 0; i < n; i++) arr_desc[i] = arr_asc[n-1-i];

    printf("Sorted (Low->High): ");
    for(int i = 0; i < n; i++) printf("%d ", arr_asc[i]);
    printf("\n");

    printf("Sorted (High->Low): ");
    for(int i = 0; i < n; i++) printf("%d ", arr_desc[i]);
    printf("\n");

    // Left Rotation
    int first = arr[0];
    for(int i = 0; i < n-1; i++) arr[i] = arr[i+1];
    arr[n-1] = first;

    printf("Left Rotated: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Linear Search
    int key, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &key);

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if(!found) printf("Not found\n");


    // =====================================
    // STRING OPERATIONS
    // =====================================
    printf("\n===== STRING OPERATIONS =====\n");

    int len = strlen(str);
    printf("Length: %d\n", len);

    // Reverse
    char rev[200];
    for(int i = 0; i < len; i++)
        rev[i] = str[len-i-1];
    rev[len] = '\0';

    printf("Reversed: %s\n", rev);

    // Palindrome
    int pal = 1;
    for(int i = 0; i < len/2; i++)
        if(str[i] != str[len-i-1]) pal = 0;

    printf("Palindrome: %s\n", pal ? "Yes" : "No");

    // Vowels & Consonants
    int v = 0, c = 0;
    for(int i = 0; i < len; i++) {
        char ch = str[i];
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) {
            if(strchr("aeiouAEIOU", ch)) v++;
            else c++;
        }
    }
    printf("Vowels: %d, Consonants: %d\n", v, c);

    // Frequency
    int freq[256] = {0};
    for(int i = 0; i < len; i++) freq[str[i]]++;

    printf("Char Frequency:\n");
    for(int i = 0; i < 256; i++)
        if(freq[i]) printf("%c -> %d\n", i, freq[i]);

    // Remove duplicates
    printf("Without duplicates: ");
    for(int i = 0; i < len; i++) {
        int dup = 0;
        for(int j = 0; j < i; j++)
            if(str[i] == str[j]) dup = 1;

        if(!dup) printf("%c", str[i]);
    }
    printf("\n");

    // Sorting characters (Low->High and High->Low)
    char s_asc[200], s_desc[200];
    strcpy(s_asc, str);
    int slen = len;
    for(int i = 0; i < slen-1; i++)
        for(int j = 0; j < slen-i-1; j++)
            if(s_asc[j] > s_asc[j+1]) {
                char t = s_asc[j];
                s_asc[j] = s_asc[j+1];
                s_asc[j+1] = t;
            }
    for(int i = 0; i < slen; i++) s_desc[i] = s_asc[slen-1-i];
    s_asc[slen] = s_desc[slen] = '\0';

    printf("Sorted chars (Low->High): %s\n", s_asc);
    printf("Sorted chars (High->Low): %s\n", s_desc);

    // Uppercase
    for(int i = 0; i < len; i++)
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;

    printf("Uppercase: %s\n", str);

    // Word count
    int words = 1;
    for(int i = 0; i < len; i++)
        if(str[i] == ' ') words++;

    printf("Words: %d\n", words);

    // Remove spaces
    printf("No spaces: ");
    for(int i = 0; i < len; i++)
        if(str[i] != ' ') printf("%c", str[i]);
    printf("\n");

    // Tokenization
    char temp[200];
    strcpy(temp, str);

    printf("Words list:\n");
    char *token = strtok(temp, " ");
    while(token) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    // Character Search
    char ch;
    int foundChar = 0;
    printf("Enter char to search: ");
    scanf(" %c", &ch);

    for(int i = 0; i < len; i++) {
        if(str[i] == ch) {
            printf("Char found at %d\n", i);
            foundChar = 1;
            break;
        }
    }
    if(!foundChar) printf("Char not found\n");

    // Substring Search
    char sub[100];
    int foundSub = 0;
    printf("Enter substring: ");
    scanf("%s", sub);

    for(int i = 0; i <= len - strlen(sub); i++) {
        int match = 1;
        for(int j = 0; j < strlen(sub); j++) {
            if(str[i+j] != sub[j]) {
                match = 0;
                break;
            }
        }
        if(match) {
            printf("Substring found at %d\n", i);
            foundSub = 1;
            break;
        }
    }
    if(!foundSub) printf("Substring not found\n");

    return 0;
}