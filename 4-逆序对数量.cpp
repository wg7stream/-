#include <iostream>

using namespace std;

/*
    计算逆序对的数量（序列）：
    1. 递归算左边的；
    2. 递归算右边的；
    3. 算一个左一个右的；
    4. 把他们加到到一起。

    这个时候我们注意到一个很重要的性质，左右半边的元素在各自任意调换顺序，
    是不影响第三步计数的，因此我们可以数完就给它排序。这么做的好处在于，
    如果序列是有序的，会让第三步计数很容易。如果无序暴力数的话这一步是O(n^2)的
*/


int n;// 用于记录输入数组的大小
const int N = 100010;// 数组最大的元素个数
int q[N], tmp[N];//  tmp[N]用于临时保存每次归并后排好序的数组

typedef long long LL;// 逆序对最大的个数可能会很大，用long long存储

// 函数的返回值是当前计算出的逆序对个数
LL merge_sort(int l, int r) {
    if (l >= r) return 0;
    
    int mid = l + r >> 1;
    LL res = merge_sort(l, mid) + merge_sort(mid +1, r);
    
    int k = 0;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k ++] = q[i ++];
        else {
            tmp[k ++] = q[j ++];
            res += mid - i + 1;
        }
    }
    
    while (i <= mid) tmp[k ++] = q[i ++];
    while (j <= r) tmp[k ++] = q[j ++];
    
    for (int i = l, j = 0; i <= r; i ++, j ++) {
        q[i] = tmp[j];
    }
    
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> q[i];
    }
    
    cout << merge_sort(0, n - 1) << endl;
    
}