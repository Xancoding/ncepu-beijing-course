#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ��ʼ������
    vector<int> queue = {1, 2, 3};

    // ģ��˿ͼ������
    cout << "��ʼ���У�" << endl;
    for (int i : queue) {
        cout << i << " ";
    }
    cout << endl;

    queue.push_back(4);
    queue.push_back(5);
    cout << "�˿ͼ����" << endl;
    for (int i : queue) {
        cout << i << " ";
    }
    cout << endl;

    // ģ��˿ͷ����Ŷ�
    cout << "�ڶ�λ�˿ͷ����Ŷӣ�" << endl;
    queue.erase(queue.begin() + 1);
    for (int i : queue) {
        cout << i << " ";
    }
    cout << endl;

    // ģ���������
    for (int i = 6; i <= 11; ++i) {
        queue.push_back(i);
    }
    cout << "����������" << endl;
    for (int i : queue) {
        cout << i << " ";
    }
    cout << endl;

    // ģ�⿪����ͨ����ת�ƹ˿�
    cout << "������ͨ����ת��ż��λ�˿ͣ�" << endl;
    vector<int> queue2;
    for (int i = 0; i < queue.size(); ++i) {
        if (i % 2 == 1) {
            queue2.push_back(queue[i]);
        }
    }
    for (int i : queue) {
        cout << i << " ";
    }
    cout << endl;
    cout << "��ͨ����" << endl;
    for (int i : queue2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
