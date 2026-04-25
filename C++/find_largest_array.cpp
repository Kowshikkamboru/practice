#include <iostream>
#include <algorithm>
using namespace std;

// Use std::max_element instead of a custom function.

void testQ1() { 
    cout << "\n========== Question 1: Find Largest Element ==========\n"; 
    int arr[] = {3, 7, 2, 9, 1, 5}; 
    int n = 6; 
    cout << "Input: [3, 7, 2, 9, 1, 5]\n"; 
    cout << "Output: " << *max_element(arr, arr + n) << "\n"; 
}

int main() {
    testQ1();
    return 0;
}