#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		vector<string> res = {};
		res = solve(digits, letters);
		return  res;
	}
	vector<string> solve(string s, vector<string> letters) {
		vector<string> res = {};
		if (s.size() == 0) return res;
		vector<string> tmp = solve(s.substr(1), letters);
		string s0 = letters[s[0] - '0'];
		for (int i = 0; i < s0.size(); ++i) {
			if (tmp.size() == 0) {
				res.push_back(s0.substr(i, 1));
			} else {
				for (int j = 0; j < tmp.size(); ++j) {
					res.push_back(s0[i] + tmp[j]);
				}
			}
		}
		return res;
	}
};

int main()
{
	return 0;
}