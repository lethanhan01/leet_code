#include <bits/stdc++.h>
using namespace std;
int size = 10;
struct Item{
    double w;
    double v;
};
int n;  double W;
vector<Item> a;
double total=0;

void input(){
    cin >> n >> W;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].w >> a[i].v;
    }
}

bool check(Item a, Item b){
    return (a.v/a.w) > (b.v/b.w);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sort(a.begin(), a.end(), check);
    for(int i = 0; i < n; i++){
        if(W <= 0){
            break;
        }

        if(a[i].w <= W){
            total += a[i].w;
            W -= a[i].w;
        }else{
            total += a[i].v * (W / a[i].w);
            W = 0;
        }

    }
    cout << fixed << setprecision(2) << total << endl;
    return 0;
}