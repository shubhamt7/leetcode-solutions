class Solution {
    public int superpalindromesInRange(String left, String right) {
        List<Long>palindromeNos = new ArrayList<>();
        
        long leftNo = Long.parseLong(left);
        long rightNo = Long.parseLong(right);
        
        //generating palindrome numbers

        for(long i = 1; i <= 9; i++){
            palindromeNos.add(i);
        }
        
        for(int i = 1; i < 10000; i++){
            String leftPart = Long.toString(i);
            String rightPart = new StringBuilder(leftPart).reverse().toString();
            
            //in range 10^8
            palindromeNos.add(Long.parseLong(leftPart + rightPart));
            
            //in range 10^9
            for(int digit = 0; digit <= 9; digit++){
                palindromeNos.add(Long.parseLong(leftPart + digit + rightPart));
            }
        }
        
        // Now, we will check whether the squares of these palindromes
        // are also palindromes, and lie between the given range.
        
        int count = 0;
        for(long num : palindromeNos){
            
            long sqNum = num*num;
            if(leftNo <= sqNum && sqNum <= rightNo && isPalindrome(Long.toString(sqNum))){
                count++;
            }
            
        }
        
        return count;
        
    }

    boolean isPalindrome(String num){
    
        int n = num.length();
        for(int i = 0; i < n / 2; i++){
            if(num.charAt(i) != num.charAt(n - 1 - i))
                return false;
        }
        
        return true;
        
    }
}

