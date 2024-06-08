#include <iostream>

using namespace std;

bool binary_search(int arr[], int sizeOfArr, int target) {
    int left = 0;
    int right = sizeOfArr;

    while (left <= right) {
        int mid = left + ((right - left) / 2);
        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

bool binary_search_recursive(int arr[], int left, int right, int target) {
    int mid = left + ((right - left) / 2);
    if (left > right) {
        return false;
    }
    if (arr[mid] == target) {
        return true;
    } else if (arr[mid] > target) {
        return binary_search_recursive(arr, left, mid - 1, target);
    } else {
        return binary_search_recursive(arr, mid + 1, right, target);
    }
}

int main() {
    int arr[] = {6, 7, 8, 9, 10, 11, 14, 15, 17, 19, 22, 23, 25};

    // cout << "Is Found: " << binary_search(arr, 13, 25);
    cout << "Is Found: " << binary_search_recursive(arr, 0, 13, 25);

    return 0;
}