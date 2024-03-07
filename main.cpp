#include <winbgim.h> 
#include "DoHoa.h"

// Doc Mot Vat Tu
void DocMotVatTu(ifstream& filein, tree &root, MangDanhSachVatTu& mangds)
{
	char maVT[11];
	char tenVT[15];
	char donviTinh[11];
	int soluongTon;
	int i = 0;
	filein.open("VATTU.txt", ios::in);
	if (!filein.is_open())
	{
		cout << "Loi mo file VATTU de doc" << endl;
		return;
	}
	while (!filein.eof())
	{
		VatTu* p = TaoNodeVatTu();
		filein.getline(maVT, sizeof(maVT), '\n');
		strcpy(p->maVT, maVT);
		filein.getline(tenVT, sizeof(tenVT), '\n');
		strcpy(p->tenVT, tenVT);
		filein.getline(donviTinh, sizeof(donviTinh), '\n');
		strcpy(p->donviTinh, donviTinh);
		filein >> soluongTon;
		p->soluongTon = soluongTon;
		char* tam = new char;
		filein.getline(tam, sizeof(tam), '\n');
		chuyen_cach(tenVT);
		viet_hoa(tenVT);
		chuyen_cach(donviTinh);
		viet_hoa(donviTinh);
		chuyen_cach(maVT);
		viet_hoa(maVT);
		if (strlen(maVT) == 0 || strlen(maVT) < 6 || strlen(maVT) > 6 || strlen(tenVT) == 0 || strlen(donviTinh) == 0 || soluongTon < 0 ||
			ChuanHoa(maVT) == false || ChuanHoa(tenVT) == false || ChuanHoa(donviTinh) == false)
		{
			break;
		}
		if (KiemTraTrungMaVT(root, maVT) == false)
		{
			int dem = 0;
            if(mangds.soluong == MAX_DSVT)
                return;
            ThemVatTu(root, p);
			ThemVatTuVaoMang(p, mangds, i);
		}
	}
	filein.close();
}

// Doc Mot nhan vien
void DocMotNhanVien(ifstream& filein, DanhSachNhanVien& dsnv)
{
	int maNV;
	char Ho[19];
	char Ten[11];
	int Phai;
	filein.open("NHANVIEN.txt", ios::in);
	if (!filein.is_open())
	{
		cout << "Loi mo file NHANVIEN de doc" << endl;
		return;
	}
	while (!filein.eof())
	{
		maNV = 999999;
		NhanVien* nv = new NhanVien;
		filein >> maNV;
		char* tam = new char;
		filein.getline(tam, sizeof(tam), '\n');
		filein.getline(Ho, sizeof(Ho), '\n');
		filein.getline(Ten, sizeof(Ten), '\n');
		filein >> Phai;
		char* PHAI = new char;
		if (Phai == 1)
		{
			strcpy(PHAI, "Nam");
		}
		else if (Phai == 0)
		{
			strcpy(PHAI, "Nu");
		}
		char* tamx = new char;
		filein.getline(tamx, sizeof(tamx), '\n');
		chuyen_cach(Ho);
		viet_hoa(Ho);
		chuyen_cach(Ten);
		viet_hoa(Ten);
		if (strlen(Ho) == 0 || strlen(PHAI) == 0 || strlen(Ten) == 0 || maNV < 1000 || maNV > 9999 ||
			ChuanHoa(Ho) == false || ChuanHoa(Ten) == false)
		{
			break;
		}
		if (KiemTraTrungMaNV(dsnv, maNV) == false)
		{
			ThemNhanVien(dsnv, maNV, Ho, Ten, PHAI);
		}
	}
	filein.close();
}


