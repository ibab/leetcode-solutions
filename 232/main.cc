#include <stack>

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        std::stack<int> new_stack;
        new_stack.push(x);
        std::stack<int> tmp;
        while (!stack_.empty()) {
            tmp.push(stack_.top());
            stack_.pop();
        }
        while (!tmp.empty()) {
            new_stack.push(tmp.top());
            tmp.pop();
        }
        stack_ = new_stack;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack_.pop();
    }

    // Get the front element.
    int peek(void) {
        return stack_.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stack_.empty();
    }
private:
    std::stack<int> stack_;
};

