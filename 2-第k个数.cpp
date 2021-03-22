#include <iostream>

using namespace std;

const int N = 1000010;
int q[N];
int n;
int res;

int quick_sort(int l, int r, int k){
    if (l == r) return q[l];
    
    int i = l - 1, j = r + 1;
    int base = q[l];
    // 简洁的写法
    while (i < j){
        while (q[++ i] < base);
        while (q[-- j] > base);
        if (i < j) swap(q[i], q[j]);
    }
    
    // 左边数组的长度
    int len = j - l + 1;
    if (k <= len) return quick_sort(l, j, k);
    else return quick_sort(j + 1, r, k - len);
}


int main(){
    cin >> n;
    int k;
    cin >> k;
    
    for (int i = 0; i < n; i ++) cin >> q[i];
    
    cout << quick_sort(0, n - 1, k) << endl;
    
    return 0;
    
}