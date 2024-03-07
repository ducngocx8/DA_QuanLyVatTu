#pragma once
#include <iostream>
#include<iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "CTDL.h"
#include "HoTro.h"
using namespace std;

void NhapVatTu(tree &root, char* mavt, char* tenvt, char* donvi, float soluongton);
void ThemVatTu(tree& t, VatTu* p);
void ThemVatTuVaoMang(tree t, MangDanhSachVatTu& mangds, int& i);
void XoaVatTuKhoiMang(MangDanhSachVatTu& mangds, int vitri);
void SapXepVatTuTheoTen(MangDanhSachVatTu& mangds);
VatTu* TimVatTu(tree& t, char* a);
VatTu* TimVatTuTrongMang(MangDanhSachVatTu mangds, char* MaVT);
void DemSoLuongVatTu(tree t, int &dem);
void ThemNhanVien(DanhSachNhanVien& dsnv, int manv, char* ho, char* ten, char* phai);
NhanVien* TimNhanVien(DanhSachNhanVien& dsnv, int manv);
void SapXepNhanVienTheoTen(DanhSachNhanVien& dsnv);
void HieuChinhNhanVien(DanhSachNhanVien& dsnv, int vitri, char* Ho, char* Ten, bool Phai);
void XoaNhanVien(DanhSachNhanVien& dsnv, int vitri);
void ThemHoaDon(HoaDon*& Head, HoaDon* p);
HoaDon* TimHoaDonTheoSoHD(HoaDon* Head, char* SoHoaDon);
void ThemChiTietHD(DS_ChiTietHoaDon& dscthd, ChiTietHoaDon cthdnew);
ChiTietHoaDon* TimChiTietHD(DS_ChiTietHoaDon dscthd, int vitri);
void XoaChiTietHoaDon(DS_CHITIETHOADON& dscthd, int vitri);
bool VatTuLapHoaDon(char* MaVT, DanhSachNhanVien dsnv);
int TimViTriHoaDonCuoi(DanhSachNhanVien dsnv);
void HieuChinhHoaDon(DS_ChiTietHoaDon &dsct, int vitri, CHITIETHOADON tam);
HoaDon* TimCTHD(char* sohoadon, DanhSachNhanVien dsnv);
NhanVien* NhanVienLapHoaDon(char* sohoadon, DanhSachNhanVien dsnv);
bool CoTonTaiCTHD(HoaDon* p, char* mavT);
void GhiFile(ofstream& fileout, MangDanhSachVatTu mangds, DanhSachNhanVien dsnv);
int SoNgayGiuaHaiNgay(Date first, Date end);

// Tao Node Vat Tu
VatTu* TaoNodeVatTu()
{
	VatTu* p = new VatTu;
	p->left = NULL;
	p->right = NULL;
	return p;
}

// Kiem Tra Trung Ma VT
bool KiemTraTrungMaVT(tree t, char* a)
{
	if (t == NULL)
	{
		return false;
	}
	else
	{
		if (strcmp(t->maVT, a) < 0)
		{
			KiemTraTrungMaVT(t->left, a);
		}
		else if (strcmp(t->maVT, a) > 0)
		{
			KiemTraTrungMaVT(t->right, a);
		}
		else
		{
			return true;
		}
	}
}

// Random Ma VT
void RandomMAVT(char ma[])
{
	srand(time(NULL));
	char b[11] = "VT0000";
	for (int i = 2; i < strlen(b); i++)
	{
		b[i] = rand() % (57 - 48 + 1) + 48;
	}
	for (int i = 0; i < strlen(b); i++)
	{
		ma[i] = b[i];
	}
	ma[strlen(b)] = '\0';
}

// ==================================== Nhap Vat Tu =====================
void NhapVatTu(tree& root, char* mavt, char* tenvt, char* donvi, float soluongton)
{
	VatTu* p = TaoNodeVatTu();
	strcpy(p->maVT, mavt);
	strcpy(p->tenVT, tenvt);
	strcpy(p->donviTinh, donvi);
	p->soluongTon = soluongton;
	ThemVatTu(root, p);
}

// ==================================== Them Vat Tu vao DS =====================

void ThemVatTu(tree& t, VatTu* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if ((strcmp(p->maVT, t->maVT) > 0))
		{
			ThemVatTu(t->right, p);
		}
		else if ((strcmp(p->maVT, t->maVT) < 0))
		{
			ThemVatTu(t->left, p);
		}
	}
}

