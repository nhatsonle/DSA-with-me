#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
public:
    bool hasDuplicate(vector<int>& nums){
        unordered_set<int> s(nums.begin(), nums.end());
        if(nums.size() == s.size())
        {
            return false;
        }
        else
            return true;

    }
};

int main() {
  vector<int> nums = {1,2,3,3};
  Solution res;
  cout << res.hasDuplicate(nums);
  return 0;
}
