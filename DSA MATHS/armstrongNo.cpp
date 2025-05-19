#include <bits/stdc++.h>
using namespace std;


// Function to check if a number is Armstrong
bool isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int digits = 0;

    // Count the number of digits
    int temp = num;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    // Calculate the sum of digits raised to the power of number of digits
    temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    // Check if sum is equal to original number
    return (sum == originalNum);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isArmstrong(num)) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }

    return 0;
}
