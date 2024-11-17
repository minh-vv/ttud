//Hoang Quoc Viet-20210936
#include<bits/stdc++.h>
using namespace std;

int n,C;
int x[100005]= {};
int result;

bool check( int dis ){

    int last = x[1];
    int dem = 1;

    for( int i =2 ; i<= n; i++ ){

        if( x[i] - last >= dis ){
            dem++;
            last = x[i];
        }
    }

    if(dem >= C )
        return true;
    else
        return false;

}
int main(){
        freopen("MaxDistanceSubSequence.inp","r",stdin);

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T; cin>> T;
    while(T--){
        cin>> n>> C;

        for( int i = 1 ; i<=n ;i++){
            cin>> x[i];
        }

        sort( x+1 , x+n+1); //Sap xep mang X

        // Tim kiem nhi phan distance
        int left= 0;
        int right= x[n] - x[1];

        while( left <= right){
            int mid = ( right + left )/2;

            if( check( mid ) ){
                result = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        cout<< result << '\n';
    }

}
