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

void menuDocGia()
{
	cout << setw(15) << left;
	cout << "Ma doc gia: ";
	cout << setw(31) << left;
	cout << "Ten doc gia: ";
	cout << setw(12) << left;
	cout << "Ngay sinh: ";
	cout << setw(25) << left;
	cout << "Dia chi: ";
	cout << setw(25) << left;
	cout << "Nghe nghiep: ";
	cout << setw(15) << left;
	cout << "Ngay cap: ";
	cout << setw(15) << left;
	cout << "Ngay het han: ";
	cout << "\n";
}

void menuPhieuMuonTraSach()
{
	cout << setw(15) << left;
	cout << "Ma phieu: ";
	cout << setw(31) << left;
	cout << "Ten doc gia: ";
	cout << setw(15) << left;
	cout << "Ngay muon: ";
	cout << setw(15) << left;
	cout << "Ngay het han: ";
	cout << setw(15) << left;
	cout << "Ngay tra: ";
	cout << "\n";
}

Sach & Sach::operator=(const Sach & sach)
{
	if (this != &sach)
	{
		this->maSach = sach.maSach;
		this->tenSach = sach.tenSach;
		this->tacGia = sach.tacGia;
		this->nhaXuatBan = sach.nhaXuatBan;
		this->giaSach = sach.giaSach;
	}

	return *this;
}

/*---------------Sách---------------*/
void Sach::nhap()
{
	cout << "Ma sach: ";
	getline(cin, this->maSach);
	cout << "Ten sach: ";
	getline(cin, this->tenSach);
	cout << "Tac gia: ";
	getline(cin, this->tacGia);
	cout << "Nha xuat ban: ";
	getline(cin, this->nhaXuatBan);
	cout << "Gia sach: ";
	cin >> this->giaSach;
	cin.ignore();
}

void Sach::xuat()
{
	cout << setw(15) << left;
	cout << this->maSach;
	cout << setw(51) << left;
	cout << this->tenSach;
	cout << setw(31) << left;
	cout << this->tacGia;
	cout << setw(31) << left;
	cout << this->nhaXuatBan;
	cout << setw(10) << left;
	cout << this->giaSach;
}

void Sach::nhapFile(istream & iFile)
{
	getline(iFile, this->maSach, ',');
	getline(iFile, this->tenSach, ',');
	getline(iFile, this->tacGia, ',');
	getline(iFile, this->nhaXuatBan, ',');
	iFile >> this->giaSach;
}

void Sach::xuatFile(ostream & oFile)
{
	oFile << this->maSach;
	oFile << ',';
	oFile << this->tenSach;
	oFile << ',';
	oFile << this->tacGia;
	oFile << ',';
	oFile << this->nhaXuatBan;
	oFile << ',';
	oFile << this->giaSach;
}

void Sach::setMaSach(const string& maSach)
{
	this->maSach = maSach;
}

string Sach::getMaSach()
{
	return this->maSach;
}

void Sach::setTenSach(const string & tenSach)
{
	this->tenSach = tenSach;
}

string Sach::getTenSach()
{
	return this->tenSach;
}

void Sach::setTacGia(const string & tacGia)
{
	this->tacGia = tacGia;
}

string Sach::getTacGia()
{
	return this->tacGia;
}

void Sach::setNhaXuatBan(const string & nhaXuatBan)
{
	this->nhaXuatBan = nhaXuatBan;
}

string Sach::getNhaXuatBan()
{
	return this->nhaXuatBan;
}

void Sach::setGiaSach(const float & giaSach)
{
	this->giaSach = giaSach;
}

float Sach::getGiaSach()
{
	return (float)this->giaSach;
}




SachTiengViet & SachTiengViet::operator=(const SachTiengViet & sachTiengViet)
{
	if (this != &sachTiengViet)
	{
		Sach::operator=(sachTiengViet);
	}
	return *this;
}



/*---------------Sách Tiếng Việt---------------*/
string SachTiengViet::loaiSach()
{
	return "Sach Tieng Viet";
}




SachNgoaiVan & SachNgoaiVan::operator=(const SachNgoaiVan & sachNgoaiVan)
{
	if (this != &sachNgoaiVan)
	{
		Sach::operator=(sachNgoaiVan);
		this->ISBN = sachNgoaiVan.ISBN;
	}
	return *this;
}

