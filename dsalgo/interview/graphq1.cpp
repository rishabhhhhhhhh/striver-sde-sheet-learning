//
#include "bits/stdc++.h"
using namespace std;

void colorNodesUsingBFS(
	string srcNode,
	unordered_map< string, vector<string> > & revGraph,
	unordered_map< string, int > & colorMap,
	int uniqueColor
) {
	queue< string > q;
	q.push(srcNode);
	
	while(!q.empty()) {
		string frontNode = q.front();
		q.pop();
		
		colorMap[frontNode] = uniqueColor;
		
		for(vector<string>::iterator it = revGraph[frontNode].begin() ; it != revGraph[frontNode].end() ; it++) {
			if(colorMap.find(*it) == colorMap.end()) {
				q.push(*it);
			}
		}
	}
}

int main() {
	
	int n; //no of connections
	cin >> n;
	
	unordered_map< string, string > graph;
	unordered_map< string, vector<string> > revGraph;
	unordered_map< string, int > colorMap;
	
	for(int i = 1 ; i <= n ; i++) {
		
		string src, dest;
		cin >> src >> dest;
		
		graph[src] = dest;
		
		if(revGraph.find(dest) == revGraph.end()) {
			vector<string> childList(1, src);
			revGraph[dest] = childList;
		} else {
			revGraph[dest].push_back(src);
		}
	}
	
	int uniqueColor = 1;
	for(unordered_map< string, string >::iterator it = graph.begin() ; it != graph.end() ; it++) {
//		if(graph.find(it->second) == graph.end()) {
 		if((graph.find(it->second) == graph.end()) && (colorMap.find(it->second) == colorMap.end())) {
		  //  cout << "sn : " << (it->second) << endl;
			colorNodesUsingBFS(it->second, revGraph, colorMap, uniqueColor);
			uniqueColor++;
		}
	}
	
// 	for(unordered_map<string, int>::iterator it = colorMap.begin() ; it != colorMap.end() ; it++) {
// 		cout << (it->first) << " => " << (it->second) << endl; 
// 	}
	
	int q;
	cin >> q;
	
	while(q--) {
		int m;
		cin >> m;
		
		bool cycleFound = false, intersectionFound = false;
		set<int> strSet;
		
		for(int i=1;i<=m;i++) {
			string str;
			cin >> str;
			
			int colorOfNode;
			if(colorMap.find(str) == colorMap.end()) {
				colorOfNode = -1;
			} else {
				colorOfNode = colorMap[str];
			}
			
			if(colorOfNode == -1) {
				cycleFound = true;
			} else {
				if(strSet.find(colorOfNode) == strSet.end()) {
					strSet.insert(colorOfNode);		
				} else {
					intersectionFound = true;
				}
			}
		}
		
		if(cycleFound) {
			cout << "Cycle Found\n";
		} else if(intersectionFound) {
			cout << "Intersection Found\n";
		} else {
			cout << "Independent\n";
		}
	}
}
/*
15
h a
g a
a b
e b
f b
b c
c d
i j
j k
l m
m n
n m
o p
p q
r q
8
5 a b c m q
4 a i m o
3 e l q
2 j h
1 a
3 a c h
3 g e k
2 q r
*/
