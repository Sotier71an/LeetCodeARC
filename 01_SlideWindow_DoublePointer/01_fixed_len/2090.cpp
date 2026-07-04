class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        // init vec
        vector<int> k_avg(n, -1);
        long long sum = 0;
        int avg = 0;

        // exceptional case
        int window_size = 2 * k + 1;
        if (n < window_size) return k_avg;

        // init
        for (int i = 0; i < window_size; i++) {
            sum += nums[i];
        }
        k_avg[k] = sum / window_size;

        // iterate
        for (int i = window_size; i < n; i++) {
            sum = sum + nums[i] - nums[i - window_size];
            avg = sum / window_size;
            k_avg[i - k] = avg;
        }

        return k_avg;
    }
};