#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,x;
    cin >> n;
    vector<int> a(n,0);
    for(int i = 0; i<n;i++){
        cin >> a[i];
    }
    cin >> x;
    int res = 0;
    for(int i =0; i<n;i++){
        if(a[i]==x){
            res+=1;
        }
    }
    cout <<  res;
    return 0;
}