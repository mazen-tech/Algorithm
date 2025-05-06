#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <random>

// Generate random integers
std::vector<int> generateRandomVector(int size) {
    std::vector<int> data(size);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 100000);
    for (int &x : data)
        x = dist(rng);
    return data;
}

// Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; ++i)
        for (int j = 0; j < n-i-1; ++j)
            if (arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
}

// Bucket Sort
void bucketSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int bucketCount = 10;
    std::vector<std::vector<int>> buckets(bucketCount);

    for (int num : arr)
        buckets[(bucketCount * num) / (maxVal + 1)].push_back(num);

    arr.clear();
    for (auto &bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}

// Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
        if (arr[j] < pivot)
            std::swap(arr[++i], arr[j]);
    std::swap(arr[i+1], arr[high]);
    quickSort(arr, low, i);
    quickSort(arr, i + 2, high);
}

// Merge Sort
void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> leftArr(arr.begin()+left, arr.begin()+mid+1);
    std::vector<int> rightArr(arr.begin()+mid+1, arr.begin()+right+1);
    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size())
        arr[k++] = (leftArr[i] <= rightArr[j]) ? leftArr[i++] : rightArr[j++];
    while (i < leftArr.size()) arr[k++] = leftArr[i++];
    while (j < rightArr.size()) arr[k++] = rightArr[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

// Heap Sort
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Measure time utility
template<typename Func>
long long measureTime(Func sortFunc, std::vector<int> data) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(data);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// Wrappers to use with measureTime
long long runBubbleSort(std::vector<int> arr) { bubbleSort(arr); return 0; }
long long runBucketSort(std::vector<int> arr) { bucketSort(arr); return 0; }
long long runQuickSort(std::vector<int> arr) { quickSort(arr, 0, arr.size() - 1); return 0; }
long long runMergeSort(std::vector<int> arr) { mergeSort(arr, 0, arr.size() - 1); return 0; }
long long runHeapSort(std::vector<int> arr)  { heapSort(arr); return 0; }

int main() {
    int size;
    std::cout << "Enter number of elements to sort: ";
    std::cin >> size;

    std::vector<int> original = generateRandomVector(size);

    std::cout << "\nSorting performance in microseconds:\n";

    auto bubble_time = measureTime(bubbleSort, original);
    std::cout << "Bubble Sort: " << bubble_time << " µs\n";

    auto bucket_time = measureTime(bucketSort, original);
    std::cout << "Bucket Sort: " << bucket_time << " µs\n";

    auto quick_time = measureTime([](std::vector<int> data) {
        quickSort(data, 0, data.size() - 1);
    }, original);
    std::cout << "Quick Sort: " << quick_time << " µs\n";

    auto merge_time = measureTime([](std::vector<int> data) {
        mergeSort(data, 0, data.size() - 1);
    }, original);
    std::cout << "Merge Sort: " << merge_time << " µs\n";

    auto heap_time = measureTime(heapSort, original);
    std::cout << "Heap Sort: " << heap_time << " µs\n";

    return 0;
}
