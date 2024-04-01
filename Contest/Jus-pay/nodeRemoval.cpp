#include <iostream>
#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

void DFS(int node,vector<vector<int>> &graph,vector<bool>&vis,vector<bool>&inPath,set<int>&toBlock,int des){
	vis[node] = true;
	for(int nbr:graph[node]){
		if(nbr == des){
			toBlock.insert(node);
		}else if(!vis[nbr]){
			DFS(nbr,graph,vis,inPath,toBlock,des);
			if(inPath[nbr]){
				inPath[node] = true;
			}
		}
	}
	if(inPath[node] && toBlock.find(node) == toBlock.end()){
		for(int nbr : graph[node]){
			if(!vis[nbr]){
				toBlock.insert(nbr);
			}
		}
	}

}

set<int> findNodesToRemove(int n,vector<vector<int>> &graph,int src,int des){
  vector<bool>vis(n+1,false),inPath(n+1,false);
  set<int> toBlock;
  DFS(src,graph,vis,inPath,toBlock,des);
  return toBlock;
}
int main() {
  int n;
  cin >> n;
  vector<int> memberIds(n);
  unordered_map<int, int> memberIdToIndex;
  for (int i = 0; i < n; i++) {
    cin >> memberIds[i];
    memberIdToIndex[memberIds[i]] = i;
  }
  vector<vector<int>> graph(n);
  int e;
  cin >> e;
  int from, to;
  for (int i = 0; i < e; i++) {
    cin >> from >> to;
    graph[memberIdToIndex[from]].push_back(memberIdToIndex[to]);
  }
  int src, des;
  cin >> src >> des;
  src = memberIdToIndex[src];
  des = memberIdToIndex[des];
  set<int> nodesToRemove = findNodesToRemove(n,graph,src,des);
  for(int node: nodesToRemove ){
	cout<<memberIds[node]<<" ";
  }


  return 0;
}