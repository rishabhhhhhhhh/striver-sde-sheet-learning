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

class DLL {
	public:
	
	Node *head, *tail;
	
	DLL() {
		head = tail = NULL;
	}
	
	DLL(Node *h1, Node *t1) {
		head = h1;
		tail = t1;
	}
	
	void addNodeAtEnd(Node * currentNode) {
		if(head == NULL) {
			head = tail = currentNode;
			currentNode->next = currentNode->prev = NULL;
		} else {
			tail->next = currentNode;
			currentNode->next = NULL;
			currentNode->prev = tail;
			tail = currentNode;
		}
	}
	
	void removeNode(Node * currentNode) {
		if(head == currentNode) {
			head = head->next;
			if(head == NULL) {
				tail = NULL;
			} else {
				head->prev = NULL;
			}
		} else if(tail == currentNode) {
			tail = tail->prev;
			tail->next = NULL;
		} else {
			Node * nextNode = currentNode->next;
			Node * prevNode = currentNode->prev;
			
			nextNode->prev = prevNode;
			prevNode->next = nextNode;
		}
		currentNode->next = currentNode->prev = NULL;
	}
};

class PCache {
	int maxSize;
	map< int , map< int, DLL* > > expiryTimeToPriorityToDLL;
	unordered_map< int, Node* > keyToNode;
	
	void reorderNode(Node * currentNode) {
		//remove node from current list and append it to end
		int currentExpiryTime = currentNode->expiryTime;
		int currentPriority = currentNode->priority;
		
		map< int, DLL* > priorityToDLL = expiryTimeToPriorityToDLL[currentExpiryTime];
		DLL * currentList = priorityToDLL[currentPriority];
		currentList->removeNode(currentNode);
		currentList->addNodeAtEnd(currentNode);
		
		//update priority
		priorityToDLL[currentPriority] = currentList;
		
		//update expiry time
		expiryTimeToPriorityToDLL[currentExpiryTime] = priorityToDLL;
	}
	
	public:
	
	PCache(int capacity) {
		maxSize = capacity;
	} 
	
	int getItem(string key) {
		if(keyToNode.find(key) == keyToNode.end()) {
			return -1;
		}
		Node * currentNode = keyToNode[key];
		int ans = currentNode->value;
		
		reorderNode(currentNode);
		
		return ans;
	}
	
	void setItem(string key, int value, int priority, int expiryTime) {
		
	}
	
	void evictItem() {
		map< int, map< int, DLL* > >::iterator it = expiryTimeToPriorityToDLL.begin();
		
		int lowestExpiryTime = it->first;
	}
	
	void printMap() {
		cout << "PRINT MAP\n";
		for(map< int, map< int, DLL* > >::iterator it = expiryTimeToPriorityToDLL.begin() ; it != expiryTimeToPriorityToDLL.end() ; it++) {
			int tExpiryTime = it->first;
			map< int, DLL* > priorityToDLL = it->second;
			
			cout << "expiry time : " << tExpiryTime << endl;
			for(map< int, DLL* >::iterator it1 = priorityToDLL.begin() ; it1 != priorityToDLL.end() ; it1++) {
				
				int tPriority = it1->first;
				DLL * tList = it1->second;
				
				cout << "priority : " << tPriority << endl;
				Node * tCurrent = tList->head;
				while(tCurrent != NULL) {
					cout << (tCurrent->key) << " => " << (tCurrent->value) << endl;
					tCurrent = tCurrent->next;
				}
			}
		}
	}
};

int main() {
	
}
