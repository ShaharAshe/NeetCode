#include <cstdlib>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> result(nums.size(), 1);
        int temp_all_prod = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            int temp_one_back = nums[i-1];
            temp_all_prod *= temp_one_back;
            result[i] *= temp_all_prod;
        }
        temp_all_prod = 1;
        for (int i = nums.size()-2; 0 <= i; --i) {
            int temp_one_back = nums[i+1];
            temp_all_prod *= temp_one_back;
            result[i] *= temp_all_prod;
        }
        return result;
    }
};

int main() {
    std::vector<int> nums{1,2,4,6};

    auto result = Solution().productExceptSelf(nums);

    for (auto &num : result){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}