/* ��ȫ���㷨��
 * ����ȫ��������а�ȫ����
 * 1. ��ʼ������
 * 2. ��������һ�����������
 *      1. Finish = false
 *      2. Need <= Work
 * �������ڣ������� 4 ��
 * 3. �� Work = Work + Allocation��Finish = true ʱ�������� 2 ��
 * 4. �����е� Finish = true����ôϵͳ���ڰ�ȫ״̬
 */
/* ��Դ�����㷨��
 * 1. Request <= Need�������� 2 �������򣬲�����������
 * 2. Request <= Aviable�������� 3 �������򣬲�����������
 * 3. ������Դ���ж���״̬�Ƿ�ȫ
 */

/* ����(����ȫ)��
����������Դ������:
2 2
������Դ����:
0 1
�������
0 0
0 0
����������
1 3
1 3
������Դ�Ľ��̱�ţ�
2
����������
0 1
 */

/* ����(��ȫ)��
����������Դ������:
5 4
������Դ����:
1 5 2 0
�������
0 0 1 2
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4
����������
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6
������Դ�Ľ��̱�ţ�
2
����������
0 4 2 0
 */
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Process {
public:
    int id{};  // ���̱��
    vector<int> allocation;  // �����ѷ������Դ��
    vector<int> max;  // ��������������Դ��
    vector<int> need;  // ���̻���Ҫ����Դ��
    bool finish{};  // �����Ƿ����
};

class System {
public:
    int n{};  // ������
    int m{};  // ��Դ������
    int number{};           // ������Դ�Ľ��̱��
    vector<int> request;    // ĳ�������������Դ��
    vector<int> available;  // ϵͳ���õ���Դ��
    vector<Process> processes;  // �����б�
    vector<int> work;  // ��������
    vector<int> work_tmp;  // �ݴ湤������
    vector<int> safe_sequence;  // ��ȫ����
    vector<vector<int>> all_safe_sequences;  // ���а�ȫ����

    // ��ӡ��ʼ���������
    void print_init()
    {
        for (int i = 0; i < n; ++i)
        {
            Process p = processes[i];

            cout << '\n' << "����" << p.id << "�ѷ������Դ����";
            for (int j = 0; j < m; ++j)
            {
                cout << p.allocation[j] << ' ';
            }

            cout << '\n' << "����" << p.id << "����������Դ����";
            for (int j = 0; j < m; ++j)
            {
                cout << p.max[j] << ' ';
            }

            cout << '\n' << "����" << p.id << "��Ҫ����Դ����";
            for (int j = 0; j < m; ++j)
            {
                cout << p.need[j] << ' ';
            }
            cout << '\n';
        }
    }

    // ��ʼ������
    void init() {
        cout << "Number of processes && Types of resources:" << endl;
        cin >> n >> m;
        cout << "Available resource vector:" << endl;
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            available.push_back(num);
        }

        cout << "Allocation matrix:\n";
        for (int i = 0; i < n; ++i) {
            auto* p = new Process;
            p->id = i + 1;
            for (int j = 0; j < m; ++j) {
                int num;
                cin >> num;
                p->allocation.push_back(num);
            }
            p->finish = false;
            processes.push_back(*p);
        }

        cout << "Max matrix:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int num;
                cin >> num;
                processes[i].max.push_back(num);

                assert(num - processes[i].allocation[j] >= 0 && "Need < 0!!!");
                processes[i].need.push_back(num - processes[i].allocation[j]);  // ���㻹��Ҫ����Դ��
            }
        }

        work = available;

//        print_init();
    }

    // ��ʼ������
    void init_request()
    {
        cout << "Request process number:\n";
        cin >> number;
        cout << "Request resource vector:\n";
        for (int i = 0; i < m; ++i)
        {
            int num;
            cin >> num;
            request.push_back(num);
        }

    }

    // �������Ƿ���������
    bool check(Process &p) {
        for (int i = 0; i < m; i++) {
            if (p.need[i] > work[i]) {
                return false;
            }
        }
        return true;
    }

    // ���¹�������
    void update_work(Process &p) {
        for (int i = 0; i < m; i++) {
            work[i] += p.allocation[i];
        }
    }

    // ���˹�������
    void remove_work(Process &p) {
        for (int i = 0; i < m; i++) {
            work[i] -= p.allocation[i];
        }
    }

    // ������Դ�������
    void update_resource(Process &p)
    {
        for (int i = 0; i < m; ++i)
        {
            available[i] -= request[i];
            p.allocation[i] += request[i];
            p.need[i] -= request[i];
        }
        work_tmp = work;
        work = available;
    }

    // ������Դ�������
    void remove_resource(Process &p)
    {
        for (int i = 0; i < m; ++i)
        {
            available[i] += request[i];
            p.allocation[i] -= request[i];
            p.need[i] += request[i];
        }
        work = work_tmp;
    }

    // ���Ұ�ȫ����
    void find_safe_sequence(int count) {
        for (int i = 0; i < n; i++) {
            Process &p = processes[i];
            if (!p.finish && check(p)) {
                p.finish = true;
                safe_sequence.push_back(p.id);
                update_work(p);
                if (count == n - 1) {
                    all_safe_sequences.push_back(safe_sequence);
                } else {
                    find_safe_sequence(count + 1);
                }
                p.finish = false;
                safe_sequence.pop_back();
                remove_work(p);
            }
        }
    }

    void print_all_safe_sequences() {
        if (all_safe_sequences.empty())
        {
            cout << "The system status is unsafe!!!\n";
            return;
        }

        cout << "Total safe sequences��" << all_safe_sequences.size() << '\n';
        cout << "All safe sequences:" << endl;
        for (auto seq : all_safe_sequences) {
            cout << "[" << seq[0];
            for (int j = 1; j < seq.size(); j++) {
                cout << ", " << seq[j];
            }
            cout << "]" << endl;
        }
    }

    void resource_request()
    {
        Process &p = processes[number - 1];
        for (int i = 0; i < m; ++i)
        {
            assert(request[i] <= p.need[i] && "Request > Need!!!");
            assert(request[i] <= available[i] && "Request > Avaiable, No resources available!!!");
        }

        update_resource(p);
        all_safe_sequences.clear();  // ������еİ�ȫ����
        find_safe_sequence(0);
        int length{ static_cast<int>(all_safe_sequences.size()) };
        if (length > 0)
        {
            cout << "Resources can be allocated immediately\n";
        }
        else
        {
            cout << "Resources can't' be allocated immediately!!!\n";
        }
        remove_resource(p);
    }
};

int main() {
    System system;
    system.init();
    system.find_safe_sequence(0);
    system.print_all_safe_sequences();

    system.init_request();
    system.resource_request();
    system.print_all_safe_sequences();
    return 0;
}