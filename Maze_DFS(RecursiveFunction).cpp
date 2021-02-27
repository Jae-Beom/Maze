/*****************************************************/
/*************** 미로에서 최단경로 찾기 **************/
/******************* 2021.01.01 **********************/
/***************** 만든이 : 공대생JB *****************/
/*****************************************************/


#include <iostream>

const int N = 10;           //미로 크기(주위에 두른 벽 포함)
const int path_other = 0;   //최단거리가 아닌경로 : 맵에 0로 기록
const int minimum_path = 2; //최단거리 경로 : 맵에 2로 기록

int count_move = 0;         //움직인 횟수 카운트
int minimum_move = 10000;   //최소 움직인 거리

int minimum_path_map[N][N] = { 0, };//복사할 맵

//주어진 미로
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

//최소경로 구해주는 함수 (출발지점 row, 출발지점 column, 카운트할 숫자 시작값, 도착지점 row, 도착지점 column)
void findPath(int x1, int y1, int count_move, int x2, int y2) {

	//도착지점 도착
	if (x1 == x2 && y1 == y2) {
		if (count_move < minimum_move) {
			//최소 움직임 기록
			minimum_move = count_move;

			//최소 경로 맵 기록
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					minimum_path_map[i][j] = map[i][j];
				}
			}

			//도착지점 표시
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

	//최단 경로 맵 출력
	printf("최단 경로는 다음과 같습니다.\n\n");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", minimum_path_map[i][j]);
		}
		printf("\n");
	}

	//최단 경로 맵 출력
	printf("\n********************\n");
	printf("  움직인 횟수 : %d ", minimum_move);
	printf("\n********************\n");

	return 0;
}