/*---------------Sách Ngoại Văn---------------*/
void SachNgoaiVan::nhap()
{
	Sach::nhap();
	cout << "Ma ISBN: ";
	getline(cin, this->ISBN);
}

void SachNgoaiVan::xuat()
{
	Sach::xuat();
	cout << setw(13) << left;
	cout << this->ISBN;
}

void SachNgoaiVan::nhapFile(istream & iFile)
{
	Sach::nhapFile(iFile);
	iFile.seekg(1L, ios::cur);
	getline(iFile, this->ISBN);
}

void SachNgoaiVan::xuatFile(ostream & oFile)
{
	Sach::xuatFile(oFile);
	oFile << ',';
	oFile << this->ISBN;
}

void SachNgoaiVan::setISBN(const string & ISBN)
{
	this->ISBN = ISBN;
}

string SachNgoaiVan::getISBN()
{
	return this->ISBN;
}

string SachNgoaiVan::loaiSach()
{
	return "Sach Ngoai Van";
}



/*---------------Đọc Giả---------------*/

void DocGia::nhap()
{
	cout << "Ma doc gia: ";
	getline(cin, this->maDocGia);
	cout << "Ten doc gia: ";
	getline(cin, this->tenDocGia);
	cout << "Ngay sinh: ";
	getline(cin, this->ngaySinh);
	cout << "Dia chi: ";
	getline(cin, this->diaChi);
	cout << "Nghe nghiep: ";
	getline(cin, this->ngheNghiep);
	cout << "Ngay cap: ";
	getline(cin, this->ngayCap);
	cout << "Ngay het han: ";
	getline(cin, this->ngayHetHan);
}

void DocGia::xuat()
{
	cout << setw(15) << left;
	cout << this->maDocGia;
	cout << setw(31) << left;
	cout << this->tenDocGia;
	cout << setw(12) << left;
	cout << this->ngaySinh;
	cout << setw(25) << left;
	cout << this->diaChi;
	cout << setw(25) << left;
	cout << this->ngheNghiep;
	cout << setw(15) << left;
	cout << this->ngayCap;
	cout << setw(15) << left;
	cout << this->ngayHetHan;
}

void DocGia::nhapFile(istream & input)
{
	getline(input, this->maDocGia, ',');
	getline(input, this->tenDocGia, ',');
	getline(input, this->ngaySinh, ',');
	getline(input, this->diaChi, ',');
	getline(input, this->ngheNghiep, ',');
	getline(input, this->ngayCap, ',');
	getline(input, this->ngayHetHan);
}

void DocGia::xuatFile(ostream & output)
{
	output << this->maDocGia;
	output << ',';
	output << this->tenDocGia;
	output << ',';
	output << this->ngaySinh;
	output << ',';
	output << this->diaChi;
	output << ',';
	output << this->ngheNghiep;
	output << ',';
	output << this->ngayCap;
	output << ',';
	output << this->ngayHetHan;
}

void DocGia::setMaDocGia(const string & maDocGia)
{
	this->maDocGia = maDocGia;
}

string DocGia::getMaDocGia()
{
	return this->maDocGia;
}

void DocGia::setTenDocGia(const string & tenDocGia)
{
	this->tenDocGia = tenDocGia;
}

string DocGia::getTenDocGia()
{
	return this->tenDocGia;
}

void DocGia::setNgaySinh(const string & ngaySinh)
{
	this->ngaySinh = ngaySinh;
}

string DocGia::getNngaySinh()
{
	return this->ngaySinh;
}

void DocGia::setDiaChi(const string & diaChi)
{
	this->diaChi = diaChi;
}

string DocGia::getDiaChi()
{
	return this->diaChi;
}

void DocGia::setNgheNghiep(const string & ngheNghiep)
{
	this->ngheNghiep;
}

string DocGia::getNgheNghiep()
{
	return this->ngheNghiep;
}

void DocGia::setNgayCap(const string & ngayCap)
{
	this->ngayCap = ngayCap;
}

string DocGia::getNgayCap()
{
	return this->ngayCap;
}

void DocGia::setNgayHetHan(const string & ngayHetHan)
{
	this->ngayHetHan = ngayHetHan;
}

