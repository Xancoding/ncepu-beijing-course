/* ����������
 * ������һ����Ҫʹ��ĳһ��Դ���� n �����ɵļ��� S������Դ���κ�ʱ��ֻ�ܱ�һ�����ռ��
 * � i ��һ����ʼʱ�� b �ͽ��� e����ִ��ʱ��Ϊ e - b����������ִ��ʱ��Ϊ 0.һ��ĳ�����ʼִ�У��Ͳ��ܱ���ϣ�ֱ����ִ����ϡ�
 * ����㷨��һ�����л���ŷ�����ʹ�����а��ŵĻ�������
 */

/* ���˼·��
 * �����������̰���㷨����������˼����ÿ��ѡ�����ʱ������Ļ���Ա�Ϊ�����Ļ���¸����ʱ�䡣
 */

/* ���룺
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 15
 */

/* �����
ѡȡ�Ļ��
[1, 4][5, 7][8, 11][12, 15]
��4���
 */
#include <iostream>

using namespace std;

const int N = 1010;

int n;         // n ���
int cnt;       // ѡȡ�ļ��ݻ�ĸ���
bool flag[N];  // ���ѡ��Ļ

struct Action
{
    int st;    // ���ʼʱ��
    int ed;    // �����ʱ��
    bool operator<(const Action& s) const
    {
        return ed <= s.ed;
    }
};

int main()
{
    cout << "�����n��\n";
    cin >> n;

    Action action[n];
    cout << "� ��ʼʱ�� ����ʱ�䣨�ո��������\n";
    for (int i = 0; i < n; ++i) cin >> action[i].st >> action[i].ed;
    sort(action, action + n);  // �������ʱ���������

    int preEnd{ 0 };                        // ǰһ�����ݻ����ʱ��
    for (int i = 0; i < n; ++i)
    {
        if (action[i].st >= preEnd)
        {
            flag[i] = true;
            preEnd = action[i].ed;
        }
    }

    cout << "ѡȡ�Ļ��\n";
    for (int i = 0; i < n; ++i)
    {
        if (flag[i])
        {
            printf("[%d, %d]", action[i].st, action[i].ed);
            ++cnt;
        }
    }
    printf("\n��%d���\n", cnt);

    return 0;
}