#include "stdafx.h" // ������� ����
#include "MyBoard.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; // ǥ�� namespace ���

MyBlock * n1=new MyBlock; // 16���� ����� ����
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

int sig=0; // �ñ׳� ���� 1 ����
int sig2=0; // �ñ׳� ���� 2 ����

MyBoard::MyBoard() // ������
{
	m_pHead=0; // ��带 0���� �ʱ�ȭ
}

MyBoard::~MyBoard() // �Ҹ���
{}


void MyBoard::Set() // ��ϵ��� ���忡 �����ϴ� �Լ�
{
	n1->SetNumber(0, 0, 0); // ����� ���� �ʱ�ȭ
	n2->SetNumber(0, 0, 1); // ����� ���� �ʱ�ȭ
	n3->SetNumber(0, 0, 2); // ����� ���� �ʱ�ȭ
	n4->SetNumber(0, 0, 3); // ����� ���� �ʱ�ȭ
	n5->SetNumber(0, 1, 0); // ����� ���� �ʱ�ȭ
	n6->SetNumber(0, 1, 1); // ����� ���� �ʱ�ȭ
	n7->SetNumber(0, 1, 2); // ����� ���� �ʱ�ȭ
	n8->SetNumber(0, 1, 3); // ����� ���� �ʱ�ȭ
	n9->SetNumber(0, 2, 0); // ����� ���� �ʱ�ȭ
	n10->SetNumber(0, 2, 1); // ����� ���� �ʱ�ȭ
	n11->SetNumber(0, 2, 2); // ����� ���� �ʱ�ȭ
	n12->SetNumber(0, 2, 3); // ����� ���� �ʱ�ȭ
	n13->SetNumber(0, 3, 0); // ����� ���� �ʱ�ȭ
	n14->SetNumber(0, 3, 1); // ����� ���� �ʱ�ȭ
	n15->SetNumber(0, 3, 2); // ����� ���� �ʱ�ȭ
	n16->SetNumber(0, 3, 3); // ����� ���� �ʱ�ȭ
	n1->SetUp(0); // ����� �����¿� ��ϵ� ����
	n1->SetDown(n5);
	n1->SetLeft(0);
	n1->SetRight(n2);
	n2->SetUp(0); // ����� �����¿� ��ϵ� ����
	n2->SetDown(n6);
	n2->SetLeft(n1);
	n2->SetRight(n3);
	n3->SetUp(0); // ����� �����¿� ��ϵ� ����
	n3->SetDown(n7);
	n3->SetLeft(n2);
	n3->SetRight(n4);
	n4->SetUp(0); // ����� �����¿� ��ϵ� ����
	n4->SetDown(n8);
	n4->SetLeft(n3);
	n4->SetRight(0);
	n5->SetUp(n1); // ����� �����¿� ��ϵ� ����
	n5->SetDown(n9);
	n5->SetLeft(0);
	n5->SetRight(n6);
	n6->SetUp(n2); // ����� �����¿� ��ϵ� ����
	n6->SetDown(n10);
	n6->SetLeft(n5);
	n6->SetRight(n7);
	n7->SetUp(n3); // ����� �����¿� ��ϵ� ����
	n7->SetDown(n11);
	n7->SetLeft(n6);
	n7->SetRight(n8);
	n8->SetUp(n4); // ����� �����¿� ��ϵ� ����
	n8->SetDown(n12);
	n8->SetLeft(n7);
	n8->SetRight(0);
	n9->SetUp(n5); // ����� �����¿� ��ϵ� ����
	n9->SetDown(n13);
	n9->SetLeft(0);
	n9->SetRight(n10);
	n10->SetUp(n6); // ����� �����¿� ��ϵ� ����
	n10->SetDown(n14);
	n10->SetLeft(n9);
	n10->SetRight(n11);
	n11->SetUp(n7); // ����� �����¿� ��ϵ� ����
	n11->SetDown(n15);
	n11->SetLeft(n10);
	n11->SetRight(n12);
	n12->SetUp(n8); // ����� �����¿� ��ϵ� ����
	n12->SetDown(n16);
	n12->SetLeft(n11);
	n12->SetRight(0);
	n13->SetUp(n9); // ����� �����¿� ��ϵ� ����
	n13->SetDown(0);
	n13->SetLeft(0);
	n13->SetRight(n14);
	n14->SetUp(n10); // ����� �����¿� ��ϵ� ����
	n14->SetDown(0);
	n14->SetLeft(n13);
	n14->SetRight(n15);
	n15->SetUp(n11); // ����� �����¿� ��ϵ� ����
	n15->SetDown(0);
	n15->SetLeft(n14);
	n15->SetRight(n16);
	n16->SetUp(n12); // ����� �����¿� ��ϵ� ����
	n16->SetDown(0);
	n16->SetLeft(n15);
	n16->SetRight(0);
	m_pHead=n1; // ��带 ù��° ������� ����
	srand(time(0)); // �����Լ� ����

	for(int j=0; j<2; j++) // �� ���� ���� ���� ����
	{
		while(1) // ���� ����
		{
			int i=rand()%16+1; // 16������ �� �� ����
			if(Init(i)==0) // 0�� ��� ���� ����
				break;
			else // �׷��� ������ �� ����
				continue;
		}
	}
}

