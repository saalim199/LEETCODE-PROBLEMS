class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp;
    
    int solve(int k, int n) {
        if (k == 1) return n;
        if (n == 0) return 0;
        if (dp[k][n]) return dp[k][n];

        int low = 1, high = n, res = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            int broken = solve(k - 1, mid - 1); // egg breaks
            int notBroken = solve(k, n - mid); // egg doesn't break
            int temp = 1 + max(broken, notBroken);

            if (broken > notBroken) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }

            res = min(res, temp);
        }

        return dp[k][n] = res;
    }

    int superEggDrop(int k, int n) {
        return solve(k, n);
    }
};
