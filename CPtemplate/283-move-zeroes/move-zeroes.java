class Solution {
    private void swap(int[] a, int j, int i){
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    } 
    public void moveZeroes(int[] nums) {
        int z = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i] != 0){
                swap(nums,i,z);
                System.out.println(i+" "+z);
                z++;
            }
        }
    }
}