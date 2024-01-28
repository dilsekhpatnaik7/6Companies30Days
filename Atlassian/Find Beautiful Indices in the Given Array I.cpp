// Problem Link: https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/description/

class Solution {
    vector<int> find_occurrences(string& s, string& b) {
        vector<int> indices;
        int i = s.find(b);
        while(i != string::npos) {
            indices.push_back(i);
            i = s.find(b, i + 1);
        }
        return indices;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> first = find_occurrences(s, a);
        vector<int> second = find_occurrences(s, b);

        int i = 0, j = 0;
        vector<int> ans;
        while(i < first.size() && j < second.size()) {
            if(abs(first[i] - second[j]) <= k) ans.push_back(first[i++]);
            else if(second[j] - first[i] > k) i++;
            else  j++;
        }
        return ans;
    }
};