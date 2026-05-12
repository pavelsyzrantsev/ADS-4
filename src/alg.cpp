// Copyright 2021 NNTU-CS
#include <cstdint>
#include "alg.h"

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
        int temp = arr[j];
        while (j + 1 < len && arr[j + 1] == temp) {
          ++j;
        }
      }
    }
    int temp = arr[i];
    while (i + 1 < len && arr[i + 1] == temp) {
      ++i;
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      ++count;
      int left_val = arr[left];
      int right_val = arr[right];
      while (left + 1 < len && arr[left + 1] == left_val) {
        ++left;
      }
      while (right - 1 >= 0 && arr[right - 1] == right_val) {
        --right;
      }
      ++left;
      --right;
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}

int binarySearch(int *arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    if (target < arr[i]) {
      break;
    }
    int index = binarySearch(arr, i + 1, len - 1, target);
    if (index != -1) {
      ++count;
      int temp = arr[index];
      while (index + 1 < len && arr[index + 1] == temp) {
        ++index;
      }
      i = index;
    }
    int temp = arr[i];
    while (i + 1 < len && arr[i + 1] == temp) {
      ++i;
    }
  }
  return count;
}
