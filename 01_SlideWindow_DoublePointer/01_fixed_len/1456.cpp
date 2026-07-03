class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int max_cnt = 0;
        int cnt = 0;

        // init window
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                cnt++;
            }
            max_cnt = cnt;
        }

        // iterate
        for (int i = k; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                cnt++;
            }
            if (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u') {
                cnt--;
            }
            max_cnt =max(cnt, max_cnt);
        }

        return max_cnt;
    }
};