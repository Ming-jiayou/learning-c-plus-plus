#include <iostream>
#include <windows.h>
using namespace std;

// 冒泡排序函数
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        // 标记是否发生了交换
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // 交换元素
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        // 如果没有发生交换，说明列表已经有序
        if (!swapped) {
            break;
        }
    }
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
     // 设置控制台代码页为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "排序前的数组: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "排序后的数组: ";
    printArray(arr, n);

    return 0;
}