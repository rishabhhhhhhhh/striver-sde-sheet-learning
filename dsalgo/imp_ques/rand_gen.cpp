#include <bits/stdc++.h>
using namespace std;
int main() {
    int tc;
    cin >> tc;
    
    while(tc--) {
        int left, right;
        cin >> left >> right;//gen rand no in [left, right]
        
        srand(time(NULL));
        
        int randomNo = left + rand()%(right - left + 1);
        
        cout << randomNo << endl;
    }
}
