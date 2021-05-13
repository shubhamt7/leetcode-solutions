bool checkAllZeroes(string s){
    bool allAreZeroes = true;
    
    for(char c : s){
        if(c != '0'){
            allAreZeroes = false;
            break;
        }
    }
    
    return allAreZeroes;
}

void generatePossibleCoods(string s, vector<string>&possibleCoods){


    if(s.length() == 1){
        possibleCoods.push_back(s);
        return;
    }
        
    if(s[0] != '0' )
        possibleCoods.push_back(s);
    
    for(int i = 1; i < s.length(); i++){
        string s1 = s.substr(0, i);
        if(checkAllZeroes(s1) && s1.length() > 1)
            continue;
        
        string s2 = s.substr(i, s.length());
        if(checkAllZeroes(s2) && s2.length() > 1)
            continue;
        
        if(s2[s2.length() - 1] == '0' || s1.length() > 1 && s1[0] == '0')
            continue;
        else
            possibleCoods.push_back(s1 + "." + s2);
    }
    
}

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        
        if(s.length() == 4){
            s.insert(2, ", ");
            return {s};
        }
        s = s.substr(1, s.length() - 2);
        // cout<<s<<' ';
        
        if(checkAllZeroes(s)){
            return {};
        }
        
        
        vector<string>coordinateStrings;
        
        for(int i = 1; i < s.length(); i++){
            string s1 = s.substr(0, i);
            string s2 = s.substr(i, s.length());
            
            if(checkAllZeroes(s1) && s1.length() > 1)
                continue;
        
            if(checkAllZeroes(s2) && s2.length() > 1)
                continue;
            
            vector<string>possibleAs;
            vector<string>possibleBs;

            generatePossibleCoods(s1, possibleAs);
            generatePossibleCoods(s2, possibleBs);
            
            for(string a : possibleAs){
                for(string b : possibleBs){
                    coordinateStrings.push_back("(" + a + ", " + b + ")");
                }
            }
        }
        
        // sort(coordinateStrings.begin(), coordinateStrings.end());
        return coordinateStrings;
       
    }
};
