class Solution {
    public boolean checkPossibility(int[] nums) {
    
        for(int i = 1, err = 0; i < nums.length; i++){
            
            if(nums[i] < nums[i - 1]){
                
                if(err == 1 || (i > 1 && i < nums.length - 1 && nums[i + 1] < nums[i - 1] && nums[i - 2] > nums[i]))
                    return false;
                
                err++;
            }
        }
        
        return true;    
    }
}


// https://leetcode.com/problems/non-decreasing-array/discuss/1190763/JS-Python-Java-C%2B%2B-or-Simple-Solution-w-Visual-Explanation
