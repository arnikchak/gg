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
      
      int flag=0;
    
      unordered_map<int,int> map;
      stack<int> st;
      for(int i=0;i<=n;i++){
          if(map[i]==0){
              topo(st,i,map,adj);
          }
      }
    
    vector<int> ans;
    while(st.empty()==false){
        ans.push_back(st.top());
        st.pop();
    }
    
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
    
}