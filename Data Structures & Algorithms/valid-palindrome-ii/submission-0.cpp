class Solution {
public:
   bool Palindrone(int i , int j , string & s){
       while(i<j){
          if(s[i]!=s[j]){
            return false;
          }
          i++;
        j--;
       }
       return true;
   }
    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0 , j = n-1;
        while(i<j){
            if(s[i]!=s[j]){
                return Palindrone(i+1,j,s) || Palindrone(i , j-1,s);
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};