#include "formats.cpp"



//====================================================================
//============================VAT TU=================================
//====================================================================
tree khoi_Tao_Vat_Tu()
{
	vat_Tu *vt =new vat_Tu;
	vt->pLeft=NULL;
	vt->pRight=NULL;
	return vt;
}
bool nhap_Vat_Tu(tree &vt)
{
	
	HighLight2();
	gotoxy(108,2);
	cout<<"                                         ";
	gotoxy(108,3);
	cout<<"               THEM VAT TU               ";
	gotoxy(108,4);
	cout<<"                                         ";
	Normal();
	o_Nhap(92,14);
	gotoxy(93,15);
	cout<< "MA VAT TU     |                                                   ";
	
	o_Nhap(92,18);
	gotoxy(93,19);
	cout<< "TEN VAT TU    |                                                   ";
	
	o_Nhap(92,22);
	gotoxy(93,23);
	cout<< "DON VI TINH   |                                                   ";
	
	o_Nhap(92,26);
	gotoxy(93,27);
	cout<< "SO LUONG      |                                                   ";
	Normal();
	string tempmvt;
	string tempten;
	string tempdvt;
	float tempsl;
	// nhap mavt
nhapmvt:
	int kbhit= nhap_MVT(tempmvt,108,15);
	if(kbhit==27)
	{
		return false;
	}
	if(kbhit==72)
	{
		
		gotoxy(108,15);
		cout<<"                                                   ";
		goto nhapmvt;
	}
	if(kbhit==80)
	{
		
		gotoxy(108,15);
		cout<<"                                                   ";
		gotoxy(108,15);
		cout<<tempmvt;
		goto nhapten;
	}
nhapten:
	kbhit=nhap_String(tempten,108,19);
	if(kbhit==27)
	{
		return false;
	}
	if(kbhit==72)
	{
		
		gotoxy(108,19);
		cout<<"                                                   ";
		gotoxy(108,19);
		cout<<tempten;
		goto nhapmvt;
	}
	if(kbhit==80)
	{
		
		gotoxy(108,19);
		cout<<"                                                   ";
		gotoxy(108,19);
		cout<<tempten;
		goto nhapdvt;
	}
nhapdvt:
	kbhit=nhap_String(tempdvt,108,23);
	if(kbhit==27)
	{
		return false;
	}
	if(kbhit==72)
	{
		
		gotoxy(108,23);
		cout<<"                                                   ";
		gotoxy(108,23);
		cout<<tempdvt;
		goto nhapten;
	}
	if(kbhit==80)
	{
		
		gotoxy(108,23);
		cout<<"                                                   ";
		gotoxy(108,23);
		cout<<tempdvt;
		goto nhapsl;
	}
nhapsl:
	
	kbhit= nhap_Float(tempsl,108 ,27);
	if(kbhit==27)
	{
		return false;
	}	
	if(kbhit==72)
	{
		gotoxy(108,27);
		cout<<"                                                   ";
		gotoxy(108,27);
		cout<<"0";
		goto nhapdvt;
	}
	if(kbhit==80)
	{
		goto nhapsl;
	}
	if(checkstring(tempmvt,10)==true)
	{
		Error("MA VAT TU KHONG DUOC DE TRONG!");
		goto nhapmvt;
	}
	if(checkstring(tempten,50)==true)
	{
		Error("TEN VAT TU KHONG DUOC DE TRONG!");
		goto nhapten;
	}
	if(check_Num_In_Sring(tempten)==false)
	{
		Error("TEN KHONG DUOC CHUA SO ");
		goto nhapten;
	}
	if(checkstring(tempdvt,tempdvt.length())==true)
	{
		Error("DON VI TINH KHONG DUOC DE TRONG!");
		goto nhapdvt;
	}
	if(check_Num_In_Sring(tempdvt)==false)
	{
		Error("DON VI TINH KHONG DUOC CHUA SO ");
		goto nhapdvt;
	}
	vt->ma_Vat_Tu=tempmvt;
	vt->ten_Vat_Tu=tempten;
	vt->don_Vi_Tinh=tempdvt;
	vt->so_Luong_Ton=tempsl;
	chuan_Hoa(vt->don_Vi_Tinh);
	chuan_Hoa(vt->ten_Vat_Tu);
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
			goto nhapsl;
		}
	}while(true);
	
	return true;
} 
void them_Vat_Tu(ds_Vat_Tu &dsvt)
{
	//thong bao tren o note
	Vang_trang();
	gotoxy(11,36);
	cout<<"ESC       : THOAT       ";
	gotoxy(11,37);
	cout<<"LEN,XUONG : DIEU CHINH  ";
	Normal();
	tree vt=khoi_Tao_Vat_Tu();
	bool suc;
	suc= nhap_Vat_Tu(vt);
	bool check = check_Vat_Tu(dsvt.ds,vt->ma_Vat_Tu);
	if(((check == false) || (dsvt.ds == NULL))&&(suc==true))
	{
		them_node_Vat_Tu(dsvt.ds,vt);
		Error("NHAP VAT TU THANH CONG");
		dsvt.n++;
	}
	else if (check ==true)
	{
		Error("MA VAT TU DA TON TAI");
	}
	xoa_Khung_HD();
	
	
}
void them_node_Vat_Tu(tree &p,tree vt)
{
	if (p == NULL)
	{
		p=vt;
	}
	else
	{
		if (vt->ma_Vat_Tu > p->ma_Vat_Tu)
		{
			return them_node_Vat_Tu(p->pRight, vt);
		}
		else if (vt->ma_Vat_Tu < p->ma_Vat_Tu)
		{
			return them_node_Vat_Tu(p->pLeft, vt);
		}
	}
}
//------------------------------------------------xuat ra man hinh
void show_Vat_Tu(tree a,int n)
{
	gotoxy(62,8+n);
	cout<<"                                 ";
	gotoxy(62,8+n);
	cout<<a->ma_Vat_Tu;
	gotoxy(96,8+n);
	cout<<"                                   ";
	gotoxy(96,8+n);
	cout<<a->ten_Vat_Tu;
	gotoxy(132,8+n);
	cout<<"                         ";
	gotoxy(132,8+n);
	cout<<a->don_Vi_Tinh;
	gotoxy(158,8+n);
	cout<<"                          ";
	gotoxy(158,8+n);
	cout<<a->so_Luong_Ton;
	
}
void xuat_Vat_Tu(ds_Vat_Tu &a)
{
	

	HighLight2();
	gotoxy(104,2);
	cout<<"                                         ";
	gotoxy(104,3);
	cout<<"             DANH SACH VAT TU            ";
	gotoxy(104,4);
	cout<<"                                         ";
	Normal();
	
	string* arrtemp = new string[a.n];
	get_MVT(a.ds,arrtemp);
	
optionfail:	
	xoa_Man_Hinh2();
	
	HighLight2();
	gotoxy(60,6);
	cout<<"|    Ma Vat Tu                     Ten Vat Tu                          Don Vi Tinh               So Luong Ton                |";
	Normal();
	ve_Khung_Xuat();
	//tao ra 1 mang tam de luu cac ma vat tu trong danh sach mang cap phat dong 
	if(a.n==0)
	{
		
		Error("CHUA CO VAT TU NAO");
		getch();
		return;
	}
	

	Normal();
	int chonnv=show_VT_Page(a,arrtemp);

	// chon trong danh sach vat tu 
	if(chonnv!=-1)
	{
		// hoi co muon lap hoa don voi nhan vien nay hay khong
		gotoxy(wherex()-1,wherey());
		cout<<" ";
		Normal();
		int checklaphd=o_Option("TUY CHON CHO VAT TU NAY",79,15,0);// sua o nay lai
		
		if(checklaphd==1)// sua vattu
		{
			chonnv-=1;
			sua_Vat_Tu_in_DS(a.ds, arrtemp[chonnv]);
		}
		else if(checklaphd==2)// xoa vat tu
		{
			chonnv-=1;
			tree check=check_Vat_Tu(a.ds,arrtemp[chonnv]);
			if(check->used>0)// used >0  tuc la da co trong 1 hoa don nao do khong the xoa duoc
			{
				Error("VAT TU DA SU DUNG KHONG THE XOA !");
				goto optionfail;
			} 
			else
			{
				xoa_Vat_Tu_in_DS(a,arrtemp[chonnv]);
			}
			
		}
		else if(checklaphd==-1)
		{
			goto optionfail;	
		}
	}
	index=0;
	delete[] arrtemp;
	
}
void get_MVT(tree a,string* &arrtemp)
{
	if(a==NULL)
	{
		return;
	}
	else
	{	
		get_MVT(a->pRight,arrtemp);
		arrtemp[index]=a->ma_Vat_Tu;
		index++;
		get_MVT(a->pLeft,arrtemp);
	}
}

