class Solution {
public:
    string longestPalindrome(string s) {
        string rStr = string(s.rbegin(), s.rend());
        string resultStr = "";
        int n = s.length();
        
        if(n <= 1) {
            return s;
        }
        
        int dp[n][n];
        int max = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                if(s.c_str()[i] == rStr.c_str()[j]) {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    
                    if(dp[i][j] > max) {
                        int lMax = dp[i][j];
                        int start = i - lMax + 1;
                        
                        string resOrg = s.substr(start, lMax);
                        string resRev = string(resOrg.rbegin(), resOrg.rend());
         
                        if(resOrg == resRev) { 
                            resultStr = resOrg;
                            max = resultStr.length();
                        }

                    }
                }
            }
        }
        
        return resultStr;
    }
};