# cs-subject

Visual studio 2019
C++

step_1.h 헤더 파일 생성

void input((string, int, char))
   - 문자열, 정수, 문자를 입력 받음.
   - 정수 범위 : -100 <= n <= 100
   - 입력 허용 문자 : r, R, l, L
   - 값이 잘 들어올때까지 입력 반복.

string goLeft(string, int)
   - 문자열을 정수 값만큼 왼쪽으로 회전.
   - string::substr로 구현

string goRight(string, int)
   - 문자열을 정수 값만큼 오른쪽으로 회전.
   - string::substr로 구현

string step_1()