// ========================= Them Vat Tu vao mang =====================

void ThemVatTuVaoMang(tree t, MangDanhSachVatTu& mangds, int& i)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		mangds.ds[i] = new VatTu;
		strcpy(mangds.ds[i]->maVT, t->maVT);
		strcpy(mangds.ds[i]->tenVT, t->tenVT);
		strcpy(mangds.ds[i]->donviTinh, t->donviTinh);
		mangds.ds[i]->soluongTon = t->soluongTon;
		i++;
		mangds.soluong = i;
		ThemVatTuVaoMang(t->left, mangds, i);
		ThemVatTuVaoMang(t->right, mangds, i);
	}
}

void DemSoLuongVatTu(tree t, int &dem)
{
	if(t == NULL)
		return;
	else
	{
		dem++;
		DemSoLuongVatTu(t->right, dem);
		DemSoLuongVatTu(t->left, dem);
	}
}
// ========================= Xoa vat tu khoi mang ==================================

void XoaVatTuKhoiMang(MangDanhSachVatTu& mangds, int vitri)
{
	for (int i = vitri; i < mangds.soluong - 1; i++)
	{
		mangds.ds[i] = mangds.ds[i + 1];
	}
	mangds.soluong--;
}

// ==================================== Sap xep vat tu theo ten =====================
void HoanViVatTu(VatTu*& a, VatTu*& b)
{
	VatTu* tam = new VatTu;
	strcpy(tam->maVT, a->maVT);
	strcpy(tam->tenVT, a->tenVT);
	strcpy(tam->donviTinh, a->donviTinh);
	tam->soluongTon = a->soluongTon;
	strcpy(a->maVT, b->maVT);
	strcpy(a->tenVT, b->tenVT);
	strcpy(a->donviTinh, b->donviTinh);
	a->soluongTon = b->soluongTon;
	strcpy(b->maVT, tam->maVT);
	strcpy(b->tenVT, tam->tenVT);
	strcpy(b->donviTinh, tam->donviTinh);
	b->soluongTon = tam->soluongTon;
	delete tam;
}

void SapXepVatTuTheoTen(MangDanhSachVatTu& mangds)
{
	for (int i = 0; i < mangds.soluong - 1; i++)
	{
		for (int j = 0; j < mangds.soluong - i - 1; j++)
		{
			if (strcmp(mangds.ds[j]->tenVT, mangds.ds[j+1]->tenVT) > 0)
			{
				HoanViVatTu(mangds.ds[j], mangds.ds[j+1]);
			}
		}
	}
}

// ==================================== Tim Vat Tu theo ma vat tu =====================

VatTu* TimVatTu(tree& t, char* a)
{
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		if (strcmp(a, t->maVT) > 0)
		{
			TimVatTu(t->right, a);
		}
		else if (strcmp(a, t->maVT) < 0)
		{
			TimVatTu(t->left, a);
		}
		else
		{
			return t;
		}
	}
}

VatTu* TimVatTuTrongMang(MangDanhSachVatTu mangds, char* MaVT)
{
	for (int i = 0; i < mangds.soluong; i++)
	{
		if (strcmp(MaVT, mangds.ds[i]->maVT) == 0)
		{
			return mangds.ds[i];
		}
	}
	return NULL;
}
// ============================ Tim Vat Tu theo vi tri =====================
VatTu* TimVatTuTheoViTri(MangDanhSachVatTu& mangds, int vitri)
{
	if (vitri >= mangds.soluong)
	{
		return NULL;
	}
	else
	{
		return mangds.ds[vitri];
	}

}

// ==================================== Xoa Vat Tu =====================

void SwapHaiVatTu(tree a, tree b)
{
	tree tam= new VatTu;
	strcpy(tam->maVT, a->maVT);
	strcpy(tam->tenVT, a->tenVT);
	strcpy(tam->donviTinh, a->donviTinh);
	tam->soluongTon = a->soluongTon;
	
	strcpy(a->maVT, b->maVT);
	strcpy(a->tenVT, b->tenVT);
	strcpy(a->donviTinh, b->donviTinh);
	a->soluongTon = b->soluongTon;
	
	strcpy(b->maVT, tam->maVT);
	strcpy(b->tenVT, tam->tenVT);
	strcpy(b->donviTinh, tam->donviTinh);
	b->soluongTon = tam->soluongTon;	
	delete tam;	
}

