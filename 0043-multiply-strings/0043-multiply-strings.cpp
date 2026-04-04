#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // Edge case: if either number is "0", product is "0"
        if (num1 == "0" || num2 == "0") return "0";

        int n = (int)num1.size();
        int m = (int)num2.size();

        // Maximum length of product of n-digit and m-digit numbers is n + m
        vector<int> result(n + m, 0);

        // Multiply each digit from right to left (like manual multiplication)
        for (int i = n - 1; i >= 0; --i) {
            int d1 = num1[i] - '0';
            for (int j = m - 1; j >= 0; --j) {
                int d2 = num2[j] - '0';

                int posLow = i + j + 1; // ones place for this multiplication
                int posHigh = i + j;    // carry place

                int sum = d1 * d2 + result[posLow];
                result[posLow] = sum % 10;
                result[posHigh] += sum / 10;
            }
        }

        // Convert result vector to string, skipping leading zeros
        string product;
        int idx = 0;
        while (idx < (int)result.size() && result[idx] == 0) idx++;

        while (idx < (int)result.size()) {
            product.push_back(char(result[idx] + '0'));
            idx++;
        }

        return product.empty() ? "0" : product;
    }
};
