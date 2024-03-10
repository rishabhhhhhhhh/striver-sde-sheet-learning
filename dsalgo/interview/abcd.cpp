//
#include "bits/stdc++.h"
using namespace std;

vector<int> func(int n){
	return ({1, 2, 3});
}

void print(vector<int> & arr) {
	
	cout << "ARRAY\n";
	for(vector<int>::iterator it = arr.begin() ; it != arr.end() ; it++) {
		cout << (*it) << " ";
	}	
}

int main() {
	int tc;
	cin >> tc;
	
	while(tc--) {
		int n;
		cin >> n;
		
		vector<int> ans = func(n);
		print(ans);
	}
}
