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
	}

	//F 2, B 0
	void rotateFB(int n, int cnt) {
		int n2 = n == 2 ? 0 : 2;

		for (int i = 0; i < cnt; i++) {
			vector<char> temp = cube_U[n];
			cube_U[n][0] = cube_L[2][n];
			cube_U[n][1] = cube_L[1][n];
			cube_U[n][2] = cube_L[0][n];

			cube_L[2][n] = cube_D[n2][0];
			cube_L[1][n] = cube_D[n2][1];
			cube_L[0][n] = cube_D[n2][2];

			cube_D[n2][0] = cube_R[2][n2];
			cube_D[n2][1] = cube_R[1][n2];
			cube_D[n2][2] = cube_R[0][n2];

			cube_R[0][n2] = temp[0];
			cube_R[1][n2] = temp[1];
			cube_R[2][n2] = temp[2];
		}
	}
	void rotateFB_reverse(int n, int cnt) {
		int n2 = n == 2 ? 0 : 2;

		for (int i = 0; i < cnt; i++) {
			vector<char> temp = cube_U[n];
			cube_U[n][0] = cube_R[0][n2];
			cube_U[n][1] = cube_R[1][n2];
			cube_U[n][2] = cube_R[2][n2];

			cube_R[0][n2] = cube_D[n2][2];
			cube_R[1][n2] = cube_D[n2][1];
			cube_R[2][n2] = cube_D[n2][0];

			cube_D[n2][2] = cube_L[2][n];
			cube_D[n2][1] = cube_L[1][n];
			cube_D[n2][0] = cube_L[0][n];

			cube_L[2][n] = temp[0];
			cube_L[1][n] = temp[1];
			cube_L[0][n] = temp[2];
		}
	}
	//U 0, D 2
	void rotateUD(int n, int cnt) {
		for (int i = 0; i < cnt; i++) {
			auto temp = cube_F[n];
			cube_F[n] = cube_R[n];
			cube_R[n] = cube_B[n];
			cube_B[n] = cube_L[n];
			cube_L[n] = temp;
		}
	}
	void rotateUD_reverse(int n, int cnt) {
		for (int i = 0; i < cnt; i++) {
			auto temp = cube_F[n];
			cube_F[n] = cube_L[n];
			cube_L[n] = cube_B[n];
			cube_B[n] = cube_R[n];
			cube_R[n] = temp;
		}
	}
	// L 0, R 2
	void rotateLR(int n, int cnt) {
		int n2 = n == 2 ? 0 : 2;

		for (int i = 0; i < cnt; i++) {
			tuple<char, char, char> t(cube_U[0][n], cube_U[1][n], cube_U[2][n]);
			cube_U[0][n] = cube_B[2][n2];
			cube_U[1][n] = cube_B[1][n2];
			cube_U[2][n] = cube_B[0][n2];

			cube_B[2][n2] = cube_D[0][n];
			cube_B[1][n2] = cube_D[1][n];
			cube_B[0][n2] = cube_D[2][n];

			cube_D[0][n] = cube_F[0][n];
			cube_D[1][n] = cube_F[1][n];
			cube_D[2][n] = cube_F[2][n];

			cube_F[0][n] = get<0>(t);
			cube_F[1][n] = get<1>(t);
			cube_F[2][n] = get<2>(t);
		}
	}
	void rotateLR_reverse(int n, int cnt) {
		int n2 = n == 2 ? 0 : 2;
		for (int i = 0; i < cnt; i++) {
			tuple<char, char, char> t(cube_U[0][n], cube_U[1][n], cube_U[2][n]);
			cube_U[0][n] = cube_F[0][n];
			cube_U[1][n] = cube_F[1][n];
			cube_U[2][n] = cube_F[2][n];

			cube_F[0][n] = cube_D[0][n];
			cube_F[1][n] = cube_D[1][n];
			cube_F[2][n] = cube_D[2][n];

			cube_D[0][n] = cube_B[2][n2];
			cube_D[1][n] = cube_B[1][n2];
			cube_D[2][n] = cube_B[0][n2];

			cube_B[2][n2] = get<0>(t);
			cube_B[1][n2] = get<1>(t);
			cube_B[0][n2] = get<2>(t);
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
					cube_F[j-1][i] != cube_F[j][i] ||
					cube_R[i][j - 1] != cube_R[i][j] ||
					cube_R[j - 1][i] != cube_R[j][i] ||
					cube_U[i][j - 1] != cube_U[i][j] ||
					cube_U[j - 1][i] != cube_U[j][i] ||
					cube_B[i][j - 1] != cube_B[i][j] ||
					cube_B[j - 1][i] != cube_B[j][i] ||
					cube_L[i][j - 1] != cube_L[i][j] ||
					cube_L[j - 1][i] != cube_L[j][i] ||
					cube_D[i][j - 1] != cube_D[i][j] ||
					cube_D[j - 1][i] != cube_D[j][i] )
					return false;
			}
		}

		return true;
	}

	void mixCube() {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(1, 10);
		
		for (int i = 0; i < 6; i++) {
			rotateFB(2, dis(gen));
			rotateLR_reverse(2, dis(gen));
			rotateUD(0, dis(gen));
			rotateFB_reverse(0, dis(gen));
			rotateLR(0, dis(gen));
			rotateUD_reverse(2, dis(gen));
		}
	}
};