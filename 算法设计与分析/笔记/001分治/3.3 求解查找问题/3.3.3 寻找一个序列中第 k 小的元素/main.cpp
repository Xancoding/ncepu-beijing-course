/* ����������
 * ����һ������Ϊ n ���������У����ÿ���ѡ���㷨������д�С���������ĵ� k ����
 * ʱ�临�Ӷȷ�����
 * T(n) = T(n / 2) + O(n)
 * --> T(n) = O(n)
 */

/* ���룺
���빲���У���һ�а������� n��
�ڶ��а��� n ����������ʾ�������С�
10
2 5 1 7 10 6 9 4 3 8
 */

/* �����
��1С��Ԫ�أ�1
��2С��Ԫ�أ�2
��3С��Ԫ�أ�3
��4С��Ԫ�أ�4
��5С��Ԫ�أ�5
��6С��Ԫ�أ�6
��7С��Ԫ�أ�7
��8С��Ԫ�أ�8
��9С��Ԫ�أ�9
��10С��Ԫ�أ�10
 */
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int q[N];

int quick_select(int q[], int l, int r, int k)
{
    int i = l - 1, j = r + 1, x = q[l + r >> 1];

    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    if (k - 1 == j) return q[j];
    else if (k - 1 < j)  return quick_select(q, l, j, k);
    else return quick_select(q, j + 1, r, k);
}


int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    for (int k = 1; k <= n; ++k)
    {
        int res { quick_select(q, 0, n - 1, k) };
        printf("��%dС��Ԫ�أ�%d\n", k, res);
    }

    return 0;
}