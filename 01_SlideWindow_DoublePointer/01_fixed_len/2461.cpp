class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        long long ans = 0, sum = 0;

        // init
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            cnt[nums[i]]++;
        }
        if (cnt.size() == k) {
            ans = sum;
        }

        // iterate
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            cnt[nums[i]]++;
            cnt[nums[i - k]]--;
            if (cnt[nums[i - k]] == 0) {
                cnt.erase(nums[i - k]);
            }
            if (cnt.size() == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};