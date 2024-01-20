// Problem Link: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";

        for(auto word: dictionary) {
            int i = 0, j = 0;
            while(i < s.size() && j < word.size()) {
                if(s[i] == word[j]) i++, j++;
                else i++;
            }
            if(j == word.size()) {
                if(word.size() > ans.size() || word.size() == ans.size() && word < ans) ans = word;
            }
        }
        return ans;
    }
};