string DocGia::getNgayHetHan()
{
	return this->ngayHetHan;
}





/*---------------Phiếu Mượn Trả Sách---------------*/
void PhieuMuonTraSach::nhapFile(istream& inFile)
{
	string test;
	int count = 0;
	do
	{
		getline(inFile, this->maPhieu, ',');
		getline(inFile, this->tenDocGia, ',');
		inFile >> this->ngayMuon;
		inFile >> this->ngayHetHan;
		inFile >> this->ngayTra;
		this->sachMuon.resize(this->sachMuon.size() + 1);

		getline(inFile, test);
		for (int i = 0; i < test.length(); i++)
		{
			if (test[i] == ',')
			{
				count++;
			}
		}
		int pos = test.length();
		if (count == 5)
		{
			inFile.seekg(-(pos + 2), ios::cur);
			this->sachMuon[this->sachMuon.size() - 1] = new SachNgoaiVan;
			this->sachMuon[this->sachMuon.size() - 1]->nhapFile(inFile);
		}
		else if (count == 4)
		{
			inFile.seekg(-(pos + 2), ios::cur);
			this->sachMuon[this->sachMuon.size() - 1] = new SachTiengViet;
			this->sachMuon[this->sachMuon.size() - 1]->nhapFile(inFile);
		}

		getline(inFile, test, ',');
		int i = test.length();
		if (this->maPhieu == test)
		{
			inFile.seekg(-(i + 1), ios::cur);
		}
		else
		{
			if (test.length() == 0)
			{
				break;
			}
			inFile.seekg(-(i + 1), ios::cur); break;
		}
		count = 0;
	} while (true);
}

void PhieuMuonTraSach::xuatFile(ostream & outFile)
{
	for (int i = 0; i < this->sachMuon.size(); i++)
	{
		outFile << this->maPhieu;
		outFile << ',';
		outFile << this->tenDocGia;
		outFile << ',';
		outFile << this->ngayMuon;
		outFile << ',';
		outFile << this->ngayHetHan;
		outFile << ',';
		outFile << this->ngayTra;
		outFile << ',';

		this->sachMuon[i]->xuatFile(outFile);
		outFile << '\n';
	}
}

string PhieuMuonTraSach::getMaPhieu()
{
	return this->maPhieu;
}

string PhieuMuonTraSach::getTenDocGia()
{
	return this->tenDocGia;
}

MyDate PhieuMuonTraSach::getNgayHetHan()
{
	return this->ngayHetHan;
}

MyDate PhieuMuonTraSach::getNgayTra()
{
	return this->ngayTra;
}

vector<Sach*>& PhieuMuonTraSach::getSachMuon()
{
	return this->sachMuon;
}



void PhieuMuonTraSach::nhap(const string& maPhieu, const string& tenDocGia)
{
	this->maPhieu = maPhieu;
	this->tenDocGia = tenDocGia;
	cout << "Ngay muon: ";
	this->ngayMuon.nhap();
	cout << "Ngay het han: ";
	this->ngayHetHan.nhap();
	cout << "Ngay tra: ";
	this->ngayTra.nhap();

	int soSach;
	int choose;
	cout << "Nhap so sach can muon: ";
	cin >> soSach;
	cin.ignore();
	this->sachMuon.resize(soSach);


	for (int i = 0; i < soSach; i++)
	{
		cout << "Input 1: Sach Tieng Viet.\n";
		cout << "      2: Sach Ngoai Van.\n";
		cout << "Choose: ";
		cin >> choose;
		cin.ignore();

		if (choose == 1)
		{
			this->sachMuon[i] = new SachTiengViet;
			this->sachMuon[i]->nhap();
		}
		else if (choose == 2)
		{
			this->sachMuon[i] = new SachNgoaiVan;
			this->sachMuon[i]->nhap();
		}
	}
}

void PhieuMuonTraSach::xuat()
{
	menuPhieuMuonTraSach();
	cout << setw(15) << left;
	cout << this->maPhieu;
	cout << setw(31) << left;
	cout << this->tenDocGia;
	cout << setw(15) << left;
	cout << this->ngayMuon;
	cout << setw(15) << left;
	cout << this->ngayHetHan;
	cout << setw(15) << left;
	cout << this->ngayTra;
	cout << "\n";

	cout << "\nDanh muc sach muon: \n";
	
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

	for (auto *i : this->sachMuon)
	{
		i->xuat();
		cout << '\n';
	}
	cout << "\n_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
}


