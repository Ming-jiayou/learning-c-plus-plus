#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> m = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3}
    };

    // 插入元素
    m["date"] = 4;

    // 遍历映射
    for (const auto& pair : m) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 查找元素
    if (m.find("banana") != m.end()) {
        std::cout << "Found banana" << std::endl;
    }

    return 0;
}