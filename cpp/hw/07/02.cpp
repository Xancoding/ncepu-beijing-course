#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
    string name;
    int age;

    Student(string name, int age) {
        this->name = name;
        this->age = age;
    }

    bool operator>(const Student& other) const {
        return this->age > other.age;
    }
};

template <typename T>
T max_element(vector<T> arr) {
    T max_value = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    return max_value;
}

int main() {
    // ����ѧ����������
    vector<Student> students = {
            Student("����", 20),
            Student("����", 22),
            Student("����", 18),
            Student("����", 21),
    };

    // ʹ�ú���ģ�巵����������ѧ��
    Student max_age_student = max_element(students);
    cout << "��������ѧ����" << max_age_student.name << "�����䣺" << max_age_student.age << endl;

    return 0;
}
