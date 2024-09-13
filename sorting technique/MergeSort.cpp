#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    // Merge the two halves into temp
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements from the left half, if any
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from the right half, if any
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the sorted elements back into the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = (low + high) / 2;

    // Recursively sort the two halves
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // Merge the sorted halves
    merge(arr, low, mid, high);
}

int main() {
    int arr[5] = {10, 8, 45, 52, 3};

    mergeSort(arr, 0, 4); // Corrected last index from 5 to 4

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
