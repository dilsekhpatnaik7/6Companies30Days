// Problem Link: https://leetcode.com/problems/bulls-and-cows/description/

class Solution {
public:
    string getHint(string& secret, string &guess) {
        unordered_map<char,int> secret_freq;
        unordered_map<char,int> guess_freq;

        int size = secret.size();

        int bulls = 0;
        int cows = 0;
        for(int i = 0; i < size; i++){
            if(secret[i] == guess[i]){
                bulls++;
            } else{
                secret_freq[secret[i]]++;
                guess_freq[guess[i]]++;
            }
        }

        for(auto it: guess_freq){
            cows += min(it.second, secret_freq[it.first]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};