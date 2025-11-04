#include<iostream>
#include<vector>
#include<ctype.h>
#include<stack>
#include<string.h>
using namespace std;
class Solution {
    public:
        int dailyTemperatures(vector<int>& temperatures) {
            int left = 0;
            int right = 0;
            int res = 0;
            while(right < temperatures.size())
            {
                if(temperatures[left] == temperatures[right])
                    res = max((right - left + 1), res);
                right++;
                if(temperatures[left] != temperatures[right])
                    left = right;
            }
            return res;
        }
    };

int main()
{
    Solution sol;
    vector<int> num = {7,3,3,3,2,2,2,2};
    cout << sol.dailyTemperatures(num) << endl;
    return 0;
}
