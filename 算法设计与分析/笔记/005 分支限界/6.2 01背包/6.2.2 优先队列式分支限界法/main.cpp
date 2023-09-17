#include <iostream>
#include <queue>
using namespace std;
const int N = 20, INF = 0x3f3f3f3f;

// �����ʾ
int n{ 3 }, m { 30 };
int v[] = { 0, 16, 15, 15 };  // ������±�Ϊ 0 ��Ԫ�ز�ʹ��
int w[] = { 0, 45, 25, 25 };  // ��ֵ���±�Ϊ 0 ��Ԫ�ز�ʹ��

int maxw = -INF;  // ����ֵ
int bestx[N];     // ���Ž�����
int tot{ 1 };     // �������еĽ�����ۼ�

struct NodeType
{
    int number{};  // �����
    int level{};   // ��ǰ����������ռ��еĲ��
    int v{};       // ��ǰ���������
    int w{};       // ��ǰ�����ܼ�ֵ
    int x[N];      // ��ǰ�������Ľ�����
    double ub{};   // �Ͻ�

    bool operator<(const NodeType& other) const {
        return ub < other.ub;
    }
};

// �����֧��� e ���Ͻ�
void bound(NodeType& e)
{
    int level{ e.level+1 };
    int sumv = e.v;     // ���
    double sumw = e.w;  // ��ֵ
    while ((sumv + v[level]) <= m && level <= n)
    {
        sumv += v[level];    // ��װ�����
        sumw += w[level];    // ��װ���ֵ
        ++level;
    }
    
    if (level <= n)
        e.ub = sumw + (m - sumv) * w[level] / v[level];
    else 
        e.ub = sumw;
}

// ��� e ����
void enQueue(NodeType e, priority_queue<NodeType>& qu)
{
    // Ҷ���
    if (e.level == n)
    {
        // �ҵ������ֵ�Ľ��
        if (e.w > maxw)
        {
            maxw = e.w;
            for (int i = 1; i <= n; ++i)
            {
                bestx[i] = e.x[i];
            }
        }
    }
    else 
        qu.push(e);
}

// ��� 01 �������Ž�
void bfs()
{
    NodeType e, e1, e2;           // ���� 3 �����
    priority_queue<NodeType> qu;  // �����
    e.level = 0;                  // ���ڵ㸳��ֵ����μ�Ϊ 0
    e.w = 0, e.v = 0;
    e.number = tot++;

    for (int i = 1; i <= n; ++i) e.x[i] = 0;

    bound(e);        // ����ڵ��Ͻ�
    qu.push(e);  // ���ڵ����

    while (!qu.empty())
    {
        e = qu.top();  qu.pop();
        // ���֦
        if (e.v + v[e.level+1] <= m)
        {
            // �������ӽ��
            e1.number = tot++;
            e1.level = e.level+1;
            e1.v = e.v + v[e1.level];
            e1.w = e.w + w[e1.level];

            // ���ƽ�����
            for (int i = 1; i <= n; ++i) e1.x[i] = e.x[i];
            e1.x[e1.level] = 1;
            bound(e1);           // ���Ͻ�
            enQueue(e1, qu);  // ���
        }
        // �����Һ��ӽ��
        e2.number = tot++;
        e2.level = e.level+1;
        e2.v = e.v;
        e2.w = e.w;

        // ���ƽ�����
        for (int i = 1; i <= n; ++i) e2.x[i] = e.x[i];
        e2.x[e2.level] = 0;

        bound(e2);           // ���Ͻ�

        // �Ҽ�֦
        if (e2.ub > maxw) enQueue(e2, qu);  // ���
    }
}

int main()
{
    bfs();
    cout << "��֧���޷���\n X=[ ";
    for (int i = 1; i <= n; ++i) cout << bestx[i] << ' ';
    cout << "],װ���ܼ�ֵΪ" << maxw << '\n';

    return 0;
}

