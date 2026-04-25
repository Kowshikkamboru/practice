#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <limits>
#include <cctype>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << "=== Arithmetic operations ===\n";
	cout << "Enter two integers (a b): ";
	long long a, b;
	if (!(cin >> a >> b)) return 0;
	cout << "a + b = " << (a + b) << "\n";
	cout << "a - b = " << (a - b) << "\n";
	cout << "a * b = " << (a * b) << "\n";
	if (b != 0) cout << "a / b = " << (a / b) << " (integer division)\n";
	if (b != 0) cout << "a % b = " << (a % b) << "\n";

	cout << "\n=== Bitwise operations ===\n";
	cout << "Enter two integers for bitwise ops (x y): ";
	long long x, y;
	if (!(cin >> x >> y)) return 0;
	cout << "x & y = " << (x & y) << "\n";
	cout << "x | y = " << (x | y) << "\n";
	cout << "x ^ y = " << (x ^ y) << "\n";
	cout << "~x = " << (~x) << "\n";
	cout << "x << 1 = " << (x << 1) << "\n";
	cout << "x >> 1 = " << (x >> 1) << "\n";

	cout << "\n=== Logical and comparison operations ===\n";
	cout << "Enter two integers for comparisons (p q): ";
	long long p, q;
	if (!(cin >> p >> q)) return 0;
	cout << "p == q: " << (p == q) << "\n";
	cout << "p != q: " << (p != q) << "\n";
	cout << "p < q: " << (p < q) << "\n";
	cout << "(p < q) && (p != 0): " << ((p < q) && (p != 0)) << "\n";
	cout << "(p > q) || (q == 0): " << ((p > q) || (q == 0)) << "\n";

	cout << "\n=== Array operations ===\n";
	cout << "Enter number of elements (n): ";
	int n;
	if (!(cin >> n)) return 0;
	vector<long long> arr;
	arr.reserve(max(0, n));
	cout << "Enter " << n << " integers:\n";
	for (int i = 0; i < n; ++i) {
		long long v; cin >> v; arr.push_back(v);
	}
	long long sum = accumulate(arr.begin(), arr.end(), 0LL);
	auto [min_it, max_it] = minmax_element(arr.begin(), arr.end());
	cout << "Sum = " << sum << ", Average = ";
	if (n>0) cout << (double)sum / n << "\n"; else cout << "N/A\n";
	if (n>0) cout << "Min = " << *min_it << ", Max = " << *max_it << "\n";
	cout << "Reversed array: ";
	reverse(arr.begin(), arr.end());
	for (auto val : arr) cout << val << ' ';
	cout << "\n";

	cout << "\n=== String operations ===\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter a line of text: \n";
	string s;
	getline(cin, s);
	cout << "You entered: " << s << "\n";
	cout << "Length: " << s.size() << "\n";
	cout << "Concatenate with ' [suffix]': " << (s + " [suffix]") << "\n";
	if (!s.empty()) cout << "First char: " << s.front() << ", Last char: " << s.back() << "\n";
	size_t pos = s.find(' ');
	if (pos != string::npos) cout << "First space at index: " << pos << "\n"; else cout << "No spaces found\n";
	string upper = s;
	for (char &c : upper) c = toupper(static_cast<unsigned char>(c));
	cout << "Uppercase: " << upper << "\n";

	cout << "\nDone.\n";
	return 0;
}
