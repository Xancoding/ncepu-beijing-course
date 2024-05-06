#include <iostream>
#include <vector>

using namespace std;

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
    // ���� int ����
    vector<int> int_arr = {1, 5, 3, 2, 4};
    int max_int = max_element(int_arr);
    cout << "��� int Ԫ�أ�" << max_int << endl;

    // ���� double ����
    vector<double> double_arr = {1.2, 5.6, 3.1, 2.7, 4.9};
    double max_double = max_element(double_arr);
    cout << "��� double Ԫ�أ�" << max_double << endl;

    return 0;
}
