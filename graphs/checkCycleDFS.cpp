#include<bits/stdc++.h>
#include <iostream>

using namespace std;


bool cycle(int node,unordered_map<int,int>& map,unordered_map<int,int>& dfsmap,vector<int> adj[]){
    
    map[node]=1;
    dfsmap[node]=1;
    
    for(auto it: adj[node]){
        
        
        if(map[it]==0){
            if(cycle(it,map,dfsmap,adj)==true) return true;
        }
        else if(map[it]==1 && dfsmap[it]==1){
            return true;
        }
        
    }
    
    dfsmap[node]=0;
    return false;

}

int main()
{
    
      int n=9;
      vector<int> adj[n+1];
      
      adj[1].push_back(2);
      adj[2].push_back(3);
      adj[3].push_back(4);
      adj[4].push_back(5);
      adj[6].push_back(5);
      adj[3].push_back(6);
      adj[7].push_back(2);
      //adj[9].push_back(7);
      adj[8].push_back(9);
      adj[7].push_back(8);
      
      int flag=0;
    
      unordered_map<int,int> map;
      unordered_map<int,int> dfsmap;
      for(int i=1;i<=n;i++){
          if(map[i]==0){
              if(cycle(i,map,dfsmap,adj)) {
                  flag=1;
                  break;
              }
          }
      }
    
    
    
    if(flag==1) cout<<"cycle exists";
    else cout<<"cycle does not exists";
    
    
    
    
    
    
    
    
    
    
    
}