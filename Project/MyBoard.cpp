#include "stdafx.h" // 헤더파일 선언
#include "MyBoard.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; // 표준 namespace 사용

MyBlock * n1=new MyBlock; // 16개의 블록을 선언
MyBlock * n2=new MyBlock;
MyBlock * n3=new MyBlock;
MyBlock * n4=new MyBlock;
MyBlock * n5=new MyBlock;
MyBlock * n6=new MyBlock;
MyBlock * n7=new MyBlock;
MyBlock * n8=new MyBlock;
MyBlock * n9=new MyBlock;
MyBlock * n10=new MyBlock;
MyBlock * n11=new MyBlock;
MyBlock * n12=new MyBlock;
MyBlock * n13=new MyBlock;
MyBlock * n14=new MyBlock;
MyBlock * n15=new MyBlock;
MyBlock * n16=new MyBlock;

int sig=0; // 시그널 변수 1 선언
int sig2=0; // 시그널 변수 2 선언

MyBoard::MyBoard() // 생성자
{
	m_pHead=0; // 헤드를 0으로 초기화
}

MyBoard::~MyBoard() // 소멸자
{}


void MyBoard::Set() // 블록들을 보드에 세팅하는 함수
{
	n1->SetNumber(0, 0, 0); // 블록의 값들 초기화
	n2->SetNumber(0, 0, 1); // 블록의 값들 초기화
	n3->SetNumber(0, 0, 2); // 블록의 값들 초기화
	n4->SetNumber(0, 0, 3); // 블록의 값들 초기화
	n5->SetNumber(0, 1, 0); // 블록의 값들 초기화
	n6->SetNumber(0, 1, 1); // 블록의 값들 초기화
	n7->SetNumber(0, 1, 2); // 블록의 값들 초기화
	n8->SetNumber(0, 1, 3); // 블록의 값들 초기화
	n9->SetNumber(0, 2, 0); // 블록의 값들 초기화
	n10->SetNumber(0, 2, 1); // 블록의 값들 초기화
	n11->SetNumber(0, 2, 2); // 블록의 값들 초기화
	n12->SetNumber(0, 2, 3); // 블록의 값들 초기화
	n13->SetNumber(0, 3, 0); // 블록의 값들 초기화
	n14->SetNumber(0, 3, 1); // 블록의 값들 초기화
	n15->SetNumber(0, 3, 2); // 블록의 값들 초기화
	n16->SetNumber(0, 3, 3); // 블록의 값들 초기화
	n1->SetUp(0); // 블록의 상하좌우 블록들 지정
	n1->SetDown(n5);
	n1->SetLeft(0);
	n1->SetRight(n2);
	n2->SetUp(0); // 블록의 상하좌우 블록들 지정
	n2->SetDown(n6);
	n2->SetLeft(n1);
	n2->SetRight(n3);
	n3->SetUp(0); // 블록의 상하좌우 블록들 지정
	n3->SetDown(n7);
	n3->SetLeft(n2);
	n3->SetRight(n4);
	n4->SetUp(0); // 블록의 상하좌우 블록들 지정
	n4->SetDown(n8);
	n4->SetLeft(n3);
	n4->SetRight(0);
	n5->SetUp(n1); // 블록의 상하좌우 블록들 지정
	n5->SetDown(n9);
	n5->SetLeft(0);
	n5->SetRight(n6);
	n6->SetUp(n2); // 블록의 상하좌우 블록들 지정
	n6->SetDown(n10);
	n6->SetLeft(n5);
	n6->SetRight(n7);
	n7->SetUp(n3); // 블록의 상하좌우 블록들 지정
	n7->SetDown(n11);
	n7->SetLeft(n6);
	n7->SetRight(n8);
	n8->SetUp(n4); // 블록의 상하좌우 블록들 지정
	n8->SetDown(n12);
	n8->SetLeft(n7);
	n8->SetRight(0);
	n9->SetUp(n5); // 블록의 상하좌우 블록들 지정
	n9->SetDown(n13);
	n9->SetLeft(0);
	n9->SetRight(n10);
	n10->SetUp(n6); // 블록의 상하좌우 블록들 지정
	n10->SetDown(n14);
	n10->SetLeft(n9);
	n10->SetRight(n11);
	n11->SetUp(n7); // 블록의 상하좌우 블록들 지정
	n11->SetDown(n15);
	n11->SetLeft(n10);
	n11->SetRight(n12);
	n12->SetUp(n8); // 블록의 상하좌우 블록들 지정
	n12->SetDown(n16);
	n12->SetLeft(n11);
	n12->SetRight(0);
	n13->SetUp(n9); // 블록의 상하좌우 블록들 지정
	n13->SetDown(0);
	n13->SetLeft(0);
	n13->SetRight(n14);
	n14->SetUp(n10); // 블록의 상하좌우 블록들 지정
	n14->SetDown(0);
	n14->SetLeft(n13);
	n14->SetRight(n15);
	n15->SetUp(n11); // 블록의 상하좌우 블록들 지정
	n15->SetDown(0);
	n15->SetLeft(n14);
	n15->SetRight(n16);
	n16->SetUp(n12); // 블록의 상하좌우 블록들 지정
	n16->SetDown(0);
	n16->SetLeft(n15);
	n16->SetRight(0);
	m_pHead=n1; // 헤드를 첫번째 블록으로 지정
	srand(time(0)); // 랜덤함수 선언

	for(int j=0; j<2; j++) // 두 개의 랜덤 값을 생성
	{
		while(1) // 무한 루프
		{
			int i=rand()%16+1; // 16까지의 수 중 랜덤
			if(Init(i)==0) // 0인 경우 루프 종료
				break;
			else // 그렇지 않으면 재 진행
				continue;
		}
	}
}

