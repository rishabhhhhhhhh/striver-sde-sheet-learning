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
};

class MyCache {
	int maxSize;
	unordered_map< string, Node* > keyToNode;
	map< int, map< int, DLL* > > expiryToPriorityToDLL;
	
	void removeNode(Node * currentNode) {
		int priority = currentNode->priority;
		int expiryTime = currentNode->expiryTime;
		
		map< int, DLL* > priorityToDLL = expiryToPriorityToDLL[expiryTime];
		
		DLL * currentList = priorityToDLL[priority];
		
		Node * currentListHead = currentList->head;
		Node * currentListTail = currentList->tail;
		
		if(currentNode == currentListHead) {
			currentListHead = currentListHead->next;
			if(currentListHead == NULL) {
				currentListTail = NULL;
			} else {
				currentListHead->prev = NULL;
			}
		} else if(currentNode == currentListTail) {
			currentListTail = currentListTail->prev;
			currentListTail->next = NULL;
		} else {
			Node * nextNode = currentNode->next;
			Node * prevNode = currentNode->prev;
			
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
		}
		
		currentNode->next = currentNode->prev = NULL;
		currentList->head = currentListHead;
		currentList->tail = currentListTail;
		
		//if priority becomes empty
		if(currentList->head == NULL) {
			priorityToDLL.erase(priority);
		} else {
		    priorityToDLL[priority] = currentList;
		}
		
		//if expiry time becomes empty
		if(priorityToDLL.size() == 0) {
			expiryToPriorityToDLL.erase(expiryTime);
		} else {
		    expiryToPriorityToDLL[expiryTime] = priorityToDLL;
		}
	}
	
	void addNode(Node * currentNode) {
		int priority = currentNode->priority;
		int expiryTime = currentNode->expiryTime;
		
		map< int, DLL* > priorityToDLL;
		if(expiryToPriorityToDLL.find(expiryTime) == expiryToPriorityToDLL.end()) {
			expiryToPriorityToDLL[expiryTime] = priorityToDLL;
		}
		priorityToDLL = expiryToPriorityToDLL[expiryTime];
		
		DLL * currentList;
		if(priorityToDLL.find(priority) == priorityToDLL.end()) {
			currentList = new DLL();
			priorityToDLL[priority] = currentList;
		}	
		currentList = priorityToDLL[priority];
		
		Node * currentListHead = currentList->head;
		Node * currentListTail = currentList->tail;
		
		if(currentListHead == NULL) {
			currentListHead = currentListTail = currentNode;
			currentNode->next = currentNode->prev = NULL;
		} else {
			currentListTail->next = currentNode;
			currentNode->next = NULL;
			currentNode->prev = currentListTail;
			currentListTail = currentNode;
		}
		
		currentList->head = currentListHead;
		currentList->tail = currentListTail;
		
		priorityToDLL[priority] = currentList;
		expiryToPriorityToDLL[expiryTime] = priorityToDLL;
	}
	
	public:
	
	MyCache(int capacity) {
		maxSize = capacity;
	}	
	
	int getItem(string key) {
		if(keyToNode.find(key) == keyToNode.end()) {
			return -1;
		}
		Node * currentNode = keyToNode[key];
		int ans = currentNode->value;
		
		removeNode(currentNode);
		addNode(currentNode);
		
		return ans;
	}
	
	void setItem(string key, int value, int priority, int expiryTime) {
		if(keyToNode.find(key) == keyToNode.end()) {
			if(keyToNode.size() == maxSize) {
				evictItem();
			}
		} else {
			Node * currentNode = keyToNode[key];
			removeNode(currentNode);
			
			keyToNode.erase(key);
			delete currentNode;
		}
		
		if(keyToNode.size() == maxSize) {
			cout << "Still full\n";
			return;
		}
		Node * newNode = new Node(key, value, priority, expiryTime, NULL, NULL);
		addNode(newNode);
		keyToNode[key] = newNode;
	}
	
	bool evictItem() {
		if(expiryToPriorityToDLL.size() == 0) {
			cout << "Cannot evict item because of expiry item not available\n";
			return false;//no item available
		}
		map< int, map< int, DLL* > >::iterator it = expiryToPriorityToDLL.begin();
		map< int, DLL* > priorityToDLL = it->second;
		
		if(priorityToDLL.size() == 0) {
			cout << "Cannot evict item because of priority not available\n";
			return false; //no item with priority
		}
		map< int, DLL* >::iterator it1 = priorityToDLL.begin();
		DLL * currentList = it1->second;
		
		Node * currentListHead = currentList->head;
		string keyToBeRemoved = currentListHead->key;
		
		removeNode(currentListHead);
		keyToNode.erase(keyToBeRemoved);
		delete currentListHead;
		
		return true;
	}
	
	void printE() {
		
		for(map< int, map< int, DLL* > >::iterator it = expiryToPriorityToDLL.begin() ; it != expiryToPriorityToDLL.end() ; it++) {
			
			int tExpiryTime = it->first;
			map< int, DLL* > tP = it->second;
			
			cout << "Expiry time : " << tExpiryTime << endl;
			for(map< int, DLL* >::iterator it1 = tP.begin() ; it1 != tP.end() ; it1++) {
				
				int tPriority = it1->first;
				DLL * tList = it1->second;
				
				cout << "Priority : " << tPriority << endl;
				
				cout << "Printing list : ";
				Node * current = tList->head;
				if(current == NULL) {
				    cout << "EL\n";
				}
				while(current != NULL) {
					cout << (current->key) << " => " << (current->value) << " ";
					current = current->next;
				}
				cout << endl << endl;
			}
		}
	}
};

int main() {
	
	int tc;
	cin >> tc;
	
	int size;
	cin >> size;
	
	MyCache myCache(size);
	
	while(tc--) {
	    cout << "TC : " << tc << endl;
		string s;
		cin >> s;
		
		if(s == "get") {
			string key;
			cin >> key;
			
			cout << "ANS: " << myCache.getItem(key) << endl;
		} else {
			
			string key;
			cin >> key;
			
			int value, priority, expiryTime;
			cin >> value >> priority >> expiryTime;
			
			myCache.setItem(key, value, priority, expiryTime);
		}
		
		cout << "---------------\n\n";
		myCache.printE();
	}
}
