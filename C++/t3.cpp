#include <iostream>
#include <cstdio>
#include <string>
#include <limits>
#include <cstdlib> // for atoi

using namespace std;

// Very simple examples (no validation) showing how to read an integer
// into a variable and print it. Examples shown:
// 1) scanf/printf (C-style)
// 2) cin >> a / cout (C++-style)
// 3) getline into string + stoi
// 4) cin.getline into char buffer + sscanf

int main() {
    int a;

    // 1) C-style scanf / printf (no validation)
    printf("C-style: enter an integer: ");
    scanf("%d", &a);
    printf("You entered (printf): %d\n", a);
    // consume leftover newline so next input reads from new line
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    // 2) C++-style cin >> a / cout (no validation)
    cout << "C++-style: enter an integer: ";
    cin >> a;
    cout << "You entered (cout): " << a << '\n';
  

    // 3) getline into std::string then convert with atoi (no validation)
    cout << "getline (string): enter an integer: ";
    string s;
    getline(cin, s);
 
    cout << "You entered (from string): " << a << '\n';

    // 4) cin.getline into char[] then atoi (no validation)
    cout << "cin.getline (char[]): enter an integer: ";
    char buf[64];
    cin.getline(buf, sizeof(buf));

    cout << "You entered (from buf): " << a << '\n';

    return 0;
}