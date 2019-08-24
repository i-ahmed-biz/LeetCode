class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        vector<char> currentList;
        unordered_map<char, int> currentMap;
        
        for(int i = 0; i < s.length(); i++) {
            char iThChar = s.c_str()[i];
            
            if(currentMap.count(iThChar) <= 0) {
                currentMap[iThChar] = i;
                currentList.push_back(iThChar);
            }
            else {
                if(currentList.size() > maxLen) {
                    maxLen = currentList.size();
                }
                if(currentList.size() > 0){
                    int start = currentMap[currentList[0]];
                    int end = currentMap[iThChar];
                    
                    for(int j = 0; j <= end - start; j++) {
                        unordered_map<char, int>::iterator it =  currentMap.find(currentList[j]);
                        currentMap.erase(it);
                    }
                    
                    vector<char>::iterator itV =  currentList.begin();
                    currentList.erase(itV, itV + (end - start) + 1);
                    
                    currentMap[iThChar] = i;
                    currentList.push_back(iThChar);
                }
            }
        }
        
        if(currentList.size() > maxLen) {
            maxLen = currentList.size();
        }
        
        return maxLen;
    }
};
