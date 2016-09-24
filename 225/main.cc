class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        std::queue<int> new_queue;
        new_queue.push(x);
        while (!queue_.empty()) {
            new_queue.push(queue_.front());
            queue_.pop();
        }
        queue_ = new_queue;
    }

    // Removes the element on top of the stack.
    void pop() {
        queue_.pop();
    }

    // Get the top element.
    int top() {
        return queue_.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return queue_.empty();
    }
private:
    std::queue<int> queue_;
};

