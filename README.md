# cs-subject

Visual studio 2019
C++

2�ܰ�: ��� ť�� �����ϱ�

class Cube 

	������
	- vector<deque<int>> arr  ť�� �迭

	�Լ�
   - moveU(bool reverse)   bool ���� ���� ���� ������ �������̳� �������� ȸ��
   - moveR(bool reverse)   bool ���� ���� ���� ������ ���� ���� �Ʒ��� ȸ��
   - moveL(bool reverse)   bool ���� ���� ���� ���� ���� ���� �Ʒ��� ȸ��
   - moveB(bool reverse)   bool ���� ���� ���� �Ʒ����� �������̳� �������� ȸ��
   - printArr()            �迭 ���

class CubeManagement 

   ������
   - Cube cube             ť�� 
   - queue<string> ops     ��ɾ� ���� ť
  
   �Լ�
   - getOp()              ��ɾ� �Է�
   - doOp(string op)      ť�� �ִ� ��ɾ� ����
   - printCube()          ť�� �迭 ���
   - start()              ť�� ����