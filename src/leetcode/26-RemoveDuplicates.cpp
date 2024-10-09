#include <vector>
#include <iostream>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    
    int i = 0;
    for(int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    
    return i + 1;
}

int main() {
    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 4, 5};
    int length = removeDuplicates(nums);
    
    std::cout << "New length: " << length << std::endl;
    std::cout << "Array after removing duplicates: ";
    for (int k = 0; k < length; ++k) {
        std::cout << nums[k] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
