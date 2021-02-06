class Solution {
  public:
    string simplifyPath(string path) {
        
      //splitting the path at '/'
      vector < string > dirs;
      string s = "";
        
      for (int i = 0; path[i]; i++) {
        if(path[i] == '/') {
          if (s != "") {
            dirs.push_back(s);
            s = "";
          }
        } 
          else {
          s += path[i];
        }
      }
        
      if(s != ""){
          dirs.push_back(s);
      }
    
      // for(auto x : dirs){
      //     cout<<x<<' ';
      // }
        
      stack < string > st;
      //for each entry in directories (which can be some directory name, . or ..)
      //if . -> don't do anything, stay in the same directory
      //if .. -> pop the top of stack, because we want to go back to the parent directory
      //if some_name -> append the some_name directory to the simplified path, separated by a '/'
    
        
      for (int i = 0; i < dirs.size(); i++) {
        if (dirs[i] == ".") continue;

        else if (dirs[i] == "..") {
            
          if (st.empty()) 
              continue;
          else 
              st.pop();
        } 
          else 
              st.push(dirs[i]);

      }

      if (st.empty()) return "/";
      dirs.clear();

      while (!st.empty()) {
        // cout<<st.top()<<' ';
        dirs.push_back(st.top());
        st.pop();
      }

        
      reverse(dirs.begin(), dirs.end());

      string res = "";
      for (int i = 0; i < dirs.size(); i++) {

        res += "/";
        res += dirs[i];

      }

      return res;
    }
};
