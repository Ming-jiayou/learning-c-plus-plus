#include <iostream>
#include <string>

int strStr(const std::string& haystack, const std::string& needle) {
    // 使用 find 方法查找 needle 在 haystack 中的位置
    size_t pos = haystack.find(needle);
    
    // 如果找到了，返回位置；否则返回 -1
    if (pos != std::string::npos) {
        return static_cast<int>(pos);
    } else {
        return -1;
    }
}

int main() {
    std::string haystack = "hello world";
    std::string needle = "world";
    
    int result = strStr(haystack, needle);
    
    if (result != -1) {
        std::cout << "Found at index: " << result << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    
    return 0;
}