bool MyBoard::Up(int s) // ���� ������ ���
{
	if(s==1)
		return true; // 1�� ����
	else
		return false; // 0�� ����
}

bool MyBoard::Down(int s) // �Ʒ��� ������ ���
{
	if(s==2)
		return true; // 1�� ����
	else
		return false; // 0�� ����
}


bool MyBoard::Left(int s) // ���� ������ ���
{
	if(s==3)
		return true; // 1�� ����
	else
		return false; // 0�� ����
}


bool MyBoard::Right(int s) // ������ ������ ���
{
	if(s==4)
		return true; // 1�� ����
	else
		return false; // 0�� ����
}

void MyBoard::U() // ��� �̵�
{
	MyBlock * Cur = m_pHead; // ���� ��� ����
	MyBlock * Cmp = new MyBlock; // ���� ���
	int temp=0; // �ӽú���
	int s=0; // �ñ׳� ����

	for(int k=0; k<4; k++) // ��� ���� �� ����
	{
		if(Cur->GetNum() == Cur->GetDown()->GetNum() && Cur->GetDown()->GetDown()->GetNum() == Cur->GetDown()->GetDown()->GetDown()->GetNum())
			s=-1; // �� ��Ͼ� ���ʴ�� ���� ���� ���
		else
			s=0; // �׷��� ���� ���

		for(int i=0; i<3; i++)
		{
			Cmp=Cur; // �� ��Ͽ� ���� ��� ����
			for(int j=i; j<3; j++)
			{
				if(Cmp->GetNum()==0) // �� ����� 0�̶�� 
				{
					temp=Cmp->GetNum(); // ���� ��ϰ� swap
					Cmp->SetNumber(Cmp->GetDown()->GetNum(), Cmp->GetX(), Cmp->GetY()); // ���� ��ϰ� swap
					Cmp->GetDown()->SetNumber(temp, Cmp->GetDown()->GetX(), Cmp->GetDown()->GetY()); // ���� ��ϰ� swap
				}
				else // �׷��� �ʴٸ�
				{
					if(Cmp->GetDown()->GetNum()==Cmp->GetNum()) // �� ����� ���� ���ٸ�
					{
						if(s!=1) // s�� 1�� �ƴ� ���
						{
							Cmp->SetNumber(Cmp->GetDown()->GetNum()+Cmp->GetNum(), Cmp->GetX(), Cmp->GetY()); // �� ����� ��ħ
							Cmp->GetDown()->SetNumber(0, Cmp->GetDown()->GetX(), Cmp->GetDown()->GetY()); // �� ����� ��ħ
							s++; // s�� 1 ����
						}
					}
				}
				Cmp=Cmp->GetDown(); // �� ��� �Ʒ��� �̵�
			}
		}
		Cur=Cur->GetRight(); // ���� ��� ���������� �̵�
	}
}

