//
// Created by 24398 on 2024/4/11.
//
#include <iostream>
#include <map>

using namespace std;

int main() {
    // ����map����
    map<string, string> id_name;

    // �������
    id_name["1234567890"] = "����";
    id_name["9876543210"] = "����";
    id_name["0123456789"] = "����";

    // ��ѯ����
    cout << "���������֤���룺" << id_name["1234567890"] << endl;

    // �޸�����
    id_name["9876543210"] = "���";
    cout << "�޸ĺ����ĵ�������" << id_name["9876543210"] << endl;

    // ɾ������
    id_name.erase("0123456789");

    // ��������
    for (auto it = id_name.begin(); it != id_name.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
