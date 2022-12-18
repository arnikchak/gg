#include<bits/stdc++.h>
#include <iostream>

using namespace std;


bool cycle(int node,int parent,unordered_map<int,int>& map,vector<int> adj[]){
    
    
    map[node]=1;
    for(int i=0;i<adj[node].size();i++){
        
        if(map[adj[node][i]]==0){
            if(cycle(adj[node][i],node,map,adj)) return true;
        }
        else if(map[adj[node][i]]==1 && adj[node][i]!=parent) return true;
        
        }
    
    return false;
    
}






int main()
{
    
int n=5;
vector<int> adj[n+1];
vector<int> ans;
adj[1].push_back(2);

//adj[2].push_back(5);
adj[2].push_back(3);
adj[3].push_back(2);
adj[3].push_back(4);
adj[4].push_back(3);
adj[4].push_back(5);
adj[5].push_back(4);
//adj[5].push_back(2);

//dfs traversal
int flag=0;
                                  
                                  
                    vector<int> traversal;
                    unordered_map<int,int> map;
                    for(int i=1;i<=n;i++){
                        if(map[i]==0){
                            if(cycle(i,-1,map,adj)){
                                flag=1;
                            }
                        }
                    }
                                  
                if(flag==0) cout<<"not found";
                else if(flag==1)cout<<"found cycle is there";
                        
  
}
