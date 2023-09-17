/* ����������
���ڸ����ĺ��� n ��Ԫ�ص��������У���������������ʹδ��������ͬԪ�ء�
 */

/* ���룺
���빲���У���һ�а������� n ��
�ڶ��а��� n ����������ʾ�������С�
5
3 1 2 4 5
 */

/* �����
���Ԫ�أ�5
�δ�Ԫ�أ�4
 */
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;
const int INF = 0x3f3f3f3f;

int n;
int a[N];
int max1, max2;  // ���Ԫ�ء��δ�Ԫ��

void solve(int a[], int l, int r, int& max1, int& max2)
{
    if (l == r)
    {
        max1 = a[l];
        max2 = -INF;
    }
    else if (r - l == 1)
    {
        max1 = max(a[l], a[r]);
        max2 = min(a[l], a[r]);
    }
    else
    {
        int mid = l + r >> 1;
        int lmax1{}, lmax2{};
        int rmax1{}, rmax2{};
        solve(a, l, mid, lmax1, lmax2);
        solve(a, mid + 1, r, rmax1, rmax2);

        if (lmax1 > rmax1)
        {
            max1 = lmax1;
            max2 = max(lmax2, rmax1);
        }
        else
        {
            max1 = rmax1;
            max2 = max(lmax1, rmax2);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    solve(a, 0, n - 1, max1, max2);
    cout << "���Ԫ�أ�" << max1 << '\n';
    cout << "�δ�Ԫ�أ�" << max2 << '\n';

    return 0;
}