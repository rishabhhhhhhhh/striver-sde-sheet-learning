//
#include "bits/stdc++.h"
using namespace std;

int findAns(
	vector<int> & customer,
	vector<int> & seller,
	int n,
	int m
) {
	int i = 0, j = 0;
	int ans = INT_MIN; //maximum of all minimum distance(b/w customer and seller)
	while(i < n) {
		
		if(j < m && seller[j] <= customer[i]) {
			j++;
		} else {
			int distanceToLeftSeller = INT_MIN;
			int distanceToRightSeller = INT_MAX;
			
			if(j > 0) {
				distanceToLeftSeller = customer[i] - seller[j - 1];
			}
			if(j < m) {
				distanceToRightSeller = seller[j] - customer[i];
			}
			
			int minDistanceToAnySeller = min(distanceToLeftSeller, distanceToRightSeller);
			
			ans = max(ans, minDistanceToAnySeller);
			i++;
		}
	}
	return ans;
}

int main() {
	
	vector<int> customer;
	customer.push_back(-2);
	customer.push_back(2);
	customer.push_back(4);
	
	vector<int> seller;
	seller.push_back(-3);
	seller.push_back(0);
	
	int n = customer.size();
	int m = seller.size();
	
	cout << findAns(customer, seller, n, m);
}
