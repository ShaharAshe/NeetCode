#include <cstdlib>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left_i = 0,
            right_i = numbers.size() - 1;
        
        while (left_i < right_i) {
            int temp_sum = numbers[left_i] + numbers[right_i];
            if (temp_sum == target) {
                return std::vector<int>{left_i+1, right_i+1};
            }
            if (temp_sum < target){
                ++left_i;
            } else {
                --right_i;
            }
        }
        return std::vector<int>();
    }
};

int main() {
    std::vector<int> numbers{1,2,3,4};
    int target = 3;

    auto result = Solution().twoSum(numbers, target);

    for (auto &c : result) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    

    return EXIT_SUCCESS;
}