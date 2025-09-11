#include <bits/stdc++.h>
using namespace std;

// LC 29. Divide Two Integers
// TC O(log^2(n)), SC O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge case for division by zero
        if (divisor == 0) return INT_MAX;
        
        // Handle a specific edge case for integer limits
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Use long long to handle the absolute values to prevent overflow
        long long ldividend = labs(dividend);
        long long ldivisor = labs(divisor);

        long long quotient = 0;
        while (ldividend >= ldivisor) {
            long long temp_divisor = ldivisor;
            long long multiple = 1;
            while (ldividend >= (temp_divisor << 1)) {
                temp_divisor <<= 1;
                multiple <<= 1;
            }
            ldividend -= temp_divisor;
            quotient += multiple;
        }
        
        // Apply the correct sign and check for overflow
        if (isNegative) {
            if (-quotient < INT_MIN) return INT_MIN;
            return (int)-quotient;
        } else {
            if (quotient > INT_MAX) return INT_MAX;
            return (int)quotient;
        }
    }
};