class Solution {
public:
    bool has(int x, vector<int>& v){
        for(int i : v){
            if(i == x) return true;
        }
        return false;
    }
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> ret;
       for(int i : nums1){
           if(has(i, nums2)){
               ret.insert(i);
           }
           if(has(i, nums3)){
               ret.insert(i);
           }
       }
        for(int i : nums2){
           
           if(has(i, nums3)){
               ret.insert(i);
           }
       }
        return vector<int>(ret.begin(), ret.end());
    }
};