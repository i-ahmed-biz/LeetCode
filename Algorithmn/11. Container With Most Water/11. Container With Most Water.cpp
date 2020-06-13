class Solution {
public:
    int maxArea(vector<int>& height) {
       int max = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int area = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
                if(area > max) {
                    max = area;
                }
            }
        }
        
        return max;
    }
};