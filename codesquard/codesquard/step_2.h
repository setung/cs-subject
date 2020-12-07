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

		}
		else {

		}
	}

	void moveL(bool reverse) {
		if (!reverse) {

		}
		else {

		}
	}

	void moveB(bool reverse) {
		if (!reverse) {
			arr[2].push_back(arr[2].front());
			arr[2].pop_front();
		}
		else {
			arr[2].push_front(arr[2].back());
			arr[2].pop_back();
		}
	}

	void printArr() {
		for (auto a : arr) {
			for (auto n : a)
				cout << n << ' ';
			cout << '\n';
		}
	}
};

class CubeManagement {
private :
	Cube cube;
	queue<string> ops;
public :
	void init() {

	}

	void getOp() {
		cout << "CUBE : ";
		string readOp;
		cin >> readOp;

		for (int i = 0; i < readOp.size(); i++) {
			if (readOp[i] == '\'') {

			}
			else {

			}
		}
		
	}

	void doOp() {

	}

	void printCube() {
		cube.printArr();
	}

};