#include <bits/stdc++.h>

void merge(
    long long * arr, 
    int leftStart, 
    int leftEnd, 
    int rightEnd, 
    long long & ans
) {
    int start = leftStart;
    int rightStart = leftEnd + 1;

    long long tempAns = 0;
    int len = rightEnd - leftStart + 1;
    // cout  << "len=" << len << endl;
    // cout << "left " << leftStart << " " << leftEd

    vector<long long> tempArr(len);
    int tempArrC = 0;


    while(leftStart <= leftEnd && rightStart <= rightEnd) {

        if(arr[leftStart] <= arr[rightStart]) {
            tempArr[tempArrC++] = arr[leftStart++];    
        } else {
            tempAns = tempAns + (leftEnd - leftStart + 1);
            tempArr[tempArrC++] = arr[rightStart++];
        }
    }

    while(leftStart <= leftEnd) {

        tempArr[tempArrC++] = arr[leftStart++];
    }

    while(rightStart <= rightEnd) {

        tempArr[tempArrC++] = arr[rightStart++];
    }

    for(int i = start, j = 0 ; j < tempArrC ; j++, i++) {

        arr[i] = tempArr[j];
    }

    ans = ans + tempAns;
}

void mSort(long long *arr, int left, int right, long long & ans) {

    if(right <= left) {
        return;
    }

    int mid = (left + right) >> 1;

    mSort(arr, left, mid, ans);
    mSort(arr, mid+1, right, ans);
    
    merge(arr, left, mid, right, ans);
}

void print(long long * arr, int n) {

    cout << "Print Elements\n";
    for(int i = 0 ; i < n ; i++) {

        cout << arr[i] << " ";
    }
    cout << endl;
}

long long getInversions(long long *arr, int n){
    
    long long ans = 0;
    
    int left = 0, right = n - 1;

    mSort(arr, left, right, ans);

    // print(arr, n);
    
    return ans; 
}