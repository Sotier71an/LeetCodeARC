class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        double avg = 0;
        int ans = 0;
        double sum = 0;

        // init window
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        avg = sum / k;
        if (avg >= threshold) {
            ans++;
        }

        for (int i = k; i < n; i++) {
            sum += arr[i];
            sum -= arr[i - k];
            avg = sum / k;
            if (avg >= threshold) {
                ans++;
            }
        }

        return ans;

    }
};