void MyBoard::D() // �ϴ� �̵�
{
	MyBlock * Cur = m_pHead; // ���� ���
	MyBlock * Cmp = new MyBlock; // �� ���
	int temp=0; // �ӽ� ����
	int s=0; // �ñ׳� ����

	Cur=Cur->GetDown(); // ���� ����� �� ������ �̵�
	Cur=Cur->GetDown(); // �̵�
	Cur=Cur->GetDown(); // �̵�
	
	for(int k=0; k<4; k++) // ��� �̵� ���� ����
	{
		if(Cur->GetNum() == Cur->GetUp()->GetNum() && Cur->GetUp()->GetUp()->GetNum() == Cur->GetUp()->GetUp()->GetUp()->GetNum())
			s=-1; // ������� �� ��Ͼ� ���� ���� ���
		else
			s=0; // �׷��� ���� ���

		for(int i=0; i<3; i++)
		{
			Cmp=Cur; // �� ��Ͽ� ���� ��� ����
			for(int j=i; j<3; j++)
			{
				if(Cmp->GetNum()==0) // �� ����� 0�̶�� 
				{
					temp=Cmp->GetNum(); // ���� ��ϰ� swap
					Cmp->SetNumber(Cmp->GetUp()->GetNum(), Cmp->GetX(), Cmp->GetY()); // ���� ��ϰ� swap
					Cmp->GetUp()->SetNumber(temp, Cmp->GetUp()->GetX(), Cmp->GetUp()->GetY()); // ���� ��ϰ� swap
				}
				else // �׷��� �ʴٸ�
				{
					if(Cmp->GetUp()->GetNum()==Cmp->GetNum()) // ���� ��ϰ� ���� ���ٸ� 
					{
						if(s!=1) // s�� 1�� �ƴ� ���
						{
							Cmp->SetNumber(Cmp->GetUp()->GetNum()+Cmp->GetNum(), Cmp->GetX(), Cmp->GetY()); // �� ����� ��ģ��
							Cmp->GetUp()->SetNumber(0, Cmp->GetUp()->GetX(), Cmp->GetUp()->GetY()); // ��ģ��
							s++; // s�� 1 ����
						}
					}
				}
				Cmp=Cmp->GetUp(); // �� ����� ������� �̵�
			}
		}
		Cur=Cur->GetRight(); // ���� ����� �������� �̵�
	}
}

void MyBoard::L() // ���� �̵� 
{
	MyBlock * Cur = m_pHead;// ���� ���
	MyBlock * Cmp = new MyBlock; // �� ���
	int temp=0; // �ӽ� ����
	int s=0; // �ñ׳� ����

	for(int k=0; k<4; k++) // �̵� ����
	{
		if(Cur->GetNum() == Cur->GetRight()->GetNum() && Cur->GetRight()->GetRight()->GetNum() == Cur->GetRight()->GetRight()->GetRight()->GetNum())
			s=-1; // �ν־� ���ʴ�� ���� ���� ���
		else
			s=0; // �׷��� ���� ���

		for(int i=0; i<3; i++)
		{
			Cmp=Cur; // �� ��Ͽ� ���� ��� ����
			for(int j=i; j<3; j++)
			{
				if(Cmp->GetNum()==0) // �� ����� ���� 0�� ���
				{
					temp=Cmp->GetNum(); // ���� ��ϰ� swap
					Cmp->SetNumber(Cmp->GetRight()->GetNum(), Cmp->GetX(), Cmp->GetY()); // ���� ��ϰ� swap
					Cmp->GetRight()->SetNumber(temp, Cmp->GetRight()->GetX(), Cmp->GetRight()->GetY()); // ���� ��ϰ� swap
				}
				else // �׷��� �ʴٸ�
				{
					if(Cmp->GetRight()->GetNum()==Cmp->GetNum()) // ���� ��ϰ� ���� ���
					{
						if(s!=1) // �ñ׳��� 1�� �ƴ϶��
						{
							Cmp->SetNumber(Cmp->GetRight()->GetNum()+Cmp->GetNum(), Cmp->GetX(), Cmp->GetY()); // �� ����� ��ģ��
							Cmp->GetRight()->SetNumber(0, Cmp->GetRight()->GetX(), Cmp->GetRight()->GetY()); // ��ģ��
							s++; // s�� 1 ����
						}
					}
				}
				Cmp=Cmp->GetRight(); // �� ��� �������� �̵�
			}
		}
		Cur=Cur->GetDown(); // ���� ��� �ϴ����� �̵�
	}
}	

