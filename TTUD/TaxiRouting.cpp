#include <bits/stdc++.h>
using namespace std;
int maxN = 13;
int INF = 1e9;

int n; // so hanh khach
vector<vector<int>> c(2*maxN, vector<int>(2*maxN,0)); // ma tran klhoang cach
int cmin = INF; // khoang cach nho nhat giua 2 diem dung

vector<int> X(2*maxN); // lo trinh xe taxi
vector<int> appear(2*maxN, 0); // danh dau xem diem nay da di qua hay chua
int currentDist = 0; // tong quang duong di duoc
int currentLoad = 0; // so khach dang cho hien tai 
int result = INF; // ket qua toi uu

void input(){
    cin >> n;
    for(int i =0; i <= 2*n; i++){
        for(int j =0; j <= 2*n; j++){
            cin >> c[i][j];
            if(i!=j){
                cmin = min(cmin, c[i][j]);
            }
        }
    }
}

bool check(int v){
    if(appear[v] == 1){
        return false;
    }
    if(v > n){
        return appear[v-n] == 1;
    }else{
        return currentLoad < 1;
    }
    return true;
}

void Try(int k){
    for(int v =1; v <= 2*n; v++){
        if(check(v) == 0){
            continue;
        }

        //Dat trang thai
        X[k] = v;
        appear[v] = 1;
        currentDist += c[X[k-1]][X[k]];

        //Kiem tra xem la don khach hay tra khach
        if(v > n){
            currentLoad--;
        }else{
            currentLoad++;
        }

        //kiem tra dieu kien dung va tinh can
        if(k == 2*n){
            result = min(result, currentDist + c[X[k]][X[0]]);
        }else{
            int lowerBound = currentDist + cmin*(2*n - k +1);
            if(result > lowerBound){
                Try(k+1);
            }
        }

        //Tra lai trang thai ban dau
        appear[v] = 0;
        currentDist -= c[X[k-1]][X[k]];
        if(v > n){
            currentLoad++;
        }else{
            currentLoad--;
        }
    }  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    X[0]= 0;
    Try(1);
    cout << result << endl;
    return 0;
}