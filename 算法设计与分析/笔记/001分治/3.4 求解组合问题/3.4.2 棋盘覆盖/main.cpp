/* ����������
 * ��һ�� 2^k * 2^k �����̣�ǡ����һ����������������ͬ����֮Ϊ���ⷽ��
 * ����Ҫ�� L �ι��Ƹ��ǳ������ⷽ�����������ȫ�����񣬹��ƿ���������ת�������κ��������Ʋ����ص�
 * �����һ�����Ƿ�����
 */
#include <iostream>
#include <vector>

using namespace std;

int label = 0;

void cover(vector<vector<int>>& board, int special, int tr, int tc, int dr, int dc, int size) {
    if (size == 1) {
        return;
    }
    label++;
    int s = size / 2;
    int offset = label * s * s;
    // ���ⷽ����������������
    if (dr < tr + s && dc < tc + s) {
        cover(board, special, tr, tc, dr, dc, s);
    }
    else {
        board[tr + s - 1][tc + s - 1] = offset + s + 1;
        cover(board, special, tr, tc, tr + s - 1, tc + s - 1, s);
    }
    // ���ⷽ����������������
    if (dr < tr + s && dc >= tc + s) {
        cover(board, special, tr, tc + s, dr, dc, s);
    }
    else {
        board[tr + s - 1][tc + s] = offset + 1;
        cover(board, special, tr, tc + s, tr + s - 1, tc + s, s);
    }
    // ���ⷽ����������������
    if (dr >= tr + s && dc < tc + s) {
        cover(board, special, tr + s, tc, dr, dc, s);
    }
    else {
        board[tr + s][tc + s - 1] = offset + 3;
        cover(board, special, tr + s, tc, tr + s, tc + s - 1, s);
    }
    // ���ⷽ����������������
    if (dr >= tr + s && dc >= tc + s) {
        cover(board, special, tr + s, tc + s, dr, dc, s);
    }
    else {
        board[tr + s][tc + s] = offset + 2;
        cover(board, special, tr + s, tc + s, tr + s, tc + s, s);
    }
}

int main() {
    int k = 3; // ���̴�СΪ 2^k * 2^k
    int n = 1 << k;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int special_row = 5; // ���ⷽ��������
    int special_col = 2; // ���ⷽ��������
    board[special_row][special_col] = -1;
    cover(board, -1, 0, 0, special_row, special_col, n);
    // �������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] < 0) {
                cout << "* ";
            }
            else {
                printf("%4d", board[i][j]);
            }
        }
        cout << endl;
    }
    return 0;
}
