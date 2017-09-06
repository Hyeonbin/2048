class MyBlock // MyBlock 클래스
{
private:
	MyBlock * m_pUp; // 상단 블록
	MyBlock * m_pDown; // 하단 블록
	MyBlock * m_pLeft; // 좌측 블록
	MyBlock * m_pRight; // 우측 블록

public:
	int m_number, m_x, m_y; // 숫자, x좌표, y좌표 변수
	MyBlock(); // 생성자
	~MyBlock(); // 소멸자
	void SetNumber(int a, int b, int c); // 변수들의 값을 정해줄 함수
	void SetUp(MyBlock * U); // 상단 블록을 이어줄 함수
	void SetDown(MyBlock * D); // 하단 블록을 이어줄 함수
	void SetLeft(MyBlock * L); // 좌측 블록을 이어줄 함수
	void SetRight(MyBlock * R); // 우측 블록을 이어줄 함수
	MyBlock * GetUp(); // 상단 블록을 리턴해줄 함수
	MyBlock * GetDown(); // 하단 블록을 리턴해줄 함수
	MyBlock * GetLeft(); // 좌측 블록을 리턴해줄 함수
	MyBlock * GetRight(); // 우측 블록을 리턴해줄 함수
	int GetNum(); // 숫자를 리턴해줄 함수
	int GetX(); // x좌표를 리턴해줄 함수
	int GetY(); // y좌표를 리턴해줄 함수
};