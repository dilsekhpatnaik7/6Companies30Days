// Problem Link: https://leetcode.com/problems/throne-inheritance/description/

class ThroneInheritance {
    unordered_map<string, bool> dead;  
    unordered_map<string, vector<string>> family;  
    string root;

public:
    ThroneInheritance(string kingName) {
        root = kingName;
    }
    
    void birth(string parentName, string childName) {
        family[parentName].push_back(childName);   
    }
    
    void death(string name) {
        dead[name] = true;
    }
    
    void dfs(vector<string> &ans, string root) {
        if(!dead[root]) ans.push_back(root);
        
        for(string child: family[root]) {
            dfs(ans, child);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(ans, root);
        return ans;
    }
};