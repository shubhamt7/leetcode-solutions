class Solution {
    public int jump(int[] nums) {
        if(nums.length == 1)return 0;
        
        int l = 0, r = 0;
        int farthest;
        int jumps = 0;
        
        while(r < nums.length - 1){
            farthest = l;
            
            for(int i = l; i <= r; i++){
                farthest = Math.max(farthest, i + nums[i]);
            }
            
            jumps++;
            l = r + 1;
            r = farthest;
        }
        return jumps;
        
    }
}


// Explanation - https://youtu.be/dJ7sWiOoK7g
