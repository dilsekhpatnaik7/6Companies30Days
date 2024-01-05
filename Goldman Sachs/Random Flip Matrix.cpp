// Problem Link: https://leetcode.com/problems/random-flip-matrix/description/

class Solution {
public:
    int i, j, m, n;
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        i = 0, j = 0;
    }
    
    vector<int> flip() {
        vector<int> v = {i, j};
        j = j + 1;
        if(j == n) {
            j = 0, i = i + 1;
            if(i == m) i = 0;
        }
        return v;
    }
    
    void reset() {
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */