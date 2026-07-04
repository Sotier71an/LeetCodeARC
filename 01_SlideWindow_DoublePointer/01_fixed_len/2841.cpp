class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long ans = 0, cur_sum = 0;
        unordered_map<int, int> cnt;

        // init
        for (int i = 0; i < k; i++) {
            cur_sum += nums[i];
            cnt[nums[i]]++;
        }
        if (cnt.size() >= m) {
            ans = cur_sum;
        }

        // iterate
        for (int i = k; i < n; i++) {
            cur_sum += nums[i] - nums[i - k];
            cnt[nums[i]]++;
            cnt[nums[i - k]]--;
            if (cnt[nums[i - k]] == 0) {
                cnt.erase(nums[i - k]);
            }
            if (cnt.size() >= m) {
                ans = max(ans, cur_sum);
            }
        }

        return ans;
    }
};