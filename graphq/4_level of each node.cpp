
#include<bits/stdc++.h>
using namespace std;


void marker(int src,unordered_map<int,int>& map,unordered_map<int,int>& level,vector<int> adj[]){
    
    
    map[src]=1;
    queue<int> q;
    q.push(src);
    level[src]=0;
    while(q.empty()==false){
        int x=q.front();
        q.pop();
        for(auto it: adj[x]){
            if(map[it]==0){
                q.push(it);
                level[it]=level[x]+1;
                map[it]=1;
            }
        }
    }
    
    
}






int main()
{
    
    int n=7;
    vector<int> adj[n+1];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[1].push_back(5);
    adj[2].push_back(6);
    adj[6].push_back(7);
    
    unordered_map<int,int> map;
    unordered_map<int,int> level;
    marker(0,map,level,adj);
    for(int i=0;i<=7;i++) cout<<level[i]<<" ";
    
    
}
