//https://www.codingninjas.com/studio/problems/1112602?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=PROBLEM
int findDuplicate(vector<int> &arr, int n){
    for(int i = 0 ; i < n ;i++) {
        int element = abs(arr[i]);
        if(arr[element] < 0)
            return element;
        arr[element] = -1 * arr[element];
    }
}
