// Problem Link: https://leetcode.com/problems/destroying-asteroids/description/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        long long weight = mass;
        
        for(int i = 0; i < n; i++){
            if(weight >= asteroids[i]) weight += asteroids[i];
            else return false;
        }
        return true;
    }
};