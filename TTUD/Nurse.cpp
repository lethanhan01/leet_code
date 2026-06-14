#include <bits/stdc++.h>
using namespace std;
#define maxN 1002

int n;          // chuoi n ngay di lam
int k1, k2;     // thoi gian di lam trong khoang [k1, k2]
vector<int> S0(maxN,0);   // S0[i] so cach xep lich cho i ngay ma ngay i la ngay duoc nghi
vector<int> S1(maxN,0);   // S1[i] so cach xep lich cho i ngay ma ngay i la ngay di lam

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k1 >> k2;
    S0[1] = S1[k1]= S0[0] = 1;                      // Truong hop co so

    for(int i = k1 + 1; i <= n; i++){
        S0[i] = S1[i-1];                            // ngay i nghi, thi ngay i-1 di lam
        for(int j =k1; j <= k2 && i-j >= 0; j++){ 
            S1[i] += S0[i-j];                       // ngay i di lam: mot chuoi ngay lam viec trong khoang [k1,k2]
        }
    } 
    cout << S0[n] + S1[n];  // so cach lam viec cho ngay n
    return 0;
}