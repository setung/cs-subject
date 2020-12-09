#pragma once
#include "header.h"

class Cube {
private:
	vector<vector<char>> cube_F;
	vector<vector<char>> cube_R;
	vector<vector<char>> cube_U;
	vector<vector<char>> cube_B;
	vector<vector<char>> cube_L;
	vector<vector<char>> cube_D;
	vector<vector<vector<char>>*> cube_A;
public:
	Cube() {
		init();
	}

	void init() {
		cube_F = { {'O','O','O'}, {'O','O','O'}, {'O','O','O'} };
		cube_R = { {'G','G','G'}, {'G','G','G'}, {'G','G','G'} };
		cube_U = { {'B','B','B'}, {'B','B','B'}, {'B','B','B'} };
		cube_B = { {'Y','Y','Y'}, {'Y','Y','Y'}, {'Y','Y','Y'} };
		cube_L = { {'W','W','W'}, {'W','W','W'}, {'W','W','W'} };
		cube_D = { {'R','R','R'}, {'R','R','R'}, {'R','R','R'} };

		cube_A.push_back(&cube_U);
		cube_A.push_back(&cube_L);
		cube_A.push_back(&cube_F);
		cube_A.push_back(&cube_R);
		cube_A.push_back(&cube_B);
		cube_A.push_back(&cube_D);
	}

	void test() {
		printCube();
		cout << isFitted() << '\n';
		rotateR(0, 1);
		cout << isFitted() << '\n';
		rotateL(1, 1);
		printCube();
		cout << isFitted() << '\n';
	}

	void rotateF(bool reverse, int n) {
		for (int i = 0; i < n; i++) {
			if (!reverse) {
				vector<char> temp = cube_U[2];
				cube_U[2][0] = cube_L[2][2];
				cube_U[2][1] = cube_L[1][2];
				cube_U[2][2] = cube_L[0][2];

				cube_L[2][2] = cube_D[0][0];
				cube_L[1][2] = cube_D[0][1];
				cube_L[0][2] = cube_D[0][2];

				cube_D[0][0] = cube_R[2][0];
				cube_D[0][1] = cube_R[1][0];
				cube_D[0][2] = cube_R[0][0];

				cube_R[0][0] = temp[0];
				cube_R[1][0] = temp[1];
				cube_R[2][0] = temp[2];
			}
			else {
				vector<char> temp = cube_U[2];
				cube_U[2][0] = cube_R[0][0];
				cube_U[2][1] = cube_R[1][0];
				cube_U[2][2] = cube_R[2][0];

				cube_R[0][0] = cube_D[0][2];
				cube_R[1][0] = cube_D[0][1];
				cube_R[2][0] = cube_D[0][0];

				cube_D[0][2] = cube_L[2][2];
				cube_D[0][1] = cube_L[1][2];
				cube_D[0][0] = cube_L[0][2];

				cube_L[2][2] = temp[0];
				cube_L[1][2] = temp[1];
				cube_L[0][2] = temp[2];
			}
		}
	}
	void rotateR(bool reverse, int n) {
		for (int i = 0; i < n; i++) {
			if (!reverse) {
				tuple<char, char, char> t(cube_U[0][2], cube_U[1][2], cube_U[2][2]);
				cube_U[0][2] = cube_F[0][2];
				cube_U[1][2] = cube_F[1][2];
				cube_U[2][2] = cube_F[2][2];

				cube_F[0][2] = cube_D[0][2];
				cube_F[1][2] = cube_D[1][2];
				cube_F[2][2] = cube_D[2][2];

				cube_D[0][2] = cube_B[2][0];
				cube_D[1][2] = cube_B[1][0];
				cube_D[2][2] = cube_B[0][0];

				cube_B[2][0] = get<0>(t);
				cube_B[1][0] = get<1>(t);
				cube_B[0][0] = get<2>(t);
			}
			else {
				tuple<char, char, char> t(cube_U[0][2], cube_U[1][2], cube_U[2][2]);
				cube_U[0][2] = cube_B[2][0];
				cube_U[1][2] = cube_B[1][0];
				cube_U[2][2] = cube_B[0][0];

				cube_B[2][0] = cube_D[0][2];
				cube_B[1][0] = cube_D[1][2];
				cube_B[0][0] = cube_D[2][2];

				cube_D[0][2] = cube_F[0][2];
				cube_D[1][2] = cube_F[1][2];
				cube_D[2][2] = cube_F[2][2];

				cube_F[0][2] = get<0>(t);
				cube_F[1][2] = get<1>(t);
				cube_F[2][2] = get<2>(t);
			}
		}
	}
	void rotateU(bool reverse, int n) {
		for (int i = 0; i < n; i++) {
			if (!reverse) {
				auto temp = cube_F[0];
				cube_F[0] = cube_R[0];
				cube_R[0] = cube_B[0];
				cube_B[0] = cube_L[0];
				cube_L[0] = temp;
			}
			else {
				auto temp = cube_F[0];
				cube_F[0] = cube_L[0];
				cube_L[0] = cube_B[0];
				cube_B[0] = cube_R[0];
				cube_R[0] = temp;
			}
		}
	}
	void rotateB(bool reverse, int n) {
		for (int i = 0; i < n; i++) {
			if (!reverse) {
				vector<char> temp = cube_U[0];
				cube_U[0][0] = cube_R[0][2];
				cube_U[0][1] = cube_R[1][2];
				cube_U[0][2] = cube_R[2][2];

				cube_R[0][2] = cube_D[2][2];
				cube_R[1][2] = cube_D[2][1];
				cube_R[2][2] = cube_D[2][0];

				cube_D[2][2] = cube_L[2][0];
				cube_D[2][1] = cube_L[1][0];
				cube_D[2][0] = cube_L[0][0];

				cube_L[2][0] = temp[0];
				cube_L[1][0] = temp[1];
				cube_L[0][0] = temp[2];
			}
			else {
				vector<char> temp = cube_U[0];
				cube_U[0][0] = cube_L[2][0];
				cube_U[0][1] = cube_L[1][0];
				cube_U[0][2] = cube_L[0][0];

				cube_L[2][0] = cube_D[2][0];
				cube_L[1][0] = cube_D[2][1];
				cube_L[0][0] = cube_D[2][2];

				cube_D[2][0] = cube_R[2][2];
				cube_D[2][1] = cube_R[1][2];
				cube_D[2][2] = cube_R[0][2];

				cube_R[0][2] = temp[0];
				cube_R[1][2] = temp[1];
				cube_R[2][2] = temp[2];
			}
		}
	}
	void rotateL(bool reverse, int n) {
		for (int i = 0; i < n; i++) {
			if (!reverse) {
				tuple<char, char, char> t(cube_U[0][0], cube_U[1][0], cube_U[2][0]);
				cube_U[0][0] = cube_B[2][2];
				cube_U[1][0] = cube_B[1][2];
				cube_U[2][0] = cube_B[0][2];

				cube_B[2][2] = cube_D[0][0];
				cube_B[1][2] = cube_D[1][0];
				cube_B[0][2] = cube_D[2][0];

				cube_D[0][0] = cube_F[0][0];
				cube_D[1][0] = cube_F[1][0];
				cube_D[2][0] = cube_F[2][0];

				cube_F[0][0] = get<0>(t);
				cube_F[1][0] = get<1>(t);
				cube_F[2][0] = get<2>(t);
			}
			else {
				tuple<char, char, char> t(cube_U[0][0], cube_U[1][0], cube_U[2][0]);
				cube_U[0][0] = cube_F[0][0];
				cube_U[1][0] = cube_F[1][0];
				cube_U[2][0] = cube_F[2][0];

				cube_F[0][0] = cube_D[0][0];
				cube_F[1][0] = cube_D[1][0];
				cube_F[2][0] = cube_D[2][0];

				cube_D[0][0] = cube_B[2][2];
				cube_D[1][0] = cube_B[1][2];
				cube_D[2][0] = cube_B[0][2];

				cube_B[2][2] = get<0>(t);
				cube_B[1][2] = get<1>(t);
				cube_B[0][2] = get<2>(t);
			}
		}
	}
	void rotateD(bool reverse, int n) {
		for (int i = 0; i < n; i++) {
			if (!reverse) {
				auto temp = cube_F[2];
				cube_F[2] = cube_L[2];
				cube_L[2] = cube_B[2];
				cube_B[2] = cube_R[2];
				cube_R[2] = temp;
			}
			else {
				auto temp = cube_F[2];
				cube_F[2] = cube_R[2];
				cube_R[2] = cube_B[2];
				cube_B[2] = cube_L[2];
				cube_L[2] = temp;
			}
		}
	}

