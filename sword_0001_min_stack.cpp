class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        if (s2.empty() || x <= s2.top()) {
            s2.push(x);
        }
        if (x > s2.top()) {
            s2.push(s2.top());
        }
        s1.push(x);
    }

    void pop() {
        s1.pop();
        s2.pop();
    }

    int top() {
        if (s1.empty()) return -1;
        return s1.top();
    }

    int min() {
        if (s2.empty()) return -1;
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};
