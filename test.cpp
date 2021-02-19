// 数据范围
// 1≤n≤100000
// 输入样例：
// 5
// 3 1 2 4 5
// 输出样例：
// 1 2 3 4 5

#include <iostream>

using namespace std;

const int N = 100010;
int q[N];

// 写法1
void quick_sort(int q[], int l, int r) {
    if (l >= r) return;
    
    int x = q[l + r >> 1];// 获取数组的中间数字 
    int i = l - 1, j = r + 1;
    
    while (i < j) {
        do i ++; while (q[i] < x);
        do j --; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}


// 写法2
void quick_sort2(int q[], int l, int r) {
    if (l >= r) return;
    
    int i = l, j = r;
    int x = q[l + r >> 1];
    
    while (i < j) {
        while (q[i] < x) i ++;
        while (q[j] > x) j --;
        if (i < j) swap(q[i], q[j]);
    }
    
    quick_sort2(q, l, j);
    quick_sort2(q, j + 1, r);
}

int main(){
    int n;
    cin >> n;
    
    // 输入数字
    for (int i = 0; i < n; i ++) cin >> q[i];
    
    quick_sort2(q, 0, n - 1);
    
    for (int i = 0; i < n; i ++) cout << q[i] <<' ';
    cout << endl;
    
    return 0;
}