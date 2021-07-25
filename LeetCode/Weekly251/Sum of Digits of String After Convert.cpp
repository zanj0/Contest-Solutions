class Solution {
public:
    int getVal(string& s){
        int ret = 0;
        for(int i = 0; i < s.size(); i++){
            ret += (s[i] - '0');
        }
        return ret;
    }
    int getLucky(string s, int k) {
        int ret = 0;
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            temp += to_string((s[i] - 'a') + 1);
        }
        s = temp;
        while(k--){
            ret = getVal(s);
            s = to_string(ret);
        }
        return ret;
    }
};