// Doc Mot Hoa Don
void DocMotHoaDon(ifstream& filein, DanhSachNhanVien& dsnv, tree &root, MangDanhSachVatTu& mangds)
{
    int maNV;
	char maVT[11];
	float soLuong;
	int donGia;
	int VAT;
	int ngay;
	int thang;
	int nam;
	char soHD[21];
	char Loai[2];
	char* text = new char;
	filein.open("HOADON.txt", ios::in);
	if (!filein.is_open())
	{
		cout << "Loi mo file HOADON de doc" << endl;
		return;
	}
	while (!filein.eof())
	{
		ngay = 99; // Luon sai de doc dung thi OKE
		filein.getline(Loai, sizeof(Loai), '\n');
		filein >> ngay;
		filein.getline(text, sizeof(text), '/');
		filein >> thang;
		filein.getline(text, sizeof(text), '/');
		filein >> nam;
		filein.getline(text, sizeof(text), '\n');
		filein.getline(soHD, sizeof(soHD), '\n');
		filein >> maNV;
		filein.getline(text, sizeof(text), '\n');
		filein.getline(maVT, sizeof(maVT), '\n');
		filein >> soLuong;
		filein >> donGia;
		filein >> VAT;
		cout << "Loai = " << Loai << endl;
		cout << "Ngay = " << ngay << "/" << thang << "/" << nam << endl;
		cout << "So Hoa Don = " << soHD << endl;
		cout << "Ma nhan vien = " << maNV << endl;
		cout << "So luong = " << soLuong << endl;
		cout << "Don gia = " << donGia << endl;
		cout << "Vat = " << VAT << endl;
		if (strlen(Loai) == 0 || SoSanhNgay(ngay, thang, nam) == false || strlen(soHD) == 0 || strlen(soHD) < 6 || strlen(soHD) > 6 || maNV > 9999 || maNV < 1000 || soLuong < 0 || donGia < 0 || VAT < 0)
		{
			continue;
		}
		filein.getline(text, sizeof(text), '\n');
		NhanVien* nv = TimNhanVien(dsnv, maNV);
		if (nv == NULL)
		{
			continue;
		}
		VatTu* vt = TimVatTu(root, maVT);
		if (vt == NULL)
		{
			continue;
		}
		HoaDon* p = TimHoaDonTheoSoHD(nv->Head, soHD);
		if (p != NULL && (strcmp(p->Loai, Loai) != 0 || p->ngaylapHD.ngay != ngay || p->ngaylapHD.thang != thang || p->ngaylapHD.nam != nam))
		{
			continue;
		}
		if (nv == NULL || vt == NULL)
		{
			continue;
		}
//		if(strcmp(Loai, "X") == 0  && soLuong > vt->soluongTon)
//		{
//			continue;
//		}
		TaoHoaDon(nv, vt, Loai, ngay, thang, nam, soHD, soLuong, donGia, VAT, mangds, dsnv, 0);
	}
	filein.close();
}
void GiaiPhong(MangDanhSachVatTu &dsdt)
{
	for(int i = 0; i<dsdt.soluong; i++)
	{
		delete dsdt.ds[i];
	}
}
void DoanhThuMotVatTu2(MangDanhSachVatTu &dsdt, MangDanhSachVatTu dsvt, DanhSachNhanVien dsnv, Date one, Date two)
{
	dsdt.soluong = 0;
	for(int i = 0; i<dsvt.soluong; i++)
	{
		long long doanhthu = 0;
		for(int j = 0; j<dsnv.slnv; j++)
		{
			HoaDon* p = dsnv.ds[j]->Head;
			if(p == NULL)
			{
				continue;
			}
			else
			{
				while(p!=NULL)
				{
					if(SoNgayGiuaHaiNgay(one, p->ngaylapHD) >= 0 && SoNgayGiuaHaiNgay(p->ngaylapHD, two) >= 0 && strcmp(p->Loai, "X") == 0)
					{
						for(int k = 0; k<p->List_CTHD.sl; k++)
						{
							if(strcmp(p->List_CTHD.cthd[k].maVT, dsvt.ds[i]->maVT) == 0)
							{
								long long a = p->List_CTHD.cthd[k].donGia*(p->List_CTHD.cthd[k].VAT/100 +1);
								long long b = a* p->List_CTHD.cthd[k].soLuong;
								doanhthu = doanhthu + b;
							}
						}
					}
					p = p->next;
				}
			}
		}
		dsdt.ds[dsdt.soluong] = new VatTu;
		strcpy(dsdt.ds[dsdt.soluong]->maVT, dsvt.ds[i]->maVT);
		dsdt.ds[dsdt.soluong]->soluongTon = doanhthu;
		dsdt.soluong++;
//		cout<<"Ma VT: "<<dsvt.ds[i]->maVT<<"    "<<dsvt.ds[i]->tenVT<<"     "<<doanhthu<<endl;
	}
	cout<<"DS co so phan tu la: "<<dsdt.soluong<<endl;
	
}
void HoanViDoanhThu1(VatTu* &a, VatTu* &b)
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

void SapXepDoanhThu1(MangDanhSachVatTu &dsdt)
{
	for(int i = 0; i<dsdt.soluong - 1; i++)
	{
		for(int j = 0; j<dsdt.soluong-i-1; j++)
		{
			if(dsdt.ds[j]->soluongTon < dsdt.ds[j+1]->soluongTon)
			{
				HoanViDoanhThu1(dsdt.ds[j], dsdt.ds[j+1]);
			}
		}
	}
}

