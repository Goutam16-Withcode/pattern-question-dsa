class MyStack {
public:
    vector<int> nums;

    MyStack() {
    }

    void push(int x) {
        nums.push_back(x);
    }

    int pop() {
        int element = nums.back();
        nums.pop_back();
        return element;
    }

    int top() {
        return nums.back();
    }

    bool empty() {
        return nums.empty();
    }
};