
//shortest path in directed acyclic graph

#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int counter(vector<int> adj[],unordered_map<int,int>& map,int node,int& count){
   
    if(map[node]==0){
        count++;
        map[node]=1;
        for(auto it: adj[node]){
            counter(adj,map,it,count);
        }
    }
    
}


int main()
{
    int n=5;
    vector<int> adj[n+1];
    adj[0].push_back(5);
    adj[0].push_back(3);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[3].push_back(0);
    adj[3].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(5);
    adj[5].push_back(0);
    adj[5].push_back(2);
    unordered_map<int,int> map;
    int count=0;
    counter(adj,map,0,count);
    cout<<count;


}