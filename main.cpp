
#include <vector>
#include <iostream>

using namespace std;

int partition(int* numbers, int low, int high){
    //choose rightmost ele as pivot
    int pivot = numbers[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (numbers[j] <= pivot){
            i = i + 1;
            //swap
            int temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
        }
    }

    //place pivot in correct position
    int temp = numbers[i+1];
    numbers[i+1] = numbers[high];
    numbers[high] = temp;

    return i+1;
}

void quicksort(int* numbers, int low, int high){
    if (low < high){
        //partition array and get pivot
        int pivotIndex = partition(numbers, low, high);

        //sort left subarray
        quicksort(numbers, low, pivotIndex - 1);

        //sort right subarray
        quicksort(numbers, pivotIndex + 1, high);
    }
}

void sort(int* numbers, int size){
    quicksort(numbers, 0, size - 1);
}

int sortAndFindMedian(int* numbers, int size){
    sort(numbers, size);
    int n = size;
    if (n % 2 == 0){
        return (numbers[n/2 - 1] + numbers[n/2]) / 2;
    }
    else{
        return numbers[n/2];
    }
}

void testcase(int* nums, int size){
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    int median = sortAndFindMedian(nums, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) cout << nums[i] << " ";
    cout << endl;
    cout << "Median: " << median << endl;
}

int main(){
    //test Case 1
    int nums1[] = {5, 6, 8, 3, 211, 61};
    int size1 = 6;
    testcase(nums1, size1);

    //test Case 2
    int nums2[] = {9, 10, 12, 13, 13, 13, 15, 15, 16, 16, 18, 22, 23, 24, 24, 25};
    int size2 = 16;
    testcase(nums2, size2);

    int nums3[] = {10, 2, 38, 23, 38, 23, 21};
    int size3 = 7;
    testcase(nums3, size3);

    return 0;
}