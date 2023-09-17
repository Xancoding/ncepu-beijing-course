/* ���룺
 * ��һ������������N��V���ÿո�������ֱ��ʾ��Ʒ�����ͱ����ݻ���
 * �������� N �У�ÿ���������� vi,wi���ÿո�������ֱ��ʾ�� i ����Ʒ������ͼ�ֵ��
5 10
2 6
2 3
6 5
5 4
4 6
 */

/* �����
 * ѡȡ����Ʒ��1 2 5
 * �ܼ�ֵ��15
 */
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;           // ��Ʒ�����������ݻ�
int f[N][N];        // ǰ i ����Ʒ��ѡ�������ݻ�Ϊ j������ֵ
int w[N], v[N];     // ��Ʒ��ֵ����Ʒ���
int num[N];         // ��Ʒ i �Ƿ�ѡȡ

/*
 * ���ܣ����ѡ�����Ʒ
 */
void dispChoice()
{
    int k{ m };
    for (int i = n; i >= 1; --i)
    {
        if (f[i][k] == f[i - 1][k])
        {
            num[i] = 0;
        }
        else
        {
            num[i] = 1;
            k -= v[i];
        }
    }

    cout << "ѡȡ����Ʒ��";
    for (int i = 1; i <= n; ++i)
    {
        if (num[i])
        {
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
            {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }

        }

    dispChoice();

    cout << "�ܼ�ֵ��" << f[n][m] << '\n';

    return 0;
}
