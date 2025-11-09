#include <iostream>
using namespace std;

// Recursive Fibonacci
int fibRecursive(int n) {
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Non-Recursive (Iterative) Fibonacci
int fibIterative(int n) {
    if (n <= 1)
        return n;
    int prev = 0, curr = 1, next;
    for (int i = 2; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "\nFibonacci using Recursion: " << fibRecursive(n);
    cout << "\nFibonacci using Iteration: " << fibIterative(n) << endl;

    return 0;
}
