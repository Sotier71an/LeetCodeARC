class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double avg = 0;
        double sum = 0;

        // init window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        avg = sum / k;
        double max_avg = avg;

        //iterate
        for (int i = k; i < n; i++) {
            sum += nums[i];
            sum -= nums[i - k];
            avg = sum / k;
            max_avg = max(avg, max_avg);
        }

        return max_avg;
    }
};