#ifndef __LIBRARY_H__
#define __LIBRARY_H__
#include "MyDate.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

void menuSach();
void menuDocGia();
void menuPhieuMuonTraSach();

/*Class Sách*/
class Sach
{
private:
	string maSach;
	string tenSach;
	string tacGia;
	string nhaXuatBan;
	float giaSach;
public:
	Sach() {};
	virtual ~Sach() {};
	Sach& operator=(const Sach& sach);

	virtual void nhap();
	virtual void xuat();

	virtual void nhapFile(istream& iFile);
	virtual void xuatFile(ostream& oFile);


	virtual void setMaSach(const string& maSach);
	virtual string getMaSach();

	virtual void setTenSach(const string& tenSach);
	virtual string getTenSach();

	virtual void setTacGia(const string& tacGia);
	virtual string getTacGia();

	virtual void setNhaXuatBan(const string& nhaXuatBan);
	virtual string getNhaXuatBan();

	virtual void setGiaSach(const float& giaSach);
	virtual float getGiaSach();

};

/*Class Sách Tiếng Việt*/
class SachTiengViet : public Sach
{
private:
public:
	SachTiengViet() : Sach() {};
	virtual ~SachTiengViet() {};
	SachTiengViet& operator=(const SachTiengViet& sachTiengViet);


	virtual string loaiSach();
};

/*Class Sách Ngoại Văn*/
class SachNgoaiVan : public Sach
{
private:
	string ISBN;
public:
	SachNgoaiVan() : Sach() {};
	virtual ~SachNgoaiVan() {};
	SachNgoaiVan& operator=(const SachNgoaiVan& sachNgoaiVan);

	virtual void nhap();
	virtual void xuat();

	virtual void nhapFile(istream& iFile);
	virtual void xuatFile(ostream& oFile);

	virtual void setISBN(const string& ISBN);
	virtual string getISBN();

	virtual string loaiSach();
};

/*Class Đọc Giả*/
class DocGia
{
private:
	string maDocGia;
	string tenDocGia;
	string ngaySinh;
	string diaChi;
	string ngheNghiep;
	string ngayCap;
	string ngayHetHan;
public:
	DocGia() {};
	~DocGia() {};

	void nhap();
	void xuat();

	void nhapFile(istream& input);
	void xuatFile(ostream& output);

	void setMaDocGia(const string& maDocGia);
	string getMaDocGia();

	void setTenDocGia(const string& tenDocGia);
	string getTenDocGia();

	void setNgaySinh(const string& ngaySinh);
	string getNngaySinh();

	void setDiaChi(const string& diaChi);
	string getDiaChi();

	void setNgheNghiep(const string& ngheNghiep);
	string getNgheNghiep();

	void setNgayCap(const string& ngayCap);
	string getNgayCap();

	void setNgayHetHan(const string& ngayHetHan);
	string getNgayHetHan();
};

/*Class Phiếu Mượn Trả Sách*/
class PhieuMuonTraSach
{
private:
	string maPhieu;
	string tenDocGia;
	MyDate ngayMuon;
	MyDate ngayHetHan;
	MyDate ngayTra;
	vector<Sach*> sachMuon;
public:
	PhieuMuonTraSach() {};
	~PhieuMuonTraSach()
	{
		if (this->sachMuon.size() > 0)
		{
			for (auto *i : this->sachMuon)
			{
				delete i;
			}
		}
	}
	void nhap(const string& maPhieu, const string& tenDocGia);
	void xuat();

	void nhapFile(istream& inFile);
	void xuatFile(ostream& outFile);

	string getMaPhieu();
	string getTenDocGia();

	MyDate getNgayHetHan();
	MyDate getNgayTra();
	vector<Sach*>& getSachMuon();
};


/*Class Quản Lý Thư Viện*/
class QuanLyThuVien
{
private:
	vector<Sach*> sach;
	vector<DocGia> docGia;
	vector<PhieuMuonTraSach*> phieuMuonTraSach;
public:
	QuanLyThuVien() {};
	virtual ~QuanLyThuVien()
	{
		if (this->sach.size() > 0)
		{
			for (auto *i : this->sach)
			{
				delete[] i;
			}
		}
	}
	
	void nhap();
	void xuat();

	void nhapFile(const string& fileSach, const string& fileDocGia, const string& filePhieu);
	void xuatFile(const string& fileSach, const string& fileDocGia, const string& filePhieu);

	void themSach();
	void xoaSach();
	void suaSach();
	void timKiemSach();
	void xemSach();

	void themDocGia();
	void xoaDocGia();
	void suaDocGia();
	void timKiemDocGia();
	void xemDocGia();

	void dangKyMuonSach();
	void xemPhieuMuonTraSach();

	void danhSachDocGiaBiPhat();
};

#endif // !LIBRARY_H__
