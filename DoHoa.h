#pragma once
#include "define.h"
#include "CTDL.h"
#include "stdlib.h"
#include "XuLy.h"

void VeBangHoaDon(int trang);
void VeBangNhanVien(int trang);
void VeBangVatTu(int trang);
void VeBangThongKeHD(int trang);
void VeBangTopVatTu(int trang);
void VeBangInHD(int trang);
void ResetmapID();
void GanID(int x1, int y1, int x2, int y2, int id);
void ClearStream();
void TaoHCN(int x1, int y1, int x2, int y2, int id, int mau, int mauvien);
void TaoDong(int x1, int y1, int chieucao, int mangdodai[], int mau, int mauvien, int id, int socot);
void TaoBang(int x1, int y1, int chieucao, int socot, int mangdodai[], int mau, int mauvien, int sodong, int id, int trang, char td[][50]);
void VeKhungVien(int x1, int y1, int x2, int y2, int mauvien);
void TaoTextThongBao(int x1, int y1, int x2, int y2, int mauvien, int mauchu, int maufill, char text[]);
void TaoText(int x1, int y1, int x2, int y2, int mauvien, int mauchu, int maufill, char text[]);
void TaoTextInput(int x1, int y1, int x2, int y2, int mauvien, int maufill, char text[], int id);
void InDanhSachVatTu(MangDanhSachVatTu mangds, int trang);
long long DoanhThuMotHoaDon(HoaDon* p);
int SoLuongHoaDonTheoNgay(DanhSachNhanVien dsnv, Date start, Date end);
void InDanhSachHoaDonTheoNgay(DanhSachNhanVien dsnv, tree root, Date start, Date end, int trang);
void InHoaDon(DS_CHITIETHOADON dscthd, tree root, int trang); // Man 3
void DoanhThuMotVatTu(MangDanhSachVatTu &mangdt, MangDanhSachVatTu mangds, DanhSachNhanVien dsnv, Date start, Date end); // Bo vao mang doanh thu
int SoLuongXuatMotVatTu(char* MAVT, tree root, DanhSachNhanVien dsnv, Date start, Date end);
void InTopDoanhThu(MangDanhSachVatTu mangdt, tree root, DanhSachNhanVien dsnv, Date start, Date end, int trang);
void InFullChiTietHoaDon(DS_CHITIETHOADON dscthd, tree root,  int trang);
void NhapSo(char s[], int max, int kieuso, int px, int py, int ID, int& IDnext);
void ScannerString(char s[], int max, int px, int py, int ID, int& IDnext);
void NhapChuoi(char s[], int max, int px, int py, int ID, int& IDnext);
void VeTabVatTu();
void VeTabNhanVien();
void VeTabHoaDon();
void VeTabThongKe();
void VeTabInHD();
void VeBangVatTu(int trang);
void VeBangNhanVien(int trang);
void VeBangHoaDon(int trang);
void VeBangThongTin();
void VeBangHuongDan();
void VeBangThongKeHD(int trang);
void VeBangInHD(int trang);
void ManHinh1();
void ManHinh2(); 
void ManHinh3();
void ManHinh4();
void Man4_1();
void ManHinhInHD();
void ResetConTentMan1(char soluong[7], char donvi[11], char tenvt[15], char mavt[11]);
void ResetConTentMan2(char phai[4], char tennv[11], char ho[16], char manv[5]);
void ResetConTentMan3(char , char, char, char, char, char, char, char, char, char, char, char, int, int, int);
void XuLy(tree& root, DanhSachNhanVien& dsnv, DS_ChiTietHoaDon& dscthd, MangDanhSachVatTu& mangds);
int mapID[NGANG][DOC];

void ResetmapID()
{
	for (int i = 0; i < NGANG; i++)
	{
		for (int j = 0; j < DOC; j++)
		{
			mapID[i][j] = 0;
		}
	}
}

void GanID(int x1, int y1, int x2, int y2, int id)
{
	for (int i = x1; i < x2; i++)
	{
		for (int j = y1; j < y2; j++)
		{
			mapID[i][j] = id;
		}
	}
}

