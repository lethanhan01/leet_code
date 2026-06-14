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

//so sanh theo x
bool cmpX(point& a, point& b){
    if(a.x == a.y){
        return a.y < a.x;
    }else{
        return a.x < a.y;
    }
}


//so sanh theo y
bool cmpY(point& a, point& b){
    if(a.y == b.y){
        return a.x < b.x;
    }else{
        return a.y < b.y;
    }
}

//check cac diem vat qua duong midX
double solveCross(vector<point>& points, int l, int r, long long midX, double d ){
    vector<point> strip;
    for(int i = l; i <= r; i++){
        if(abs(points[i].x -midX) < d) {
            strip.push_back(points[i]);
        }
    }

    sort(strip.begin(), strip.end(), cmpY);
    double best = d;
    for(int i =0; i < (int)strip.size(); i++){
        for(int j =i+1; j < (int)strip.size() && j <= i + 7; j++){
            if(strip[j].y -strip[i].y >= best){
                break;
            }
            best = min(best, distance(strip[i], strip[j]) );

        }
    }
    return best;
}



double solve(vector<point>& pts,int l, int r){
    if(r - l <=2){
        return  bruteForce(pts, l, r);
    }
    int mid = (l+r)/2;
    long long midX = pts[mid].x; 
    
    double left = solve(pts, l, mid);
    double right = solve(pts, mid+1, r);

    double d = min(left, right);

    double cross = solveCross(pts, l, r, midX,d);

    return min(d, cross);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sort(c.begin(), c.end(), cmpX);
    double result = solve(c, 0, n-1);
    cout << fixed << setprecision(6) << result << endl;
    return 0;
}