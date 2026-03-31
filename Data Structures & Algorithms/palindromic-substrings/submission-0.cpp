class Solution {
private:
    bool isPalindromic(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    int solve(int ind, string s, int n) {
        if (ind == n) return 0;

        int cnt = 0;

        for (int i = ind; i < n; i++) {
            string b = s.substr(ind, i - ind + 1);
            if (isPalindromic(b)) {
                cnt++;
            }
        }

        // move start index forward
        cnt += solve(ind + 1, s, n);

        return cnt;
    }

public:
    int countSubstrings(string s) {
        int n = s.size();
        return solve(0, s, n);
    }
};
