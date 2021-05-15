class Solution {
    
    public boolean checkValidLeftNumber(String s){ 
        boolean isValidNumber = true;
        
            try{
                Double num = Double.parseDouble(s); 
            }catch(Exception e){
                isValidNumber = false;
            }
      
        return isValidNumber;
    }
    
    public boolean checkValidRightNumber(String s){ 
         boolean isValidNumber = true;
        
            try{
                Long num = Long.parseLong(s); 
            }catch(Exception e){
                isValidNumber = false;
            }
      
        return isValidNumber;
    }
    
    public boolean isNumber(String s) {
                 
        if(s.length() == 1){
            return Character.isDigit(s.charAt(0));
        }
        
        if(Character.isLetter(s.charAt(0)) || Character.isLetter(s.charAt(s.length() - 1)))
            return false;
        
        if(s.contains("e")){
            String[] subs = s.split("e");
            
            if(subs.length != 2)
                return false;
            
            String left = subs[0];
            String right = subs[1];
            
            boolean ans = checkValidLeftNumber(left) && checkValidRightNumber(right); 
            return ans;
            
        }else{
            return checkValidLeftNumber(s);
        }
               
    }
}
