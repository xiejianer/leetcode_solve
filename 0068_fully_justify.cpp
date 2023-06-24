class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if (words.size() == 0) return res;
        int start_pos = 0;
        int end_pos = 0;
        while (start_pos < words.size()) {
            int max_len = 0;
            int real_len = 0;
            while (start_pos < words.size()) {
                if (start_pos == end_pos) {
                    max_len += words[end_pos].size();
                } else {
                    max_len += words[end_pos].size() + 1;
                }
                real_len += words[end_pos].size();
                if (end_pos + 1 < words.size() && max_len + words[end_pos + 1].size() + 1 <= maxWidth) {
                    ++end_pos;
                } else {
                    break;
                }
            }
            if (end_pos + 1 == words.size()) break;
            vector<string> blanks(end_pos - start_pos, "");
            int blank_size = maxWidth - real_len;
            while (blank_size > 0 && end_pos > start_pos) {
                for (int i = 0; i < end_pos - start_pos; ++i) {
                    blanks[i] += " ";
                    --blank_size;
                    if (blank_size <= 0) break;
                }
            }
            string tmp = "";
            for (int i = start_pos; i < end_pos; ++i) {
                tmp += words[i] + blanks[i - start_pos];
            }
            tmp += words[end_pos];
            if (start_pos == end_pos) {
                while (tmp.size() < maxWidth) {
                    tmp += " ";
                }
            }
            res.push_back(tmp);
            start_pos = end_pos + 1;
            ++end_pos;
        }
        string s = "";
        for (int i = start_pos; i < end_pos; ++i) {
            s += words[i] + " ";
        }
        s += words[end_pos];
        while (s.size() < maxWidth) {
            s += ' ';
        }
        res.push_back(s);
        return res;
    }
};
