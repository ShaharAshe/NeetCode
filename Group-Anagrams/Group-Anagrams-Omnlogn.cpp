#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagram_listing_map;
        for (auto &c : strs) {
            std::string sorted_c = c;
            std::sort(sorted_c.begin(), sorted_c.end());
            if(anagram_listing_map.find(sorted_c) != anagram_listing_map.end()) {
                anagram_listing_map[sorted_c].emplace_back(c);
            } else {
                anagram_listing_map.emplace(sorted_c, std::vector<std::string>{c});
            }
        }
        std::vector<std::vector<std::string>> results;
        for (auto &cell : anagram_listing_map) {
            results.emplace_back(cell.second);
        }
        return results;
    }
};

int main() {
    std::vector<std::string> strs{"act","pots","tops","cat","stop","hat"};
    auto result = Solution().groupAnagrams(strs);

    for (auto &i : result) {
        std::cout << "[";
        for (auto &j : i) {
            std::cout << j << " ";
        }
        std::cout << "]";
    }
    

    return EXIT_SUCCESS;
}