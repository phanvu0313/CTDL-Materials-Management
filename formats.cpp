#include"nguyenmau.cpp"
#include<bits/stdc++.h> 

//====================================================================
//=========================FORMATS===================================
//====================================================================
void draw()
{
	int x=0;
	int y=0;
	int z=198;
	for(int i=0;i<200;i++)
	{
		Normal();
		for(int j=0;j<50;j+=2)
		{
			gotoxy(x+i,y+j);
			cout<<" ";
			gotoxy(z-i,y+j+1);
			cout<<" ";
		}
		Sleep(1);
	}

}
void drawoff()
{
	int x=0;
	int y=0;
	int z=198;
	for(int i=0;i<200;i++)
	{
		SetColor(15);
		SetBGColor(0);
		for(int j=0;j<50;j+=2)
		{
			gotoxy(x+i,y+j);
			cout<<" ";
			gotoxy(z-i,y+j+1);
			cout<<" ";
		}
		Sleep(1);
	}

}
void loading( )
{
	gotoxy(93,24);
	cout<<"Loading ...";
	o_Nhap(65,21);
	
	Nocursortype();
	int x=66;int y=22;
	while(1)
	{
		
		Normal();
		gotoxy(x,y);
		cout<<" ";
		x++;
		if(x<70)
		{
			Sleep(10);
		}
		else if((x>70)&&(x<120))
		{
			Sleep(10);
		}
		else
		{
			Sleep(30);
		}
		if(x==132)
		{
			break;
		}
		
	}
	SetBGColor(0);
	int i;
	while(1)
	{
		if(kbhit())
		{
			break;
		}
		SetColor(i);
		gotoxy(85,26);
		cout<<"PRESS ANY KEY TO CONTINUE ...";
		i++;
		Sleep(200);
	}
	getch();
	draw();
	
} 
void getcurrentdate(date &temp)
{
	time_t now = time(0);
    tm *ltm = localtime(&now);
    temp.nam= 1900 + ltm->tm_year ;
    temp.thang =1 + ltm->tm_mon;
 	temp.ngay=ltm->tm_mday;
}
void doc_So(int n,int x,int y)
{
	int a;
	cout << endl;
	a = demsobo3(n);
	gotoxy(x,y);
	
	if (n == 0)
	{
		cout << "Khong ";
	}
	for (int i = 0; i < 10; i++)
	{
		if (a >= 0)
		{
			docsobo3(xoacham(n, a));
			if (xoacham(n, a) % 1000 == 0)
			{
				a--;
				continue;
			}
			if (xoacham(n, a) != 0)
			{
				doccham(a);
				a--;
			}

		}
		else
		{
			break;
		}
	}
}

int demso(int a)
{
	int x = 0;
		while (a != 0)
		{
			a = a / 10;
			x++;
		}
		return x;
}
void docmotdenmuoi(int a)
{
	if (a == 1)
	{
		cout << "Mot ";
	}
	else if (a == 2)
	{
		cout << "Hai ";
	}
	else if (a == 3)
	{
		cout << "Ba ";
	}
	else if (a == 4)
	{
		cout << "Bon ";
	}
	else if (a == 5)
	{
		cout << "Nam ";
	}
	else if (a == 6)
	{
		cout << "Sau ";
	}
	else if (a == 7)
	{
		cout << "Bay ";
	}
	else if (a == 8)
	{
		cout << "Tam ";
	}
	else if (a == 9)
	{
		cout << "Chin ";
	}
}
int demsobo3(int a)
{
	int x = 0;
	int y;
	y = demso(a);
	for (int i=0;i<=10;i++)
	{
		if (y/3 > 0)
		{
			x++;
			y -= 3;
		}
		else
		{
			break;
		}
	}
	return x;
}
void docsobo3(int a)
{
	int dv, c, t;
	t = (((a % 1000) - (a % 100)) / 100);
	c = (((a % 100) - (a % 10)) / 10);
	dv = (a % 10);

	if (t==0)
	{
		
		if (c != 0)
		{
			if ((a!=0) &&(a>999))
			{
				cout << "Khong Tram ";

				if (c == 1)
				{
					cout << "Muoi ";
					docmotdenmuoi(dv);
				}
				else
				{
					docmotdenmuoi(c);
					cout << "Muoi ";
					docmotdenmuoi(dv);
				}
			}
			else
			{
				if (c == 1)
				{
					cout << "Muoi ";
					docmotdenmuoi(dv);
				}
				else
				{
					docmotdenmuoi(c);
					cout << "Muoi ";
					docmotdenmuoi(dv);
				}
			}
		}
		else
		{
			if (((a != 0) && (a > 999))&& dv!=0)
			{
				cout << "Khong Tram Linh ";
				docmotdenmuoi(dv);
			}
			else
			{
				docmotdenmuoi(dv);
			}

			
		}
	}
	else 
	{
		if (c != 0)
		{
			docmotdenmuoi(t);
			cout << "Tram ";
				if (c == 1)
				{
					cout << "Muoi ";
					docmotdenmuoi(dv);
				}
				else
				{
					docmotdenmuoi(c);
					cout << "Muoi ";
					docmotdenmuoi(dv);
				}
			
		}
		else
		{

			if (dv == 0)
			{
				docmotdenmuoi(t);
				cout << "Tram ";
			}
			else
			{
				docmotdenmuoi(t);
				cout << "Tram linh ";
				docmotdenmuoi(dv);
			}

		}

	}
}
void doccham(int a)
{
	

		if (a == 0)
		{
			cout << "";
		}
		else if (a == 1)
		{
			cout << "Nghin ";
		}
		else if (a == 2)
		{
			cout << "Trieu ";
		}
		else if (a == 3)
		{
			cout << "Ty ";
		}
	
}
int xoacham (int a,int b)
{
	int x = 0;
	for (int j = 0; j < b; j++)
	{
		for (int i = 0; i < 3; i++)
		{

			x = x * 10;
			x = x + a % 10;
			a = a / 10;
		}
	}
	return a;
}


//====================================================================
//====================================================================
//====================================================================

