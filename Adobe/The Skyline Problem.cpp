// Problem Link: https://leetcode.com/problems/the-skyline-problem/description/

class Solution {
public:
    void makeXArray(vector<int>& xarr, vector<vector<int>>& buildings){
        for(auto b: buildings){
            xarr.push_back(b[0]);
            xarr.push_back(b[1]);
        }
        unique(xarr.begin(), xarr.end());
        sort(xarr.begin(), xarr.end());
    }

    int getMax(priority_queue<pair<int,int>>& q, int x){
        int maxHeight = 0;
        while(!q.empty()) {
            auto top = q.top();
            if(top.second <= x) q.pop();
            else {
                maxHeight = top.first;
                break;
            }
        }
        return maxHeight;
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<vector<int>> result;
        vector<int> xarr(2 * n);

        makeXArray(xarr, buildings);
        
        priority_queue<pair<int,int>> q;
        int prevHeight = 0, i = 0;
        for(auto it : xarr){
            while(i < n and buildings[i][0] == it){
                q.push({buildings[i][2], buildings[i][1]});
                i++;
            }
            int maxHeight = getMax(q, it);
            if(prevHeight != maxHeight) result.push_back(vector<int> {(int)it, maxHeight});
            prevHeight = maxHeight;
        }
        return result;
    }
};