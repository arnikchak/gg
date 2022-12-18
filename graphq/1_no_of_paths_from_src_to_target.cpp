
//shortest path in directed acyclic graph

#include <iostream>
#include<bits/stdc++.h>

using namespace std;



void finder(int src,int dst,vector<int> adj[],unordered_map<int,int>& map,int& count){
    
    
    map[src]=1;
    if(src==dst){
        count++;
    }
    else{
        
            for(auto it: adj[src]){
                if(map[it]==0){
                finder(it,dst,adj,map,count);
                }
            }
    
    }
    
    map[src]=0;
    
}




int counter(int src,int dst,vector<int> adj[]){
    
    int count=0;
    unordered_map<int,int> map;
    finder(src,dst,adj,map,count);
    return count;
    
}




int main()
{
    int n=4;
    vector<int> adj[n+1];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(4);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(4);
    adj[3].push_back(2);

    
    
    
    cout<<counter(0,4,adj);

}




//LC ARCHIVE 797,1557
//level of each one  in a generic tree