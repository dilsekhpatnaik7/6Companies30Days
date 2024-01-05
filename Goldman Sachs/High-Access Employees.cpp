// Problem Link: https://leetcode.com/problems/high-access-employees/description/

class Solution {
public:
    bool isHighAccessTime(vector<int>& time) {
        for(int i = 2; i < time.size(); i++) {
            int currentTime = time[i];
            int prevPrevTime = time[i - 2];

            if(currentTime - prevPrevTime <= 99) return true;
        }
        return false;
    }

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        unordered_map<string, vector<int>> m;

        for(auto i: access_times) {
            string employee = i[0];
            int time = stoi(i[1]);
            m[employee].push_back(time);
        }

        for(auto i: m) {
            vector<int> time = i.second;
            sort(time.begin(), time.end());

            if(isHighAccessTime(time)) ans.push_back(i.first);
        }
        return ans;
    }
};