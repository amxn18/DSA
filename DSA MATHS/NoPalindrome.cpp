#include<iostream>
using namespace std;
int main() {
   int n;
   cout << "Enter a number: ";
   if(n < 0 || (n% 10 ==0 && n!=0)) {
       return 0;
   }
   int rev = 0;
   while(n > rev){
      int rem = n % 10;
      rev = rev * 10 + rem;
      n = n / 10;
   }
   return (n == rev || n == rev / 10) ? 1 : 0;
}

// # TC : O(log n)
// # SC : O(1)