void NodeThayThe(tree &t, VatTu *&X)
{
	if(t->left!=NULL)
	{
		NodeThayThe(t->left,X);
	}
	else
	{
		SwapHaiVatTu(t,X);
		X = t;
		t=t->right;
	}
}

void XoaVatTu(tree &t, char* ma)
{
	if(t!=NULL)
	{
		if(strcmp(t->maVT, ma) == 0)
		{
			tree X = t;
			if(t->left==NULL)
			{
				t=t->right;
			}
			else if(t->right==NULL)
			{
				t=t->left;
			}
			else if(t->left!=NULL && t->right!=NULL)
			{
				 NodeThayThe(t->right,X);
			}
			delete X;
		}
		else if(strcmp(t->maVT, ma) < 0)
		{
			XoaVatTu(t->right, ma);
		}
		else if(strcmp(t->maVT, ma) > 0)
		{
			XoaVatTu(t->left,ma);
		}
	}
}

// ==================================== Kiem Tra Trung Ma Nhan Vien =====================
bool KiemTraTrungMaNV(DanhSachNhanVien dsnv, int x)
{
	for (int i = 0; i < dsnv.slnv; i++)
	{
		if (dsnv.ds[i]->maNV == x)
		{
			return true;
		}
	}
	return false;
}
int RanDomMaNV(DanhSachNhanVien dsnv)
{
	srand(time(NULL));
	int ma; // 1000-9999
	do
	{
		ma = rand() % (9999 - 1000 + 1) + 1000;
	} 		while (KiemTraTrungMaNV(dsnv, ma) == true);
	return ma;
}

// ==================================== Nhap Nhan Vien =====================

void ThemNhanVien(DanhSachNhanVien& dsnv, int manv, char* ho, char* ten, char* phai)
{
	if (dsnv.slnv >= MAX_DSNV)
	{
		return;
	}
	NhanVien* nv = new NhanVien;
	nv->maNV = manv;
	strcpy(nv->Ho, ho);
	strcpy(nv->Ten, ten);
	if (strcmp(phai, "Nam") == 0)
	{
		nv->Phai = 1;
	}
	else if (strcmp(phai, "Nu") == 0)
	{
		nv->Phai = 0;
	}
	dsnv.ds[dsnv.slnv] = nv;
	dsnv.slnv++;
	SapXepNhanVienTheoTen(dsnv);
}

// ==================================== Tim Mot Nhan Vien Theo Ma NV + Vi Tri=====================

NhanVien* TimNhanVien(DanhSachNhanVien& dsnv, int manv)
{
	for (int i = 0; i < dsnv.slnv; i++)
	{
		if (dsnv.ds[i]->maNV == manv)
		{
			return dsnv.ds[i];
		}
	}
	return NULL;
}

NhanVien* TimKiemNhanVienTheoViTri(DanhSachNhanVien& dsnv, int vitri)
{
	if (vitri >= dsnv.slnv)
	{
		return NULL;
	}
	else
	{
		return dsnv.ds[vitri];
	}
}
// ======================== Sap xep nhan vien theo ten =====================
void HoanViNhanVien(NhanVien*& a, NhanVien*& b)
{
	NhanVien* tam = new NhanVien;
	strcpy(tam->Ho, a->Ho);
	tam->maNV = a->maNV;
	strcpy(tam->Ten, a->Ten);
	tam->Phai = a->Phai;
	tam->Head = a->Head;
	strcpy(a->Ho, b->Ho);
	a->maNV = b->maNV;
	strcpy(a->Ten, b->Ten);
	a->Phai = b->Phai;
	a->Head = b->Head;
	strcpy(b->Ho, tam->Ho);
	b->maNV = tam->maNV;
	strcpy(b->Ten, tam->Ten);
	b->Phai = tam->Phai;
	b->Head = tam->Head;
	delete tam;
}

