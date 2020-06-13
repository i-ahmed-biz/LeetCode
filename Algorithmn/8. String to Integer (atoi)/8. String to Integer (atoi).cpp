class Solution {
public:
    int myAtoi(string str) {
       int x; 
       string filterStr = "";
       int i = 0;

       while(i < str.length() && isspace(str.at(i))) {
           i++;
       }
       if((i < str.length()) && (str.at(i) == '+' || str.at(i) == '-' || isdigit(str.at(i)))){
           filterStr.append(1, str.at(i));
           i++;
       }
       else {
           return 0;
       }

       while(i < str.length() && isdigit(str.at(i))) {
           filterStr.append(1, str.at(i));
           i++;
       }
   
       long longValue = atol(filterStr.c_str());
       if(longValue < INT_MIN) {
           return INT_MIN;
       }
       
       if(longValue > INT_MAX) {
           return INT_MAX;
       }
       return (int)longValue;
    }
};