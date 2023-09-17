/* ����������
 * ����һ���� n �����������У��������������������еĺ�
 */

/* ���룺
���빲e���У���һ�а������� n��
�ڶ��а��� n ������
6
-2 11 -4 13 -5 -2
 */

/* �����
��������к�Ϊ��20
 */
#include<iostream>
using namespace std;

typedef long long LL;

const int N = 1010;
const int INF = 0x3f3f3f3f;

int n;
int a[N];


// ����Խ�������ߵ���������к�
LL maxCrossSum(int a[], int l, int mid, int r)
{
    LL sum = 0, leftSum = -INF, rightSum = -INF;
    // ���м�λ�����������������к�
    for (int i = mid; i >= l; --i)
    {
        sum += a[i];
        leftSum = max(leftSum, sum);
    }
    sum = 0;
    // ���м�λ�����������������к�
    for (int i = mid + 1; i <= r; ++i)
    {
        sum += a[i];
        rightSum = max(rightSum, sum);
    }
    // ���ؿ�Խ�������ߵ���������к�
    return leftSum + rightSum;
}

// �������������������к�
LL maxSubSum(int a[], int l, int r)
{
    if (l == r) return a[l]; // �����г���Ϊ1ʱ��ֱ�ӷ��ظ���ֵ

    int mid = l + r >> 1; // �����з�Ϊ�����֣�����м�λ��
    LL leftMax = maxSubSum(a, l, mid); // �ݹ������벿�ֵ�������������к�
    LL rightMax = maxSubSum(a, mid + 1, r); // �ݹ�����Ұ벿�ֵ�������������к�
    LL crossMax = maxCrossSum(a, l, mid, r); // ����Խ�������ߵ���������к�

    return max(leftMax, max(rightMax, crossMax)); // ���������е����ֵ
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << "������������кͣ�" << maxSubSum(a, 0, n - 1);
    return 0;
}
