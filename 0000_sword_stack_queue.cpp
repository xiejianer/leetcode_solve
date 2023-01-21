class CQueue {
public:
    CQueue() {}

    void appendTail(int value) {
        if (s1.empty()) {
            //int num = 0;
            while (! s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        s1.push(value);
    }

    int deleteHead() {
        while (! s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        if (s2.empty()) {
            return -1;
        }
        int num = s2.top();
        s2.pop();
        return num;
    }
private:
    stack<int> s1;
    stack<int> s2;
};
