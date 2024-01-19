// Problem Link: https://leetcode.com/problems/short-encoding-of-words/description/

class Solution {
public:
    static bool comp(string& s, string& t) {
        return s.size() > t.size();
    }

    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, int> m;
        sort(words.begin(), words.end(), comp);

        for(int i = 0; i < words.size(); i++) m[words[i]]++;

        int ans = 0;
        for(int i = 0; i < words.size(); i++) {
            int size = words[i].size();
            if(m[words[i]] > 0) ans += size + 1;

            for(int j = size - 1; j >= 0; j--) {
                string s = words[i].substr(j, size - j);
                m[s] = 0;
            }
        }
        return ans;
    }
};