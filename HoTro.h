#pragma once
#include <string.h>
#define MAX_DSVT 500

int toInt(char* content)
{
	int x = 0;
	for (int i = 0; i < strlen(content); i++)
	{
		if (i > 0 && content[i] == '_') break;
		if (content[i] >= '0' && content[i] <= '9') x = x * 10 + (content[i] - '0');
		else return -1;
	}
	return x;
}

float ToFloat(char* content)
{
	double x = atof(content);
	return x;
}

void FloatToChar(float x, char* s)
{
	sprintf(s, "%f", x);
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == '.')
		{
			s[i + 2] = '\0';
			break;
		}
	}
}

bool ChuanHoa(char* s)
{
	int n = strlen(s);
	if (s[0] == ' ' || s[n - 1] == ' ')
	{
		return false;
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			return false;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == ',' || s[i] == ',' || s[i] == '.' || s[i] == '(' || s[i] == ')' || s[i] == '?' || s[i] == ':' || s[i] == ';' || s[i] == '!')
		{
			return false;
		}
	}
	return true;
}

void chuyen_cach(char* sx)
{
	int i=0,n =0,j=0,x = 0;
	while (sx[i]==' ') 
	        i=i+1;          

	while (sx[n]!='\0')
	    n = n +1;
	j=n-1;
	while (sx[j] == ' ')
	          j = j -1 ;
	while (i<=j)
	  {
	  	sx[x] = sx[i];
	  	i=i+1;
	  	x=x+1;
	  }
    for (int z=x;z<=n;z++)  sx[z] ='\0';
    for (int i=0;i<x-1;i++)
     {
     	if (sx[i] ==' ' &&sx[i+1]==' ')
     	     {
     	     	for (int j=i+1;j<x-1;j++)
     	     	      sx[j] = sx[j+1];
     	     	sx[x-1]='\0';
				x=x-1;
     	     	i=i-1;
			  }
	 }
}

void viet_hoa(char* sx)          
{
	if (sx[0]>='a' && sx[0]<='z')
	          sx[0] = char (int(sx[0]) - 32);
	int i = 1;
	while (sx[i] != '\0' )
	  {
	  	if (sx[i-1] ==' ' && (sx[i]>='a' && sx[i+1] <='z'))
	  	    sx[i] = char(int(sx[i]) - 32);
	  	else if ((sx[i] >= 'A' && sx[i]<='Z') && sx[i-1]!=' ')
	  	      sx[i] = char(int (sx[i])+32);
	  	i=i+1;
	  }
}

struct MangDanhSachVatTu {
	VatTu* ds[MAX_DSVT];
	int soluong = 0;
};

void HoanViDoanhThu(VatTu* &a, VatTu* &b)
{
	VatTu* tam = new VatTu;
	tam->soluongTon = a->soluongTon;
	strcpy(tam->maVT, a->maVT);
	a->soluongTon = b->soluongTon;
	strcpy(a->maVT, b->maVT);
	b->soluongTon = tam->soluongTon;
	strcpy(b->maVT, tam->maVT);
	delete tam;
}

void SapXepDoanhThu(MangDanhSachVatTu& mangdt)
{
	for (int i = 0; i < mangdt.soluong; i++)
	{
		for (int j = i + 1; j < mangdt.soluong; j++)
		{
			if (mangdt.ds[i]->soluongTon < mangdt.ds[j]->soluongTon)
			{
				HoanViDoanhThu(mangdt.ds[i], mangdt.ds[j]);
			}
		}
	}
}