/*---------------Quản Lý Thư Viện---------------*/
void QuanLyThuVien::nhapFile(const string & fileSach, const string& fileDocGia, const string& filePhieu)
{
	ifstream ifopen;
	/*------------Đọc File Sách------------*/
	ifopen.open(fileSach, ios::in);

	string test;
	getline(ifopen, test);

	int count = 0;

	while (!ifopen.eof())
	{
		getline(ifopen, test);
		for (int i = 0; i < test.length(); i++)
		{
			if (test[i] == ',')
			{
				count++;
			}
		}
		int pos = test.length();
		if (count == 5)
		{
			ifopen.seekg(-(pos + 2), ios::cur);

			this->sach.resize(this->sach.size() + 1);
			this->sach[this->sach.size() - 1] = new SachNgoaiVan;
			this->sach[this->sach.size() - 1]->nhapFile(ifopen);
		}
		else if (count == 4)
		{
			ifopen.seekg(-(int)(pos + 2), ios::cur);

			this->sach.resize(this->sach.size() + 1);
			this->sach[this->sach.size() - 1] = new SachTiengViet;
			this->sach[this->sach.size() - 1]->nhapFile(ifopen);
		}

		count = 0;
	}

	ifopen.close();


	/*------------Đọc File Đọc Giả------------*/
	ifopen.open(fileDocGia, ios::in);

	getline(ifopen, test);

	test = "";
	while (!ifopen.eof())
	{
		ifopen >> test;
		if (test.length() <= 0)
		{
			break;
		}
		else
		{
			int i = test.length();
			ifopen.seekg(-i, ios::cur);
		}
		this->docGia.resize(this->docGia.size() + 1);
		this->docGia[this->docGia.size() - 1].nhapFile(ifopen);

		test = "";
	}
	ifopen.close();


	/*------------Đọc File Danh Sach Phieu Muon Tra Sach------------*/
	ifopen.open("DanhSachPhieuMuonTraSach.csv", ios::in);

	getline(ifopen, test);
	

	while (!ifopen.eof())
	{
		this->phieuMuonTraSach.resize(this->phieuMuonTraSach.size() + 1);
		this->phieuMuonTraSach[this->phieuMuonTraSach.size() - 1] = new PhieuMuonTraSach;
		this->phieuMuonTraSach[this->phieuMuonTraSach.size() - 1]->nhapFile(ifopen);

		test = "";
		getline(ifopen, test, ',');

		if (test.length() != 0)
		{
			int i = test.length();
			ifopen.seekg(-(i + 1), ios::cur);
		}
		else
		{
			break;
		}
	}

	ifopen.close();
}

void QuanLyThuVien::nhap()
{
}

void QuanLyThuVien::xuat()
{
	for (auto *i : this->sach)
	{
		i->xuat();
		cout << endl;
	}

	for (auto i : this->docGia)
	{
		i.xuat();
		cout << endl;
	}

	for (auto *i : this->phieuMuonTraSach)
	{
		i->xuat();
		cout << endl;
	}
}

void QuanLyThuVien::xuatFile(const string & fileSach, const string& fileDocGia, const string& filePhieu)
{
	ofstream ofopen;

	/*------------Ghi File Sách------------*/
	ofopen.open(fileSach, ios::out);

	ofopen << "Ma sach,Ten sach,Tac gia,Nha xuat ban,Gia sach,ISBN\n";

	for (auto *i : this->sach)
	{
		i->xuatFile(ofopen);
		ofopen << '\n';
	}

	ofopen.close();


	/*------------Ghi File Đọc Giả------------*/
	ofopen.open(fileDocGia, ios::out);

	ofopen << "Ma doc gia,Ten doc gia,Ngay sinh,Dia chi,Nghe nghiep,Ngay cap,Ngay het han\n";

	for (auto i : this->docGia)
	{
		i.xuatFile(ofopen);
		ofopen << '\n';
	}

	ofopen.close();

	/*------------Đọc File Danh Sach Phieu Muon Tra Sach------------*/
	ofopen.open(filePhieu, ios::out);

	ofopen << "Ma phieu,Ma doc gia,Ngay muon,Ngay het han,Ngay tra,Ma sach,Ten sach,Tac gia,Nha xuat ban,Gia sach,ISBN\n";

	for (auto *i : this->phieuMuonTraSach)
	{
		i->xuatFile(ofopen);
	}
	ofopen.close();
}

