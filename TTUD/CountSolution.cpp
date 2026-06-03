#include <bits/stdc++.h>
using namespace std;

int n, M;
vector<int> a;
vector<int> x;

// Biến đếm số nghiệm
int counts = 0;

/*
    Hàm Try(k, currentSum)

    k          : đang gán giá trị cho biến x[k]
    currentSum : tổng hiện tại của các biến đã gán trước đó

    Ví dụ:
    a1*x1 + a2*x2 + a3*x3 = M

    Try(0, 0) nghĩa là bắt đầu gán x[0]
    Try(1, sum) nghĩa là đã gán x[0], đang gán x[1]
    Try(2, sum) nghĩa là đã gán x[0], x[1], đang gán x[2]
*/
void Try(int k, int currentSum) {

    /*
        CODE CŨ CỦA BẠN SAI Ở ĐÂY:

        Bạn dùng:
            if(n == 1)

        Nhưng n là số lượng biến ban đầu.
        Không nên giảm n trong quá trình đệ quy.

        Cách đúng:
            Dùng k để biết đã gán đến biến nào.

        Khi k == n nghĩa là đã gán đủ:
            x[0], x[1], ..., x[n-1]
    */
    if(k == n) {
        /*
            Vì đã gán đủ n biến,
            ta kiểm tra tổng có đúng bằng M không.
        */
        if(currentSum == M) {
            counts++;
        }

        return;
    }

    /*
        Thử các giá trị nguyên dương cho x[k].

        Vì đề bài yêu cầu nghiệm nguyên dương nên:
            x[k] >= 1

        CODE CŨ CỦA BẠN SAI Ở ĐÂY:

        Bạn viết:
            for(int i = 0; i < n; i++)

        Điều đó làm chương trình không biết rõ đang gán biến nào.
        Khi quay lui, ta không nên lặp qua tất cả biến ở mỗi bước.

        Cách đúng:
            Ở bước k, chỉ gán giá trị cho đúng x[k].
    */
    for(int value = 1; ; value++) {

        /*
            Tính tổng mới nếu chọn:
                x[k] = value
        */
        int newSum = currentSum + a[k] * value;

        /*
            Nếu tổng đã vượt M thì dừng.

            Vì value càng tăng thì newSum càng lớn,
            nên không cần thử tiếp nữa.
        */
        if(newSum > M) {
            break;
        }

        /*
            Gán giá trị cho x[k]
        */
        x[k] = value;

        /*
            Gọi đệ quy để gán biến tiếp theo.

            CODE CŨ CỦA BẠN SAI Ở ĐÂY:

            Bạn viết:
                solve(a, M - a[i] * x[i], n - 1)

            Việc giảm n làm mất ý nghĩa ban đầu của n.
            Hơn nữa, bạn không biết đang gán x nào.

            Cách đúng:
                Try(k + 1, newSum)

            Nghĩa là:
                Sau khi gán x[k], chuyển sang gán x[k + 1].
        */
        Try(k + 1, newSum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> M;

    a.resize(n);
    x.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    /*
        Bắt đầu quay lui từ biến đầu tiên x[0],
        với tổng ban đầu bằng 0.
    */
    Try(0, 0);

    cout << counts << endl;

    return 0;
}