#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // ��Ҫ���Ƶ�Դ�ļ�
    ifstream source_file("source.jpg", ios::binary);
    if (!source_file) {
        cerr << "�޷���Դ�ļ�" << endl;
        return 1;
    }

    // ����Ŀ���ļ�
    ofstream target_file("copy.jpg", ios::binary);
    if (!target_file) {
        cerr << "�޷�����Ŀ���ļ�" << endl;
        return 1;
    }

    // ��ȡԴ�ļ����ݲ�д��Ŀ���ļ�
    vector<char> buffer(1024);
    while (!source_file.eof()) {
        source_file.read(buffer.data(), buffer.size());
        target_file.write(buffer.data(), source_file.gcount());
    }

    source_file.close();
    target_file.close();

    cout << "�ļ����Ƴɹ�" << endl;

    return 0;
}