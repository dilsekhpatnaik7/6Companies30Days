// Problem Link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int repeating = -1, missing = -1;
        unordered_map<int, int> m;
        
        for(int i = 0; i < n; i++) {
            m[arr[i]]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if(m[i] == 2) repeating = i;
            if(m[i] == 0) missing = i; 
        }
        return {repeating, missing};
    }
};