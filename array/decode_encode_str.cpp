#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string s : strs)
        {
        	int sz = s.size();
            string tmp = to_string(sz);
            res += tmp;
            res += '#';
            res += s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> result;
        size_t i = 0;
        while(i < s.size())
        {
            int pos = s.find('#', i);
            if(pos == string::npos)
            {
                break;
            }

            string strlen = s.substr(i, pos - i);
            int len = 0;
            try{
                len = stoi(strlen);
            }catch (const invalid_argument&) {
                // couldn't parse length -> malformed
                break;
            } catch (const out_of_range&) {
                // length too large -> malformed
                break;
            }

            i = pos + 1;
            if(i + static_cast<size_t>(len) > s.size())
            {
                break; //the length of the substr to be read exceeds the one of the original string
            }
            result.push_back(s.substr(i, len));
            i += len;
        }
        return result;
    }
};


int main()
{
	Solution sol;
	vector<string> s = {"neet", "code"};
	cout << sol.encode(s) << endl;
	vector<string> res = sol.decode(sol.encode(s));
    for(auto a : res)
    {
        cout << a << endl;
    }

	return 0;
}
