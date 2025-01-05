#include<bits/stdc++.h>

using namespace std;
int n, T ,D;
int a[1005];
int t[1005];

int F[1005][105] = {};

int res = -1e9;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>T>>D;

    for( int i = 1;i <= n;i++) cin>> a[i];
    for( int i = 1;i <= n;i++) cin>> t[i];

    for( int i = 1 ; i<= n ;i++){
        for( int k = 1 ; k <= T; k++){
            if( k < t[i] ){
                F[i][k] = 0;
            }else{
                F[i][k] = a[i];
                for( int j = 1 ; j <= D && i - j >= 0 ; j++){

                    F[i][k] = max( F[i][k] , F[i-j][k-t[i]] +a[i] );
                }
            }
            res = max ( res, F[i][k]);
        }
    }

    cout<<res;

    return 0;
}
