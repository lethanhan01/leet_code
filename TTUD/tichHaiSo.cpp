#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin >> a >> b; //dien a va b
    int n = a.size(); // so cac chu so cua a
    int m = b.size(); // so cac chu so cua b
   
    //cout << n << m << endl;

    vector<int> res(m+n,0);// ket qua cua phep nhan string, m +n la tong so chu so co the
    
    for(int i =n-1; i >= 0; i--){
        for(int j=m-1; j>=0; j--){
            int mul = (a[i]-'0')*(b[j]-'0');// Chuyen chu so thanh so
            int p1 = i+j; // vi tri phan nho
            int p2 = i+j+1; // vi tri chu so hang don vi
            int sum = mul + res[p2];
            res[p2] = sum%10;
            res[p1] += sum/10;
        }
    }
    //Loai bot cac chu so 0 o truoc ketqua de bat dau show cac ketqua
    int i =0;
    while (i < (int)res.size() && res[i] == 0){
        i++;
    }
    //ktra xem kq bang 0 hay khong
    if(i == (int)res.size()){
        cout << 0;
        return 0;
    }else{
        //hien thi ketqua
        while (i < (int)res.size())
        {
            cout << res[i++];

        } 
    }
    return 0;
}