#include <bits/stdc++.h>
using namespace std;
int n,m; // n mon hoc, m giao vien
int maxN = 1000, maxM = 500; 
vector<vector<int>> k; 
int c; 
vector<vector<int>> conflict(maxN,vector<int>(2,0));
int bestSum = 0;

void input(){
    cin >> n >> m;
    cin >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x; // Nhap so tiet ma gv day duoc
        k[i].resize(x);
        for(int j =0; j < k[i].size() ;j++){
            cin >> k[i][j]; //nhap cac tiet hoc ma giao vien co the day duoc
        }
    }
    cin >> c;
    conflict.resize(c);
    for(int i =0; i < c; i++){
        cin >> conflict[i][0] >> conflict[i][1];
    }
}
//Duyet cac tiet hoc v
bool check(int i, int v){
    //Check xem tiet nay co conflict voi cac tiet truoc khong
    //Check xem tiet nay co thay co nao day chua
    //
}

void Try(int k){
    for(int v =0; v < n ;v++){

    }
}

void output(int result,  ){
    // In ra tong so tiet hoc co the xep

    //in ra index cua tung thay co tuong ung voi cac tiet hoc phu trach

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();


    return 0;
}