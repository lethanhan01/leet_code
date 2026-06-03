#include <bits/stdc++.h>
using namespace std;

int maxHW = 10;
int H, W;
int n;

struct rectangle{
    int hi;
    int wi; 
};

vector<rectangle> a(10,{0,0});

bool mark[10][10];
int totalArea = 0;



void input() {
    cin >> H >> W;
    cin >> n;

    for(int i =0; i < n; i++){
        cin >> a[i].hi >> a[i].wi ;
        totalArea += a[i].hi * a[i].wi;
    }

}

// Kiem tra vi tri (vo vx vy) co phu hop hay khong
bool check(int vo, int vx, int vy, int k){
    int hk = a[k].hi;
    int wk = a[k].wi;
    if(vo ==1){
        swap(hk,wk);
    }

    if(hk+ vy > H){
        return 0;
    }
    if(wk +vx > W){
        return 0;
    }

    for(int i = vx; i < vx + wk ; i++){
        for(int j = vy; j < vy + hk; j++){
            if(mark[i][j] == 1){
                return 0;
            }
        }
    }
    return 1;
}


//Ham danh dau true/false
void doMark(int vo, int vx, int vy, int k, bool markv){
    int hk = a[k].hi;
    int wk = a[k].wi;
    if(vo ==1){
        swap(hk,wk);
    }
    for(int i = vx; i < vx + wk ; i++){
        for(int j = vy; j < vy + hk; j++){
            mark[i][j] == markv;
        }
    }
}

bool Try(int k){
    if(k == n){
        return true;
    }

    for(int vo =0; vo <=1; vo ++){
        int hk = a[k].hi;
        int wk = a[k].wi;
        if(vo ==1){
            swap(hk,wk);
        }
        
        if(vo == 1 && hk == wk){
            continue;
        }

        for(int vy = 0; vy <= H-hk; vy++){
            for(int vx = 0; vx <= W -wk; vx++){
                if(check(vo,vx,vy,k)){
                    doMark(vo, vx, vy, k, 1);
                    if(Try(k+1)){
                        return true;
                    }
                    doMark(vo, vx, vy, k, 0);
                }
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    if(totalArea > H*W){
        cout << 0 << endl;
        return 0;
    }

    sort(a.begin(), a.end(), [](const rectangle& a, const rectangle& b){
        return a.hi*a.wi > b.hi*b.wi;
    });

    if(Try(0)){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}