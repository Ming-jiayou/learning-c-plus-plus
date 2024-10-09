#include <vector>
#include <iostream>

int majorityElement(const std::vector<int>& nums) {
    int candidate = 0;
    int count = 0;
    
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    
    return candidate;
}

int main() {
    std::vector<int> nums = {2,2,3,3,3};
    int majority = majorityElement(nums);
    
    std::cout << "Majority element: " << majority << std::endl;
    
    return 0;
}