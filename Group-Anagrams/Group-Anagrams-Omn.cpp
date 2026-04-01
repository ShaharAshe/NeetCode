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
        struct VectorHash {
            size_t operator()(const std::vector<size_t>& v) const {
                size_t hash = 0;
                for (auto &i : v) {
                    hash ^= std::hash<size_t>{}(i) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
                }
                return hash;
            }
        };
        
        std::unordered_map<std::vector<size_t>, std::vector<std::string>, VectorHash> anagram_listing_map;
        for (auto &c : strs) {
            std::vector<size_t> appearance(26);
            for (auto &i : c) {
                ++appearance[i - 'a'];
            }
            
            if(anagram_listing_map.find(appearance) != anagram_listing_map.end()) {
                anagram_listing_map[appearance].emplace_back(c);
            } else {
                anagram_listing_map.emplace(appearance, std::vector<std::string>{c});
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