int show_VT_Page(ds_Vat_Tu a,string* arrtemp)//show vat tu theo trang
{
	int currentpage=1;
	int maxpage=1;
	if(a.n<=17)
	{
		maxpage=1;
	}
	else if(a.n>17)
	{
		if(a.n%17==0)
		{
			maxpage=a.n/17;
		}
		else if(a.n%17!=0)
		{
			maxpage=(a.n/17 +1);
		}
	}	
	show_A_Page_VT(a,arrtemp,currentpage);
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
			int sovt=0;
			if(currentpage<maxpage)
			{
				sovt=17;
			}
			else if(currentpage==maxpage)
			{
				sovt=a.n%17;
			}
			int chonnv=menu_Quanly(chon_Vat_Tu,sovt,2);
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
				show_A_Page_VT(a,arrtemp,currentpage);
			}
			
		}
		else if(sukien==PU)
		{
			if(currentpage>1)
			{
				currentpage--;
				show_A_Page_VT(a,arrtemp,currentpage);
			}
		}
		
	}
	return -1;	
}
void show_A_Page_VT(ds_Vat_Tu a,string* arrtemp,int currentpage)//show 1 trang vat tu
{
	xoa_Trong_Khung_Xuat();
	// show 37 vat tu trong 1 trang
	int maxpage=1;
	if(a.n<=17)
	{
		maxpage=1;
	}
	else if(a.n>17)
	{
		if(a.n%17==0)
		{
			maxpage=a.n/17;
		}
		else if(a.n%17!=0)
		{
			maxpage=(a.n/17 +1);
		}
	}	
	int n=0;
	int lastVT=0;
	int firstVT=(currentpage-1)*17;
	//tinh lastVT
	if(currentpage<maxpage)
	{
		lastVT=firstVT+17;
	}
	// bang nhau co 2 truowng hop 1: bang nhau co du 2: bang  nhau khong du
	else if(currentpage==maxpage)
	{
		//1: khong du
		if(a.n%17 ==0)
		{
			lastVT=firstVT+17;
		}
		//2:co du
		else if(a.n%17 !=0)
		{
			lastVT=firstVT+(a.n%17);
		}
		
	}
	//xuat cac vat tu cua page ra man hinh
	for(int i=firstVT;  i< lastVT ;i++)
	{
		tree x;
		x=check_Vat_Tu(a.ds,arrtemp[i]);
		show_Vat_Tu(x,n);
		n+=2;
		
	}
	HighLight();
	gotoxy(49,42);
	cout<<"Pg Dn       : Next";
	gotoxy(49,43);
	cout<<"Pg Up       : Prev";
	Normal();
	gotoxy(49,44);
	cout<<"Page        : "<<currentpage<<"/"<<maxpage;
	gotoxy(49,45);
	cout<<"Tong Vat Tu : "<<a.n<<"  (17vt / Page)";
	
}
//void xuat_Vat_Tu(tree a,int &n) // xuat tat ca
//{
//	
//	if (a != NULL)
//	{	
//		xuat_Vat_Tu(a->pRight,n);
//		show_Vat_Tu(a,n);
//		n++;
//		
//		gotoxy(91,8+n);
//		
//		xuat_Vat_Tu(a->pLeft,n);
//		
//	}
//}
//---------------------------------------------check vat tu da ton tai chua
tree check_Vat_Tu(tree p,string mavt)
{
	if(p==NULL)
	{
		return NULL;
	}
	else
	{
		if(p->ma_Vat_Tu.compare(mavt)==0)
		{
			return p;
		}
		else if(p->ma_Vat_Tu.compare(mavt)<0) 
		{
			return check_Vat_Tu(p->pRight,mavt);
		}
		else if(p->ma_Vat_Tu.compare(mavt)>0) 
		{
			return check_Vat_Tu(p->pLeft,mavt);
		}	
	}

}
//----------------------------------------------chinh sua vat tu
void sua_Vat_Tu(tree &p)
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
	cout<<"               SUA VAT TU                ";
	gotoxy(108,4);
	cout<<"                                         ";
	Normal();
	gotoxy(102,15);
	
	o_Nhap(92,14);
	gotoxy(93,15);
	cout<< "MA VAT TU     |                                                   ";
	string temp;
