class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n);
        right.back() = nums.back();
        for(int i = n - 2; i >= 0; i--){
            right[i] = right[i + 1] + nums[i];
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            int rightSum = i + 1 < n ? right[i + 1] : 0;
            if(sum == rightSum) return i;
            sum += i >= 0? nums[i] : 0;
        }
        return -1;
    }
};