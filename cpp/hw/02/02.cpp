#include <iostream>
#include <cstring>

class Country {
private:
    char* name;
    double area;

public:
    // Ĭ�Ϲ��캯��
    Country(const char* n, double a) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        area = a;
        std::cout << name << "���캯��" << std::endl;
    }

    // �������캯��
    Country(const Country& c) {
        name = new char[strlen(c.name) + 1];
        strcpy(name, c.name);
        area = c.area;
        std::cout << c.name << "�������캯��" << std::endl;
    }

    // ��������
    ~Country() {
        std::cout << name << "��������" << std::endl;
        delete[] name;
    }

    const char* getName() const {
        return name;
    }

    double getArea() const {
        return area;
    }

    // ��ʾ��Ϣ
    void display() const {
        std::cout << "���ң�" << name << " �����" << area << std::endl;
    }

    // �ȽϹ������
    std::string compareArea(const Country& c) const {
        if (area > c.area) {
            return ">";
        } else if (area < c.area) {
            return "<";
        } else {
            return "=";
        }
    }
};

int main() {
    // ����
    Country c1("China", 960.0);
    Country c2(c1);
    Country c3("USA", 937.0);

    c1.display();
    c2.display();
    c3.display();

    std::cout << c1.getName() << c1.compareArea(c2) << c2.getName() << std::endl;
    std::cout << c1.getName() << c1.compareArea(c3) << c3.getName() << std::endl;

    return 0;
}