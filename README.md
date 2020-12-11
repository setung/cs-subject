# cs-subject

Visual studio 2019
C++

Cube class
	- ������ 
      - vector<vector<char>> cube_F;  �ո�
	  - vector<vector<char>> cube_R;  ������ ��
	  - vector<vector<char>> cube_U;  ����
	  - vector<vector<char>> cube_B;  �޸�
	  - vector<vector<char>> cube_L;  ���� ��
	  - vector<vector<char>> cube_D;  �Ʒ���

	- �Լ� 
	  - void init()		ť�� �ʱ�ȭ
	  - void rotateFB(int n, int cnt)     F �Ǵ� B ���� cnt ��ŭ ȸ��
	  - void rotateFB_reverse(int n, int cnt) 
	  - void rotateUD(int n, int cnt)   U �Ǵ� D ���� cnt ��ŭ ȸ��
	  - void rotateUD_reverse(int n, int cnt)
	  - void rotateLR(int n, int cnt)   L �Ǵ� R ���� cnt ��ŭ ȸ��
	  - void rotateLR_reverse(int n, int cnt)
	  - void printCube()   ť�� ���� ���
	  - bool isFitted()    ť�� ������ �������� üũ
	  - void mixCube()     ť�� �������� ����

CubeManager class
	- ������
	   - Cube cube;      ť��
	   - int ExecutedOp_count = 0;    ��ɾ� ���� ����
	   - deque<pair<string, int>> ops;	��ɾ� ���� <��ɾ�, Ƚ��>
	   - clock_t startTime;    ���� �ð�

	- �Լ�
	   - void getOps()     ��ɾ� ���� �Է�
	   - void executeOp()  ��ɾ� ���� ����
	   - void doOp(string op, int op_cnt) ��ɾ� ����  
	   - void printCube()  ť�� ���
	   - void start()     ť�� ����
	   - bool checkCube()  ť�� �˻�
	   - void end()   ť�� ����
	   - string getPlayTime()  ť�� ���� �ð� ���