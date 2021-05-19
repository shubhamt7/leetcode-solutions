class Solution {
public:
    
    vector<string> getFileNameAndContent(string file){
        string content = "";
        int i;
        for(i = file.length() - 2; file[i] != '('; i--){
            content += file[i];
        }
        
        string fileName = file.substr(0, i);
        return {content, fileName};
        
    }
    
    vector<string>tokenizer(string s)
    {
        vector<string>v;
        
        stringstream ss(s);
        string word;
        while (ss >> word) {
            v.push_back(word);
        }
        
        return v;
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string, vector<string>>map;
        
        for(string path : paths){
            vector<string>dirAndFiles = tokenizer(path);
            
            string directory = dirAndFiles[0];
            
            for(int i = 1; i < dirAndFiles.size(); i++){
                
                vector<string>details = getFileNameAndContent(dirAndFiles[i]);
                string filePath = directory + "/"+ details[1];
                
                map[details[0]].push_back(filePath);
            }
        }
        
        vector<vector<string>>ans;
        
        for(auto entry : map){
            
            if(entry.second.size() > 1){
                ans.push_back(entry.second);
            }
            
        }
        
        return ans;
        
    }
};
