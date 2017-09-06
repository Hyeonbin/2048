#include "stdafx.h" // 헤더파일 선언
#include "MyBlock.h"
#include <iostream>

using namespace std; // 표준 namespace 사용

MyBlock::MyBlock() // 생성자
{
	m_number=0; // 각 변수 및 블록들 값 초기화
	m_x=0;
	m_y=0;
	m_pUp=0;
    m_pDown=0;
	m_pLeft=0;
	m_pRight=0;
}

MyBlock::~MyBlock() // 소멸자
{}

void MyBlock::SetNumber(int a, int b, int c) // 변수들 값을 함수의 인자들로 초기화
{
	m_number=a; // 인자들로 초기화
	m_x=b; // 인자들로 초기화
	m_y=c; // 인자들로 초기화
}

void MyBlock::SetUp(MyBlock * U) // 상단 블록을 연결
{
	m_pUp=U; // 연결
}

void MyBlock::SetDown(MyBlock * D) // 하단 블록을 연결
{
	m_pDown=D; // 연결
}

void MyBlock::SetLeft(MyBlock * L) // 좌측 블록을 연결
{
	m_pLeft=L; // 연결
}

void MyBlock::SetRight(MyBlock * R) // 우측 블록을 연결
{
	m_pRight=R; // 연결
}

MyBlock * MyBlock::GetUp() // 상단 블록을 리턴
{
	return m_pUp; // 리턴
}

MyBlock * MyBlock::GetDown() // 하단 블록을 리턴
{
	return m_pDown; // 리턴
}

MyBlock * MyBlock::GetLeft() // 좌측 블록을 리턴
{
	return m_pLeft; // 리턴
}

MyBlock * MyBlock::GetRight() // 우측 블록을 리턴
{
	return m_pRight; // 리턴
}

int MyBlock::GetNum() // 블록의 값을 리턴
{
	return m_number; // 리턴
}

int MyBlock::GetX() // x좌표를 리턴
{
	return m_x; // 리턴
}

int MyBlock::GetY() // y좌표를 리턴
{
	return m_y; // 리턴
}