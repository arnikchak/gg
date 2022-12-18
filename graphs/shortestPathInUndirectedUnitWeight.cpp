#include<bits/stdc++.h>
#include <iostream>

using namespace std;




int
main ()
{

  int n = 8;
  vector < int >adj[n + 1];
  adj[0].push_back(1);
  adj[0].push_back(3);
  adj[3].push_back(0);
  adj[3].push_back(1);
  adj[3].push_back(4);
  adj[1].push_back(0);
  adj[1].push_back(3);
  adj[1].push_back(2);
  adj[2].push_back(1);
  adj[2].push_back(6);
  adj[6].push_back(2);
  adj[6].push_back(7);
  adj[6].push_back(5);
  adj[6].push_back(8);
  adj[4].push_back(3);
  adj[4].push_back(5);
  adj[5].push_back(4);
  adj[5].push_back(6);
  adj[7].push_back(8);
  adj[8].push_back(7);
  adj[7].push_back(6);
  adj[8].push_back(6);


  unordered_map<int,int> map;
  for (int i = 0; i <= 8; i++) map[i] = INT_MAX;
  queue < int >q;
  int src = 0;
  map[src] = 0;
  q.push (src);
  
  
  
  while(q.empty()==false){
      int node=q.front();
      q.pop();
      for(auto it: adj[node]){
          if(map[node]+1<map[it]){
              map[it]=map[node]+1;
              q.push(it);
          }
      }
  }
    
  for(int i=0;i<=8;i++) cout<<map[i]<<" ";    
   
}