void ClearStream()
{
	while (kbhit())
	{
		char c = getch();
	}
}
void ClearColor()
{
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void TaoHCN(int x1, int y1, int x2, int y2, int id, int mau, int mauvien)
{
	setfillstyle(1, mau);
	bar(x1, y1, x2, y2);
	setcolor(mauvien);
	rectangle(x1, y1, x2, y2);
	GanID(x1, y1, x2, y2, id);
}
void TaoDong(int x1, int y1, int chieucao, int mangdodai[], int mau, int mauvien, int id, int socot)
{
	int y2 = y1 + chieucao;
	int x2;
	for (int i = 0; i < socot; i++)
	{
		x2 = x1 + mangdodai[i];
		TaoHCN(x1, y1, x2, y2, id, mau, mauvien);
		x1 = x2;
	}
}
void TaoBang(int x1, int y1, int chieucao, int socot, int mangdodai[], int mau, int mauvien, int sodong, int id, int trang, char td[][50])
{
	setcolor(0);
	setbkcolor(mau);
	int y2;
	int y = y1;
	for (int i = 1; i <= sodong; i++)
	{
		TaoDong(x1, y1, chieucao, mangdodai, mau, mauvien, id + i, socot);
		if (i != 1)
		{
			char temp[4];
			itoa((i - 1) + 10 * (trang - 1), temp, 10); // id =  15, trang = 10 => 14+10*14
			if (i < 11)
			{
				outtextxy(x1 + 35, y1 + 10, temp);
			}
			else
				outtextxy(x1 + 29, y1 + 10, temp);
		}
		y2 = y1 + chieucao;
		y1 = y2;
	}
	for (int i = 0; i < socot; i++)
	{
		outtextxy(x1 + 5, y + 5, td[i]);
		x1 = x1 + mangdodai[i];
	}
}

void VeKhungVien(int x1, int y1, int x2, int y2, int mauvien)
{
	setcolor(mauvien);
	rectangle(x1, y1, x2, y2);
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void TaoTextThongBao(int x1, int y1, int x2, int y2, int mauvien, int mauchu, int maufill, char text[])
{
	setcolor(mauvien); // rec
	setfillstyle(1, maufill);
	bar(x1, y1, x2, y2);
	rectangle(x1, y1, x2, y2);
	setcolor(mauchu);
	setbkcolor(maufill); // Xoa net vien chu
	outtextxy(x1 + 10, y1 + 12, text);
	setcolor(MAUDEN);
}

void TaoText(int x1, int y1, int x2, int y2, int mauvien, int mauchu, int maufill, char text[])
{
	settextstyle(0, 0, 2);
	setcolor(mauvien); // rec
	setfillstyle(1, maufill);
	bar(x1, y1, x2, y2);
	rectangle(x1, y1, x2, y2);
	setcolor(mauchu);
	setbkcolor(maufill); // Xoa net vien chu
	outtextxy(x1 + 10, y1 + 12, text);
	setcolor(MAUDEN);
}

void TaoTextInput(int x1, int y1, int x2, int y2, int mauvien, int maufill, char text[], int id)
{
	settextstyle(0, 0, 2);
	setcolor(mauvien); // rec
	setfillstyle(1, maufill);
	bar(x1, y1, x2, y2);
	rectangle(x1, y1, x2, y2);
	setcolor(MAUTRANG);
	setbkcolor(maufill); // Xoa net vien chu
	outtextxy(x1 + 10, y1 + 12, text);
	GanID(x1, y1, x2, y2, id); // Gan ID
	setcolor(MAUDEN);
}


// In danh sach vat tu Man1
void InDanhSachVatTu(MangDanhSachVatTu mangds, int trang)
{
	VeBangVatTu(trang);
	int y1 = 275;
	setcolor(MAUDEN);
	int x1 = 420;
	SapXepVatTuTheoTen(mangds);
	for (int i = 0; i < mangds.soluong; i++)
	{
		if (i < trang * 10 && i >= (trang - 1) * 10)
		{
			outtextxy(420, y1, mangds.ds[i]->maVT);
			outtextxy(620, y1, mangds.ds[i]->tenVT);
			outtextxy(910, y1, mangds.ds[i]->donviTinh);
			char* ch = new char;;
			itoa(mangds.ds[i]->soluongTon, ch, 10);
			outtextxy(1140, y1, ch);
			y1 = y1 + 40;
		}
	}
}

// Doanh Thu 1 Hoa Don
long long DoanhThuMotHoaDon(HoaDon* p)
{
	long long doanhthu = 0;
	for (int i = 0; i < p->List_CTHD.sl; i++)
	{
		long long a = (p->List_CTHD.cthd[i].VAT/100 + 1) * p->List_CTHD.cthd[i].donGia;
		long long b = a * p->List_CTHD.cthd[i].soLuong;
		doanhthu = doanhthu + b;
	}
	return doanhthu;
}


// So luong hoa don theo ngay - Man41
int SoLuongHoaDonTheoNgay(DanhSachNhanVien dsnv, Date start, Date end)
{
	int dem = 0;
	for (int i = 0; i < dsnv.slnv; i++)
	{
		HoaDon* p = dsnv.ds[i]->Head;
		while (p != NULL && SoNgayGiuaHaiNgay(start, p->ngaylapHD) >= 0 && SoNgayGiuaHaiNgay(p->ngaylapHD, end) >= 0)
		{
			dem = dem + 1;
			p = p->next;
		}
	}
	return dem;
}

// In danh sach hoa don theo ngay Man4
void InDanhSachHoaDonTheoNgay(DanhSachNhanVien dsnv, tree root, Date start, Date end, int trang)
{
	VeBangThongKeHD(trang);
	int y1 = 280;
	setcolor(MAUDEN);
	int x1 = 420;
	char* Ngay = new char;
	char* Thang = new char;
	char* Nam = new char;
	long long Tong;
	char* sum = new char;
	settextstyle(1, 0, 1);
	int size = 0;
	for (int j = 0; j < dsnv.slnv; j++)
	{
		HoaDon* p = dsnv.ds[j]->Head;
		while (p != NULL)
		{
			if (size >= (trang - 1) * 10 && size < trang * 10) // size >= 10 va size < 19
			{
				if (SoNgayGiuaHaiNgay(start, p->ngaylapHD) >= 0 && SoNgayGiuaHaiNgay(p->ngaylapHD, end) >= 0)
				{
					outtextxy(420, y1, p->soHD);
					itoa(p->ngaylapHD.ngay, Ngay, 10);
					itoa(p->ngaylapHD.thang, Thang, 10);
					itoa(p->ngaylapHD.nam, Nam, 10);
					char* tam = new char;
					strcpy(tam, Ngay);
					char* tam1 = strcat(tam, "/");
					char* tam2 = strcat(tam1, Thang);
					char* tam3 = strcat(tam2, "/");
					char* tam4 = strcat(tam3, Nam);
					outtextxy(560, y1, tam4);
					outtextxy(740, y1, p->Loai);
					char* hovaten = new char;
			    	strcpy(hovaten, dsnv.ds[j]->Ho);
			    	strcat(hovaten, " ");
			    	strcat(hovaten, dsnv.ds[j]->Ten);
					outtextxy(820, y1, hovaten);
					Tong = DoanhThuMotHoaDon(p);
					lltoa(Tong, sum, 10);
	//				FloatToChar(Tong, sum);
					outtextxy(1140, y1, sum);
					y1 = y1 + 40;
					size++;
				}
			}
			else
			{
				size++;
			}
			p = p->next;
		}
	}
	settextstyle(1, 0, 1);
	cout << "DEM = " << size << endl;
}

// In Hoa Don Man3
void InHoaDon(DS_CHITIETHOADON dscthd, tree root, int trang)
{
	VeBangHoaDon(trang);
	int y1 = 305;
	setcolor(MAUDEN);
	int x1 = 420;
	for (int i = 0; i < dscthd.sl; i++)
	{
		if (i < trang * 10 && i >= (trang - 1) * 10)
		{
			outtextxy(420, y1, dscthd.cthd[i].maVT);
			char sl[20];
			VatTu* vt = TimVatTu(root, dscthd.cthd[i].maVT);
			outtextxy(590, y1, vt->tenVT);
			itoa(dscthd.cthd[i].soLuong, sl, 10);
			outtextxy(830, y1, sl);
			char dg[20];
			itoa(dscthd.cthd[i].donGia, dg, 10);
			outtextxy(1000, y1, dg);
			char vat[20];
			FloatToChar(dscthd.cthd[i].VAT, vat);
			outtextxy(1170, y1, vat);
			y1 = y1 + 40;
		}
	}
}

// In danh sach nhan vien Man2
void InDanhSachNhanVien(DanhSachNhanVien& dsnv, int trang)
{
	VeBangNhanVien(trang);
	//	SapXepNhanVienTheoTen(dsnv);
	int y1 = 270;
	setcolor(MAUDEN);
	int x1 = 430;
	for (int i = 0; i < dsnv.slnv; i++)
	{
		if (i < trang * 10 && i >= (trang - 1) * 10)
		{
			char* manv = new char;
			itoa(dsnv.ds[i]->maNV, manv, 10);
			outtextxy(x1, y1, manv);
			outtextxy(610, y1, dsnv.ds[i]->Ho);
			outtextxy(920, y1, dsnv.ds[i]->Ten);
			char* gtinh = new char;
			if (dsnv.ds[i]->Phai == 1)
			{
				strcpy(gtinh, "Nam");
			}
			else if (dsnv.ds[i]->Phai == 0)
			{
				strcpy(gtinh, "Nu");
			}
			outtextxy(1170, y1, gtinh);
			y1 = y1 + 40;
		}
	}
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void XuatCay(tree t)
{
	if(t == NULL)
	{
		return;
	}
	else
	{
		XuatCay(t->left);
		cout<<t->maVT<<"     "<<t->tenVT<<"     "<<t->donviTinh<<endl;
		XuatCay(t->right);
	}
}

// Tao Mang Doanh Thu Mot Vat Tu Man41
void DoanhThuMotVatTu(MangDanhSachVatTu &mangdt, MangDanhSachVatTu mangds, DanhSachNhanVien dsnv, Date start, Date end)
{
	mangdt.soluong = 0;
	for (int i = 0; i < mangds.soluong; i++)
	{
		long long doanhthu = 0;
		for (int j = 0; j < dsnv.slnv; j++)
		{
			HoaDon* p = dsnv.ds[j]->Head;
			if (p == NULL) // Bo qua va den ke tiep
			{
				continue;
			}
			else
			{
				while (p != NULL) // Duyet CTHD
				{
					if (SoNgayGiuaHaiNgay(start, p->ngaylapHD) >= 0 && SoNgayGiuaHaiNgay(p->ngaylapHD, end) >= 0)
					{
                        if (strcmp(p->Loai, "X") == 0)
						{
							for (int h = 0; h < p->List_CTHD.sl; h++)
							{
								if (strcmp(p->List_CTHD.cthd[h].maVT, mangds.ds[i]->maVT) == 0)
								{
									long long a = (p->List_CTHD.cthd[h].VAT/100 + 1) * p->List_CTHD.cthd[h].donGia;
									long long b = a * p->List_CTHD.cthd[h].soLuong;
									doanhthu = doanhthu + b;
								}
							}
						}
					}
					p = p->next;
				}
			}
		}
		mangdt.ds[mangdt.soluong] = new VatTu;
		mangdt.ds[mangdt.soluong]->soluongTon = doanhthu;
		strcpy(mangdt.ds[mangdt.soluong]->maVT, mangds.ds[i]->maVT);
		mangdt.soluong++;
	}
	
	for(int i = 0; i<mangdt.soluong; i++)
	{
		cout<<"MaVT = "<<mangdt.ds[i]->maVT<<". Ten vat tu = "<<TimVatTuTrongMang(mangds, mangdt.ds[i]->maVT)->tenVT<<". Doanh thu = "<<mangdt.ds[i]->soluongTon<<endl;
	}
}


// So luong Xuat 1 Vat Tu Man41
int SoLuongXuatMotVatTu(char* MAVT, tree root, DanhSachNhanVien dsnv, Date start, Date end)
{
	int soluong = 0;
	for (int i = 0; i < dsnv.slnv; i++)
	{
		HoaDon* p = dsnv.ds[i]->Head;
		if (p != NULL)
		{
			while (p != NULL)
			{
				if (SoNgayGiuaHaiNgay(start, p->ngaylapHD) >= 0 && SoNgayGiuaHaiNgay(p->ngaylapHD, end) >= 0)
				{
					for (int j = 0; j < p->List_CTHD.sl; j++)
					{
						if (strcmp(p->List_CTHD.cthd[j].maVT, MAVT) == 0 && strcmp(p->Loai, "X") == 0)
						{
							soluong = soluong + p->List_CTHD.cthd[j].soLuong;
						}
					}
				}
				p = p->next;
			}
		}
		else
			continue;
	}
	return soluong;
}


// In Top Doanh Thu Man41
void InTopDoanhThu(MangDanhSachVatTu mangdt, tree root, DanhSachNhanVien dsnv, Date start, Date end, int trang)
{
	SapXepDoanhThu(mangdt);
	VeBangTopVatTu(trang);
	int y1 = 280;
	setcolor(MAUDEN);
	int x1 = 420;
	for (int i = 0; i < 10; i++)
	{
		if(mangdt.ds[i]->soluongTon == 0)
		{
			break;
		}
		outtextxy(420, y1, mangdt.ds[i]->maVT);
		VatTu* p = TimVatTu(root, mangdt.ds[i]->maVT);
		outtextxy(590, y1, p->tenVT);
		char* soluongxuat = new char;
		int sl = SoLuongXuatMotVatTu(p->maVT, root, dsnv, start, end);
		itoa(sl, soluongxuat, 10);
		outtextxy(840, y1, soluongxuat);
		char* dthu = new char;
	//	FloatToChar(mangdt.ds[i]->soluongTon, dthu);
		lltoa(mangdt.ds[i]->soluongTon, dthu, 10);
		outtextxy(1040, y1, dthu);
		y1 = y1 + 40;
	}
}

// In Full chi tiet hoa don Man31
void InFullChiTietHoaDon(DS_CHITIETHOADON dscthd, tree root,  int trang)
{
	VeBangInHD(trang);
	int y1 = 305;
	setcolor(MAUDEN);
	int x1 = 420;
	for (int i = 0; i < dscthd.sl; i++)
	{
		if (i < trang * 10 && i >= (trang - 1) * 10)
		{
			outtextxy(420, y1, dscthd.cthd[i].maVT);
			char* sl = new char;
			VatTu* vt = TimVatTu(root, dscthd.cthd[i].maVT);
			outtextxy(590, y1, vt->tenVT);
			// FloatToChar(dscthd.cthd[i].soLuong, sl);
			itoa(dscthd.cthd[i].soLuong, sl, 10);
			outtextxy(830, y1, sl);
			char* dg = new char;;
			itoa(dscthd.cthd[i].donGia, dg, 10);
			outtextxy(1000, y1, dg);
			char* vat = new char;
			FloatToChar(dscthd.cthd[i].VAT, vat);
			outtextxy(1170, y1, vat);
			y1 = y1 + 40;
		}
	}
}
void NhapSo(char s[], int max, int kieuso, int px, int py, int ID, int& IDnext)
{
	setcolor(MAUDEN);
	setbkcolor(MAUTRANG);
	settextstyle(1, 0, 1); // 101
	int mx = -1;
	int my = -1;
	unsigned int l = strlen(s);
	s[l] = '|';
	s[l + 1] = 0;
	outtextxy(px, py, s);
	ClearStream();
	while (1)
	{
		delay(0.1);
		getmouseclick(WM_LBUTTONDOWN, mx, my);
		clearmouseclick(WM_LBUTTONDOWN);

		if (!(((mx == -1) && (my == -1)) || (mapID[my][mx] == ID))) {
			s[l] = ' ';
			s[l + 1] = '\0';
			outtextxy(px, py, s);
			s[l] = '\0';
			break;
		}
		if (kbhit())
		{
			char c = getch();
			if (l < max)
			{
				if (c >= '0' && c <= '9')
				{
					s[l] = c;
					l++;
					s[l] = '\0';
				}
				if (c == '.' && kieuso == 2) //kieu so float
				{
					bool kt = false; // khong co '.'
					for (int i = 0; i < strlen(s); i++)
					{
						if (s[i] == '.')
						{
							kt = true;
							break;
						}
					}
					if (kt == false)
					{
						s[l] = c;
						l++;
						s[l] = '\0';
					}
				}
			}
			if (c == 13) {
				s[l] = ' ';
				s[l + 1] = '\0';
				outtextxy(px, py, s);
				s[l] = '\0';
				settextstyle(0, 0, 2);
				break;
			}
			if (c == 8 && l > 0)
			{
				s[l] = ' ';
				s[l + 1] = '\0';
				outtextxy(px, py, s);
				s[l - 1] = ' ';
				l--;
			}
			s[l] = '|';
			s[l + 1] = ' ';
			s[l + 2] = '\0';
			outtextxy(px, py, s);
			if (s[l] == ' ') s[l] = '\0';
		}
	}
	if ((mx != -1) && (my != -1)) {
		IDnext = mapID[mx][my];
	}
	settextstyle(0, 0, 2);
}

void ScannerString(char s[], int max, int px, int py, int ID, int& IDnext) // Chu thuong khong co so
{
	setcolor(MAUDEN);
	setbkcolor(MAUTRANG);
//	settextstyle(1, 0, 1); // 101
    settextstyle(0, 0, 2); // 101
	int mx = -1;
	int my = -1;
	unsigned int l = strlen(s);
	s[l] = '|';
	s[l + 1] = 0;
	outtextxy(px, py, s);
	ClearStream();
	while (1)
	{
		delay(0.1);
		getmouseclick(WM_LBUTTONDOWN, mx, my);
		clearmouseclick(WM_LBUTTONDOWN);

		if (!(((mx == -1) && (my == -1)) || (mapID[my][mx] == ID))) {
			s[l] = ' ';
			s[l + 1] = '\0';
			outtextxy(px, py, s);
			s[l] = '\0';
			break;
		}
		if (kbhit())
		{
			char c = getch();
			if (l < max)
			{
				if ((l == 0 || s[l - 1] == ' '))
				{
					if (c <= 'z' && c >= 'a')
						c = c + 'A' - 'a';
					else
						c = c;

				}
				else if (c <= 'Z' && c >= 'A')
					c = c - 'A' + 'a';
				//				if (c == '_')
				//				{
				//					s[l] = c;
				//					l++;
				//					s[l] = '\0';
				//				}
				if (c >= 'a' && c <= 'z')
				{
					s[l] = c;
					l++;
					s[l] = '\0';
				}
				if (c >= 'A' && c <= 'Z')
				{
					s[l] = c;
					l++;
					s[l] = '\0';
				}
				//				if (c >= '0' && c <= '9')
				//				{
				//					s[l] = c;
				//					l++;
				//					s[l] = '\0';
				//				}
				if (l > 0) if (s[l - 1] != ' ' && c == ' ')
				{
					s[l] = c;
					l++;
					s[l] = '\0';
				}
				if ((l == 0 || s[l - 1] == ' ') && (s[l] >= 'a' || s[l] <= 'z'))
					s[l] = s[l] + 'A' - 'a';
				s[l + 1] = 0;
				outtextxy(px, py, s);
			}
			if (c == 13) {
				s[l] = ' ';
				s[l + 1] = '\0';
				outtextxy(px, py, s);
				s[l] = '\0';
				settextstyle(0, 0, 2);
				if (s[l - 1] == ' ')
				{
					s[l - 1] = '\0';
				}
				break;
			}
			if (c == 8 && l > 0)
			{
				s[l] = ' ';
				s[l + 1] = '\0';
				outtextxy(px, py, s);
				s[l - 1] = ' ';
				l--;
			}
			s[l] = '|';
			s[l + 1] = ' ';
			s[l + 2] = '\0';
			outtextxy(px, py, s);
			if (s[l] == ' ') s[l] = '\0';//

		}
	}
	if ((mx != -1) && (my != -1)) {
		if (s[l - 1] == ' ')
		{
			s[l - 1] = '\0';
		}
		IDnext = mapID[mx][my];
	}
	settextstyle(0, 0, 2);
}

void NhapChuoi(char s[], int max, int px, int py, int ID, int& IDnext)
{
	setcolor(MAUDEN);
	setbkcolor(MAUTRANG);
	// settextstyle(1, 0, 1); // 101
	settextstyle(0, 0, 2); // 101
	int mx = -1;
	int my = -1;
	unsigned int l = strlen(s);
	s[l] = '|';
	s[l + 1] = 0;
	outtextxy(px, py, s);
	ClearStream();
	while (1)
	{
		delay(0.1);
		getmouseclick(WM_LBUTTONDOWN, mx, my);
		clearmouseclick(WM_LBUTTONDOWN);

		if (!(((mx == -1) && (my == -1)) || (mapID[my][mx] == ID))) {
			s[l] = ' ';
			s[l + 1] = '\0';
			outtextxy(px, py, s);
			s[l] = '\0';	
			break;
		}
		if (kbhit())
		{
			char c = getch();
			if (l < max)
			{
				if ((l == 0 || l == 1 || s[l - 1] == ' '))
				{
					if (c <= 'z' && c >= 'a')
						c = c + 'A' - 'a';
					else
						c = c;

				}
				else if (c <= 'Z' && c >= 'A')
					c = c - 'A' + 'a';
				if (c >= 'A' && c <= 'Z')
				{
					s[l] = c;
					l++;
					s[l] = '\0';
				}
				if (c >= '0' && c <= '9' && l > 1)
				{
					s[l] = c;
					l++;
					s[l] = '\0';
				}

				if ((l == 0 || s[l - 1] == ' ') && (s[l] >= 'a' || s[l] <= 'z'))
					s[l] = s[l] + 'A' - 'a';
				s[l + 1] = 0;
				outtextxy(px, py, s);
			}
			if (c == 13) { // Enter
				s[l] = ' ';
				s[l + 1] = '\0';
				outtextxy(px, py, s);
				s[l] = '\0';
				settextstyle(0, 0, 2);
				if (s[l - 1] == ' ')
				{
					s[l - 1] = '\0';
				}
				break;
			}
			if (c == 8 && l > 0) // Xoa
			{
				s[l] = ' ';
				s[l + 1] = '\0';
				outtextxy(px, py, s);
				s[l - 1] = ' ';
				l--;
			}
			s[l] = '|';
			s[l + 1] = ' ';
			s[l + 2] = '\0';
			outtextxy(px, py, s);
			if (s[l] == ' ') s[l] = '\0';//

		}
	}
	if ((mx != -1) && (my != -1)) {
		if (s[l - 1] == ' ')
		{
			s[l - 1] = '\0';
		}
		IDnext = mapID[mx][my];
	}
	settextstyle(0, 0, 2);
}

void VeTabVatTu() // Ve Tab Vat Tu
{
	TaoTextInput(30, 20, 270, 70, MAUDEN, MAUXANHDUONG, "    VAT TU", -1); // Tab Vat_Tu
	TaoTextInput(30, 80, 270, 130, MAUDEN, MAUXANHLA, "   NHAN VIEN", -2); // Tab Nhan_Vien
	TaoTextInput(30, 140, 270, 190, MAUDEN, MAUXANHLA, "    HOA DON", -3); // Tab Hoa_Don
	TaoTextInput(30, 200, 270, 250, MAUDEN, MAUXANHLA, "   THONG KE", -4); // Tab Thong Ke
	TaoTextInput(70, 340, 220, 380, MAUXANHNHAT, MAUXANHNHAT, "CANH BAO", 0); // Tab Canh_Bao
	TaoTextInput(60, 680, 230, 720, MAUXANHNHAT, MAUXANHLA, "THONG TIN", -7); // Tab Thong_Tin
	TaoTextInput(60, 620, 230, 660, MAUXANHNHAT, MAUXANHLA, "HUONG DAN", -8); // Tab Huong_Dan
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void VeTabNhanVien() // Ve Tab Nhan Vien
{
	TaoTextInput(30, 20, 270, 70, MAUDEN, MAUXANHLA, "    VAT TU", -1); // Tab Vat_Tu
	TaoTextInput(30, 80, 270, 130, MAUDEN, MAUXANHDUONG, "   NHAN VIEN", -2); // Tab Nhan_Vien
	TaoTextInput(30, 140, 270, 190, MAUDEN, MAUXANHLA, "    HOA DON", -3); // Tab Hoa_Don
	TaoTextInput(30, 200, 270, 250, MAUDEN, MAUXANHLA, "   THONG KE", -4); // Tab Thong Ke
	TaoTextInput(70, 340, 220, 380, MAUXANHNHAT, MAUXANHNHAT, "CANH BAO", 0); // Tab Canh_Bao
	TaoTextInput(60, 680, 230, 720, MAUXANHNHAT, MAUXANHLA, "THONG TIN", -7); // Tab Thong_Tin
	TaoTextInput(60, 620, 230, 660, MAUXANHNHAT, MAUXANHLA, "HUONG DAN", -8); // Tab Huong_Dan
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void VeTabHoaDon() // Ve Tab Hoa Don
{
	TaoTextInput(30, 20, 270, 70, MAUDEN, MAUXANHLA, "    VAT TU", -1); // Tab Vat_Tu
	TaoTextInput(30, 80, 270, 130, MAUDEN, MAUXANHLA, "   NHAN VIEN", -2); // Tab Nhan_Vien
	TaoTextInput(30, 140, 270, 190, MAUDEN, MAUXANHDUONG, "    HOA DON", -3); // Tab Hoa_Don
	TaoTextInput(30, 200, 270, 250, MAUDEN, MAUXANHLA, "   THONG KE", -4); // Tab Thong Ke
	TaoTextInput(70, 340, 220, 380, MAUXANHNHAT, MAUXANHNHAT, "CANH BAO", 0); // Tab Canh_Bao
	TaoTextInput(60, 680, 230, 720, MAUXANHNHAT, MAUXANHLA, "THONG TIN", -7); // Tab Thong_Tin
	TaoTextInput(60, 620, 230, 660, MAUXANHNHAT, MAUXANHLA, "HUONG DAN", -8); // Tab Huong_Dan
	TaoTextInput(50, 560, 240, 600, MAUXANHNHAT, MAUXANHLA, "IN HOA DON", -10); // Tab Huong_Dan
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void VeTabThongKe() // Ve Tab Thong Ke HD
{
	TaoTextInput(30, 20, 270, 70, MAUDEN, MAUXANHLA, "    VAT TU", -1); // Tab Vat_Tu
	TaoTextInput(30, 80, 270, 130, MAUDEN, MAUXANHLA, "   NHAN VIEN", -2); // Tab Nhan_Vien
	TaoTextInput(30, 140, 270, 190, MAUDEN, MAUXANHLA, "    HOA DON", -3); // Tab Hoa_Don
	TaoTextInput(30, 200, 270, 250, MAUDEN, MAUXANHDUONG, "   THONG KE", -4); // Tab Thong Ke
	TaoTextInput(70, 340, 220, 380, MAUXANHNHAT, MAUXANHNHAT, "CANH BAO", 0); // Tab Canh_Bao
	TaoTextInput(60, 680, 230, 720, MAUXANHNHAT, MAUXANHLA, "THONG TIN", -7); // Tab Thong_Tin
	TaoTextInput(60, 620, 230, 660, MAUXANHNHAT, MAUXANHLA, "HUONG DAN", -8); // Tab Huong_Dan
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void VeTabInHD() // Ve tab In Hoa Don
{
	TaoTextInput(30, 20, 270, 70, MAUDEN, MAUXANHLA, "    VAT TU", -1); // Tab Vat_Tu
	TaoTextInput(30, 80, 270, 130, MAUDEN, MAUXANHLA, "   NHAN VIEN", -2); // Tab Nhan_Vien
	TaoTextInput(30, 140, 270, 190, MAUDEN, MAUXANHLA, "    HOA DON", -3); // Tab Hoa_Don
	TaoTextInput(30, 200, 270, 250, MAUDEN, MAUXANHLA, "   THONG KE", -4); // Tab Thong Ke
	TaoTextInput(70, 340, 220, 380, MAUXANHNHAT, MAUXANHNHAT, "CANH BAO", 0); // Tab Canh_Bao
	TaoTextInput(60, 680, 230, 720, MAUXANHNHAT, MAUXANHLA, "THONG TIN", -7); // Tab Thong_Tin
	TaoTextInput(60, 620, 230, 660, MAUXANHNHAT, MAUXANHLA, "HUONG DAN", -8); // Tab Huong_Dan
	TaoTextInput(50, 560, 240, 600, MAUXANHNHAT, MAUXANHDUONG, "IN HOA DON", -10); // Tab In CTHD
	setbkcolor(MAUXANHNHAT);
}

void VeBangVatTu(int trang) // Ve bang Vat Tu
{
	settextstyle(1, 0, 1);
	char TieuDe[][50] = { "STT", "Ma Vat Tu", "      Ten Vat Tu", "Don Vi Tinh ", "So Luong Ton" };
	int mangdodai[] = { 90, 200, 300, 220, 200, 150, 150, 150, 150,150 };
	TaoBang(310, 220, 40, 5, mangdodai, MAUTRANG, MAUDEN, 11, 999, trang, TieuDe);
}

void VeBangNhanVien(int trang) // Ve Bang Nhan Vien
{
	settextstyle(1, 0, 1);
	char TieuDe[][50] = { "STT", "Ma Nhan Vien", "               Ho", "           Ten ", "      Phai" };
	int mangdodai[] = { 90, 200, 300, 260, 165, 150, 150, 150, 150,150 };
	TaoBang(310, 215, 40, 5, mangdodai, MAUTRANG, MAUDEN, 11, 1999, trang, TieuDe);
}

void VeBangHoaDon(int trang) // Ve Bang Hoa Don
{
	settextstyle(1, 0, 1);
	char TieuDe[][50] = { "STT", "Ma Vat Tu", "    Ten Vat Tu", "  So Luong ", "  Don Gia", "    VAT" };
	int mangdodai[] = { 90, 170, 250, 170, 170, 165, 150, 90, 90,90, 90, 90 };
	TaoBang(310, 250, 40, 6, mangdodai, MAUTRANG, MAUDEN, 11, 2999, trang, TieuDe);
}

void VeBangThongTin() // Ve Bang Thong Tin
{
	cleardevice();
	ResetmapID();
	setbkcolor(MAUXANHNHAT);
	TaoTextInput(30, 20, 270, 70, MAUDEN, MAUXANHLA, "    VAT TU", -1); // Tab Vat_Tu
	TaoTextInput(30, 80, 270, 130, MAUDEN, MAUXANHLA, "   NHAN VIEN", -2); // Tab Nhan_Vien
	TaoTextInput(30, 140, 270, 190, MAUDEN, MAUXANHLA, "    HOA DON", -3); // Tab Hoa_Don
	TaoTextInput(30, 200, 270, 250, MAUDEN, MAUXANHLA, "   THONG KE", -4); // Tab Thong Ke
	TaoTextInput(70, 340, 220, 380, MAUXANHNHAT, MAUXANHNHAT, "CANH BAO", 0); // Tab Canh_Bao
	TaoTextInput(60, 680, 230, 720, MAUXANHNHAT, MAUXANHDUONG, "THONG TIN", -7); // Tab Thong_Tin
	TaoTextInput(60, 620, 230, 660, MAUXANHNHAT, MAUXANHLA, "HUONG DAN", -8); // Tab Huong_Dan
	VeKhungVien(5, 5, 1340, 740, MAUDEN);
	VeKhungVien(10, 10, 295, 310, MAUDEN);
	VeKhungVien(300, 10, 1335, 735, MAUDEN);
	VeKhungVien(10, 320, 295, 735, MAUDEN);
	TaoTextInput(100, 260, 200, 300, MAUTRANG, MAUCAM, "THOAT", 9999); // Thoat
	TaoText(500, 50, 1200, 100, MAUXANHNHAT, MAUTRANG, MAUXANHLA, "  HOC VIEN CONG NGHE BUU CHINH VIEN THONG");
	TaoText(500, 170, 1200, 220, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "+ MON HOC:       CAU TRUC DU LIEU & GIAI THUAT");
	TaoText(500, 240, 1200, 290, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "+ GIANG VIEN:    LUU NGUYEN KY THU");
	TaoText(500, 310, 1200, 360, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "+ DO AN:         QUAN LY VAT TU");
	TaoText(500, 380, 1200, 430, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "+ SINH VIEN:     1.NGUYEN DUC NGOC - N19DCCN123");
	TaoText(500, 450, 1200, 500, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "                 2.BUI XUAN TU - N19DCCN173");
	TaoText(500, 550, 1200, 600, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "              ---2021---");
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void VeBangHuongDan()  // Ve Bang Huong Dan
{
	cleardevice();
	ResetmapID();
	setbkcolor(MAUXANHNHAT);
	TaoTextInput(30, 20, 270, 70, MAUDEN, MAUXANHLA, "    VAT TU", -1); // Tab Vat_Tu
	TaoTextInput(30, 80, 270, 130, MAUDEN, MAUXANHLA, "   NHAN VIEN", -2); // Tab Nhan_Vien
	TaoTextInput(30, 140, 270, 190, MAUDEN, MAUXANHLA, "    HOA DON", -3); // Tab Hoa_Don
	TaoTextInput(30, 200, 270, 250, MAUDEN, MAUXANHLA, "   THONG KE", -4); // Tab Thong Ke
	TaoTextInput(70, 340, 220, 380, MAUXANHNHAT, MAUXANHNHAT, "CANH BAO", 0); // Tab Canh_Bao
	TaoTextInput(60, 680, 230, 720, MAUXANHNHAT, MAUXANHLA, "THONG TIN", -7); // Tab Thong_Tin
	TaoTextInput(60, 620, 230, 660, MAUXANHNHAT, MAUXANHDUONG, "HUONG DAN", -8); // Tab Huong_Dan
	VeKhungVien(5, 5, 1340, 740, MAUDEN);
	VeKhungVien(10, 10, 295, 310, MAUDEN);
	VeKhungVien(300, 10, 1335, 735, MAUDEN);
	VeKhungVien(10, 320, 295, 735, MAUDEN);
	TaoTextInput(100, 260, 200, 300, MAUTRANG, MAUCAM, "THOAT", 9999); // Thoat
	// TEXT
	TaoText(470, 50, 1200, 100, MAUXANHNHAT, MAUTRANG, MAUXANHLA, "   HUONG DAN SU DUNG CHUOT DE THAO TAC");
	TaoText(310, 170, 1200, 190, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "+ VAT TU: Ma vat tu gom 6 ky tu theo cau truc VTxxxx: VT1234");
	TaoText(310, 200, 1200, 220, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "  voi xxxx la 4 ky tu so. De them VAT TU sau khi nhap xong");
	TaoText(310, 230, 1200, 250, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "  thong tin nhan vao 'THEM', xoa cac muc da nhap nhan vao 'NEW'");
	TaoText(310, 260, 1200, 280, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "  De xoa VAT TU nhap chon VAT TU trong DANH SACH + nut 'XOA'");
	TaoText(310, 290, 1200, 310, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "  De chinh sua VAT TU nhap chon VAT TU trong DANH SACH sau do");
	TaoText(310, 320, 1200, 330, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "  chinh sua cac thong tin va nhan nut 'HIEU CHINH' de xac nhan");

	TaoText(310, 390, 1200, 410, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "+ NHAN VIEN: Chuc nang them, sua, xoa tuong tu nhu VAT TU");
	TaoText(310, 450, 1200, 470, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "+ HOA DON: Ngay lap HD so voi thoi gian hien tai phai < 60 ngay");
	TaoText(310, 480, 1200, 500, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "  Moi HOA DON chi duoc lap tu duy nhat 1 NHAN VIEN");
	TaoText(310, 510, 1200, 530, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "  Toi da 20 chi tiet hoa don cho moi hoa don");
	TaoText(310, 540, 1200, 560, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "  Co the xoa chi tiet HD trong qua trinh lap hoa don");
	TaoText(310, 610, 1200, 630, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "  Ma Vat Tu: VTXXXX - Ma Nhan Vien: AAAA - So Hoa Don: HDBBBB");
	TaoText(310, 650, 1200, 670, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "   +  Ma Vat Tu - Ma Nhan Vien - So Hoa Don la duy nhat  +");
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void VeBangThongKeHD(int trang) // Ve Bang Thong Ke HD
{
	settextstyle(1, 0, 1);
	char TieuDe[][50] = { "STT", "  SHD", "  Ngay Lap", " Loai", "   Nhan Vien Lap HD", "  Tri Gia HD" };
	int mangdodai[] = { 90, 140, 170, 80, 340, 190, 10, 10, 90,90, 10, 10 };
	TaoBang(315, 230, 40, 6, mangdodai, MAUTRANG, MAUDEN, 11, 4999, trang, TieuDe);
}

void VeBangInHD(int trang) // Ve Bang INHD
{
	settextstyle(1, 0, 1);
	char TieuDe[][50] = { "STT", "Ma Vat Tu", "    Ten Vat Tu", "  So Luong ", "  Don Gia", "    VAT" };
	int mangdodai[] = { 90, 170, 250, 170, 170, 165, 150, 90, 90,90, 90, 90 };
	TaoBang(310, 250, 40, 6, mangdodai, MAUTRANG, MAUDEN, 11, 2999, trang, TieuDe);
}

void VeBangTopVatTu(int trang) // Ve Bang Top Vat Tu
{
	settextstyle(1, 0, 1);
	char TieuDe[][50] = { "STT", "Ma Vat Tu", "    Ten Vat Tu", "   S.L Xuat", "      Doanh Thu" };
	int mangdodai[] = { 90, 170, 250, 200, 300, 165, 150, 90, 90,90, 90, 90 };
	TaoBang(315, 230, 40, 5, mangdodai, MAUTRANG, MAUDEN, 11, 5999, trang, TieuDe);
}

void ManHinh1() // Man Hinh Vat Tu
{
	cleardevice();
	ResetmapID();

	// Ve Khung + Tab
	VeTabVatTu();
	VeKhungVien(300, 10, 1335, 200, MAUDEN); // Khung Vien VatTu
	VeKhungVien(5, 5, 1340, 740, MAUDEN);
	VeKhungVien(10, 10, 295, 310, MAUDEN);
	VeKhungVien(300, 205, 1335, 735, MAUDEN);
	VeKhungVien(10, 320, 295, 735, MAUDEN);

	// Ve Text
	TaoTextInput(330, 24, 450, 71, MAUTRANG, MAUHONG, "Ma VT: ", 0); // Text MA VT
	TaoTextInput(330, 74, 450, 121, MAUTRANG, MAUHONG, "Ten VT: ", 0); // Text Ten VT
	TaoTextInput(840, 24, 995, 71, MAUTRANG, MAUHONG, "Don Vi: ", 0); // Text Don VI
	TaoTextInput(840, 74, 995, 121, MAUTRANG, MAUHONG, "So Luong: ", 0); // Text So Luong

	// Ve man hinh nhap
	TaoTextInput(450, 25, 800, 70, MAUDEN, MAUTRANG, "", 11); // Ma_VT 
	TaoTextInput(450, 75, 800, 120, MAUDEN, MAUTRANG, "", 12); // Ten_VT
	TaoTextInput(995, 25, 1250, 70, MAUDEN, MAUTRANG, "", 13); // Don_Vi
	TaoTextInput(995, 75, 1250, 120, MAUDEN, MAUTRANG, "", 14); // So_Luong

	// Button
	TaoTextInput(450, 140, 530, 180, MAUTRANG, MAUXANHLA, "THEM", 15); // Button Them
	TaoTextInput(560, 140, 650, 180, MAUTRANG, MAUCAM, " NEW", 16); // Button Xuat
	// TaoTextInput(680, 140, 770, 180, MAUTRANG, MAUXANHDUONG, " XOA", 17); // Button NEW = VAT_TU
	// TaoTextInput(800, 140, 980, 180, MAUTRANG, MAUCAM, "HIEU CHINH", 18); // Button Hieu Chinh
	TaoTextInput(100, 260, 200, 300, MAUTRANG, MAUCAM, "THOAT", 9999); // Thoat

	// Ve phan trang Page
	TaoTextInput(330, 680, 430, 720, MAUTRANG, MAUXANHDUONG, " Lui", 19); // Button NEW = VAT_TU
	TaoTextInput(1200, 680, 1310, 720, MAUTRANG, MAUCAM, " Tiep", 20); // Button Hieu Chih

	// Ve Bang Vat Tu
	VeBangVatTu(1);
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void ManHinh2() // Man Hinh Nhan Vien
{
	cleardevice();
	ResetmapID();

	// Ve Khung + Tab
	VeTabNhanVien();
	VeKhungVien(300, 10, 1335, 200, MAUDEN); // Khung Vien Nhan Vien
	VeKhungVien(5, 5, 1340, 740, MAUDEN);
	VeKhungVien(10, 10, 295, 310, MAUDEN);
	VeKhungVien(300, 205, 1335, 735, MAUDEN);
	VeKhungVien(10, 320, 295, 735, MAUDEN);

	// Ve Text
	TaoTextInput(330, 24, 450, 71, MAUTRANG, MAUHONG, "Ma NV: ", 0); // Text Ma NV
	TaoTextInput(330, 74, 450, 121, MAUTRANG, MAUHONG, "Ho: ", 0); // Text Ho NV
	TaoTextInput(840, 24, 995, 71, MAUTRANG, MAUHONG, "Ten: ", 0); // Text Ten VT 
	TaoTextInput(840, 74, 995, 121, MAUTRANG, MAUHONG, "Phai: ", 0); // // Text Gioi Tinh

	// Ve man hinh nhap nhan vien
	TaoTextInput(450, 25, 800, 70, MAUDEN, MAUTRANG, "", 21); // Ma_NV
	TaoTextInput(450, 75, 800, 120, MAUDEN, MAUTRANG, "", 22); // Ho_NV
	TaoTextInput(995, 25, 1250, 70, MAUDEN, MAUTRANG, "", 23); // Ten_NV
	TaoTextInput(995, 75, 1250, 120, MAUDEN, MAUTRANG, "", 24); // Gioi_Tinh

	// Button
	TaoTextInput(450, 140, 530, 180, MAUTRANG, MAUXANHLA, "THEM", 25); // Button Them
	TaoTextInput(560, 140, 650, 180, MAUTRANG, MAUCAM, " NEW", 26); // Button NEW 
	//TaoTextInput(680, 140, 770, 180, MAUTRANG, MAUXANHDUONG, " XOA", 28); // Button XOA
	//TaoTextInput(790, 140, 970, 180, MAUTRANG, MAUCAM, "HIEU CHINH", 27); // Button HIEU CHINH
	TaoTextInput(100, 260, 200, 300, MAUTRANG, MAUCAM, "THOAT", 9999); // Thoat
	
	// Ve phan trang Page
	TaoTextInput(330, 680, 430, 720, MAUTRANG, MAUXANHDUONG, " Lui", 30); // Button TIEP
	TaoTextInput(1200, 680, 1310, 720, MAUTRANG, MAUCAM, " Tiep", 29); // Button LUI
	
	// Ve Bang
	VeBangNhanVien(1);
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void ManHinh3() // Man Hinh Hoa Don
{
	cleardevice();
	ResetmapID();

	// Ve Khung + Tab
	VeTabHoaDon();
	VeKhungVien(300, 10, 1335, 230, MAUDEN); // Khung Vien Hoa Don
	VeKhungVien(5, 5, 1340, 740, MAUDEN);
	VeKhungVien(10, 10, 295, 310, MAUDEN);
	VeKhungVien(300, 240, 1335, 735, MAUDEN);
	VeKhungVien(10, 320, 295, 735, MAUDEN);

	// Ve Text
	TaoTextInput(330, 24, 465, 61, MAUTRANG, MAUHONG, "Loai HD: ", 0); // Text Loai_HD
	TaoTextInput(580, 24, 730, 61, MAUTRANG, MAUHONG, "Ngay Lap: ", 0); // Text Ngay_Lap
	TaoTextInput(980, 24, 1100, 61, MAUTRANG, MAUHONG, "So HD: ", 0); // Text So_HD
	TaoTextInput(330, 75, 450, 115, MAUTRANG, MAUXANHDUONG, "Ma NV: ", 0); // Text Ma NV
	TaoTextInput(680, 75, 830, 115, MAUTRANG, MAUXANHDUONG, "Ten NV: ", 0); // Text Ten NV
	TaoTextInput(330, 129, 440, 166, MAUTRANG, MAUXANHLA, "Ma VT: ", 0); // Text Ma_Vat_Tu
	TaoTextInput(590, 129, 710, 166, MAUTRANG, MAUXANHLA, "Ten VT: ", 0); // Text Ma_Vat_Tu
	TaoTextInput(920, 129, 980, 166, MAUTRANG, MAUXANHLA, "SL: ", 0); // Text So_Luong
	TaoTextInput(1110, 129, 1170, 166, MAUTRANG, MAUXANHLA, "DG: ", 0); // Text So_Luong
	TaoTextInput(1000, 180, 1100, 215, MAUTRANG, MAUXANHLA, "VAT: ", 0); // Text So_Luong

	// Ve man hinh nhap
	TaoTextInput(465, 25, 550, 60, MAUDEN, MAUTRANG, "", 31); // Loai_HD
	TaoTextInput(730, 25, 950, 60, MAUDEN, MAUTRANG, "", 32); // Ngay_Lap
	TaoTextInput(1100, 25, 1320, 60, MAUDEN, MAUTRANG, "", 33); // So_HD
	TaoTextInput(450, 76, 640, 114, MAUDEN, MAUTRANG, "", 34); // Ma NV
	TaoTextInput(830, 76, 1100, 114, MAUDEN, MAUTRANG, "", 0); // Ten NV
	TaoTextInput(440, 130, 575, 165, MAUDEN, MAUTRANG, "", 36); // Ma_VT
	TaoTextInput(710, 130, 900, 165, MAUDEN, MAUTRANG, "", 0); // Ten_VT
	TaoTextInput(980, 130, 1090, 165, MAUDEN, MAUTRANG, "", 38); // So_Luong
	TaoTextInput(1170, 130, 1330, 165, MAUDEN, MAUTRANG, "", 39); // Don_Gia
	TaoTextInput(1100, 181, 1200, 214, MAUDEN, MAUTRANG, "", 391); // VAT

	//Button
	TaoTextInput(410, 180, 500, 215, MAUTRANG, MAUXANHDUONG, "THEM", 392); // Button NEW
	TaoTextInput(530, 180, 640, 215, MAUTRANG, MAUCAM, "HD MOI", 394); // Button Tao HD moi
	//TaoTextInput(650, 180, 830, 215, MAUTRANG, MAUXANHDUONG, "HIEU CHINH", 3956); // Button Hieu Chinh
	//TaoTextInput(850, 180, 920, 215, MAUTRANG, MAUCAM, "XOA", 395); // Button XOA
	TaoTextInput(100, 260, 200, 300, MAUTRANG, MAUCAM, "THOAT", 9999); // Thoat

	// Ve phan trang Page
	TaoTextInput(330, 695, 430, 730, MAUTRANG, MAUXANHDUONG, " Lui", 396); // Button NEW = VAT_TU
	TaoTextInput(1200, 695, 1310, 730, MAUTRANG, MAUCAM, " Tiep", 397); // Button Hieu Chihh

	// Ve bang HD
	VeBangHoaDon(1);
	setcolor(MAUDEN);
	outtextxy(740, 37, "___/____/____");
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void ManHinh4() // Man Hinh Thong Ke
{
	cleardevice();
	ResetmapID();

	// Ve Khung + Tab
	VeTabThongKe();
	VeKhungVien(300, 10, 1335, 200, MAUDEN); // Khung Vien Nhan Vien
	VeKhungVien(5, 5, 1340, 740, MAUDEN);
	VeKhungVien(10, 10, 295, 310, MAUDEN);
	VeKhungVien(300, 205, 1335, 735, MAUDEN);
	VeKhungVien(10, 320, 295, 735, MAUDEN);

	TaoTextInput(330, 84, 470, 126, MAUTRANG, MAUHONG, "Tu ngay: ", 0); // Text ngay bat dau
	TaoTextInput(840, 84, 995, 126, MAUTRANG, MAUHONG, "Den ngay: ", 0); // Text ngay ket thuc

	// Ve man hinh nhap nhan vien
	TaoTextInput(470, 85, 690, 125, MAUDEN, MAUTRANG, "", 42); // Ngay bat dau
	TaoTextInput(995, 85, 1230, 125, MAUDEN, MAUTRANG, "", 44); // Ngay ket thuc
	TaoTextInput(900, 140, 1160, 180, MAUTRANG, MAUXANHLA, " TOP DOANH THU ", -5); // Text Ma NV
	TaoText(350, 25, 1250, 65, MAUTRANG, MAUXANHDUONG, MAUXANHNHAT, "  BANG LIET KE CAC HOA DON TRONG KHOANG THOI GIAN ");
	TaoTextInput(100, 260, 200, 300, MAUTRANG, MAUCAM, "THOAT", 9999); // Thoat

	// Button
	TaoTextInput(400, 140, 670, 180, MAUTRANG, MAUCAM, "XUAT DS HOA DON", 45); // Button XUAT DSHD
	TaoTextInput(330, 680, 430, 720, MAUTRANG, MAUXANHDUONG, " Lui", 46); // Button Lui
	TaoTextInput(1200, 680, 1310, 720, MAUTRANG, MAUCAM, " Tiep", 47); // Button Tiep
	
	// Ve Bang
	VeBangThongKeHD(1);
	setcolor(MAUXANHDUONG);
	outtextxy(477, 102, "___/___/____");
	outtextxy(1002, 102, "___/___/____");
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void Man4_1()
{
	cleardevice();
	ResetmapID();
	VeTabThongKe();
	VeKhungVien(300, 10, 1335, 200, MAUDEN); // Khung Vien Nhan Vien
	VeKhungVien(5, 5, 1340, 740, MAUDEN);
	VeKhungVien(10, 10, 295, 310, MAUDEN);
	VeKhungVien(300, 205, 1335, 735, MAUDEN);
	VeKhungVien(10, 320, 295, 735, MAUDEN);
	// Ve Text
	TaoTextInput(330, 84, 470, 126, MAUTRANG, MAUHONG, "Tu ngay: ", 0); // Text ngay bat dau
	TaoTextInput(840, 84, 995, 126, MAUTRANG, MAUHONG, "Den ngay: ", 0); // Text ngay ket thuc
	VeBangTopVatTu(1);

	// Ve man hinh nhap nhan vien
	TaoTextInput(470, 85, 690, 125, MAUDEN, MAUTRANG, "", 51); // Ngay bat dau
	TaoTextInput(995, 85, 1230, 125, MAUDEN, MAUTRANG, "", 52); // Ngay ket thuc
	TaoTextInput(400, 140, 720, 180, MAUTRANG, MAUCAM, "XUAT TOP DOANH THU", 53); // Button XUAT DSHD
	TaoTextInput(900, 140, 1200, 180, MAUTRANG, MAUXANHDUONG, " THONG KE HOA DON ", -4); // Text Ma NV
	TaoText(350, 25, 1250, 65, MAUTRANG, MAUXANHDUONG, MAUXANHNHAT, "10 VAT TU CO DOANH THU CAO NHAT TRONG KHOANG THOI GIAN ");
	TaoTextInput(100, 260, 200, 300, MAUTRANG, MAUCAM, "THOAT", 9999); // Thoat

	setcolor(MAUXANHDUONG);
	setbkcolor(MAUTRANG);
	settextstyle(1, 0, 1);
	outtextxy(477, 102, "___/___/____");
	outtextxy(1002, 102, "___/___/____");
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

void ManHinhInHD()
{
	cleardevice();
	ResetmapID();
	
	// Ve Tab + Khung
	VeTabInHD();
	VeKhungVien(300, 10, 1335, 200, MAUDEN); // Khung Vien Nhan Vien
	VeKhungVien(5, 5, 1340, 740, MAUDEN);
	VeKhungVien(10, 10, 295, 310, MAUDEN);
	VeKhungVien(300, 205, 1335, 735, MAUDEN);
	VeKhungVien(10, 320, 295, 735, MAUDEN);
	
	// Ve Text
	TaoTextInput(310, 84, 500, 126, MAUTRANG, MAUHONG, "So Hoa Don: ", 0); // Text ngay bat dau
	VeBangInHD(1);

	// Ve man hinh nhap nhan vien
	TaoTextInput(500, 85, 750, 125, MAUDEN, MAUTRANG, "", 61); // SHD
	TaoTextInput(500, 140, 680, 180, MAUTRANG, MAUCAM, "IN HOA DON", 62); // IN
	TaoText(350, 25, 1250, 65, MAUTRANG, MAUXANHDUONG, MAUXANHNHAT, "                     IN CHI TIET HOA DON ");
	TaoTextInput(330, 695, 430, 730, MAUTRANG, MAUXANHDUONG, " Lui", 63); // Button NEW = VAT_TU
	TaoTextInput(1200, 695, 1310, 730, MAUTRANG, MAUCAM, " Tiep", 64); // Button Hieu Chih
	TaoTextInput(100, 260, 200, 300, MAUTRANG, MAUCAM, "THOAT", 9999); // Thoat
	setbkcolor(MAUXANHNHAT);
	setcolor(MAUDEN);
}

// Xoa Noi Dung Da Ghi Man 1
void ResetConTentMan1(char soluong[7], char donvi[11], char tenvt[15], char mavt[11])
{
	strcpy(soluong, "");
	strcpy(donvi, "");
	strcpy(tenvt, "");
	strcpy(mavt, "");
	TaoTextInput(450, 25, 800, 70, MAUDEN, MAUTRANG, "", 11); // Ma_VT 
	TaoTextInput(450, 75, 800, 120, MAUDEN, MAUTRANG, "", 12); // Ten_VT
	TaoTextInput(995, 25, 1250, 70, MAUDEN, MAUTRANG, "", 13); // Don_Vi
	TaoTextInput(995, 75, 1250, 120, MAUDEN, MAUTRANG, "", 14); // So_Luong
}

// Xoa Noi Dung Da Ghi Man 2
void ResetConTentMan2(char phai[4], char tennv[11], char ho[16], char manv[5])
{
	strcpy(phai, "");
	strcpy(tennv, "");
	strcpy(ho, "");
	strcpy(manv, "");
	TaoTextInput(450, 25, 800, 70, MAUDEN, MAUTRANG, "", 21); // Ma_NV
	TaoTextInput(450, 75, 800, 120, MAUDEN, MAUTRANG, "", 22); // Ho_NV
	TaoTextInput(995, 25, 1250, 70, MAUDEN, MAUTRANG, "", 23); // Ten_NV
	TaoTextInput(995, 75, 1250, 120, MAUDEN, MAUTRANG, "", 24); // Gioi_Tinh
}

// Xoa Noi Dung Da Ghi Man 3
void ResetConTentMan3(char vat[3], char dongia[10], char soluong3[6], char tenvt3[15], char mavt3[7], char tennv3[11], char manv3[5], char sohoadon[7], char nam[5], char thang[3], char ngay[3], char loai[2], int Ngay, int Thang, int Nam)
{
	strcpy(vat, "");
	strcpy(dongia, "");
	strcpy(soluong3, "");
	strcpy(tenvt3, "");
	strcpy(mavt3, "");
	strcpy(tennv3, "");
	strcpy(manv3, "");
	strcpy(sohoadon, "");
	strcpy(nam, "");
	strcpy(ngay, "");
	strcpy(thang, "");
	strcpy(loai, "");
	ngay = 0;
	thang = 0;
	nam = 0;
}

void XuLy(tree &root, DanhSachNhanVien& dsnv, MangDanhSachVatTu& mangds)
{
	ResetmapID();
	int NumPageVT = 1;
	int NumPageNV = 1;
	int NumPageHD = 1;
	int NumPageTK = 1;
	int NumPageCTHD = 1;
MAN_1:
	ManHinh1();
	setbkcolor(MAUXANHNHAT);
	InDanhSachVatTu(mangds, NumPageVT); // NunPageVT
MAN_2_3:
	int x = -1, y = -1;
	char sohoadon6[10] = "";
	char nam51[5] = "";
	char thang51[3] = "";
	char ngay51[3] = "";
	char nam5[5] = "";
	char thang5[3] = "";
	char ngay5[3] = "";
	float soluongton;
	char soluong[15] = "";
	char donvi[11] = "";
	char tenvt[17] = "";
	char mavt[11];
	int manvint;
	char phai[5] = "";
	char tennv[14] = "";
	char ho[22] = "";
	char manv[10] = "";
	char vat[6] = "";
	char dongia[15] = "";
	char soluong3[10] = "";
	char tenvt3[15] = "";
	char mavt3[10] = "";
	char tennv3[15] = "";
	char manv3[10] = "";
	char sohoadon[10] = "";
	Date start;
	Date end;
	int Nam = 0;
	int Thang = 0;
	int Ngay = 0;
	char nam[5] = "";
	char thang[3] = "";
	char ngay[3] = "";
	char loai[2] = "";
	char nam41[5] = "";
	char thang41[3] = "";
	char ngay41[3] = "";
	char nam4[5] = "";
	char thang4[3] = "";
	char ngay4[3] = "";
	char tennv4[11] = "";
	char manv4[5] = "";
	int kieuso; // 1 so int, 2 float
	int idnext;
	while (true)
	{
		int id = mapID[x][y];
		x = -1, y = -1;
		// Ve Man Hinh
		delay(0.001);
		// Bat chuot	
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
		}
		switch (id)
		{
		case 11:
		{
		NHAP_MA_VT:
			TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
			setbkcolor(MAUTRANG);
			RandomMAVT(mavt);
			outtextxy(459, 40, mavt);
			break;
		}
		case 12: // Nhap ten vat tu
		{
		NHAP_TEN_VT:
			ScannerString(tenvt, 14, 459, 90, 12, idnext);
			cout << "Ten = " << tenvt << "." << endl;
			break;
		}
		case 13: // Nhap don vi tinh
		{
		NHAP_DON_VI_TINH:
			ScannerString(donvi, 10, 1000, 40, 13, idnext);
			break;
		}
		case 14: // Nhap so luong ton
		{
		NHAP_SO_LUONG_TON:
			NhapSo(soluong, 5, 1, 1000, 90, 14, idnext);
			soluongton = toInt(soluong);
			break;
		}
		case 15: // Them vat tu
		{
			if (strlen(mavt) < 6 || KiemTraTrungMaVT(root, mavt) == true || (mavt[0] != 'V' && mavt[1] != 'T'))
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Ma vat tu khong duoc trung/rong");
				settextstyle(1, 0, 2);
				setbkcolor(MAUTRANG);
				goto NHAP_MA_VT;
				break;
			}
			if (strlen(tenvt) == 0)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 420, " - Ten vat tu khong duoc rong");
				settextstyle(1, 0, 2);
				goto NHAP_TEN_VT;
			}
			if (strlen(donvi) == 0)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 430, " - Don vi khong duoc rong");
				settextstyle(1, 0, 2);
				goto NHAP_DON_VI_TINH;
			}
			if (strlen(soluong) == 0)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 440, "- So luong khong duoc rong");
				settextstyle(1, 0, 2);
				goto NHAP_SO_LUONG_TON;
			}
			if(mangds.soluong == MAX_DSVT)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 440, "- Toi da 500 Vat Tu");
				settextstyle(1, 0, 2);
				break;
			}
			else
			{
				setcolor(MAUDEN);
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 420, "- Them vat tu thanh cong");
				settextstyle(1, 0, 2);
				NhapVatTu(root, mavt, tenvt, donvi, soluongton);
				int i = 0;
				ThemVatTuVaoMang(root, mangds, i);
				SapXepVatTuTheoTen(mangds);
				InDanhSachVatTu(mangds, NumPageVT);
				cout << "HELLO MANG" << endl;
				cout << "END MANG" << endl;
				ResetConTentMan1(soluong, donvi, tenvt, mavt);
				break;
			}
		}
		case 16: // Reset Noi Dung Man 1
		{
			ResetConTentMan1(soluong, donvi, tenvt, mavt);
			TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
			break;
		}
		case 19: // Page lui
		{
			if (NumPageVT == 1)
			{
				break;
			}
			else if (NumPageVT > 1)
			{
				TaoTextInput(620, 680, 1000, 720, MAUXANHNHAT, MAUXANHNHAT, "", 0);
				NumPageVT--;
				VeBangVatTu(NumPageVT);
				InDanhSachVatTu(mangds, NumPageVT);
				break;
			}
		}
		case 20: // Page Tiep
		{
			int maxtrang;
			if(mangds.soluong % 10 == 0)
			{
				maxtrang = mangds.soluong / 10;
			}
			else
			{
				maxtrang = mangds.soluong / 10 + 1;
			}
			if (NumPageVT >= maxtrang) // 34 => 4 trang
			{
				TaoText(620, 680, 1000, 720, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "DA TOI CUOI DANH SACH");
				break;
			}
			else
			{
				NumPageVT++;
				VeBangVatTu(NumPageVT);
				InDanhSachVatTu(mangds, NumPageVT);
				break;
			}
		}
		case 21: // Nhap Ma Nhan Vien
		{
		NHAP_MA_NV:
			TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
			manvint = RanDomMaNV(dsnv);
			itoa(manvint, manv, 10);
			setbkcolor(MAUTRANG);
			outtextxy(459, 40, manv);
			break;
		}
		case 22: // Nhap ho nhan vien
		{
		NHAP_HO:
			ScannerString(ho, 18, 459, 90, 22, idnext);
			break;
		}
		case 23: // Nhap ten nhan vien
		{
		NHAP_TEN_NV:
			ScannerString(tennv, 10, 1000, 40, 23, idnext);
			break;
		}
		case 24: // Nhap phai gioi tinh
		{
		NHAP_PHAI:
			ScannerString(phai, 3, 1000, 90, 24, idnext);
			break;
		}
		case 25: // Them nhan vien
		{
			TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
			if (dsnv.slnv >= MAX_DSNV)
			{
				settextstyle(0, 0, 1);
				outtextxy(20, 400, " - Loi! SLNV khong vuot qua 500");
				settextstyle(1, 0, 2);
				break;
			}
			setcolor(MAUDEN);
			if (KiemTraTrungMaNV(dsnv, manvint) == true)
			{
				settextstyle(0, 0, 1);
				outtextxy(20, 400, " - Ma nhan vien khong duoc trung");
				settextstyle(1, 0, 2);
				goto NHAP_MA_NV;
			}
			if (strlen(manv) == 0)
			{
				settextstyle(0, 0, 1);
				outtextxy(20, 410, " - Ma nhan vien khong duoc rong");
				settextstyle(1, 0, 2);
				goto NHAP_MA_NV;
			}
			if (strlen(ho) == 0)
			{
				settextstyle(0, 0, 1);
				outtextxy(20, 420, " - Ho nhan vien khong duoc rong");
				settextstyle(1, 0, 2);
				goto NHAP_HO;
			}
			if (strlen(tennv) == 0)
			{
				settextstyle(0, 0, 1);
				outtextxy(20, 430, " - Ten nhan vien khong duoc rong");
				settextstyle(1, 0, 2);
				goto NHAP_TEN_NV;
			}
			if (strlen(phai) == 0 || (strcmp(phai, "Nam") != 0 && strcmp(phai, "Nu") != 0))
			{
				settextstyle(0, 0, 1);
				outtextxy(20, 440, " - Phai chi nhan (Nam/Nu)");
				settextstyle(1, 0, 2);
				goto NHAP_PHAI;
			}
			ThemNhanVien(dsnv, manvint, ho, tennv, phai);
			setcolor(MAUDEN);
			TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
			settextstyle(0, 0, 1);
			outtextxy(20, 420, "- Them nhan vien thanh cong");
			settextstyle(1, 0, 2);
			InDanhSachNhanVien(dsnv, NumPageNV);
			ResetConTentMan2(phai, tennv, ho, manv);
			setbkcolor(MAUXANHNHAT);
			setcolor(MAUDEN);
			break;
		}
		case 26: // Reset Noi Dung Man 2
		{
			ResetConTentMan2(phai, tennv, ho, manv);
			break;
		}
		case 30: // Page lui
		{
			if (NumPageNV == 1)
			{
				break;
			}
			else if (NumPageNV > 1)
			{
				TaoTextInput(620, 680, 1000, 720, MAUXANHNHAT, MAUXANHNHAT, "", 0);
				NumPageNV--;
				VeBangNhanVien(NumPageNV);
				InDanhSachNhanVien(dsnv, NumPageNV);
				break;
			}
		}
		case 29: // Page Tiep
		{
			int maxtrang;
			if(dsnv.slnv % 10 == 0)
			{
				maxtrang = dsnv.slnv / 10;
			}
			else
			{
				maxtrang = dsnv.slnv / 10 + 1;
			}

		if (NumPageNV >= maxtrang) // 34 => 4 trang
			{
				TaoText(620, 680, 1000, 720, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "DA TOI CUOI DANH SACH");
				break;
			}
			else
			{
				NumPageNV++;
				VeBangNhanVien(NumPageNV);
				InDanhSachNhanVien(dsnv, NumPageNV);
				break;
			}
		}
		case 31: // Nhap loai
		{
		NHAP_LOAI:
			ScannerString(loai, 1, 470, 34, 31, idnext);
			if (strcmp(loai, "X") != 0 && strcmp(loai, "N") != 0)
			{
				if (strlen(loai) == 0)
				{
					break;
				}
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Loai chi nhan N hoac X");
				settextstyle(1, 0, 2);
				goto NHAP_LOAI;
			}
			TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
			break;
		}
		case 32: // Nhap Ngay lap
		{
		Nhap_Ngay_Thang_Nam:
			strcpy(ngay, "");
			strcpy(thang, "");
		    strcpy(nam, "");
            time_t Time_HT = time(0);
         	tm* time_z = localtime(&Time_HT);
            Ngay = time_z->tm_mday;
			Thang = 1 + time_z->tm_mon;
			Nam = 1900 + time_z->tm_year;
			itoa(Ngay, ngay, 10);
			itoa(Thang, thang, 10);
			itoa(Nam, nam, 10);
			TaoTextInput(730, 25, 950, 60, MAUDEN, MAUTRANG, "", 32);
			setcolor(MAUDEN);
			settextstyle(1, 0, 2);
	        outtextxy(740, 37, "___/___/____");
	        setbkcolor(MAUXANHNHAT);
            outtextxy(738, 33, ngay);
            outtextxy(808, 33, thang);
            outtextxy(870, 33, nam);
            TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Che canh bao sai. da nhap thanh cong
            settextstyle(0, 0, 1);
            outtextxy(20, 420, "Lay Thoi gian he thong thanh cong");
            settextstyle(1, 0, 2);
            break;
		}
		case 33: //  Nhap So Hoa Don
		{
		NHAP_SO_HD:
         	TaoTextInput(1100, 25, 1320, 60, MAUDEN, MAUTRANG, "", 33); // So_HD
			RandomMAHD(sohoadon);
			outtextxy(1105, 36, sohoadon);
			cout << "MaHD = " << sohoadon << "." << endl;
			break;
		}
		case 34: // Nhap Ma NV
		{
		NHAP_MA_NV_3:
			NhapSo(manv3, 4, 1, 455, 85, 34, idnext);
			NhanVien* p = NULL;
			p = TimNhanVien(dsnv, toInt(manv3));
			if (p == NULL)
			{
				TaoTextInput(830, 76, 1100, 114, MAUDEN, MAUTRANG, "", 0); // Che Ten NV
				break;
			}
			TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Che canh baosai. da nhap thanh cong
			TaoTextInput(830, 76, 1100, 114, MAUDEN, MAUTRANG, "", 0); // Che Ten NV
			outtextxy(835, 85, p->Ten);
			break;
		}
		case 36: // Nhap Ma VT
		{
		NHAP_MA_VT_3:
			NhapChuoi(mavt3, 6, 446, 140, 36, idnext);
            VatTu* p = NULL;
			p = TimVatTu(root, mavt3);
			if (p == NULL)
			{
				TaoTextInput(710, 130, 900, 165, MAUDEN, MAUTRANG, "", 0); // Che ten VT
				break;			
			}
			TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Che canh baosai. da nhap thanh cong
			TaoTextInput(710, 130, 900, 165, MAUDEN, MAUTRANG, "", 0); // Che Ten VT
			outtextxy(717, 140, p->tenVT);
			break;
		}
		case 38: // Nhap So luong 3
		{
		NHAP_SO_LUONG_3: // FIX CHUA XONG
			NhapSo(soluong3, 4, 1, 985, 140, 38, idnext);
			if (strcmp(loai, "X") == 0 && ToFloat(soluong3) > TimVatTu(root, mavt3)->soluongTon)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				char* slton = new char;
				outtextxy(20, 420, "SL khong vuot qua so luong ton");
				outtextxy(20, 440, "SL ton hien co la: ");
				TimVatTu(root, mavt3)->soluongTon;
			//	FloatToChar(TimVatTu(root, mavt3)->soluongTon, slton);
			    itoa(TimVatTu(root, mavt3)->soluongTon, slton, 10);
			    strcat(slton, " ");
			    strcat(slton, TimVatTu(root, mavt3)->donviTinh);
				outtextxy(170, 440, slton);
				goto NHAP_SO_LUONG_3;
			}
			break;
		}
		case 39: // Nhap Don Gia
		{
		NHAP_DON_GIA:
			NhapSo(dongia, 8, 1, 1175, 140, 39, idnext);
			break;
		}
		case 391: // Nhap Vat
		{
		NHAP_VAT:
			NhapSo(vat, 4, 2, 1110, 190, 391, idnext);
			break;
		}
		case 392: // Them Hoa Don Nhan Vien
		{
			if (strlen(loai) == 0)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Loai hoa don khong duoc rong");
				settextstyle(1, 0, 2);
				goto NHAP_LOAI;
			}
			if (laNgayHopLe(Ngay, Thang, Nam) == false)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Ngay thang nam chua dung");
				settextstyle(1, 0, 2);
				goto Nhap_Ngay_Thang_Nam;
			}
			if (strlen(sohoadon) == 0)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "So hoa don khong duoc rong");
				outtextxy(20, 430, "Random ma hoa don thanh cong");
				settextstyle(1, 0, 2);
				goto NHAP_SO_HD;
			}
			if (strlen(manv3) == 0 || strlen(manv3) <= 4)
			{
				NhanVien* p = NULL;
			    p = TimNhanVien(dsnv, toInt(manv3));
			    if(strlen(manv3) == 0)
			    {
			    	TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				    settextstyle(0, 0, 1);
				    outtextxy(20, 410, "Ma nhan vien khong duoc rong");
				    settextstyle(1, 0, 2);
				    goto NHAP_MA_NV_3;
				}
			    else if (p == NULL)
			    {
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Ma nhan vien khong ton tai");
				settextstyle(1, 0, 2);
				goto NHAP_MA_NV_3;
			    }
			}
			if (strlen(mavt3) == 0 || (strlen(mavt3) <= 6))
			{
				VatTu* p = NULL;
			    p = TimVatTu(root, mavt3);
			    if(strlen(mavt3) == 0)
			    {
			    	TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				    settextstyle(0, 0, 1);
				    outtextxy(20, 410, "Ma vat tu khong duoc rong");
				    settextstyle(1, 0, 2);
				    goto NHAP_MA_VT_3;
				}
		    	else if (p == NULL)
		    	{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				TaoTextInput(710, 130, 900, 165, MAUDEN, MAUTRANG, "", 0); // Che Ten VT
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Ma vat tu khong ton tai");
				settextstyle(1, 0, 2);
				goto NHAP_MA_VT_3;
		    	}
	       }
			if (strlen(soluong3) == 0 || toInt(soluong3) == 0)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "So luong khong duoc rong hoac = 0");
				settextstyle(1, 0, 2);
				goto NHAP_SO_LUONG_3;
			}
			if (strcmp(loai, "X") == 0 && toInt(soluong3) > TimVatTu(root, mavt3)->soluongTon)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "So luong ton khong du de XUAT");
				outtextxy(20, 430, "SL ton con lai la: ");
				char* sluongton = new char;
				VatTu* hehe = TimVatTu(root, mavt3);
				if(hehe == NULL)
				{
					break;
				}
			    itoa(hehe->soluongTon, sluongton, 10);
			    strcat(sluongton, " ");
			    strcat(sluongton, hehe->donviTinh);
				outtextxy(170, 430, sluongton);
				settextstyle(1, 0, 2);
				goto NHAP_SO_LUONG_3;
			}
			if (strlen(dongia) == 0)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Don gia khong duoc rong");
				settextstyle(1, 0, 2);
				goto NHAP_DON_GIA;
			}
			if (strlen(vat) == 0 || ToFloat(vat) > 100)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "VAT khong duoc rong hoac >100%");
				settextstyle(1, 0, 2);
				goto NHAP_VAT;
			}
			NhanVien* nv = TimNhanVien(dsnv, toInt(manv3));
			VatTu* vt = TimVatTu(root, mavt3);
			HoaDon* p = TimHoaDonTheoSoHD(nv->Head, sohoadon);
			if (p != NULL && strcmp(p->Loai, loai) != 0)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Loai hoa don chua chinh xac voi HD");
				settextstyle(1, 0, 2);
				goto NHAP_LOAI;
			}
			if (p != NULL && (p->ngaylapHD.ngay != Ngay || p->ngaylapHD.thang != Thang || p->ngaylapHD.nam != Nam))
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Ngay lap HD chua chinh xac voi HD");
				settextstyle(1, 0, 2);
				goto Nhap_Ngay_Thang_Nam;
			}
			if (p == NULL) // Nhan vien nay chua co so hoa don do
			{
				goto TAO_HOA_DON;
			}
			if(CoTonTaiCTHD(p, mavt3) == true)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Ma vat tu da co trong DS");
				settextstyle(1, 0, 2);
				TaoTextInput(710, 130, 900, 165, MAUDEN, MAUTRANG, "", 0); // Che Ten VT
				goto NHAP_MA_VT_3;
			}
			else if (p != NULL && p->List_CTHD.sl == 20)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Toi da 20 chi tiet hoa don");
				settextstyle(1, 0, 2);
				break;
			}
		TAO_HOA_DON:
			TaoHoaDon(nv, vt, loai, Ngay, Thang, Nam, sohoadon, ToFloat(soluong3), toInt(dongia), ToFloat(vat), mangds, dsnv, 1);
			// XuatHoaDon(nv);
			p = TimHoaDonTheoSoHD(nv->Head, sohoadon);
			if (p == NULL)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Mot SHD khong duoc in cho 2 NV");
				settextstyle(1, 0, 2);
				break;
			}
			else
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Them thanh cong!");
				settextstyle(1, 0, 2);
			}
			InHoaDon(p->List_CTHD, root, NumPageHD);
			char* dt = new char;
			// FloatToChar(DoanhThuMotHoaDon(p), dt);
			lltoa(DoanhThuMotHoaDon(p), dt, 10);
			strcat(dt," VND");
			TaoText(500, 695, 700, 730, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "Tong Tien: ");
			TaoText(800, 695, 1000, 730, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, dt);
			goto THEM_MOI_CTHD;
			break;
		}
		case 394: // Xoa Noi Dung Da Nhap Man 3
		{
			ResetConTentMan3(vat, dongia, soluong3, tenvt3, mavt3, tennv3, manv3, sohoadon, nam, thang, ngay, loai, Ngay, Thang, Nam);
			VeBangHoaDon(1);
			TaoText(500, 695, 700, 730, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "                                      ");
			TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
			TaoTextInput(465, 25, 550, 60, MAUDEN, MAUTRANG, "", 31); // Loai_HD
			TaoTextInput(730, 25, 950, 60, MAUDEN, MAUTRANG, "", 32); // Ngay_Lap
			TaoTextInput(1100, 25, 1320, 60, MAUDEN, MAUTRANG, "", 33); // So_HD
			TaoTextInput(450, 76, 640, 114, MAUDEN, MAUTRANG, "", 34); // Ma NV
			TaoTextInput(830, 76, 1100, 114, MAUDEN, MAUTRANG, "", 0); // Ten NV
			TaoTextInput(440, 130, 575, 165, MAUDEN, MAUTRANG, "", 36); // Ma_VT
			TaoTextInput(710, 130, 900, 165, MAUDEN, MAUTRANG, "", 0); // Ten_VT
			TaoTextInput(980, 130, 1090, 165, MAUDEN, MAUTRANG, "", 38); // So_Luong
			TaoTextInput(1170, 130, 1330, 165, MAUDEN, MAUTRANG, "", 39); // Don_Gia
			TaoTextInput(1100, 181, 1200, 214, MAUDEN, MAUTRANG, "", 391); // VAT
			strcpy(ngay, "");
			strcpy(thang, "");
			strcpy(nam, "");
			setcolor(MAUDEN);
			settextstyle(1, 0, 2);
			outtextxy(733, 37, "___/____/____");
			setbkcolor(MAUXANHNHAT);
			Ngay = 0, Thang = 0, Nam = 0;
		THEM_MOI_CTHD:
			TaoTextInput(440, 130, 575, 165, MAUDEN, MAUTRANG, "", 36); // Ma_VT
			TaoTextInput(710, 130, 900, 165, MAUDEN, MAUTRANG, "", 0); // Ten_VT
			TaoTextInput(980, 130, 1090, 165, MAUDEN, MAUTRANG, "", 38); // So_Luong
			TaoTextInput(1170, 130, 1330, 165, MAUDEN, MAUTRANG, "", 39); // Don_Gia
			TaoTextInput(1100, 181, 1200, 214, MAUDEN, MAUTRANG, "", 391); // VAT
			strcpy(vat, "");
			strcpy(dongia, "");
			strcpy(soluong3, "");
			strcpy(tenvt3, "");
			strcpy(mavt3, "");
			break;
		}
		case 396: // Page lui
		{
			if (NumPageHD == 1)
			{
				break;
			}
			else if (NumPageHD > 1)
			{
				TaoTextInput(620, 695, 1000, 730, MAUXANHNHAT, MAUXANHNHAT, "", 0);
				NumPageHD--;
				VeBangHoaDon(NumPageHD);
				NhanVien* nv = TimNhanVien(dsnv, toInt(manv3));
				HoaDon* p = TimHoaDonTheoSoHD(nv->Head, sohoadon);
				InHoaDon(p->List_CTHD, root, NumPageHD);
				char* dt = new char;
				// FloatToChar(DoanhThuMotHoaDon(p), dt);
				lltoa(DoanhThuMotHoaDon(p), dt, 10);
				strcat(dt," VND");
				TaoText(500, 695, 700, 730, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "Tong Tien: ");
				TaoText(800, 695, 1000, 730, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, dt);
				break;
			}
		}
		case 397: // Page Tiep
		{
			NhanVien* nv = TimNhanVien(dsnv, toInt(manv3));
			if (nv == NULL)
				break;
			HoaDon* p = TimHoaDonTheoSoHD(nv->Head, sohoadon);
			if (p == NULL)
				break;
			int maxtrang;
			if(p->List_CTHD.sl % 10 == 0)
			{
				maxtrang = p->List_CTHD.sl / 10;
			}
			else
			{
				maxtrang = p->List_CTHD.sl / 10 + 1;
			}
			if (NumPageHD >= maxtrang) // 34 => 4 trang
			{
				//	TaoText(620, 695, 1000, 730, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "DA TOI CUOI DANH SACH");
				break;
			}
			else
			{
				NumPageHD++;
				VeBangHoaDon(NumPageHD);
				InHoaDon(p->List_CTHD, root, NumPageHD);
				break;
			}
		}
		case 3001: case 3002: case 3003: case 3004: case 3005: case 3006: case 3007: case 3008: case 3009: case 3010: case 3011:
		{
//			bool heyz = true;
			bool XOAHD = false;
			bool EDITHD = false;
			int vitri = (id - 3001) + (NumPageHD - 1) * 10;
			NhanVien* nv = TimNhanVien(dsnv, toInt(manv3));
			if (nv == NULL)
			{
//				heyz = false;
				break;
			}
			HoaDon* p = TimHoaDonTheoSoHD(nv->Head, sohoadon); // Tim ra HD 1234
			cout << "So Hoa Don = " << p->soHD << endl;
			cout << "Loai = " << p->Loai << endl;
			
			if (p == NULL)
			{
//				heyz = false;
				break;
			}
			ChiTietHoaDon* ct = TimChiTietHD(p->List_CTHD, vitri); // Tim ra chi tiet hoa don cua HD 1234
			if (ct == NULL)
			{
			//	heyz = false;
				TaoTextInput(410, 170, 920, 220, MAUXANHNHAT, MAUXANHNHAT, "", 0);
				TaoTextInput(410, 180, 500, 215, MAUTRANG, MAUXANHDUONG, "THEM", 392); // Button NEW
	            TaoTextInput(530, 180, 640, 215, MAUTRANG, MAUCAM, "HD MOI", 394); // Button Tao HD moi
	            goto THEM_MOI_CTHD;
				break;
			}
			TaoTextInput(465, 25, 550, 60, MAUDEN, MAUTRANG, "", 0); // Loai_HD
	        TaoTextInput(730, 25, 950, 60, MAUDEN, MAUTRANG, "", 0); // Ngay_Lap
	        TaoTextInput(1100, 25, 1320, 60, MAUDEN, MAUTRANG, "", 0); // So_HD
            TaoTextInput(450, 76, 640, 114, MAUDEN, MAUTRANG, "", 0); // Ma NV
	        TaoTextInput(830, 76, 1100, 114, MAUDEN, MAUTRANG, "", 0); // Ten NV
	        
			TaoTextInput(440, 130, 575, 165, MAUDEN, MAUTRANG, "", 361); // Ma_VT
			TaoTextInput(710, 130, 900, 165, MAUDEN, MAUTRANG, "", 0); // Ten_VT
			TaoTextInput(980, 130, 1090, 165, MAUDEN, MAUTRANG, "", 362); // So_Luong
			TaoTextInput(1170, 130, 1330, 165, MAUDEN, MAUTRANG, "", 363); // Don_Gia
			TaoTextInput(1100, 181, 1200, 214, MAUDEN, MAUTRANG, "", 364); // VAT
			
	        TaoTextInput(410, 170, 920, 220, MAUXANHNHAT, MAUXANHNHAT, "", 0);
		//	TaoTextInput(410, 180, 500, 215, MAUTRANG, MAUXANHDUONG, "THEM", 392); // Button NEW
	    //  TaoTextInput(530, 180, 640, 215, MAUTRANG, MAUCAM, "HD MOI", 394); // Button Tao HD moi
	        TaoTextInput(650, 180, 830, 215, MAUTRANG, MAUXANHDUONG, "HIEU CHINH", 3956); // Button Hieu Chinh
	        TaoTextInput(850, 180, 920, 215, MAUTRANG, MAUCAM, "XOA", 395); // Button XOA
            setbkcolor(MAUTRANG);
            outtextxy(470,34, p->Loai);
            outtextxy(1105,36, p->soHD);
            outtextxy(835, 85, nv->Ten);
            outtextxy(740, 35, "___/___/____");
            char* ngayl = new char;
            char* thangl = new char;
            char* naml = new char;
            char* manvl = new char;
            itoa(p->ngaylapHD.ngay, ngayl, 10);
            itoa(p->ngaylapHD.thang, thangl, 10);
            itoa(p->ngaylapHD.nam, naml, 10);
            itoa(nv->maNV, manvl, 10);
            outtextxy(455, 85, manvl);
            outtextxy(738, 33, ngayl);
			outtextxy(808, 33, thangl);
			outtextxy(870, 33, naml);
			
			setbkcolor(MAUXANHNHAT);
			outtextxy(445, 140, ct->maVT);
			outtextxy(715, 140, TimVatTu(root, ct->maVT)->tenVT);
			char* sl = new char;
			char* dg = new char;
			char* vat1 = new char;
			
		//	FloatToChar(ct->soLuong, sl);
			itoa(ct->soLuong, sl, 10);
			outtextxy(984, 140, sl);
			itoa(ct->donGia, dg, 10);
			outtextxy(1175, 140, dg);
			FloatToChar(ct->VAT, vat1);
			outtextxy(1110, 190, vat1);

            
			strcpy(vat, vat1);
			strcpy(dongia, dg);
			strcpy(mavt3, ct->maVT);
			strcpy(soluong3, sl);
			float soluongnhapbandau = ct->soLuong;
			float soluongnhapbandau1 = soluongnhapbandau;
			char* mavtbandau = new char;
			strcpy(mavtbandau, ct->maVT);
			while (true)
			{
				 XOAHD = false;
			     EDITHD = false;
			//     heyz = false;
				int id = mapID[x][y];
				x = -1, y = -1;
				delay(0.001);
				if (ismouseclick(WM_LBUTTONDOWN))
				{
					getmouseclick(WM_LBUTTONDOWN, x, y);
					clearmouseclick(WM_LBUTTONDOWN);
					
					switch (mapID[x][y])
					{				
				
					case 361: // Ma VT
					{
					NHAPMAVT3:
						NhapChuoi(mavt3, 6, 446, 140, 36, idnext);
						VatTu* p = NULL;
						p = TimVatTu(root, mavt3);
						if (p == NULL)
						{
							if (strlen(mavt3) == 0) // Neu do dai  = 0 thi co the thoat * fix sau
							{
								TaoTextInput(710, 130, 900, 165, MAUDEN, MAUTRANG, "", 0); // Che Ten VT
								break;
							}
							TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
							settextstyle(0, 0, 1);
							outtextxy(20, 410, "Ma vat tu khong ton tai");
							settextstyle(1, 0, 2);
							goto NHAPMAVT3;
						}
						TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Che canh baosai. da nhap thanh cong
						TaoTextInput(710, 130, 900, 165, MAUDEN, MAUTRANG, "", 0); // Che Ten VT
						outtextxy(717, 140, p->tenVT);
						break;
					}
					case 362: // Nhap So Luong
					{
						if (strlen(mavt3) == 0)
						{
							TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
							settextstyle(0, 0, 1);
							outtextxy(20, 410, "Ma vat tu khong duoc rong");
							settextstyle(1, 0, 2);
							goto NHAPMAVT3;
						}
					NHAPSOLUONG3: //
						NhapSo(soluong3, 4, 1, 985, 140, 38, idnext);
						if(strcmp(TimVatTu(root,mavt3)->maVT, mavtbandau) == 0)
						{
							soluongnhapbandau1 = soluongnhapbandau;
						}
						else
						{
							soluongnhapbandau1 = 0;
						}
						if (strcmp(loai, "X") == 0 && ToFloat(soluong3) > TimVatTu(root, mavt3)->soluongTon + soluongnhapbandau1)
						{
							TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
							settextstyle(0, 0, 1);
							char* slton = new char;
							outtextxy(20, 420, "SL khong vuot qua so luong ton");
							outtextxy(20, 440, "SL hien co la: ");
							float hienco = TimVatTu(root, mavt3)->soluongTon + soluongnhapbandau1;
							// FloatToChar(hienco, slton);
							itoa(hienco, slton, 10);
							outtextxy(140, 440, slton);
							goto NHAPSOLUONG3;
						}
						TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
						break;
					}
					case 363: // Don Gia
					{
					NHAPDONGIA:
						NhapSo(dongia, 8, 1, 1175, 140, 39, idnext);
						break;
					}
					case 364: // Vat
					{
					NHAPVAT:
						NhapSo(vat, 4, 2, 1110, 190, 391, idnext);
						break;
					}

					case 70: case 0: case 397: case 396:
					{
						break; // Ko lam gi ca
					}
					case 395: // Xoa Chi Tiet HD
					{
						XOAHD = false;
						XoaChiTietHoaDon(p->List_CTHD, vitri);
						if (strcmp(p->Loai, "N") == 0)
						{
							TimVatTu(root, ct->maVT)->soluongTon = TimVatTu(root, ct->maVT)->soluongTon - ct->soLuong;
							TimVatTuTrongMang(mangds, ct->maVT)->soluongTon = TimVatTu(root, ct->maVT)->soluongTon;
						}
						else if (strcmp(p->Loai, "X") == 0)
						{
							TimVatTu(root, ct->maVT)->soluongTon = TimVatTu(root, ct->maVT)->soluongTon + ct->soLuong;
							TimVatTuTrongMang(mangds, ct->maVT)->soluongTon = TimVatTu(root, ct->maVT)->soluongTon;
						}
						char* dt = new char;
					//	FloatToChar(DoanhThuMotHoaDon(p), dt);
					    lltoa(DoanhThuMotHoaDon(p), dt, 10);
						TaoText(500, 695, 700, 730, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "Tong Tien: ");
						strcat(dt," VND");
						TaoText(800, 695, 1000, 730, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, dt);
						XOAHD = true;
			//			heyz = true;
						goto HIEU_CHINH_HOA_DON_OK;
						break;
					}

					case 3956: // Hieu Chinh Chi Tiet Hoa Don
					{
						EDITHD = false;
						if (strlen(mavt3) == 0)
						{
							TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
							settextstyle(0, 0, 1);
							outtextxy(20, 410, "Ma vat tu khong duoc rong");
							settextstyle(1, 0, 2);
							goto NHAPMAVT3;
						}
						if(CoTonTaiCTHD(p, mavt3) == true && strcmp(mavt3, TimChiTietHD(p->List_CTHD, vitri)->maVT) != 0)
		                {
			              	TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
			               	settextstyle(0, 0, 1);
				            outtextxy(20, 410, "Ma vat tu da co trong DS");
			              	settextstyle(1, 0, 2);
			              	TaoTextInput(710, 130, 900, 165, MAUDEN, MAUTRANG, "", 0); // Che Ten VT
			               	goto NHAPMAVT3;
			            }
						if (strlen(soluong3) == 0 || ToFloat(soluong3) == 0)
						{
							TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
							settextstyle(0, 0, 1);
							outtextxy(20, 410, "So luong khong duoc rong");
							settextstyle(1, 0, 2);
							goto NHAPSOLUONG3;
						}
						if(strcmp(TimVatTu(root,mavt3)->maVT, mavtbandau) == 0)
						{
							soluongnhapbandau1 = soluongnhapbandau;
						}
						else
						{
							soluongnhapbandau1 = 0;
						}
						if (strcmp(p->Loai, "X") == 0 && toInt(soluong3) > TimVatTu(root, mavt3)->soluongTon + soluongnhapbandau1)
						{
							TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
							settextstyle(0, 0, 1);
							outtextxy(20, 410, "So luong ton khong du de XUAT");
							outtextxy(20, 430, "SL con lai la: ");
							char* h = new char;
//							strcpy(h, "               ");
//							char* sluong = new char;
//							// FloatToChar(TimVatTu(root, mavt3)->soluongTon, sluong);
//							itoa(TimVatTu(root, mavt3)->soluongTon, sluong, 10);
//							strcat(h, sluong);
//							outtextxy(20, 430, h);
//							settextstyle(1, 0, 2);
//							
							float hienco = TimVatTu(root, mavt3)->soluongTon + soluongnhapbandau1;
							itoa(hienco, h, 10);
							outtextxy(150, 430, h);
							
							
							goto NHAPSOLUONG3;
						}
						if (strlen(dongia) == 0)
						{
							TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
							settextstyle(0, 0, 1);
							outtextxy(20, 410, "Don gia khong duoc rong");
							settextstyle(1, 0, 2);
							goto NHAPDONGIA;
						}
						if (strlen(vat) == 0 || ToFloat(vat) > 100)
						{
							TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
							settextstyle(0, 0, 1);
							outtextxy(20, 410, "VAT khong duoc rong hoac > 100%");
							settextstyle(1, 0, 2);
							goto NHAPVAT;
						}						
						if (strcmp(p->Loai, "N") == 0)
						{
							if(strcmp(TimVatTu(root,mavt3)->maVT, mavtbandau) == 0) // khong thay doi ma vat tu
							{
								TimVatTu(root, mavt3)->soluongTon = TimVatTu(root, ct->maVT)->soluongTon - soluongnhapbandau +  ToFloat(soluong3);
								TimVatTuTrongMang(mangds, mavt3)->soluongTon = TimVatTu(root, mavt3)->soluongTon;
							}
							else // Thay doi ma vat tu
							{
								TimVatTu(root, mavt3)->soluongTon = TimVatTu(root, mavt3)->soluongTon - soluongnhapbandau1 +  ToFloat(soluong3);
								TimVatTuTrongMang(mangds, mavt3)->soluongTon = TimVatTu(root, mavt3)->soluongTon;
								TimVatTu(root, mavtbandau)->soluongTon = TimVatTu(root, mavtbandau)->soluongTon - soluongnhapbandau;
								TimVatTuTrongMang(mangds, mavtbandau)->soluongTon = TimVatTu(root, mavtbandau)->soluongTon;
							}
						}
						else if (strcmp(p->Loai, "X") == 0)
						{
							if(strcmp(TimVatTu(root,mavt3)->maVT, mavtbandau) == 0) // khong thay doi ma vat tu
							{
								TimVatTu(root, mavt3)->soluongTon = TimVatTu(root, mavt3)->soluongTon + soluongnhapbandau -  ToFloat(soluong3);
								TimVatTuTrongMang(mangds, mavt3)->soluongTon = TimVatTu(root, mavt3)->soluongTon;
							}
							else // Thay doi ma vat tu
							{
								TimVatTu(root, mavt3)->soluongTon = TimVatTu(root, mavt3)->soluongTon +  soluongnhapbandau1 -  ToFloat(soluong3);
								TimVatTuTrongMang(mangds, mavt3)->soluongTon = TimVatTu(root, mavt3)->soluongTon;
								TimVatTu(root, mavtbandau)->soluongTon = TimVatTu(root, mavtbandau)->soluongTon + soluongnhapbandau;
								TimVatTuTrongMang(mangds, mavtbandau)->soluongTon = TimVatTu(root, mavtbandau)->soluongTon;
							}
						}

						CHITIETHOADON cttam;
						cttam.donGia = toInt(dongia);
						strcpy(cttam.maVT, mavt3);
						cttam.soLuong = ToFloat(soluong3);
						cttam.VAT = ToFloat(vat);
						HieuChinhHoaDon(p->List_CTHD, vitri, cttam);
						EDITHD = true;
				//		heyz = true;
						goto HIEU_CHINH_HOA_DON_OK;
						break;
					}

					default:
					{
					//	heyz = false;						
						goto HIEU_CHINH_HOA_DON_OK;
						break;
					}
					}
				}
			}
		HIEU_CHINH_HOA_DON_OK:
			VeBangHoaDon(NumPageHD);
			InHoaDon(p->List_CTHD, root, NumPageHD);
			char* dt = new char;
			// FloatToChar(DoanhThuMotHoaDon(p), dt);
			lltoa(DoanhThuMotHoaDon(p), dt, 10);
			TaoText(500, 695, 700, 730, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "Tong Tien: ");
			strcat(dt," VND");
			TaoText(800, 695, 1000, 730, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, dt);
			if(EDITHD == true)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
				settextstyle(0, 0, 1);
				TaoTextThongBao(20, 420, 289, 450, MAUTRANG, MAUXANHDUONG, MAUXANHNHAT, "HIEU CHINH CTHD THANH CONG!");
				settextstyle(1, 0, 2);
			//	EDITHD = false;
			}
			if(XOAHD == true)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
				settextstyle(0, 0, 1);
				TaoTextThongBao(20, 420, 289, 450, MAUTRANG, MAUXANHDUONG, MAUXANHNHAT, "XOA CTHD THANH CONG!");
				settextstyle(1, 0, 2);
			//	XOAHD = false;
			}
			if( (XOAHD == true || EDITHD == true) ) //&& heyz == true
			{
//			cout<<"TA LA MA DAY ---------------------------------------------------------------------" <<endl;
            TaoTextInput(410, 170, 920, 220, MAUXANHNHAT, MAUXANHNHAT, "", 0);
			TaoTextInput(410, 180, 500, 215, MAUTRANG, MAUXANHDUONG, "THEM", 392); // Button NEW
        	TaoTextInput(530, 180, 640, 215, MAUTRANG, MAUCAM, "HD MOI", 394); // Button Tao HD moi
        	goto THEM_MOI_CTHD;
	        }
	        XOAHD = false, EDITHD = false; //heyz = false;
	       //  goto THEM_MOI_CTHD;
			break;
		}
		case 1001: case 1002: case 1003: case 1004: case 1005: case 1006: case 1007: case 1008: case 1009: case 1010: case 1011:
		{
			TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Che khi nhap vao 1 id 1001->1011
			bool XOA_VT = false;
			bool EDIT_VT = false;
			int vitri = (id - 1001) + (NumPageVT - 1) * 10;
			cout << "sl = " << mangds.soluong << endl;
			if (mangds.soluong == 0)
			{
				break;
			}
			else
			{
				tree ptam = TimVatTuTheoViTri(mangds, vitri);
				if (ptam == NULL)
				{
					TaoTextInput(450, 140, 1200, 180, MAUXANHNHAT, MAUXANHNHAT, "", 0); //CHE
					TaoTextInput(450, 140, 530, 180, MAUTRANG, MAUXANHLA, "THEM", 25); // Button Them
	                TaoTextInput(560, 140, 650, 180, MAUTRANG, MAUCAM, " NEW", 26); // Button NEW 
					break;
				}
				else
				{
					TaoTextInput(450, 25, 800, 70, MAUDEN, MAUTRANG, "", 701); // Ma_VT
					TaoTextInput(450, 75, 800, 120, MAUDEN, MAUTRANG, "", 121); // Ten VT
					TaoTextInput(995, 25, 1250, 70, MAUDEN, MAUTRANG, "", 131); // Don Vi
					TaoTextInput(995, 75, 1250, 120, MAUDEN, MAUTRANG, "", 702); // So Luong Ton

                	TaoTextInput(450, 140, 1200, 180, MAUXANHNHAT, MAUXANHNHAT, "", 0); //CHE
                	TaoTextInput(680, 140, 770, 180, MAUTRANG, MAUXANHDUONG, " XOA", 17); // Button NEW = VAT_TU
                	TaoTextInput(800, 140, 980, 180, MAUTRANG, MAUCAM, "HIEU CHINH", 18); // Button Hieu Chinh
					char* text = new char;
					setbkcolor(MAUXANHNHAT); /////
					outtextxy(459, 40, ptam->maVT);
					outtextxy(459, 90, ptam->tenVT);
					outtextxy(1000, 40, ptam->donviTinh);
					// FloatToChar(ptam->soluongTon, text);
					itoa(ptam->soluongTon, text, 10);
					outtextxy(1000, 90, text);
					// Hieu chinh vat tu
					strcpy(mavt, ptam->maVT);
					strcpy(tenvt, ptam->tenVT); // luu ten VT + Hien Thi + Chinh sua thi chi can chinh 1 so ky tu vi da copy truoc do roi
					strcpy(donvi, ptam->donviTinh); // Luu don vi tinh Vat Tu
					soluongton = ptam->soluongTon;
					while (true)
					{
						int id = mapID[x][y];
						x = -1, y = -1;
						delay(0.001);
						if (ismouseclick(WM_LBUTTONDOWN))
						{
							getmouseclick(WM_LBUTTONDOWN, x, y);
							clearmouseclick(WM_LBUTTONDOWN);
							switch (mapID[x][y])
							{
							case 121:
							{
							NhapTenVT:
								TaoTextInput(450, 75, 800, 120, MAUDEN, MAUTRANG, "", 121); // Ho_NV
								ScannerString(tenvt, 14, 459, 90, 22, idnext);
								break;
							}
							case 131:
							{
							NhapDonVi:
								TaoTextInput(995, 25, 1250, 70, MAUDEN, MAUTRANG, "", 231); // Ten_NV
								ScannerString(donvi, 10, 1000, 40, 23, idnext);
								break;
							}
							case 70: case 0: case 15: case 16: case 19: case 20: case 1000:
							{
								break; // Ko lam gi ca
							}
							case 701:
							{
								TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
								settextstyle(0, 0, 1);
								outtextxy(20, 410, "Khong the chinh sua ma vat tu");
								settextstyle(1, 0, 2);
								break;
							}
							case 702:
							{
								TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
								settextstyle(0, 0, 1);
								outtextxy(20, 420, "Khong the chinh sua so luong ton");
								settextstyle(1, 0, 2);
								break;
							}
							case 17: // Xoa Vat Tu
							{
								if (VatTuLapHoaDon(ptam->maVT, dsnv) == true) // Neu vat tu da co trong hoa don thi khong the xoa
								{
									TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
									settextstyle(0, 0, 1);
									outtextxy(20, 420, "Khong the xoa vat tu da lap HD");
									break;
								}
								XoaVatTuKhoiMang(mangds, vitri);
							    XoaVatTu(root, ptam->maVT);
								XOA_VT = true;
								XuatCay(root);
								goto HIEU_CHINH_VAT_TU_OK;
								break;
							}
							case 18: // Hieu chinh vat tu
							{
								EDIT_VT = false;
								if (strlen(tenvt) == 0)
								{
									TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
									settextstyle(0, 0, 1);
									outtextxy(20, 410, "Ten vat tu khong duoc rong");
									settextstyle(1, 0, 2);
									goto NhapTenVT;
								}
								if (strlen(donvi) == 0)
								{
									TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
									settextstyle(0, 0, 1);
									outtextxy(20, 420, "Don vi tinh khong duoc rong");
									settextstyle(1, 0, 2);
									goto NhapDonVi;
								}
								strcpy(ptam->tenVT, tenvt); // Cap nhat lai chinh sua trong mang VT
								strcpy(ptam->donviTinh, donvi); // Cap nhat lai chinh sua
								strcpy(TimVatTu(root, mavt)->tenVT, tenvt);
								strcpy(TimVatTu(root, mavt)->donviTinh, donvi);
								EDIT_VT = true;
								goto HIEU_CHINH_VAT_TU_OK;
							}
							default:
							{
								goto THOAT_HIEU_CHINH_VAT_TU;
								break;
							}
							}
						}
					}
				HIEU_CHINH_VAT_TU_OK:
					setbkcolor(MAUXANHNHAT);
					ManHinh1();
				THOAT_HIEU_CHINH_VAT_TU:
					SapXepVatTuTheoTen(mangds);
					InDanhSachVatTu(mangds, NumPageVT);
					ResetConTentMan1(soluong, donvi, tenvt, mavt);
					if (EDIT_VT == true)
					{
						TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
						settextstyle(0, 0, 1);
						TaoTextThongBao(20, 420, 289, 450, MAUTRANG, MAUXANHDUONG, MAUXANHNHAT, "HIEU CHINH VAT TU THANH CONG!");
						settextstyle(1, 0, 2);
						EDIT_VT = false;
					}
					if (XOA_VT == true)
					{
						TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
						settextstyle(0, 0, 1);
						TaoTextThongBao(20, 420, 289, 450, MAUTRANG, MAUXANHDUONG, MAUXANHNHAT, "XOA VAT TU THANH CONG!");
						settextstyle(1, 0, 2);
						XOA_VT = false;
					}
					//	delete ptam;
					break;
				}
			}
		}
		case 2001: case 2002: case 2003: case 2004: case 2005: case 2006: case 2007: case 2008: case 2009: case 2010: case 2011:
		{
			TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
			int vitri = (id - 2001) + (NumPageNV - 1) * 10;
			bool XOA_NV = false;
			bool EDIT_NV = false;
			if (dsnv.slnv == 0)
			{
				break;
			}
			else
			{
				NhanVien* tam = TimKiemNhanVienTheoViTri(dsnv, vitri);
				if (tam == NULL)
				{
					TaoTextInput(450, 140, 1200, 180, MAUXANHNHAT, MAUXANHNHAT, "", 0); //CHE
					TaoTextInput(450, 140, 530, 180, MAUTRANG, MAUXANHLA, "THEM", 25); // Button Them
                	TaoTextInput(560, 140, 650, 180, MAUTRANG, MAUCAM, " NEW", 26); // Button NEW 
					break;
				}
				else
				{
					TaoTextInput(450, 25, 800, 70, MAUDEN, MAUTRANG, "", 220); // Ma_NV
					TaoTextInput(450, 75, 800, 120, MAUDEN, MAUTRANG, "", 221); // Ho_NV
					TaoTextInput(995, 25, 1250, 70, MAUDEN, MAUTRANG, "", 231); // Ten_NV
					TaoTextInput(995, 75, 1250, 120, MAUDEN, MAUTRANG, "", 241); // Gioi_Tinh
                    TaoTextInput(450, 140, 1200, 180, MAUXANHNHAT, MAUXANHNHAT, "", 0); //CHE
	                TaoTextInput(680, 140, 770, 180, MAUTRANG, MAUXANHDUONG, " XOA", 28); // Button XOA
	                TaoTextInput(790, 140, 970, 180, MAUTRANG, MAUCAM, "HIEU CHINH", 27); // Button HIEU CHINH
					char* text = new char;
					setbkcolor(MAUXANHNHAT);
					itoa(tam->maNV, text, 10);
					setbkcolor(MAUXANHNHAT);
					outtextxy(459, 40, text);
					outtextxy(459, 90, tam->Ho);
					outtextxy(1000, 40, tam->Ten);
					if (tam->Phai == 1)
					{
						outtextxy(1000, 90, "NAM");
					}
					else
					{
						outtextxy(1000, 90, "NU");
					}
					// Hieu chinh nhan vien
					strcpy(ho, tam->Ho); // luu ho
					strcpy(tennv, tam->Ten); // Luu ten
					if (tam->Phai == 1) // Luu gioi tinh // Neu khong nhap thi khong can chinh sua
					{
						strcpy(phai, "Nam");
					}
					else if (tam->Phai == 0)
					{
						strcpy(phai, "Nu");
					}
					while (true)
					{
						int id = mapID[x][y];
						x = -1, y = -1;
						delay(0.001);
						if (ismouseclick(WM_LBUTTONDOWN))
						{
							getmouseclick(WM_LBUTTONDOWN, x, y);
							clearmouseclick(WM_LBUTTONDOWN);
							switch (mapID[x][y])
							{
							case 220:
							{
								TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
								settextstyle(0, 0, 1);
								outtextxy(20, 410, "Khong the chinh sua ma nhan vien");
								settextstyle(1, 0, 2);
								break;
							}
							case 221:
							{
							NhapHo:
								TaoTextInput(450, 75, 800, 120, MAUDEN, MAUTRANG, "", 221); // Ho_NV
								ScannerString(ho, 18, 459, 90, 22, idnext);
								break;
							}
							case 231:
							{
							NhapTen:
								TaoTextInput(995, 25, 1250, 70, MAUDEN, MAUTRANG, "", 231); // Ten_NV
								ScannerString(tennv, 10, 1000, 40, 23, idnext);
								break;
							}
							case 241:
							{
							NhapGioiTinh:
								TaoTextInput(995, 75, 1250, 120, MAUDEN, MAUTRANG, "", 241); // Gioi_Tinh
								ScannerString(phai, 3, 1000, 90, 24, idnext);
								break;
							}
							case 70: case 0: case 25: case 26: case 29: case 30: case 2000:
							{
								break; // Ko lam gi ca
							}
							case 27: // HIEU CHINH
							{
								EDIT_NV = false;
								if (strlen(ho) == 0)
								{
									TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
									settextstyle(0, 0, 1);
									outtextxy(20, 410, "Ho nhan vien khong duoc rong");
									settextstyle(1, 0, 2);
									goto NhapHo;
								}
								if (strlen(tennv) == 0)
								{
									TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
									settextstyle(0, 0, 1);
									outtextxy(20, 420, "Ten nhan vien khong duoc rong");
									settextstyle(1, 0, 2);
									goto NhapTen;
								}
								if (strlen(phai) == 0 || (strcmp(phai, "Nam") != 0 && strcmp(phai, "Nu") != 0))
								{
									TaoTextInput(15, 430, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
									settextstyle(0, 0, 1);
									outtextxy(20, 420, "Phai (Nam/Nu) chua nhap dung");
									settextstyle(1, 0, 2);
									goto NhapGioiTinh;
								}
								strcpy(tam->Ho, ho);
								strcpy(tam->Ten, tennv);
								if (strcmp(phai, "Nam") == 0)
								{
									tam->Phai = 1;
								}
								else if (strcmp(phai, "Nu") == 0)
								{
									tam->Phai = 0;
								}
								EDIT_NV = true;
								goto HIEU_CHINH_NV_OK;
								break;
							}
							case 28: // XOA
							{
								XOA_NV = false;
								if (tam->Head != NULL) // Nhan Vien da lap hoa don thi khong the xoa
								{
									TaoTextInput(15, 430, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
									settextstyle(0, 0, 1);
									outtextxy(20, 420, "Khong the xoa nhan vien da lap HD");
									settextstyle(1, 0, 2);
									break;
								}
								XoaNhanVien(dsnv, vitri);
								XOA_NV = true;
								goto HIEU_CHINH_NV_OK;
								break;
							}
							default:
							{
								goto THOAT_HIEU_CHINH_NV;
								break;
							}
							}
							//break
						}
					}
				HIEU_CHINH_NV_OK:
					setbkcolor(MAUXANHNHAT);
					ManHinh2();
				THOAT_HIEU_CHINH_NV:
					SapXepNhanVienTheoTen(dsnv);
					InDanhSachNhanVien(dsnv, NumPageNV);
					ResetConTentMan2(phai, tennv, ho, manv);
					if (XOA_NV == true)
					{
						TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
						settextstyle(0, 0, 1);
						TaoTextThongBao(20, 420, 289, 450, MAUTRANG, MAUXANHDUONG, MAUXANHNHAT, "XOA NHAN VIEN THANH CONG!");
						settextstyle(1, 0, 2);
						XOA_NV == false;
					}
					if (EDIT_NV == true)
					{
						TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0);
						settextstyle(0, 0, 1);
						TaoTextThongBao(20, 420, 289, 450, MAUTRANG, MAUXANHDUONG, MAUXANHNHAT, "HIEU CHINH NHAN VIEN THANH CONG!");
						settextstyle(1, 0, 2);
						EDIT_NV == false;
					}
					break;
				}
			}
		}
		case 42:
		{
			strcpy(ngay4, "");
			strcpy(thang4, "");
			strcpy(nam4, "");
		NHAP_NGAY_4:
			TaoTextInput(470, 85, 690, 125, MAUDEN, MAUTRANG, "", 42); // Ngay bat dau
			setcolor(MAUXANHDUONG);
			setbkcolor(MAUTRANG);
			settextstyle(1, 0, 1);
			outtextxy(477, 102, "___/___/____");
			setbkcolor(MAUXANHNHAT);
			setcolor(MAUDEN);
			NhapSo(ngay4, 2, 1, 480, 100, 42, idnext);
		NHAP_THANG_4:
			NhapSo(thang4, 2, 1, 537, 100, 42, idnext);
		NHAP_NAM_4:
			NhapSo(nam4, 4, 1, 595, 100, 42, idnext);
			break;
		}
		case 44:
		{
			strcpy(ngay41, "");
			strcpy(thang41, "");
			strcpy(nam41, "");
		NHAP_NGAY_41:
			TaoTextInput(995, 85, 1230, 125, MAUDEN, MAUTRANG, "", 44); // Ngay ket thuc
			setcolor(MAUXANHDUONG);
			setbkcolor(MAUTRANG);
			settextstyle(1, 0, 1);
			outtextxy(1002, 102, "___/___/____");
			setbkcolor(MAUXANHNHAT);
			setcolor(MAUDEN);
			NhapSo(ngay41, 2, 1, 1005, 100, 44, idnext);
		NHAP_THANG_41:
			NhapSo(thang41, 2, 1, 1062, 100, 44, idnext);
		NHAP_NAM_41:
			NhapSo(nam41, 4, 1, 1121, 100, 44, idnext);
			break;
		}
		case 45:
		{
			int Ngay1 = toInt(ngay4);
			int Thang1 = toInt(thang4);
			int Nam1 = toInt(nam4);

			int Ngay2 = toInt(ngay41);
			int Thang2 = toInt(thang41);
			int Nam2 = toInt(nam41);

			if (strlen(ngay4) == 0 || strlen(thang4) == 0 || strlen(thang4) == 0 || SoSanhNgay(Ngay1, Thang1, Nam1) == false)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Thoi gian bat dau nhap khong dung");
				strcpy(ngay4, "");
				strcpy(thang4, "");
				strcpy(nam4, "");
				settextstyle(1, 0, 2);
				TaoTextInput(470, 85, 690, 125, MAUDEN, MAUTRANG, "", 42); // Ngay bat dau
				setcolor(MAUXANHDUONG);
				setbkcolor(MAUTRANG);
				settextstyle(1, 0, 1);
				outtextxy(477, 102, "___/___/____");
				setbkcolor(MAUXANHNHAT);
				setcolor(MAUDEN);
				goto NHAP_NGAY_4;
			}
			if (strlen(ngay41) == 0 || strlen(thang41) == 0 || strlen(thang41) == 0 || SoSanhNgay(Ngay2, Thang2, Nam2) == false)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Thoi gian ket thuc nhap khong dung");
				settextstyle(1, 0, 2);
				strcpy(ngay41, "");
				strcpy(thang41, "");
				strcpy(nam41, "");
				TaoTextInput(995, 85, 1230, 125, MAUDEN, MAUTRANG, "", 44); // Ngay ket thuc
				setcolor(MAUXANHDUONG);
				setbkcolor(MAUTRANG);
				settextstyle(1, 0, 1);
				outtextxy(1002, 102, "___/___/____");
				setbkcolor(MAUXANHNHAT);
				setcolor(MAUDEN);
				goto NHAP_NGAY_41;
			}
			start = { toInt(ngay4), toInt(thang4), toInt(nam4) };
			end = { toInt(ngay41), toInt(thang41), toInt(nam41) };
			if (SoNgayGiuaHaiNgay(start, end) < 0)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Time sau khong duoc < time truoc");
				settextstyle(1, 0, 2);
				goto NHAP_NGAY_41;
			}
			TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
			int dem = SoLuongHoaDonTheoNgay(dsnv, start, end);
			if(dem == 0)
			{
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "KHONG CO HOA DON NAO!");
				settextstyle(1, 0, 2);		
			}
			InDanhSachHoaDonTheoNgay(dsnv, root, start, end, NumPageTK);
			cout << "SLHD = " << SoLuongHoaDonTheoNgay(dsnv, start, end) << endl;
			while (true)
			{
				int id = mapID[x][y];
				x = -1, y = -1;
				delay(0.001);
				if (ismouseclick(WM_LBUTTONDOWN))
				{
					getmouseclick(WM_LBUTTONDOWN, x, y);
					clearmouseclick(WM_LBUTTONDOWN);
					switch (mapID[x][y])
					{
					case 46: // Page lui
					{
						if (NumPageTK == 1)
						{
							break;
						}
						else if (NumPageTK > 1)
						{
							TaoTextInput(620, 695, 1000, 730, MAUXANHNHAT, MAUXANHNHAT, "", 0);
							NumPageTK--;
							VeBangThongKeHD(NumPageTK);
							InDanhSachHoaDonTheoNgay(dsnv, root, start, end, NumPageTK);
							break;
						}
					}
					case 47: // Page Tiep
					{
						cout<<"DEM = "<<dem<<endl;
						int maxtrang;
		            	if(dem % 10 == 0)
			            {
			            	maxtrang = dem / 10;
		             	}
			            else
			            {
				            maxtrang = dem / 10 + 1;
		             	}
						if (NumPageTK >= maxtrang) // 34 => 4 trang
						
						{
							TaoText(620, 695, 1000, 730, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "DA TOI CUOI DANH SACH");
							break;
						}
						else
						{
							NumPageTK++;
							VeBangThongKeHD(NumPageTK);
							InDanhSachHoaDonTheoNgay(dsnv, root, start, end, NumPageTK);
							break;
						}
					}
					case 70: case 0: case 5001: case 5002: case 5003: case 5004: case 5005: case 5006: case 5007: case 5008: case 5009: case 5010: case 5000:
					{
						break;
					}
					default:
					{
						goto THOAT_THONG_KE;
						break;
					}
					}
				}
			}
		THOAT_THONG_KE:
			break;
		}
		case 51:
		{
			strcpy(ngay5, "");
			strcpy(thang5, "");
			strcpy(nam5, "");
		NHAP_NGAY_5:
			TaoTextInput(470, 85, 690, 125, MAUDEN, MAUTRANG, "", 51); // Ngay bat dau
			setcolor(MAUXANHDUONG);
			setbkcolor(MAUTRANG);
			settextstyle(1, 0, 1);
			outtextxy(477, 102, "___/___/____");
			setbkcolor(MAUXANHNHAT);
			setcolor(MAUDEN);
			NhapSo(ngay5, 2, 1, 480, 100, 42, idnext);
		NHAP_THANG_5:
			NhapSo(thang5, 2, 1, 537, 100, 42, idnext);
		NHAP_NAM_5:
			NhapSo(nam5, 4, 1, 595, 100, 42, idnext);
			break;
		}
		case 52:
		{
			strcpy(ngay51, "");
			strcpy(thang51, "");
			strcpy(nam51, "");
		NHAP_NGAY_51:
			TaoTextInput(995, 85, 1230, 125, MAUDEN, MAUTRANG, "", 52); // Ngay ket thuc
			setcolor(MAUXANHDUONG);
			setbkcolor(MAUTRANG);
			settextstyle(1, 0, 1);
			outtextxy(1002, 102, "___/___/____");
			setbkcolor(MAUXANHNHAT);
			setcolor(MAUDEN);
			NhapSo(ngay51, 2, 1, 1005, 100, 44, idnext);
		NHAP_THANG_51:
			NhapSo(thang51, 2, 1, 1062, 100, 44, idnext);
		NHAP_NAM_51:
			NhapSo(nam51, 4, 1, 1121, 100, 44, idnext);
			break;
		}
		case 53:
		{
			int Ngay5 = toInt(ngay5);
			int Thang5 = toInt(thang5);
			int Nam5 = toInt(nam5);

			int Ngay51 = toInt(ngay51);
			int Thang51 = toInt(thang51);
			int Nam51 = toInt(nam51);

			if (strlen(ngay5) == 0 || strlen(thang5) == 0 || strlen(thang5) == 0 || SoSanhNgay(Ngay5, Thang5, Nam5) == false)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Thoi gian bat dau nhap khong dung");
				strcpy(ngay5, "");
				strcpy(thang5, "");
				strcpy(nam5, "");
				settextstyle(1, 0, 2);
				TaoTextInput(470, 85, 690, 125, MAUDEN, MAUTRANG, "", 51); // Ngay bat dau
				setcolor(MAUXANHDUONG);
				setbkcolor(MAUTRANG);
				settextstyle(1, 0, 1);
				outtextxy(477, 102, "___/___/____");
				setbkcolor(MAUXANHNHAT);
				setcolor(MAUDEN);
				goto NHAP_NGAY_5;
			}
			if (strlen(ngay51) == 0 || strlen(thang51) == 0 || strlen(thang51) == 0 || SoSanhNgay(Ngay51, Thang51, Nam51) == false)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Thoi gian ket thuc nhap khong dung");
				settextstyle(1, 0, 2);
				strcpy(ngay51, "");
				strcpy(thang51, "");
				strcpy(nam51, "");
				TaoTextInput(995, 85, 1230, 125, MAUDEN, MAUTRANG, "", 52); // Ngay ket thuc
				setcolor(MAUXANHDUONG);
				setbkcolor(MAUTRANG);
				settextstyle(1, 0, 1);
				outtextxy(1002, 102, "___/___/____");
				setbkcolor(MAUXANHNHAT);
				setcolor(MAUDEN);
				goto NHAP_NGAY_51;
			}
			start = { toInt(ngay5), toInt(thang5), toInt(nam5) };
			end = { toInt(ngay51), toInt(thang51), toInt(nam51) };
			if (SoNgayGiuaHaiNgay(start, end) < 0)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "Time sau khong duoc < time truoc");
				settextstyle(1, 0, 2);
				goto NHAP_NGAY_51;
			}
			TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
			MangDanhSachVatTu mangdt;
			DoanhThuMotVatTu(mangdt, mangds, dsnv, start, end);
			InTopDoanhThu(mangdt, root, dsnv, start, end, 1);
			break;
		}
		case 61: // Nhap so hoa don
	    {
	    	NHAP_SOHD6:
	    	NhapChuoi(sohoadon6, 6, 510, 100, 61,idnext);
	        break;
		}
		case 62: // In Chi Tiet HD
		{
			HoaDon* p = TimCTHD(sohoadon6,dsnv);		
			if(p == NULL)
			{
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				settextstyle(0, 0, 1);
				outtextxy(20, 410, "SHD khong dung hoac khong ton tai");
				settextstyle(1, 0, 2);
				TaoTextInput(820, 70, 1300, 190, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Xoa Phan In Truoc Do
				goto NHAP_SOHD6;
			}
			if(p != NULL)
			{
				TaoTextInput(820, 70, 1300, 190, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Xoa Phan In Truoc Do
				TaoTextInput(15, 400, 290, 500, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Canh bao nhap sai
				TaoTextInput(620, 680, 1000, 720, MAUXANHNHAT, MAUXANHNHAT, "", 0); // Xoa Phan Thong bao cuoi danh sach
				InFullChiTietHoaDon(p->List_CTHD, root, 1);
				char* dt = new char;
			//  FloatToChar(DoanhThuMotHoaDon(p), dt);
			    lltoa(DoanhThuMotHoaDon(p), dt, 10);
			    strcat(dt," VND");
			    TaoText(820, 70, 960, 90, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "Tong Tien: ");
			    TaoText(1000, 70, 1300, 90, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, dt);
			    TaoText(820, 100, 960, 120, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "Nhan Vien: ");
			    TaoText(820, 130, 960, 150, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "Ngay lap HD: ");
			    char* ngaylap = new char;	    
			    char* namlap = new char;
			    char* thanglap = new char;
			    char* timelap = new char;			    			    
			    itoa(p->ngaylapHD.ngay, ngaylap, 10);
				itoa(p->ngaylapHD.thang, thanglap, 10);
				itoa(p->ngaylapHD.nam, namlap, 10);
				char* tam = new char;
				strcpy(tam, ngaylap);
				char* tam1 = strcat(tam, "/");
				char* tam2 = strcat(tam1, thanglap);
				char* tam3 = strcat(tam2, "/");
				char* tam4 = strcat(tam3, namlap);
				TaoText(1020, 130, 1300, 150, MAUXANHNHAT, MAUHONG, MAUXANHNHAT, tam4);
				TaoText(820, 160, 960, 180, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "Loai HD: ");
				char* loaiHD = new char;
				{
					if(strcmp(p->Loai, "N") == 0)
					{
						strcpy(loaiHD, "NHAP");
					}
					else if(strcmp(p->Loai, "X") == 0)
					{
						strcpy(loaiHD, "XUAT");
					}
				}
				TaoText(1000, 160, 1300, 180, MAUXANHNHAT, MAUVANG, MAUXANHNHAT, loaiHD);
			    NhanVien* h = NhanVienLapHoaDon(sohoadon6,dsnv);
			    if(h == NULL)
			    {
			    	break;
			    }
			    else
			    {
			    	char* hovaten = new char;
			    	strcpy(hovaten, h->Ho);
			    	strcat(hovaten, " ");
			    	strcat(hovaten, h->Ten);
			    	TaoText(1000, 100, 1300, 120, MAUXANHNHAT, MAUCAM, MAUXANHNHAT, hovaten);
				}		    
			    
			}
			break;
		}
		case 63: // Page lui
		{
			HoaDon* p = TimCTHD(sohoadon6,dsnv);
			if(p == NULL)
			{
				break;
			}
			if (NumPageCTHD == 1)
			{
				break;
			}
			else if (NumPageCTHD > 1)
			{
				TaoTextInput(620, 680, 1000, 720, MAUXANHNHAT, MAUXANHNHAT, "", 0);
				NumPageCTHD--;
				VeBangInHD(NumPageCTHD);
				InFullChiTietHoaDon(p->List_CTHD, root, NumPageCTHD);
				break;
			}
		}
		case 64: // Page Tiep
		{
			HoaDon* p = TimCTHD(sohoadon6,dsnv);
			if(p == NULL)
			{
				break;
			}
            int maxtrang;
			if(p->List_CTHD.sl % 10 == 0)
			{
				maxtrang = p->List_CTHD.sl / 10;
			}
			else
			{
				maxtrang = p->List_CTHD.sl / 10 + 1;
			}
			if (NumPageCTHD >= maxtrang) // 34 => 4 trang // 20/10 = 2+1
			{
				TaoText(620, 695, 1000, 720, MAUXANHNHAT, MAUXANHDUONG, MAUXANHNHAT, "DA TOI CUOI DANH SACH");
				break;
			}
			else
			{
				NumPageCTHD++;
				VeBangInHD(NumPageCTHD);
				InFullChiTietHoaDon(p->List_CTHD, root, NumPageCTHD);
				break;
			}
		}
		case -1:
		{
			ResetConTentMan1(soluong, donvi, tenvt, mavt);
			setbkcolor(MAUXANHNHAT);
			SapXepVatTuTheoTen(mangds);
			goto MAN_1;
			break;
		}
		case -2:
		{
			ResetConTentMan2(phai, tennv, ho, manv);
			setbkcolor(MAUXANHNHAT);
			ManHinh2();
			InDanhSachNhanVien(dsnv, NumPageNV); // Trang 1 Nhan Vien
			goto MAN_2_3;
			break;
		}
		case -3:
		{
			setbkcolor(MAUXANHNHAT);
			ManHinh3();
			goto MAN_2_3;
			break;
		}
		case -4:
		{
			setbkcolor(MAUXANHNHAT);
			ManHinh4();
			goto MAN_2_3;
			break;
		}
		case -5:
		{
			setbkcolor(MAUXANHNHAT);
			Man4_1();
			goto MAN_2_3;
			break;
		}
		case -7:
		{
			setbkcolor(MAUXANHNHAT);
			VeBangThongTin();
			break;
		}
		case -8:
		{
			setbkcolor(MAUXANHNHAT);
			VeBangHuongDan();
			break;
		}
		case -10:
		{
			setbkcolor(MAUXANHNHAT);
			ManHinhInHD();
			goto MAN_2_3;;
			break;
		}
		}
		if (id == 9999)
		{
			ofstream fileout;
			GhiFile(fileout, mangds, dsnv);
			for(int m = 0; m<dsnv.slnv; m++)
			{
				delete dsnv.ds[m];
			}
			for(int l = 0; l<mangds.soluong; l++)
			{
				delete mangds.ds[l];
			}
			closegraph();
			break;
		}
	}
}
