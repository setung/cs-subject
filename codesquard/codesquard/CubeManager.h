#pragma once
#include "Cube.h"

class CubeManager {
private:
	Cube cube;
	queue<string> ops;

	void getOp() {
		cout << "CUBE> ";
		string readOp;
		cin >> readOp;

		for (int i = 0; i < readOp.size(); i++) {
			string op;
			op.push_back(readOp[i]);

			if (i != readOp.size() - 1 && readOp[i + 1] == '\'') {
				op += '\'';
				i++;
			}

			ops.push(op);
		}
	}

	bool doOp(string op) {
		if (op == "R") cube.moveRow(2,0);
		else if (op == "R\'") cube.moveRow(2, 1);
		else if (op == "U") cube.moveCol(0, 0);
		else if (op == "U\'") cube.moveCol(0, 1);
		else if (op == "L") cube.moveRow(0, 1);
		else if (op == "L\'") cube.moveRow(0, 0);
		else if (op == "B") cube.moveCol(2, 1);
		else if (op == "B\'") cube.moveCol(2, 0);
		else if (op == "Q") {
			cout << "Bye~\n";
			exit(1);
		}
		else
			return false;

		return true;
	}

	void printCube() {
		cube.printArr();
	}

public:
	void start() {
		printCube();

		while (true) {
			getOp();

			while (!ops.empty()) {
				if (doOp(ops.front())) {
					cout << '\n' << ops.front() << '\n';
					printCube();
				}
				ops.pop();
			}
		}
	}
};