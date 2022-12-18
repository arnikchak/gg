
//shortest path in directed acyclic graph

#include <iostream>
#include<bits/stdc++.h>

using namespace std;



void toposort(stack<int>& st,int node,unordered_map<int,int>& map,vector<pair<int,int>> adj[]){
    
     map[node]=1;
     for(auto it: adj[node]){
         if(map[it.first]==0){
             toposort(st,it.first,map,adj);
         }
     }
    
    st.push(node);
    
}




int main()
{
    int n=7;
   unordered_map<int,int> map;
   stack<int> st;
   vector<pair<int,int>> adj[n+1];
   adj[0].push_back({1,2});
      adj[0].push_back({4,1});
         adj[1].push_back({2,3});
         
   adj[2].push_back({3,6});
   adj[4].push_back({2,2});
   adj[4].push_back({5,4});
   adj[5].push_back({3,1});
   
   
   
   
   
   for(int i=0;i<=n;i++){
       if(map[n]==0){
           toposort(st,i,map,adj);
       }
   }
    
    unordered_map<int,int> dist;
    for(int i=0;i<=n;i++) dist[i]=1e9;
    dist[0]=0;
    while(st.empty()==false){
        int node=st.top();
        st.pop();
        if(dist[node]!=1e9){
            for(auto it: adj[node]){
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first]=dist[node]+it.second;
                }
            }
        }
    }

    for(int i=0;i<=n;i++){
        cout<<dist[i]<<" ";
    }

}