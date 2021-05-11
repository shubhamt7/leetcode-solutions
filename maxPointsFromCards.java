class Solution {
    public int maxScore(int[] cardPoints, int k) {
        
        int ans = 0;
        int size = cardPoints.length - k;
        int start = 0, end = size - 1;
        
        int sum = 0;
        int total_sum = 0;
        
        for(int cardPoint : cardPoints){
            total_sum += cardPoint;
        }
        if(cardPoints.length == k)
            return total_sum;
        
        for(int i = 0; i < size; i++){
            sum += cardPoints[i];
        }
        
        ans = Math.max(ans, total_sum - sum);
        
        end++;
        while(end < cardPoints.length){
            sum -= cardPoints[start];
            sum += cardPoints[end];
            start++;
            end++;
            ans = Math.max(ans, total_sum - sum);
        }
    
        return ans;
    }
}