void SapXepNhanVienTheoTen(DanhSachNhanVien& dsnv)
{
	for (int i = 0; i < dsnv.slnv - 1; i++)
	{
		for (int j = 0; j < dsnv.slnv - i - 1; j++)
		{
			if (strcmp(dsnv.ds[j]->Ten, dsnv.ds[j + 1]->Ten) == 0)
			{
				if (strcmp(dsnv.ds[j]->Ho, dsnv.ds[j + 1]->Ho) > 0);
				{
					int kq = strcmp(dsnv.ds[j]->Ho, dsnv.ds[j + 1]->Ho);
					if (kq > 0)
					{
						HoanViNhanVien(dsnv.ds[j], dsnv.ds[j + 1]);
					}
				}
			}
			if (strcmp(dsnv.ds[j]->Ten, dsnv.ds[j + 1]->Ten) > 0)
			{
				HoanViNhanVien(dsnv.ds[j], dsnv.ds[j + 1]);
			}
		}
	}
}

// ======================= Hieu Chinh Nhan Vien =====================

void HieuChinhNhanVien(DanhSachNhanVien& dsnv, int vitri, char* Ho, char* Ten, bool Phai)
{
	NhanVien* tam = new NhanVien;
	strcpy(tam->Ho, Ho);
	strcpy(tam->Ten, Ten);
	tam->Phai = Phai;
	tam->maNV = TimKiemNhanVienTheoViTri(dsnv, vitri)->maNV;
	dsnv.ds[vitri] = tam;
}
// ======================= Xoa Nhan Vien ============================

void XoaNhanVien(DanhSachNhanVien& dsnv, int vitri)
{
	for (int i = vitri; i < dsnv.slnv - 1; i++)
	{
		dsnv.ds[i] = dsnv.ds[i + 1];
	}
	dsnv.slnv--;
}

// ==================================== Hoa Don =====================
HoaDon* TaoNodeHD()
{
	HoaDon* p = new HoaDon;
	p->next = NULL;
	return p;
}

void RandomMAHD(char ma[])
{
	srand(time(NULL));
	char b[11] = "HD0000";
	for (int i = 2; i < strlen(b); i++)
	{
		b[i] = rand() % (57 - 48 + 1) + 48;
	}
	for (int i = 0; i < strlen(b); i++)
	{
		ma[i] = b[i];
	}
	ma[strlen(b)] = '\0';
}

bool KiemTraTrungMAHD(char ma[], DanhSachNhanVien dsnv)
{
	for (int i = 0; i < dsnv.slnv; i++)
	{
		HoaDon* p = dsnv.ds[i]->Head;
		while (p != NULL)
		{
			if (strcmp(ma, p->soHD) == 0)
			{
				return true;
			}
			p = p->next;
		}
	}
	return false;
}

// ==================================== Them Hoa Don =====================

void ThemHoaDon(HoaDon*& Head, HoaDon* p)
{
	if (Head == NULL)
	{
		Head = p;
	}
	else
	{
		p->next = Head;
		Head = p;
	}
	settextstyle(0, 0, 1);
	outtextxy(20, 410, "Them HOA DON Thanh Cong");
	settextstyle(1, 0, 2);
}
// ==================================== Tim Hoa Don =====================

