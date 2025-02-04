class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        int sum=nums[0];
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                 sum+=nums[i+1]; 
            }
            else {
                res.push_back(sum);
                sum=nums[i+1];
            }
        }
        res.push_back(sum);
        int max= *max_element(res.begin(), res.end());
        return max;
    }
};