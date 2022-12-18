#include<bits/stdc++.h>
#include <iostream>

using namespace std;


bool isBipartite(unordered_map<int,int>& map,int i,vector<int> adj[]){
    
    queue<int> q;
    q.push(i);
    map[i]=1;
    while(q.empty()==false){
        int var=q.front();
        q.pop();
        for(auto it: adj[var]){
            if(map[it]==-1){
            
                 
                map[it]=1-map[var];
                q.push(it);
            }
            else if(map[it]==map[var]) return false;
        }
    }
    
    return true;
}




int main()
{
    
int n=6;
vector<int> adj[n+1];
vector<int> ans;
adj[1].push_back(2);
adj[2].push_back(1);
adj[2].push_back(6);
adj[2].push_back(3);
adj[3].push_back(2);
adj[3].push_back(4);
adj[4].push_back(3);
adj[4].push_back(5);
adj[5].push_back(4);
adj[6].push_back(2);
adj[5].push_back(6);
adj[6].push_back(5);
unordered_map<int,int> map;
for(int i=1;i<=6;i++) map[i]=-1;
//is graph bipartite
int flag=0;

              for(int i=1;i<=6;i++){
                  if(map[i]==-1){
                      if(isBipartite(map,i,adj)==false){
                          flag=1;
                          break;
                      }
                  }
              }

           
   if(flag==0) cout<<"graph is bipartite";
   else cout<<"graph is not bipartite";
  
}
