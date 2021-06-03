/*
输入样例：
6 3
1 2 2 3 3 4
3
4
5
输出样例：
3 4
5 5
-1 -1
*/

#include <iostream>

using namespace std;

const int N = 100010;
int q[N];
int n, m, k;

int main() {
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i ++) {
        cin >> q[i];
    }
    
// m次查询
    while (m --){
        int x;
        cin >> x;
        
        int l = 0, r = n - 1;
        while ( l < r){
            int mid = l + r >> 1;
            if (q[mid] >= x) r = mid;
            else l = mid + 1;
        }
        // l或r都行 因为最后l会等于r
        if (q[l] != x) cout << "-1 -1" << endl;
        else{
        // 输出较小的那个位置
            cout << l << ' ';
            int l = 0, r = n - 1;
            while (l < r){
                int mid = l + r + 1 >> 1;
                if (q[mid] <= x) l = mid;
                else r = mid - 1;
            }
            // 输出较大的那个位置
            cout << l << endl;
        }
    }
    return 0;
}