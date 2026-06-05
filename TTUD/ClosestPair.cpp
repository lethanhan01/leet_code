#include <bits/stdc++.h>
using namespace std;
int maxN =  100000;
int n;
struct point {
    int x;
    int y;
};
vector<point> c(maxN);

void input(){
    cin >> n;
    c.resize(n);

    for(int i =0; i < n; i++){
        cin >> c[i].x >> c[i].y;
    }
}

double distance(point& a, point& b){
    double dx= a.x-b.x, dy= a.y-b.y;
    return sqrt(dx*dx + dy*dy);
}

double bruteForce(vector<point>& a, int l, int r){
    double d = 1e8;
    for(int i = l; i <= r; i++){
        for(int j = i+1; j <= r; j++){
            d = min(d, distance(a[i], a[j]));
        }
    }
    return d;
}

double solveStrip(vector<point>& pts, int l, int r, int midX, double d){
    vector<point> strip;
    for(int i =1;i <=r; i++){
        if(abs((double)(pts[i].x - midX)) < d){
            strip.push_back(pts[i]);
        }
    }
    sort(strip.begin(), strip.end(),[](const point& a, const point& b){
        return a.y <  b.y;
    })
}

double solve(vector<point>& pts,int l, int r){

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}