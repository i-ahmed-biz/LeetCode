class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3) {
            return vector<vector<int>>();
        }
        
        for(int i = 1; i < nums.size() - 1; i++) {
            int beg = 0;
            int end = nums.size() - 1;
            while(beg < i && end > i) {
                int sum = nums[beg] + nums[i] + nums[end];
                if(sum == 0) {
                    vector<int>triplet{nums[beg] , nums[i] , nums[end]};
                    result.insert(triplet);
                    beg++;
                    end--;
                }
                else if(sum > 0) {
                    end--;
                }
                else {
                    beg++;
                }
            }
            
        }
        
        return vector<vector<int>>(result.begin(), result.end());
                
    }
};