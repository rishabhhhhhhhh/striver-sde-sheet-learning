#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int tc;
    cin >> tc;
    tc++; //getline taking 1 line as other tc
    
    while(tc--) {
        string str;
        getline(cin, str);
        int len = str.length();
        cout << "String: " << str <<  "Len :" << len << endl;
    }
}
/*
5
Hello world i am here   j
  j h   s kk    
L sjdj dfj   . dd   .    
A . A . 
H
*/