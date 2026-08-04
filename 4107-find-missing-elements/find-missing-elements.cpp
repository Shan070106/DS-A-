class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxe = *max_element(nums.begin(),nums.end());
        int mine = *min_element(nums.begin(),nums.end());

        int number[maxe+1];
        for(int i=1; i<=maxe; i++){
            number[i] = i;
        }

        for(int i: nums){
            number[i] = -1;
        }
        vector<int> ans;
        for(int i=mine;i<=maxe;i++){
            if(number[i] != -1)
                ans.push_back(i);
        }
        return ans;
    }
};