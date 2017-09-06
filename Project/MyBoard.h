#include "MyBlock.h" // ������� ����

class MyBoard // MyBoard Ŭ���� ����
{
private:
	MyBlock * m_pHead; // ��带 ����
public:
	MyBoard(); // ������
	~MyBoard(); // �Ҹ���

	void Set(); // ��ϵ��� ���� ������ �Լ�

	bool Up(int s); // ���� ������ ��� 
	bool Down(int s); // �Ʒ��� ������ ���
	bool Left(int s); // ���� ������ ���
	bool Right(int s); // ������ ������ ���

	void U(); // ���� ����
	void D(); // �Ʒ��� ����
	void L(); // ���� ����
	void R(); // ������ ����
	void Print(); // ��ũ���� ���� ���
	int Print(int x, int y); // �ش� ��ǥ�� ���� ����
	int Init(int i); // �ش� ��Ͽ� 2�� �Է�
	int Win(); // �¸� ���� �˻�
	void CRotate(); // �ð�������� ȸ��
	void IRotate(); // �ݽð�������� ȸ��
};
