# cs-subject

Visual studio 2019
C++

2단계: 평면 큐브 구현하기

class Cube 

	데이터
	- vector<deque<int>> arr  큐브 배열

	함수
   - void moveCol(int n, bool clockDirection)  n 번째 열을 clockDirection 방향으로 회전
   - void moveRow(int n, bool clockDirection)  n 번째 행을 clockDirection 방향으로 회전
   - printArr()            배열 출력

class CubeManager

   데이터
   - Cube cube             큐브 
   - queue<string> ops     명령어 모음 큐
  
   함수
   - getOp()              명령어 입력
   - doOp(string op)      큐에 있는 명령어 실행
   - printCube()          큐브 배열 출력
   - start()              큐브 실행