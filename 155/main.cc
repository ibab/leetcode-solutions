
#include <stack>
#include <iostream>

// The idea is to use a second stack that keeps track of the 
// minimum element corresponding to the elements stored in the primary stack up
// to that point. If we maintain the secondary stack by calling push/pop each
// time we change the primary stack, the topmost element in the secondary stack
// will always be the correct minimum.
class MinStack {
public:
    MinStack() {
        minimum_.push(INT_MAX);
    }
    
    void push(int x) {
        stack_.push(x);
        if (x < minimum_.top()) {
            minimum_.push(x);
        } else {
            minimum_.push(minimum_.top());
        }
    }
    
    void pop() {
        stack_.pop();
        minimum_.pop();
    }
    
    int top() {
        return stack_.top();
    }
    
    int getMin() {
        return minimum_.top();
    }
private:
    std::stack<int> stack_;
    std::stack<int> minimum_;
};

int main() {
    MinStack stack;
    stack.push(4);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    for (int i = 0; i < 4; i++) {
        std::cout << "Top is " << stack.top() << std::endl;
        std::cout << "Min is " << stack.getMin() << std::endl;
        std::cout << "Removing element..." << std::endl;
        stack.pop();
    }
    return 0;
}
