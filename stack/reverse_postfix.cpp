#include<iostream>
#include<vector>
#include<ctype.h>
#include<stack>
#include<string.h>

using namespace std;
class Solution{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> stk;
        for(auto s : tokens)
        {
            if(isdigit(s[0]) || s[0] == '-' && s.length() > 1)
            {
                try{
                    int val = stoi(s);
                    stk.push(val);
                } catch (const exception& e){
                    cerr << "Error converting number: " << s << endl;
                }
            }
            else
            {
                int tmp1 = stk.top();
                stk.pop();
                int tmp2 = stk.top();
                stk.pop();
                int new_operand;
                if(s == "+")
                {
                    new_operand = tmp2 + tmp1;
                }
                if(s == "-")
                {
                    new_operand = tmp2 - tmp1;
                }
                if(s == "*")
                {
                    new_operand = tmp2 * tmp1;
                }
                if(s == "/")
                {
                    new_operand = tmp2 / tmp1;
                }
                stk.push(new_operand);
            }
        }
        return stk.top();
    }
};

int main()
{

    return 0;
}
