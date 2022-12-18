Minimum initial vertices to traverse whole matrix with given conditions



//shortest path in directed acyclic graph

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(int n,int m,vector<vector<bool>> vis,vector<vector<int>> matrix,int N,int M){
    
    
    vis[n][m]=true;
    if(n+1<N){
        if(vis[n+1][m]==false && matrix[n+1][m]<=matrix[n][m]){
            dfs(n+1,m,vis,matrix,N,M);
        }
    }
    if(m+1<M){
        if(vis[n][m+1]==false && matrix[n][m+1]<=matrix[n][m]){
            dfs(n,m+1,vis,matrix,N,M);
        }
    }
    if(m-1>=0){
        if(vis[n][m-1]==false && matrix[n][m-1]<=matrix[n][m]){
            dfs(n,m-1,vis,matrix,N,M);
        }
    }
    if(n-1>=0){
        if(vis[n-1][m]==false && matrix[n-1][m]<=matrix[n][m]){
            dfs(n-1,m,vis,matrix,N,M);
        }
    }
    
    
    
    
}




int main()
{
    int n=4;
    vector<vector<int>> matrix={{3,3},{1,1}};
    vector<pair<int,pair<int,int>>> vect;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            vect.push_back({matrix[i][j],{i,j}});
        }
    }
    sort(vect.begin(),vect.end());
    vector<vector<bool>> vis;
    for(int i=0;i<2;i++){
        vis.push_back({false,false,false});
    }
    //memse(vis,false,sizeof vis);
    for(int i=vect.size()-1;i>=0;i--){
        if(vis[vect[i].second.first][vect[i].second.second]==false){
            cout<<vect[i].second.first<<" "<<vect[i].second.second<<endl;
            dfs(vect[i].second.first,vect[i].second.second,vis,matrix,2,2);
        }
    }



}