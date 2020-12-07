#pragma once
#include <iostream>
#include <string>
using namespace std;

void input(string& str, int& n, char& direction) {
	while (true) {
		cin >> str >> n >> direction;

		if (!(n <= 100 && n >= -100 && (direction == 'r' || direction == 'R' || direction == 'l' || direction == 'L'))) {
			cout << "Wrong data! Try again!\n";
		}
		else {
			if (n < 0) {
				n *= -1;
				if (direction == 'r' || direction == 'R')
					direction = 'l';
				else
					direction = 'r';
			}

			break;
		}
	}
}
string goLeft(string& str, int n) {
	/*
	for (int i = 0; i < n; i++)
		str = str.substr(1, str.size() - 1) + str.front();
	*/

	n %= str.size();
	str = str.substr(n, str.size()-n) + str.substr(0, n);

	return str;
}
string goRight(string& str, int n) {
	/*
	for (int i = 0; i < n; i++)
		str = str.back() + str.substr(0, str.size() - 1);
	*/

	n %= str.size();
	str = str.substr(str.size()-n, n) + str.substr(0, str.size() - n);

	return str;
}
string step_1() {
	string str;
	int n;
	char direction;

	input(str, n, direction);

	if (direction == 'r' || direction == 'R')
		goRight(str, n);
	else
		goLeft(str, n);

	return str;
}