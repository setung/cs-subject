# cs-subject

Visual studio 2019
C++

2�ܰ�: ��� ť�� �����ϱ�

class Cube 

	������
	- vector<deque<int>> arr  ť�� �迭

	�Լ�
   - void moveCol(int n, bool clockDirection)  n ��° ���� clockDirection �������� ȸ��
   - void moveRow(int n, bool clockDirection)  n ��° ���� clockDirection �������� ȸ��
   - printArr()            �迭 ���

class CubeManager

   ������
   - Cube cube             ť�� 
   - queue<string> ops     ��ɾ� ���� ť
  
   �Լ�
   - getOp()              ��ɾ� �Է�
   - doOp(string op)      ť�� �ִ� ��ɾ� ����
   - printCube()          ť�� �迭 ���
   - start()              ť�� ����