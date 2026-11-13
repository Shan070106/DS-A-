class Solution {
    public int removeDuplicates(int[] nums) {
        int up = 1;
        for(int ci=1;ci<nums.length;ci++){
            if(nums[up-1] != nums[ci]){
                nums[up] = nums[ci];
                up++;
            }
        }
        return up;
    }
}