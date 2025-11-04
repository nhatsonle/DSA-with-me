#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(),
        [](char c){ return !(isalpha(c) || isdigit(c)); }), // keep only letters and digits
        s.end());
        for(auto& c : s)
        {
            c = tolower(c);
        }
        int i = 0; int j = s.size() - 1;
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

int main()
{
    Solution res;
    string s = "Was it a car or a cat I saw?";
    cout << res.isPalindrome(s) << endl;
    return 0;
}