void MyBoard::R() // ���� �̵� �Լ�
{
	MyBlock * Cur = m_pHead; // ���� ���
	MyBlock * Cmp = new MyBlock; // �� ���
	int temp=0; // �ӽ� ����
	int s=0; // �ñ׳� ����

	Cur=Cur->GetRight(); // ���� ��� �������� �̵�
	Cur=Cur->GetRight(); // �̵�
	Cur=Cur->GetRight(); // �̵�

	for(int k=0; k<4; k++)
	{
		if(Cur->GetNum() == Cur->GetLeft()->GetNum() && Cur->GetLeft()->GetLeft()->GetNum() == Cur->GetLeft()->GetLeft()->GetLeft()->GetNum())
			s=-1; // �� �־� ���� ���� ���
		else
			s=0; // �׷��� ���� ���

		for(int i=0; i<3; i++)
		{
			Cmp=Cur; // �� ��Ͽ� ���� ��� ����
			for(int j=0; j<3-i; j++)
			{
				if(Cmp->GetNum()==0) // �� ����� ���� 0�� ���
				{
					temp=Cmp->GetNum(); // ���� ��ϰ� swap
					Cmp->SetNumber(Cmp->GetLeft()->GetNum(), Cmp->GetX(), Cmp->GetY()); // ���� ��ϰ� swap
					Cmp->GetLeft()->SetNumber(temp, Cmp->GetLeft()->GetX(), Cmp->GetLeft()->GetY()); // ���� ��ϰ� swap
				}
				else // �׷��� �ʴٸ�
				{
					if(Cmp->GetLeft()->GetNum()==Cmp->GetNum()) // ���� ��ϰ� ���� ���ٸ�
					{
						if(s!=1) // s�� 1�� ���
						{
							Cmp->SetNumber(Cmp->GetLeft()->GetNum()+Cmp->GetNum(), Cmp->GetX(), Cmp->GetY()); // �� ����� ��ħ
							Cmp->GetLeft()->SetNumber(0, Cmp->GetLeft()->GetX(), Cmp->GetLeft()->GetY()); // ��ģ��
							s++; // s�� 1 ����
						}
					}
				}
				Cmp=Cmp->GetLeft(); // �� ��� �������� �̵�
			}
		}
		Cur=Cur->GetDown(); // ���� ��� �ϴ����� �̵�
	}
}	

void MyBoard::Print() // ��� �Լ�
{
	MyBlock * Cur = m_pHead; // ���� ���

	cout<<"[Board]"<<endl; // ���ڿ� ���

	for(int i=0; i<4; i++) // ����� ���� �ݺ���
	{
		cout<<"[  "; // ���ڿ� ���
		for(int j=0; j<4; j++)
		{
			cout<<Cur->GetNum()<<"  "; // ��� �� ���
			if(j==3)
				break;
			Cur=Cur->GetRight(); // ���� �̵�
		}
		cout<<"]"<<endl; // ���ڿ� ���
		if(i==3)
			break;
		Cur=Cur->GetDown(); // �ϴ� �̵�
		Cur=Cur->GetLeft(); // ���� �̵�
		Cur=Cur->GetLeft(); // �̵�
		Cur=Cur->GetLeft(); // �̵�
	}
}

int MyBoard::Init(int i) // �� ��Ͽ� 2�� �ִ� �Լ�
{
	MyBlock * Cur = m_pHead; // ���� ���

	for(int j=0; j<i-1; j++) // ������� �̵��ϴ� �Լ�
	{
		if(j==3 || j==7 || j==11) // ���� ���� ���
		{
			Cur=Cur->GetDown();  // �ϴ� �̵�
			Cur=Cur->GetLeft(); // ���� �̵�
			Cur=Cur->GetLeft(); // �̵�
			Cur=Cur->GetLeft(); // �̵�
		}
		else // �ƴϸ�
			Cur=Cur->GetRight(); // ���� �̵�
	}

	if(Cur->GetNum()==0) // ����� ���� 0�� ���
	{
		Cur->SetNumber(2, Cur->GetX(), Cur->GetY()); // 2�� ����
		return 0; // 0�� ��ȯ
	}
	else // �׷��� ������
	{
		if(sig2==0) // �ñ׳�2�� 0�� �ܿ�
			return 0; // 0�� ��ȯ
		else // �׷��� �ʴٸ� 
			return 1; // 1�� ��ȯ
	}
}

