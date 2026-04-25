#include <iostream>
using namespace std;

// Compute Fibonacci values inline in main (no separate functions)
int main() {
	int arr[] = {0, 1, 2, 3, 4, 5};
	int m = sizeof(arr) / sizeof(arr[0]);
	if (m == 0) return 0;

	// find maximum index we need
	int maxIndex = arr[0];
	for (int i = 1; i < m; ++i) if (arr[i] > maxIndex) maxIndex = arr[i];

	// allocate array to hold Fibonacci values up to maxIndex
	int *fib = new int[maxIndex + 1];
	fib[0] = 0;
	if (maxIndex >= 1) fib[1] = 1;
	for (int i = 2; i <= maxIndex; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	cout << "Fibonacci values for indices {0,1,2,3,4,5}:\n";
	for (int i = 0; i < m; ++i) {
		cout << "fib(" << arr[i] << ") = " << fib[arr[i]] << '\n';
	}

	delete[] fib;
	return 0;
}

