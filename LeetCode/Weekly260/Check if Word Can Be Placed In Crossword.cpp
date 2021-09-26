class Solution {
public:
    int r, c;
    bool vertical(vector<vector<char>>& v, string& s){
        int n = s.size();
        for(int j = 0; j < c; j++){
            for(int start = 0; start + n - 1 < r; start++){
                int sptr = 0;
                int rptr = start;
                if(start - 1 >= 0 && v[start - 1][j] != '#') continue;
                if(start + n < r && v[start + n][j] != '#') continue;
                while(sptr < s.size() && (v[rptr][j] == ' ' || v[rptr][j] == s[sptr])){
                    rptr++;
                    sptr++;
                }
                if(sptr == s.size()) return true;
            }
        }
        return false;
    }
    
    bool horizontal(vector<vector<char>>& v, string& s){
        int n = s.size();
        for(int i = 0; i < r; i++){
            for(int start = 0; start + n - 1 < c; start++){
                int sptr = 0;
                int cptr = start;
                if(start - 1 >= 0 && v[i][start - 1] != '#') continue;
                if(start + n < c && v[i][start + n] != '#') continue;
                while(sptr < s.size() && (v[i][cptr] == ' ' || v[i][cptr] == s[sptr])){
                    cptr++;
                    sptr++;
                }
                if(sptr == s.size()) return true;
            }
        }
        return false;
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        r = board.size();
        c = r? board[0].size() : 0;
        bool ret = false;
        
        ret = vertical(board, word) || horizontal(board, word);
        reverse(word.begin(), word.end());
        ret = ret || vertical(board, word) || horizontal(board, word);
        return ret;
    }
};