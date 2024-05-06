#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int score;

    // ���캯��
    Student(string name, int score) {
        this->name = name;
        this->score = score;
    }

    // ��ֵ���������
    Student& operator=(const Student& other) {
        // ��������
        // this->name = other.name; // ע�͵����д��룬ʵ��ֻ�гɼ��仯
        this->score = other.score;
        return *this;
    }

    // ��Ԫ������ʵ��cout<<ѧ������
    friend ostream& operator<<(ostream& os, const Student& stu) {
        os << "������" << stu.name << ", �ɼ���" << stu.score;
        return os;
    }

    // ��������أ��Գɼ��ж�����ѧ���Ƿ����
    bool operator==(const Student& other) const {
        return this->score == other.score;
    }
};

int main() {
    Student stu1("����", 90);
    Student stu2("����", 80);

    // ���Ը�ֵ�����
    stu1 = stu2;
    cout << stu1 << endl; // ���������������, �ɼ���80

    // ����cout<<ѧ������
    cout << stu2 << endl; // ���������������, �ɼ���80

    // �������������
    if (stu1 == stu2) {
        cout << "����ѧ���ɼ���ͬ" << endl;
    } else {
        cout << "����ѧ���ɼ���ͬ" << endl;
    }

    return 0;
}
