/* ����������
 * ����һ��������������У�����������������еĳ���
 */

/* ���룺
��һ�а����������� N��
�ڶ��а��� N ��������
9
2 1 5 3 6 4 8 9 7
 */

/* �������Ψһ����
�����������У�2 5 6 8 9
����������еĳ��ȣ�5
 */
#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N];    // �� a[i] ��β������������еĳ���
int pre[N];  // �� a[i] ��β������������е�ǰ�������±�
int res{};   // ����������еĳ���
int cur{};   // ����������е����һ�������±�
stack<int>LIS;

/*
 * ���ܣ����LIS
 */
void dispLIS()
{

    for (int i = 1; i <= res; ++i)
    {
        LIS.push(a[cur]);
        cur = pre[cur];
    }
    cout << "�����������У�";
    for (int i = 1; i <= res; ++i)
    {
        cout << LIS.top() << ' ';
        LIS.pop();
    }
    cout << '\n';
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // ��ʼ��
    for (int i = 1; i <= n; ++i)
    {
        f[i] = 1;
        pre[i] = i;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
        {
            if (a[i] > a[j] && f[i] < f[j] + 1)
            {
                f[i] = f[j] + 1;
                pre[i] = j;
            }
        }

    for (int i = 1; i <= n; ++i)
    {
        if (res <= f[i])
        {
            res = f[i];
            cur = i;
        }
    }

    dispLIS();
    cout << "����������еĳ��ȣ�" << res << '\n';
}


