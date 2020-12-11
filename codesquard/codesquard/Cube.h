#pragma once
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Cube
{
private:
	vector<deque<int>> arr;
public:
	Cube() {
		arr = vector<deque<int>>(3, deque<int>(3));
		arr[0] = { 'R','R','W' };
		arr[1] = { 'G','C','W' };
		arr[2] = { 'G','B','B' };
	};

	void moveCol(int n, bool clockDirection) {
		if (!clockDirection) {
			arr[n].push_back(arr[n].front());
			arr[n].pop_front();
		}
		else {
			arr[n].push_front(arr[n].back());
			arr[n].pop_back();
		}
	}

	void moveRow(int n, bool clockDirection) {
		if (!clockDirection) {
			int temp = arr[0][n];
			arr[0][n] = arr[1][n];
			arr[1][n] = arr[2][n];
			arr[2][n] = temp;
		}
		else {
			int temp = arr[2][n];
			arr[2][n] = arr[1][n];
			arr[1][n] = arr[0][n];
			arr[0][n] = temp;
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
