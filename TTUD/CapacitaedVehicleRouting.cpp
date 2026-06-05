#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, K, Q;                // n: so diem giao hang, K: so xe tai, Q: tai trong toi da cua moi xe
vector<int> d;              // d[i]: so luong hang can giao tai khach i
vector<vector<int>> c;      // c[i][j]: khoang cach tu diem i den diem j

vector<int> Y;              // Y[k]: khach hang dau tien cua xe tai thu k
vector<int> X;              // X[s]: diem tiep theo sau diem s trong lo trinh
vector<int> visited;        // visited[i] = 1 neu khach i da duoc phuc vu, visited[i] = 0 neu chua duoc phuc vu
vector<int> loadTruck;      // loadTruck[k]: tong so hang hien tai cua xe k

int currentDist = 0;        // Tong quang duong cua phuong an dang xet
int result = INF;           // Ket qua tot nhat tim duoc
int cmin = INF;             // Canh nho nhat trong ma tran khoang cach, dung de tinh can duoi

int visitedCount = 0;       // So hang da duoc phuc vu

void input() {
    cin >> n >> K >> Q;     // Tạo vector d có n + 1 phần tử
    d.resize(n + 1, 0);     // d[0] là depot nên không dùng, các khách là d[1] đến d[n]
    for (int i = 1; i <= n; i++) {
        cin >> d[i];        // Nhap so luong hang can giao
    }
    
    c.resize(n + 1);     // Tạo ma trận c kích thước (n + 1) x (n + 1)
    for (int i = 0; i <= n; i++) {
        c[i].resize(n + 1, 0);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if (i != j) {
                cmin = min(cmin, c[i][j]);
            }   
        }
    }

    // Khởi tạo các vector phụ trợ
    Y.resize(K + 1, 0);
    X.resize(n + 1, 0);
    visited.resize(n + 1, 0);
    loadTruck.resize(K + 1, 0);
}

// Ham kiem tra xem co the chon v lam khach dau tien cua xe k hay khong
bool checkY(int v, int k) {
    if (v == 0) return true;     // Neu v = 0, nghia la xe k khong dung de giao hang
    if (visited[v]) return false;   // Neu khach v da duoc xe khac phuc vu roi thi khong duoc chon lai
    if (loadTruck[k] + d[v] > Q) return false;     // Neu hang cua khach v vuot qua tai trong xe thi khong hop le

    return true;
}

// Ham kiem tra xem xe k co the di tiep den diem v hay khong
bool checkX(int v, int k) {
    if (v == 0) return true;     // v = 0 nghia la xe quay ve kho
    if (visited[v]) return false;     // Khach da duoc phuc vu thi khong duoc phuc vu lai
    if (loadTruck[k] + d[v] > Q) return false;     // Kiem tra rang buoc tai trong Q

    return true;
}

// Ham tinh can duoi
bool boundOK() {
    int remaining = n - visitedCount;

    int lowerBound = currentDist + remaining * cmin;     // Moi khach con lai it nhat can them 1 canh co chi phi >= cmin
    return lowerBound < result;
}

// TryX(s, k): dang xay tiep lo trinh cho xe k,
// hien tai xe dang o diem s
void TryX(int s, int k) {
    // Neu s = 0, nghia la xe k la xe rong, khong phuc vu khach nao
    if (s == 0) {
        if (k < K) {
            // Chuyen sang xe tiep theo
            TryX(Y[k + 1], k + 1);
        } else {
            // Da xet het K xe
            if (visitedCount == n) {
                result = min(result, currentDist);
            }
        }
        return;
    }

    // Thu chon diem tiep theo sau diem s, v = 0 nghia la ket thuc lo trinh cua xe k va quay ve kho
    for (int v = 0; v <= n; v++) {
        if (checkX(v, k)) {
            X[s] = v;

            // Cong chi phi di tu s den v
            currentDist += c[s][v];

            if (v == 0) {
                // Neu v = 0, xe k quay ve kho, sau do chuyen sang xe tiep theo

                if (k == K) {
                    // Ktra dk dung, va tinh ket qua
                    if (visitedCount == n) {
                        result = min(result, currentDist);
                    }
                } else {
                    // Cat nhanh truoc khi chuyen sang xe tiep theo
                    if (boundOK()) {
                        TryX(Y[k + 1], k + 1);
                    }
                }
            } else {
                // Neu v la mot khach hang that su

                visited[v] = 1;
                visitedCount++;
                loadTruck[k] += d[v];

                // Cat nhanh:
                // Neu can duoi van nho hon ket qua tot nhat hien tai thi moi tiep tuc tim
                if (boundOK()) {
                    TryX(v, k);
                }

                // Quay lui
                loadTruck[k] -= d[v];
                visitedCount--;
                visited[v] = 0;
            }

            // Quay lui chi phi
            currentDist -= c[s][v];
        }
    }
}

// TryY(k): chon khach dau tien cho xe k
void TryY(int k) {
    /*
        De tranh sinh trung lap do cac xe giong nhau, ta ep cac khach dau tien cua cac xe khong rong tang dan.
        Vi du:
        Xe 1 bat dau bang khach 2, xe 2 bat dau bang khach 5 thi ta khong can xet lai truong hop:
        Xe 1 bat dau bang khach 5, xe 2 bat dau bang khach 2
    */

    int start = 0;

    if (k > 1 && Y[k - 1] > 0) {
        start = Y[k - 1] + 1;
    }

    for (int v = start; v <= n; v++) {
        if (checkY(v, k)) {
            Y[k] = v;

            if (v > 0) {
                // Xe k bat dau tu depot 0 va di den khach v
                currentDist += c[0][v];

                visited[v] = 1;
                visitedCount++;
                loadTruck[k] += d[v];
            }

            if (k == K) {
                // Sau khi da chon xong diem dau tien cho tat ca K xe, bat dau xay tiep tung lo trinh bang TryX
                if (boundOK()) {
                    TryX(Y[1], 1);
                }
            } else {
                if (boundOK()) {
                    TryY(k + 1);
                }
            }

            // Quay lui
            if (v > 0) {
                loadTruck[k] -= d[v];
                visitedCount--;
                visited[v] = 0;

                currentDist -= c[0][v];
            }

            Y[k] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    // Neu tong nhu cau lon hon tong tai trong cua K xe thi chac chan khong co loi giai hop le
    int totalDemand = 0;
    for (int i = 1; i <= n; i++) {
        totalDemand += d[i];
    }

    if (totalDemand > K * Q) {
        cout << -1;
        return 0;
    }

    TryY(1);

    cout << result;

    return 0;
}