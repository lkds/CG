#pragma once
#include "CP2.h"
class CLine
{
public:
	CLine();
	virtual ~CLine();
	void MoveTo(CDC*, CP2);//�ƶ���ָ��λ��
	void LineTo(CDC*, CP2);//����ֱ�ߣ������յ�
public:
	CP2 P0;//���
	CP2 P1;//�յ�
	CRect rect;
};

