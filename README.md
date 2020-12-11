# cs-subject

Visual studio 2019
C++

Cube class
	- 데이터 
      - vector<vector<char>> cube_F;  앞면
	  - vector<vector<char>> cube_R;  오른쪽 면
	  - vector<vector<char>> cube_U;  윗면
	  - vector<vector<char>> cube_B;  뒷면
	  - vector<vector<char>> cube_L;  왼쪽 면
	  - vector<vector<char>> cube_D;  아래면

	- 함수 
	  - void init()		큐브 초기화
	  - void rotateFB(int n, int cnt)     F 또는 B 면을 cnt 만큼 회전
	  - void rotateFB_reverse(int n, int cnt) 
	  - void rotateUD(int n, int cnt)   U 또는 D 면을 cnt 만큼 회전
	  - void rotateUD_reverse(int n, int cnt)
	  - void rotateLR(int n, int cnt)   L 또는 R 면을 cnt 만큼 회전
	  - void rotateLR_reverse(int n, int cnt)
	  - void printCube()   큐브 상태 출력
	  - bool isFitted()    큐브 맞춰진 상태인지 체크
	  - void mixCube()     큐브 무작위로 섞기

CubeManager class
	- 데이터
	   - Cube cube;      큐브
	   - int ExecutedOp_count = 0;    명령어 실행 개수
	   - deque<pair<string, int>> ops;	명령어 모음 <명령어, 횟수>
	   - clock_t startTime;    시작 시간

	- 함수
	   - void getOps()     명령어 모음 입력
	   - void executeOp()  명령어 모음 실행
	   - void doOp(string op, int op_cnt) 명령어 실행  
	   - void printCube()  큐브 출력
	   - void start()     큐브 시작
	   - bool checkCube()  큐브 검사
	   - void end()   큐브 종료
	   - string getPlayTime()  큐브 게임 시간 계산