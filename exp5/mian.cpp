#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <functional>  // 引入 std::function

// 起泡排序（Bubble Sort）
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

// 插入排序（Insertion Sort）
void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 选择排序（Selection Sort）
void selectionSort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

// 归并排序（Merge Sort）
void merge(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge(arr, left, mid);
        merge(arr, mid + 1, right);

        // 合并两个已排序的子数组
        std::vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        for (i = 0; i < temp.size(); i++) {
            arr[left + i] = temp[i];
        }
    }
}

// 快速排序（Quick Sort）
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 堆排序（Heap Sort）
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 1; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 生成随机序列
std::vector<int> generateRandomSequence(int size) {
    std::vector<int> seq(size);
    for (int i = 0; i < size; i++) {
        seq[i] = rand() % 1000;  // 生成 0 到 999 之间的随机数
    }
    return seq;
}

// 性能测试
void testSortPerformance(std::function<void(std::vector<int>&)> sortFunction, const std::string& algorithmName, std::vector<int> seq) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(seq);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << algorithmName << " took " << duration.count() << " seconds.\n";
}

int main() {
    int n = 1000;
    std::vector<int> ascending = generateRandomSequence(n);
    std::vector<int> descending = ascending;
    std::reverse(descending.begin(), descending.end());
    std::vector<int> random = generateRandomSequence(n);

    std::cout << "Testing Sorting Algorithms on Ascending Sequence:\n";
    testSortPerformance(bubbleSort, "Bubble Sort", ascending);
    testSortPerformance(insertionSort, "Insertion Sort", ascending);
    testSortPerformance(selectionSort, "Selection Sort", ascending);
    testSortPerformance([](std::vector<int>& arr) { merge(arr, 0, arr.size() - 1); }, "Merge Sort", ascending);
    testSortPerformance([](std::vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }, "Quick Sort", ascending);
    testSortPerformance(heapSort, "Heap Sort", ascending);

    std::cout << "\nTesting Sorting Algorithms on Descending Sequence:\n";
    testSortPerformance(bubbleSort, "Bubble Sort", descending);
    testSortPerformance(insertionSort, "Insertion Sort", descending);
    testSortPerformance(selectionSort, "Selection Sort", descending);
    testSortPerformance([](std::vector<int>& arr) { merge(arr, 0, arr.size() - 1); }, "Merge Sort", descending);
    testSortPerformance([](std::vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }, "Quick Sort", descending);
    testSortPerformance(heapSort, "Heap Sort", descending);

    std::cout << "\nTesting Sorting Algorithms on Random Sequence:\n";
    testSortPerformance(bubbleSort, "Bubble Sort", random);
    testSortPerformance(insertionSort, "Insertion Sort", random);
    testSortPerformance(selectionSort, "Selection Sort", random);
    testSortPerformance([](std::vector<int>& arr) { merge(arr, 0, arr.size() - 1); }, "Merge Sort", random);
    testSortPerformance([](std::vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }, "Quick Sort", random);
    testSortPerformance(heapSort, "Heap Sort", random);

    return 0;
}
