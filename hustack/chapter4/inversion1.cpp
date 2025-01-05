#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
int n;
int a[1000001];
int b[1000001];
int res = 0;
void connect(int l, int mid, int r){
    int i = l;
    int j = mid +1 ;
    int k = l;

    while (i <= mid && j <= r){
        if (a[i] > a[j]){
            b[k] = a[j];
            j++;
            res = (res + mid - i + 1 ) % MOD;
        }
        else {
            b[k] = a[i];
            i++;
        }
        k++;
    }
    while (i<= mid){
        b[k] = a[i];
        i++;
        k++;
    }
    while (j<= r){
        b[k] = a[j];
        j++;
        k++;
    }

    for (int i = l; i <= r; i++){
        a[i] = b[i];
    }
}

void mergeSort(int l, int r){
    if (l == r) return;
    int mid = (l+r)/2;

    mergeSort(l,mid);
    mergeSort(mid+1,r);

    connect(l,mid,r); 
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    //freopen("test.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <=n; i++){
        cin >> a[i];
    }
    mergeSort(1,n);
    cout << res;
    
}