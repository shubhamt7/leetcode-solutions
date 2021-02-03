class Solution {
public:
    string getSmallestString(int n, int k) {
        
        int c = 26;
        string result = "";
        
        while(n != 0){
            if(k - c >= n - 1){
                n--;
                result += (c-1) + 'a';
                k -= c;
            }else{
                c--;
            }
        }
        
        reverse(result.begin(), result.end());
        
        return result;
        
    }
};
