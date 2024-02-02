class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for (int i = 1; i <= 9; ++i) {
            int num = i;
            int nxt = i + 1;

            while (num <= high && nxt <= 9) {
                num = num * 10 + nxt;
                if (low <= num && num <= high) res.push_back(num);
                nxt++;
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};