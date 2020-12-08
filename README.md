# cs-subject

Visual studio 2019
C++

2단계: 평면 큐브 구현하기

class Cube 

	데이터
	- vector<deque<int>> arr  큐브 배열

	함수
   - moveU(bool reverse)   bool 값에 따라 가장 윗줄을 오른쪽이나 왼쪽으로 회전
   - moveR(bool reverse)   bool 값에 따라 가장 오른쪽 줄을 위나 아래로 회전
   - moveL(bool reverse)   bool 값에 따라 가장 왼쪽 줄을 위나 아래로 회전
   - moveB(bool reverse)   bool 값에 따라 가장 아랫줄을 오른쪽이나 왼쪽으로 회전
   - printArr()            배열 출력

class CubeManagement 

   데이터
   - Cube cube             큐브 
   - queue<string> ops     명령어 모음 큐
  
   함수
   - getOp()              명령어 입력
   - doOp(string op)      큐에 있는 명령어 실행
   - printCube()          큐브 배열 출력
   - start()              큐브 실행