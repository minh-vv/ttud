#include <bits/stdc++.h>
using namespace std;

string num1,num2,date,time1,time2;
int checkPhoneNumber = 1;
int totalCalls = 0;
map <string,int> numberCallsFrom, timeCallsFrom;


bool KtraSDT(string num){
    if (num.length != 10) return false;
    for (int i=0; i< num.length ;i++){
        if ( !isdigit(num[i])) return false;
    }
    return true;
}

int TimeCall(string t){
    return 3600 *((t[0]-'0')*10 + (t[1]-'0'))
            +60 *((t[3]-'0')*10 + (t[4]-'0'))
            +((t[6]-'0')*10 + (t[7]-'0'));
}

int main(){
    freopen("Telco.inp","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string cmd;
    while(1){
        cin >> cmd;
        if (cmd == "#") break;

        cin >> num1 >> num2 >> date >> time1 >> time2;

        totalCalls ++;
        if ( KtraSDT (num1) == false) checkPhoneNumber = 0;
        if ( KtraSDT (num2) == false) checkPhoneNumber = 0;

        numberCallsFrom(num1)++;
        timeCallsFrom(num1) = TimeCall(time2) - TimeCall(time1);
    }
    while (1){
        cin >> cmd;
        if (cmd == "#") break;
        if (cmd == "?check_phone_number")
            cout << checkPhoneNumber << '\n';
        else if (cmd == "?number_calls_from")
    }


}
