#pragma once
#define MAX_DSNV 500
#define MAX_CTHD 20

// =========================================  Cay VatTu ====================================
struct VatTu {
	char maVT[11];
	char tenVT[15];
	char donviTinh[11];
	long long soluongTon;
	VatTu* left;
	VatTu* right;
};
typedef struct VatTu VATTU;
typedef VatTu* tree;

// ========================================== Mang chi tiet hoa don==============================
struct ChiTietHoaDon {
	char maVT[11];
	int soLuong;
	int donGia;
	float VAT;
};
typedef struct ChiTietHoaDon CHITIETHOADON;

struct DS_ChiTietHoaDon {
	ChiTietHoaDon cthd[MAX_CTHD];
	int sl = 0;
};
typedef struct DS_ChiTietHoaDon DS_CHITIETHOADON;

struct Date{
	int ngay;
	int thang;
	int nam;
};
typedef struct Date DATEX;

// ============================================ Lien ket don hoa don====================================
struct HoaDon {
	char soHD[21];
	Date ngaylapHD;
	char Loai[2];
	HoaDon* next;
	DS_ChiTietHoaDon List_CTHD;
};
typedef struct HoaDon HOADON;

// ====================================== Mang con tro nhan vien=============================================
struct NhanVien {
	int maNV;
	char Ho[19];
	char Ten[11];
	bool Phai;
	HoaDon* Head = NULL;
};
typedef struct NhanVien NHANVIEN;

struct DanhSachNhanVien {
	NhanVien* ds[MAX_DSNV];
	int slnv = 0;
};
