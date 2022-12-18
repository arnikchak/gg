#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    
int n=5;
int m=7;
vector<int> adj[n+1];
unordered_map<int,int> map;
adj[1].push_back(2);
adj[2].push_back(1);
adj[3].push_back(2);
adj[2].push_back(3);
adj[5].push_back(3);
adj[3].push_back(5);
adj[2].push_back(4);
adj[4].push_back(2);
adj[1].push_back(5);
adj[5].push_back(1);
adj[1].push_back(3);
adj[3].push_back(1);
adj[3].push_back(4);
adj[4].push_back(3);
vector<int> ans;
    
    for(int i=1;i<=n;i++){
        if(map[i]==0){
            queue<int> q;
            q.push(i);
            map[i]=1;
            while(q.empty()==false){
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto itr: adj[node]){
                    if(map[itr]==0){
                        q.push(itr);
                        map[itr]=1;
                    }
                }
            }
        }
    }
    
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    
    
  
}
