#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Cube
{
private :
	vector<deque<int>> arr;
public :
	Cube() {
		arr = vector<deque<int>>(3, deque<int>(3));
		arr[0] = { 'R','R','W' };
		arr[1] = { 'G','C','W' };
		arr[2] = { 'G','B','B' };
	};

	void moveU(bool reverse) {
		if (!reverse) {
			arr[0].push_back(arr[0].front());
			arr[0].pop_front();
		}
		else {
			arr[0].push_front(arr[0].back());
			arr[0].pop_back();
		}
	}

	void moveR(bool reverse) {
		if (!reverse) {
			int temp = arr[0][2];
			arr[0][2] = arr[1][2];
			arr[1][2] = arr[2][2];
			arr[2][2] = temp;
		}
		else {
			int temp = arr[2][2];
			arr[2][2] = arr[1][2];
			arr[1][2] = arr[0][2];
			arr[0][2] = temp;
		}
	}

	void moveL(bool reverse) {
		if (!reverse) {
			int temp = arr[2][0];
			arr[2][0] = arr[1][0];
			arr[1][0] = arr[0][0];
			arr[0][0] = temp;
		}
		else {
			int temp = arr[0][0];
			arr[0][0] = arr[1][0];
			arr[1][0] = arr[2][0];
			arr[2][0] = temp;
		}
	}

	void moveB(bool reverse) {
		if (!reverse) {
			arr[2].push_front(arr[2].back());
			arr[2].pop_back();
		}
		else {
			arr[2].push_back(arr[2].front());
			arr[2].pop_front();
		}
	}

	void printArr() {
		for (auto a : arr) {
			for (char n : a)
				cout << n << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
};

class CubeManagement {
private :
	Cube cube;
	queue<string> ops;

	void getOp() {
		cout << "CUBE> ";
		string readOp;
		cin >> readOp;

		for (int i = 0; i < readOp.size(); i++) {
			string op;
			op.push_back(readOp[i]);

			if (i != readOp.size()-1 && readOp[i + 1] == '\'') {
				op += '\'';
				i++;
			}
			
			ops.push(op);
		}
	}

	bool doOp(string op) {
		if (op == "R") cube.moveR(0);
		else if(op=="R\'") cube.moveR(1);
		else if (op == "U") cube.moveU(0);
		else if (op == "U\'") cube.moveU(1);
		else if (op == "L") cube.moveL(0);
		else if (op == "L\'") cube.moveL(1);
		else if (op == "B") cube.moveB(0);
		else if (op == "B\'") cube.moveB(1);
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

public :
	void start() {
		printCube();

		while (true) {
			getOp();

			while (!ops.empty()) {
				if (doOp(ops.front())) {
					cout<<'\n' << ops.front() << '\n';
					printCube();
				}
				ops.pop();
			}
		}
	}
};