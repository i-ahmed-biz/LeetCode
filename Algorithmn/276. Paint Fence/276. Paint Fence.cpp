class Solution {
    vector<vector<int>>DP;
    int numWaysFinder(int n, int k, int i, int prevColor, bool isPrevSame) {
        if(i >= n) {
            return 1;
        }
        if(DP[i][isPrevSame] != -1) {
            return DP[i][isPrevSame];
        }
        int nWays = 0;
        for(int p = 0; p < k; p++) {
            if(p == prevColor && isPrevSame) {
                continue;
            }
            else {
                nWays = nWays + numWaysFinder(n, k, i + 1, p, prevColor == p);
            }
        }
        
        return DP[i][isPrevSame] = nWays;
    }
    public:
    int numWays(int n, int k) {
        if(n == 0 || k == 0) {
            return 0;
        }
        DP.assign(n + 1, vector<int>(2, -1));
        int nWays = 0;
        return numWaysFinder(n, k, 0, -1, false);
    }
};