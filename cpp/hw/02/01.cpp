//
// Created by 24398 on 2024/3/6.
//
#include "iostream"

class Rectangle {
private:
    double width;
    double height;

public:
    // Ĭ�Ϲ��캯��
    Rectangle(double w, double h) {
        width = w;
        height = h;
        std::cout << "���캯��" << std::endl;
    }

    // �������캯��
    Rectangle(const Rectangle &r) {
        width = r.width;
        height = r.height;
        std::cout << "�������캯��" << std::endl;
    }

    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return 2 * (width + height);
    }

    void setWidth(double w) {
        width = w;
    }

    void setHeight(double h) {
        height = h;
    }

    double getWidth() {
        return width;
    }

    double getHeight() {
        return height;
    }

    bool isSquare() {
        return width == height;
    }
};

int main() {
    // ����
    Rectangle r1(3, 4);
    Rectangle r2(r1);
    Rectangle r3(3, 3);

    std::cout << "�����" << r1.getArea() << " " << "�ܳ���" << r1.getPerimeter() << std::endl;

    std::cout << "�����" << r2.getArea() << " " << "�ܳ���" << r2.getPerimeter() << std::endl;

    std::cout << "�Ƿ�Ϊ�����Σ�" << r3.isSquare() << std::endl;
    std::cout << "�Ƿ�Ϊ�����Σ�" << r1.isSquare() << std::endl;

    return 0;
}