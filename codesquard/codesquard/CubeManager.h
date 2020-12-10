#pragma once
#include "header.h"
#include "Cube.h"
class CubeManager {
	Cube cube;
	int ExecutedOp_count = 0;
	deque<pair<string, int>> ops;	// <명령어, 횟수>

public:

	void getOps() {
		string readOps;
		cin >> readOps;
		string op = "";
		for (int i = 0; i < readOps.size(); i++) {
			if (readOps[i] == '\'') {
				ops.back().first += '\'';
			}
			else if (readOps[i] >= '0' && readOps[i] <= '9') {
				ops.back().second = readOps[i] - '0';
			}
			else {
				op = readOps[i];
				ops.push_back({ op,1 });
			}
		}
	}

	void doOp() {
		while (!ops.empty()) {
			string op = ops.front().first;
			int op_cnt = ops.front().second;
			ops.pop_front();
			ExecutedOp_count++;

			if (op != "Q") {
				if (op == "F") { cube.rotateF(0, op_cnt); }
				else if (op == "R") { cube.rotateR(0, op_cnt); }
				else if (op == "U") { cube.rotateU(0, op_cnt); }
				else if (op == "B") { cube.rotateB(0, op_cnt); }
				else if (op == "L") { cube.rotateL(0, op_cnt); }
				else if (op == "D") { cube.rotateD(0, op_cnt); }
				else if (op == "F'") { cube.rotateF(1, op_cnt); }
				else if (op == "R'") { cube.rotateR(1, op_cnt); }
				else if (op == "U'") { cube.rotateU(1, op_cnt); }
				else if (op == "B'") { cube.rotateB(1, op_cnt); }
				else if (op == "L'") { cube.rotateL(1, op_cnt); }
				else if (op == "D'") { cube.rotateD(1, op_cnt); }
				printCube();
				checkCube();
			}
			else {
				end();
			}
		}
	}

	void printCube() {
		cube.printCube();
	}

	void start() {
		cube.mixCube();
		printCube();
		
		while (true) {
			getOps();
			doOp();
		}
	}


	bool checkCube() {
		if (cube.isFitted()) {
			cout << "축하합니다. 정답입니다. \n";
			end();
		}

		return false;
	}
	void end() {
		cout << "경과 시간 :  00:00\n";
		cout << "조작 갯수 : " << ExecutedOp_count << '\n';
		cout << "이용해 주셔서 감사합니다. 뚜뚜뚜.\n";

		exit(0);
	}


};