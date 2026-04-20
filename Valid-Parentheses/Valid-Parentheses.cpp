#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::unordered_map<char, char> open_close_parentheses{
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        std::stack<char> parentheses_stack;

        for (auto &c : s) {
            if (open_close_parentheses.find(c) != open_close_parentheses.end()) {
                parentheses_stack.push(c);
            } else {
                if (!parentheses_stack.empty() && open_close_parentheses[parentheses_stack.top()] == c) {
                    parentheses_stack.pop();
                } else {
                    return false;
                }
            }
        }
        return (parentheses_stack.empty()) ? true : false;
    }
};

int main() {
    std::string s = "([{}])";
    auto result = Solution().isValid(s);

    std::cout << (result ? "true" : "false") << std::endl;

    return EXIT_SUCCESS;
}