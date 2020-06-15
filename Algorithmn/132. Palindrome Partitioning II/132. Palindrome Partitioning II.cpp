class Solution {
    vector<vector<int>>DP;
    vector<vector<int>>pDP;
    bool isPalindrome(string &s, int i, int j) {
        if(i>=j) return true;
        if(pDP[i][j]!=-1) {
            return pDP[i][j];
        }
        if(s[i]==s[j]&&isPalindrome(s, i+1,j-1)) 
        {
            return pDP[i][j] = 1;
        }
        else{
            return pDP[i][j] = 0;
        }       
    }
    
    int minCutHelper(string &s, int l, int r) {
       if(DP[l][r] != -1) {
            return DP[l][r];
       }
       if(isPalindrome(s, l, r)) {
           return DP[l][r] = 0;
       }  
    
       int minimum = INT_MAX;
       int currP = INT_MAX;
       for(int i = 1; i <= r; i++) {
           if(isPalindrome(s, i, r)) {
               currP = minCutHelper(s, 0, i - 1) + 1;
           }
           minimum = min(minimum, currP);
       } 
       return DP[l][r] = minimum;
    }
public:
    int minCut(string s) {
        DP.assign(s.length(), vector<int>(s.length(), -1));
        pDP.assign(s.length(), vector<int>(s.length(), -1));

        return minCutHelper(s, 0, s.length() - 1);
    }
};
