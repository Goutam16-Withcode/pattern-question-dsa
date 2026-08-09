class MyQueue {
public:
    vector<int> v;

    MyQueue() {}

    void push(int x) {
        v.push_back(x);
    }

    int pop() {
        int front_element = v.front();
        v.erase(v.begin());
        return front_element;
    }

    int peek() {
        return v.front();
    }

    bool empty() {
        return v.empty();
    }
};