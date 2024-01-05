// Problem Link: https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1

class Solution{   
public:
    string printMinNumberForPattern(string S){
        string ans = "";
        
        for(int i = 1; i <= S.size() + 1; i++) {
            ans += i + '0';
        }
        
        while(true) {
            int j = 1, k = 0;
            bool flag = true;
            
            while(j < ans.size()) {
               if(S[k] == 'D' && ans[j] > ans[j - 1]) {
                swap(ans[j], ans[j - 1]);
                flag = false;
              } 
              
              if(S[k] == 'I' && ans[j] < ans[j - 1]){
                  swap(ans[j], ans[j - 1]);
                  flag = false;
              }
              j++;
              k++;
            }
            if(flag) break;
        }
        return ans;
    }
};