/*
leetcode.com/problems/valid-parentheses/
*/

class Solution {

   
public:
    bool isValid(string s) {
        stack<char> st;
         unordered_map<char ,char> umap;
            umap[')'] = '(';
            umap['}'] = '{';
            umap[']'] = '[';
        
        int size = s.length();
        for(int i = 0 ; i < size; i++){
           
            if(umap.find(s.at(i)) == umap.end()){
                 
                st.push(s.at(i));
            }else{
                // cout<<"tt"<<s.at(i)<<st.top() <<umap.at(s.at(i))<<endl;
                if(st.empty()) return false;
                if(st.top() != umap.at(s.at(i))) return false;
                st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
        
    }
};
