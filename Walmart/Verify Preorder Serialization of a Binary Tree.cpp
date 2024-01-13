// Problem Link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.size() == 0) return true;

        istringstream s(preorder);
        string node;
        int vacancy = 1;
        while(getline(s, node, ',')) {
            vacancy--;
            if(vacancy < 0) return false;
            if(node != "#") vacancy += 2;
        }
        return vacancy == 0;
    }
};