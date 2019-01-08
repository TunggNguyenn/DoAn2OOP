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
	QuanLyThuVien quanLyThuVien;
	quanLyThuVien.nhap("Sach.csv", "DocGia.csv", "DanhSachPhieuMuonTraSach.csv");
	menuSach();
	quanLyThuVien.xuat();

	//quanLyThuVien.xoaSach();
	//quanLyThuVien.xuat();

	////quanLyThuVien.suaSach();
	////quanLyThuVien.xuat();

	////quanLyThuVien.timKiemSach();

	quanLyThuVien.xoaDocGia();
	quanLyThuVien.xuat();

	//quanLyThuVien.suaDocGia();
	//quanLyThuVien.xuat();

	//quanLyThuVien.timKiemDocGia();

	//ifstream ifopen;
	//ifopen.open("DanhSachPhieuMuonTraSach.csv", ios::in);
	//string s;
	//string test;
	//getline(ifopen, s);

	//vector<PhieuMuonTraSach> phieu;
	////phieu.resize(3);
	//string str1;
	//getline(ifopen, str1, ',');
	//string str2;

	//int dem = 1;
	//while (true)
	//{
	//	getline(ifopen, test);
	//	getline(ifopen, str2, ',');
	//	if (str2.length() == 0)
	//	{
	//		break;
	//	}
	//	else if (str1 != str2)
	//	{
	//		dem++;
	//	}
	//	str1 = str2;
	//}
	//cout << dem;
	//ifopen.seekg(0L, ios::beg);

	//getline(ifopen, s);
	//phieu.resize(dem);
	//for (int i = 0; i < dem; i++)
	//{

	//	phieu[i].nhapFile(ifopen);
	//}

	//for (int i = 0; i < 3; i++)
	//{
	//	phieu[i].xuat();
	//	cout << endl;
	//}
	system("pause");
	return 0;
}