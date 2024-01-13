// Problem Link: https://leetcode.com/problems/top-k-frequent-words/description/

class Solution {
public:
    static bool comp(pair<int, string>& p1, pair<int, string>& p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(int i = 0; i < words.size(); i++) m[words[i]]++;

        vector<pair<int, string>> v;
        for(auto i: m) v.push_back({i.second, i.first});
        sort(v.begin(), v.end(), comp);

        vector<string> ans;
        for(int i = 0; i < k; i++) ans.push_back(v[i].second);

        return ans;
    }
};