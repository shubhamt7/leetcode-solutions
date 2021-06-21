class Solution {
    private void addNewRow(ArrayList<ArrayList<Integer>> rows){
        
        ArrayList<Integer>lastRow = (ArrayList) rows.get(rows.size() - 1);
        int n = lastRow.size();
            
        ArrayList<Integer>newRow = new ArrayList<Integer>();
        newRow.add(1);
        
        int l = 0, r = 1;
        while(r < n){
            newRow.add(lastRow.get(l) + lastRow.get(r));
            l++; r++;
        }

        newRow.add(1);
        rows.add(newRow);
    }
    
    public List<List<Integer>> generate(int numRows) {
        
        ArrayList rows = new ArrayList();
        
        ArrayList<Integer>firstRow = new ArrayList<Integer>();
        firstRow.add(1);
        rows.add(firstRow);
        int remainingRows = numRows - 1;
        
        while(remainingRows > 0){
            addNewRow(rows);
            remainingRows--;    
        } 
        
        return rows;
        
    }
}