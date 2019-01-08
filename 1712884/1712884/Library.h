#ifndef __LIBRARY_H__
#define __LIBRARY_H__
#include "MyDate.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;



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

	friend istream& operator>>(istream& input, Sach& sach);
	friend ostream& operator<<(ostream& output, const Sach& sach);
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

	friend istream& operator>>(istream& input, SachTiengViet& sachTiengViet);
	friend ostream& operator<<(ostream& output, SachTiengViet& sachTiengViet);
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

	virtual void setISBN(const string& ISBN);
	virtual string getISBN();

	virtual string loaiSach();
	friend istream& operator>>(istream& input, SachNgoaiVan& sachNgoaiVan);
	friend ostream& operator<<(ostream& output, SachNgoaiVan& sachNgoaiVan);
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

	friend istream& operator>>(istream& input, DocGia& docGia);
	friend ostream& operator<<(ostream& output, const DocGia& docGia);
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
				delete[] i;
			}
		}
	}

	void nhap();
	void xuat();

	friend istream& operator>>(istream& input, PhieuMuonTraSach& phieuMuonTraSach);
//	friend ostream& operator<<(ostream& output, const PhieuMuonTraSach& phieuMuonTraSach);
};


/*Class Quản Lý Thư Viện*/
class QuanLyThuVien
{
private:
	vector<Sach*> sach;
	vector<DocGia> docGia;
	vector<PhieuMuonTraSach> phieuMuonTraSach;
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
	
	void nhap(const string& fileSach, const string& fileDocGia);
	void xuat();

	void themSach();
	void xoaSach();
	void suaSach();
	void timKiemSach();

	void themDocGia();
	void xoaDocGia();
	void suaDocGia();
	void timKiemDocGia();


};

#endif // !LIBRARY_H__
