class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<= 0) {
            return "";
        }
        else if(strs.size() == 1) {
            return strs[0];
        }
        bool scanComplete = false;
        int index = 0;
        int i;
        string prefix = "";
        char prefixCh [2] = {'\0','\0'};
        
        while(!scanComplete) {
            if(index < strs[0].length()) {
               prefixCh[0] = strs[0].c_str()[index]; 
            }
            
            for(i = 1; i < strs.size(); i++) {
                if(index >= strs[i].length() || strs[i].c_str()[index] != prefixCh[0]) {
                    break;
                }
            }
            
            if(i >= strs.size()) {
                prefix.append(prefixCh);
            }
            else {
               scanComplete = true; 
            }
            index++;
        }
        
        return prefix;
    }
};