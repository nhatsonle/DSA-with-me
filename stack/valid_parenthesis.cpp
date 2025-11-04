#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        for(auto i : nums)
        {
            hmap[i]++;
        }
        vector<pair<int,int>> data;
        for(const auto& [key, value]: hmap)
        {
            data.push_back({key, value});
        }
        auto cmp = [](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        vector<int> res;
        for(auto p : data)
            pq.push(p);
        while(k > 0)
        {
            res.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return res;
    }
};
int main()
{
    Solution res;
    vector<int> nums = {1,2,2,3,3,3};
    int k = 2;
    vector<int> rs = res.topKFrequent(nums, k);
    for(int i = 0; i < rs.size(); i++)
    {
        cout << rs[i] << " ";
    }
    return 0;
}
