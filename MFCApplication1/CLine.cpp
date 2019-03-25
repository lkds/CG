#include "pch.h"
#include "CLine.h"


CLine::CLine()
{
}


CLine::~CLine()
{
}

void CLine::MoveTo(CDC* pDC, CP2 p0)
{
	P0 = p0;
}

void CLine::LineTo(CDC* pDC, CP2 p1) {
	P1 = p1;
	CP2 p, t;

	if (fabs(P0.x - P1.x) < 1e-6)//绘制垂线
	{
		if (P0.y > P1.y)//交换顶点，使起始点低于终点
		{
			t = P0;
			P0 = P1;
			P1 = t;
		}
		for (p = P0; p.y < P1.y; p.y++)
		{
			double i = (p.y - P0.y) / (P1.y - P0.y);
			pDC->SetPixelV(round(p.x), round(p.y), RGB(255 * i, 255 * (1 - i), 0));
		}

	}
	else {

		double k, d;
		k = (P1.y - P0.y) / (P1.x - P0.x);
		if (k > 1.0)//绘制k>1
		{
			if (P0.y > P1.y)
			{
				t = P0;
				P0 = P1;
				P1 = t;
			}
			d = 1 - 0.5 * k;
			for (p = P0; p.y < P1.y; p.y++)
			{
				double i = (p.y - P0.y) / (P1.y - P0.y);
				pDC->SetPixelV(round(p.x), round(p.y), RGB(255 * i, 255 * (1 - i), 0));
				if (d >= 0)
				{
					p.x++;
					d += 1 - k;
				}
				else
				{
					d += 1;

				}
			}

		}

		else if (k <= 1.0 && k >= 0)//绘制k<1
		{
			if (P0.x > P1.x)
			{
				t = P0;
				P0 = P1;
				P1 = t;
			}
			d = 0.5-k;
			for (p = P0; p.x < P1.x; p.x++)
			{
				double i = (p.x - P0.x) / (P1.x - P0.x);
				pDC->SetPixelV(round(p.x), round(p.y), RGB(255 * i, 255 * (1 - i), 0));
				if (d < 0)
				{
					p.y++;
					d += 1 - k;
				}
				else
				{
					d -= k;

				}
			}
		}
		else if (k < -1.0)//绘制k<-1
		{
			if (P0.y < P1.y)
			{
				t = P0;
				P0 = P1;
				P1 = t;
			}
			d = -1 - 0.5 * k;
			for (p = P0; p.y > P1.y; p.y--)
			{
				double i = (p.y - P0.y) / (P1.y - P0.y);
				pDC->SetPixelV(round(p.x), round(p.y), RGB(255 * i, 255 * (1 - i), 0));
				if (d < 0)
				{
					p.x++;
					d -= 1 + k;
				}
				else
				{
					d -= 1;

				}
			}
		}
		else if (k >= -1.0 && k < 0)//绘制-1<=k<0
		{
			if (P0.x > P1.x)
			{
				t = P0;
				P0 = P1;
				P1 = t;
			}
			d = -0.5 - k;
			for (p = P0; p.x < P1.x; p.x++)
			{
				double i = (p.x - P0.x) / (P1.x - P0.x);
				pDC->SetPixelV(round(p.x), round(p.y), RGB(255 * i, 255 * (1 - i), 0));
				if (d > 0)
				{
					p.y--;
					d -= 1 + k;
				}
				else
				{
					d -= k;

				}
			}
		}
		P0 = p1;
	}
}