#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    
int n=5;
int m=7;
vector<int> adj[n+1];

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

    for(int i=1;i<n+1;i++){
        cout<<i<<"->";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
  
}
