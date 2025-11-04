#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<sstream>

using namespace std;



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hmap;
        vector<vector<string>> res;
        for(string str: strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());

            hmap[temp].push_back(str);
        }
        for (const auto& [key, value] : hmap)
            res.push_back(value);
        return res;
    }
};






int main() {
  vector<string> strs = {"act","pots","tops","cat","stop","hat"};
  Solution res;
  vector<vector<string>> rs = res.groupAnagrams(strs);
  for(int i = 0; i < rs.size(); i++)
    {
        for(int j = i; j < rs[0].size(); j++)
            cout << rs[i][j] << endl;
    }

  return 0;
}
