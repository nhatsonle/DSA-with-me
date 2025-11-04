#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

/*class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        for(int i : nums){
            hmap[i]++;
        }
        vector<int> temp;
        for(const auto& [key, value]: hmap)
        {
            tmp.push_back(value);
        }
        sort(tmp.begin(), tmp.sort(), greater<int>());



        vector<int> res;
        for (const auto& [key, value] : hmap)
            res.push_back(value);
        return res;
    }
};
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int n : nums) {
            count[n] = 1 + count[n];
        }
        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = freq.size() - 1; i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};

