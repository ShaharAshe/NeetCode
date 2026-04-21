#include <cstdlib>
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> numeric_calculate_stack;
        for (auto &c : tokens) {
            int numeric_val = std::atoi(c.c_str());
            if (numeric_val != 0 || c == "0") {
                numeric_calculate_stack.emplace(numeric_val);
            } else {
                int temp_val = 0;
                temp_val = numeric_calculate_stack.top();
                numeric_calculate_stack.pop();
                switch (c[0])
                {
                    case '+' : {
                        numeric_calculate_stack.top() += temp_val;
                        break;
                    }
                    case '-' : {
                        numeric_calculate_stack.top() -= temp_val;
                        break;
                    }
                    case '*' : {
                        numeric_calculate_stack.top() *= temp_val;
                        break;
                    }
                    case '/' : {
                        if (temp_val == 0) {
                            numeric_calculate_stack.top() = 0;
                        } else {
                            numeric_calculate_stack.top() /= temp_val;
                        }
                        break;
                    }
                }
            }
        }
        return numeric_calculate_stack.top();
    }
};

int main() {
    // std::vector<std::string> tokens {"1","2","+","3","*","4","-"};
    std::vector<std::string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    auto result = Solution().evalRPN(tokens);
    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}