bool MyBoard::Up(int s) // 위쪽 동작인 경우
{
	if(s==1)
		return true; // 1을 리턴
	else
		return false; // 0을 리턴
}

bool MyBoard::Down(int s) // 아래쪽 동작인 경우
{
	if(s==2)
		return true; // 1을 리턴
	else
		return false; // 0을 리턴
}


bool MyBoard::Left(int s) // 왼쪽 동작인 경우
{
	if(s==3)
		return true; // 1을 리턴
	else
		return false; // 0을 리턴
}


bool MyBoard::Right(int s) // 오른쪽 동작인 경우
{
	if(s==4)
		return true; // 1을 리턴
	else
		return false; // 0을 리턴
}

void MyBoard::U() // 상단 이동
{
	MyBlock * Cur = m_pHead; // 현재 블록 선언
	MyBlock * Cmp = new MyBlock; // 비교할 블록
	int temp=0; // 임시변수
	int s=0; // 시그널 변수

	for(int k=0; k<4; k++) // 블록 간의 비교 진행
	{
		if(Cur->GetNum() == Cur->GetDown()->GetNum() && Cur->GetDown()->GetDown()->GetNum() == Cur->GetDown()->GetDown()->GetDown()->GetNum())
			s=-1; // 두 블록씩 차례대로 값이 같은 경우
		else
			s=0; // 그렇지 않은 경우

		for(int i=0; i<3; i++)
		{
			Cmp=Cur; // 비교 블록에 현재 블록 저장
			for(int j=i; j<3; j++)
			{
				if(Cmp->GetNum()==0) // 비교 블록이 0이라면 
				{
					temp=Cmp->GetNum(); // 옆의 블록과 swap
					Cmp->SetNumber(Cmp->GetDown()->GetNum(), Cmp->GetX(), Cmp->GetY()); // 옆의 블록과 swap
					Cmp->GetDown()->SetNumber(temp, Cmp->GetDown()->GetX(), Cmp->GetDown()->GetY()); // 옆의 블록과 swap
				}
				else // 그렇지 않다면
				{
					if(Cmp->GetDown()->GetNum()==Cmp->GetNum()) // 두 블록의 값이 같다면
					{
						if(s!=1) // s가 1이 아닌 경우
						{
							Cmp->SetNumber(Cmp->GetDown()->GetNum()+Cmp->GetNum(), Cmp->GetX(), Cmp->GetY()); // 두 블록을 합침
							Cmp->GetDown()->SetNumber(0, Cmp->GetDown()->GetX(), Cmp->GetDown()->GetY()); // 두 블록을 합침
							s++; // s는 1 증가
						}
					}
				}
				Cmp=Cmp->GetDown(); // 비교 블록 아래로 이동
			}
		}
		Cur=Cur->GetRight(); // 현재 블록 오른쪽으로 이동
	}
}

