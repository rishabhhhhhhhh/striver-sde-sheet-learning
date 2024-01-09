#include "bits/stdc++.h"
void reverse(vector<int> & arr, int left, int right) {

    while(left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

vector<int> nextGreaterPermutation(vector<int> &A) {
    
    int n = A.size();

    int nonIncSeqStartIndex = n - 1;

    while(nonIncSeqStartIndex > 0 && A[nonIncSeqStartIndex - 1] >= A[nonIncSeqStartIndex]) {
        nonIncSeqStartIndex--;
    } 

    if(nonIncSeqStartIndex == 0) {

        reverse(A, 0, n - 1);

        return A;
    }

    int nextGreaterElementIndex = nonIncSeqStartIndex;

    for(int i = nonIncSeqStartIndex ; i < n ; i++) {

        if(A[i] > A[nonIncSeqStartIndex - 1]) {

            nextGreaterElementIndex = i;
        } else {

            break;
        }
    } 

    swap(A[nonIncSeqStartIndex - 1], A[nextGreaterElementIndex]);
    reverse(A, nonIncSeqStartIndex, n - 1);

    return A;

}