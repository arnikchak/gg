#include<bits/stdc++.h>
#include <iostream>

using namespace std;


void topo(stack<int>& st,int node,unordered_map<int,int>& map,vector<int> adj[]){
    
    map[node]=1;
    for(auto it:adj[node]){
        if(map[it]==0){
            topo(st,it,map,adj);
        }
    }
    st.push(node);
}

int main()
{
    
      int n=5;
      vector<int> adj[n+1];
      adj[2].push_back(3);
      adj[3].push_back(1);
      adj[4].push_back(0);
      adj[4].push_back(1);
      adj[5].push_back(0);
      adj[5].push_back(2);
      
      unordered_map<int,int> indegree;
      for(int i=0;i<=n;i++){
          for(auto itr: adj[i]) indegree[itr]++;
      }
      queue<int> q;
      
      for(int i=0;i<=n;i++){
          if(indegree[i]==0) q.push(i);
      }
      
      vector<int> topo;
      while(q.empty()==false){
          int node=q.front();
          topo.push_back(node);
          q.pop();
          for(auto itr: adj[node]){
              indegree[itr]--;
              if(indegree[itr]==0){
                  q.push(itr);
              }
          }
      }
      for(int i=0;i<topo.size();i++){
          cout<<topo[i]<<" ";
      }
    
}