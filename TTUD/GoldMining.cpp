#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000

int n, L1, L2;
int ans;
vector<int> a;
vector<int> S;

void input(){
    cin >> n >> L1 >> L2;
    a.resize(n);
    S.resize(n);    
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
}

void solve(){
    deque<int> d;
    ans = 0;
    for(int i =0; i < n; i++){
        while (!d.empty() && (d.front() < i -L2)){
            d.pop_front();
        }
        int j =i -L1;
        if(j >= 0){
            while (!d.empty() && (S[d.back()] < S[j]))
            {
                d.pop_back();
            }
            d.push_back(j);
            
        }
        S[i] = a[i] + (d.empty() ? 0 : S[d.front()]);
        ans = max(ans,S[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();
    cout << ans;
    return 0;
}