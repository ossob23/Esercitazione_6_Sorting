#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

namespace SortLibrary {

    // Bubble Sort
    template <typename T>
    void BubbleSort(std::vector<T>& arr) {
        size_t n = arr.size();
        for (size_t i = 0; i < n - 1; i++) {
            for (size_t j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1])
                    std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    // Heapify helper for Heap Sort
    template <typename T>
    void Heapify(std::vector<T>& arr, int n, int i) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            Heapify(arr, n, largest);
        }
    }

    // Heap Sort
    template <typename T>
    void HeapSort(std::vector<T>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            Heapify(arr, n, i);
        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            Heapify(arr, i, 0);
        }
    }

    // Selection Sort
    template <typename T>
    void SelectionSort(std::vector<T>& vec) {
        for (size_t i = 0; i < vec.size(); ++i) {
            size_t min_idx = i;
            for (size_t j = i + 1; j < vec.size(); ++j) {
                if (vec[j] < vec[min_idx]) {
                    min_idx = j;
                }
            }
            std::swap(vec[i], vec[min_idx]);
        }
    }

    // Insertion Sort
    template <typename T>
    void InsertionSort(std::vector<T>& vec) {
        for (size_t i = 1; i < vec.size(); ++i) {
            T key = vec[i];
            size_t j = i;
            while (j > 0 && vec[j - 1] > key) {
                vec[j] = vec[j - 1];
                --j;
            }
            vec[j] = key;
        }
    }

}



