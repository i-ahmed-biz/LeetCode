class Solution {
    void swap(char &s1, char &s2) {
        char temp = s1;
        s1 = s2;
        s2 = temp;
    }
    void reverseStr(string& str) 
    { 
        int n = str.length(); 
  
        for (int i = 0; i < n / 2; i++) 
            swap(str[i], str[n - i - 1]); 
    } 
public:
    int reverse(int x) {
      int sign = 1;
      if(x <= INT_MIN) {
          x = 0;
      }
      else if(x < 0) {
          sign = -1;
          x = -x;
      }
      string str = to_string(x); 
      reverseStr(str);
      long long xL = sign * atol(str.c_str());
      if(xL >= INT_MAX)  {
         xL = 0; 
      }
      else if(xL <= INT_MIN) {
          xL = 0;
      }
    
      return (int) xL;
    }
};