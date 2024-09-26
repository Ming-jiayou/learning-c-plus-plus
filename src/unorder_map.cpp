#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> um = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3}
    };

    // 插入元素
    um["date"] = 4;

    // 遍历映射
    for (const auto& pair : um) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 查找元素
    if (um.find("banana") != um.end()) {
        std::cout << "Found banana" << std::endl;
    }

    return 0;
}