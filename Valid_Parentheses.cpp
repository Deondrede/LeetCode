#include <stack>
class Solution {
public:
    bool isValid(string s) {
        if ((s.length() == 1) || (s.empty() == true) || (s[0] == ']') || (s[0] == '}') || (s[0] == ')')){
            return false;
        }
        
        int leftoverBrace = 0;
        stack<char> braceStack;
        
        for (auto brace : s){
            if ((brace == '[') || (brace == '{') || (brace == '(')){
                braceStack.push(brace);
            }
            else if (!braceStack.empty()){
                if ((braceStack.top() == '[' && brace == ']') || (braceStack.top() == '{' && brace == '}') || (braceStack.top() == '(' && brace == ')')){
                    braceStack.pop();
                }
                else{
                    leftoverBrace++;
                }
            }
            else{
                leftoverBrace++;
            }
        }
        
        if (braceStack.empty() && leftoverBrace == 0){
            return true;
        }
        else {
            return false;
        }
    }
};