void QuanLyThuVien::themSach()
{
	int choose;

	do
	{
		cout << "Input 1: Them sach Tieng Viet.\n";
		cout << "      2: Them sach Ngoai Van.\n";
		cout << "Choose: ";
		cin >> choose;
		cin.ignore();
		cout << "\nNhap: \n";
		if (choose == 1)
		{
			SachTiengViet* sachTiengViet = new SachTiengViet;
			sachTiengViet->nhap();
			this->sach.resize(this->sach.size() + 1);
			this->sach[this->sach.size() - 1] = sachTiengViet;
			break;
		}
		else if (choose == 2)
		{
			SachNgoaiVan* sachNgoaiVan = new SachNgoaiVan;
			sachNgoaiVan->nhap();
			this->sach.resize(this->sach.size() + 1);
			this->sach[this->sach.size() - 1] = sachNgoaiVan;
			break;
		}
		else
		{
			cout << "Lua chon khong phu hop. Vui long nhap lai.\n\n";
			continue;
		}
	} while (true);
}

void QuanLyThuVien::xoaSach()
{
	int choose;
	string s;

	do
	{
		cout << "Input 1: Xoa dua vao ma sach.\n";
		cout << "      2: Xoa dua vao ten sach.\n";
		cout << "Choose: ";
		cin >> choose;
		cin.ignore();

		if (choose == 1)
		{
			cout << "Nhap ma sach can xoa: ";
			getline(cin, s);
			for (auto *&i : this->sach)
			{
				if (i->getMaSach() == s && i != this->sach[this->sach.size() - 1])
				{
					delete[] i;
					if (dynamic_cast<SachNgoaiVan*>(this->sach[this->sach.size() - 1]))
					{

						i = new SachNgoaiVan;
						*i = *this->sach[this->sach.size() - 1];
						dynamic_cast<SachNgoaiVan*>(i)->setISBN(dynamic_cast<SachNgoaiVan*>(this->sach[this->sach.size() - 1])->getISBN());
					}
					else
					{
						i = new SachTiengViet;
						*i = *this->sach[this->sach.size() - 1];
					}

					this->sach.resize(this->sach.size() - 1);
					break;
				}
				else if (i->getMaSach() == s && i == this->sach[this->sach.size() - 1])
				{
					this->sach.resize(this->sach.size() - 1);
					break;
				}
			}
			break;
		}
		else if (choose == 2)
		{
			cout << "Nhap ten sach can xoa: ";
			getline(cin, s);
			for (auto *i : this->sach)
			{
				if (i->getTenSach() == s && i != this->sach[this->sach.size() - 1])
				{
					delete[] i;
					if (dynamic_cast<SachNgoaiVan*>(this->sach[this->sach.size() - 1]))
					{
						i = new SachNgoaiVan;
						*i = *this->sach[this->sach.size() - 1];
						dynamic_cast<SachNgoaiVan*>(i)->setISBN(dynamic_cast<SachNgoaiVan*>(this->sach[this->sach.size() - 1])->getISBN());
					}
					else
					{
						i = new SachTiengViet;
						*i = *this->sach[this->sach.size() - 1];
					}

					this->sach.resize(this->sach.size() - 1);
					break;
				}
				else if (i->getTenSach() == s && i == this->sach[this->sach.size() - 1])
				{
					this->sach.resize(this->sach.size() - 1);
					break;
				}
				
			}
			break;
		}
		else
		{
			cout << "Lua chon khong phu hop. Vui long nhap lai.\n\n";
			continue;
		}
	} while (true);


}

