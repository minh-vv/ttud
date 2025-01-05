int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("test.inp", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> cmd ;
        cin >> u >> v ;
        if (cmd == "get-max") 
            cout<<getMaxNode(u, v)<< endl;
        else if (cmd == "update")
            updateNode(u, v)<< endl;
    }
}