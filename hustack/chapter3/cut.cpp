#include <iostream>
#include <vector>
using namespace std;

int H,W,n;
vector<pair<int,int>> blocks;
int material[20][20];

bool canPlace(int x, int y, int h, int w){ //x, y la vi tri hien tai
    if(x+w > W || y+h > H) return false;
    for(int i=x; i<x+w; i++){
        for(int j=y; j<y+h; j++){
            if(material[i][j] == 0) return false;
        }
    }
    return true;
}

void place(int x, int y, int h, int w, int val){
    for(int i=x; i<x+w; i++){
        for(int j=y; j<y+h; j++){
            material[i][j] = val;
        }
    }
}

bool Try(int idx){
    if (idx == n) return true;
    int h = blocks[idx].first;
    int w = blocks[idx].second;

    for(int x = 0; x < W ; x++ ){
        for(int y = 0; y < H; y++){
            if(canPlace(x,y,h,w)){
                place(x,y,h,w,0);
                if(Try(idx+1)) return true;
                place(x,y,h,w,1);
            }

            if(canPlace(x,y,w,h)){
                place(x,y,w,h,0);
                if(Try(idx+1)) return true;
                place(x,y,w,h,1);
            }
        }

    }
    return false;
}


int main() {
    cin >> H >> W >> n;
    blocks.resize(n);
    for(int i=0; i<n; i++) {
        cin >> blocks[i].first >> blocks[i].second;
    }

    for(int i=0; i<W;i++){
        for(int j=0; j<H; j++){
            material[i][j] = 1;
        }
    }

    if (Try(0)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}