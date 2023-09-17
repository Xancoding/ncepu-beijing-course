/* ����������
 * �����������ȷֱ�Ϊ N �� M ���ַ��� A �� B������� A ������������ B �������е��ַ���������Ƕ���
 */

/* ���룺
��һ�а����������� N �� M��
�ڶ��а���һ������Ϊ N ���ַ�������ʾ�ַ��� A��
�����а���һ������Ϊ M ���ַ�������ʾ�ַ��� B��
�ַ�������Сд��ĸ���ɡ�
6 9
abcbdb
acbbabdbb
 */

/* �����
����������У�acbdb
���ȣ�5
 */
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

const int N = 1010;

int n, m;
int f[N][N];    // a��b �д�ͷ��ʼ�ĳ��ȷֱ�Ϊ i��j �������е� LCS ����
char a[N], b[N];
stack<char> LCS;


/*
 * ���ܣ���� LCS
 */
void dispLCS()
{
    int k{ f[n][m] };
    int i{ n };
    int j{ m };
    while (k > 0)
    {
        if (f[i][j] == f[i - 1][j])
        {
            --i;
        }
        else if (f[i][j] == f[i][j - 1])
        {
            --j;
        }
        else
        {
            LCS.push(a[i]);
            --i;
            --j;
            --k;
        }
    }

    cout << "����������У�";
    for (int i = 1; i <= f[n][m]; ++i)
    {
        cout << LCS.top();
        LCS.pop();
    }

    cout << '\n';
}

int main() {
    cin >> n >> m;

    scanf("%s%s", a + 1, b + 1);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);                         // a[i] != b[j]
            if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);   // a[i] = b[j]
        }

    dispLCS();
    cout << "���ȣ�" << f[n][m] << endl;

    return 0;
}