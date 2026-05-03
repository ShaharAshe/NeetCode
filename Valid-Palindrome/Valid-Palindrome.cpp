#include <cstdlib>
#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        for(int left_i = 0, right_i = s.size()-1; left_i <= right_i; ++left_i, --right_i) {
            while (left_i <= right_i && !std::isalnum(s[left_i])) ++left_i;
            while (left_i <= right_i && !std::isalnum(s[right_i])) --right_i;
            if (right_i < left_i) return true;
            if(std::tolower(s[left_i]) != std::tolower(s[right_i])) return false;
        }
        return true;
    }
};

int main() {
    // std::string s = "Was it a car or a cat I saw?";
    std::string s = "No lemon, no melon";

    auto result = Solution().isPalindrome(s);

    std::cout << (result? "True" : "False") << std::endl;

    return EXIT_SUCCESS;
}