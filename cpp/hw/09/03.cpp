#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// ������������ͳ�Ƴ���Ϊ specific_length ����������
struct CountLength {
    int specific_length;
    CountLength(int length) : specific_length(length) {}

    bool operator()(const std::string& name) const {
        return name.length() == specific_length;
    }
};

// ������������ͳ�������а����ض��ַ���������
struct CountContains {
    std::string substring;
    CountContains(const std::string& str) : substring(str) {}

    bool operator()(const std::string& name) const {
        return name.find(substring) != std::string::npos;
    }
};

int main() {
    std::vector<std::string> names = {"����", "����", "����", "��ƽ", "���", "��С��"};

    // ʹ�� std::count_if �ͺ�������ͳ�Ƴ���Ϊ4����������
    int count2 = std::count_if(names.begin(), names.end(), CountLength(4));
    std::cout << "2�����ֵ�����: " << count2 << std::endl;

    // ʹ�� std::count_if �ͺ�������ͳ�Ƴ���Ϊ6����������
    int count3 = std::count_if(names.begin(), names.end(), CountLength(6));
    std::cout << "3�����ֵ�����: " << count3 << std::endl;

    // ʹ�� std::count �ͺ�������ͳ�ư���"��"����������
    int countContains = std::count_if(names.begin(), names.end(), CountContains("��"));
    std::cout << "���ִ���\"��\"������: " << countContains << std::endl;

    return 0;
}