nhapmvt:
	int chk=nhap_MVT(temp,108,15);
	if(chk==27)
	{
		xoa_Khung_HD();
		return;
	}
	tree check=check_Vat_Tu(p,temp);
	if (check!=NULL)
	{
		if(sua_Mot_Vat_Tu(p,temp)==true)
		{
			Error("SUA VAT TU THANH CONG");
			xoa_Khung_HD();
		}
		else
		{
			return;
		}
		
	}
	else
	{
		Error("MA VAT TU KHONG TON TAI");
		goto nhapmvt;
	}
}
// sua trong danh sach
void sua_Vat_Tu_in_DS(tree &p,string mvt)
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
	cout<<"               SUA VAT TU                ";
	gotoxy(108,4);
	cout<<"                                         ";
	Normal();
	gotoxy(102,15);
	
	o_Nhap(92,14);
	gotoxy(93,15);
	cout<< "MA VAT TU     |                                                   ";
	string temp=mvt;
	gotoxy(108,15);
	cout<<temp;
	
	tree check=check_Vat_Tu(p,temp);
	if (check!=NULL)
	{
		if(sua_Mot_Vat_Tu(p,temp)==true)
		{
			Error("SUA VAT TU THANH CONG");
			xoa_Khung_HD();
		}
		else
		{
			return;
		}
		
	}
	
}
bool sua_Mot_Vat_Tu(tree &p,string mavt)
{
	if (p != NULL)
	{	
		if(p->ma_Vat_Tu==mavt)
		{
			Normal();
			o_Nhap(92,22);
			gotoxy(93,23);
			cout<< "TEN VAT TU    |                                                   ";
			
			o_Nhap(92,26);
			gotoxy(93,27);
			cout<< "DON VI TINH   |                                                   ";
			Normal();
		
			string tempten=p->ten_Vat_Tu;
			string tempdvt=p->don_Vi_Tinh;
			gotoxy(108,23);
			cout<<tempten;
			gotoxy(108,27);
			cout<<tempdvt;
			int kbhit;
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
				cout<<tempten;
				goto nhapten;
			}
			if(kbhit==80)
			{
				
				gotoxy(108,23);
				cout<<"                                                   ";
				gotoxy(108,23);
				cout<<tempten;
				goto nhapdvt;
			}
nhapdvt:
			kbhit=nhap_String(tempdvt,108,27);
			if(kbhit==27)
			{
				return false;
			}
			if(kbhit==72)
			{
				
				gotoxy(108,27);
				cout<<"                                                   ";
				gotoxy(108,27);
				cout<<tempdvt;
				goto nhapten;
			}
			if(kbhit==80)
			{
				
				gotoxy(108,27);
				cout<<"                                                   ";
				gotoxy(108,27);
				cout<<tempdvt;
				goto nhapdvt;
			}
			
			if(checkstring(tempten,50)==true)
			{
				Error("TEN VAT TU KHONG DUOC DE TRONG");
				goto nhapten;
			}
			if(checkstring(tempdvt,tempdvt.length())==true)
			{
				Error("DON VI TINH KHONG DUOC DE TRONG");
				goto nhapdvt;
			}
			if(check_Num_In_Sring(tempten)==false)
			{
				Error("TEN VAT TU KHONG DUOC CHUA SO");
				goto nhapten;
			}
			if(check_Num_In_Sring(tempdvt)==false)
			{
				Error("DON VI TINH KHONG DUOC CHUA SO");
				goto nhapdvt;
			}
			do
			{
				
				Nocursortype();
				bool luu=o_Thoat("   BAN CO MUON LUU KHONG ?",79,15);
				
				Showcursortype();
				if(luu==false)
				{
					return false;
				}
				if(luu==true)
				{
					p->don_Vi_Tinh=tempdvt;
					p->ten_Vat_Tu=tempten;
					chuan_Hoa(p->don_Vi_Tinh);
					chuan_Hoa(p->ten_Vat_Tu);
					return true;
				}
				
			}while(true);
			
			
		}
		else if(p->ma_Vat_Tu.compare(mavt)<0) 
		{
			return sua_Mot_Vat_Tu(p->pRight,mavt);
		}
		else if(p->ma_Vat_Tu.compare(mavt)>0) 
		{
			return sua_Mot_Vat_Tu(p->pLeft,mavt);
		}	
	}
}

