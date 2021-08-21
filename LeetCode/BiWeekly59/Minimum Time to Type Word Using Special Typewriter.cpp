class Solution {
public:
    int minTimeToType(string word) {
        int ret = 0;
        int curr = 0;
        int n = word.size();
        for(int i = 0; i < n; i++){
            int nxt = word[i] - 'a';
            int op1, op2;
            if(curr < nxt){
                op1 = nxt - curr;
                op2 = (curr + 1) + (25 - nxt);
            }else{
                op1 = curr - nxt;
                op2 = (25 - curr + 1) + nxt;
            }
            ret += min(op1, op2);
            curr = word[i] - 'a';
            ret += 1;
        }
        return ret;
    }
};