// Problem Link: https://www.geeksforgeeks.org/problems/run-length-encoding/1

string encode(string src) {
    string ans = "";
    for(int i = 0; i < src.length(); ) {
        int character = src[i];
        int count = 0;
        
        ans += character;
        while(i < src.length() && src[i] == character) {
            count++;
            i++;
        }
        ans += count + '0';
    }
    return ans;
}