void QuanLyThuVien::suaSach()
{
	int choose;
	string s;
	bool flag = false;

	cout << "Nhap ma sach can sua: ";
	getline(cin, s);

	for (auto *i : this->sach)
	{
		if (i->getMaSach() == s)
		{
			flag = true;
			string str;
			do
			{
				cout << "Input 1: Sua ma sach.\n";
				cout << "      2: Sua ten sach.\n";
				cout << "      3: Sua tac gia.\n";
				cout << "      4: Sua nha xuat ban.\n";
				cout << "      5: Sua gia sach.\n";
				cout << "Choose: ";
				cin >> choose;
				cin.ignore();
				if (choose == 1)
				{
					cout << "Nhap ma sach moi: ";
					getline(cin, str);
					i->setMaSach(str); break;
				}
				else if (choose == 2)
				{
					cout << "Nhap ten sach moi: ";
					getline(cin, str);
					i->setTenSach(str); break;
				}
				else if (choose == 3)
				{
					cout << "Nhap tac gia moi: ";
					getline(cin, str);
					i->setTacGia(str); break;
				}
				else if (choose == 4)
				{
					cout << "Nhap nha xuat ban moi: ";
					getline(cin, str);
					i->setNhaXuatBan(str); break;
				}
				else if (choose == 5)
				{
					int price;
					cout << "Nhap gia sach moi: ";
					cin >> price;
					cin.ignore();
					i->setGiaSach(price); break;
				}
				else
				{
					cout << "Lua chon khong phu hop. Vui long nhap lai.\n\n";
					continue;
				}
			} while (true);
		}
		if (flag == true)
		{
			break;
		}
	}

	if (flag == false)
	{
		cout << "Ma sach khong ton tai.!!\n\n";
	}
}

void QuanLyThuVien::timKiemSach()
{
	int choose;
	bool flag = false;
	string s;

	do
	{
		cout << "Input 1: Tim kiem theo ma sach.\n";
		cout << "      2: Tim kiem theo ten sach.\n";
		cout << "      3: Tim kiem theo tac gia.\n";
		cout << "Choose: ";
		cin >> choose;
		cin.ignore();


		if (choose == 1)
		{
			cout << "Nhap ma sach can tim: ";
			getline(cin, s);
			menuSach();
			for (auto *i : this->sach)
			{
				if (i->getMaSach() == s)
				{
					i->xuat();
					cout << endl;
					flag = true;
				}
			}
			break;
		}
		else if (choose == 2)
		{
			cout << "Nhap ten sach can tim: ";
			getline(cin, s);
			menuSach();
			for (auto *i : this->sach)
			{
				if (i->getTenSach() == s)
				{
					i->xuat();
					cout << endl;
					flag = true;
				}
			}
			break;
		}
		else if (choose == 3)
		{
			cout << "Nhap ten tac gia can tim: ";
			getline(cin, s);
			menuSach();
			for (auto *i : this->sach)
			{
				if (i->getTacGia() == s)
				{
					i->xuat();
					cout << endl;
					flag = true;
				}
			}
			break;
		}
		else
		{
			cout << "Lua chon khong phu hop. Vui long nhap lai.\n\n";
			continue;
		}
	} while (true);

	if (flag == false)
	{
		cout << "\n\nKhong tim thay thong tin du lieu can tim phu hop.\n\n";
	}
}

void QuanLyThuVien::xemSach()
{
	for (auto *i : this->sach)
	{
		i->xuat();
		cout << endl;
	}
}

void QuanLyThuVien::themDocGia()
{
	this->docGia.resize(this->docGia.size() + 1);
	this->docGia[this->docGia.size() - 1].nhap();
}

