class Solution {
public:
    string simplifyPath(string path) {
        string s = "/";
        int i = 1;
        int pos = 0;
        string tmp;
        while (i < path.size()) {
            pos = path.find('/', i);
            if (pos == string::npos) {
                tmp = path.substr(i);
                if (tmp == ".") break;
                else if (tmp == "..") {
                    int j = s.size() - 1;
                    if (j != 0) {
                        s.pop_back();
                        j--;
                    }
                    while (s[j] != '/') {
                        s.pop_back();
                        j--;
                    }
                    break;
                }
                else {
                    s += tmp;
                    break;
                }
            } else {
                if (pos != i) {
                    tmp = path.substr(i, pos - i);
                    if (tmp == "..") {
                        int j = s.size() - 1;
                        if (j != 0) {
                            s.pop_back();
                            j--;
                        }
                        while (s[j] != '/') {
                            s.pop_back();
                            j--;
                        }
                    }
                    else if (tmp == ".") {
                        ;
                    }
                    else {
                        s += tmp;
                        s += '/';
                    }
                }
            }
            i = pos + 1;
        }
        i = s.size() - 1;
        while (i != 0 && s[i] == '/') {
            s.pop_back();
        }
        return s;
    }
};
控制台

