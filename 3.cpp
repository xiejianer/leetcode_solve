#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max_len = 0;
		unordered_map<char, int> um;
		int start_pos = 0;
		int idx = 0;
		while (idx < s.length()) {
			if (um.find(s[idx]) != um.end()) {
				if (idx - start_pos > max_len) {
					max_len = idx - start_pos;
				}
				if (um[s[idx]] + 1 > start_pos) {
					start_pos = um[s[idx]] + 1;
				}
			}
			um[s[idx]] = idx;
			++idx;
		}
		if (idx - start_pos > max_len) {
			max_len = idx - start_pos;
		}
		return max_len;
	}
};

int main()
{
	Solution s;
	string str1 = "abcabcbb", str2 = "bbbb", str3 = "pwwkew", str4 = "";
	cout << s.lengthOfLongestSubstring(str1) << endl;
	cout << s.lengthOfLongestSubstring(str2) << endl;
	cout << s.lengthOfLongestSubstring(str3) << endl;
	cout << s.lengthOfLongestSubstring(str4) << endl;
	return 0;
}