string chuan_Hoa(string &a)
{
	//bien thanh chu thuong het
	transform(a.begin(), a.end(), a.begin(), ::toupper); 
	//xoa 32 dau
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	//xoa 32 cuoi
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1); 
	}
	//xoa 32 giua
	for (int i = 0; i < a.length(); i++)
	{
		
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i);
			i--;
		}
	}
	//moi sau dau 32
	for (int i = 0; i < a.length() - 1; i++)
	{
		if (a[i] == ' ' )
		{
		
			if (a[i + 1] >= 97 && a[i + 1] <= 122)
			{
				a[i + 1] -= 32; 
			}
		}
	}
	return a;
}
bool check_Num_In_Sring(string a)
{
	for (int i = 0; i < a.length() - 1; i++)
	{
		if (a[i] >47 && a[i]<58 )
		{
			return false;
		}
	}
	return true;
}
bool checkstring(string &a,int n)
{
	if(n<a.length())
	{
		for(int i=n;i<a.length();i++)
		{
			a[i]=' ';
		}
		while (a[a.length() - 1] == ' ')
		{
			a.erase(a.begin() + a.length() - 1); 
		}
	}
	int x=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]==' ') x++;
	}
	if(x==a.length())
	{
		return true;
	}
	if (a.empty()==true)
	{
		return true;
	}
	return false;

}
bool check_CMND(string cmnd,ds_Nhan_Vien b,int manv)
{
	if(cmnd=="")
	{
		Error("CMND KHONG DUNG");
		return false;
	}
	for(int i=0;i<cmnd.length();i++)
	{
		if((cmnd[i]<48)||(cmnd[i]>57))
		{
			
			Error("CMND KHONG DUNG");
			return false;
		}
	}
	for(int i=0;i<b.n;i++)
	{
		if(manv==-1)
		{
			if(b.ds[i]->so_CMND==cmnd)
			{
				Error("CMND DA TON TAI !");
				return false;
			}
		}
		else
		{
			if(b.ds[i]->so_CMND==cmnd)
			{
				if(b.ds[i]->ma_Nhan_Vien==manv)
				{
					return true;
				}
				else
				{
					Error("CMND DA TON TAI !");
					return false;
				}
				
			}
		}
		
	}
	return true;
}
int nhap_String(string &a,int x,int y)
{
	//nhap vat tu
	
	// ki tu duoc nhap nam trong khoang 48-57, 65-90,97-122
	int kbhit;
	//nhap mavt

	do
	{
		
		gotoxy(x,y);
		cout<<a;
		kbhit=getch();
		
  		if (kbhit==-32)
		{
		  kbhit = getch();	
		} 
  		else
  		{
  			char ch = kbhit;
			if((kbhit >47 && kbhit <58)||(kbhit>64 && kbhit<91)||(kbhit>96 &&kbhit<123)||kbhit==32)
			{
				if(a.length()<50)
				{
					gotoxy(x+a.length(),y);
					ch=toupper(ch);
					cout<<ch;
					a.push_back(ch);
				}
				
			}
			//neu an backspace thi xoa
			else if(kbhit==8)
			{
				if(a.length()!=0)
				{
					gotoxy(x+a.length()-1,y);
					cout<<" ";
					a.erase(a.end()-1 );
					
				}
			}
		}
		
		if( kbhit==72 ||kbhit==80||kbhit==27)
		{
			if(a.length()>0)
			{
				a.erase(a.end()-1 );
			}
			
			return kbhit;
		}
		
	}while(kbhit!=13);
	
	if(a.length()==0)
	{
		return -1;
	}
}
//nhap mvt
int nhap_MVT(string &a,int x,int y)
{
	//nhap vat tu
	
	// ki tu duoc nhap nam trong khoang 48-57, 65-90,97-122
	int kbhit;
	//nhap mavt

	do
	{
		
		gotoxy(x,y);
		cout<<a;
		kbhit=getch();
		
  		if (kbhit==-32)
		{
		  kbhit = getch();	
		} 
  		else
  		{
  			char ch = kbhit;
			if((kbhit >47 && kbhit <58)||(kbhit>64 && kbhit<91)||(kbhit>96 &&kbhit<123))
			{
				if(a.length()<50)
				{
					gotoxy(x+a.length(),y);
					ch=toupper(ch);
					cout<<ch;
					a.push_back(ch);
				}
				
			}
			//neu an backspace thi xoa
			else if(kbhit==8)
			{
				if(a.length()!=0)
				{
					gotoxy(x+a.length()-1,y);
					cout<<" ";
					a.erase(a.end()-1 );
					
				}
			}
		}
		
		if( kbhit==72 ||kbhit==80||kbhit==27)
		{
			if(a.length()>0)
			{
				a.erase(a.end()-1 );
			}
			
			return kbhit;
		}
		
	}while(kbhit!=13);
	
	if(a.length()==0)
	{
		return -1;
	}
}
// nhap so
int nhap_Float(float &temp,int x,int y)
{
	//nhap vat tu
	
	// ki tu duoc nhap nam trong khoang 48-57, 65-90,97-122
	string a;
	int kbhit;
	//nhap mavt

	do
	{
		temp = ::strtod(a.c_str(), 0);
		gotoxy(x,y);
		cout<<a;
		kbhit=getch();
		
  		if (kbhit==-32)
		{
		  kbhit = getch();	
		} 
  		else
  		{
  			char ch = kbhit;
			if((kbhit >47 && kbhit <65)||kbhit==46)
			{
				if(a.length()<50)
				{
					gotoxy(x+a.length(),y);
					cout<<ch;
					a.push_back(ch);
				}
				
			}
			//neu an backspace thi xoa
			else if(kbhit==8)
			{
				if(a.length()!=0)
				{
					gotoxy(x+a.length()-1,y);
					cout<<" ";
					a.erase(a.end()-1 );
					
				}
			}
		}
		
		if( kbhit==72 ||kbhit==80||kbhit==27)
		{
			if(a.length()!=0)
			{
				a.erase(a.end()-1 );
			}
			
			
			return kbhit;
		}
	
	}while(kbhit!=13);	
	if(a.length()==0)
	{
		return -1;
	}
	
}
int nhap_Int(int &temp,int x,int y)
{
	//nhap vat tu
	
	// ki tu duoc nhap nam trong khoang 48-57, 65-90,97-122
	string a;
	int kbhit;
	//nhap mavt

	do
	{
		temp = ::strtod(a.c_str(), 0);
		gotoxy(x,y);
		cout<<a;
		kbhit=getch();
		
  		if (kbhit==-32)
		{
		  kbhit = getch();	
		} 
  		else
  		{
  			char ch = kbhit;
			if((kbhit >47 && kbhit <65))
			{
				if(a.length()<50)
				{
					gotoxy(x+a.length(),y);
					cout<<ch;
					a.push_back(ch);
				}
				
			}
			//neu an backspace thi xoa
			else if(kbhit==8)
			{
				if(a.length()!=0)
				{
					gotoxy(x+a.length()-1,y);
					cout<<" ";
					a.erase(a.end()-1 );
					
				}
			}
		}
		
		if( kbhit==72 ||kbhit==80||kbhit==27)
		{
			if(a.length()!=0)
			{
				a.erase(a.end()-1 );
			}
			
			
			return kbhit;
		}
	
	}while(kbhit!=13);	
	if(a.length()==0)
	{
		return -1;
	}
	
}
int nhap_Phai(string &phai,int x,int y)//108,23
{
	Nocursortype();
	int kbhit;
	HighLight5();
	gotoxy(120,y);
	cout<<"Nam";
	Normal();
	gotoxy(140,y);
	cout<<"Nu";
	phai="Nam";
	Normal();
	do
	{
		kbhit=getch();
		if(kbhit==-32)
		{
			kbhit=getch();
		}
		if(kbhit==75)//left
		{
			HighLight5();
			gotoxy(120,y);
			cout<<"Nam";
			Normal();
			gotoxy(140,y);
			cout<<"Nu";
			phai="Nam";
		}
		else if(kbhit==77)//right
		{
			HighLight5();
			gotoxy(140,y);
			cout<<"Nu";
			Normal();
			gotoxy(120,y);
			cout<<"Nam";
			phai="Nu";
		}
		
		if( kbhit==72 ||kbhit==80||kbhit==13)
		{
			Showcursortype();
			return kbhit;
		}
	}while(true);
}
int nhap_Loai(string &loai,int x,int y)//108,23
{
	Nocursortype();
	int kbhit;
	HighLight5();
	gotoxy(120,y);
	cout<<"Xuat";
	Normal();
	gotoxy(140,y);
	cout<<"Nhap";
	loai="X";
	Normal();
	do
	{
		kbhit=getch();
		if(kbhit==-32)
		{
			kbhit=getch();
		}
		if(kbhit==75)//left
		{
			HighLight5();
			gotoxy(120,y);
			cout<<"Xuat";
			Normal();
			gotoxy(140,y);
			cout<<"Nhap";
			loai="X";
		}
		else if(kbhit==77)//right
		{
			HighLight5();
			gotoxy(140,y);
			cout<<"Nhap";
			Normal();
			gotoxy(120,y);
			cout<<"Xuat";
			loai="N";
		}
		
		if( kbhit==72 ||kbhit==80||kbhit==13)
		{
			Showcursortype();
			return kbhit;
		}
	}while(true);
}
bool check_Date(date a)
{
	if(a.thang > 12 || a.thang<0)
	{
		return false;
	}
	if(a.thang==1 || a.thang==3 || a.thang==5 || a.thang==7 || a.thang==8 || a.thang==10 || a.thang==12)
	{
		if(a.ngay>31||a.ngay<0)
		{
			return false;
		}
		
	}
	if(a.thang==6 || a.thang==4 || a.thang==9 || a.thang==11)
	{
		if(a.ngay>30||a.ngay<0)
		{
			return false;
		}
	}
	if((((a.nam%4)==0)&&(a.nam%100)!=0)||(a.nam%400)==0)
	{
		if(a.thang==2)
		{
			if(a.ngay>29||a.ngay<0)
				{
					return false;
				}
		}
	}
	else
	{
		if(a.thang==2)
		{
			if(a.ngay>28||a.ngay<0)
				{
					return false;
				}
		}
	}
	return true;
} 
// do hoa menuu
void clearscl() 
{
	int x=wherex() , y=wherey();
	gotoxy(0,0);
  	clreol();
  	gotoxy(x,y);
}
void Error (string a)
{
  Nocursortype();
  HighLight4(); 
  int x=wherex() , y=wherey();
  gotoxy (115,48);
  cout <<a;
  Sleep(1000);
  HighLight();
  gotoxy(115,48);
  clreol();
  gotoxy(x,y);
  Normal();
  Showcursortype();
}
void mau_Sac(string temp,int x,int y)
{
//	srand(time(NULL)); 
//	int mau = rand() % (15 - 0 + 1) + 0;
	int i=0;
	int j=0;
	while(true)
	{
		if(kbhit())
		{
			break;
		}
		SetColor(i);
		SetBGColor(1);
		gotoxy(x,y);
		cout<<temp;
		if(j==50)
		{
			j=0;
		}
		if(j<25)
		{
			i=0;
		}
		else if(j>25)
		{
			i=15;
		}
		j++;
		Sleep(5);
	}
	Normal();
}
void Normal () 
{
	SetColor(0);
	SetBGColor(15);
}
void Xanhla () 
{
	SetColor(2);
}
//mau xanh 
void HighLight () 
{
	SetColor(15);
	SetBGColor(3);
}
// mau trang
void HighLight2 () 
{
	SetColor(15);
	SetBGColor(3);
}
//chu mau do
void HighLight3 () 
{
	SetColor(4);
	//SetBGColor(6);
}
//chu mau  nen xanh
void HighLight4 () 
{
	SetColor(12);
	SetBGColor(15);
}
// nen normal chu mau xanh
void HighLight5 () 
{
	SetColor(3);
	SetBGColor(15);
}
// xanh dam
void HighLight6() 
{
	SetColor(15);
	SetBGColor(11);
}
void HighLight7() 
{
	SetColor(15);
	SetBGColor(4);
}
void HighLight8() 
{
	SetColor(4);
	SetBGColor(11);
}
void Vang_trang()
{
	SetColor(0);
	SetBGColor(14);
}
//ve khung va chu
void ve_Khung_login()
{

//218 goc trai; 191 goc phai
//179 doc ; 196 ngang
//192 goc trai duoi; 217 goc phai duoi
	gotoxy(68,15);
	cout<<char(218);
	for(int i=0;i<61;i++) cout<<char(196);
	cout<<char(191);
	gotoxy(68,16);
	cout<<char(179)<<"                                                             "<<char(179);
	gotoxy(68,17);
	cout<<char(179)<<"                           LOGIN                             "<<char(179);
	gotoxy(68,18);
	cout<<char(179)<<"                                                             "<<char(179);
	gotoxy(68,19);
	cout<<char(179)<<"         ============== CHON CHUC VU ==============          "<<char(179);
	gotoxy(68,20);
	cout<<char(179)<<"                                                             "<<char(179);
	gotoxy(68,21);
	cout<<char(179)<<"                                                             "<<char(179);
	gotoxy(68,22);
	cout<<char(179)<<"                                                             "<<char(179);
	gotoxy(68,23);
	cout<<char(179)<<"                                                             "<<char(179);
	gotoxy(68,24);
	cout<<char(179)<<"                                                             "<<char(179);
	gotoxy(68,25);  
	cout<<char(179)<<"                                                             "<<char(179);
	gotoxy(68,26);
	cout<<char(179)<<"                                                             "<<char(179);
	gotoxy(68,27);
	cout<<char(179)<<"                                                             "<<char(179);
	gotoxy(68,28);
	cout<<char(179)<<"                                                             "<<char(179);
	gotoxy(68,29);
	cout<<char(192);
	for(int i=0;i<61;i++)cout<<char(196);
	cout<<char(217);
	gotoxy(92,22);
	ve_QLVT();
	Normal();
} 
//o chon option trong xuat danh sach
void ve_o_Option(int x,int y)
{
	
	SetColor(14);
	SetBGColor(4);
	gotoxy(x,y);
	cout<<char(218);
	for(int i=0;i<40;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	for(int i=1;i<20;i++)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+41,y+i);
		cout<<char(179);
	}
	

	gotoxy(x,y+19);
	cout<<char(192);
	for(int i=0;i<40;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	Normal();
	for(int i=0;i<18;i++)
	{
		gotoxy(x+1,y+1+i);
		cout<<"                                        ";
	}
	Normal();
}