void QuanLyThuVien::xoaDocGia()
{
	int choose;
	string s;
	bool flag = false;

	do
	{
		cout << "Input 1: Xoa dua vao ma doc gia.\n";
		cout << "      2: Xoa dua vao ten doc gia.\n";
		cout << "Choose: ";
		cin >> choose;
		cin.ignore();

		if (choose == 1)
		{
			cout << "Nhap ma doc gia can xoa: ";
			getline(cin, s);
			for (int i = 0; i < this->docGia.size(); i++)
			{
				if ((this->docGia[i].getMaDocGia() == s) && (this->docGia[i].getMaDocGia() != this->docGia[this->docGia.size() - 1].getMaDocGia()))
				{
					this->docGia[i] = this->docGia[this->docGia.size() - 1];
					this->docGia.resize(this->docGia.size() - 1);
					break;
				}
				else if ((this->docGia[i].getMaDocGia()) == s && (this->docGia[i].getMaDocGia() == this->docGia[this->docGia.size() - 1].getMaDocGia()))
				{
					this->docGia.resize(this->docGia.size() - 1);
					break;
				}
			}
			break;
		}
		else if (choose == 2)
		{
			cout << "Nhap ten doc gia can xoa: ";
			getline(cin, s);
			for (auto i : this->docGia)
			{
				if (i.getTenDocGia() == s)
				{
					i.xuat();
					flag = true;
				}
			}
			cout << endl;
			if (flag == true)
			{
				string str;
				cout << "Nhap ma doc gia can xoa: ";
				getline(cin, str);
				for (int i = 0; i < this->docGia.size(); i++)
				{
					if (this->docGia[i].getMaDocGia() == str && (this->docGia[i].getMaDocGia() != this->docGia[this->docGia.size() - 1].getMaDocGia()))
					{
						this->docGia[i] = this->docGia[this->docGia.size() - 1];
						this->docGia.resize(this->docGia.size() - 1);
						break;
					}
					else if (this->docGia[i].getMaDocGia() == str && (this->docGia[i].getMaDocGia() == this->docGia[this->docGia.size() - 1].getMaDocGia()))
					{
						this->docGia.resize(this->docGia.size() - 1);
						break;
					}
				}
			}
			break;
		}
		else
		{
			cout << "Lua chon khong phu hop. Vui long nhap lai.\n\n";
			continue;
		}
	} while (true);
}

void QuanLyThuVien::suaDocGia()
{
	int choose;
	string s;
	bool flag = false;

	cout << "Nhap ma doc gia can sua: ";
	getline(cin, s);

	for (int i = 0; i < this->docGia.size(); i++)
	{
		if (this->docGia[i].getMaDocGia() == s)
		{
			flag = true;
			string str;
			do
			{
				cout << "Input 1: Sua ma doc gia.\n";
				cout << "      2: Sua ten doc gia.\n";
				cout << "      3: Sua ngay sinh.\n";
				cout << "      4: Sua dia chi.\n";
				cout << "      5: Sua nghe nghiep.\n";
				cout << "Choose: ";
				cin >> choose;
				cin.ignore();
				if (choose == 1)
				{
					cout << "Nhap ma doc gia moi: ";
					getline(cin, str);
					this->docGia[i].setMaDocGia(str); break;
				}
				else if (choose == 2)
				{
					cout << "Nhap ten doc gia moi: ";
					getline(cin, str);
					this->docGia[i].setTenDocGia(str); break;
				}
				else if (choose == 3)
				{
					cout << "Nhap ngay sinh moi: ";
					getline(cin, str);
					this->docGia[i].setNgaySinh(str); break;
				}
				else if (choose == 4)
				{
					cout << "Nhap dia chi moi: ";
					getline(cin, str);
					this->docGia[i].setDiaChi(str); break;
				}
				else if (choose == 5)
				{
					cout << "Nhap nghe nghiep moi: ";
					getline(cin, str);
					cin.ignore();
					this->docGia[i].setNgheNghiep(str); break;
				}
				else
				{
					cout << "Lua chon khong phu hop. Vui long nhap lai.\n\n";
					continue;
				}
			} while (true);
		}
		if (flag == true)
		{
			break;
		}
	}

	if (flag == false)
	{
		cout << "Ma doc gia khong ton tai.!!\n\n";
	}
}

void QuanLyThuVien::timKiemDocGia()
{
	int choose;
	bool flag = false;
	string s;

	do
	{
		cout << "Input 1: Tim kiem theo ma doc gia.\n";
		cout << "      2: Tim kiem theo ten doc gia.\n";
		cout << "Choose: ";
		cin >> choose;
		cin.ignore();

		if (choose == 1)
		{
			cout << "Nhap ma doc gia can tim: ";
			getline(cin, s);
			menuDocGia();
			for (int i = 0; i < this->docGia.size(); i++)
			{
				if (this->docGia[i].getMaDocGia() == s)
				{
					this->docGia[i].xuat();
					cout << endl;
					flag = true;
				}
			}
			cout << endl;
			break;
		}
		else if (choose == 2)
		{
			cout << "Nhap ten doc gia can tim: ";
			getline(cin, s);
			menuDocGia();
			for (int i = 0; i < this->docGia.size(); i++)
			{
				if (this->docGia[i].getTenDocGia() == s)
				{
					this->docGia[i].xuat();
					cout << endl;
					flag = true;
				}
			}
			cout << endl;
			break;
		}
		else
		{
			cout << "Lua chon khong phu hop. Vui long nhap lai.\n\n";
			continue;
		}
	} while (true);

	if (flag == false)
	{
		cout << "\n\nKhong tim thay thong tin du lieu can tim phu hop.\n\n";
	}
}

