#include<iostream>
using namespace std;
int countDigits(int n) {
    int count = 0;
    while (n > 0) {
        n /= 10; // Remove the last digit
        count++; // Increment the count
    }
    return count;
}

// # TC : O(log n)
// # SC : O(1)