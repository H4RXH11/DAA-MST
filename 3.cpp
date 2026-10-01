//HARSHIT SAH 25/DA/032

#include<bits/stdc++.h>
using namespace std;

int main(){
    cout << "Enter number of vertex & edges : ";
    int n, m; cin >> n >> m;

    cout << "Enter Graph details (u,v,w): ";

    vector<vector<pair<int,int>>> adj(n);
    for(int i=0; i<m; i++){
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }

    int mst_weight = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> vis(n,0);

    for(auto [w,v] : adj[0]){
        pq.push({w,v});
    }
    vis[0] = 1;
    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        if(!vis[temp.second]){
            mst_weight += temp.first;
            vis[temp.second] = 1;

            for(auto [w,v] : adj[temp.second]){
                pq.push({w,v});
            }
        }
    }

    cout << "Mst weight = " << mst_weight;
}