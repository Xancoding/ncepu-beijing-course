/* ����������
����һ���� n �����������У��������������������еĺ�
 */
/* ���룺
 * ��һ������������N����ʾ���г��ȡ�
 * �������� 1 �У�N ��������
6
-2 11 -4 13 -5 -2
 */

/* �����
��ѡ�����У�11 -4 13
������������к�Ϊ��20
 */
#include <iostream>

using namespace std;

const int N = 1010;

int n;         // ���г���
int a[N];
int f[N];      // �� a[i] Ϊ��β��������������к�
int resIndex;  // ��������к͵����һ���������±�
/*
 * ���ܣ����ѡ���������
 */
void dispChoice()
{
    // �ҵ��������������

    for (int i = 1; i <= n; ++i)
    {
        if (f[i] >= f[resIndex])
        {
            resIndex = i;
        }
    }

    // �ҵ�ǰһ��С�ڵ��� 0 ��
    // �� f[i] <= 0����f[i + 1] - a[i]
    // �� a[i] �������������������
    int k{ 1 };
    for (int i = resIndex; i >= 1; --i)
    {
        if (f[i] <= 0)
        {
            k = i;
            break;
        }
    }

    cout << "��ѡ�����У�";
    for (int i = k + 1; i <= resIndex; ++i)
        cout << a[i] << ' ';

    cout << '\n';
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> a[i];


    for (int i = 1; i <= n; ++i)
    {
        f[i] = max(a[i], f[i - 1] + a[i]);
    }

    dispChoice();

    cout << "������������к�Ϊ��" << f[resIndex] << '\n';

    return 0;
}