HoaDon* TimHoaDonTheoSoHD(HoaDon* Head, char* SoHoaDon)
{
	HoaDon* p = Head;
	while (p != NULL)
	{
		if (strcmp(SoHoaDon, p->soHD) == 0)
		{
			cout << "Tim thay hoa don theo so hoa don" << endl;
			return p;
		}
		p = p->next;
	}
	return NULL;
}
void TaoHoaDon(NhanVien*& nv, VatTu* &vt, char* loai, int ngay, int thang, int nam, char* shd, float soluong, int dongia, float vat, MangDanhSachVatTu& mangds, DanhSachNhanVien dsnv, int loaithem)
{
	HoaDon* h = TaoNodeHD();
	strcpy(h->Loai, loai);
	strcpy(h->soHD, shd);
	h->ngaylapHD.ngay = ngay,
	h->ngaylapHD.thang = thang;
	h->ngaylapHD.nam = nam;
	strcpy(h->List_CTHD.cthd[h->List_CTHD.sl].maVT, vt->maVT);
	h->List_CTHD.cthd[h->List_CTHD.sl].donGia = dongia;
	h->List_CTHD.cthd[h->List_CTHD.sl].soLuong = soluong;
	h->List_CTHD.cthd[h->List_CTHD.sl].VAT = vat;
	
	// Neu tim so hoa don nhan vien nhap hien tai chua co trong danh sach hoa don nhan vien nhap thi them hoa don
	// Nguoc lai them chi tiet hoa don
	ChiTietHoaDon cthdnew = h->List_CTHD.cthd[h->List_CTHD.sl];

	bool AddNo = true; // Kiem tra nhan vien khac nhan vien dang lap co lap so hoa don do khong. Neu co thi khong the them
	for (int i = 0; i < dsnv.slnv; i++)
	{
		if (nv->maNV != dsnv.ds[i]->maNV)
		{
			HoaDon* p = dsnv.ds[i]->Head;
			if (p == NULL)
			{
			//	goto HELLO;
				continue;
			}
			while (p != NULL)
			{
				if (strcmp(p->soHD, shd) == 0) // Da co nguoi lap so hoa don do
				{
					AddNo = false;
					cout << "FALSE ROI NE" << endl;
					break;
				}
				p = p->next;
			}
			if (AddNo == false)
			{
				break;
			}
	//	HELLO:
		//	cout << "EBDK" << endl;
		}
	}

	if (TimHoaDonTheoSoHD(nv->Head, shd) == NULL && AddNo == true) // Ko thay so hoa don
	{
		ThemHoaDon(nv->Head, h); // Them Hoa Don cho nhan vien * Se tang so luong hoa don
		h->List_CTHD.sl++;
	}
	else if ((TimHoaDonTheoSoHD(nv->Head, shd) != NULL) && AddNo == true) // Da co so hoa don
	{
		ThemChiTietHD(TimHoaDonTheoSoHD(nv->Head, shd)->List_CTHD, cthdnew);
	}
	if(loaithem == 1)
	{
		if (strcmp(loai, "N") == 0 && AddNo == true)
		{
			vt->soluongTon = vt->soluongTon + soluong;
			TimVatTuTrongMang(mangds, vt->maVT)->soluongTon = vt->soluongTon;
		}
		else if (strcmp(loai, "X") == 0 && AddNo == true)
		{
			vt->soluongTon = vt->soluongTon - soluong;
			TimVatTuTrongMang(mangds, vt->maVT)->soluongTon = vt->soluongTon;
		}
   }

}

//void XuatHoaDon(NhanVien* nv)
//{
//	cout << "Ma nhan vien: " << nv->maNV << endl;
//	cout << "Ho ten: " << nv->Ho << " " << nv->Ten << endl;
//	cout << "Phai: " << nv->Phai << endl;
//	cout << "Thong Tin Hoa Don Da Lap: " << endl;
//	HoaDon* p = nv->List_HD.Head;
//	while (p != NULL)
//	{
//		cout << "So hoa don: " << p->soHD << endl;
//		cout << "Loai hoa don: " << p->Loai << endl;
//		cout << "Ngay lap: " << p->ngaylapHD.ngay << "/" << p->ngaylapHD.thang << "/" << p->ngaylapHD.nam << endl;
//		cout << "--------------------------So Luong -----------------------" << p->List_CTHD.sl << endl;
//		for (int i = 0; i < p->List_CTHD.sl; i++)
//		{
//			cout << "Ma VT: " << p->List_CTHD.cthd[i].maVT << endl;
//			cout << "So luong: " << p->List_CTHD.cthd[i].soLuong << endl;
//			cout << "Don gia: " << p->List_CTHD.cthd[i].donGia << endl;
//			cout << "VAT: " << p->List_CTHD.cthd[i].VAT << endl;
//		}
//		cout << "-------------------END DANH SACH--------------------" << endl;
//		p = p->next;
//	}
//}

void ThemChiTietHD(DS_ChiTietHoaDon& dscthd, ChiTietHoaDon cthdnew)
{
	if(dscthd.sl == MAX_CTHD)
	{
		return;
	}
	dscthd.cthd[dscthd.sl] = cthdnew;
	dscthd.sl++;
	settextstyle(0, 0, 1);
	outtextxy(20, 410, "Them CTHD Thanh Cong");
	settextstyle(1, 0, 2);
}

ChiTietHoaDon* TimChiTietHD(DS_ChiTietHoaDon dscthd, int vitri) // Xoa Hieu Chinh
{
	if (vitri >= dscthd.sl)
	{
		cout << "Khong tim thay chi tiet HD theo vi tri" << endl;
		return NULL;
	}
	else
	{
		cout << "Tim thay chi tiet HD theo vi tri" << endl;
		ChiTietHoaDon* p = new ChiTietHoaDon;
		*p = dscthd.cthd[vitri];
		return p;
	}
}

