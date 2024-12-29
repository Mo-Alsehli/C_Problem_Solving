#include <bits/stdc++.h>

using namespace std;

bool binarySearch(vector<int>& v, int target){
    int left = 0, right = v.size() - 1;

    while(left <= right){
        int mid = ((right - left) / 2) - left;

        if(v[mid] == target){
            return true;
        }else if(v[mid] > target){
            right = mid - 1;
        }else {
            left = mid + 1;
        }
    }

    return false;
}

// SORTING ALGORITHMS

// Selection Sort Algorithm.
// It sorts the array by repeatedly finding the minimum element (consider ascending order) from unsorted part and putting it at the beginning.
void swap(int *a, int *b){
    // *a = (*a) ^ (*b);
    // *b = (*a) ^ (*b);
    // *a = (*a) ^ (*b);

    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
    int i, j, minIndex;
    for(i = 0; i < n-1; i++){
        minIndex = i;
        int flag = 0;
        for(j = i+1; j < n; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
                flag = 1;
            }
        }
        if(flag == 0) return;
        swap(&arr[minIndex], &arr[i]);
    }
}


/*
- Bubble Sort Algorithm:
-- It works by repeadtedly swapping the adjacent elements if they are in the wrong order.
*/

void bubleSort(int arr[], int n){
    int flag = false;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                flag = true;
            }
        }}
        if(!flag) return;
    }


int main(){
    // Binary Search Works Only With a Sorted Array.
    vector<int> v {{1, 2, 3, 4, 5}};

    cout << binarySearch(v, 3) << endl;
    cout << binarySearch(v, 10) << endl;

    int arr[] = {5, 4, 3, 2, 1};
    bubleSort(arr, sizeof(arr)/sizeof(int));
    for(auto el: arr){
        cout << el << " - ";
    }
    cout << endl;
}