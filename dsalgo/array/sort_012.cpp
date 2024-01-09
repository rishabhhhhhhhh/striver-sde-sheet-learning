#include <bits/stdc++.h> 
void sort012(int *arr, int n) {

   int zeroIndex = 0, twoIndex = n - 1;

   for(int i = 0 ; i <= twoIndex ; i++) {
      
      if(arr[i] == 0) {

         swap(arr[zeroIndex], arr[i]);
         zeroIndex++;
      
      } else if(arr[i] == 2) {

         swap(arr[i], arr[twoIndex]);
         twoIndex--;
         i--;
      
      }
   }

}