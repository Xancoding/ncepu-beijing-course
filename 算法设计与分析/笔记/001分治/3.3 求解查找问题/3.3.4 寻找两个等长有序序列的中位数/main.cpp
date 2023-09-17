/* ����������
 * ����һ������Ϊ n ���������У������Ϊ�������У�a�������м�λ�õ�Ԫ�س�Ϊ a ����λ��
 * ���һ������������������λ�������м���������һ����ż������������λ�����м�ƫ�������
 * ���һ���㷨������������������е�������
 */

/* ���룺
���빲���У���һ�а������� n��
�ڶ��а��� n ����������ʾ���� a��
�����а��� n ����������ʾ���� b��
5
11 13 15 17 19
2 4 6 8 20
 */

/* �����
��λ��Ϊ��11
 */
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N], b[N];
int m1, m2;

void prePart(int &l, int &r)  // �����е�ǰ��������
{
    r = (l + r) >> 1;
}

void postPart(int &l, int &r)  // �����еĺ��������
{
    int m{ (l + r) >> 1 };
    if ((l + r) % 2 == 0)      // ��������������Ԫ��
        l = m;
    else                       // ��������ż����Ԫ��
        l = m + 1;
}
int getMidNum(int a[], int la, int ra, int b[], int lb, int rb)
{
    if (la == ra && lb == rb)   // �������ж�ֻ��һ��Ԫ�أ����ؽ�С��
    {
        return a[la] < b[lb] ? a[la] : b[lb];
    }
    else
    {
        m1 = (la + ra) >> 1;      // ���� a ����λ��
        m2 = (lb + rb) >> 1;      // ���� b ����λ��

        // ��֤�����Ĳ��ֳ�����ͬ
        if (a[m1] == b[m2])     // ����λ�����ʱ���ظ���λ��
        {
            return a[m1];
        }
        else if (a[m1] < b[m2])
        {
            postPart(la, ra);  // a ȡ��벿��
            prePart(lb, rb);   // b ȡǰ�벿��
            return getMidNum(a, la, ra, b, lb, rb);
        }
        else
        {
            prePart(la, ra);    // a ȡǰ�벿��
            postPart(lb, rb);   // b ȡ��벿��
            return getMidNum(a, la, ra, b, lb, rb);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    cout << "��λ��Ϊ��" << getMidNum(a, 0, n - 1, b, 0, n - 1) << '\n';

    return 0;
}