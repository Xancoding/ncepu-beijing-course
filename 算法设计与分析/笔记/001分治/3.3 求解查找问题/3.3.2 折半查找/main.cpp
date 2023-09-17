/* ���룺
���빲���У���һ�а������� n��k��n ��ʾ����ĳ��ȣ�k ��ʾ�����ҵ�Ԫ��
�ڶ��а��� n ����������ʾ�������С�
10 6
1 2 3 4 5 6 7 8 9 10
 */

/* �����

 */
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n, k;
int a[N];
int cur;

int binarySearch(int a[], int l, int r, int k)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] == k)
        {
            cur = mid;
            return mid;
        }
        else if (a[mid] < k) l = mid + 1;
        else r = mid - 1;
    }

    return -1;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int res{binarySearch(a, 0, n - 1, k) };

    if (res == -1) cout << "δ�ҵ�" << k << "Ԫ��\n";
    else printf("a[%d] = %d", cur, k);

    return 0;
}