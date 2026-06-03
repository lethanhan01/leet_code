#include <bits/stdc++.h>
using namespace std;

const int maxN = 15;
const int INF = 1e9;

int n,K;                //so hanh khach, so ghe tren xe
vector<vector<int>> c(2*maxN, vector<int>(2*maxN,0)); //ma tran khoang cach
int cmin = INF;         //Khoang cach nho nhat giua 2 diem dung

int X[2*maxN];          //hanh trinh cua xe bus, vi du: X[6]={0,3,1,4,2,6,5}
int appear[2*maxN];     //danh dau xem diem dung da di qua hay chua
int currentDist = 0;    //tong quang duong hien tai
int currentLoad = 0;    //so hanh khach hien tai tren xe
int result = INF;        //Loi giai tot nhat tim duoc

//Ham nay la nhap input thoi 
void input() {
    cin >> n >> K;
    for(int i =0; i < 2*n+1;i++){
        for(int j =0; j < 2*n+1; j++){
            cin >> c[i][j];
            if(i!=j){
                cmin = min(cmin, c[i][j]);
            }
        }
    }

}

//Ham nay la ham check dieu kien v, v la diem dung
bool check(int v){
    if(appear[v] == 1){
        return 0; //diem dung v da duoc ghe roi
    }
    if(v > n){
        return ( appear[v-n] == 1 ); //chi duoc ghe v neu da don hanh khach v-n
    }else{
        return currentLoad < K; //xe phai con cho ngoi
    }
} 


void Try(int k) {
    //Kiem tra dieu kien cua diem dung dang xet de loai bot cac truong hop can xet
    for(int v =1; v < 2*n+1; v++){
        if(check(v)==0){
            continue;
        } 
        X[k] = v;   //Dat v vao X[k]
        appear[v] = 1; // cap nhat la da den diem dung v roi
        currentDist += c[X[k-1]][X[k]]; //Cap nhat quang duong hien tai
        
        // Neu diem dung v <= n thi la don khach, con v > n la tra khach
        if(v <= n){
            currentLoad++; 
        }else{
            currentLoad--;
        } 

        //neu di het 2n diem thi tinh ket qua
        if(k==2*n){
            result = min(result, currentDist + c[X[k]][X[0]]);   
        }
        else{ //neu chua di het 2n diem thi tinh bound va chuyen sang branch khac
            int lowerBound = currentDist + cmin*(2*n-k+1);
            if(lowerBound < result){
                Try(k+1); // Neu can duoi van nho hon ket qua tot nhat hien tai thi moi tiep tuc tim
            }
        }

        //Tra lai trang thai ban dau
        appear[v] = 0;
        currentDist -= c[X[k-1]][X[k]];
        if(v <= n) {
            currentLoad--;
        }else{
            currentLoad++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    X[0] = 0;
    Try(1);
    cout << result << endl;
    return 0;
}