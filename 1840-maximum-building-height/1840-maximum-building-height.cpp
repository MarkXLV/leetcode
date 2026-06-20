class Solution {
public:
    bool isPossible(long long target,
                    int n,
                    vector<vector<int>>& restrictions) {

        int m = restrictions.size();

        for (int i = 1; i < m; i++) {

            long long id1 = restrictions[i - 1][0];
            long long h1  = restrictions[i - 1][1];

            long long id2 = restrictions[i][0];
            long long h2  = restrictions[i][1];

            long long dist = id2 - id1;

            long long peak =
                max(h1, h2) +
                (dist - abs(h1 - h2)) / 2;

            if (peak >= target)
                return true;
        }

        long long lastPeak =
            (long long)restrictions.back()[1] +
            (n - restrictions.back()[0]);

        return lastPeak >= target;
    }

    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Forward pass
        for (int i = 1; i < m; i++) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] +
                restrictions[i][0] -
                restrictions[i - 1][0]
            );
        }

        // Backward pass
        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] +
                restrictions[i + 1][0] -
                restrictions[i][0]
            );
        }

        long long l = 0;
        long long r = 1000000000LL;
        long long ans = 0;

        while (l <= r) {

            long long mid = l + (r - l) / 2;

            if (isPossible(mid, n, restrictions)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return (int)ans;
    }
};