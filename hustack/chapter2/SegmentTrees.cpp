#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000001];
int maxValue[1000001];
int m;
int u,v;
string cmd;

void updateNode(int id, int l, int r, int index, int value){
    if (l > r) return;
    if (index < l || index > r) return;
    if (l==r) {
        maxValue[id] = value;
        return;
    }
    int mid = (l+r)/2;
    int LC = id *2 ;
    int RC = id * 2 +1;
    updateNode(LC, l , mid, index, value);
    updateNode(RC, mid+1, r, index, value);
    maxValue[id] = max(maxValue[LC],maxValue[RC]);
}
void update(int index, int value){
    updateNode(1,1,n,index,value);
}

int getMaxNode(int id, int l, int r, int i, int j){
    if (i > r || j < l) return -1; 
    if (i <= l && r <= j) return maxValue[id];
    int mid = (l+r)/2;
    int LC = id*2; 
    int RC = id*2+1;
    int maxLeft = getMaxNode(LC,l, mid, i, j);
    int maxRight = getMaxNode(RC, mid+1, r, i, j);
    return max(maxLeft,maxRight);

}
int getMax(int i,int j){
    return getMaxNode(1,1,n,i,j);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("test.inp", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        update(i,a[i]);
        
    }
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> cmd ;
        cin >> u >> v ;
        if (cmd == "get-max") 
            cout<< getMax(u,v) << endl;
        else if (cmd == "update")
            update(u,v);
    }
}