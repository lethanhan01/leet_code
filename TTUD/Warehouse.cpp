#include <bits/stdc++.h>
using namespace std;
int maxN = 1001, maxT =101, maxD =11;
int n, T, D;
vector<int> a;
vector<int> t;
int result;
int S[maxN][maxT];

void input() {
    cin >> n >> T >> D; 
    a.resize(n);
    t.resize(n);
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    for(int i =0; i < n; i++){
        cin >> t[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    int ans = a[1];
    S[1][t[1]] = a[1];
    for(int i =0; i <= n; i++){
        for(int k =1; k <= T; k++){
            if(k >= t[i]){
                
            }

        }
    }
    return 0;
}