//------------------------------------------xoa vat tu 
tree node_The(tree p)// tim node nho nhat cua cay con phai de the cho
{
	if (p != NULL)
	{
		if (p->pLeft == NULL)
		{
			return p;
		}
		return node_The(p->pLeft);
	}
	
}
void xoa_Vat_Tu(ds_Vat_Tu &dsvt)
{
	//note
	Vang_trang();
	gotoxy(11,36);
	cout<<"ESC       : THOAT       ";
	gotoxy(11,37);
	cout<<"LEN,XUONG : DIEU CHINH  ";
	Normal();
	
	
	int thoat;
	HighLight2();
	gotoxy(108,2);
	cout<<"                                         ";
	gotoxy(108,3);
	cout<<"               XOA VAT TU                ";
	gotoxy(108,4);
	cout<<"                                         ";
	Normal();
	string temp;
	o_Nhap(92,14);
	gotoxy(93,15);
	cout<< "MA VAT TU     |                                                   ";
nhapmvt:
	int kbhit= nhap_MVT(temp,108,15);
	if(kbhit==27)
	{
		xoa_Khung_HD();
		return ;
	}
	if(kbhit==72)
	{
		
		gotoxy(108,15);
		cout<<"                                                   ";
		goto nhapmvt;
	}
	if(kbhit==80)
	{
		
		gotoxy(108,15);
		cout<<"                                                   ";
		gotoxy(108,15);
		cout<<temp;
		goto nhapmvt;
	}
	tree check=check_Vat_Tu(dsvt.ds,temp);
	if(check->used==1)
	{
		Error("VAT TU DA SU DUNG KHONG THE XOA !");
		goto nhapmvt;
	} 
	if (check!=NULL)
	{
		
		o_Nhap(92,18);
		HighLight3 () ;
		gotoxy(93,19);
		cout<< "TEN VAT TU    |                                                   ";
		gotoxy(108,19);
		cout<<check->ten_Vat_Tu;
		o_Nhap(92,22);
		HighLight3 () ;
		gotoxy(93,23);
		cout<< "DON VI TINH   |                                                   ";
		gotoxy(108,23);
		cout<<check->don_Vi_Tinh;
		
		o_Nhap(92,26);
		HighLight3 () ;
		gotoxy(93,27);
		cout<< "SO LUONG      |                                                   ";
		gotoxy(108,27);
		cout<<check->so_Luong_Ton;
		
		Normal();
		Nocursortype();
		gotoxy(100,35);
		cout<<"ESC : THOAT";
		gotoxy(135,35);
		cout<<"ENTER: XOA ";
		thoat=getch();
		while((thoat!=Esc)&&(thoat!=enter))
		{
			thoat=getch();
		}
		if(thoat==enter)
		{
			xoa_Mot_Vat_Tu(dsvt.ds,temp);
			dsvt.n--;
			Error("XOA VAT TU THANH CONG");
			
		}
		else if(thoat==Esc)
		{
			
		}
		
	}
	else
	{
		Error("MA VAT TU KHONG TON TAI");
		goto nhapmvt;
	}
	xoa_Khung_HD();
}
// xoa trong danh sach
void xoa_Vat_Tu_in_DS(ds_Vat_Tu &dsvt,string mvt)
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
	
	
	int thoat;
	HighLight2();
	gotoxy(108,2);
	cout<<"                                         ";
	gotoxy(108,3);
	cout<<"               XOA VAT TU                ";
	gotoxy(108,4);
	cout<<"                                         ";
	Normal();
	string temp=mvt;
	o_Nhap(92,14);
	gotoxy(93,15);
	cout<< "MA VAT TU     |                                                   ";
	gotoxy(108,15);
	cout<<temp;
	tree check=check_Vat_Tu(dsvt.ds,temp);
	if (check!=NULL)
	{
		
		o_Nhap(92,18);
		HighLight3 () ;
		gotoxy(93,19);
		cout<< "TEN VAT TU    |                                                   ";
		gotoxy(108,19);
		cout<<check->ten_Vat_Tu;
		o_Nhap(92,22);
		HighLight3 () ;
		gotoxy(93,23);
		cout<< "DON VI TINH   |                                                   ";
		gotoxy(108,23);
		cout<<check->don_Vi_Tinh;
		
		o_Nhap(92,26);
		HighLight3 () ;
		gotoxy(93,27);
		cout<< "SO LUONG      |                                                   ";
		gotoxy(108,27);
		cout<<check->so_Luong_Ton;
		
		Normal();
		Nocursortype();
		gotoxy(100,35);
		cout<<"ESC : THOAT";
		gotoxy(135,35);
		cout<<"ENTER: XOA ";
		thoat=getch();
		while((thoat!=Esc)&&(thoat!=enter))
		{
			thoat=getch();
		}
		if(thoat==enter)
		{
			xoa_Mot_Vat_Tu(dsvt.ds,temp);
			dsvt.n--;
			Error("XOA VAT TU THANH CONG");
			
		}
		else if(thoat==Esc)
		{
			
		}
		
	}
	xoa_Khung_HD();
}
void xoa_Mot_Vat_Tu(tree& p, string mavt)
{
	if (p != NULL)
	{
		if (p->ma_Vat_Tu.compare(mavt)<0)
		{
			xoa_Mot_Vat_Tu(p->pRight, mavt);
		}
		else if (p->ma_Vat_Tu.compare(mavt)>0)
		{
			xoa_Mot_Vat_Tu(p->pLeft, mavt);
		}
		else//neu mavt == p->ma_vat_tu
		{
			//neu node khong co con nao <=>node la
			if ((p->pLeft == NULL) && (p->pRight == NULL))
			{
				delete p;
				p=NULL;
				return;
			}
			//neu node co 1 con phai
			if (p->pLeft == NULL && p->pRight != NULL)
			{
				tree temp=p;
				tree temp2=p->pRight;
				delete temp;
				p=temp2;
				return;
			}
			//neu node co 1 con trai
			if (p->pLeft != NULL && p->pRight == NULL)
			{
				tree temp=p;
				tree temp2=p->pLeft;
				delete temp;
				p=temp2;
				return;
			}
			// neu node co 2 con
			if (p->pLeft != NULL && p->pRight != NULL)
			{
				tree temp=p->pRight;
				tree temp2 = node_The(p->pRight);
				temp2->pLeft= p->pLeft;
				delete p;
				p=temp;
				return;
			}
		}		
	}
}
void search_Goi_Y_Ten_Vat_Tu(ds_Vat_Tu a ,string tempten,string arrtemp[2][5])
{
	//sap sep mang arrtemp tang dan theo su xuat hien cua tempten
	string arrtempten[a.n];// lay ten
	string arrtempmvt[a.n];// lay mvt
	index=0;
	get_Ten_VT(a.ds,arrtempten,arrtempmvt);//done
	sap_Xep_Ten_Goi_Y(a.n, tempten, arrtempten, arrtempmvt);
	index=0;
	//lay 5 ten dau bang
	for(int i=0;i<5;i++)
	{
		if(arrtempten[i].find(tempten)==-1)
		{
			
			break;
		}
		arrtemp[0][i]=arrtempten[i];
		arrtemp[1][i]=arrtempmvt[i];
		index++;
	}	
}
void sap_Xep_Ten_Goi_Y(int n,string tempten,string arrtempten[],string arrtempmvt[])
{
	int inttemp[n];
	for(int i=0;i<n;i++)// do ra 1 mang moi theo thu tu xuat hien
	{
		inttemp[i]=arrtempten[i].find(tempten);
		if(inttemp[i]==-1)
		{
			inttemp[i]=100;
		}
	}
	// sap xep thu tu xuat hien va mang arrtemp2 luon
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(inttemp[i]>inttemp[j])
			{
				int temp= inttemp[i];
				inttemp[i]=inttemp[j];
				inttemp[j]=temp;
				string temps= arrtempten[i];
				arrtempten[i]=arrtempten[j];
				arrtempten[j]=temps;
				temps= arrtempmvt[i];
				arrtempmvt[i]=arrtempmvt[j];
				arrtempmvt[j]=temps;
			}
		}
	}
	
	
}
void get_Ten_VT(tree a,string arrtemp[],string arrtempmvt[])
{
	if(a==NULL)
	{
		return;
	}
	else
	{	
		get_Ten_VT(a->pRight,arrtemp,arrtempmvt);
		arrtemp[index]=a->ten_Vat_Tu;
		arrtempmvt[index]=a->ma_Vat_Tu;
		index++;
		get_Ten_VT(a->pLeft,arrtemp,arrtempmvt);
	}
}
void show_Goi_Y(string arrtemp[2][5],int n)
{
	int x=66;
	int y=18;
	xoa_Khung_Nhap(n);
	for(int i=0;i<n;i++)
	{
		gotoxy(x,y+i);
		cout<<arrtemp[0][i];
		gotoxy(x+30,y+i);
		cout<<arrtemp[1][i];
	}
	
	
}