void QuanLyThuVien::xemDocGia()
{
	for (auto i : this->docGia)
	{
		i.xuat();
		cout << endl;
	}
}

void QuanLyThuVien::dangKyMuonSach()
{
	string s;
	bool flag = false;
	cout << "Nhap ma doc gia de dang ky: ";
	getline(cin, s);

	for (auto i : this->docGia)
	{
		if (i.getMaDocGia() == s)
		{
			flag = true;
			this->phieuMuonTraSach.resize(this->phieuMuonTraSach.size() + 1);
			this->phieuMuonTraSach[this->phieuMuonTraSach.size() - 1] = new PhieuMuonTraSach;
			this->phieuMuonTraSach[this->phieuMuonTraSach.size() - 1]->nhap(i.getMaDocGia(), i.getTenDocGia()); break;
		}
	}

	if (flag == false)
	{
		cout << "Ban chua dang ky doc gia. Vui long dang ky doc gia truoc khi dang ky muon sach. Tks.!!\n";
	}
}

void QuanLyThuVien::xemPhieuMuonTraSach()
{
	for (auto *i : this->phieuMuonTraSach)
	{
		i->xuat();
		cout << endl;
	}
}

void QuanLyThuVien::danhSachDocGiaBiPhat()
{
	bool flag = false;

	for (auto *i : this->phieuMuonTraSach)
	{
		cout << setw(15) << left;
		cout << "Ma doc gia: ";
		cout << setw(31) << left;
		cout << "Ten doc gia: " << endl;

		cout << setw(15) << left;
		cout << i->getMaPhieu();
		cout << setw(31) << left;
		cout << i->getTenDocGia();

		int tong = 0;
		if (i->getNgayHetHan().distance(i->getNgayTra()) > 0)
		{
			cout << "\n\nDanh muc bi phat do tra tre han: ";
			cout << i->getNgayHetHan().distance(i->getNgayTra()) << " ngay\n";
			
			cout << setw(15) << left;
			cout << "Ma sach: ";
			cout << setw(31) << left;
			cout << "Ten sach: ";
			cout << setw(15) << left;
			cout << "Loai sach: ";
			cout << setw(15) << left;
			cout << "So tien phat: " << endl;
			for (int j = 0; j < i->getSachMuon().size(); j++)
			{
				cout << setw(15) << left;
				cout << i->getSachMuon()[j]->getMaSach();
				cout << setw(31) << left;
				cout << i->getSachMuon()[j]->getTenSach();

				if (dynamic_cast<SachNgoaiVan*>(i->getSachMuon()[j]))
				{
					
					cout << setw(15) << left;
					cout << dynamic_cast<SachNgoaiVan*>(i->getSachMuon()[j])->loaiSach();
					cout << setw(15) << left;
					cout << 20000 * i->getNgayHetHan().distance(i->getNgayTra()) << endl;
					tong += 20000 * i->getNgayHetHan().distance(i->getNgayTra());
				}
				else
				{
					cout << setw(15) << left;
					cout << dynamic_cast<SachTiengViet*>(i->getSachMuon()[j])->loaiSach();
					cout << setw(15) << left;
					cout << 10000 * i->getNgayHetHan().distance(i->getNgayTra()) << endl;
					tong += 10000 * i->getNgayHetHan().distance(i->getNgayTra());
				}

			}
			cout << '\n';
		}
		else
		{
			cout << "Khong bi phat.\n\n";
		}
		cout << "Tong tien phat: " << tong << endl;
		cout << "\n_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
		cout << '\n';
	}
}
