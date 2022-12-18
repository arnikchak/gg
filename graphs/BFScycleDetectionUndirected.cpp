#include<bits/stdc++.h>
#include <iostream>

using namespace std;


bool cycle(int node,int parent,unordered_map<int,int>& map,vector<int> adj[]){
    
    queue<pair<int,int>> q;
    map[node]=1;
    q.push({node,parent});
    while(q.empty()==false){
        
        int curr=q.front().first;
        int par=q.front().second;
        q.pop();
        for(int i=0;i<adj[curr].size();i++){
            
            if(map[adj[curr][i]]==0){
                map[adj[curr][i]]=1;
                q.push({adj[curr][i],curr});
            }
            else if(map[adj[curr][i]]==1 && par!=adj[curr][i]){
                return true;
            }
            
            
        }
        
        
    }
    
    return false;
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

//cycle detection using bfs traversal

// (curr,parent,map,adj)
int flag=0;
unordered_map<int,int> map;
         for(int i=1;i<=n;i++){
             if(map[i]==0){
                 if(cycle(i,-1,map,adj)==true) flag=1;
             }
         }
             
           if(flag==0) cout<<"cycle not found";
           if(flag==1) cout<<"cycle found";
  
}
