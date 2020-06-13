class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>romanMap; 
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;
        int sum = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i + 1 < s.length() && romanMap[s.at(i)] < romanMap[s.at(i + 1)]) {
                sum = sum + romanMap[s.at(i + 1)] - romanMap[s.at(i)];
                i++;
            }
            else {
                sum = sum + romanMap[s.at(i)];
            }
        }
        return sum;
    }
};
