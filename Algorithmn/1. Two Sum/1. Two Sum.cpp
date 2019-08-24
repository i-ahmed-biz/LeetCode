class Solution {
    unordered_map<int, int> indexMap;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++) {
            indexMap[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            if(indexMap.count(complement) > 0) {
                if(i == indexMap[complement]) {
                    continue;
                }
                    
               result.push_back(i);
               result.push_back(indexMap[complement]);
               break;
            }
        }
        
        return result;
    }
};