void MyBoard::D() // 하단 이동
{
	MyBlock * Cur = m_pHead; // 현재 블록
	MyBlock * Cmp = new MyBlock; // 비교 블록
	int temp=0; // 임시 변수
	int s=0; // 시그널 변수

	Cur=Cur->GetDown(); // 현재 블록을 맨 밑으로 이동
	Cur=Cur->GetDown(); // 이동
	Cur=Cur->GetDown(); // 이동
	
	for(int k=0; k<4; k++) // 블록 이동 동작 진행
	{
		if(Cur->GetNum() == Cur->GetUp()->GetNum() && Cur->GetUp()->GetUp()->GetNum() == Cur->GetUp()->GetUp()->GetUp()->GetNum())
			s=-1; // 순서대로 두 블록씩 값이 같은 경우
		else
			s=0; // 그렇지 않은 경우

		for(int i=0; i<3; i++)
		{
			Cmp=Cur; // 비교 블록에 현재 블록 저장
			for(int j=i; j<3; j++)
			{
				if(Cmp->GetNum()==0) // 비교 블록이 0이라면 
				{
					temp=Cmp->GetNum(); // 다음 블록과 swap
					Cmp->SetNumber(Cmp->GetUp()->GetNum(), Cmp->GetX(), Cmp->GetY()); // 다음 블록과 swap
					Cmp->GetUp()->SetNumber(temp, Cmp->GetUp()->GetX(), Cmp->GetUp()->GetY()); // 다음 블록과 swap
				}
				else // 그렇지 않다면
				{
					if(Cmp->GetUp()->GetNum()==Cmp->GetNum()) // 위쪽 블록과 값이 같다면 
					{
						if(s!=1) // s가 1이 아닌 경우
						{
							Cmp->SetNumber(Cmp->GetUp()->GetNum()+Cmp->GetNum(), Cmp->GetX(), Cmp->GetY()); // 두 블록을 합친다
							Cmp->GetUp()->SetNumber(0, Cmp->GetUp()->GetX(), Cmp->GetUp()->GetY()); // 합친다
							s++; // s는 1 증가
						}
					}
				}
				Cmp=Cmp->GetUp(); // 비교 블록은 상단으로 이동
			}
		}
		Cur=Cur->GetRight(); // 현재 블록은 우측으로 이동
	}
}

void MyBoard::L() // 좌측 이동 
{
	MyBlock * Cur = m_pHead;// 현재 블록
	MyBlock * Cmp = new MyBlock; // 비교 블록
	int temp=0; // 임시 변수
	int s=0; // 시그널 변수

	for(int k=0; k<4; k++) // 이동 진행
	{
		if(Cur->GetNum() == Cur->GetRight()->GetNum() && Cur->GetRight()->GetRight()->GetNum() == Cur->GetRight()->GetRight()->GetRight()->GetNum())
			s=-1; // 두쌍씩 차례대로 값이 같은 경우
		else
			s=0; // 그렇지 않은 경우

		for(int i=0; i<3; i++)
		{
			Cmp=Cur; // 비교 블록에 현재 블록 저장
			for(int j=i; j<3; j++)
			{
				if(Cmp->GetNum()==0) // 비교 블록의 값이 0인 경우
				{
					temp=Cmp->GetNum(); // 다음 블록과 swap
					Cmp->SetNumber(Cmp->GetRight()->GetNum(), Cmp->GetX(), Cmp->GetY()); // 다음 블록과 swap
					Cmp->GetRight()->SetNumber(temp, Cmp->GetRight()->GetX(), Cmp->GetRight()->GetY()); // 다음 블록과 swap
				}
				else // 그렇지 않다면
				{
					if(Cmp->GetRight()->GetNum()==Cmp->GetNum()) // 다음 블록과 같은 경우
					{
						if(s!=1) // 시그널이 1이 아니라면
						{
							Cmp->SetNumber(Cmp->GetRight()->GetNum()+Cmp->GetNum(), Cmp->GetX(), Cmp->GetY()); // 두 블록을 합친다
							Cmp->GetRight()->SetNumber(0, Cmp->GetRight()->GetX(), Cmp->GetRight()->GetY()); // 합친다
							s++; // s는 1 증가
						}
					}
				}
				Cmp=Cmp->GetRight(); // 비교 블록 우측으로 이동
			}
		}
		Cur=Cur->GetDown(); // 현재 블록 하단으로 이동
	}
}	

