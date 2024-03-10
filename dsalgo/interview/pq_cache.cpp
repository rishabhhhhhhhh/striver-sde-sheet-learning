//
#include "bits/stdc++.h"
using namespace std;

class Node {
	
	public:
	
	string key;
	int value, priority, expiryTime;
	
	Node *prev, *next;
	
	Node(string k1, int v1, int p1, int e1, Node *prev1, Node *next1) {
		key = k1;
		value = v1;
		priority = p1;
		expiryTime = e1;
		prev = prev1;
		next = next1;
	}
};

class PQComp {
	public:
	
	bool operator()(Node* below, Node* above) {
		if(below->expiryTime == above->expiryTime) {
			return (above->priority) <= (below->priority);
		}
		return (above->expiryTime) < (below->expiryTime);
	}
};

class MyCache {
	
	int maxSize;
	
};
