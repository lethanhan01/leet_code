#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int m;
int q =0;
vector<int> S;
void input(){
    cin >> n;
    a.resize(n);
    S.resize(n);
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    S[0] = a[0];
    cin >> m;
}


void Try(int i, int sum) {
    // Nếu đã xét hết các phần tử
    if(i == n) {
        if(sum >= m) {
            q++;
        }
        return;
    }

    // Trường hợp 1: không chọn a[i]
    Try(i + 1, sum);

    // Trường hợp 2: chọn a[i]
    Try(i + 1, sum + a[i]);
}

int main()  {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    Try(0,0);
    cout << q << endl;
    return 0;
}