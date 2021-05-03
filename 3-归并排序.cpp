#include <iostream>

using namespace std;

const int N = 100010;
int n, q[N];

// 递归的思想

void merge_sort(int q[], int l, int r) {
    if (l >= r) return;
    
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    
    int temp[N];
    int k = 0;// 核心 记录已经合并的数组个数
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) temp[k ++] = q[i ++];
        else temp[k ++] = q[j ++];
    }
    
    // 当其中一个还有剩余，将其合并进去
    while (i <= mid) temp[k ++] = q[i ++];
    while (j <= r) temp[k ++] = q[j ++];
    
    // 在进行替换 更新原来的数组
    for (int i = l, j = 0; i <= r; i ++, j ++) {
        q[i] = temp[j];
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i ++) {
        cin >> q[i];
    }
    
    merge_sort(q, 0, n - 1);
    
    for (int i = 0; i < n; i ++) {
        cout << q[i] << ' ';
    }
    cout << endl;
    
    return 0;
}