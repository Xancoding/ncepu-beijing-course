/* FIFO���Ƚ��ȳ��㷨
 * ���ڽ�����פ��ʱ����õ�ҳ�滻�������
 *
 * LRU��������δʹ���û��㷨
 * ѡ�����һ��ʱ���δ�����ʵ�ҳ����̭���ڴ�
 */
/* ���룺
ҳ��������г��ȣ�
20
�ڴ�鳤�� && ҳ���ȣ�
5 8
 */
#include <list>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

/**
 * @brief ��ͷ��β������������ֵ
 *
 * @param page_in_block �ڴ��е�ҳ��
 * @param flag �Ƿ�ҳ
 */
void print_list(list<int>& page_in_block, bool flag, int page_num)
{
    cout << page_num << ":\t";
    for (auto item : page_in_block)
    {
        cout << item << ' ';
    }
    // �����ҳ��־
    if (flag)
    {
        cout << "��ҳ!!!";
    }

    cout << '\n';
}

void FIFO(int len, int block_size, vector<int>& page_access_sequence)
{
    int cnt{ 0 };  // ҳ���û�����
    list<int> page_in_block;
    cout << "FIFO�㷨ҳ���û����̣�\t��ͷ---��β\n";
    for (auto item : page_access_sequence)
    {
        // ҳ��Ԥװ��
        if (page_in_block.size() < block_size)
        {
            // ��ǰ���ʵ�ҳ�治���ڴ���
            if (find(page_in_block.begin(), page_in_block.end(), item) == page_in_block.end())
            {
                page_in_block.push_back(item);
            }
            print_list(page_in_block, false, item);
        }
        // Ԥװ�����
        else
        {
            auto it = find(page_in_block.begin(), page_in_block.end(), item);
            if (it == page_in_block.end())  // ��ǰ���ʵ�ҳ�治���ڴ���
            {
                ++cnt;
                page_in_block.pop_front();
                page_in_block.push_back(item);
                print_list(page_in_block, true, item);
            }
            print_list(page_in_block, false, item);
        }
    }

    cout << "FIFO�㷨ȱҳ�ʣ�" << (double)cnt / len * 100 << "%\n";
}

void LRU(int len, int block_size, vector<int>& page_access_sequence)
{
    int cnt{ 0 };  // ҳ���û�����
    list<int> page_in_block;
    cout << "LRU�㷨ҳ���û����̣�\tջ��---ջ��\n";
    for (auto item : page_access_sequence)
    {
        // ҳ��Ԥװ��
        if (page_in_block.size() < block_size)
        {
            auto it = find(page_in_block.begin(), page_in_block.end(), item);
            // ��ǰ���ʵ�ҳ�治���ڴ���
            if (it == page_in_block.end())
            {
                page_in_block.push_back(item);
            }
            // ��ǰ���ʵ�ҳ�����ڴ���
            else
            {
                page_in_block.erase(it);
                page_in_block.push_back(item);
            }
            print_list(page_in_block, false, item);
        }
        // Ԥװ�����
        else
        {
            auto it = find(page_in_block.begin(), page_in_block.end(), item);
            if (it == page_in_block.end())  // ��ǰ���ʵ�ҳ�治���ڴ���
            {
                ++cnt;
                page_in_block.pop_front();
                page_in_block.push_back(item);
                print_list(page_in_block, true, item);
            }
            else // ��ǰ���ʵ�ҳ�����ڴ���
            {
                page_in_block.erase(it);
                page_in_block.push_back(item);
                print_list(page_in_block, false, item);
            }
        }
    }

    cout << "LRU�㷨ȱҳ�ʣ�" << (double)cnt / len * 100 << "%\n";
}

int main()
{
    int len;
    cout << "ҳ��������г��ȣ�\n";
    cin >> len;

    int block_size, page_size;
    cout << "�ڴ�鳤�� && ҳ���ȣ�\n";
    cin >> block_size >> page_size;

//    vector<int> page_access_sequence{7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
//    vector<int> page_access_sequence{4, 2, 4, 2, 7, 2, 6, 2, 3,  4};
    vector<int> page_access_sequence;

    // ����һ�������������
    std::random_device rd; // ���ڻ�ȡ�������
    std::mt19937 gen(rd()); // ʹ��Mersenne Twister�㷨���������

    // ����һ���ֲ���ָ��������ķ�Χ
    std::uniform_int_distribution<> dis(0, page_size-1);

    for (int i = 0; i < len; ++i)
    {
        int random_num = dis(gen);
        page_access_sequence.push_back(random_num);
    }

    cout << "ҳ��������У�\n";
    for (auto item : page_access_sequence)
    {
        cout << item << ' ';
    }
    cout << '\n';

    FIFO(len, block_size,  page_access_sequence);
    LRU(len, block_size, page_access_sequence);

    return 0;
}