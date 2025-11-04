#include<iostream>
#include<vector>

using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        numbers.insert(numbers.begin(), 0);
        int startIdx = 1;
        int endIdx = numbers.size() - 1;
        while(startIdx < endIdx)
        {
            int sum = numbers[startIdx] + numbers[endIdx];
            if(sum == target)
            {
                res.push_back(numbers[startIdx]);
                res.push_back(numbers[endIdx]);
                return res;
            }
            else if(sum < target)
            {
                startIdx++;
            }
            else
            {
                endIdx--;
            }
        }
        return res;
    }
};


int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4};
    int target = 3;
    vector<int> res = sol.twoSum(nums, target);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}

