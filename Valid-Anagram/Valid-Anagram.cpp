#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::unordered_map<char, int> s_letters_existens_map;
        for (size_t i = 0; i < s.size(); ++i) {
            ++s_letters_existens_map[s[i]];
            --s_letters_existens_map[t[i]];
        }

        for (auto &cell : s_letters_existens_map) {
            if (0 < cell.second || cell.second < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::string s = "racecar",
                t = "carrace";
    auto result = Solution().isAnagram(s, t);

    std::cout << ((result) ? "true" : "false") << std::endl;

    return EXIT_SUCCESS;
}