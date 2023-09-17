/* ���룺
 * ��һ������������N��V���ÿո�������ֱ��ʾ��Ʒ�����ͱ����ݻ���
 * �������� N �У�ÿ���������� vi,wi���ÿո�������ֱ��ʾ�� i ����Ʒ������ͼ�ֵ��
3 7
3 4
4 5
2 3
 */

/* �����
 * ѡȡ����Ʒ��
 * ��Ʒ3��2��
 * ��Ʒ2��0��
 * ��Ʒ1��1��
 * �ܼ�ֵΪ��10
 */
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;           // ��Ʒ�����������ݻ�
int f[N][N];        // ǰ i ����Ʒ��ѡ�������ݻ�Ϊ j������ֵ
int w[N], v[N];     // ��Ʒ��ֵ����Ʒ���
int num[N][N];      // f[i][j] ȡ���ֵʱ��Ʒ i ѡȡ�ĸ���

/*
 * ���ܣ����ѡ�����Ʒ
 */
void dispChoice()
{
    int k{ m };
    cout << "ѡȡ����Ʒ��\n";
    for (int i = n; i >= 1; --i)
    {
        cout << "��Ʒ" << i << "��" << num[i][k] << "��\n";
        k -= num[i][k] * v[i];
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];


    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 0; k * v[i] <= j; ++k)  // ע��k �� 0 ��ʼȡ
            {
                if (f[i][j] <= f[i - 1][j - k * v[i]] + k * w[i])
                {
                    f[i][j] = f[i - 1][j - k * v[i]] + k * w[i];
                    num[i][j] = k;
                }

            }


    dispChoice();
    cout << "�ܼ�ֵΪ��" << f[n][m] << '\n';

    return 0;

}