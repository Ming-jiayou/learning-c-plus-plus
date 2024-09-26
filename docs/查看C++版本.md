# 查看C++的版本

```c++
#include <iostream>

int main() {
    std::cout << "C++ Standard: " << __cplusplus << std::endl;
    return 0;
}
```

输出结果：

![image-20240926181126365](https://mingupupup.oss-cn-wuhan-lr.aliyuncs.com/imgs/image-20240926181126365.png)

- `199711L` 表示C++98/C++03
- `201103L` 表示C++11
- `201402L` 表示C++14
- `201703L` 表示C++17
- `202002L` 表示C++20

因此我使用的C++版本是C++17。

查看编译器的版本，打开CMD，输入`g++ --version`，结果如下所示：

![image-20240926181349252](https://mingupupup.oss-cn-wuhan-lr.aliyuncs.com/imgs/image-20240926181349252.png)

但是编译器的版本并不是与C++版本对应的。