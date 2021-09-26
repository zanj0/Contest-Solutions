
class Solution {
public:
    
    vector<pair<int, char>> modify(string& s){
        vector<pair<int, char>> ret;
        pair<int, char> temp;
        int n = s.size();
        temp.second = '~';
        for(int i = 0; i < n; i++){
            if(s[i] == '+'|| s[i] == '*'){
                ret.push_back(temp);
                temp.first = 0;
                temp.second = s[i];
                ret.push_back(temp);
                temp.second = '~';
            }else{
                temp.first *= 10;
                temp.first += s[i] - '0';
            }
        }
        ret.push_back(temp);
        return ret;
    }
    
    void out(vector<pair<int, char>>& v){
        for(auto& it : v){
            cout << it.first << " " << it.second << endl;
        }
    }
    
    unordered_map<int, map<int, unordered_set<int>>> dp;
    
    unordered_set<int> dfs(int l, int r, vector<pair<int, char>>& v){
        if(dp.count(l) && dp[l].count(r))  {
            return dp[l][r];
        }
        unordered_set<int> ret;
        if(l == r){
            ret.insert(v[l].first);
            return dp[l][r] = ret;
        }
        for(int i = l; i <= r; i++){
            if(v[i].second != '~'){
                // Operator detected.
                bool add = v[i].second == '+';
                unordered_set<int> left = dfs(l, i - 1, v);
                unordered_set<int> right = dfs(i + 1, r, v);
                for(auto& l : left){
                    for(auto& r : right){
                        int val = add? l + r : l * r;
                        if(val > 1000) continue;
                        ret.insert(val);
                    }
                }
            }
        }
        return dp[l][r] = ret;
    }
    
    int getProperAns(vector<pair<int, char>>& v){
        vector<int> st;
        int ret = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i].second == '~'){
                st.push_back(v[i].first);
            }else if(v[i].second == '*'){
                int backNum = st.back();
                st.pop_back();
                st.push_back(backNum * v[i + 1].first);
                i++;
            }
        }
        for(int i : st){
            ret += i;
        }
        return ret;
    }
    
    int scoreOfStudents(string s, vector<int>& answers) {
        vector<pair<int, char>> v = modify(s);
        int ret = 0;
        unordered_set<int> possible = dfs(0, v.size() - 1, v);
        int real = getProperAns(v);
        for(int i : answers){
            if(i == real){
                ret += 5;
            }else if(possible.count(i)) ret += 2;
        }
        return ret;
    }
};