// HARSHIT SAH 25/DA/032

#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
int findParent(int x) {
    if(parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

int main() {
    int n = 5;
    vector<array<int,3>> edges = {{2, 0, 1},{6, 0, 3}, {3, 1, 2},{8, 1, 3},{5, 1, 4},{7, 2, 4}};
    sort(edges.begin(), edges.end());
    parent.resize(n);

    for(int i = 0; i < n; i++) parent[i] = i;

    int mst_weight = 0;
    int edgesTaken = 0;

    for(auto [w,u,v] : edges) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu != pv) {
            cout << u << " -- " << v << " (" << w << ")\n";
            mst_weight += w; edgesTaken++;
            parent[pu] = pv;
            
            if(edgesTaken == n - 1)
                break;
        }
    }

    cout << "MST weight = " << mst_weight << endl;

    return 0;
}