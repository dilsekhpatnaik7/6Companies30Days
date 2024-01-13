// Problem Link: https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for(int i = 0; i < s.size(); i++) m[s[i]]++;

        vector<pair<int, char>> v;
        for(auto i: m) v.push_back({i.second, i.first});
        sort(v.rbegin(), v.rend());

        string ans = "";
        for(auto i: v) {
            for(int j = 0; j < i.first; j++) ans += i.second;
        }
        return ans;
    }
};