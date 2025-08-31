#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void generate(int n, string curr, vector<string>& result){
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }
        generate(n, curr+"0", result);
        generate(n, curr+"1", result);
    }

    vector<string> generateBinaryStrings(int num) {
       vector<string> result;
       generate(num, "", result);
       return result;
    }
};

// TC: O(2^N)
// SC: O(N) for recursion stack + O(2^N) for result

// If the problem states that without consecutive 1's
class Solution {
  public:
    void generate(int n, string curr, vector<string>& result){
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }
        generate(n, curr+"0", result);
        if(curr.empty() || curr.back() != '1'){
            generate(n, curr+"1", result);
        }
    }

    vector<string> generateBinaryStrings(int num) {
       vector<string> result;
       generate(num, "", result);
       return result;
    }
};

// TC: O(2^N)
// SC: O(N) for recursion stack + O(2^N) for result
