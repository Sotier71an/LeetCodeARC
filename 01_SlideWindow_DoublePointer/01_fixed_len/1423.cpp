class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // 逆向思维 size=n-k 的 最小点数窗口
        int n = cardPoints.size();
        k = n - k;
        int min_sum = 0, cur_sum = 0;

        // init
        for (int i = 0; i < k; i++) {
            cur_sum += cardPoints[i];
        }
        min_sum = cur_sum;

        // iterate
        for (int i = k; i < n; i++) {
            cur_sum += cardPoints[i] - cardPoints[i - k];
            min_sum = min(min_sum, cur_sum);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += cardPoints[i];
        }
        ans = ans - min_sum;
        return ans;
    }
};