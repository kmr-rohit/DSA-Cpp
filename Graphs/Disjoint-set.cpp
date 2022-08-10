// Helps us to find wheater the 2 given node are belonging  to same compenent 

#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector<int> parent;
    vector<int> size;

    DisjointSet(int maxSize) {
        parent.resize(maxSize);
        size.resize(maxSize);
        for (int i = 0; i < maxSize; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = findPar(parent[v]);
    }

    void union(int a, int b) {
        a = findPar(a);
        b = findPar(b);
        if (a != b) {
            // 
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
void solve() {
    int n;
    cin >> n;
    DisjointSet S(n);  // Initializing with maximum Size
    S.union(3, 7);
    S.union(4, 5);
    S.union(6, 7);
    S.union(8, 9);
    S.union(1, 2);

    cout << S.findPar(1) << endl;

    // cheacking if 2 and 3 belong to same component

    if(S.findPar(2) == S.findPar(3))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}



