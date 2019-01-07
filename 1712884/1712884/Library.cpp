#include "Library.h"



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
	cout << setw(12) << left;
	cout << "Ngay cap: ";
	cout << setw(25) << left;
	cout << "Ngay het han: ";
	cout << "\n";
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




/*---------------Sách Tiếng Việt---------------*/
string SachTiengViet::loaiSach()
{
	return "Sach Tieng Viet";
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

istream & operator>>(istream & input, Sach& sach)
{
	getline(input, sach.maSach, ',');
	getline(input, sach.tenSach, ',');
	getline(input, sach.tacGia, ',');
	getline(input, sach.nhaXuatBan, ',');
	input >> sach.giaSach;
	return input;
}

ostream & operator<<(ostream & output, const Sach & sach)
{
	output << setw(15) << left;
	output << sach.maSach;
	output << setw(51) << left;
	output << sach.tenSach;
	output << setw(31) << left;
	output << sach.tacGia;
	output << setw(31) << left;
	output << sach.nhaXuatBan;
	output << setw(15) << left;
	output << sach.giaSach;
	return output;
}

istream & operator>>(istream & input, SachTiengViet & sachTiengViet)
{
	string s;
	float price;
	getline(input, s, ',');
	sachTiengViet.setMaSach(s);
	getline(input, s, ',');
	sachTiengViet.setTenSach(s);
	getline(input, s, ',');
	sachTiengViet.setTacGia(s);
	getline(input, s, ',');
	sachTiengViet.setNhaXuatBan(s);
	input >> price;
	sachTiengViet.setGiaSach(price);
	return input;
}

ostream & operator<<(ostream & output, SachTiengViet & sachTiengViet)
{
	output << setw(15) << left;
	output << sachTiengViet.getMaSach();
	output << setw(51) << left;
	output << sachTiengViet.getTenSach();
	output << setw(31) << left;
	output << sachTiengViet.getTacGia();
	output << setw(31) << left;
	output << sachTiengViet.getNhaXuatBan();
	output << setw(15) << left;
	output << sachTiengViet.getGiaSach();
	return output;
}

istream & operator>>(istream & input, SachNgoaiVan & sachNgoaiVan)
{
	string s;
	float price;
	getline(input, s, ',');
	sachNgoaiVan.setMaSach(s);
	getline(input, s, ',');
	sachNgoaiVan.setTenSach(s);
	getline(input, s, ',');
	sachNgoaiVan.setTacGia(s);
	getline(input, s, ',');
	sachNgoaiVan.setNhaXuatBan(s);
	input >> price;
	sachNgoaiVan.setGiaSach(price);
	input.seekg(1l, ios::cur);
	getline(input, s);
	sachNgoaiVan.setISBN(s);
	return input;
}

ostream & operator<<(ostream & output, SachNgoaiVan & sachNgoaiVan)
{
	output << setw(15) << left;
	output << sachNgoaiVan.getMaSach();
	output << setw(51) << left;
	output << sachNgoaiVan.getTenSach();
	output << setw(31) << left;
	output << sachNgoaiVan.getTacGia();
	output << setw(31) << left;
	output << sachNgoaiVan.getNhaXuatBan();
	output << setw(15) << left;
	output << sachNgoaiVan.getGiaSach();
	output << setw(15) << left;
	output << sachNgoaiVan.getISBN();
	return output;
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
	cout << setw(12) << left;
	cout << this->ngayCap;
	cout << setw(25) << left;
	cout << this->ngayHetHan;
	cout << "\n";
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

istream & operator>>(istream & input, DocGia & docGia)
{
	getline(input, docGia.maDocGia, ',');
	getline(input, docGia.tenDocGia, ',');
	getline(input, docGia.ngaySinh, ',');
	getline(input, docGia.diaChi, ',');
	getline(input, docGia.ngheNghiep, ',');
	getline(input, docGia.ngayCap, ',');
	getline(input, docGia.ngayHetHan);
	return input;
}

ostream & operator<<(ostream & output, const DocGia & docGia)
{
	output << setw(15) << left;
	output << docGia.maDocGia;
	output << setw(31) << left;
	output << docGia.tenDocGia;
	output << setw(12) << left;
	output << docGia.ngaySinh;
	output << setw(25) << left;
	output << docGia.diaChi;
	output << setw(25) << left;
	output << docGia.ngheNghiep;
	output << setw(12) << left;
	output << docGia.ngayCap;
	output << setw(25) << left;
	output << docGia.ngayHetHan;
	output << "\n";
	return output;
}


/*---------------Phiếu Mượn Trả Sách---------------*/
void PhieuMuonTraSach::nhap()
{

}


/*---------------Quản Lý Thư Viện---------------*/
void QuanLyThuVien::nhap(const string & fileSach)
{
	ifstream ifopen;
	ifopen.open(fileSach, ios::in);
	ifopen.seekg(53L, ios::beg);
	
	string test;
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
			SachNgoaiVan* sachNgoaiVan = new SachNgoaiVan;
			ifopen >> *sachNgoaiVan;

			this->sach.resize(this->sach.size() + 1);
			this->sach[this->sach.size() - 1] = sachNgoaiVan;
		}
		else if (count == 4)
		{
			ifopen.seekg(-(int)(pos + 2), ios::cur);
			SachTiengViet* sachTiengViet = new SachTiengViet;
			ifopen >> *sachTiengViet;

			this->sach.resize(this->sach.size() + 1);
			this->sach[this->sach.size() - 1] = sachTiengViet;
		}

		count = 0;
	}
}

void QuanLyThuVien::xuat()
{
	for (auto *i : this->sach)
	{
		i->xuat();
		cout << endl;
	}
}

void QuanLyThuVien::themSach()
{
	int choose;

	do
	{
		cout << "Input 1: Them sach Tieng Viet.\n";
		cout << "      2: Them sach Ngoai Van.\n";
		cin >> choose;
		cin.ignore();
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
