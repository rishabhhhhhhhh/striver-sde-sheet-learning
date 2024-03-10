//
#include "bits/stdc++.h"
using namespace std;

void bfsToSetColor(
	string srcNode,
	unordered_map< string, vector<string> > & graph,
	unordered_map< string, int > & colorMap,
	int uniqueColor
) {
	queue<string> q;
	q.push(srcNode);
	
	while(!q.empty()) {
		string frontNode = q.front();
		q.pop();
		
		if(colorMap.find(frontNode) == colorMap.end()) {
			colorMap[frontNode] = uniqueColor;
		}
		
		for(vector<string>::iterator it = graph[frontNode].begin() ; it != graph[frontNode].end() ; it++) {
			if(colorMap.find(*it) == colorMap.end()) {
				q.push(*it);
			}
		}
	}
}

int main() {
	int inputs;
	cin >> inputs;
	
	unordered_map<string, string> graph;
	unordered_map<string, vector<string> > revGraph;
	unordered_map<string, int> nodeToChild;
	unordered_map<string, int> color;
	
	while(inputs--) {
		
		string src, dest;
		cin >> src >> dest;
		
		graph[src] = dest;
		
		if(revGraph.find(dest) == revGraph.end()) {
			vector<string> localResult(1, src);
			revGraph[dest] = localResult;
		} else {
			revGraph[dest].push_back(src);
		}
		
		if(nodeToChild.find(src) == nodeToChild.end()) {
			nodeToChild[src] = 1;
		} else {
			nodeToChild[src]++;
		}
	}
	
	int uniqueColor = 1;
	for(unordered_map<string, vector<string> >::iterator it = revGraph.begin() ; it != revGraph.end() ; it++) {
		string srcNode = it->first;
		
		if(nodeToChild.find(srcNode) == nodeToChild.end()) {
		    cout << srcNode << " sn " << endl;
			bfsToSetColor(srcNode, revGraph, color, uniqueColor);
			uniqueColor++;
		}
	}
	
	for(unordered_map<string, int>::iterator it = color.begin() ; it != color.end() ; it++) {
		cout << (it->first) << " => " << (it->second) << endl; 
	}
//	int queries;
//	cin >> queries;
//	
//	while(queries--) {
//		
//		int totalNodes;
//		cin >> totalNodes;
//		
//		bool finalAns = false;
//		while(totalNodes--) {
//			
//		}
//	}
}
