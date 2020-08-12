#define MAX 100
#define NGANGDOI '='
#define NGANGDON '-'

typedef unsigned short int Byte;

struct NgayThangNam
{
	Byte ngay;
	Byte thang;
	unsigned int nam;
};

struct ThueBao
{
	unsigned int  MaSo;
	char Ho[40];
	char Ten[8];
	char DiaChi[80];
	char SoDT[12];
	NgayThangNam HopDong;
};

void XuatKeNgangDon()
{
	int i;
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':';
	for (i=1;i<=76;i++)
		cout << NGANGDON;
	cout << ':';
}

void XuatKeNgang()
{
	int i;
	cout << "\n";
	cout << setiosflags(ios::left) << ':';
	for (i=1;i<=76;i++)
		cout << NGANGDOI;
	cout << ':';
}

void XuatTieuDe()
{
	XuatKeNgang();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << "Ma so"
		<< ':'
		<< setw(17) << "Ho"
		<< setw(8) << "Ten"
		<< ':'
		<< setw(15) << "Dia chi"
		<< ':'
		<< setw(13) << "So DT"
		<< ':'
		<< setw(11) << "Ngay HD"
		<< ':';
	XuatKeNgang();
}

void Nhap1TB(ThueBao &p)
{
	cout << "\nNhap ma so thue bao : ";
	_flushall();
	cin >> p.MaSo;
	cout << "\nNhap ho va ten lot : ";
	_flushall();
	gets_s(p.Ho,40);
	cout << "\nNhap ten : ";
	_flushall();
	gets_s(p.Ten,8);
	cout << "\nNhap dia chi : ";
	_flushall();
	gets_s(p.DiaChi,80);
	cout << "\nNhap so dien thoai : ";
	_flushall();
	gets_s(p.SoDT,12);
	cout << "\nNhap ngay hop dong : ";
	_flushall();
	cin >> p.HopDong.ngay;
	cout << "\nNhap thang hop dong : ";
	_flushall();
	cin >> p.HopDong.thang ;
	cout << "\nNhap nam hop dong : ";
	_flushall();
	cin >> p.HopDong.nam;
}

void NhapDS(ThueBao a[MAX], int &n)
{
	int i;
	cout << "\nNhap so luong thue bao n = ";
	cin >> n;
	for (i=0;i<n;i++)
	{
		system("CLS");
		cout << "\nNhap thong tin thue bao thu " << i+1 << " : ";
		Nhap1TB(a[i]);
	}
}

void Xuat1TB(ThueBao p)
{
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << p.MaSo
		<< ':'
		<< setw(17) << p.Ho
		<< setw(8) << p.Ten
		<< ':'
		<< setw(15) << p.DiaChi
		<< ':'
		<< setw(13) << p.SoDT
		<< ':'
		<< setw(2) << p.HopDong.ngay
		<< '/'
		<< setw(2) << p.HopDong.thang
		<< '/'
		<< setw(5) << p.HopDong.nam
		<< ':';
}

void XuatDS(ThueBao a[MAX], int n)
{
	int i;
	XuatTieuDe();
	for (i=0;i<n;i++)
	{
		cout << endl;
		Xuat1TB(a[i]);
		if ((i+1)%5==0)
			XuatKeNgangDon();
	}
	XuatKeNgang();
}

void Tim_SoDT_Ten(ThueBao a[MAX], int n, char ten[8])
{
	int i, dem=0;
	for (i=0;i<n;i++)
		if (_strcmpi(a[i].Ten,ten)==0)
			dem++;
	if (!dem)
		cout << "\nKhong tim thay nguoi nao ten " << ten << " trong danh sach";
	else
	{
		cout << "\nDa tim thay " << dem << " nguoi co ten " << ten << "\n";
		for (i=0;i<n;i++)
			if (_strcmpi(a[i].Ten,ten)==0)
				cout << endl << a[i].Ho << ' ' << a[i].Ten << " co so DT : " << a[i].SoDT;
	}
}

void Tim_TT_SoDT(ThueBao a[MAX], int n, char soDT[12])
{
	int i, dem=0;
	for (i=0;i<n;i++)
		if (_strcmpi(a[i].SoDT,soDT)==0)
			dem++;
	if (!dem)
		cout << "\nKhong tim thay nguoi nao co so dien thoai " << soDT << " trong danh sach";
	else
	{
		cout << "\nThong tin thue bao so dien thoai " << soDT << endl;
		XuatTieuDe();
		for (i=0;i<n;i++)
			if (_strcmpi(a[i].SoDT,soDT)==0)
			{
				cout << endl;
				Xuat1TB(a[i]);
			}
			XuatKeNgang();
	}
}

void XuatTB_CungDiaChi(ThueBao a[MAX], int n)
{
	int i, j, dau, m=0, dem=0;
	ThueBao b[MAX];
	int vt[MAX];
	for (i=0;i<n;i++)
	{
		dau=1;
		for (j=0;j<m && dau;j++)
			dau=dau && (_strcmpi(a[i].DiaChi,b[j].DiaChi)!=0);
		if (dau)
		{
			strcpy_s(b[m++].DiaChi,MAX,a[i].DiaChi);
			vt[m]=i;
			dem++;
		}
	}
	m=1;
	XuatTieuDe();
	while(m<=dem)
	{
		for (i=0;i<n;i++)
		{
			if (_strcmpi(a[i].DiaChi,a[vt[m]].DiaChi)==0)
			{
				cout << endl;
				Xuat1TB(a[i]);
			}
		}
		if (m<dem) XuatKeNgangDon();
		m++;
	};
	XuatKeNgang();

}

void HoanVi(ThueBao &p, ThueBao &q)
{
	ThueBao t;
	t=p;
	p=q;
	q=t;
}

void SapXep_MaVung_Tang(ThueBao a[MAX], int n)
{
	int i, j;
	for (i=0;i<n-1;i++)
		for (j=i+1;j<n;j++)
			if (_strcmpi(a[i].SoDT,a[j].SoDT)>0) 
				HoanVi(a[i],a[j]);
}