void MyBoard::R() // 우측 이동 함수
{
	MyBlock * Cur = m_pHead; // 현재 블록
	MyBlock * Cmp = new MyBlock; // 비교 블록
	int temp=0; // 임시 변수
	int s=0; // 시그널 변수

	Cur=Cur->GetRight(); // 현재 블록 우측으로 이동
	Cur=Cur->GetRight(); // 이동
	Cur=Cur->GetRight(); // 이동

	for(int k=0; k<4; k++)
	{
		if(Cur->GetNum() == Cur->GetLeft()->GetNum() && Cur->GetLeft()->GetLeft()->GetNum() == Cur->GetLeft()->GetLeft()->GetLeft()->GetNum())
			s=-1; // 두 쌍씩 값이 같은 경우
		else
			s=0; // 그렇지 않은 경우

		for(int i=0; i<3; i++)
		{
			Cmp=Cur; // 비교 블록에 현재 블록 저장
			for(int j=0; j<3-i; j++)
			{
				if(Cmp->GetNum()==0) // 비교 블록의 값이 0인 경우
				{
					temp=Cmp->GetNum(); // 다음 블록과 swap
					Cmp->SetNumber(Cmp->GetLeft()->GetNum(), Cmp->GetX(), Cmp->GetY()); // 다음 블록과 swap
					Cmp->GetLeft()->SetNumber(temp, Cmp->GetLeft()->GetX(), Cmp->GetLeft()->GetY()); // 다음 블록과 swap
				}
				else // 그렇지 않다면
				{
					if(Cmp->GetLeft()->GetNum()==Cmp->GetNum()) // 다음 블록과 값이 같다면
					{
						if(s!=1) // s가 1인 경우
						{
							Cmp->SetNumber(Cmp->GetLeft()->GetNum()+Cmp->GetNum(), Cmp->GetX(), Cmp->GetY()); // 두 블록을 합침
							Cmp->GetLeft()->SetNumber(0, Cmp->GetLeft()->GetX(), Cmp->GetLeft()->GetY()); // 합친다
							s++; // s는 1 증가
						}
					}
				}
				Cmp=Cmp->GetLeft(); // 비교 블록 왼쪽으로 이동
			}
		}
		Cur=Cur->GetDown(); // 현재 블록 하단으로 이동
	}
}	

void MyBoard::Print() // 출력 함수
{
	MyBlock * Cur = m_pHead; // 현재 블록

	cout<<"[Board]"<<endl; // 문자열 출력

	for(int i=0; i<4; i++) // 출력을 위한 반복문
	{
		cout<<"[  "; // 문자열 출력
		for(int j=0; j<4; j++)
		{
			cout<<Cur->GetNum()<<"  "; // 블록 값 출력
			if(j==3)
				break;
			Cur=Cur->GetRight(); // 우측 이동
		}
		cout<<"]"<<endl; // 문자열 출력
		if(i==3)
			break;
		Cur=Cur->GetDown(); // 하단 이동
		Cur=Cur->GetLeft(); // 좌측 이동
		Cur=Cur->GetLeft(); // 이동
		Cur=Cur->GetLeft(); // 이동
	}
}

int MyBoard::Init(int i) // 빈 블록에 2를 넣는 함수
{
	MyBlock * Cur = m_pHead; // 현재 블록

	for(int j=0; j<i-1; j++) // 블록으로 이동하는 함수
	{
		if(j==3 || j==7 || j==11) // 열의 끝인 경우
		{
			Cur=Cur->GetDown();  // 하단 이동
			Cur=Cur->GetLeft(); // 좌측 이동
			Cur=Cur->GetLeft(); // 이동
			Cur=Cur->GetLeft(); // 이동
		}
		else // 아니면
			Cur=Cur->GetRight(); // 우측 이동
	}

	if(Cur->GetNum()==0) // 블록의 값이 0인 경우
	{
		Cur->SetNumber(2, Cur->GetX(), Cur->GetY()); // 2를 저장
		return 0; // 0을 반환
	}
	else // 그렇지 않으면
	{
		if(sig2==0) // 시그널2가 0인 겨웅
			return 0; // 0을 반환
		else // 그렇지 않다면 
			return 1; // 1을 반환
	}
}

