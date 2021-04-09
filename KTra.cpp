//456
//123
//mnmnm
//66666666
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>
#include <iostream>
using namespace std;
 
#define Pi 3.14

class Diem{
	private:
		int x,y;
	public:
		Diem();
		Diem(int h,int t);
		void Nhap();
		void Xuat();
		int getX();
		int getY();
		float KhoangCach(Diem);
};

class Eclipse{
	private:
		float r1,r2;
	protected:
		Diem o;
		float cv,dt;
	public:
		Eclipse();
		Eclipse(Diem t, float d,float r);
		void Nhap();
		void Xuat();
		void TinhCV();
		void TinhDT();
		float getR1();
		float getR2();
		Diem getTam();
		float getCV();
		float getDT();	
		int Ktra();	
};

class MangEclipse{
	private:
		Eclipse mhe[100];
		int n;
	public:
		void Nhap();
		void Xuat();
		void Tinh_CVMHE();
		void Tinh_DTMHE();
		float Tinh_TongDT();
		void LietKe();
};

int main()
{
	MangEclipse ME;
	cout<<"---NHAP THONG TIN HINH ECLIPSE---";
	ME.Nhap();
	cout<<"---THONG TIN HINH ECLIPSE---";
	ME.Xuat();
	ME.LietKe();
	float tongdt=ME.Tinh_TongDT();
	getch();
	return 1;
}

//class D
int Diem::getX()
{
	return x;
}
int Diem::getY()
{
	return y;
}
void Diem::Nhap()
{
	cout<<"\nNhap hoanh do x:";cin>>x;
	cout<<"\nNhap tung do y:";cin>>y;	
}
void Diem::Xuat()
{
	cout<<"\nHoanh do x:"<<x;
	cout<<"\nTung do y:"<<y<<endl;
}
float Diem::KhoangCach(Diem P)
{
	return sqrt((x-P.x)*(x-P.x))+((y-P.y)*(y-P.y));
}
Diem::Diem()
{
	x=y=0;
}
Diem::Diem(int h,int t)
{
	x=h;
	y=t;
}

//class E
float Eclipse::getR1()
{
	return r1;
}
float Eclipse::getR2()
{
	
	return r2;
}
float Eclipse::getCV()
{
	return cv;
}
float Eclipse::getDT()
{
	return dt;
}
Diem Eclipse::getTam()
{
	return o;
}
void Eclipse::Nhap()
{
	cout<<"Nhap tam o"; o.Nhap();
	cout<<"\nNhap ban kinh r1:";cin>>r1;
	cout<<"\nNhap ban kinh r2:";cin>>r2;
	TinhCV();
	TinhDT();
	cin.ignore();
}
void Eclipse::Xuat()
{
	cout<<"\nTam o:";o.Xuat();
	cout<<"\nBan kinh r1:"<<r1;
	cout<<"\nBan kinh r2:"<<r2;
	cout<<"\nChu vi:"<<cv;
	cout<<"\nDien tich:"<<dt;
}
void Eclipse::TinhDT()
{
	dt= Pi* r1 *r2;
}
void Eclipse::TinhCV()
{
	cv= (sqrt((r1*r1+r2*r2)/2));
}
Eclipse::Eclipse()
{
	Diem o(0,0);
	r1=r2=dt=cv=0;
}
Eclipse::Eclipse(Diem t,float d, float r)
{
	o=t;
	r1=d;
	r2=r;
}
int Eclipse::Ktra()
{
	if(o.getX()>0&&o.getY()>0)
	 return 1;
	return 0;
}
//class Mang E
void MangEclipse::Nhap()
{
	cout<<"\nNhap so luong hinh Eclipse:";cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		cout<<"Hinh Eclipse thu"<<i+1<<endl;
		mhe[i].Nhap();
		mhe[i].TinhCV();
		mhe[i].TinhDT();
	}
}
void MangEclipse::Xuat()
{
	for(int i=0;i<n;i++)
	{
		cout<<"\nThong tin hinh Eclipse thu"<<i+1<<endl;
		mhe[i].Xuat();
	}
}
float MangEclipse::Tinh_TongDT()
{
	float tongdt=0;
	for(int i=0;i<n;i++)
	{
		if(mhe[i].getCV()>9)
		tongdt=tongdt+mhe[i].getDT();
	}
	cout<<"\nTong dien tich cac hinh Eclipse co chu vi lon hon 9 :"<<tongdt<<endl;
}
void MangEclipse::LietKe()
{
	cout<<"\nDanh sach cac hinh Eclipse co hoanh do va tung do lon hon 0";
	for(int i=0;i<n;i++)
	{
		if(mhe[i].Ktra())
		mhe[i].Xuat();
	}
}
//dnghi test1
//minhngoc test
//minhngoctest1
