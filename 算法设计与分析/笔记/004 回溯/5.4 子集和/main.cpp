/* ���룺
4 31
11 13 24 7
 */

/* �����
�� 1 ����ѡȡ����Ϊ��
11 13 7
�� 2 ����ѡȡ����Ϊ��
24 7
 */

#include <iostream>
using namespace std;
const int N = 1010;

int n, m;
int a[N];  // ����
int cnt;   // ��ĸ���

void dispOption(int op[])
{
    ++cnt;
    cout << "�� " << cnt << " ����ѡȡ����Ϊ��\n";
    for (int i = 1; i <= n; ++i)
    {
        if (op[i])
        {
            cout << a[i] << ' ';
        }
    }
    cout << '\n';
}

/* �������ݹ��������ǰ�����͡��ò㼰���µ����������͡�������
 */
void dfs(int i, int cw, int rw, int op[])
{
    // �ݹ����
    if (i > n)
    {
        if (cw == m)
        {
            dispOption(op);
        }
    }
    else
    {
        if (cw + a[i] <= m)  // ���֦
        {
            op[i] = 1;
            dfs(i + 1, cw + a[i], rw - a[i], op);
        }
        if (cw + rw - a[i] >= m)  // �Ҽ�֦
        {
            op[i] = 0;
            dfs(i + 1, cw, rw - a[i], op);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int rw{ 0 };    // ����������
    for (int i = 1; i <= n; ++i) rw += a[i];

    int op[N];  // ������
    dfs(1, 0, rw, op);

    return 0;
}