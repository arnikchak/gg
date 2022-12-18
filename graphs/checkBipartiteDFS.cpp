#include<bits/stdc++.h>
#include <iostream>

using namespace std;



bool isbipartite(int node,unordered_map<int,int>& map,vector<int> adj[]){
    if(map[node]==-1) map[node]=1;
    //map[node]=1;
    for(auto it: adj[node]){
        
        if(map[it]==-1){
            map[it]=1-map[node];
            if(isbipartite(it,map,adj)==false) return false;
        
        }
        else if(map[it]==map[node]) return false;
        
        
    }
    
    
    return true;
    
    
}













int main()
{
    
    int n=7;
    vector<int> adj[n+1];
    
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(5);
    adj[4].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[5].push_back(2);
    adj[5].push_back(6);
    adj[6].push_back(5);
    adj[6].push_back(7);
    adj[7].push_back(6);
    //adj[6].push_back(2);
    //adj[6].push_back(5);
    adj[3].push_back(2);
    adj[3].push_back(4);
    
    
      // printing the graph 
      for(int i=1;i<=n;i++){
          cout<<i<<" -> ";
          for(int j=0;j<adj[i].size();j++){
              cout<<adj[i][j]<<" ";
              
          }
          cout<<endl;
      }
    
       int flag=0;
       
       unordered_map<int,int> map;
       for(int i=1;i<=n;i++) map[i]=-1; 
       for(int i=1;i<=n;i++){
           if(map[i]==-1){
               if(isbipartite(i,map,adj)==false){
                   flag=1;
                   break;
               }
           }
       }
       if(flag==1) cout<<"graph is not bipartite";
       else cout<<"graph is bipartite";
    
    
    
}