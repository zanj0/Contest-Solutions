class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i = 0;
        int n = s.size();
        for(auto& it : words){
            int j = 0;
            while(j < it.size() && i < n && it[j] == s[i]){
                j++; i++;
            }
            if(j != it.size()) return false;
            if(i == n && j == it.size()) return true;
            if(i == n) return false;
        }
        return i == n;
    }
};