	void printCube() {
		for (auto arr : cube_U) {
			for (char c : arr)
				cout << c << ' ';
			cout << '\n';
		}
		cout << "\n";

		for (int i = 0; i < 3; i++)
			cout << cube_L[0][i] << ' ';
		cout << "   ";
		for (int i = 0; i < 3; i++)
			cout << cube_F[0][i] << ' ';
		cout << "   ";
		for (int i = 0; i < 3; i++)
			cout << cube_R[0][i] << ' ';
		cout << "   ";
		for (int i = 0; i < 3; i++)
			cout << cube_B[0][i] << ' ';
		cout << '\n';
		for (int i = 0; i < 3; i++)
			cout << cube_L[1][i] << ' ';
		cout << "   ";
		for (int i = 0; i < 3; i++)
			cout << cube_F[1][i] << ' ';
		cout << "   ";
		for (int i = 0; i < 3; i++)
			cout << cube_R[1][i] << ' ';
		cout << "   ";
		for (int i = 0; i < 3; i++)
			cout << cube_B[1][i] << ' ';
		cout << '\n';
		for (int i = 0; i < 3; i++)
			cout << cube_L[2][i] << ' ';
		cout << "   ";
		for (int i = 0; i < 3; i++)
			cout << cube_F[2][i] << ' ';
		cout << "   ";
		for (int i = 0; i < 3; i++)
			cout << cube_R[2][i] << ' ';
		cout << "   ";
		for (int i = 0; i < 3; i++)
			cout << cube_B[2][i] << ' ';
		cout << "\n\n";
		for (auto arr : cube_D) {
			for (char c : arr)
				cout << c << ' ';
			cout << '\n';
		}
		cout << "\n\n";

	}

	bool isFitted() {
		for (int i = 0; i < 3; i++) {
			for (int j = 1; j < 3; j++) {
				if (cube_F[i][j - 1] != cube_F[i][j] ||
					cube_R[i][j - 1] != cube_R[i][j] ||
					cube_U[i][j - 1] != cube_U[i][j] ||
					cube_B[i][j - 1] != cube_B[i][j] ||
					cube_L[i][j - 1] != cube_L[i][j] ||
					cube_D[i][j - 1] != cube_D[i][j] )
					return false;
			}
		}

		return true;
	}

	void mixCube() {

	}
};