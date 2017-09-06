#include "MyBlock.h" // 헤더파일 선언

class MyBoard // MyBoard 클래스 선언
{
private:
	MyBlock * m_pHead; // 헤드를 선언
public:
	MyBoard(); // 생성자
	~MyBoard(); // 소멸자

	void Set(); // 블록들의 값을 지정할 함수

	bool Up(int s); // 위쪽 동작일 경우 
	bool Down(int s); // 아래쪽 동작일 경우
	bool Left(int s); // 왼쪽 동작일 경우
	bool Right(int s); // 오른쪽 동작일 경우

	void U(); // 위쪽 동작
	void D(); // 아래쪽 동작
	void L(); // 왼쪽 동작
	void R(); // 오른쪽 동작
	void Print(); // 스크린에 보드 출력
	int Print(int x, int y); // 해당 좌표의 값을 리턴
	int Init(int i); // 해당 블록에 2를 입력
	int Win(); // 승리 조건 검사
	void CRotate(); // 시계방향으로 회전
	void IRotate(); // 반시계방향으로 회전
};
