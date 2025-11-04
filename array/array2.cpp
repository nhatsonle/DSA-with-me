#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq1, freq2;
        if(s.size() != t.size())
        {
            return false;
        }
        for(char c : s){
            freq1[c]++;
        }
        for(char c : t){
            freq2[c]++;
        }
        for(char c : s)
        {
            if(freq1[c] != freq2[c])
                return false;
        }
        return true;
    }
};


int main() {
  string s = "jar", t = "jam";
  Solution res;
  cout << res.isAnagram(s,t) << endl;
  return 0;
}
