#include <bits/stdc++.h>
using namespace std;
int xO,yO,xA,yA,xB,yB;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> xO >> yO >> xA >> yA>> xB>>yB;
    int tich = (xA-xO) *(yB-yO) -  (yA-yO) * (xB-xO);
    cout << tich;
    return 0;
}
