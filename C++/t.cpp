#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <bitset>

using namespace std;

int readInt(const string &prompt) {
	int x;
	while (true) {
		cout << prompt;
		if (cin >> x) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return x;
		}
		cout << "Please enter a valid integer.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

double readDouble(const string &prompt) {
	double x;
	while (true) {
		cout << prompt;
		if (cin >> x) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return x;
		}
		cout << "Please enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

bool readBool(const string &prompt) {
	string s;
	while (true) {
		cout << prompt;
		if (!getline(cin, s)) s = "";
		if (s == "1" || s == "true" || s == "True") return true;
		if (s == "0" || s == "false" || s == "False") return false;
		cout << "Please enter true/false or 1/0.\n";
	}
}

void arithmeticOps(int a, int b, double d) {
	cout << "\n--- Arithmetic Operations ---\n";
	cout << a << " + " << b << " = " << (a + b) << '\n';
	cout << a << " - " << b << " = " << (a - b) << '\n';
	cout << a << " * " << b << " = " << (a * b) << '\n';
	if (b != 0) {
		cout << a << " / " << b << " (integer division like C) = " << (a / b) << '\n';
		cout << a << " % " << b << " = " << (a % b) << '\n';
	} else {
		cout << "Division by zero: / and % undefined\n";
	}
	cout << a << " ^ 2 = " << (a * a) << " (power)\n";
	cout << a << " + " << d << " (mixed int+double) = " << (a + d) << "\n";
}

void bitwiseOps(int a, int b) {
	cout << "\n--- Bitwise Operations ---\n";
	cout << a << " & " << b << " = " << (a & b) << '\n';
	cout << a << " | " << b << " = " << (a | b) << '\n';
	cout << a << " ^ " << b << " = " << (a ^ b) << '\n';
	cout << "~" << a << " = " << (~a) << '\n';
	cout << a << " << 1 = " << (a << 1) << '\n';
	cout << a << " >> 1 = " << (a >> 1) << " (arithmetic right shift)\n";

	// Show binary representation (32-bit view)
	cout << a << " (binary 32-bit): " << bitset<32>(static_cast<unsigned int>(a)) << '\n';
	cout << b << " (binary 32-bit): " << bitset<32>(static_cast<unsigned int>(b)) << '\n';
}

void logicalOps(int a, int b, bool flag) {
	cout << "\n--- Logical Operations ---\n";
	cout << a << " > " << b << " = " << boolalpha << (a > b) << '\n';
	cout << a << " < " << b << " = " << boolalpha << (a < b) << '\n';
	// In C you use && and ||, in C++ the same; we show results clearly
	cout << "(a > b) && flag = " << boolalpha << ((a > b) && flag) << '\n';
	cout << "(a > b) || flag = " << boolalpha << ((a > b) || flag) << '\n';
	cout << "!flag = " << boolalpha << (!flag) << "\n";
}

void arrayOps(vector<int> arr) {
	cout << "\n--- Array (vector) Operations ---\n";
	cout << "Contents: ";
	for (int v : arr) cout << v << ' ';
	cout << '\n';
	int sum = 0;
	for (int v : arr) sum += v;
	cout << "Sum = " << sum << '\n';
	if (!arr.empty()) {
		cout << "Max = " << *max_element(arr.begin(), arr.end()) << '\n';
	}
	vector<int> sorted = arr;
	sort(sorted.begin(), sorted.end());
	cout << "Sorted: ";
	for (int v : sorted) cout << v << ' ';
	cout << '\n';
}

void stringOps(const string &s, int a) {
	cout << "\n--- String Operations ---\n";
	cout << "Original: '" << s << "'\n";
	cout << "Length: " << s.length() << '\n';
	// C users: strlen(s.c_str()) is similar
	string up = s;
	transform(up.begin(), up.end(), up.begin(), ::toupper);
	cout << "Uppercase: " << up << '\n';
	string low = s;
	transform(low.begin(), low.end(), low.begin(), ::tolower);
	cout << "Lowercase: " << low << '\n';
	cout << "Substring (0,3): " << (s.size() >= 3 ? s.substr(0,3) : string("(too short)")) << '\n';
	cout << "Concat with ' world': " << (s + " world") << '\n';
	// replace 'a' with '@' (simple loop)
	string rep = s;
	for (char &c : rep) if (c == 'a') c = '@';
	cout << "Replace 'a'->'@': " << rep << '\n';
	cout << "Contains '" << a << "'?: " << boolalpha << (s.find(to_string(a)) != string::npos) << '\n';
	cout << "Equals 'test' (ignore case)?: " << boolalpha << (low == string("test")) << '\n';
}

int main() {
	cout << "Simple C++ demo: arithmetic, bitwise, logical, array, string\n";
	int a = readInt("Enter first integer (a): ");
	int b = readInt("Enter second integer (b): ");
	double d = readDouble("Enter a floating-point number (d): ");
	cout << "Enter boolean (true/false or 1/0): ";
	bool flag = readBool("");
	cout << "Enter a string: ";
	string s;
	getline(cin, s);

	arithmeticOps(a, b, d);
	bitwiseOps(a, b);
	logicalOps(a, b, flag);

	vector<int> arr = {a, b, a + b, a - b};
	arrayOps(arr);

	stringOps(s, a);

	cout << "\n--- Done ---\n";
	return 0;
}

