/*****************************************************/
/*************** �̷ο��� �ִܰ�� ã�� **************/
/******************* 2021.01.01 **********************/
/***************** ������ : �����JB *****************/
/*****************************************************/


#include <iostream>

const int N = 10;           //�̷� ũ��(������ �θ� �� ����)
const int path_other = 0;   //�ִܰŸ��� �ƴѰ�� : �ʿ� 0�� ���
const int minimum_path = 2; //�ִܰŸ� ��� : �ʿ� 2�� ���

int count_move = 0;         //������ Ƚ�� ī��Ʈ
int minimum_move = 10000;   //�ּ� ������ �Ÿ�

int minimum_path_map[N][N] = { 0, };//������ ��

//�־��� �̷�
int map[N][N] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
	{1, 0, 1, 1, 1, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

//�ּҰ�� �����ִ� �Լ� (������� row, ������� column, ī��Ʈ�� ���� ���۰�, �������� row, �������� column)
void findPath(int x1, int y1, int count_move, int x2, int y2) {

	//�������� ����
	if (x1 == x2 && y1 == y2) {
		if (count_move < minimum_move) {
			//�ּ� ������ ���
			minimum_move = count_move;

			//�ּ� ��� �� ���
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					minimum_path_map[i][j] = map[i][j];
				}
			}

			//�������� ǥ��
			minimum_path_map[x2][y2] = minimum_path;
		}
	}
	else {
		map[x1][y1] = minimum_path;

		//left
		if (map[x1][y1 - 1] == path_other) {
			findPath(x1, y1 - 1, count_move + 1, x2, y2);
		}

		//up
		if (map[x1 - 1][y1] == path_other) {
			findPath(x1 - 1, y1, count_move + 1, x2, y2);
		}

		//right
		if (map[x1][y1 + 1] == path_other) {
			findPath(x1, y1 + 1, count_move + 1, x2, y2);
		}

		//down
		if (map[x1 + 1][y1] == path_other) {
			findPath(x1 + 1, y1, count_move + 1, x2, y2);
		}

		map[x1][y1] = path_other;
	}
}


int main() {

	findPath(N - 2, 1, count_move, 1, N - 2);

	//�ִ� ��� �� ���
	printf("�ִ� ��δ� ������ �����ϴ�.\n\n");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", minimum_path_map[i][j]);
		}
		printf("\n");
	}

	//�ִ� ��� �� ���
	printf("\n********************\n");
	printf("  ������ Ƚ�� : %d ", minimum_move);
	printf("\n********************\n");

	return 0;
}
