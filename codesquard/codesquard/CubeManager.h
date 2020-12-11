#pragma once
#include "header.h"
#include "Cube.h"
#include <time.h>
class CubeManager {
	Cube cube;
	int ExecutedOp_count = 0;
	deque<pair<string, int>> ops;	// <��ɾ�, Ƚ��>
	clock_t startTime;
public:

	void getOps() {
		string readOps;
		cout << "CUBE> ";
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

	void executeOp() {
		while (!ops.empty()) {
			string op = ops.front().first;
			int op_cnt = ops.front().second;
			ops.pop_front();
			ExecutedOp_count++;
			cout << op;
			if (op_cnt > 1) cout << op_cnt << '\n';
			else cout << '\n';
		
			doOp(op,op_cnt);
		}
	}

	void doOp(string op, int op_cnt) {
		if (op != "Q") {
			if (op == "F") { cube.rotateFB(2, op_cnt); }
			else if (op == "R") { cube.rotateLR_reverse(2, op_cnt); }
			else if (op == "U") { cube.rotateUD(0, op_cnt); }
			else if (op == "B") { cube.rotateFB_reverse(0, op_cnt); }
			else if (op == "L") { cube.rotateLR(0, op_cnt); }
			else if (op == "D") { cube.rotateUD_reverse(2, op_cnt); }
			else if (op == "F'") { cube.rotateFB_reverse(2, op_cnt); }
			else if (op == "R'") { cube.rotateLR(2, op_cnt); }
			else if (op == "U'") { cube.rotateUD_reverse(0, op_cnt); }
			else if (op == "B'") { cube.rotateFB(0, op_cnt); }
			else if (op == "L'") { cube.rotateLR_reverse(0, op_cnt); }
			else if (op == "D'") { cube.rotateUD(2, op_cnt); }
			printCube();
			checkCube();
		}
		else {
			end();
		}
	}

	void printCube() {
		cube.printCube();
	}

	void start() {
		startTime = clock();
		cube.mixCube();
		printCube();
	
		while (true) {
			getOps();
			executeOp();
		}
	}

	bool checkCube() {
		if (cube.isFitted()) {
			cout << "�����մϴ�. �����Դϴ�. \n";
			end();
		}

		return false;
	}

	void end() {
		cout << "��� �ð� :  " << getPlayTime() << '\n';
		cout << "���� ���� : " << ExecutedOp_count << '\n';
		cout << "�̿��� �ּż� �����մϴ�. �ѶѶ�.\n";

		exit(0);
	}

	string getPlayTime() {
		int result = (int)(clock() - startTime)/1000;
		int m = result / 60;
		int s = result % 60;

		string str = m < 10 ? "0" + to_string(m) : to_string(m);
		str += ":";
		str += s < 10 ? "0" + to_string(s) : to_string(s);

		return (str);
	}

};