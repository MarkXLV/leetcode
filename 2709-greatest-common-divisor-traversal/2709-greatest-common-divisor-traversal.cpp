#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return;

        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;

        for(int x : nums) {
            if(x == 1) return false; // special case
        }

        int maxVal = *max_element(nums.begin(), nums.end());

        // Step 1: SPF (Smallest Prime Factor)
        vector<int> spf(maxVal + 1);
        for(int i = 0; i <= maxVal; i++) spf[i] = i;

        for(int i = 2; i * i <= maxVal; i++) {
            if(spf[i] == i) {
                for(int j = i * i; j <= maxVal; j += i) {
                    if(spf[j] == j) spf[j] = i;
                }
            }
        }

        // Step 2: DSU
        DSU dsu(n);

        // Map: prime -> index of number
        unordered_map<int, int> primeOwner;

        // Step 3: Factorize each number using SPF
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            unordered_set<int> primes;

            while(x > 1) {
                primes.insert(spf[x]);
                x /= spf[x];
            }

            // Step 4: Union by common primes
            for(int p : primes) {
                if(primeOwner.count(p)) {
                    dsu.unite(i, primeOwner[p]);
                } else {
                    primeOwner[p] = i;
                }
            }
        }

        // Step 5: Check if all belong to same component
        int root = dsu.find(0);
        for(int i = 1; i < n; i++) {
            if(dsu.find(i) != root) return false;
        }

        return true;
    }
};