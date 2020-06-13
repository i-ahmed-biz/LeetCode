class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() == 0 || numRows <= 1) {
            return s;
        }
        string zigZagArr[numRows];
        bool down = true;
        int row = 0;
        
        for(int i = 0; i < s.length(); i++) {
            zigZagArr[row].append(1, s.at(i));
            down ? row++:row--;
            if(row == numRows - 1) {
                down = false;
            }
            if(row == 0) {
                down = true;
            }
        }
        
        string result = "";
        
        for(int i = 0; i < numRows; i++) {
            result.append(zigZagArr[i]);
        }
        
        return result;
    }
};