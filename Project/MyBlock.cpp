#include "stdafx.h" // ������� ����
#include "MyBlock.h"
#include <iostream>

using namespace std; // ǥ�� namespace ���

MyBlock::MyBlock() // ������
{
	m_number=0; // �� ���� �� ��ϵ� �� �ʱ�ȭ
	m_x=0;
	m_y=0;
	m_pUp=0;
    m_pDown=0;
	m_pLeft=0;
	m_pRight=0;
}

MyBlock::~MyBlock() // �Ҹ���
{}

void MyBlock::SetNumber(int a, int b, int c) // ������ ���� �Լ��� ���ڵ�� �ʱ�ȭ
{
	m_number=a; // ���ڵ�� �ʱ�ȭ
	m_x=b; // ���ڵ�� �ʱ�ȭ
	m_y=c; // ���ڵ�� �ʱ�ȭ
}

void MyBlock::SetUp(MyBlock * U) // ��� ����� ����
{
	m_pUp=U; // ����
}

void MyBlock::SetDown(MyBlock * D) // �ϴ� ����� ����
{
	m_pDown=D; // ����
}

void MyBlock::SetLeft(MyBlock * L) // ���� ����� ����
{
	m_pLeft=L; // ����
}

void MyBlock::SetRight(MyBlock * R) // ���� ����� ����
{
	m_pRight=R; // ����
}

MyBlock * MyBlock::GetUp() // ��� ����� ����
{
	return m_pUp; // ����
}

MyBlock * MyBlock::GetDown() // �ϴ� ����� ����
{
	return m_pDown; // ����
}

MyBlock * MyBlock::GetLeft() // ���� ����� ����
{
	return m_pLeft; // ����
}

MyBlock * MyBlock::GetRight() // ���� ����� ����
{
	return m_pRight; // ����
}

int MyBlock::GetNum() // ����� ���� ����
{
	return m_number; // ����
}

int MyBlock::GetX() // x��ǥ�� ����
{
	return m_x; // ����
}

int MyBlock::GetY() // y��ǥ�� ����
{
	return m_y; // ����
}