int o_Option(string text,int x,int y,int loai)
{
	// 1la nhan vien
	//0 la vat tu
	int loainb;
	if(loai==1)
	{
		loainb=4;
	}
	else
	{
		loainb=2;
	}
	Nocursortype();
	// ve o thoat
	ve_o_Option(x,y);
	gotoxy(x+9,y+2);
	cout<<text;
	int chon=menu_Quanly(option,loainb,6);
	Normal();
	return chon;
}
//
void o_Chon_Menu(int x,int y)
{
	o_Ten_Menu(13,3);
	HighLight();

	gotoxy(x,y);
	cout<<char(218);
	for(int i=0;i<39;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	for(int i=0;i<27;i++)
	{
		gotoxy(x-1,y+1+i);
		cout<<char(179);
		gotoxy(x,y+1+i);
		cout<<char(179);
		gotoxy(x+40,y+1+i);
		cout<<char(179);
		gotoxy(x+41,y+1+i);
		cout<<char(179);
	}
	

	gotoxy(x,y+28);
	cout<<char(192);
	for(int i=0;i<39;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	Normal();

}
void xoa_o_Menu()
{
	Normal();
	int x=4;
	int y=6;
	for(int i=0;i<23;i++)
	{
		gotoxy(x,y+i);
		cout<<"                                       "; 
	}
	
}
void o_Help(int x,int y)
{
	HighLight();

	gotoxy(x,y);
	cout<<char(218);
	for(int i=0;i<39;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	for(int i=0;i<16;i++)
	{
		gotoxy(x-1,y+1+i);
		cout<<char(179);
		gotoxy(x,y+1+i);
		cout<<char(179);
		gotoxy(x+40,y+1+i);
		cout<<char(179);
		gotoxy(x+41,y+1+i);
		cout<<char(179);
	}
	

	gotoxy(x,y+17);
	cout<<char(192);
	for(int i=0;i<39;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	SetColor(0);
	
	gotoxy(x+15,y+1);
	cout<<char(175)<<"[ NOTE ]"<<char(174);
	Normal();
}

void ve_Khung()
{
	o_Chon_Menu(3,1);
	gotoxy(0,0);
	HighLight2();
	cout<<"                                                                                                                                                                                                        ";
	
	gotoxy(2,0);
	cout<<"     PHAN VAN VU  N17DCCN190  D17CQCN03     ";
	gotoxy(45,5);
	for(int i=0;i<50;i++)
	{
		gotoxy(0,i);
		cout<<"  ";
		gotoxy(45,i);
		cout<<"  ";
		gotoxy(198,i);
		cout<<"  ";
	}
	gotoxy(45,47);
	cout<<"                                                                                                                                                           ";
	gotoxy(0,49);
	cout<<"                                                                                                                                                                                                        ";
	gotoxy(47,48);
	HighLight4();
	cout<<"THONG BAO  : ";
	Normal();
	// khung huowng dan
	HighLight2();
	gotoxy(2,30);
	cout<<char(198)<<"========================================="<<char(181);
	//cout<<"                                              ";
	Normal();
	o_Help(3,31);
}
void xoa_Man_Hinh()
{
	for(int i=1;i<47;i++)
	{
		gotoxy(47,i);
		cout<<"                                                                                                                                                       ";
	}
		
	
}
void ve_o_Thoat(int x,int y)
{
	
	SetColor(14);
	SetBGColor(4);
	gotoxy(x,y);
	cout<<char(218);
	for(int i=0;i<40;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	for(int i=1;i<10;i++)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+41,y+i);
		cout<<char(179);
	}
	

	gotoxy(x,y+9);
	cout<<char(192);
	for(int i=0;i<40;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	Normal();
	for(int i=0;i<8;i++)
	{
		gotoxy(x+1,y+1+i);
		cout<<"                                        ";
	}
	Normal();
}
bool o_Thoat(string text,int x,int y)
{
	Nocursortype();
	// ve o thoat
	ve_o_Thoat(x,y);
	int kbhit;
	bool check=false;
	gotoxy(x+9,y+2);
	cout<<text;
	gotoxy(x+10,y+6);
	HighLight5();
	cout<<"NO ";
	Normal();
	gotoxy(x+30,y+6);
	cout<<"YES";
	Normal();
	do
	{
		kbhit=getch();
		if(kbhit==-32)
		{
			kbhit=getch();
		}
		if(kbhit==75)//left
		{
			HighLight5();
			gotoxy(x+10,y+6);
			cout<<"NO ";
			Normal();
			gotoxy(x+30,y+6);
			cout<<"YES";
			check=false;
		}
		else if(kbhit==77)//right
		{
			Normal();
			gotoxy(x+10,y+6);
			cout<<"NO ";
			HighLight5();
			gotoxy(x+30,y+6);
			cout<<"YES";
			check=true;
			Normal();
		}
		
		if( kbhit==72 ||kbhit==80||kbhit==13)
		{
			Showcursortype();
			return check;
		}
	}while(true);
}
// xoa man hinh trong luc nhap hoa don
void xoa_Man_Hinh2()
{
	for(int i=5;i<46;i++)
	{
		gotoxy(47,i);
		cout<<"                                                                                                                                                       ";
	}
}
void xoa_Khung_HD()
{
	Normal();
	int y=33;
	for(int i=0;i<10;i++)
	{
		gotoxy(4,y+i);
		cout<<"                                       ";
	}
		
}
void ve_Khung_Xuat()
{
	int x=60;
	int y=7;
	gotoxy(x,y);
	cout<<char(218);
	for(int i=0;i<124;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	gotoxy(95,y);
	cout<<char(194);
	gotoxy(131,y);
	cout<<char(194);
	gotoxy(157,y);
	cout<<char(194);
	
	
	for(int i=1;i<32;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<124;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+125,y+i+1);
		cout<<char(180);
	}
	for(int i=1;i<34;i+=2)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+35,y+i);
		cout<<char(179);
		gotoxy(x+71,y+i);
		cout<<char(179);
		gotoxy(x+97,y+i);
		cout<<char(179);
		gotoxy(x+125,y+i);
		cout<<char(179);
	}
	gotoxy(x,y+34);
	cout<<char(192);
	for(int i=0;i<124;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	
	for(int i=2;i<33;i+=2)
	{
		gotoxy(95,y+i);
		cout<<char(197);
		gotoxy(131,y+i);
		cout<<char(197);
		gotoxy(157,y+i);
		cout<<char(197);
	}
	
	gotoxy(95,41);
	cout<<char(193);
	gotoxy(131,41);
	cout<<char(193);
	gotoxy(157,41);
	cout<<char(193);
	

}
void ve_Khung_Xuat_NV()
{
	int x=60;
	int y=7;
	gotoxy(x,y);
	cout<<char(218);
	for(int i=0;i<124;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	gotoxy(80,y);
	cout<<char(194);
	gotoxy(115,y);
	cout<<char(194);
	gotoxy(137,y);
	cout<<char(194);
	gotoxy(157,y);
	cout<<char(194);
	
	
	for(int i=1;i<32;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<124;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+125,y+i+1);
		cout<<char(180);
	}
	for(int i=1;i<34;i+=2)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+20,y+i);
		cout<<char(179);
		gotoxy(x+55,y+i);
		cout<<char(179);
		gotoxy(x+77,y+i);
		cout<<char(179);
		gotoxy(x+97,y+i);
		cout<<char(179);
		gotoxy(x+125,y+i);
		cout<<char(179);
	}
	gotoxy(x,y+34);
	cout<<char(192);
	for(int i=0;i<124;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	
	for(int i=2;i<33;i+=2)
	{
		gotoxy(80,y+i);
		cout<<char(197);
		gotoxy(115,y+i);
		cout<<char(197);
		gotoxy(137,y+i);
		cout<<char(197);
		gotoxy(157,y+i);
		cout<<char(197);
	}
	
	gotoxy(80,41);
	cout<<char(193);
	gotoxy(115,41);
	cout<<char(193);
	gotoxy(137,41);
	cout<<char(193);
	gotoxy(157,41);
	cout<<char(193);
	

}
//
void xoa_Trong_Khung_Xuat_NV()
{
	int y=7;
	for(int i=1;i<34;i+=2)
	{
		gotoxy(61,y+i);
		cout<<"                   ";
		gotoxy(81,y+i);
		cout<<"                                  ";
		gotoxy(116,y+i);
		cout<<"                     ";
		gotoxy(138,y+i);
		cout<<"                   ";
		gotoxy(158,y+i);
		cout<<"                           ";
	}
}
// 
void xoa_Trong_Khung_Xuat()
{
	int x=60;
	int y=7;
	for(int i=1;i<34;i+=2)
	{
		gotoxy(x+1,y+i);
		cout<<"                                  ";
		gotoxy(x+36,y+i);
		cout<<"                                   ";
		gotoxy(x+72,y+i);
		cout<<"                         ";
		gotoxy(x+98,y+i);
		cout<<"                           ";
	}
}//
void ve_Khung_Xuat_CTHD1()
{
	int x=122;
	int y=4;
	gotoxy(x,y);
	cout<<char(218);
	for(int i=0;i<73;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	gotoxy(x+13,y);
	cout<<char(194);
	gotoxy(x+33,y);
	cout<<char(194);
	gotoxy(x+37,y);
	cout<<char(194);
	gotoxy(x+56,y);
	cout<<char(194);
	
	
	for(int i=1;i<40;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<73;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+74,y+i+1);
		cout<<char(180);
	}
	for(int i=1;i<40;i+=2)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+13,y+i);
		cout<<char(179);
		gotoxy(x+33,y+i);
		cout<<char(179);
		gotoxy(x+37,y+i);
		cout<<char(179);
		gotoxy(x+56,y+i);
		cout<<char(179);
		gotoxy(x+74,y+i);
		cout<<char(179);
	}
	gotoxy(x,y+40);
	cout<<char(192);
	for(int i=0;i<73;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	
	for(int i=2;i<40;i+=2)
	{
		gotoxy(x+13,y+i);
		cout<<char(197);
		gotoxy(x+33,y+i);
		cout<<char(197);
		gotoxy(x+37,y+i);
		cout<<char(197);
		gotoxy(x+56,y+i);
		cout<<char(197);
	}
	
	gotoxy(x+13,y+40);
	cout<<char(193);
	gotoxy(x+33,y+40);
	cout<<char(193);
	gotoxy(x+37,y+40);
	cout<<char(193);
	gotoxy(x+56,y+40);
	cout<<char(193);
	

}
void xoa_Trong_Khung_Xuat_CTHD1()
{
	int x=123;
	int y=4;
	for(int i=1;i<40;i+=2)
	{
		gotoxy(x,y+i);
		cout<<"            ";
		gotoxy(x+13,y+i);
		cout<<"                   ";
		gotoxy(x+33,y+i);
		cout<<"   ";
		gotoxy(x+37,y+i);
		cout<<"            ";
		gotoxy(x+56,y+i);
		cout<<"                ";
	}
}
// khung xuat cthd trong tra hang
void ve_Khung_Xuat_CTHD_Trahang()
{
	int x=116;
	int y=4;
	gotoxy(x,y);
	cout<<char(218);
	for(int i=0;i<80;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	gotoxy(x+13,y);
	cout<<char(194);
	gotoxy(x+33,y);
	cout<<char(194);
	gotoxy(x+37,y);
	cout<<char(194);
	gotoxy(x+56,y);
	cout<<char(194);
	gotoxy(x+74,y);
	cout<<char(194);
	
	
	for(int i=1;i<40;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<80;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+81,y+i+1);
		cout<<char(180);
	}
	for(int i=1;i<40;i+=2)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+13,y+i);
		cout<<char(179);
		gotoxy(x+33,y+i);
		cout<<char(179);
		gotoxy(x+37,y+i);
		cout<<char(179);
		gotoxy(x+56,y+i);
		cout<<char(179);
		gotoxy(x+74,y+i);
		cout<<char(179);
		gotoxy(x+81,y+i);
		cout<<char(179);
	}
	gotoxy(x,y+40);
	cout<<char(192);
	for(int i=0;i<80;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	
	for(int i=2;i<40;i+=2)
	{
		gotoxy(x+13,y+i);
		cout<<char(197);
		gotoxy(x+33,y+i);
		cout<<char(197);
		gotoxy(x+37,y+i);
		cout<<char(197);
		gotoxy(x+56,y+i);
		cout<<char(197);
		gotoxy(x+74,y+i);
		cout<<char(197);
	}
	
	gotoxy(x+13,y+40);
	cout<<char(193);
	gotoxy(x+33,y+40);
	cout<<char(193);
	gotoxy(x+37,y+40);
	cout<<char(193);
	gotoxy(x+56,y+40);
	cout<<char(193);
	gotoxy(x+74,y+40);
	cout<<char(193);

}
//xoa trong khung xuat tra hang
void xoa_Trong_Khung_Xuat_CTHD_Trahang()
{
	int x=117;
	int y=4;
	for(int i=1;i<40;i+=2)
	{
		gotoxy(x,y+i);
		cout<<"            ";
		gotoxy(x+13,y+i);
		cout<<"                   ";
		gotoxy(x+33,y+i);
		cout<<"   ";
		gotoxy(x+37,y+i);
		cout<<"            ";
		gotoxy(x+56,y+i);
		cout<<"                ";
		gotoxy(x+74,y+i);
		cout<<"     ";
	}
}
// in hoa don
void ve_Khung_Xuat_CTHD()
{
	int x=89;
	int y=4;
	gotoxy(x,y);
	cout<<char(218);
	for(int i=0;i<100;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	gotoxy(x+13,y);
	cout<<char(194);
	gotoxy(x+33,y);
	cout<<char(194);
	gotoxy(x+37,y);
	cout<<char(194);
	gotoxy(x+56,y);
	cout<<char(194);
	gotoxy(x+74,y);
	cout<<char(194);
	gotoxy(x+91,y);
	cout<<char(194);
	
	for(int i=1;i<40;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<100;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+101,y+i+1);
		cout<<char(180);
	}
	for(int i=1;i<40;i+=2)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+13,y+i);
		cout<<char(179);
		gotoxy(x+33,y+i);
		cout<<char(179);
		gotoxy(x+37,y+i);
		cout<<char(179);
		gotoxy(x+56,y+i);
		cout<<char(179);
		gotoxy(x+74,y+i);
		cout<<char(179);
		gotoxy(x+91,y+i);
		cout<<char(179);
		gotoxy(x+101,y+i);
		cout<<char(179);
	}
	gotoxy(x,y+40);
	cout<<char(192);
	for(int i=0;i<100;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	
	for(int i=2;i<40;i+=2)
	{
		gotoxy(x+13,y+i);
		cout<<char(197);
		gotoxy(x+33,y+i);
		cout<<char(197);
		gotoxy(x+37,y+i);
		cout<<char(197);
		gotoxy(x+56,y+i);
		cout<<char(197);
		gotoxy(x+74,y+i);
		cout<<char(197);
		gotoxy(x+91,y+i);
		cout<<char(197);
	}
	
	gotoxy(x+13,y+40);
	cout<<char(193);
	gotoxy(x+33,y+40);
	cout<<char(193);
	gotoxy(x+37,y+40);
	cout<<char(193);
	gotoxy(x+56,y+40);
	cout<<char(193);
	gotoxy(x+74,y+40);
	cout<<char(193);
	gotoxy(x+91,y+40);
	cout<<char(193);

}
//cau i
void ve_Khung_Xuat_CTHD3()
{
	int x=50;
	int y=5;
	gotoxy(x,y);
	cout<<char(218);
	for(int i=0;i<139;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	gotoxy(x+21,y);
	cout<<char(194);
	gotoxy(x+34,y);
	cout<<char(194);
	gotoxy(x+39,y);
	cout<<char(194);	
	gotoxy(x+39+13,y);
	cout<<char(194);
	gotoxy(x+39+33,y);
	cout<<char(194);
	gotoxy(x+39+37,y);
	cout<<char(194);
	gotoxy(x+39+56,y);
	cout<<char(194);
	gotoxy(x+39+74,y);
	cout<<char(194);
	gotoxy(x+39+91,y);
	cout<<char(194);
	
	
	for(int i=1;i<40;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<139;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+39+101,y+i+1);
		cout<<char(180);
	}
	for(int i=1;i<40;i+=2)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+21,y+i);
		cout<<char(179);
		gotoxy(x+34,y+i);
		cout<<char(179);
		gotoxy(x+39,y+i);
		cout<<char(179);
		gotoxy(x+39+13,y+i);
		cout<<char(179);
		gotoxy(x+39+33,y+i);
		cout<<char(179);
		gotoxy(x+39+37,y+i);
		cout<<char(179);
		gotoxy(x+39+56,y+i);
		cout<<char(179);
		gotoxy(x+39+74,y+i);
		cout<<char(179);
		gotoxy(x+39+91,y+i);
		cout<<char(179);
		gotoxy(x+39+101,y+i);
		cout<<char(179);
	}
	gotoxy(x,y+40);
	cout<<char(192);
	for(int i=0;i<139;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	
	for(int i=2;i<40;i+=2)
	{
		gotoxy(x+21,y+i);
		cout<<char(197);
		gotoxy(x+34,y+i);
		cout<<char(197);
		gotoxy(x+39,y+i);
		cout<<char(197);
		gotoxy(x+39+13,y+i);
		cout<<char(197);
		gotoxy(x+39+33,y+i);
		cout<<char(197);
		gotoxy(x+39+37,y+i);
		cout<<char(197);
		gotoxy(x+39+56,y+i);
		cout<<char(197);
		gotoxy(x+39+74,y+i);
		cout<<char(197);
		gotoxy(x+39+91,y+i);
		cout<<char(197);
	}
	
	gotoxy(x+21,y+40);
	cout<<char(193);
	gotoxy(x+34,y+40);
	cout<<char(193);
	gotoxy(x+39,y+40);
	cout<<char(193);
	gotoxy(x+39+13,y+40);
	cout<<char(193);
	gotoxy(x+39+33,y+40);
	cout<<char(193);
	gotoxy(x+39+37,y+40);
	cout<<char(193);
	gotoxy(x+39+56,y+40);
	cout<<char(193);
	gotoxy(x+39+74,y+40);
	cout<<char(193);
	gotoxy(x+39+91,y+40);
	cout<<char(193);

}
void xoa_Khung_Xuat_CTHD_Month()
{
	int x=90;
	int y=4;
	for(int i=1;i<40;i+=2)
	{
		gotoxy(x,y+i);
		cout<<"            ";
		gotoxy(x+13,y+i);
		cout<<"                   ";
		gotoxy(x+33,y+i);
		cout<<"   ";
		gotoxy(x+37,y+i);
		cout<<"                  ";
		gotoxy(x+56,y+i);
		cout<<"                 ";
		gotoxy(x+74,y+i);
		cout<<"                ";
		gotoxy(x+91,y+i);
		cout<<"         ";
	}
		
}
void xoa_Khung_Xuat3()
{
	int x=51;
	int y=5;
	for(int i=1;i<40;i+=2)
	{
		gotoxy(x,y+i);
		cout<<"                    ";
		gotoxy(x+21,y+i);
		cout<<"            ";
		gotoxy(x+34,y+i);
		cout<<"    ";
		gotoxy(x+39,y+i);
		cout<<"            ";
		gotoxy(x+39+13,y+i);
		cout<<"                   ";
		gotoxy(x+39+33,y+i);
		cout<<"   ";
		gotoxy(x+39+37,y+i);
		cout<<"            ";
		gotoxy(x+39+56,y+i);
		cout<<"                 ";
		gotoxy(x+39+74,y+i);
		cout<<"                ";
		gotoxy(x+39+91,y+i);
		cout<<"         ";
	}
	
}
//
void ve_Khung_Xuat_Doanhthu()
{
	int x=80;
	int y=10;
	gotoxy(x,y);
	cout<<char(218);
	for(int i=0;i<70;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	gotoxy(x+21,y);
	cout<<char(194);
	
	
	
	
	for(int i=1;i<23;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<70;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+39+32,y+i+1);
		cout<<char(180);
	}
	int j=1;
	for(int i=1;i<24;i+=2)
	{
		
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+1,y+i);
		cout<<"THANG  "<<j;
		gotoxy(x+21,y+i);
		cout<<char(179) ;
		
		gotoxy(x+39+32,y+i);
		cout<<char(179);
		j++;
	}
	gotoxy(x,y+24);
	cout<<char(192);
	for(int i=0;i<70;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	
	for(int i=2;i<24;i+=2)
	{
		gotoxy(x+21,y+i);
		cout<<char(197);
		
		
	}
	
	gotoxy(x+21,y+24);
	cout<<char(193);
	
	
	

}
//
void o_Nhap(int x,int y)
{
	
	HighLight3();
	gotoxy(x,y);
	cout<<char(218);
	for(int i=0;i<66;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	
	gotoxy(x,y+1);
	cout<<char(179);
	gotoxy(x+67,y+1);
	cout<<char(179);

	gotoxy(x,y+2);
	cout<<char(192);
	for(int i=0;i<66;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	Normal();
}
void o_Ten_Menu(int x,int y)
{
	HighLight5();
	gotoxy(x,y-1);
	cout<<char(218);
	for(int i=0;i<20;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	gotoxy(x,y);
	SetColor(15);
	SetBGColor(0);
	cout<<"                      ";
	gotoxy(22,3);
	SetColor(15);
	SetBGColor(0);
	cout<<"MAIN";
	HighLight5();

	gotoxy(x,y+2-1);
	cout<<char(192);
	for(int i=0;i<20;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	Normal();
}
void o_Menu(int x,int y)
{
	
	HighLight3();
	gotoxy(x,y-1);
	cout<<char(218);
	for(int i=0;i<37;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	
	gotoxy(x,y);
	cout<<char(179);
	gotoxy(x+38,y);
	cout<<char(179);

	gotoxy(x,y+2-1);
	cout<<char(192);
	for(int i=0;i<37;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	Normal();
}
//

void ve_Khung_Nhap(int x,int y)
{
	
	Normal();
	
	gotoxy(x,y);
	cout<<char(218);
	for(int i=0;i<70;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	for(int i=0;i<30;i++)
	{
		
		gotoxy(x,y+i+1);
		cout<<char(179);
		HighLight(); 
		cout<<"                                                                      ";
		Normal();
		cout<<char(179);
	}
	gotoxy(x,y+31);
	cout<<char(192);
	for(int i=0;i<70;i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	HighLight();
	gotoxy(x+1,y+1);
	cout<<"ESC: THOAT";
	Normal();
	xoa_Khung_HD();
}
void xoa_Khung_Nhap(int n)
{
	Normal();
	Nocursortype();
	int x=65;
	int y=18;
	if(n==0)
	{
		HighLight();
		for(int i=0;i<10;i++)
		{
			
			gotoxy(x,y+i);
			cout<<"                                                     "; 
		}
		Normal();
	}
	for(int i=0;i<n;i++)
	{
		gotoxy(x,y+i);
		cout<<"                                                     "; 
	}
	Showcursortype();                                                                  
}

void xoa_Khung_Nhapblue()
{
	HighLight();
	Nocursortype();
	int x=50;
	int y=18;
	
	for(int i=0;i<20;i++)
	{
		gotoxy(x,y+i);
		cout<<"                                                                    "; 
	}
	Normal();
	Showcursortype();                                                                  
}
void ve_QLVT()
{
	SetColor(3);
	int x=0;int y=32;//x 45
	
	for(int i=0;i<50;i++)
	{
		if(kbhit())
		{
			for(int j=0;j<5;j++)
			{
				gotoxy(0,y+j);
				cout<<"                                                                                                                   ";
				
			}
			i=49;
		}
		Sleep(5);
		if(x==45)
		{
			break;
		}
		SetColor(i);
		gotoxy(x+i,y);
		cout<<" ,-----.   ,--. ,--.  ,---.  ,--.  ,--.    ,--.,--.   ,--.    ,--.   ,--.,---. ,--------.    ,--------.,--. ,--. ";
		gotoxy(x+i-1,y); cout<<" ";
		gotoxy(x+i,y+1);
		cout<<"'  .-.  '  |  | |  | /  O  \\ |  ,'.|  |    |  | \\  `.'  /      \\  `.'  //  O  \\'--.  .--'    '--.  .--'|  | |  | ";
		gotoxy(x+i-1,y+1); cout<<" ";
		gotoxy(x+i,y+2);
		cout<<"|  | |  |  |  | |  ||  .-.  ||  |' '  |    |  |  '.    /        \\     /|  .-.  |  |  |          |  |   |  | |  | ";
		gotoxy(x+i-1,y+2); cout<<" ";
		gotoxy(x+i,y+3);
		cout<<"'  '-'  '-.'  '-'  '|  | |  ||  | `   |    |  '--. |  |          \\   / |  | |  |  |  |          |  |   '  '-'  ' ";
		gotoxy(x+i-1,y+3); cout<<" ";
		gotoxy(x+i,y+4);
		cout<<" `-----'--' `-----' `--' `--'`--'  `--'    `-----' `--'           `-'  `--' `--'  `--'          `--'    `-----'  ";
		gotoxy(x+i-1,y+4); cout<<" ";
		
	}
	
	for(int i=0;i<83;i++)
	{
		if(kbhit())
		{
			Normal();
			gotoxy(15,40);
			cout<<"                                                                                                                                                                                 ";
			HighLight7();
			
			gotoxy(82,40);
			cout<<"          PHAN VAN VU           ";
			Normal();
			break;
		}
		int j=200;
		HighLight7();
		gotoxy(x+i,40);
		cout<<"          PHAN V";
		gotoxy(x+i-1,40);
		Normal();
		cout<<" ";
		HighLight7();
		gotoxy(j-i-20,40);
		cout<<"AN VU           ";
		gotoxy(i-j+1,40);
		Normal();
		cout<<" ";
		Sleep(1);
		
	}
	HighLight7();
	gotoxy(82,41);
	cout<<"          N17DCCN190            ";
	gotoxy(82,42);
	cout<<"          D17CQCN-03            ";
	gotoxy(82,43);
	cout<<" CAU TRUC GIU LIEU - GIAI THUAT ";
	Normal();
	
} 
//vat tu
void text_VT(int x,int y)
{
	Normal();
	SetColor(1);
	SetBGColor(1);
	
	gotoxy(x+31,y+2);
	cout<<"                                                         ";
	gotoxy(x+31,y+4);
	cout<<"                                                         ";
	for(int i=2;i<5;i++)
	{
		gotoxy(x+30,y+i);
		cout<<" ";
		gotoxy(x+88,y+i);
		cout<<" ";
	}
	
	Normal(); 
	SetColor(1);
	y+=10; 
	gotoxy(x,y++);
	cout<<"    ,o888888o.     8 8888      88        .8.          b.             8           8 8888  `8.`8888.      ,8' ";
	gotoxy(x,y++);
	cout<<" . 8888     `88.   8 8888      88       .888.         888o.          8           8 8888   `8.`8888.    ,8' ";
	gotoxy(x,y++);
	cout<<",8 8888       `8b  8 8888      88      :88888.        Y88888o.       8           8 8888    `8.`8888.  ,8' ";
	gotoxy(x,y++);
	cout<<"88 8888        `8b 8 8888      88     . `88888.       .`Y888888o.    8           8 8888     `8.`8888.,8' ";
	gotoxy(x,y++);
	cout<<"88 8888         88 8 8888      88    .8. `88888.      8o. `Y888888o. 8           8 8888      `8.`88888' ";
	gotoxy(x,y++);
	cout<<"88 8888     `8. 88 8 8888      88   .8`8. `88888.     8`Y8o. `Y88888o8           8 8888       `8. 8888 ";
	gotoxy(x,y++);
	cout<<"88 8888      `8,8P 8 8888      88  .8' `8. `88888.    8   `Y8o. `Y8888           8 8888        `8 8888";
	gotoxy(x,y++);
	cout<<"`8 8888       ;8P  ` 8888     ,8P .8'   `8. `88888.   8      `Y8o. `Y8           8 8888         8 8888 ";
	gotoxy(x,y++);
	cout<<" ` 8888     ,88'8.   8888   ,d8P .888888888. `88888.  8         `Y8o.`           8 8888         8 8888 ";
	gotoxy(x,y++);
	cout<<"    `8888888P'  `8.   `Y88888P' .8'       `8. `88888. 8            `Yo           8 888888888888 8 8888 ";
	
	x+=34;y+=3;
	gotoxy(x,y++);
	cout<<"`8.`888b           ,8' .8.    8888888 8888888888           8888888 8888888888 8 8888      88 ";
	gotoxy(x,y++);
	cout<<" `8.`888b         ,8' .888.         8 8888                       8 8888       8 8888      88";
	gotoxy(x,y++);
	cout<<"  `8.`888b       ,8' :88888.        8 8888                       8 8888       8 8888      88 ";
	gotoxy(x,y++);
	cout<<"   `8.`888b     ,8' . `88888.       8 8888                       8 8888       8 8888      88 ";
	gotoxy(x,y++);
	cout<<"    `8.`888b   ,8' .8. `88888.      8 8888                       8 8888       8 8888      88 ";
	gotoxy(x,y++);
	cout<<"     `8.`888b ,8' .8`8. `88888.     8 8888                       8 8888       8 8888      88";
	gotoxy(x,y++);
	cout<<"      `8.`888b8' .8' `8. `88888.    8 8888                       8 8888       8 8888      88";
	gotoxy(x,y++);
	cout<<"       `8.`888' .8'   `8. `88888.   8 8888                       8 8888       ` 8888     ,8P ";
	gotoxy(x,y++);
	cout<<"        `8.`8' .888888888. `88888.  8 8888                       8 8888         8888   ,d8P ";
	gotoxy(x,y++);
	cout<<"         `8.` .8'       `8. `88888. 8 8888                       8 8888          `Y88888P'";
	Normal();
}
// veit chu khi chon
void text_Choose(string text)
{
	gotoxy(91,12);
	cout<<"                                                       ";
	SetColor(4);
	chuan_Hoa(text);
	gotoxy(118-text.length()/2,12);
	cout<<text;
	Normal();
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void Showcursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}


// doc file vat tu doc phai N trai 
void read_VT(ds_Vat_Tu &a,ifstream &fin)
{
	fin.open("./File/vattu.txt", ios_base::in);
	if(fin.fail())
	{
		Error("DOC FILE LOI");
		return;
	}
	fin>>a.n;
	string temp;
	getline(fin,temp);
	for(int i=0;i<a.n;i++)
	{
		tree vt=khoi_Tao_Vat_Tu();
		getline(fin, vt->ma_Vat_Tu,',');
		getline(fin, vt->ten_Vat_Tu,',');
		getline(fin, vt->don_Vi_Tinh,',');
		fin>>vt->so_Luong_Ton;
		string temp;
		getline(fin,temp,',');
		fin>>vt->used;
		
		getline(fin,temp);
		them_node_Vat_Tu(a.ds,vt);
	}
	
	fin.close();
}
void write_VT(ds_Vat_Tu a,ofstream &fout)
{
	fout.open("./File/vattu.txt", ios_base::out);
	if(fout.fail())
	{
		Error("GHI FILE LOI");
		return;
	}
	fout<<a.n;
	fout<<"\n";
	write_Tree( a.ds,fout);
	fout.close();
}
void write_Tree(tree vt,ofstream &fout)
{
	if(vt==NULL)
	{
		return;
	}
	else
	{
		write_Tree(vt->pRight, fout);
		fout<<vt->ma_Vat_Tu;fout<<',';
		fout<<vt->ten_Vat_Tu;fout<<',';
		fout<<vt->don_Vi_Tinh;fout<<',';
		fout<<vt->so_Luong_Ton;fout<<',';
		fout<<vt->used;fout<<"\n";
		write_Tree(vt->pLeft,fout);
	}
}

// doc file nhan vien
void read_NV(ds_Nhan_Vien &b,ifstream &fin)
{
	fin.open("./File/nhanvien.txt", ios_base::in);
	if(fin.fail())
	{
		Error("DOC FILE LOI");
		return;
	}
	fin>>b.n;
	string temp;
	getline(fin,temp);
	for(int i=0;i<b.n;i++)
	{
		nhan_Vien *nv=new nhan_Vien;
		fin>>nv->ma_Nhan_Vien;
		string temp;
		getline(fin,temp,',');
		getline(fin,nv->ho,',');
		getline(fin,nv->ten,',');
		getline(fin,nv->phai,',');
		getline(fin,nv->so_CMND);
		
		// nhap hoa don
		fin>>nv->ds_HD.n;
		string temp2;
		getline(fin,temp2);
		
		if(nv->ds_HD.n >0)
		{
			
			for(int j=0;j<nv->ds_HD.n;j++)
			{
				node_Hoa_Don* p =khoi_Tao_Node_HD();
				getline(fin,p->HD.soHD,',');
				fin>>p->HD.ngay_Lap.ngay;
				string tempngay;
				getline(fin,tempngay,'/');
				fin>>p->HD.ngay_Lap.thang;
				string tempthang;
				getline(fin,tempthang,'/');
				fin>>p->HD.ngay_Lap.nam;
				string tempnam;
				getline(fin,tempnam,',');
				getline(fin,p->HD.loai);
				
				// doc chi tiet hoa don
				fin>>p->HD.dsCTHD.n;
				string tempcthd;
				getline(fin,tempcthd);
				if(p->HD.dsCTHD.n>0)
				{
					for(int k=0;k<p->HD.dsCTHD.n;k++)
					{
						getline(fin,p->HD.dsCTHD.ds[k].ma_Vat_Tu,',');
						fin>>p->HD.dsCTHD.ds[k].so_Luong;
						string tempsl;
						getline(fin,tempsl,',');
						fin>>p->HD.dsCTHD.ds[k].don_Gia;
						string tempdg;
						getline(fin,tempdg,',');
						fin>>p->HD.dsCTHD.ds[k].VAT;
						string tempvat;
						getline(fin,tempvat,',');
						int temptt;
						fin>>temptt;
						
						if(temptt==1)
						{
							p->HD.dsCTHD.ds[k].trang_Thai=true;
						}
						else
						{
							p->HD.dsCTHD.ds[k].trang_Thai=false;
						}
						string temptt2;
						getline(fin,temptt2,',');
						fin>>p->HD.dsCTHD.ds[k].so_Luong_Tra;
						getline(fin,temptt2);
						// tri gia bang so luong mua -so luong tra nhan cho
						long double chuathue=(p->HD.dsCTHD.ds[k].so_Luong-p->HD.dsCTHD.ds[k].so_Luong_Tra)*p->HD.dsCTHD.ds[k].don_Gia;
						p->HD.dsCTHD.ds[k].tri_Gia=chuathue+((chuathue*p->HD.dsCTHD.ds[k].VAT)/100);
					}
				}
				else if(p->HD.dsCTHD.n==0)
				{
					
					
				}
			them_Hoa_Don(nv->ds_HD.pHead, p);
			}
		}
		else if (nv->ds_HD.n == 0)
		{
			
			
		}
		
		b.ds[i]=nv;
	}
	fin.close();
}
//xuat file nhan vien
void write_NV(ds_Nhan_Vien b,ofstream &fout)
{
	//ghinv.txt
	fout.open("./File/nhanvien.txt", ios_base::out);
	if(fout.fail())
	{
		Error("GHI FILE LOI");
		return;
	}
	fout<<b.n;
	fout<<"\n";
	for(int i=0;i<b.n;i++)
	{
		fout<<b.ds[i]->ma_Nhan_Vien;fout<<',';
		fout<<b.ds[i]->ho;fout<<',';
		fout<<b.ds[i]->ten;fout<<',';
		fout<<b.ds[i]->phai;fout<<',';
		fout<<b.ds[i]->so_CMND;fout<<"\n";
		if(b.ds[i]->ds_HD.n==0)
		{
			fout<<0;fout<<"\n";
			continue;
		}
		else
		{
			fout<<b.ds[i]->ds_HD.n;fout<<"\n";
			if(b.ds[i]->ds_HD.pHead!=NULL)
			{
				for (node_Hoa_Don *k = b.ds[i]->ds_HD.pHead;k != NULL;k = k->pNext)
				{
					fout<<k->HD.soHD;fout<<',';
					fout<<k->HD.ngay_Lap.ngay;fout<<'/';
					fout<<k->HD.ngay_Lap.thang;fout<<'/';
					fout<<k->HD.ngay_Lap.nam;fout<<',';
					fout<<k->HD.loai;fout<<"\n";
					fout<<k->HD.dsCTHD.n;fout<<"\n";
					for(int l=0;l<k->HD.dsCTHD.n;l++)
					{
						fout<<k->HD.dsCTHD.ds[l].ma_Vat_Tu;fout<<',';
						fout<<k->HD.dsCTHD.ds[l].so_Luong;fout<<',';
						fout<<k->HD.dsCTHD.ds[l].don_Gia;fout<<',';
						fout<<k->HD.dsCTHD.ds[l].VAT;fout<<',';
						if(k->HD.dsCTHD.ds[l].trang_Thai==true)
						{
							fout<<1;
						}
						else
						{
							fout<<0;
						}
						fout<<',';
						fout<<k->HD.dsCTHD.ds[l].so_Luong_Tra;
						fout<<"\n";
					}
				}
			}
		}
		
	}
	
	
	fout.close();
	
}
 



