int MyBoard::Win() // 승리 조건을 검사하는 함수
{
	MyBlock * Cur = m_pHead; // 현재 블록
	int i=0; // 반복문 변수
	sig=0; // 시그널
	sig2=0; // 시그널2

	while(Cur!=0) // 현재 블록의 끝까지 반복
	{
		if(Cur->GetNum()==0) // 블록의 값이 0이라면
			sig2=1; // 시그널2의 값은 1로

		if(Cur->GetNum()==2048) // 2048을 찾는다면
		{
			return 1; // 1을 반환
			break;
		}

		if(i==3 || i==7 || i==11) // 열의 끝인 경우
		{
			i++; // i 1 증가
			Cur=Cur->GetDown(); // 하단으로 이동	
			Cur=Cur->GetLeft(); // 좌측으로 이동
			Cur=Cur->GetLeft(); // 이동
			Cur=Cur->GetLeft(); // 이동
			continue;
		}
		else // 그렇지 않다면 
		{
			i++; // i 1 증가
			Cur=Cur->GetRight(); // 우측 이동
			continue; 
		}
	}

	if(i==16 && sig2==0) // 2048이 없고 보드가 꽉 찬 경우
	{
		Cur=m_pHead; // 현재 블록
		int j=0;
		while(Cur!=0) // 이동 가능 블록을 찾기 위한 반복문
		{
			if(Cur->GetDown()!=NULL) // 하단에 블록이 있다면
			{
				if(Cur->GetNum()==Cur->GetDown()->GetNum()) // 블록 간의 값이 같다면
				{
					return 0; // 0을 리턴
					sig=1; // 시그널 1
					break; 
				}
			}
			if(Cur->GetRight()!=NULL) // 우측에 블록이 있다면
			{
				if(Cur->GetNum()==Cur->GetRight()->GetNum()) // 블록 간의 값이 같다면
				{
					return 0; // 0을 리턴
					sig=1; // 시그널 1
					break;
				}
			}

			if(j==3 || j==7 || j==11) // 줄 바꿈
			{
				j++; // j 1 증가
				Cur=Cur->GetDown(); // 하단 이동 
				Cur=Cur->GetLeft(); // 좌측 이동
				Cur=Cur->GetLeft(); // 좌측 이동
				Cur=Cur->GetLeft(); // 좌측 이동
				continue;
			}
			else // 그렇지 않다면
			{
				j++; // j 1 증가
				Cur=Cur->GetRight(); // 우측 이동
				continue;
			}
		}
		if(j==16) // j가 16이라면
			return 2; // 패배
	}
}

void MyBoard::CRotate() // 시계방향 회전
{
	MyBlock * Cur = m_pHead; // 현재 블록
	MyBlock Temp; // 임시 블록

	for(int i=0; i<16; i++) // 블록의 회전을 위한 반복문
	{
		Temp = *Cur; // 임시 블록에 현재 블록 저장

		Cur->SetUp(Temp.GetLeft()); // 상단 블록은 좌측 블록으로
		Cur->SetDown(Temp.GetRight()); // 하단 블록은 우측 블록으로
		Cur->SetRight(Temp.GetUp()); // 우측 블록은 상단 블록으로
		Cur->SetLeft(Temp.GetDown()); // 좌측 블록은 하단 블록으로

		//시계 방향으로 이동
		if(i<3)
			Cur=Temp.GetRight(); // 우측 이동
		else if(i>=3 && i<6) 
			Cur=Temp.GetDown(); // 하단 이동
		else if(i>=6 && i<9)
			Cur=Temp.GetLeft(); // 좌측 이동
		else if(i>=9 && i<11)
			Cur=Temp.GetUp(); // 상단 이동
		else if(i>=11 && i<13)
			Cur=Temp.GetRight(); // 우측 이동
		else if(i==13)
			Cur=Temp.GetDown(); // 하단 이동
		else if(i==14)
			Cur=Temp.GetLeft(); // 좌측 이동
		else if(i==15)
			m_pHead=Cur->GetUp()->GetLeft(); // 마지막에는 헤드에 첫번째 블록 저장
	}
	
	Cur=m_pHead; // 현재 블록

	for(int i=0; i<4; i++) // x, y 좌표를 다시 맞추기 위한 반복문
	{
		for(int j=0; j<4; j++)
		{
			Cur->SetNumber(Cur->GetNum(), i, j);  // 현재 블록의 x, y 좌표 리셋
			if(j==3)
				break;
			Cur=Cur->GetRight(); // 우측 이동
		}
		if(i==3)
			break;
		Cur=Cur->GetDown(); // 하단 이동
		Cur=Cur->GetLeft(); // 좌측 이동
		Cur=Cur->GetLeft(); // 좌측 이동
		Cur=Cur->GetLeft(); // 좌측 이동
	}
}

