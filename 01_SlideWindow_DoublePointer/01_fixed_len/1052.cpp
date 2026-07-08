class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // 本来就满意的顾客s0 + minutes定长窗口内不满意的顾客最大值max_sum
        int n = customers.size();
        // 计算第一部分
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                sum += customers[i];
            }
        }

        // 计算第二部分
        int max_sum = 0, cur_sum = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                cur_sum += customers[i];
            }
        }
        max_sum = cur_sum;
        for (int i = minutes; i < n; i++) {
            if (grumpy[i] == 1) {
                cur_sum += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                cur_sum -= customers[i - minutes];
            }
            max_sum = max(max_sum, cur_sum);
        }
        // 结果
        int ans = sum + max_sum;
        return ans;
    }
};