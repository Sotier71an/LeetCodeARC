class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // 求窗口中白色最少的次数
        int n = blocks.size();
        int cur_num = 0;

        // init window
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                cur_num++;
            }
        }
        int ans = cur_num;

        // iterate
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') {
                cur_num++;
            }
            if (blocks[i - k] == 'W') {
                cur_num--;
            }
            ans = min(ans, cur_num);
        }

        return ans;
    }
};