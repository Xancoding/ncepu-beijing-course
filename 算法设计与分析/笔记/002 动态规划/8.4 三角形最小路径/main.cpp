/* ����������
 * �����߶�Ϊ n ��һ�����������Σ��ҳ��Ӷ������ײ�����С·����
 * ע���ÿ����������ֻ�������ƶ������ڵ�����
 * �������� n���������� 1~n �У��� i ������ i ������
 * �����Ϊ���У��� 1 ��Ϊ��С·������ 2 ��Ϊ��С·����
 */

/* ���룺
4
2
3 4
6 5 7
8 3 9 2
 */

/* �����
·���ǣ�2 3 5 3
��С·����Ϊ��13
 */
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

const int N = 510;
const int INF = 1e9;

int n;
int a[N][N];
int f[N][N];     // �߶�Ϊ i��·���ײ�Ϊ a[i][j] ����С·����
int pre[N][N];   // �߶�Ϊ i��·���ײ�Ϊ a[i][j] ����С·����ǰ������±�
int res{ INF };  // ��С·����
int cur{};       // �ײ�����±�

/*
 * ���ܣ����������С·��
 */
void dispPath()
{
    cout << "·���ǣ�";

    stack<int>path{};
    for (int i = n; i >= 1; --i)
    {
        path.push(a[i][cur]);
        cur = pre[i][cur];
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << '\n';
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            cin >> a[i][j];

    memset(f, 0x3f ,sizeof(f));

    f[1][1] = a[1][1];
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
        {
            if (f[i - 1][j] <= f[i - 1][j - 1])
            {
                f[i][j] = f[i - 1][j] + a[i][j];
                pre[i][j] = j;
            }
            else
            {
                f[i][j] = f[i - 1][j - 1] + a[i][j];
                pre[i][j] = j - 1;
            }
        }

    // �ҵ���С·��
    for (int i = 1; i <= n; ++i)
    {
        if (res >= f[n][i])
        {
            res = f[n][i];
            cur = i;
        }
    }

    dispPath();
    cout << "��С·����Ϊ��" << res << '\n';

    return 0;
}
