class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        int index1 = 0; 
        int index2 = 0;
        
        while(index1 < nums1.size() && index2 < nums2.size()) {
            if(nums1[index1] < nums2[index2]) {
                result.push_back(nums1[index1]);
                index1++;
            }
            else {
                result.push_back(nums2[index2]);
                index2++;
            }
        }

        if(index1 < nums1.size()) {
            for(;index1 < nums1.size(); index1++) {
                result.push_back(nums1[index1]);
            }
        }
        
        if(index2 < nums2.size()) {
            for(;index2 < nums2.size(); index2++) {
                result.push_back(nums2[index2]);
            }
        }
        
        if(result.size() == 1) {
            return result[0];
        }
        else if(result.size() % 2 == 1) {
            return (double) result[(result.size() / 2)];
        }
        else {
            return ((double) result[(result.size() / 2) - 1] + (double) result[(result.size() / 2)]) / 2.0;
        }
        
        return 0;
    }
};