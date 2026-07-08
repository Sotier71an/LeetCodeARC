class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        // 窗口先不定后定长 可以先遍历第一部分 每遍历一个物品计算一次min_times 之后第二部分定长w窗口
        unordered_map<int, int> cnt;
        int times = 0;
        int n = arrivals.size();
        vector<bool> retained(n, false);

        int first_window = min(n, w);
        // 第一部分长度w
        for (int i = 0; i < first_window; i++) {
            if (cnt[arrivals[i]] < m) {
                cnt[arrivals[i]]++;
                retained[i] = true;
            } else {
                times++;
            }
        }

        // 第二部分
        for (int i = w; i < n; i++) {
            if (retained[i - w] == true) {
                cnt[arrivals[i - w]]--;
            }

            if (cnt[arrivals[i]] < m) {
                cnt[arrivals[i]]++;
                retained[i] = true;
            } else {
                times++;
            }
        }

        return times;
    }
};