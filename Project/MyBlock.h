class MyBlock // MyBlock Ŭ����
{
private:
	MyBlock * m_pUp; // ��� ���
	MyBlock * m_pDown; // �ϴ� ���
	MyBlock * m_pLeft; // ���� ���
	MyBlock * m_pRight; // ���� ���

public:
	int m_number, m_x, m_y; // ����, x��ǥ, y��ǥ ����
	MyBlock(); // ������
	~MyBlock(); // �Ҹ���
	void SetNumber(int a, int b, int c); // �������� ���� ������ �Լ�
	void SetUp(MyBlock * U); // ��� ����� �̾��� �Լ�
	void SetDown(MyBlock * D); // �ϴ� ����� �̾��� �Լ�
	void SetLeft(MyBlock * L); // ���� ����� �̾��� �Լ�
	void SetRight(MyBlock * R); // ���� ����� �̾��� �Լ�
	MyBlock * GetUp(); // ��� ����� �������� �Լ�
	MyBlock * GetDown(); // �ϴ� ����� �������� �Լ�
	MyBlock * GetLeft(); // ���� ����� �������� �Լ�
	MyBlock * GetRight(); // ���� ����� �������� �Լ�
	int GetNum(); // ���ڸ� �������� �Լ�
	int GetX(); // x��ǥ�� �������� �Լ�
	int GetY(); // y��ǥ�� �������� �Լ�
};