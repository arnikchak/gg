#include<bits/stdc++.h>
#include <iostream>

using namespace std;


void dfs(vector<int>& ans,int node,unordered_map<int,int>& map,vector<int> adj[]){
    
    ans.push_back(node);
    map[node]=1;
    for(int i=0;i<adj[node].size();i++){
        if(map[adj[node][i]]==0){
            dfs(ans,adj[node][i],map,adj);
        }
    }
    
    
}





int main()
{
    
int n=5;
vector<int> adj[n+1];
vector<int> ans;
adj[1].push_back(2);

adj[2].push_back(5);
adj[2].push_back(3);
adj[3].push_back(2);
adj[3].push_back(4);
adj[4].push_back(3);
adj[4].push_back(5);
adj[5].push_back(4);
adj[5].push_back(2);

//dfs traversal

                                  
                                  
                    vector<int> traversal;
                    unordered_map<int,int> map;
                    for(int i=1;i<=n;i++){
                        if(map[i]==0){
                            dfs(ans,i,map,adj);
                        }
                    }
                                  
                            
                            for(int i=0;i<ans.size();i++){
                                cout<<ans[i]<<" ";
                            }      
                                  
    
  
}