int MyBoard::Win() // �¸� ������ �˻��ϴ� �Լ�
{
	MyBlock * Cur = m_pHead; // ���� ���
	int i=0; // �ݺ��� ����
	sig=0; // �ñ׳�
	sig2=0; // �ñ׳�2

	while(Cur!=0) // ���� ����� ������ �ݺ�
	{
		if(Cur->GetNum()==0) // ����� ���� 0�̶��
			sig2=1; // �ñ׳�2�� ���� 1��

		if(Cur->GetNum()==2048) // 2048�� ã�´ٸ�
		{
			return 1; // 1�� ��ȯ
			break;
		}

		if(i==3 || i==7 || i==11) // ���� ���� ���
		{
			i++; // i 1 ����
			Cur=Cur->GetDown(); // �ϴ����� �̵�	
			Cur=Cur->GetLeft(); // �������� �̵�
			Cur=Cur->GetLeft(); // �̵�
			Cur=Cur->GetLeft(); // �̵�
			continue;
		}
		else // �׷��� �ʴٸ� 
		{
			i++; // i 1 ����
			Cur=Cur->GetRight(); // ���� �̵�
			continue; 
		}
	}

	if(i==16 && sig2==0) // 2048�� ���� ���尡 �� �� ���
	{
		Cur=m_pHead; // ���� ���
		int j=0;
		while(Cur!=0) // �̵� ���� ����� ã�� ���� �ݺ���
		{
			if(Cur->GetDown()!=NULL) // �ϴܿ� ����� �ִٸ�
			{
				if(Cur->GetNum()==Cur->GetDown()->GetNum()) // ��� ���� ���� ���ٸ�
				{
					return 0; // 0�� ����
					sig=1; // �ñ׳� 1
					break; 
				}
			}
			if(Cur->GetRight()!=NULL) // ������ ����� �ִٸ�
			{
				if(Cur->GetNum()==Cur->GetRight()->GetNum()) // ��� ���� ���� ���ٸ�
				{
					return 0; // 0�� ����
					sig=1; // �ñ׳� 1
					break;
				}
			}

			if(j==3 || j==7 || j==11) // �� �ٲ�
			{
				j++; // j 1 ����
				Cur=Cur->GetDown(); // �ϴ� �̵� 
				Cur=Cur->GetLeft(); // ���� �̵�
				Cur=Cur->GetLeft(); // ���� �̵�
				Cur=Cur->GetLeft(); // ���� �̵�
				continue;
			}
			else // �׷��� �ʴٸ�
			{
				j++; // j 1 ����
				Cur=Cur->GetRight(); // ���� �̵�
				continue;
			}
		}
		if(j==16) // j�� 16�̶��
			return 2; // �й�
	}
}

void MyBoard::CRotate() // �ð���� ȸ��
{
	MyBlock * Cur = m_pHead; // ���� ���
	MyBlock Temp; // �ӽ� ���

	for(int i=0; i<16; i++) // ����� ȸ���� ���� �ݺ���
	{
		Temp = *Cur; // �ӽ� ��Ͽ� ���� ��� ����

		Cur->SetUp(Temp.GetLeft()); // ��� ����� ���� �������
		Cur->SetDown(Temp.GetRight()); // �ϴ� ����� ���� �������
		Cur->SetRight(Temp.GetUp()); // ���� ����� ��� �������
		Cur->SetLeft(Temp.GetDown()); // ���� ����� �ϴ� �������

		//�ð� �������� �̵�
		if(i<3)
			Cur=Temp.GetRight(); // ���� �̵�
		else if(i>=3 && i<6) 
			Cur=Temp.GetDown(); // �ϴ� �̵�
		else if(i>=6 && i<9)
			Cur=Temp.GetLeft(); // ���� �̵�
		else if(i>=9 && i<11)
			Cur=Temp.GetUp(); // ��� �̵�
		else if(i>=11 && i<13)
			Cur=Temp.GetRight(); // ���� �̵�
		else if(i==13)
			Cur=Temp.GetDown(); // �ϴ� �̵�
		else if(i==14)
			Cur=Temp.GetLeft(); // ���� �̵�
		else if(i==15)
			m_pHead=Cur->GetUp()->GetLeft(); // ���������� ��忡 ù��° ��� ����
	}
	
	Cur=m_pHead; // ���� ���

	for(int i=0; i<4; i++) // x, y ��ǥ�� �ٽ� ���߱� ���� �ݺ���
	{
		for(int j=0; j<4; j++)
		{
			Cur->SetNumber(Cur->GetNum(), i, j);  // ���� ����� x, y ��ǥ ����
			if(j==3)
				break;
			Cur=Cur->GetRight(); // ���� �̵�
		}
		if(i==3)
			break;
		Cur=Cur->GetDown(); // �ϴ� �̵�
		Cur=Cur->GetLeft(); // ���� �̵�
		Cur=Cur->GetLeft(); // ���� �̵�
		Cur=Cur->GetLeft(); // ���� �̵�
	}
}

