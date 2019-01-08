#include "Library.h"

void menuSach()
{
	cout << setw(15) << left;
	cout << "Ma sach: ";
	cout << setw(51) << left;
	cout << "Ten sach: ";
	cout << setw(31) << left;
	cout << "Tac gia: ";
	cout << setw(31) << left;
	cout << "Nha xuat ban: ";
	cout << setw(15) << left;
	cout << "Gia sach: ";
	cout << setw(15) << left;
	cout << "ISBN: ";
	cout << "\n";
}


int main()
{
	//QuanLyThuVien quanLyThuVien;
	//quanLyThuVien.nhap("Sach.csv", "DocGia.csv");
	//menuSach();
	//quanLyThuVien.xuat();

	////quanLyThuVien.xoaSach();
	////quanLyThuVien.xuat();

	////quanLyThuVien.suaSach();
	////quanLyThuVien.xuat();

	////quanLyThuVien.timKiemSach();

	//quanLyThuVien.xoaDocGia();
	//quanLyThuVien.xuat();

	//quanLyThuVien.suaDocGia();
	//quanLyThuVien.xuat();

	//quanLyThuVien.timKiemDocGia();

	ifstream ifopen;
	ifopen.open("DanhSachPhieuMuonTraSach.csv", ios::in);
	string s;
	ifopen.seekg(144L, ios::in);
	ifopen >> s;
	cout << s << endl;

	vector<PhieuMuonTraSach> phieu;
	phieu.resize(3);

	for (int i = 0; i < 3; i++)
	{

	}
	system("pause");
	return 0;
}