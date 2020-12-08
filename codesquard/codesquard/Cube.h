#pragma once
#include "header.h"

class Cube {
	vector<vector<char>> cube_F;
	vector<vector<char>> cube_R;
	vector<vector<char>> cube_U;
	vector<vector<char>> cube_B;
	vector<vector<char>> cube_L;
	vector<vector<char>> cube_D;

	void init() {
		cube_F = { {'O','O','O'}, {'O','O','O'}, {'O','O','O'} };
		cube_R = { {'G','G','G'}, {'G','G','G'}, {'G','G','G'} };
		cube_U = { {'B','B','B'}, {'B','B','B'}, {'B','B','B'} };
		cube_B = { {'Y','Y','Y'}, {'Y','Y','Y'}, {'Y','Y','Y'} };
		cube_L = { {'W','W','W'}, {'W','W','W'}, {'W','W','W'} };
		cube_D = { {'R','R','R'}, {'R','R','R'}, {'R','R','R'} };
	}

	void rotateF(bool reverse) {

	}
	void rotateR(bool reverse) {

	}
	void rotateU(bool reverse) {

	}
	void rotateB(bool reverse) {

	}
	void rotateL(bool reverse) {

	}
	void rotateD(bool reverse) {

	}

	void printCube() {

	}


};