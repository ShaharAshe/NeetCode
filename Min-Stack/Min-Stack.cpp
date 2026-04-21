#include <cstdlib>
#include <iostream>
#include <vector>

class MinStack {
public:
    MinStack() : _min(INT32_MAX), _size(0) {}
    
    void push(int val) {
        _stack.emplace_back(val);
        if (val < _min) {
            _min = val;
        }
        _min_vals_stack.emplace_back(_min);
        ++_size;
    }
    
    void pop() {
        if (0 < _size && !_stack.empty() && !_min_vals_stack.empty()) {
            _stack.pop_back();
            _min_vals_stack.pop_back();
            --_size;
            if (_size == 0) {
                _min = INT32_MAX;
            } else {
                _min = _min_vals_stack[_size - 1];
            }
        }
    }
    
    int top() {
        if (_size != 0) {
            return _stack[_size - 1];
        }
        return 0;
    }
    
    int getMin() {
        if (_size != 0) {
            return _min;
        }
        return 0;
    }
private:
    std::vector<int> _stack;
    std::vector<int> _min_vals_stack;
    int _min;
    int _size;
};

int main() {
    auto minStack = new MinStack();
    int result;
    // ["getMin", "pop", "top", "getMin"]
    minStack->push(2);
    minStack->push(0);
    minStack->push(-3);
    result = minStack->getMin();
    std::cout << result << " ";
    minStack->pop();
    result = minStack->top();
    std::cout << result << " ";
    result = minStack->getMin();
    std::cout << result << " ";
    minStack->push(2);
    minStack->push(-4);
    minStack->push(3);
    result = minStack->getMin();
    std::cout << result << " ";
    minStack->pop();
    result = minStack->getMin();
    std::cout << result << " ";
    minStack->pop();
    result = minStack->top();
    std::cout << result << " ";
    result = minStack->getMin();
    std::cout << result << " ";
    minStack->pop();
    result = minStack->top();
    std::cout << result << " ";
    result = minStack->getMin();
    std::cout << result << " ";

    // minStack->push(1);
    // minStack->push(2);
    // minStack->push(0);
    // result = minStack->getMin(); // return 0
    // std::cout << result << " ";
    // minStack->pop();
    // result = minStack->top();    // return 2
    // std::cout << result << " " ;
    // result = minStack->getMin(); // return 1
    // std::cout << result << " " ;
    // std::cout <<std::endl;
    delete minStack;

    return EXIT_SUCCESS;
}