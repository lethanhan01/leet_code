#include <bits/stdc++.h>
using namespace std;
int maxN = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n; 
    cin >> n;
    long long q = 0;
    vector<long long> a(n,0);
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    
    for(int i =0; i < n;i++){
        for(int j = i+1; j < n; j++){
            if(a[i] == a[j]){
                q++;
            }
        }
    }
    cout << q % maxN << endl;
    return 0;
}
/*
6 
1 2 2 1 3 1
*/