void MyBoard::IRotate() // 반시계방향 회전
{
	MyBlock * Cur = m_pHead; // 현재 블록
	Cur=Cur->GetRight()->GetRight()->GetRight(); // 우측 끝으로 이동
	MyBlock Temp; // 임시 블록

	for(int i=0; i<16; i++) // 회전을 위한 반복문
	{
		Temp = *Cur; // 임시 블록에 현재 블록 저장

		Cur->SetUp(Temp.GetRight()); // 블록 상단은 우측 블록으로
		Cur->SetDown(Temp.GetLeft()); // 블록 하단은 좌측 블록으로
		Cur->SetRight(Temp.GetDown()); // 블록 우측은 하단 블록으로
		Cur->SetLeft(Temp.GetUp()); // 블록 좌측은 상단 블록으로

		//반시계방향으로 회전하면서 진행 
		if(i<3)
			Cur=Temp.GetLeft();// 좌측 이동
		else if(i>=3 && i<6)
			Cur=Temp.GetDown(); // 하단 이동
		else if(i>=6 && i<9)
			Cur=Temp.GetRight(); // 우측 이동
		else if(i>=9 && i<11)
			Cur=Temp.GetUp(); // 상단 이동
		else if(i>=11 && i<13)
			Cur=Temp.GetLeft(); // 좌측 이동
		else if(i==13)
			Cur=Temp.GetDown(); // 하단 이동
		else if(i==14)
			Cur=Temp.GetRight(); // 우측 이동
		else if(i==15)
			m_pHead=Cur->GetUp()->GetLeft()->GetLeft(); // 헤드에 첫번째 블록 저장
	}
	Cur=m_pHead; // 현재 블록

	for(int i=0; i<4; i++) // x, y 좌표를 재 지정하기 위한 반복문 
	{
		for(int j=0; j<4; j++)
		{
			Cur->SetNumber(Cur->GetNum(), i, j);  // 현재 블록 x, y좌표 리셋
			if(j==3)
				break;
			Cur=Cur->GetRight(); // 우측 이동
		}
		if(i==3)
			break;
		Cur=Cur->GetDown(); // 하단 이동
		Cur=Cur->GetLeft(); // 좌측 이동
		Cur=Cur->GetLeft(); // 좌측 이동
		Cur=Cur->GetLeft(); // 좌측 이동
	}
}

int MyBoard::Print(int x, int y) // x, y좌표에 맞는 숫자를 출력하기 위한 함수
{
	MyBlock * Cur = m_pHead; // 현재 블록
	int se=0; // 시그널 변수

	for(int i=0; i<4; i++) // 숫자 리턴을 위한 반복문
	{
		for(int j=0; j<4; j++)
		{
			if(Cur->GetX()==x && Cur->GetY()==y) // x, y좌표 체크
			{
				return Cur->GetNum(); // 맞다면 숫자 리턴
				se=1; // 시그널 1
				break;
			}
			if(j==3)
				break;
			Cur=Cur->GetRight(); // 우측 이동
		}
		if(i==3)
			break;
		if(se==1) // 시그널 1이면 동작 종료
			break;
		Cur=Cur->GetDown(); // 하단 이동
		Cur=Cur->GetLeft(); // 좌측 이동
		Cur=Cur->GetLeft(); // 좌측 이동
		Cur=Cur->GetLeft(); // 좌측 이동
	}
}
