/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set <string> us = {"+","-","/","*"};
        stack <int> s;
        int size = tokens.size();
        s.push(stoi(tokens[0]));
        for(int i = 1; i< size ; i++ ){
            if(us.find(tokens[i]) == us.end()){
                s.push(stoi(tokens[i]));
            }else{
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                s.push(compute(op1,op2,tokens[i]));
            }
        }
        return s.top();
        
    }
    int compute(int op1, int op2, string sign){
        
            return sign == "+" ? op1+op2 : sign == "*" ? op1*op2 :sign == "/" ? op1/op2 : op1-op2;  
    }
};