void XoaChiTietHoaDon(DS_CHITIETHOADON& dscthd, int vitri)
{
	for (int i = vitri; i < dscthd.sl - 1; i++)
	{
		dscthd.cthd[i] = dscthd.cthd[i + 1];
	}
	dscthd.sl--;
}

bool VatTuLapHoaDon(char* MaVT, DanhSachNhanVien dsnv)
{
	for (int j = 0; j < dsnv.slnv; j++)
	{
		HoaDon* p = dsnv.ds[j]->Head;
		while (p != NULL)
		{
			for (int k = 0; k < p->List_CTHD.sl; k++)
			{
				if (strcmp(MaVT, p->List_CTHD.cthd[k].maVT) == 0)
				{
					return true;
				}
			}
			p = p->next;
		}
	}
	return false;
}

int TimViTriHoaDonCuoi(DanhSachNhanVien dsnv) // Xac dinh nhan vien cuoi cung cua danh sach co hoa don
{
	for (int i = dsnv.slnv - 1; i >= 0; i--) // duyet tu cuoi len dau
	{
		if (dsnv.ds[i]->Head != NULL) // Danh sach hoa don cua nhan vien thu i:  NV1 co HD,  NHV3 co HD, NV2 ko co hoa don return 2
		{
			return i; // return nhan vien co hoa don cuoi.
		}
	}
	return -1;
}

void HieuChinhHoaDon(DS_ChiTietHoaDon &dsct, int vitri, CHITIETHOADON tam)
{
	dsct.cthd[vitri] = tam;
}

HoaDon* TimCTHD(char* sohoadon, DanhSachNhanVien dsnv) // Tim so hoa don
{
	HoaDon* p = new HoaDon;
	for(int i = 0; i<dsnv.slnv; i++)
			{
				p = dsnv.ds[i]->Head;
				if(p == NULL)
				{
					continue;
				}
				else
				{
					while(p!=NULL)
					{
					  if(strcmp(p->soHD, sohoadon) == 0)
					  {
						 return p;
						 break;
				      }
				      p = p->next;
				    }
				}
			}
	return NULL;
}

NhanVien* NhanVienLapHoaDon(char* sohoadon, DanhSachNhanVien dsnv)
{
	HoaDon* p = new HoaDon;
	for(int i = 0; i<dsnv.slnv; i++)
			{
				p = dsnv.ds[i]->Head;
				if(p == NULL)
				{
					continue;
				}
				else
				{
					while(p!=NULL)
					{
					  if(strcmp(p->soHD, sohoadon) == 0)
					  {
						 return dsnv.ds[i];
						 break;
				      }
				      p = p->next;
				    }
				}
			}
	return NULL;
}

bool CoTonTaiCTHD(HoaDon* p, char* mavT)
{
	if(p == NULL)
	{
		return false;
	}
	else
	{
		for(int i = 0; i < p->List_CTHD.sl; i++)
		{
			if( strcmp(p->List_CTHD.cthd[i].maVT, mavT) == 0)
			{
				return true;
			}
		}
	}
	return false;
}

