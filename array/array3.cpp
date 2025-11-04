#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hm;
        vector<int> v;
        int sz = nums.size();
        for(int i = 0; i < sz; i++)
        {
            int difference = target - nums[i];
            if(hm.find(difference) != hm.end())
            {
                v.push_back(hm[difference]);
                v.push_back(i); //i != 0 in all cases
                return v;
            }
            else{
                hm[nums[i]] = i;
            }
        }
    }
};



int main() {
  vector<int> nums = {3,4,5,6};
  int target = 7;
  Solution res;
  vector<int> rs = res.twoSum(nums, target);
  for(int i = 0; i < rs.size(); i++)
    cout << rs[i] << " ";

  return 0;
}
