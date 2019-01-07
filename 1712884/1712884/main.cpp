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
	quanLyThuVien.nhap("Sach.csv");
	menuSach();
	quanLyThuVien.xuat();

	quanLyThuVien.themSach();
	menuSach();
	quanLyThuVien.xuat();
	//fstream fopen;
	//fopen.open("Sach.csv");
	//fopen.seekg(53L);

	////string q;
	////fopen >> q;
	////cout << q << endl;
	//vector<Sach*> sach;
	//string test;
	//int count = 0;


	//while (!fopen.eof())
	//{
	//	getline(fopen, test);
	//	for (int i = 0; i < test.length(); i++)
	//	{
	//		if (test[i] == ',')
	//		{
	//			count++;
	//		}
	//	}

	//	if (count == 5)
	//	{
	//		int q = test.length();
	//		fopen.seekg(-(int)(q+2), ios::cur);
	//		SachNgoaiVan* sachNgoaiVan = new SachNgoaiVan;
	//		fopen >> *sachNgoaiVan;

	//		sach.resize(sach.size() + 1);
	//		sach[sach.size()-1] = sachNgoaiVan;
	//	}
	//	else if (count == 4)
	//	{
	//		int q = test.length();
	//		fopen.seekg(-(int)(q+2), ios::cur);
	//		SachTiengViet* sachTiengViet = new SachTiengViet;
	//		fopen >> *sachTiengViet;

	//		sach.resize(sach.size() + 1);
	//		sach[sach.size() - 1] = sachTiengViet;
	//	}
	//	count = 0;
	//}


	//for (int i = 0; i < sach.size(); i++)
	//{
	//	sach[i]->xuat();
	//	cout << endl;
	//}
	system("pause");
	return 0;
}