#pragma once
#include "header.h"

class CubeManager {
	Cube cube;
	int op_count = 0;
	deque<pair<string, int>> ops;	// <¸í·É¾î, È½¼ö>

public : 
	void test() {
		getOps();
	}

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
				ops.push_back({op,1 });
			}
		}
	}

	void doOp() {

	}

	void printCube() {

	}

	void start() {

	}

	void end() {

	}


};