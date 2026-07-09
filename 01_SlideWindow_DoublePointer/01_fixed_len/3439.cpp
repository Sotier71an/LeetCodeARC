class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        // window_size = k+1 个时间段 先用前缀和计算gaps数组 后转化成定长滑窗 注意window_size > n的情况、
        int n = startTime.size();
        vector<int> gaps(n + 1, 0);

        // 计算gaps
        gaps[0] = startTime[0] - 0;
        for (int i = 1; i < n; i++) {
            gaps[i] = startTime[i] - endTime[i - 1];
        }
        gaps[n] = eventTime - endTime[n - 1];

        int window_size = k + 1;
        // window_size > n 的情况
        if (window_size > n) {
            int total = 0;
            for (int i = 0; i < n + 1; i++) {
                total += gaps[i];
            }
            return total;
        }

        // 标准滑窗
        int cur_sum = 0, max_sum = 0;
        // init
        for (int i = 0; i < window_size; i++) {
            cur_sum += gaps[i];
        }
        max_sum = cur_sum;

        //iterate
        for (int i = window_size; i < n + 1; i++) {
            cur_sum += gaps[i] - gaps[ i - window_size];
            max_sum = max(max_sum, cur_sum);
        }

        return max_sum;
    }
};