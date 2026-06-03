#include <bits/stdc++.h>
using namespace std;

int n, M;
int counts = 0;
vector<int> x;
vector<int> a;

//Kiem tra cac nghiem co dung khong


//giai phuong trinh n nghiem nguyen duong
void Try(int k, int currentSum){
    //Ktra dk dung
    if(k==n){
        if(currentSum == M){
            counts++;
        }
        return;
    }
    for(int v = 1; ;v++){
        int newSum = currentSum + v*a[k];
        if(newSum > M){
            break;
        }
        x[k]=v;

        Try(k+1, newSum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> M;
    a.resize(n);
    x.resize(n);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Try(0,0);
    cout << counts << endl;
    return 0;
}