void GhiFile(ofstream& fileout, MangDanhSachVatTu mangds, DanhSachNhanVien dsnv)
{
	fileout.open("VATTU.txt", ios::out);
	for (int i = 0; i < mangds.soluong; i++)
	{
		fileout << mangds.ds[i]->maVT;
		fileout << endl;
		fileout << mangds.ds[i]->tenVT;
		fileout << endl;
		fileout << mangds.ds[i]->donviTinh;
		fileout << endl;
		fileout << mangds.ds[i]->soluongTon;
		if (i == mangds.soluong - 1)
		{
			break;
		}
		fileout << endl;
	}
	cout << "GHI FILE VAT TU THANH CONG" << endl;
	fileout.close();
	fileout.open("NHANVIEN.txt", ios::out);
	for (int j = 0; j < dsnv.slnv; j++)
	{
		fileout << dsnv.ds[j]->maNV;
		fileout << endl;
		fileout << dsnv.ds[j]->Ho;
		fileout << endl;
		fileout << dsnv.ds[j]->Ten;
		fileout << endl;
		fileout << dsnv.ds[j]->Phai;
		if (j == dsnv.slnv - 1)
		{
			break;
		}
		fileout << endl;
	}
	fileout.close();
	fileout.open("HOADON.txt", ios::out);
	for (int k = 0; k < dsnv.slnv; k++) // Duyet NV tu dau toi cuoi
	{
		HoaDon* p = dsnv.ds[k]->Head;
		while (p != NULL)
		{
			for (int m = 0; m < p->List_CTHD.sl; m++) // Duyet Chi tiet hoa don cua tung nhan vien
			{
				fileout << p->Loai;
				fileout << endl;
				fileout << p->ngaylapHD.ngay << "/" << p->ngaylapHD.thang << "/" << p->ngaylapHD.nam;
				fileout << endl;
				fileout << p->soHD;
				fileout << endl;
				fileout << dsnv.ds[k]->maNV;
				fileout << endl;
				fileout << p->List_CTHD.cthd[m].maVT;
				fileout << endl;
				fileout << p->List_CTHD.cthd[m].soLuong;
				fileout << endl;
				fileout << p->List_CTHD.cthd[m].donGia;
				fileout << endl;
				fileout << p->List_CTHD.cthd[m].VAT;
				if (k == TimViTriHoaDonCuoi(dsnv) && p->next == NULL && m == p->List_CTHD.sl - 1) // HD1-> HD2-> HD3->NULL Tim thay nhan vien co HD cuoi cung co HD, Chi tiet HD Cuoi
				{
					break; // HD3 - My Tom, Quat, Dien Thoai => 3
				}
				fileout << endl;
			}
			p = p->next;
		}
	}
	fileout.close();
}
bool laNamNhuan(int nYear)
{
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		return true;
	}
	return false;
}
int tinhSoNgayTrongThang(int nMonth, int nYear)
{
	int nNumOfDays;

	switch (nMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		nNumOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		nNumOfDays = 30;
		break;
	case 2:
		if (laNamNhuan(nYear))
		{
			nNumOfDays = 29;
		}
		else
		{
			nNumOfDays = 28;
		}
		break;
	}

	return nNumOfDays;
}

bool laNgayHopLe(int nDay, int nMonth, int nYear)
{
	time_t Time_HT = time(0);
	tm* time_z = localtime(&Time_HT);
	if (nYear < 1900 + time_z->tm_year)
	{
		return false;
	}
	if (nMonth < 1 || nMonth > 12 /* ||nMonth < 1 + time_z->tm_mon */)
	{
		return false;
	}
	if (nDay < 1 || nDay > tinhSoNgayTrongThang(nMonth, nYear))
	{
		return false;
	}
	Date B; // Ngay hien tai
	B.ngay = time_z->tm_mday;
	B.thang = 1 + time_z->tm_mon;
	B.nam = 1900 + time_z->tm_year;
	Date A; // Ngay nhap
	A.ngay = nDay, A.thang = nMonth, A.nam = nYear;
	if (SoNgayGiuaHaiNgay(A, B) > 365)
	{
		return false;
	}
	if (SoNgayGiuaHaiNgay(B, A) > 0)
	{
		return false;
	}
	return true;
}
bool SoSanhNgay(int nDay, int nMonth, int nYear)
{
	if (nYear < 2000)
	{
		return false;
	}
	if (nMonth < 1 || nMonth > 12)
	{
		return false;
	}
	if (nDay < 1 || nDay > tinhSoNgayTrongThang(nMonth, nYear))
	{
		return false;
	}
	return true;
}
int DemSoNamNhuan(Date date)
{
	int years = date.nam;
	if (date.thang <= 2)
		years--;

	return years / 4 - years / 100 + years / 400; // Nam chia het cho 4 khong chia het cho 100 va / 400 
}

int SoNgayGiuaHaiNgay(Date first, Date end)
{
	const int SoNgayTrongThang[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	long int n1 = first.nam * 365 + first.ngay;

	for (int i = 0; i < first.thang - 1; i++)
		n1 += SoNgayTrongThang[i];
	n1 += DemSoNamNhuan(first);

	long int n2 = end.nam * 365 + end.ngay;

	for (int i = 0; i < end.thang - 1; i++)
		n2 += SoNgayTrongThang[i];
	n2 += DemSoNamNhuan(end);

	return (n2 - n1);
}