void InTop(MangDanhSachVatTu dsdt)
{
	SapXepDoanhThu1(dsdt);
	for(int i = 0; i<10; i++)
	{
		cout<<"Ten VT: "<<dsdt.ds[i]->maVT<<"    Doanh Thu = "<<dsdt.ds[i]->soluongTon<<endl;
	}
}
void HoaDonDaAiLapChua(char* sohoadon, DanhSachNhanVien dsnv, int MaNVdanglap)
{
	bool kt = true;
	for(int i = 0; i<dsnv.slnv; i++)
	{
		if(dsnv.ds[i]->maNV != MaNVdanglap)
		{
			HoaDon* p = dsnv.ds[i]->Head;
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
						cout<<"Da co nguoi lap hoa don do"<<endl;
						kt = false;
						break;
					}
					p = p->next;
				}
			}
		}
	}
	if(kt == true)
		cout<<"Chua ai lap hoa don do"<<endl;
}

int SoLuongXuatOneVatTu(DanhSachNhanVien dsnv, char* MaVT, Date one, Date two)
{
	int soluong = 0;
	for(int i = 0; i< dsnv.slnv; i++)
	{
		HoaDon* p = dsnv.ds[i]->Head;
		if(p == NULL)
		{
			continue;
		}
		else
		{
			while(p!=NULL)
			{
				if(SoNgayGiuaHaiNgay(one, p->ngaylapHD) >=0 && SoNgayGiuaHaiNgay(p->ngaylapHD, two) >=0 && strcmp(p->Loai, "X") == 0)
				{
					for(int k = 0; k<p->List_CTHD.sl; k++)
					{
						if(strcmp(p->List_CTHD.cthd[k].maVT, MaVT ) == 0)
						{
							soluong = soluong + p->List_CTHD.cthd[k].soLuong;
						}
					}
				}
				p = p->next;
			}
		}
	}
	return soluong;
}
void XuatCayVT(VatTu* root)
{
	if(root == NULL)
		return;
	else
	{
		XuatCayVT(root->left);
		cout<<"MaVT: "<< root->maVT<<"      TenVT: "<<root->tenVT<<"      SLT  = "<<root->soluongTon<<endl;
		XuatCayVT(root->right);
	}
}
void XuatMang(MangDanhSachVatTu dsvt)
{
	for(int i = 0; i<dsvt.soluong; i++)
	{
		cout<<"MaVT: "<< dsvt.ds[i]->maVT<<"      TenVT: "<<dsvt.ds[i]->tenVT<<"      SLT  = "<<dsvt.ds[i]->soluongTon<<endl;
	}
}
void XuatNhanVien(DanhSachNhanVien dsnv)
{
	for(int i = 0; i<dsnv.slnv; i++)
	{
		cout<<"MaNV: "<< dsnv.ds[i]->maNV<<"      TenNV: "<<dsnv.ds[i]->Ho<<" "<<dsnv.ds[i]->Ten<<endl;
	}
}
NhanVien* XuatNhanVienLapHoaDon(DanhSachNhanVien dsnv, char* sohoadon)
{
	for(int i = 0; i<dsnv.slnv; i++)
	{
		HoaDon* p = dsnv.ds[i]->Head;
		if(p==NULL)
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
void ThemChiTietHoaDon(DS_ChiTietHoaDon &dscthd, ChiTietHoaDon cthd)
{
	if(dscthd.sl == MAX_CTHD)
	{
		return;
	}
	dscthd.cthd[dscthd.sl] = cthd;
	dscthd.sl++;
}
void ThemHoaDon1(HoaDon*& Head, HoaDon* p)
{
	if(Head == NULL)
	{
		Head = p;
	}
	else
	{
		p->next = Head;
		Head = p;
	}
}

void XuatCTHDONEHD(char* sohoadon, DanhSachNhanVien dsnv, int trang)
{
	HoaDon* p = TimCTHD(sohoadon, dsnv); // Tim so hoa don
	if(p == NULL)
	{
		return;
	}
	if(p!=NULL)
	{
		cout<<"So HD: "<<p->soHD<<endl;
		cout<<"Loai: "<<p->Loai<<endl;
	    cout<<"Ngay lap: "<<p->ngaylapHD.ngay<<"/"<<p->ngaylapHD.nam<<"/"<<p->ngaylapHD.nam<<endl;
		for(int i = 0; i< p->List_CTHD.sl; i++)
		{
			if(i>= (trang - 1)* 10 && i< trang*10)
			{
				cout<<"XUAT CTHD THU "<<i+1<<endl;
				cout<<"MaVT: "<<p->List_CTHD.cthd[i].maVT<<endl;
				cout<<"Don gia: "<<p->List_CTHD.cthd[i].donGia<<endl;
				cout<<"So luong: "<<p->List_CTHD.cthd[i].soLuong<<endl;
				cout<<"VAT: "<<p->List_CTHD.cthd[i].VAT<<endl;
			}
		}
	}
}
void TaoHoaDon1(NhanVien*& nv, VatTu* &vt, char* loai, int ngay, int thang, int nam, char* shd, float soluong, int dongia, float vat, MangDanhSachVatTu& mangds, DanhSachNhanVien dsnv, int loaithem)
{
	// Kiem tra nhan vien khac nhan vien nay da ai lap so hoa don nay chua
	bool Add = true;
	for(int i = 0; i<dsnv.slnv; i++)
	{
		if(dsnv.ds[i]->maNV != nv->maNV)
		{
			HoaDon* p = dsnv.ds[i]->Head;
			if(p == NULL)
			{
				continue;
			}
			else
			{
				while(p!=NULL)
				{
					if(strcmp(shd, p->soHD) == 0) // Da co nhan vien lap hoa don nay
					{
						Add = false;
						break;
					}
					p = p->next;
				}
			}
			
		}
	}
	// Kiem tra xem co dung voi hoa don khong
	HoaDon* x = TimHoaDonTheoSoHD(nv->Head, shd); // Da ton tai so hoa don nay
	{
		if(x != NULL)
		{
			if(strcmp(x->Loai, loai) != 0)
			{
				cout<<"Loai khong dung voi hoa don goc"<<endl;
				Add = false;
			}
			if(x->ngaylapHD.ngay != ngay || x->ngaylapHD.thang != thang || x->ngaylapHD.nam != nam)
			{
				cout<<"Ngay lap HD khong dung voi hoa don goc"<<endl;
				Add = false;
			}
		}
	}
	if(Add == true)
	{
		HoaDon* h = TaoNodeHD();
		strcpy(h->Loai, loai);
		Date A = {ngay, thang, nam};
		h->ngaylapHD = A;
		strcpy(h->soHD, shd);
		CHITIETHOADON CT;
		CT.donGia = dongia;
		CT.soLuong = soluong;
		CT.VAT = vat;
		strcpy(CT.maVT, vt->maVT);
		if(TimHoaDonTheoSoHD(nv->Head,shd) == NULL) // Chua co so hoa don nay
		{
			ThemHoaDon(nv->Head, h);
		}	
		if(TimHoaDonTheoSoHD(nv->Head, shd) != NULL) // Da co hoa don nay
		{
			ThemChiTietHD(TimHoaDonTheoSoHD(nv->Head, shd)->List_CTHD, CT);
		}
		
		if(loaithem == 1)
		{
			if(strcmp(loai, "X") == 0)
			{
				vt->soluongTon = vt->soluongTon - soluong;
				TimVatTuTrongMang(mangds, vt->maVT)->soluongTon = vt->soluongTon;
			}
			else if(strcmp(loai, "N") == 0)
			{
				cout<<"SLTon ban dau = "<<vt->soluongTon<<endl;
				vt->soluongTon = vt->soluongTon + soluong;
				cout<<"SLTon sau do = "<<vt->soluongTon<<endl;
				TimVatTuTrongMang(mangds, vt->maVT)->soluongTon = vt->soluongTon;
			}
			cout<<"LAP HOA DON " <<vt->maVT<<" THANH CONG"<<endl;
		}	
	}
	

}
int main()
{
	VatTu* root = NULL;
	DanhSachNhanVien dsnv;
	MangDanhSachVatTu mangds;
	// Ghi Doc File
	ifstream filein;
	DocMotVatTu(filein, root, mangds);
	DocMotNhanVien(filein, dsnv);
	DocMotHoaDon(filein, dsnv, root, mangds);
//	int dem = 0;
//	DemSoLuongVatTu(root, dem);
//	cout<<"Dem = "<<dem<<endl;
//	Date one = {1,2,2021};
//	Date two = {11,9,2021};
//	MangDanhSachVatTu DTHU;
//	DoanhThuMotVatTu2(DTHU, mangds, dsnv, one, two);
//	InTop(DTHU);
//	GiaiPhong(DTHU);
//	cout<<"---------------XUAT CAY----------------------"<<endl;
//	XuatCayVT(root);
//	cout<<"---------------XUAT MANG---------------------"<<endl;
//	XuatMang(mangds);
//	cout<<"---------------SAU XOA-----------------------"<<endl;
//	XoaVatTuKhoiMang(mangds, 12);
//	XoaVatTuKhoiMang(mangds, 12);
//	XoaVatTuKhoiMang(mangds, 12);
//	DoanhThuMotVatTu2(DTHU, mangds, dsnv, one, two);
//	InTop(DTHU);
//	GiaiPhong(DTHU);
//	cout<<"---------------XUAT CAY----------------------"<<endl;
//	XuatCayVT(root);
//	cout<<"---------------XUAT MANG---------------------"<<endl;
//	XuatMang(mangds);
//	cout<<"---------------XUAT NHAN VIEN----------------"<<endl;
//	XuatNhanVien(dsnv);
//	HoaDonDaAiLapChua("HD9755", dsnv, 2342);
//	cout<<"SLXUATHD: "<<SoLuongXuatOneVatTu(dsnv, "VT5555", one, two)<<endl;
//	NhanVien* nv = dsnv.ds[2];
//	NhanVien* nv2 = dsnv.ds[1];
//	VatTu* vt = TimVatTu(root, "VT1234");
//	VatTu* vt2 = TimVatTu(root, "VT2345");
//	VatTu* vt3 = TimVatTu(root, "VT2222");
//	VatTu* vt4 = TimVatTu(root, "VT3333");
//	VatTu* vt5 = TimVatTu(root, "VT4444");
//	VatTu* vt6 = TimVatTu(root, "VT5555");
//	VatTu* vt7 = TimVatTu(root, "VT6666");
//	VatTu* vt8 = TimVatTu(root, "VT7777");
//	VatTu* vt9 = TimVatTu(root, "VT8888");
//	VatTu* vt10 = TimVatTu(root, "VT9999");
//	VatTu* vt11 = TimVatTu(root, "VT1002");
//	VatTu* vt = mangds.ds[0];
//	VatTu* vt2 = mangds.ds[1];
//	TaoHoaDon1(nv, vt, "N", 10, 2, 2021, "HD5555", 200, 100000, 0, mangds, dsnv, 1);
//	TaoHoaDon1(nv, vt2, "N", 10, 2, 2021, "HD5555", 200, 100000, 0, mangds, dsnv, 1);
//	TaoHoaDon1(nv, vt4, "N", 10, 2, 2021, "HD5555", 200, 100000, 0, mangds, dsnv, 1);
//	TaoHoaDon1(nv, vt5, "N", 10, 2, 2021, "HD5555", 200, 100000, 0, mangds, dsnv, 1);
//	TaoHoaDon1(nv, vt3, "N", 10, 2, 2021, "HD5555", 200, 100000, 0, mangds, dsnv, 1);
//	TaoHoaDon1(nv, vt6, "N", 10, 2, 2021, "HD5555", 200, 100000, 0, mangds, dsnv, 1);
//	TaoHoaDon1(nv, vt7, "N", 10, 2, 2021, "HD5555", 200, 100000, 0, mangds, dsnv, 1);
//	TaoHoaDon1(nv, vt8, "N", 10, 2, 2021, "HD5555", 200, 100000, 0, mangds, dsnv, 1);
//	TaoHoaDon1(nv, vt9, "N", 10, 2, 2021, "HD5555", 200, 100000, 0, mangds, dsnv, 1);
//	TaoHoaDon1(nv, vt2, "N", 10, 2, 2021, "HD5555", 200, 100000, 0, mangds, dsnv, 1);
//	TaoHoaDon1(nv, vt10, "N", 10, 2, 2021, "HD5555", 200, 100000, 0, mangds, dsnv, 1);
//	TaoHoaDon1(nv, vt11, "N", 10, 2, 2021, "HD5555", 20, 100000, 0, mangds, dsnv, 1);
//	cout<<"---------------XUAT CAY----------------------"<<endl;
//	XuatCayVT(root);
//	cout<<"---------------XUAT MANG---------------------"<<endl;
//	XuatMang(mangds);
//	cout<<"Nhan vien lap hoa don HD5555 la :"<<XuatNhanVienLapHoaDon(dsnv, "HD5555")->maNV<<"    "<<XuatNhanVienLapHoaDon(dsnv, "HD5555")->Ho<<" "<<XuatNhanVienLapHoaDon(dsnv, "HD5555")->Ten<<endl;
//    XuatCTHDONEHD("HD5555", dsnv, 1);
//    // Ve man hinh
	initwindow(NGANG, DOC);
	setbkcolor(MAUXANHNHAT);
	cleardevice();
	setcolor(MAUDEN);
	XuLy(root, dsnv, mangds);
	return 0;
}
