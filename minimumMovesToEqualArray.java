class Solution {
    public int minMoves2(int[] nums) {
        
        int dist = 0;
        Arrays.sort(nums);
        int n = nums.length;
        int mid = n % 2 == 0 ? (nums[n/2] + nums[n/2 - 1]) / 2 : nums[n/2];
        
        for(int x : nums){
            dist += Math.abs(x - mid);
        }
        
        return dist;
        
    }
}


// remember that, the median minimizes the sum of absolute distances
