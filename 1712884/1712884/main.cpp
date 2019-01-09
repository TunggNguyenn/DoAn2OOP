#include "Library.h"



void menu()
{
	cout << setw(20) << left << " ";
	cout << "=========================================================================================================" << endl;

	cout << setw(40) << left << " ";
	cout << "THU VIEN: TNT" << endl;
	cout << setw(40) << left << " ";
	cout << "DIA CHI: XXX" << endl;

	cout << setw(30) << left << " ";
	cout << setw(30) << left;
	cout << "SACH";
	cout << setw(30) << left;
	cout << "DOC GIA";
	cout << setw(30) << left;
	cout << "KHAC" << endl;

	cout << setw(25) << left << " ";
	cout << setw(30) << left;
	cout << "1: Them sach.";
	cout << setw(30) << left;
	cout << "6: Them doc gia.";
	cout << setw(30) << left;
	cout << "11: Dang ky muon sach." << endl;


	cout << setw(25) << left << " ";
	cout << setw(30) << left;
	cout << "2: Xoa sach.";
	cout << setw(30) << left;
	cout << "7: Xoa doc gia.";
	cout << setw(30) << left;
	cout << "12: Xem toan bo phieu d.ky." << endl;


	cout << setw(25) << left << " ";
	cout << setw(30) << left;
	cout << "3: Sua sach.";
	cout << setw(30) << left;
	cout << "8: Sua doc gia.";
	cout << setw(30) << left;
	cout << "13: Danh sach muon sach tre han." << endl;

	cout << setw(25) << left << " ";
	cout << setw(30) << left;
	cout << "4: Tim kiem sach.";
	cout << setw(30) << left;
	cout << "9: Tim kiem doc gia.";
	cout << setw(30) << left;
	cout << "14: Luu moi." << endl;


	cout << setw(25) << left << " ";
	cout << setw(29) << left;
	cout << "5: Xem toan bo sach.";
	cout << setw(31) << left;
	cout << "10: Xem toan bo doc gia.";
	cout << setw(30) << left;
	cout << "15: Thoat." << endl;

	cout << setw(20) << left << " ";
	cout << "=========================================================================================================" << endl;
}


int main()
{
	QuanLyThuVien thuVien;
	thuVien.nhapFile("Sach.csv", "DocGia.csv", "DanhSachPhieuMuonTraSach.csv");

	int choose;
	int y;

	do
	{
		menu();
		cout << setw(45) << " ";
		cout << "Choose: ";
		cin >> choose;
		cin.ignore();

		if (choose == 1)
		{
			do
			{
				thuVien.themSach();
				cout << "Ban co muon tiep tuc khong.?? 1: Yes || 0: No. Press: ";
				cin >> y;
				cin.ignore();
			} while (y != 0);
		}
		else if (choose == 2)
		{
			do
			{
				thuVien.xoaSach();
				cout << "Ban co muon tiep tuc khong.?? 1: Yes || 0: No. Press: ";
				cin >> y;
				cin.ignore();
			} while (y != 0);
		}
		else if (choose == 3)
		{
			do
			{
				thuVien.suaSach();
				cout << "Ban co muon tiep tuc khong.?? 1: Yes || 0: No. Press: ";
				cin >> y;
				cin.ignore();
			} while (y != 0);
		}
		else if (choose == 4)
		{
			do
			{
				thuVien.timKiemSach();
				cout << "Ban co muon tiep tuc khong.?? 1: Yes || 0: No. Press: ";
				cin >> y;
				cin.ignore();
			} while (y != 0);
		}
		else if (choose == 5)
		{
			menuSach();
			thuVien.xemSach();
			cout << "\n\n";
			cout << "Press enter to continue.!!";
			cin.get();
		}
		else if (choose == 6)
		{
			do
			{
				thuVien.themDocGia();
				cout << "Ban co muon tiep tuc khong.?? 1: Yes || 0: No. Press: ";
				cin >> y;
				cin.ignore();
			} while (y != 0);
		}
		else if (choose == 7)
		{
			do
			{
				thuVien.xoaDocGia();
				cout << "Ban co muon tiep tuc khong.?? 1: Yes || 0: No. Press: ";
				cin >> y;
				cin.ignore();
			} while (y != 0);
		}
		else if (choose == 8)
		{
			do
			{
				thuVien.suaDocGia();
				cout << "Ban co muon tiep tuc khong.?? 1: Yes || 0: No. Press: ";
				cin >> y;
				cin.ignore();
			} while (y != 0);
		}
		else if (choose == 9)
		{
			do
			{
				thuVien.timKiemDocGia();
				cout << "Ban co muon tiep tuc khong.?? 1: Yes || 0: No. Press: ";
				cin >> y;
				cin.ignore();
			} while (y != 0);
		}
		else if (choose == 10)
		{
			menuDocGia();
			thuVien.xemDocGia();
			cout << "\n\n";
			cout<<"Press enter to continue.!!";
			cin.get();
		}
		else if (choose == 11)
		{
			do
			{
				thuVien.dangKyMuonSach();
				cout << "Ban co muon tiep tuc khong.?? 1: Yes || 0: No. Press: ";
				cin >> y;
				cin.ignore();
			} while (y != 0);
		}
		else if (choose == 12)
		{
			thuVien.xemPhieuMuonTraSach();
			cout << "\n\n";
			cout << "Press enter to continue.!!";
			cin.get();
		}
		else if (choose == 13)
		{
			thuVien.danhSachDocGiaBiPhat();
		}
		else if (choose == 14)
		{
			thuVien.xuatFile("test1.csv", "test2.csv", "test3.csv");
			cout << "\nLuu FILE thanh cong.!!\n";
			cout << "Press enter to continue.!!";
			cin.get();
		}
		else if (choose == 15)
		{
			cout << "Ban co muon luu lai truoc khi thoat chuong trinh hay khong.?? 1: Yes || 0: No Press: ";
			cin >> y;
			cin.ignore();
			if (y == 1)
			{
				thuVien.xuatFile("test1.csv", "test2.csv", "test3.csv");
				cout << "\nLuu FILE thanh cong.!!\n";
			}
			break;
		}
	} while (true);
	system("pause");
	return 0;
}