//
#include "bits/stdc++.h"
using namespace std;

void print(vector<string> & arr) {
	cout << "HERE\n";	
}

int main() {
	int c;
	cin >> c;
	
	try {
		if(c & 1) {
			throw runtime_error("Error occured");
		}else {
			cout << c << endl;
		}
	} catch (exception e) {
		cerr << e.what();
	}
}