void MyBoard::IRotate() // �ݽð���� ȸ��
{
	MyBlock * Cur = m_pHead; // ���� ���
	Cur=Cur->GetRight()->GetRight()->GetRight(); // ���� ������ �̵�
	MyBlock Temp; // �ӽ� ���

	for(int i=0; i<16; i++) // ȸ���� ���� �ݺ���
	{
		Temp = *Cur; // �ӽ� ��Ͽ� ���� ��� ����

		Cur->SetUp(Temp.GetRight()); // ��� ����� ���� �������
		Cur->SetDown(Temp.GetLeft()); // ��� �ϴ��� ���� �������
		Cur->SetRight(Temp.GetDown()); // ��� ������ �ϴ� �������
		Cur->SetLeft(Temp.GetUp()); // ��� ������ ��� �������

		//�ݽð�������� ȸ���ϸ鼭 ���� 
		if(i<3)
			Cur=Temp.GetLeft();// ���� �̵�
		else if(i>=3 && i<6)
			Cur=Temp.GetDown(); // �ϴ� �̵�
		else if(i>=6 && i<9)
			Cur=Temp.GetRight(); // ���� �̵�
		else if(i>=9 && i<11)
			Cur=Temp.GetUp(); // ��� �̵�
		else if(i>=11 && i<13)
			Cur=Temp.GetLeft(); // ���� �̵�
		else if(i==13)
			Cur=Temp.GetDown(); // �ϴ� �̵�
		else if(i==14)
			Cur=Temp.GetRight(); // ���� �̵�
		else if(i==15)
			m_pHead=Cur->GetUp()->GetLeft()->GetLeft(); // ��忡 ù��° ��� ����
	}
	Cur=m_pHead; // ���� ���

	for(int i=0; i<4; i++) // x, y ��ǥ�� �� �����ϱ� ���� �ݺ��� 
	{
		for(int j=0; j<4; j++)
		{
			Cur->SetNumber(Cur->GetNum(), i, j);  // ���� ��� x, y��ǥ ����
			if(j==3)
				break;
			Cur=Cur->GetRight(); // ���� �̵�
		}
		if(i==3)
			break;
		Cur=Cur->GetDown(); // �ϴ� �̵�
		Cur=Cur->GetLeft(); // ���� �̵�
		Cur=Cur->GetLeft(); // ���� �̵�
		Cur=Cur->GetLeft(); // ���� �̵�
	}
}

int MyBoard::Print(int x, int y) // x, y��ǥ�� �´� ���ڸ� ����ϱ� ���� �Լ�
{
	MyBlock * Cur = m_pHead; // ���� ���
	int se=0; // �ñ׳� ����

	for(int i=0; i<4; i++) // ���� ������ ���� �ݺ���
	{
		for(int j=0; j<4; j++)
		{
			if(Cur->GetX()==x && Cur->GetY()==y) // x, y��ǥ üũ
			{
				return Cur->GetNum(); // �´ٸ� ���� ����
				se=1; // �ñ׳� 1
				break;
			}
			if(j==3)
				break;
			Cur=Cur->GetRight(); // ���� �̵�
		}
		if(i==3)
			break;
		if(se==1) // �ñ׳� 1�̸� ���� ����
			break;
		Cur=Cur->GetDown(); // �ϴ� �̵�
		Cur=Cur->GetLeft(); // ���� �̵�
		Cur=Cur->GetLeft(); // ���� �̵�
		Cur=Cur->GetLeft(); // ���� �̵�
	}
}
