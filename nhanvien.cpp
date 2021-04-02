#include "vattu.cpp"


//====================================================================
//========================NHAN VIEN===================================
//====================================================================
bool nhap_Nhan_Vien(ds_Nhan_Vien dsnv,nhan_Vien *nv)
{
	//note
	Vang_trang();
	gotoxy(11,36);
	cout<<"ESC       : THOAT       ";
	gotoxy(11,37);
	cout<<"LEN,XUONG : DIEU CHINH  ";
	Normal();
	
	HighLight2();
	gotoxy(108,2);
	cout<<"                                         ";
	gotoxy(108,3);
	cout<<"             THEM NHAN VIEN              ";
	gotoxy(108,4);
	cout<<"                                         ";
	Normal();
	
	o_Nhap(92,14);
	gotoxy(93,15);
	cout<< "MA NHAN VIEN  |                                                   ";
	
	o_Nhap(92,18);
	gotoxy(93,19);
	cout<< "HO            |                                                   ";
	
	o_Nhap(92,22);
	gotoxy(93,23);
	cout<< "TEN           |                                                   ";
	
	o_Nhap(92,26);
	gotoxy(93,27);
	cout<< "PHAI          |            Nam                 Nu                 ";
	Normal();
	o_Nhap(92,30);
	gotoxy(93,31);
	cout<< "CMND          |                                                   ";
	Normal();
	int tempmnv;
	string tempho;
	string tempten;
	string tempphai;
	string tempcm;
	int kbhit;
nhapmnv:
	kbhit=nhap_Int(tempmnv,108,15);
	if(kbhit==27)
	{
		return false;
	}
	if(kbhit==72)
	{
		gotoxy(108,15);
		cout<<"0";
		goto nhapmnv;
	}
	if(kbhit==80)
	{
		if(tempmnv==0)
		{
			gotoxy(108,15);
			cout<<"0";
		}
		
		goto nhapho;
	}
nhapho:
	kbhit=nhap_String(tempho,108,19);
	if(kbhit==27)
	{
		return false;
	}
	if(kbhit==72)
	{
		gotoxy(108,15);
		cout<<"                                                   ";
		gotoxy(108,19);
		cout<<"                                                   ";
		gotoxy(108,19);
		cout<<tempho;
		goto nhapmnv;
	}
	if(kbhit==80)
	{
		gotoxy(108,19);
		cout<<"                                                   ";
		gotoxy(108,19);
		cout<<tempho;
		goto nhapten;
	}
nhapten:
	kbhit=nhap_String(tempten,108,23);
	if(kbhit==27)
	{
		return false;
	}
	if(kbhit==72)
	{
		gotoxy(108,23);
		cout<<"                                                   ";
		gotoxy(108,23);
		cout<<"                                                   ";
		gotoxy(108,23);
		cout<<tempten;
		goto nhapho;
	}
	if(kbhit==80)
	{
		gotoxy(108,23);
		cout<<"                                                   ";
		gotoxy(108,23);
		cout<<tempten;
		goto nhapphai;
	}

nhapphai:
	kbhit=nhap_Phai(tempphai,108 ,27);
	if(kbhit==72)
	{
		goto nhapten;
	}
	if(kbhit==80||kbhit==enter)
	{
		goto nhapcm;
	}
nhapcm:
	kbhit=nhap_String(tempcm,108,31);
	if(kbhit==27)
	{
		return false;
	}
	if(kbhit==72)
	{
		gotoxy(108,31);
		cout<<"                                                   ";
		gotoxy(108,31);
		cout<<tempcm;
		goto nhapphai;
	}
	if(kbhit==80)
	{
		gotoxy(108,31);
		cout<<"                                                   ";
		gotoxy(108,31);
		cout<<tempcm;
		goto nhapcm;
	}
	if(check_Nhan_Vien(dsnv,tempmnv)!=-1)
	{
		Error("MA NHAN VIEN DA TON TAI ");
		goto nhapmnv;
	}
	if(checkstring(tempho,tempho.length())==true)
	{
		Error("HO KHONG DUNG !");
		goto nhapho;
	}
	if(check_Num_In_Sring(tempho)==false)
	{
		Error("HO KHONG DUOC CHUA SO");
		goto nhapho;
	}
	if(checkstring(tempten,tempten.length())==true)
	{
		Error("TEN KHONG DUNG !");
		goto nhapten;
	}
	if(check_Num_In_Sring(tempten)==false)
	{
		Error("TEN KHONG DUOC CHUA SO");
		goto nhapten;
	}
	if(check_CMND(tempcm,dsnv,-1)==false)
	{
		
		goto nhapcm;
	}
	nv->ma_Nhan_Vien=tempmnv;
	nv->ho=tempho;
	nv->phai=tempphai;
	nv->ten=tempten;
	nv->so_CMND=tempcm;
	chuan_Hoa(nv->phai);
	chuan_Hoa(nv->ho);
	chuan_Hoa(nv->ten);
	Nocursortype();
	gotoxy(100,35);
	cout<<"ESC : THOAT";
	gotoxy(135,35);
	cout<<"ENTER: LUU ";
	do
	{
		int kbhit=getch();
		Showcursortype();
		if(kbhit==27)
		{
			return false;
		}
		if(kbhit==enter)
		{
			return true;
		}
		if(kbhit==72)
		{
			goto nhapcm;
		}
	}while(true);
	
	return true;
}
void them_Nhan_Vien(ds_Nhan_Vien &dsnv)
{
	nhan_Vien *nv=new nhan_Vien;
	int check=nhap_Nhan_Vien(dsnv,nv);
	
	if(check==true&&dsnv.n<500)
	{
		add_NV_Ten(dsnv, nv);
		Error("THEM NHAN VIEN THANH CONG  !");
	}
	else
	{
		delete nv;
	}
	
}
void add_NV_Ten(ds_Nhan_Vien &dsnv,nhan_Vien *nv)
{
	if(dsnv.n==0)
	{
		dsnv.ds[dsnv.n]=nv;
		dsnv.n++;
	}
	else
	{
		for(int i=0;i<dsnv.n;i++)
		{
			//neu gap phan tu lon hon no thi se them vao truoc phan tu do
			if(compare_Ten(dsnv.ds[i],nv)==1)
			{
				for(int j=dsnv.n;j>i;j--)
				{
					dsnv.ds[j]=dsnv.ds[j-1];
					
				}
				dsnv.ds[i]=nv;
				dsnv.n++;
				break;
			}
			//neu chay het tat ca ma khong co cai nao lon hon thi cho no vao cuoi danh sach
			if(i==dsnv.n-1)
			{
				dsnv.ds[dsnv.n]=nv;
				dsnv.n++;
				break;
			}
		}
	}
	
}
// so sanh ten nhan vien a va b neu a <  b int =0 (them sau); neu a>b int =1 (them truoc) ; neu a==b thi so sanh ho
int compare_Ten(nhan_Vien *a,nhan_Vien *b)
{
	//neu ten khong bang nhau thi so sanh ten
	if(a->ten.compare(b->ten)==1)
	{
		return 1;
	}
	else if(a->ten.compare(b->ten)==-1)
	{
		return 0;
	}
	else
	{
		if(a->ho.compare(b->ho)==1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
//------------------------------------------------xuat nhan vien 
void show_A_Page_NV(ds_Nhan_Vien dsnv,int currentpage)
{
	xoa_Trong_Khung_Xuat_NV();
	int maxpage=1;
	if(dsnv.n<=17)
	{
		maxpage=1;
	}
	else if(dsnv.n>17)
	{
		if(dsnv.n%17==0)
		{
			maxpage=dsnv.n/17;
		}
		else if(dsnv.n%17!=0)
		{
			maxpage=(dsnv.n/17 +1);
		}
	}
	int firstNV=0;
	int lastNV;
	firstNV=(currentpage-1)*17;
	//tinh lastVT
	if(currentpage<maxpage)
	{
		lastNV=firstNV+17;
	}
	// bang nhau co 2 truowng hop 1: bang nhau co du 2: bang  nhau khong du
	else if(currentpage==maxpage)
	{
		//1: khong du
		if(dsnv.n%17 ==0)
		{
			lastNV=firstNV+17;
		}
		//2:co du
		else if(dsnv.n%17 !=0)
		{
			lastNV=firstNV+(dsnv.n%17);
		}
		
	}
	index=0;
	for(int i=firstNV;i<lastNV;i++)
	{
		gotoxy(62,8+index);
		cout<<dsnv.ds[i]->ma_Nhan_Vien;
		gotoxy(81,8+index);
		cout<<dsnv.ds[i]->ho;
		gotoxy(116,8+index);
		cout<<dsnv.ds[i]->ten;
		gotoxy(138,8+index);
		cout<<dsnv.ds[i]->phai;
		gotoxy(159,8+index);
		cout<<dsnv.ds[i]->so_CMND<<endl;
		index+=2;
	}
	index=0;
	HighLight();
	gotoxy(49,42);
	cout<<"Pg Dn       : Next";
	gotoxy(49,43);
	cout<<"Pg Up       : Prev";
	Normal();
	gotoxy(49,44);
	cout<<"Page        : "<<currentpage<<"/"<<maxpage;
	gotoxy(49,45);
	cout<<"Tong NV : "<<dsnv.n<<"  (17nv / Page)";
} 
int show_Page_NV(ds_Nhan_Vien dsnv)
{
	int currentpage=1;
	int maxpage=1;
	if(dsnv.n<=17)
	{
		maxpage=1;
	}
	else if(dsnv.n>17)
	{
		if(dsnv.n%17==0)
		{
			maxpage=dsnv.n/17;
		}
		else if(dsnv.n%17!=0)
		{
			maxpage=(dsnv.n/17 +1);
		}
	}	
	show_A_Page_NV(dsnv, currentpage);
	int sukien;
	while(true)
	{
		sukien=getch();
		if(sukien==Esc)
		{
			break;
		}
		if(sukien==enter)
		{
			// coo the chon so nhan vien de lap hoa don
			int sonv=0;
			if(currentpage<maxpage)
			{
				sonv=17;
			}
			else if(currentpage==maxpage)
			{
				sonv=dsnv.n%17;
			}
			int chonnv=menu_Quanly(chon_Vat_Tu,sonv,2);
			if(chonnv==-1)
			{
				gotoxy(wherex()-1,wherey());
				cout<<" ";
				Normal();
			}
			else
			{
				return chonnv+((currentpage-1)*17);
			}
			
		} 
		if(sukien==PD)
		{
			if(currentpage<maxpage)
			{
				currentpage++;
				show_A_Page_NV(dsnv, currentpage);
			}
			
		}
		else if(sukien==PU)
		{
			if(currentpage>1)
			{
				currentpage--;
				show_A_Page_NV(dsnv, currentpage);
			}
		}
	}
	return -1;
}
void xuat_Nhan_Vien(ds_Nhan_Vien &dsnv,ds_Vat_Tu &a)
{
	//thong bao tren o note
	Vang_trang();
	gotoxy(7,36);
	cout<<"ESC       : THOAT              ";
	gotoxy(7,37);
	cout<<"PG UP     : TRANG TRUOC        ";
	gotoxy(7,38);
	cout<<"PG DN     : TRANG SAU          ";
	gotoxy(7,39);
	cout<<"ENTER     : CHON NV LAP HOA DON";
	Normal();
	xoa_Man_Hinh2();
	HighLight2();
	gotoxy(108,2);
	cout<<"                                         ";
	gotoxy(108,3);
	cout<<"          DANH SACH NHAN VIEN            ";
	gotoxy(108,4);
	cout<<"                                         ";
	Normal();
	
	
	
	
	
optionfail:
	xoa_Man_Hinh2();
	
	HighLight2();
	gotoxy(60,6);
	cout<<"| Ma Nhan Vien              Ho                            Ten                   Phai              CMND                       |"; 
	Normal();
	
xuatnv:
	Nocursortype();
	ve_Khung_Xuat_NV();
	if(dsnv.n==0)
	{
		Error("KHONG CO NHAN VIEN NAO");
		getch();
		return;
	}
	Normal();

	int chonnv=show_Page_NV(dsnv);
	if(chonnv!=-1)
	{
		// hoi co muon lap hoa don voi nhan vien nay hay khong
		gotoxy(wherex()-1,wherey());
		cout<<" ";
		Normal();
		int checklaphd=o_Option("TUY CHON CHO NHAN VIEN NAY",79,15,1);// sua o nay lai
		if(checklaphd==3)
		{
			//lap hoa don bang ma va ten nhan vien da chon
			Showcursortype();
			chonnv-=1;
			lap_Hoa_Don_in_DS(dsnv,a, chonnv);
		}
		else if(checklaphd==1)// sua nhan vien
		{
			chonnv-=1;
			sua_Nhan_Vien_in_DS( dsnv, chonnv);
		}
		else if(checklaphd==2)// xoa nhan vien
		{
			
			chonnv-=1;
			if(dsnv.ds[chonnv]->ds_HD.n!=0)
			{
				Error("NHAN VIEN NAY KHONG THE XOA VI DA LAP HOA DON !");
				goto optionfail;
			}
			else
			{
				xoa_Nhan_Vien_in_DS(dsnv, chonnv);
			}
			
		}
		else if(checklaphd==4)// xem hoa don cua nhan vien do
		{
			chonnv-=1;
			// ham xem hoa don trong mot khang thoi gian nhung cho thoi gian chay tu dau
			in_HD_DTD_in_DS(dsnv,a,dsnv.ds[chonnv]->ma_Nhan_Vien);
		}
	}
} 
//------------------------------------------------xoa nhan vien
int check_Nhan_Vien(ds_Nhan_Vien dsnv, int manv) 
{
  for (int i =0; i < dsnv.n ; i++)
  {
  	if (dsnv.ds[i]->ma_Nhan_Vien == manv) 
	  {
	  	return i;
	  }
  } 
  return -1;
}
void xoa_Nhan_Vien(ds_Nhan_Vien &dsnv)
{
	//note
	Vang_trang();
	gotoxy(11,36);
	cout<<"ESC       : THOAT       ";
	gotoxy(11,37);
	cout<<"LEN,XUONG : DIEU CHINH  ";
	Normal();
	
	
	HighLight2();
	gotoxy(108,2);
	cout<<"                                         ";
	gotoxy(108,3);
	cout<<"             XOA NHAN VIEN               ";
	gotoxy(108,4);
	cout<<"                                         ";
	Normal();
	o_Nhap(92,14);
	gotoxy(93,15);
	cout<< "MA NHAN VIEN  |                                                   ";
	
    int tempmnv;
nhapmnv:
	int kbhit=nhap_Int(tempmnv,108,15);
	if(kbhit==27)
	{
		return;
	}
	int i = check_Nhan_Vien(dsnv,tempmnv) ;
	// neu da co danh sach hoa don thi khong the xoa
	if(dsnv.ds[i]->ds_HD.n!=0)
	{
		Error("NHAN VIEN NAY KHONG THE XOA VI DA LAP HOA DON !");
		return;
	}
	if(i==-1)
	{
		Error("MA KHONG TON TAI");
		gotoxy(108,15);
		cout<<"                                                   ";
		gotoxy(108,15);
		cout<<" ";
		goto nhapmnv;
	}
	if (i!=-1)
	{
		o_Nhap(92,18);
		gotoxy(93,19);
		cout<< "HO            |                                                   ";
		
		o_Nhap(92,22);
		gotoxy(93,23);
		cout<< "TEN           |                                                   ";
		
		o_Nhap(92,26);
		gotoxy(93,27);
		cout<< "PHAI          |            Nam                 Nu                 ";
		Normal();
		o_Nhap(92,30);
		gotoxy(93,31);
		cout<< "CMND          |                                                   ";
		HighLight3();
		gotoxy(108,19);
		cout<<dsnv.ds[i]->ho;
		gotoxy(108,23);
		cout<<dsnv.ds[i]->ten;
		if(dsnv.ds[i]->phai=="Nam")
		{
			HighLight3();
			gotoxy(120,27);
			cout<<"Nam";
			Normal();
			gotoxy(140,27);
			cout<<"Nu";
		
		}
		else 
		{
			HighLight3();
			gotoxy(140,27);
			cout<<"Nu";
			Normal();
			gotoxy(120,27);
			cout<<"Nam";
			
		}
		HighLight3();
		gotoxy(108,31);
		cout<<dsnv.ds[i]->so_CMND;
		Normal();
		do
		{
			Nocursortype();
			gotoxy(100,35);
			cout<<"ESC : THOAT ";
			gotoxy(135,35);
			cout<<"ENTER: XOA  ";
			int kbhit=getch();
			Showcursortype();
			if(kbhit==27)
			{
				return ;
			}
			if(kbhit==enter)
			{
				delete  dsnv.ds[i];
			    for (int j=i+1; j <dsnv.n; j++)
				{
			    	dsnv.ds[j-1]=dsnv.ds[j];
				}
		    	dsnv.n--; 
				Error("XOA NHAN VIEN THANH CONG !") ;	
		    	return;
			}
			if(kbhit==72)
			{
				goto nhapmnv;
			}
		}while(true);
	}
}
// xoa trong in danh sacch
void xoa_Nhan_Vien_in_DS(ds_Nhan_Vien &dsnv,int chonnv)
{
	
	xoa_Man_Hinh();
	ve_Khung_Nhap(90,8);
	//note
	Vang_trang();
	gotoxy(11,36);
	cout<<"ESC       : THOAT       ";
	gotoxy(11,37);
	cout<<"LEN,XUONG : DIEU CHINH  ";
	Normal();
	
	
	HighLight2();
	gotoxy(108,2);
	cout<<"                                         ";
	gotoxy(108,3);
	cout<<"             XOA NHAN VIEN               ";
	gotoxy(108,4);
	cout<<"                                         ";
	Normal();
	o_Nhap(92,14);
	gotoxy(93,15);
	cout<< "MA NHAN VIEN  |                                                   ";
	
    int tempmnv=dsnv.ds[chonnv]->ma_Nhan_Vien;
    gotoxy(108,15);
    cout<<tempmnv;
	int i = check_Nhan_Vien(dsnv,tempmnv) ;
	if (i!=-1)
	{
		o_Nhap(92,18);
		gotoxy(93,19);
		cout<< "HO            |                                                   ";
		
		o_Nhap(92,22);
		gotoxy(93,23);
		cout<< "TEN           |                                                   ";
		
		o_Nhap(92,26);
		gotoxy(93,27);
		cout<< "PHAI          |            Nam                 Nu                 ";
		Normal();
		o_Nhap(92,30);
		gotoxy(93,31);
		cout<< "CMND          |                                                   ";
		HighLight3();
		gotoxy(108,19);
		cout<<dsnv.ds[i]->ho;
		gotoxy(108,23);
		cout<<dsnv.ds[i]->ten;
		if(dsnv.ds[i]->phai=="NAM")
		{
			
			HighLight3();
			gotoxy(120,27);
			cout<<"Nam";
			Normal();
			gotoxy(140,27);
			cout<<"Nu";
		
		}
		else 
		{
			HighLight3();
			gotoxy(140,27);
			cout<<"Nu";
			Normal();
			gotoxy(120,27);
			cout<<"Nam";
			
		}
		HighLight3();
		gotoxy(108,31);
		cout<<dsnv.ds[i]->so_CMND;
		Normal();
		do
		{
			Nocursortype();
			gotoxy(100,35);
			cout<<"ESC : THOAT ";
			gotoxy(135,35);
			cout<<"ENTER: XOA  ";
			int kbhit=getch();
			Showcursortype();
			if(kbhit==27)
			{
				return ;
			}
			if(kbhit==enter)
			{
				delete  dsnv.ds[i];
			    for (int j=i+1; j <dsnv.n; j++)
				{
			    	dsnv.ds[j-1]=dsnv.ds[j];
				}
		    	dsnv.n--;  	
		    	return;
			}
			
		}while(true);
	}
}
//-----------------------------------------------------chinh sua nhan vien
void sua_Nhan_Vien(ds_Nhan_Vien &dsnv)
{
	//note
	Vang_trang();
	gotoxy(11,36);
	cout<<"ESC       : THOAT       ";
	gotoxy(11,37);
	cout<<"LEN,XUONG : DIEU CHINH  ";
	Normal();
	
	
    HighLight2();
	gotoxy(108,2);
	cout<<"                                         ";
	gotoxy(108,3);
	cout<<"             SUA NHAN VIEN               ";
	gotoxy(108,4);
	cout<<"                                         ";
	Normal();
	o_Nhap(92,14);
	gotoxy(93,15);
	cout<< "MA NHAN VIEN  |                                                   ";
	int tempmnv;
nhapmnv:
	
	int kbhit=nhap_Int(tempmnv,108,15);
	if(kbhit==27)
	{
		return;
	}
	if(kbhit==80||kbhit==72)
	{
		goto nhapmnv;
	}
	int i = check_Nhan_Vien(dsnv,tempmnv) ;
	if(i==-1)
	{
		Error("MA KHONG TON TAI");
		gotoxy(108,15);
		cout<<"                                                   ";
		gotoxy(108,15);
		cout<<" ";
		goto nhapmnv;
	}
	else if (i!=-1)
	{
		Normal();
   		nhan_Vien *nv=new nhan_Vien;
			//cin.ignore();

		o_Nhap(92,18);
		gotoxy(93,19);
		cout<< "HO            |                                                   ";
		
		o_Nhap(92,22);
		gotoxy(93,23);
		cout<< "TEN           |                                                   ";
		
		o_Nhap(92,26);
		gotoxy(93,27);
		cout<< "PHAI          |            Nam                 Nu                 ";
		Normal();
		o_Nhap(92,30);
		gotoxy(93,31);
		cout<< "CMND          |                                                   ";
		Normal();
		string tempho=dsnv.ds[i]->ho;
		gotoxy(108,19);
		cout<<tempho;
		string tempten=dsnv.ds[i]->ten;
		gotoxy(108,23);
		cout<<tempten;
		string tempphai=dsnv.ds[i]->phai;
		string tempcm=dsnv.ds[i]->so_CMND;
		gotoxy(108,31);
		cout<<tempcm;
		int kbhit;
nhapho:
		kbhit=nhap_String(tempho,108,19);
		if(kbhit==27)
		{
			return ;
		}
		if(kbhit==72)
		{
			gotoxy(108,19);
			cout<<"                                                   ";
			gotoxy(108,19);
			cout<<tempho;
			goto nhapho;
		}
		if(kbhit==80)
		{
			gotoxy(108,19);
			cout<<"                                                   ";
			gotoxy(108,19);
			cout<<tempho;
			goto nhapten;
		}
nhapten:
		kbhit=nhap_String(tempten,108,23);
		if(kbhit==27)
		{
			return ;
		}
		if(kbhit==72)
		{
			gotoxy(108,23);
			cout<<"                                                   ";
			gotoxy(108,23);
			cout<<"                                                   ";
			gotoxy(108,23);
			cout<<tempten;
			goto nhapho;
		}
		if(kbhit==80)
		{
			gotoxy(108,23);
			cout<<"                                                   ";
			gotoxy(108,23);
			cout<<tempten;
			goto nhapphai;
		}
	
nhapphai:
		kbhit=nhap_Phai(tempphai,108 ,27);
		if(kbhit==72)
		{
			goto nhapten;
		}
		if(kbhit==80||kbhit==enter)
		{
			
		}
nhapcm:
		kbhit=nhap_String(tempcm,108,31);
		if(kbhit==27)
		{
			return ;
		}
		if(kbhit==72)
		{
			gotoxy(108,31);
			cout<<"                                                   ";
			gotoxy(108,31);
			cout<<tempcm;
			goto nhapphai;
		}
		if(kbhit==80)
		{
			gotoxy(108,31);
			cout<<"                                                   ";
			gotoxy(108,31);
			cout<<tempcm;
			goto nhapcm;
		}
		if(checkstring(tempho,tempho.length())==true)
		{
			Error("HO KHONG DUNG !");
			goto nhapho;
		}
		if(checkstring(tempten,tempten.length())==true)
		{
			Error("TEN KHONG DUNG !");
			goto nhapten;
		}
		if(check_Num_In_Sring(tempho)==false)
		{
			Error("HO KHONG DUNG !");
			goto nhapho;
		}
		if(check_Num_In_Sring(tempten)==false)
		{
			Error("TEN KHONG DUNG !");
			goto nhapten;
		}
		if(check_CMND(tempcm,dsnv,tempmnv)==false)
		{
			
			goto nhapcm;
		}
		
		Nocursortype();
		
		do
		{
			bool luu=o_Thoat("   BAN CO MUON LUU KHONG ?",79,15);
			Showcursortype();
			if(luu==false)
			{
				return ;
			}
			if(luu==true)
			{
				nv->ho=tempho;
				nv->phai=tempphai;
				nv->ten=tempten;
				nv->so_CMND=tempcm;
				chuan_Hoa(nv->phai);
				chuan_Hoa(nv->ho);
				chuan_Hoa(nv->ten);
				nv->ds_HD=dsnv.ds[i]->ds_HD;
				nv->ma_Nhan_Vien=dsnv.ds[i]->ma_Nhan_Vien;
				// xoa nv i roi them lai de danh sach van giu thu tu
				delete  dsnv.ds[i];
			    for (int j=i+1; j <dsnv.n; j++)
				{
			    	dsnv.ds[j-1]=dsnv.ds[j];
				}
		    	dsnv.n--;  
		    	add_NV_Ten(dsnv, nv);
				// sua luon ca ma nv;
				/*//             ma chua ton tai                 hoac            ma bang voi ma dang sua
				if((check_Nhan_Vien(dsnv,nv->ma_Nhan_Vien)==-1) || (nv->ma_Nhan_Vien==dsnv.ds[i]->ma_Nhan_Vien))
				{
					dsnv.ds[i]=nv;
				}
				else
				{
					cout<<" da ton tai";
				}*/
				return ;
			}
			if(kbhit==72)
			{
				goto nhapcm;
			}
		}while(true);
	}
}
// trong ds
void sua_Nhan_Vien_in_DS(ds_Nhan_Vien &dsnv,int chonnv)
{
	Showcursortype();
	xoa_Man_Hinh();
	ve_Khung_Nhap(90,8);
	//note
	Vang_trang();
	gotoxy(11,36);
	cout<<"ESC       : THOAT       ";
	gotoxy(11,37);
	cout<<"LEN,XUONG : DIEU CHINH  ";
	Normal();
	
	
    HighLight2();
	gotoxy(108,2);
	cout<<"                                         ";
	gotoxy(108,3);
	cout<<"             SUA NHAN VIEN               ";
	gotoxy(108,4);
	cout<<"                                         ";
	Normal();
	o_Nhap(92,14);
	gotoxy(93,15);
	cout<< "MA NHAN VIEN  |                                                   ";
	int tempmnv=dsnv.ds[chonnv]->ma_Nhan_Vien;
	gotoxy(108,15);
	cout<<tempmnv;

	int i = check_Nhan_Vien(dsnv,tempmnv) ;

	{
		Normal();
   		nhan_Vien *nv=new nhan_Vien;
			//cin.ignore();

		o_Nhap(92,18);
		gotoxy(93,19);
		cout<< "HO            |                                                   ";
		
		o_Nhap(92,22);
		gotoxy(93,23);
		cout<< "TEN           |                                                   ";
		
		o_Nhap(92,26);
		gotoxy(93,27);
		cout<< "PHAI          |            Nam                 Nu                 ";
		Normal();
		o_Nhap(92,30);
		gotoxy(93,31);
		cout<< "CMND          |                                                   ";
		Normal();
		string tempho=dsnv.ds[i]->ho;
		gotoxy(108,19);
		cout<<tempho;
		string tempten=dsnv.ds[i]->ten;
		gotoxy(108,23);
		cout<<tempten;
		string tempphai=dsnv.ds[i]->phai;
		string tempcm=dsnv.ds[i]->so_CMND;
		gotoxy(108,31);
		cout<<tempcm;
		int kbhit;
nhapho:
		kbhit=nhap_String(tempho,108,19);
		if(kbhit==27)
		{
			return ;
		}
		if(kbhit==72)
		{
			gotoxy(108,19);
			cout<<"                                                   ";
			gotoxy(108,19);
			cout<<tempho;
			goto nhapho;
		}
		if(kbhit==80)
		{
			gotoxy(108,19);
			cout<<"                                                   ";
			gotoxy(108,19);
			cout<<tempho;
			goto nhapten;
		}
nhapten:
		kbhit=nhap_String(tempten,108,23);
		if(kbhit==27)
		{
			return ;
		}
		if(kbhit==72)
		{
			gotoxy(108,23);
			cout<<"                                                   ";
			gotoxy(108,23);
			cout<<"                                                   ";
			gotoxy(108,23);
			cout<<tempten;
			goto nhapho;
		}
		if(kbhit==80)
		{
			gotoxy(108,23);
			cout<<"                                                   ";
			gotoxy(108,23);
			cout<<tempten;
			goto nhapphai;
		}
	
nhapphai:
		kbhit=nhap_Phai(tempphai,108 ,27);
		if(kbhit==72)
		{
			goto nhapten;
		}
		if(kbhit==80||kbhit==enter)
		{
			
		}
nhapcm:
		kbhit=nhap_String(tempcm,108,31);
		if(kbhit==27)
		{
			return ;
		}
		if(kbhit==72)
		{
			gotoxy(108,31);
			cout<<"                                                   ";
			gotoxy(108,31);
			cout<<tempcm;
			goto nhapphai;
		}
		if(kbhit==80)
		{
			gotoxy(108,31);
			cout<<"                                                   ";
			gotoxy(108,31);
			cout<<tempcm;
			goto nhapcm;
		}
		if(checkstring(tempho,tempho.length())==true)
		{
			Error("HO KHONG DUNG !");
			goto nhapho;
		}
		if(checkstring(tempten,tempten.length())==true)
		{
			Error("TEN KHONG DUNG !");
			goto nhapten;
		}
		if(check_Num_In_Sring(tempho)==false)
		{
			Error("HO KHONG DUNG !");
			goto nhapho;
		}
		if(check_Num_In_Sring(tempten)==false)
		{
			Error("TEN KHONG DUNG !");
			goto nhapten;
		}
		if(check_CMND(tempcm,dsnv,tempmnv)==false)
		{
			
			goto nhapcm;
		}
		
		Nocursortype();
		
		do
		{
			bool luu=o_Thoat("   BAN CO MUON LUU KHONG ?",79,15);
			Showcursortype();
			if(luu==false)
			{
				return ;
			}
			if(luu==true)
			{
				nv->ho=tempho;
				nv->phai=tempphai;
				nv->ten=tempten;
				nv->so_CMND=tempcm;
				chuan_Hoa(nv->phai);
				chuan_Hoa(nv->ho);
				chuan_Hoa(nv->ten);
				nv->ds_HD=dsnv.ds[i]->ds_HD;
				nv->ma_Nhan_Vien=dsnv.ds[i]->ma_Nhan_Vien;
				// xoa nv i roi them lai de danh sach van giu thu tu
				delete  dsnv.ds[i];
			    for (int j=i+1; j <dsnv.n; j++)
				{
			    	dsnv.ds[j-1]=dsnv.ds[j];
				}
		    	dsnv.n--;  
		    	add_NV_Ten(dsnv, nv);
				// sua luon ca ma nv;
				/*//             ma chua ton tai                 hoac            ma bang voi ma dang sua
				if((check_Nhan_Vien(dsnv,nv->ma_Nhan_Vien)==-1) || (nv->ma_Nhan_Vien==dsnv.ds[i]->ma_Nhan_Vien))
				{
					dsnv.ds[i]=nv;
				}
				else
				{
					cout<<" da ton tai";
				}*/
				return ;
			}
			if(kbhit==72)
			{
				goto nhapcm;
			}
		}while(true);
	}
}
// 
int nhap_Ma_NV(ds_Nhan_Vien dsnv)
{
	Showcursortype();
	int temp;
	o_Nhap(72,14);
	gotoxy(73,15);
	cout<< "MA NHAN VIEN  |                                                   ";
nhapmnv:
	int kbhit=nhap_Int(temp,88,15);
	if(kbhit==27)
	{
		return -2;
	}
	if(kbhit==72)
	{
		goto nhapmnv;
	}
	if(kbhit==80)
	{
		goto nhapmnv;
	}
	if(kbhit==enter)
	{
		
	}
	int check=check_Nhan_Vien(dsnv,temp);
		return check;
}












