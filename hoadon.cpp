#include "nhanvien.cpp"
#include<bits/stdc++.h>
//------------------------------- nguyen mau ham

//vi du khachs mua hang co ther co chuc nang tra hang vay nhap hang ve co chuc nang tra hang hay khong ? 

// loi moi nhan vien chi nhap duoc mot hoa don
// neu thoat ra thi tao hoa don moi
// neu dang nhap thi van la hoa don do
// neu cpo tra hang hi vat tu do se thanh hang tra neu tra het thi tra va cho 0

//====================================================================
//========================HOA DON====================================
//====================================================================
//=================================
void lap_Hoa_Don(ds_Nhan_Vien &dsnv,ds_Vat_Tu &a)
{
	
	Normal();
	ve_Khung_Nhap(90,8);
	//note
	Vang_trang();
	gotoxy(11,36);
	cout<<"ESC       : THOAT       ";
	gotoxy(11,37);
	cout<<"LEN,XUONG : DIEU CHINH  ";
	Normal();
	
	
	gotoxy(50,4);
	HighLight2();
	gotoxy(104,2);
	cout<<"                                         ";
	gotoxy(104,3);
	cout<<"               LAP HOA DON               ";
	gotoxy(104,4);
	cout<<"                                         ";
	Normal();
	o_Nhap(92,14);
	gotoxy(93,15);
	cout<< "MA NHAN VIEN  |                                                   ";
	int tempmnv;
	int kbhit;
	
nhapmnv:
	kbhit=nhap_Int(tempmnv,108,15);
	if(kbhit==27)
	{
		return ;
	}
	if(kbhit==72)
	{
		gotoxy(108,15);
		cout<<"                                                   ";
		goto nhapmnv;
	}
	if(kbhit==80)
	{
		gotoxy(108,15);
		cout<<"                                                   ";
		goto nhapmnv;
	}
	int check=check_Nhan_Vien(dsnv,tempmnv);
	if(check==-1)
	{
		Error("NHAN VIEN KHONG XAC DINH ");
		gotoxy(108,15);
		cout<<"                                                   ";
		goto nhapmnv;
	}
	else
	{

		//xoa_Man_Hinh2();
		node_Hoa_Don* hoadon; 
		o_Nhap(92,5);
		gotoxy(93,6);
		cout<<"                                                                  ";
		gotoxy(93,6);
		cout<<"Ho Va Ten :";
		gotoxy(135,6);
		cout<<"CMND      :";
		gotoxy(105,6);
		cout<<dsnv.ds[check]->ho<<" "<<dsnv.ds[check]->ten;
		gotoxy(140,6);
		cout<<dsnv.ds[check]->so_CMND;
		
		o_Nhap(92,18);
		gotoxy(93,19);
		cout<< "SO HOA DON    |                                                   ";
		
		o_Nhap(92,22);
		gotoxy(93,23);
		cout<< "LOAI HOA DON  |            Xuat                Nhap               ";

		o_Nhap(92,26);
		gotoxy(93,27);
		cout<< "NGAY LAP      |                                                   ";
		Normal();
		
		
		node_Hoa_Don* p =khoi_Tao_Node_HD();
		string tempmhd;
		string temploai;
		date tempnl;
		getcurrentdate(tempnl);
		gotoxy(108,27);
		xuat_Ngay(tempnl);
		
		int kbhit;
nhaphd: 
		kbhit=nhap_String(tempmhd,108,19);
		if(kbhit==27)
		{
			
			return;
		}
		if(kbhit==72)
		{
			gotoxy(108,19);
			cout<<"                                                   ";
			gotoxy(108,15);
			cout<<"                                                   ";
			gotoxy(93,6);
			cout<<"                                                                  ";
			goto nhapmnv;
		}
		if(kbhit==80)
		{
			gotoxy(108,19);
			cout<<"                                                   ";
			gotoxy(108,19);
			cout<<tempmhd;
			goto nhaploai;
		}
nhaploai:
		kbhit=nhap_Loai(temploai,108,23);
		if(kbhit==72)
		{
			goto nhaphd;
		}
		if(kbhit==80||kbhit==enter)
		{
			
		}

		
		// check xem ma hoa don da ton tai hay chua
		hoadon = search_So_HD(dsnv,tempmhd);
		//hoadon =search_Hoa_Don_bysoHD(dsnv.ds[check]->ds_HD.pHead,tempmhd);// chi duyet trong mot nhan vien 
		if(hoadon!=NULL)// neu da ton tai thi se !=NULL
		{
			Error("HOA DON DA TON TAI !");
			goto nhaphd;
		}
		if(checkstring(tempmhd,20)==true)
		{
			Error("SO HOA DON KHONG HOP LE");
			goto nhaphd;
		}
		
		
		Nocursortype();
		gotoxy(93,35);
		cout<<"ESC  : BO LAP HOA DON        ";
		gotoxy(128,35);
		cout<<"ENTER: TIEP TUC LAP CHI TIET ";
		do
		{
			int kbhit=getch();
			Showcursortype();
			if(kbhit==27)
			{
				return ;
			}
			if(kbhit==enter)
			{
				p->HD.soHD=tempmhd;
				p->HD.loai=temploai;
				p->HD.ngay_Lap=tempnl;
				bool cthem=them_Chi_Tiet_HD(p,a);
				if(cthem==false)
				{
					break;
				}
				
				index=0;
				//them thanh cong
				bool check_update = update_Main_SLT(a,p);
				//update so luong ton
				if(check_update==true)
				{
					them_Hoa_Don(dsnv.ds[check]->ds_HD.pHead,p);
					dsnv.ds[check]->ds_HD.n++;
					return;
				}
				else
				{
					return;
				}
			}
			if(kbhit==72)
			{
				goto nhaploai;
			}
		}while(true);
		
		
		
		
	}
}
//
void lap_Hoa_Don_in_DS(ds_Nhan_Vien &dsnv,ds_Vat_Tu &a,int manv)
{
	
	Normal();
	xoa_Man_Hinh2();
	ve_Khung_Nhap(90,8);
	//note
	Vang_trang();
	gotoxy(11,36);
	cout<<"ESC       : THOAT       ";
	gotoxy(11,37);
	cout<<"LEN,XUONG : DIEU CHINH  ";
	Normal();
	
	
	gotoxy(50,4);
	HighLight2();
	gotoxy(104,2);
	cout<<"                                         ";
	gotoxy(104,3);
	cout<<"               LAP HOA DON               ";
	gotoxy(104,4);
	cout<<"                                         ";
	Normal();
	o_Nhap(92,14);
	gotoxy(93,15);
	cout<< "MA NHAN VIEN  |                                                   ";
	int tempmnv=dsnv.ds[manv]->ma_Nhan_Vien;
	int kbhit;
	
	gotoxy(108,15);
	cout<<tempmnv;
	{

		//xoa_Man_Hinh2();
		node_Hoa_Don* hoadon; 
		o_Nhap(92,5);
		gotoxy(93,6);
		cout<<"                                                                  ";
		gotoxy(93,6);
		cout<<"Ho Va Ten :";
		gotoxy(135,6);
		cout<<"CMND      :";
		gotoxy(105,6);
		cout<<dsnv.ds[manv]->ho<<" "<<dsnv.ds[manv]->ten;
		gotoxy(140,6);
		cout<<dsnv.ds[manv]->so_CMND;
		
		o_Nhap(92,18);
		gotoxy(93,19);
		cout<< "SO HOA DON    |                                                   ";
		
		o_Nhap(92,22);
		gotoxy(93,23);
		cout<< "LOAI HOA DON  |            Xuat                Nhap               ";

		o_Nhap(92,26);
		gotoxy(93,27);
		cout<< "NGAY LAP      |                                                   ";
		Normal();
		
		
		node_Hoa_Don* p =khoi_Tao_Node_HD();
		string tempmhd;
		string temploai;
		date tempnl;
		getcurrentdate(tempnl);
		gotoxy(108,27);
		xuat_Ngay(tempnl);
		int kbhit;
nhaphd: 
		kbhit=nhap_String(tempmhd,108,19);
		if(kbhit==27)
		{
			
			return;
		}
		if(kbhit==72)
		{
			gotoxy(108,19);
			cout<<"           ";
			goto nhaphd;
		}
		if(kbhit==80)
		{
			gotoxy(108,19);
			cout<<"                                                   ";
			gotoxy(108,19);
			cout<<tempmhd;
			goto nhaploai;
		}
nhaploai:
		kbhit=nhap_Loai(temploai,108,23);
		if(kbhit==72)
		{
			goto nhaphd;
		}
		if(kbhit==80||kbhit==enter)
		{
	
		}

		
		// check xem ma hoa don da ton tai hay chua
		hoadon = search_So_HD(dsnv,tempmhd);
		//hoadon =search_Hoa_Don_bysoHD(dsnv.ds[check]->ds_HD.pHead,tempmhd);// chi duyet trong mot nhan vien 
		if(hoadon!=NULL)// neu da ton tai thi se !=NULL
		{
			Error("HOA DON DA TON TAI !");
			goto nhaphd;
		}
		if(checkstring(tempmhd,20)==true)
		{
			Error("SO HOA DON KHONG HOP LE");
			goto nhaphd;
		}
		
		
		Nocursortype();
		gotoxy(93,35);
		cout<<"ESC  : BO LAP HOA DON        ";
		gotoxy(128,35);
		cout<<"ENTER: TIEP TUC LAP CHI TIET ";
		do
		{
			int kbhit=getch();
			Showcursortype();
			if(kbhit==27)
			{
				return ;
			}
			if(kbhit==enter)
			{
				p->HD.soHD=tempmhd;
				p->HD.loai=temploai;
				p->HD.ngay_Lap=tempnl;
				bool cthem=them_Chi_Tiet_HD(p,a);
				if(cthem==false)
				{
					break;
				}
				
				index=0;
				//them thanh cong
				bool check_update = update_Main_SLT(a,p);
				//update so luong ton
				if(check_update==true)
				{
					them_Hoa_Don(dsnv.ds[manv]->ds_HD.pHead,p);
					dsnv.ds[manv]->ds_HD.n++;
					return;
				}
				else
				{
					return;
				}
			}
			if(kbhit==72)
			{
				goto nhaploai;
			}
		}while(true);
		
		
		
		
	}
}

//sau khi nhap chi tiet hoa don thi moi update
bool update_Main_SLT(ds_Vat_Tu &a,node_Hoa_Don* &p)
{
	if(p->HD.dsCTHD.n==0)
	{
		return false;
	}
	else
	{
		for(int i=0;i<p->HD.dsCTHD.n;i++)
		{
			tree getmavt = check_Vat_Tu(a.ds,p->HD.dsCTHD.ds[i].ma_Vat_Tu);
			update_So_Luong_Ton(p,getmavt);
		}
		return true;
	}
}
//khoi tao node ho don
node_Hoa_Don* khoi_Tao_Node_HD()
{
	
	node_Hoa_Don* p = new node_Hoa_Don;
	if(p==NULL)
	{
		Error("BO NHO DA DAY KHONG THE TAO HOA DON !");	
	}
	else
	{
		p->pNext = NULL;
	} 
	return p;
}
void them_Hoa_Don(node_Hoa_Don* &pHead,node_Hoa_Don* p)
{
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (node_Hoa_Don *k = pHead;k != NULL;k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}
bool nhap_Chi_Tiet_HD(chi_Tiet_HD &cthd,ds_Vat_Tu a)
{
	string arrtemp[2][5];
	
	//bay gio index mang so luong vat tu goi i
	Normal();
	gotoxy(55,42);
	cout<<"                        ";
	gotoxy(90,42);
	cout<<"                        ";
	string tt;
	Normal();
	o_Nhap(50,11);
	gotoxy(51,12);
	cout<< "MA VAT TU     |                                                   ";
	o_Nhap(50,15);
	gotoxy(51,16);
	cout<< "TEN VAT TU    |                                                   ";
	
	

	Normal();
	string tempmvt;
	string temptenvt;
	float tempsl;
	int tempdg;
	float tempvat;
	
nhapmvt:
	//xoa_Khung_Nhap();
	int kbhit= nhap_String(tempmvt,66,12);
	if(kbhit==27)
	{
		return false;
	}
	if(kbhit==72)
	{
		
		gotoxy(66,12);
		cout<<"                                                   ";
		goto nhapmvt;
	}
	if(kbhit==80)
	{
		
		gotoxy(66,12);
		cout<<"                                                   ";
		gotoxy(66,12);
		cout<<tempmvt;
		goto nhaptenvt;
	}
	if(kbhit==enter)
	{
		goto nhaptenvt;
	}
	
nhaptenvt:
	tree getmavt=check_Vat_Tu(a.ds,tempmvt);
	if(getmavt!=NULL)
	{
		temptenvt=getmavt->ten_Vat_Tu;
	}
	int soluonggoiy=0;
	do
	{
		
		gotoxy(66,16);
		cout<<temptenvt;
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
				if(temptenvt.length()<50)
				{
					xoa_Khung_Nhap(0);
					gotoxy(66+temptenvt.length(),16);
					ch=toupper(ch);
					cout<<ch;
					temptenvt.push_back(ch);
					search_Goi_Y_Ten_Vat_Tu( a ,temptenvt, arrtemp);
					show_Goi_Y(arrtemp,index );
					soluonggoiy=index;
				}
				
			}
			//neu an backspace thi xoa
			else if(kbhit==8)
			{
				if(temptenvt.length()!=0)
				{
					xoa_Khung_Nhap(0);
					gotoxy(66+temptenvt.length()-1,16);
					cout<<" ";
					temptenvt.erase(temptenvt.end()-1 );
					if(temptenvt.length()!=0)
					{
						search_Goi_Y_Ten_Vat_Tu( a ,temptenvt, arrtemp);
						
						show_Goi_Y(arrtemp,index );
						soluonggoiy=index;
					}
					
				}
			}
		}
		if(kbhit==27)
		{
			return false;
		}
		if(kbhit==80)
		{
			if(temptenvt.length()>0)
			{
				xoa_Khung_Nhap(0);
				temptenvt.erase(temptenvt.end()-1 );
				gotoxy(66,16);
				cout<<"                                                   ";
				gotoxy(66,16);
				cout<<temptenvt;
				search_Goi_Y_Ten_Vat_Tu( a ,temptenvt, arrtemp);
				show_Goi_Y(arrtemp,index );
				soluonggoiy=index;
			}
			if(soluonggoiy!=0)
			{
				int chon=menu_Quanly(chon_CTHD,soluonggoiy,4);
				
				Normal();
				Showcursortype();
				if(chon==-1)
				{
					goto nhaptenvt;
				}
				else
				{
					
					temptenvt=arrtemp[0][chon-1];
					gotoxy(66,16);
					cout<<"                                                   ";
					gotoxy(66,16);
					cout<<temptenvt;
					tempmvt=arrtemp[1][chon-1];
					gotoxy(66,12);
					cout<<"                                                   ";
					gotoxy(66,12);
					cout<<tempmvt;
					getmavt=check_Vat_Tu(a.ds,tempmvt);
				}
			}
			
			// xuat menu chon
		}
		if( kbhit==72 )
		{
			if(temptenvt.length()>0)
			{
				xoa_Khung_Nhap(0);
				temptenvt.erase(temptenvt.end()-1 );
				gotoxy(66,16);
				cout<<"                                                   ";
				gotoxy(66,16);
				cout<<temptenvt;
				search_Goi_Y_Ten_Vat_Tu( a ,temptenvt, arrtemp);
				
				show_Goi_Y(arrtemp,index );
				soluonggoiy=index;
			}
			goto nhapmvt;
		}
	}while(kbhit!=13);
	
nhapsl:
	xoa_Khung_Nhap(0);
	HighLight();
	gotoxy(50,18);
	cout<< "                                                                    ";
	Normal();
	o_Nhap(50,19);
	gotoxy(51,20);
	cout<< "SO LUONG      |                                                   ";
	if(getmavt!=NULL)
	{
		gotoxy(105,20);
		cout<<getmavt->don_Vi_Tinh;
	}
	HighLight();
	gotoxy(50,22);
	cout<< "                                                                    ";
	Normal();
	o_Nhap(50,23);
	gotoxy(51,24);
	cout<< "DON GIA       |                                                   ";
	
	o_Nhap(50,27);
	gotoxy(51,28);
	cout<< "VAT (%)       |                                                   ";
	
	kbhit= nhap_Float(tempsl,66,20);
	if(kbhit==27)
	{
		return false;
	}
	if(kbhit==72)
	{
		gotoxy(66,20);
		cout<<"0";
		goto nhaptenvt;
	}
	if(kbhit==80)
	{
		if(tempsl==0)
		{
			gotoxy(66,20);
			cout<<"0";
		}
		
		goto nhapdg;
	}
nhapdg:
	kbhit=nhap_Int(tempdg,66,24);
	if(kbhit==27)
	{
		return false;
	}
	if(kbhit==72)
	{
		gotoxy(66,24);
		cout<<"0";
		goto nhapsl;
	}
	if(kbhit==80)
	{
		gotoxy(66,24);
		cout<<"0";
		goto nhapvat;
	}
nhapvat:
	kbhit=nhap_Float(tempvat,66,28);
	if(kbhit==27)
	{
		return false;
	}
	if(kbhit==72)
	{
		gotoxy(66,28);
		cout<<"0";
		goto nhapdg;
	}
	if(kbhit==80)
	{
		gotoxy(66,28);
		cout<<"0";
		goto nhapvat;
	}
	
	
	if(checkstring(tempmvt,20)==true)
	{
		Error("MA VAT TU KHONG DUNG !");
		goto nhapmvt;
	}
	if(getmavt==NULL)
	{
		Error("VAT TU KHONG TON TAI");
		goto nhapmvt;
	}
	//khach mua  
	Nocursortype();
	gotoxy(58,35);
	cout<<"ESC : THOAT";
	gotoxy(93,35);
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
			cthd.ma_Vat_Tu=tempmvt;
			cthd.don_Gia=tempdg;
			cthd.so_Luong=tempsl;
			cthd.VAT=tempvat;
			cthd.trang_Thai=true;
			cthd.tri_Gia=(cthd.don_Gia*cthd.so_Luong)+(((cthd.don_Gia*cthd.so_Luong)*cthd.VAT)/100);
			HighLight();
			gotoxy(58,35);
			cout<<"           ";
			gotoxy(93,35);
			cout<<"           ";
			Normal();
			return true;
		}
		if(kbhit==72)
		{
			goto nhapsl;
		}
	}while(true);
	

}
//searh hoa don theo loai
node_Hoa_Don* search_Hoa_Don(node_Hoa_Don* pHead,string loaiHD)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	else
	{
		for (node_Hoa_Don *k = pHead;k != NULL;k = k->pNext)
		{
			if (k->HD.loai==loaiHD)
			{
				return k;
			}
		}
	}
}
//tim node theo so hoa don
node_Hoa_Don* search_Hoa_Don_bysoHD(node_Hoa_Don* pHead,string num_HD)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	else
	{
		for (node_Hoa_Don *k = pHead;k != NULL;k = k->pNext)
		{
			if (k->HD.soHD==num_HD)
			{
				return k;
			}
		}
	}
}

//vat tu vao chi tiet hoa don
bool them_Chi_Tiet_HD(node_Hoa_Don* &p,ds_Vat_Tu &a)
{

	xoa_Man_Hinh();
	ve_Khung_Nhap(48,8);
	ve_Khung_Xuat_CTHD1();
	//note
	Vang_trang();
	gotoxy(11,36);
	cout<<"ESC       : THOAT       ";
	gotoxy(11,37);
	cout<<"LEN,XUONG : DIEU CHINH  ";
	Normal();
	
	
	HighLight();
	gotoxy(122,3);
	cout<<"|    Mavt           Ten           TT   So luong-Dvt      Don gia-VAT      |"; 
	Normal();	
	int thoat;
	int vitrixoa;
	int chon;
	bool run=true;
	while(run)
	{
		xoa_Khung_Nhapblue();
		Showcursortype();
		HighLight2();
		gotoxy(60,2);
		cout<<"                                         ";
		gotoxy(60,3);
		cout<<"            CHI TIET HOA DON             ";
		gotoxy(60,4);
		cout<<"                                         ";
		chi_Tiet_HD tam;

		bool checknhap=nhap_Chi_Tiet_HD(tam,a);
		// neu an esc de thoat ma chua co vat tu nao duoc them thi hoa don do cung khong duoc them
		// neu co 1 chi tiet duoc them thi them vao hoa don va luu
		if((checknhap==false))
		{
			bool out=o_Thoat("BAN CO MUON LUU HAY KHONG ?",79,15);
			if(out==true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		tree getmavt=check_Vat_Tu(a.ds,tam.ma_Vat_Tu);
		bool checkslt=check_So_Luong_Ton(tam,getmavt,p->HD.loai);
		if(checkslt==true)//co the them dc
		{
			//check xem vat tu nay da duoc them vao hoa don hay chua neu roi thi khong cho them nua ; co the xoa di hoac lap hoa don moi
			if(check_MVT_In_CTHD(p, tam.ma_Vat_Tu)==true)
			{
				Error("VAT TU NAY DA DUOC THEM");
				continue;
			}
			//check_MVT_In_CTHD(p, tam.ma_Vat_Tu);
			// add chi tiet hoa don vao node
			p->HD.dsCTHD.ds[p->HD.dsCTHD.n]=tam;
			p->HD.dsCTHD.n++;
			//in ra chi tiet hoa don den xoa
			show_CTHD_Temp(a,p,123,3);
		}
		else
		{
			continue;
		}
		//ve hinh nhap tiep hay khong hay xoa vat tu
		HighLight();
		gotoxy(55,42);
		cout<<"ESC   : THEM TIEP VAT TU";
		gotoxy(90,42);
		cout<<"ENTER : XOA VAT TU      ";
		//
		xoa_Khung_HD();
		//note
		Vang_trang();
		gotoxy(7,34);
		HighLight7() ;
		cout<<"XOA VAT TU TRONG CHI TIET HOA DON";
		Vang_trang();
		gotoxy(7,36);
		cout<<"ESC       : NHAP THEM VAT TU  ";
		gotoxy(7,37);
		cout<<"LEN,XUONG : CHON VAT TU DE XOA";
		Normal();
	
	
		Normal();
		Nocursortype();
		do
			{
				chon=menu_Quanly(chon_CTHD,p->HD.dsCTHD.n,3);
				vitrixoa=chon-1;
				if(chon!=-1)
				{
					int x;
					while(true)
					{
						xoa_Khung_HD();
						HighLight7() ;
						gotoxy(11,34);
						cout<<"BAN CO CHAC MUON XOA";
						gotoxy(15,36);
						cout<<"ESC  : HUY ";
						gotoxy(15,37);
						cout<<"ENTER: XOA ";
						Normal();
						x=getch();
						if(x==enter)
						{
							xoa_VT_of_CTHD(p->HD.dsCTHD,vitrixoa);
							index=0;
							Normal();
							xoa_Trong_Khung_Xuat_CTHD1();
							show_CTHD_Temp(a,p,123,3);
							gotoxy(121,5+(chon-1)*2);cout << " ";
							Normal();
							xoa_Khung_HD();
							//note
							Vang_trang();
							gotoxy(7,34);
							HighLight7() ;
							cout<<"XOA VAT TU TRONG CHI TIET HOA DON";
							Vang_trang();
							gotoxy(7,36);
							cout<<"ESC       : NHAP THEM VAT TU  ";
							gotoxy(7,37);
							cout<<"LEN,XUONG : CHON VAT TU DE XOA";
							Normal();
							break;
						}
						else if(x==Esc)
						{
							Normal();
							xoa_Khung_HD();
							break;
						}
						
					}
				}
				Normal();
			}while(chon!=-1);
			xoa_Khung_HD();
			//note
			Vang_trang();
			gotoxy(11,36);
			cout<<"ESC       : THOAT       ";
			gotoxy(11,37);
			cout<<"LEN,XUONG : DIEU CHINH  ";
			Normal();
			continue;
	}
	return true;
}
bool check_MVT_In_CTHD(node_Hoa_Don* p,string mavt)
{
	for(int i=0;i<p->HD.dsCTHD.n;i++)
	{
		if(p->HD.dsCTHD.ds[i].ma_Vat_Tu==mavt)
		{
			return true;
		}
	}
	return false;
}
void show_CTHD_Temp(ds_Vat_Tu a,node_Hoa_Don* p,int x,int y)
{
	
	//x trong lap hoa don =123 y=3
	//xtrong xuat hoa don =89 y=3
	int z=2;
	for(int i=0;i<p->HD.dsCTHD.n;i++)
	{
		
		
		tree getmavt=check_Vat_Tu(a.ds,p->HD.dsCTHD.ds[i].ma_Vat_Tu);
		
		gotoxy(x,y+i+z);
		cout<<p->HD.dsCTHD.ds[i].ma_Vat_Tu;
		gotoxy(x+13,y+i+z);
		cout<<getmavt->ten_Vat_Tu;
		gotoxy(x+33,y+i+z);

		if(p->HD.dsCTHD.ds[i].trang_Thai==1)
		{
			cout<<"Mua";
		}
		else
		{
			cout<<"Tra";
		}
		gotoxy(x+37,y+i+z);
		cout<<p->HD.dsCTHD.ds[i].so_Luong<<"-"<<getmavt->don_Vi_Tinh;
		gotoxy(x+56,y+i+z);
		cout<<p->HD.dsCTHD.ds[i].don_Gia<<"-"<<p->HD.dsCTHD.ds[i].VAT<<"%";
		if(x==90)
		{
			
			gotoxy(x+74,y+i+z);
			cout << std::setprecision(20);
			cout<<p->HD.dsCTHD.ds[i].tri_Gia;
			gotoxy(x+91,y+i+z);
			cout<<p->HD.dsCTHD.ds[i].so_Luong_Tra;
		}
		z++;
	}
	


}
// show cthd trong tra hang
void show_CTHD_Trahang(ds_Vat_Tu a,node_Hoa_Don* p,int x,int y)
{
	
	//x trong lap hoa don =123 y=3
	//xtrong xuat hoa don =89 y=3
	int z=2;
	for(int i=0;i<p->HD.dsCTHD.n;i++)
	{
		
		
		tree getmavt=check_Vat_Tu(a.ds,p->HD.dsCTHD.ds[i].ma_Vat_Tu);
		
		gotoxy(x,y+i+z);
		cout<<p->HD.dsCTHD.ds[i].ma_Vat_Tu;
		gotoxy(x+13,y+i+z);
		cout<<getmavt->ten_Vat_Tu;
		gotoxy(x+33,y+i+z);

		if(p->HD.dsCTHD.ds[i].trang_Thai==1)
		{
			cout<<"Mua";
		}
		else
		{
			cout<<"Tra";
		}
		gotoxy(x+37,y+i+z);
		cout<<p->HD.dsCTHD.ds[i].so_Luong<<"-"<<getmavt->don_Vi_Tinh;
		gotoxy(x+56,y+i+z);
		cout<<p->HD.dsCTHD.ds[i].don_Gia<<"-"<<p->HD.dsCTHD.ds[i].VAT<<"%";
		gotoxy(x+74,y+i+z);
		cout<<p->HD.dsCTHD.ds[i].so_Luong_Tra;
		z++;
	}
	


}
void xoa_VT_of_CTHD(ds_CT_HD &dsct,int chon)
{
	for(int i=chon;i<dsct.n-1;i++)
	{
		dsct.ds[i]=dsct.ds[i+1];
	}
	dsct.n--;
}


//true la co the them hoac xuat : false la so du trong kho khong du xe xuat ra
bool check_So_Luong_Ton(chi_Tiet_HD cthd,tree checkmavt,string loai)
{
	if(loai=="X")
	{
		if(checkmavt->so_Luong_Ton < cthd.so_Luong)
		{
			Error("KHONG DU HANG DE XUAT");
			gotoxy(60,32);
			cout<<"VAT TU "<<checkmavt->ma_Vat_Tu<<" SO LUONG TON "<<checkmavt->so_Luong_Ton<<endl;
			getch();
			return false;
		}
	}
	return true;
}
void update_So_Luong_Ton(node_Hoa_Don* p,tree &getmavt)
{
	if(p->HD.loai=="X")
	{
		getmavt->so_Luong_Ton -= p->HD.dsCTHD.ds[p->HD.dsCTHD.n-1].so_Luong;
	}
	else if(p->HD.loai=="N")
	{
		getmavt->so_Luong_Ton += p->HD.dsCTHD.ds[p->HD.dsCTHD.n-1].so_Luong;
	}
	getmavt->used+=1;
}

bool nhap_Ngay(date &a,int x,int y)
{
	int sukien;
	int sotemp=0;
	gotoxy(x,y);
	cout<<"  /  /     ";
	//ngay
	lap1:
	do
	{
		gotoxy(x,y);
		sukien=getch();
		//dung lai
	}while(sukien<48 || sukien>57);
	cout<<sukien-48;
	sotemp=sukien-48;
	lap2:
	do
	{
		gotoxy(x+1,y);
		sukien=getch();
		if(sukien==8)
		{
			gotoxy(x,y);
			cout<<" ";
			goto lap1;
		}
	}while(sukien<48 || sukien>57);
	cout<<sukien-48;
	a.ngay=(sotemp*10)+(sukien-48);
	//thang
	lap3:
	do
	{
		gotoxy(x+3,y);
		sukien=getch();
		if(sukien==8)
		{
			gotoxy(x+1,y);
			cout<<" ";
			goto lap2;
		}
	}while(sukien<48 || sukien>57);
	cout<<sukien-48;
	sotemp=sukien-48;
	lap4:
	do
	{
		gotoxy(x+4,y);
		sukien=getch();
		if(sukien==8)
		{
			gotoxy(x+3,y);
			cout<<" ";
			goto lap3;
		}
	}while(sukien<48 || sukien>57);
	cout<<sukien-48;
	a.thang=(sotemp*10)+(sukien-48);
	//nam
	lap5:
	sotemp=0;
	do
	{
		gotoxy(x+6,y);
		sukien=getch();
		if(sukien==8)
		{
			gotoxy(x+4,y);
			cout<<" ";
			goto lap4;
		}
	}while(sukien<48 || sukien>57);
	cout<<sukien-48;
	sotemp= sotemp + sukien-48;
	lap6:
	do
	{
		gotoxy(x+7,y);
		sukien=getch();
		if(sukien==8)
		{
			gotoxy(x+6,y);
			cout<<" ";
			goto lap5;
		}
	}while(sukien<48 || sukien>57);
	cout<<sukien-48;
	sotemp=(sotemp*10)+(sukien-48);
	lap7:
	do
	{
		gotoxy(x+8,y);
		sukien=getch();
		if(sukien==8)
		{
			gotoxy(x+7,y);
			cout<<" ";
			goto lap6;
		}
	}while(sukien<48 || sukien>57);
	cout<<sukien-48;
	sotemp=(sotemp*10)+(sukien-48);
	lap8:
	do
	{
		gotoxy(x+9,y);
		sukien=getch();
		if(sukien==8)
		{
			gotoxy(x+8,y);
			cout<<" ";
			goto lap7;
		}
	}while(sukien<48 || sukien>57);
	cout<<sukien-48;
	sotemp=(sotemp*10)+(sukien-48);
	a.nam=sotemp;
	sukien=getch();
	if(sukien==8)
	{
		gotoxy(x+9,y);
		cout<<" ";
		goto lap8;
	}
	bool temp=check_Date(a);
	if(temp==false)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}
bool xuat_Ngay(date a)
{
	cout<<a.ngay<<"/"<<a.thang<<"/"<<a.nam;
}
// check chua co hoa don nao
// 0 la chua co 1 la co roi
int check_Null_HD(ds_Nhan_Vien b)
{
	for(int i=0;i<b.n;i++)
	{
		if(b.ds[i]->ds_HD.pHead!=NULL)
		{
			return 1;
		}	
	}
	return 0;
}
node_Hoa_Don* search_So_HD(ds_Nhan_Vien b,string num_HD)
{
	for(int i=0;i<b.n;i++)
	{
		if(b.ds[i]->ds_HD.pHead==NULL)
		{
			continue;
		}
		else
		{
			for (node_Hoa_Don* k = b.ds[i]->ds_HD.pHead;k != NULL;k = k->pNext)
			{
				if(k->HD.soHD==num_HD)
				{
					return k;
				}
			}
		}
	}
	return NULL;
}
int search_id_NV_By_So_HD(ds_Nhan_Vien b,string num_HD)
{
	for(int i=0;i<b.n;i++)
	{
		if(b.ds[i]->ds_HD.pHead==NULL)
		{
			continue;
		}
		else
		{
			for (node_Hoa_Don* k = b.ds[i]->ds_HD.pHead;k != NULL;k = k->pNext)
			{
				if(k->HD.soHD==num_HD)
				{
					return i;
				}
			}
		}
	}
	return -1;
}
bool check_3_Ngay(date a ,date b)
{
	int countday=count_Day( a)-count_Day( b);
	if(a.nam==b.nam)
	{
		if(countday<=3)
		{
			return true;
		}
		else
		{
			Error("	QUA THOI HAN TRA HANG !");
		}
	}
	else
	{
		Error("NGAY HIEN TAI KHONG THE BE HON NGAY LAP HOA DON");
		return false;
	}
	return false;
}
//
int count_Day(date a)
{
	int count=0;
	int thang1=31;
	int thang2;
	int thang3=31;
	int thang4=30;
	int thang5=31;
	int thang6=30;
	int thang7=31;
	int thang8=31;
	int thang9=30;
	int thang10=31;
	int thang11=30;
	int thang12=31;
	if((((a.nam%4)==0)&&(a.nam%100)!=0)||(a.nam%400)==0)// nam nhuan
	{
		thang2=29;
	}
	else// khong nhuan
	{
		thang2=28;
	}
	//count day
	if(a.thang==1)
	{
		return count+=a.ngay;
	}
	if(a.thang==2)
	{
		return count=thang1+a.ngay;
	}
	if(a.thang==3)
	{
		return count=thang1+thang2+a.ngay;
	}
	if(a.thang==4)
	{
		return count=thang1+thang2+thang3+a.ngay;
	}
	if(a.thang==5)
	{
		return count=thang1+thang2+thang3+thang4+a.ngay;
	}
	if(a.thang==6)
	{
		return count=thang1+thang2+thang3+thang4+thang5+a.ngay;
	}
	if(a.thang==7)
	{
		return count=thang1+thang2+thang3+thang4+thang5+thang6+a.ngay;
	}
	if(a.thang==8)
	{
		return count=thang1+thang2+thang3+thang4+thang5+thang6+thang7+a.ngay;
	}
	if(a.thang==9)
	{
		return count=thang1+thang2+thang3+thang4+thang5+thang6+thang7+thang8+a.ngay;
	}
	if(a.thang==10)
	{
		return count=thang1+thang2+thang3+thang4+thang5+thang6+thang7+thang8+thang9+a.ngay;
	}
	if(a.thang==11)
	{
		return count=thang1+thang2+thang3+thang4+thang5+thang6+thang7+thang8+thang9+thang10+a.ngay;
	}
	if(a.thang==12)
	{
		return count=thang1+thang2+thang3+thang4+thang5+thang6+thang7+thang8+thang9+thang10+thang11+a.ngay;
	}
	
} 
// check xem ngay be hay lon hon -1 be hon 1 lon hon 0 bang nhau
int day_Compare(date a,date b)
{
	if(a.nam>b.nam)
	{
		return 1;
	}
	else if(a.nam<b.nam)
	{
		return -1;
	}
	else
	{
		if(a.thang>b.thang)
		{
			return 1;
		}
		else if(a.thang<b.thang)
		{
			return -1;
		}
		else
		{
			if(a.ngay>b.ngay)
			{
				return 1;
			}
			else if(a.ngay<b.ngay)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
}
// tra hang cau f

void tra_Hang(ds_Nhan_Vien &dsnv,ds_Vat_Tu &a)
{
	//note
	Vang_trang();
	gotoxy(11,36);
	cout<<"ESC       : THOAT       ";
	gotoxy(11,37);
	cout<<"LEN,XUONG : DIEU CHINH  ";
	Normal();
	
	
	date currentdate;
	node_Hoa_Don* hoadon; 
	string num_HD;
	bool checkday;
	HighLight2();
	gotoxy(60,2);
	cout<<"                                         ";
	gotoxy(60,3);
	cout<<"               TRA HANG                  ";
	gotoxy(60,4);
	cout<<"                                         ";
	Normal();
	o_Nhap(92,18);
	gotoxy(93,19);
	cout<< "SO HOA DON    |                                                   ";
	
	o_Nhap(92,22);
	gotoxy(93,23);
	cout<< "NGAY HIEN TAI |                                                   ";
	Normal();
	
	string tempmhd;
	getcurrentdate(currentdate);
	gotoxy(108,23);
	xuat_Ngay(currentdate);
	int kbhit;
nhaphd: 
		kbhit=nhap_String(tempmhd,108,19);
		if(kbhit==27)
		{
			
			return;
		}
		if(kbhit==72)
		{
			gotoxy(108,19);
			cout<<"                                                   ";
			goto nhaphd;
		}
		if(kbhit==80)
		{
			gotoxy(108,19);
			cout<<"                                                   ";
			gotoxy(108,19);
			cout<<tempmhd;
		}
 
	hoadon = search_So_HD(dsnv,tempmhd);
	
	if(hoadon==NULL)
		{
			Error("KHONG CO HOA DON NAY !");
			goto nhaphd;
		}
	hoadon->HD.soHD=tempmhd;
	if(hoadon!=NULL)
	{
		checkday=check_3_Ngay(currentdate,hoadon->HD.ngay_Lap);
		if(checkday==true)
		{
			xoa_Man_Hinh2();
			
			o_Nhap(47,8);
			gotoxy(49,9);
			cout<< "SO HOA DON    |                                                  ";
			gotoxy(67,9);
			cout<<tempmhd;
			o_Nhap(47,12);
			gotoxy(49,13);
			cout<< "NGAY LAP      |                                                  ";
			gotoxy(67,13);
			xuat_Ngay(hoadon->HD.ngay_Lap);
			
			ve_Khung_Xuat_CTHD_Trahang();
			HighLight();
			gotoxy(116,3);
			cout<<"|    Mavt           Ten           TT   So luong-Dvt      Don gia-VAT       SLtra |"; 
			Normal();
			bool thoat=true;
			//co the tra hang
			int chon;
			//in vat tu ra man hinh
			
			//di chuyen con tro chuot de chon vat tu can tra
			while(thoat==true)
			{
				xoa_Khung_HD();
				//note
				Vang_trang();
				gotoxy(7,34);
				HighLight7() ;
				cout<<"           TRA HANG              ";
				Vang_trang();
				gotoxy(7,36);
				cout<<"ESC       : CHON LAI          ";
				gotoxy(7,37);
				cout<<"LEN,XUONG : CHON VAT TU DE TRA";
				Normal();
	
				show_CTHD_Trahang(a,hoadon,117,3);
				chon=menu_Quanly(chon_CTHD,hoadon->HD.dsCTHD.n,7);
				Normal();
				if(chon!=-1)
				{
					chon-=1;
					
					tra_Hang_CTHD(hoadon, a,chon);
					//xoa man hinh 
					xoa_Trong_Khung_Xuat_CTHD_Trahang();
				}
				if(chon==-1)
				{
					bool out =o_Thoat("BAN CO MUON THOAT KHONG",79,15);
					if(out==true)
					{
						int numNV=search_id_NV_By_So_HD(dsnv, tempmhd);
						//update hoa don 
						
						update_Tra_Hang_in_CTHD(hoadon->HD.dsCTHD);
						
						update_Tra_Hang(dsnv.ds[numNV]->ds_HD,hoadon);
						
						
						
						
						
						xoa_Khung_HD();
						return;
					}
					else
					{
						//xoa o thoat
						Normal();
						for(int i=0;i<10;i++)
						{
							gotoxy(78,14+1+i);
							cout<<"                                            ";
							
						}
						ve_Khung_Xuat_CTHD_Trahang();
					}
					
				}
				
			}			
		}
	}		
}
//update hoa don sau khi tra hang xoa cac vat tu tra het va xoa hoa don neu tra het hang
void update_Tra_Hang(ds_Hoa_Don &dsh,node_Hoa_Don* &hoadon)
{
	if(hoadon->HD.dsCTHD.n==0)//thi xoa hoa don
	{
		//xoa
		for (node_Hoa_Don *k = dsh.pHead;k != NULL;k = k->pNext)
		{
			if(k->HD.soHD==hoadon->HD.soHD)// neu hoa don can xoa o dau danh sach
			{
				dsh.pHead=k->pNext;
				delete hoadon;
				dsh.n-=1;
				break;
			}
			if(k->pNext==NULL)// neu chi co 1 hoa don
			{
				delete hoadon;
				dsh.n-=1;
				break;
			}
			if(k->pNext->HD.soHD==hoadon->HD.soHD)// neu khac 2 truong hop dau
			{
				k->pNext=hoadon->pNext;
				dsh.n-=1;
				delete hoadon;
				break;
			}
		}
	}
	
}
int find_VT_To_Del_in_Tra_Hang(ds_CT_HD ct)
{
	for(int i=0;i<ct.n;i++)
	{
		if(ct.ds[i].so_Luong==ct.ds[i].so_Luong_Tra)
		{
			return i;
		}
	}
	return -1;
}
int find_SL_To_Del(ds_CT_HD ct)
{
	int sl=0;
	for(int i=0;i<ct.n;i++)
	{
		if(ct.ds[i].so_Luong==ct.ds[i].so_Luong_Tra)
		{
			sl++;
		}
	}
	return sl;
}
void update_Tra_Hang_in_CTHD(ds_CT_HD &ct)
{
	int sl=find_SL_To_Del(ct);
	int findind=find_VT_To_Del_in_Tra_Hang( ct);
	if(findind==-1)
	{
		return;
	}
	else
	{
		for(int k=0;k<sl;k++)
		{
			for(int i=findind;i<ct.n-1;i++)
			{
				ct.ds[i]=ct.ds[i+1];
			}
			ct.n-=1;
		}
			
	}
	
}
void tra_Hang_CTHD(node_Hoa_Don* &hoadon,ds_Vat_Tu &a,int chon)
{
	
	for(int i=0;i<hoadon->HD.dsCTHD.n;i++)
	{
		if(i==chon)
		{
			if(hoadon->HD.dsCTHD.ds[i].so_Luong==hoadon->HD.dsCTHD.ds[i].so_Luong_Tra)
			{
				Error("VAT TU NAY DA TRA HET !");
				break;
			}
			int soluongtra;
			o_Nhap(47,15);
			gotoxy(49,16);
			cout<<"SL CAN TRA    |                                                  ";
nhapslt:
			Normal();
			Showcursortype();
			int kbhit=nhap_Int(soluongtra,67,16);
			if(kbhit==27)
			{
				Nocursortype();
				Normal();
				gotoxy(47,15);
				cout<<"                                                                    ";
				gotoxy(47,16);
				cout<<"                                                                    ";
				gotoxy(47,17);
				cout<<"                                                                    ";
				
				return;
			}
			if(kbhit==72||kbhit==80)
			{
				
				goto nhapslt;
			}
			// neu so luong tra cong voi so luong da tra lon hon so luong mua thi khong the tra hang nua
			if(soluongtra+hoadon->HD.dsCTHD.ds[i].so_Luong_Tra>hoadon->HD.dsCTHD.ds[i].so_Luong)
			{
				Normal();	
				Error("VUOT QUA SO LUONG MUA !");
				gotoxy(64,16);
				cout<<"                                                  ";
				goto nhapslt;
			}
			else
			{
				tree getmavt=check_Vat_Tu(a.ds,hoadon->HD.dsCTHD.ds[i].ma_Vat_Tu);
				
				if(soluongtra+hoadon->HD.dsCTHD.ds[i].so_Luong_Tra==hoadon->HD.dsCTHD.ds[i].so_Luong)
				{
					// neu tra het thi chuyen trang thai cua vat tu trong chi tiet hoa don
					hoadon->HD.dsCTHD.ds[i].trang_Thai=false;
					getmavt->used-=1;
				}
				//neu tra < so luong mua thi tru vao so luong mua con tra het thi slm =0 va hang do la hang tra
				// neu tra hang thi so luong tra da be hon hoac bang so luong mua nen
				// cap nhat so luong tra so luong mua khong doi tinhs toans se tinh lai au
				// neu tra het hang thi trang thai sex chuyen thanh false
				hoadon->HD.dsCTHD.ds[i].so_Luong_Tra+=soluongtra;
				Nocursortype();
				Normal();
				gotoxy(47,15);
				cout<<"                                                                     ";
				gotoxy(47,16);
				cout<<"                                                                     ";
				gotoxy(47,17);
				cout<<"                                                                     ";
				
				if(hoadon->HD.loai=="X")
				{
					getmavt->so_Luong_Ton+=soluongtra;
				} 
				else
				{
					getmavt->so_Luong_Ton-=soluongtra;	
				}
				Nocursortype();
				Normal();
				gotoxy(47,15);
				cout<<"                                                                     ";
				gotoxy(47,16);
				cout<<"                                                                     ";
				gotoxy(47,17);
				cout<<"                                                                     ";
				
				// update so gia tri cua hoa don 
				long double chuathue=(hoadon->HD.dsCTHD.ds[i].so_Luong-hoadon->HD.dsCTHD.ds[i].so_Luong_Tra)*hoadon->HD.dsCTHD.ds[i].don_Gia;
				hoadon->HD.dsCTHD.ds[i].tri_Gia=chuathue+((chuathue*hoadon->HD.dsCTHD.ds[i].VAT)/100);;
				return;
			}
				
			
     	}
	} 
}
//in hoa don so hoa don do nguoi dung nhap vao
void in_Hoa_Don(ds_Nhan_Vien dsnv,ds_Vat_Tu a)
{
	
	string mahd;
	o_Nhap(92,18);
	gotoxy(93,19);
	cout<< "SO HOA DON    |                                                   ";
nhaphd: 
		int kbhit=nhap_String(mahd,108,19);
		if(kbhit==27)
		{
			
			return;
		}
		if(kbhit==72)
		{
			gotoxy(108,19);
			cout<<"                                                   ";
			goto nhaphd;
		}
		if(kbhit==80)
		{
			gotoxy(108,19);
			cout<<"                                                   ";
			gotoxy(108,19);
			cout<<mahd;
			goto nhaphd;
		}
	Normal();
	int vitrinv=search_id_NV_By_So_HD(dsnv,mahd);
	node_Hoa_Don* hoadon; 
	hoadon = search_So_HD(dsnv,mahd);
	if(hoadon==NULL)
	{
		Error("KHONG TIM THAY HOA DON !");
		goto nhaphd;
	}
	
	if(hoadon!=NULL)
	{
		xoa_Man_Hinh2();
		HighLight();
		gotoxy(50,6);
		cout<<"SO HOA DON   |                        ";
		gotoxy(64,6);
		cout<<mahd;
		gotoxy(50,8);
		cout<<"LOAI HOA DON |                        ";
		gotoxy(50,9);
		cout<<"NGAY LAP     |                        ";
		gotoxy(70,8);
		if(hoadon->HD.loai=="X")
		{
			cout<<"XUAT";
		}
		else
		{
			cout<<"NHAP";
		}
		gotoxy(50,10);
		cout<<"NGUOI LAP    |                        ";
		gotoxy(64,9);
		xuat_Ngay(hoadon->HD.ngay_Lap);
		gotoxy(64,10);
		cout<<dsnv.ds[vitrinv]->ho<<" "<<dsnv.ds[vitrinv]->ten;
		
		Nocursortype();
		HighLight6();
		gotoxy(125,2);
		cout<<"CHI TIET HOA DON      :   "<<mahd;
		HighLight();
		gotoxy(89,3);
		cout<<"|    Mavt           Ten           TT   So luong-Dvt      Don gia-VAT         Tri gia (dong)   SLtra  |";
		Normal();
		ve_Khung_Xuat_CTHD();
		show_CTHD_Temp(a,hoadon,90,3);
		Xanhla () ;
		gotoxy(90,45);
		cout<<"TONG TIEN: ";
		long double total=tinh_Tien_HD(hoadon);
		cout << std::setprecision(20);
		cout<<total;
		
		doc_So((int)total,90,46);
		cout<<"Dong Chan ";
		Normal();
		
	
	}
	getch();
	Showcursortype();
}
long double tinh_Tien_HD(node_Hoa_Don* hoadon)
{
	long double total=0;
	for(int i=0;i<hoadon->HD.dsCTHD.n;i++)
	{
		if(hoadon->HD.dsCTHD.ds[i].trang_Thai==true)
		{
			total+=hoadon->HD.dsCTHD.ds[i].tri_Gia;
		}
		else
		{
			total-=hoadon->HD.dsCTHD.ds[i].tri_Gia;
		}
	}
	return total;
}
// cau h
void in_HD_DTD(ds_Nhan_Vien dsnv,ds_Vat_Tu a)
{
	//day_Compare(date a,date b)
	date fromdate;
	date todate;
	int temp;
	o_Nhap(92,14);
	gotoxy(93,15);
	cout<< "MA NHAN VIEN  |                                                   ";
	
	o_Nhap(92,18);
	gotoxy(93,19);
	cout<< "TU NGAY       |                                                   ";
	
	o_Nhap(92,22);
	gotoxy(93,23);
	cout<< "DEN NGAY      |                                                   ";
nhapmnv:
	int kbhit=nhap_Int(temp,108,15);
	if(kbhit==27)
	{
		return;
	}
	if(kbhit==72)
	{
		goto nhapmnv;
	}
	if(kbhit==80)
	{
		goto nhapn1;
	}
nhapn1:
	bool checkngay =nhap_Ngay(fromdate,108,19);
	if(checkngay==false)
	{
		Error("NGAY LOI");
		goto nhapn1;
	}
nhapn2:

	checkngay =nhap_Ngay(todate,108,23);
	if(checkngay==false)
	{
		Error("NGAY LOI");
		goto nhapn2;
	}
	if(day_Compare(todate,fromdate)==-1)
	{
		Error("KHOANG THOI GIAN KHONG DUNG");
		goto nhapn1;
	}
	int check=check_Nhan_Vien(dsnv,temp);
	if(check==-1)
	{
		Error("KHONG TIM THAY NHAN VIEN ");
		goto nhapmnv;
	}
	else
	{	
	
		Nocursortype();
		compare_Date_In_DSCTHD( dsnv.ds[check],  a, fromdate, todate);
		
		
	}
	
}
// in hoa don cua mot nhan vien trong danh sach
void in_HD_DTD_in_DS(ds_Nhan_Vien dsnv,ds_Vat_Tu a,int tempmnv)
{
	//day_Compare(date a,date b)
	date fromdate;
	fromdate.ngay=1;
	fromdate.thang=1;
	fromdate.nam=1;
	date todate;
	getcurrentdate(todate);
	int temp=tempmnv;
	int check=check_Nhan_Vien(dsnv,temp);

	{	
	
		Nocursortype();
		compare_Date_In_DSCTHD( dsnv.ds[check],  a, fromdate, todate);
		
		
	}
	
}
void compare_Date_In_DSCTHD(nhan_Vien* nv, ds_Vat_Tu a,date fromdate,date todate)
{
	HighLight6();
	gotoxy(80,1);
	cout<<"                                                                   ";
	gotoxy(90,1);
	cout<<"BANG LIET KE HOA DON TRONG MOT KHOANG THOI GIAN";
	gotoxy(80,2);
	cout<<"                                                                   ";
	gotoxy(100,2);
	xuat_Ngay(fromdate);
	gotoxy(120,2);
	xuat_Ngay(todate);
	gotoxy(80,3);
	cout<<"                                                                   ";
	gotoxy(105,3);
	cout<<nv->ho<<" "<<nv->ten; 
	gotoxy(50,4);
	HighLight(); 
	cout<<"|  So hoa don         Ngay lap     Loai     Mavt           Ten           TT   So luong-Dvt      Don gia-VAT       Tri gia (dong)       SLtra|";
	Normal();
	
	string* arrtemp = new string[nv->ds_HD.n];
	bool checkFDTD=find_Date_To_Date(nv->ds_HD.pHead, arrtemp, fromdate,todate);
	// xuat chi tiet tung hoa don ra man hinh theo trang
	if(checkFDTD==true)
	{
		xoa_Man_Hinh2();
		show_CTHD_Page_DTD(nv,a,arrtemp);
	}
	else
	{
		xoa_Man_Hinh2();
		gotoxy(95,20);
		HighLight3();
		cout<<"======== KHONG CO HOA DON NAO =======";
		Normal();
		getch();
	}
	delete[] arrtemp;
	index=0;
}
bool find_Date_To_Date(node_Hoa_Don* pHead,string* &arrtemp,date fromdate,date todate)
{
	index=0;
	bool check;
	if (pHead == NULL)
	{
		return false ;
	}
	else
	{
		for (node_Hoa_Don *k = pHead;k != NULL;k = k->pNext)
		{
			if ((day_Compare(fromdate,k->HD.ngay_Lap)==-1||day_Compare(fromdate,k->HD.ngay_Lap)==0) && (day_Compare(todate,k->HD.ngay_Lap)==1||day_Compare(todate,k->HD.ngay_Lap)==0))
			{
//				ve_Khung_Xuat_CTHD3();
//				show_CTHD_Temp(a,k,90,4);
				arrtemp[index]=k->HD.soHD;
				index++;
				check=true;
			}
		}
		if(index==0)
		{
			return false;
		}
	}
	return check;
}
void show_CTHD_Page_DTD(nhan_Vien* nv,ds_Vat_Tu a,string* arrtemp)
{
	node_Hoa_Don* hd;
	int currentpage=1;
	int  maxpage=index;
	ve_Khung_Xuat_CTHD3();
	hd = search_Hoa_Don_bysoHD(nv->ds_HD.pHead,arrtemp[currentpage-1]);
	show_Info_DTD(hd->HD);
	show_CTHD_Temp(a,hd,90,4);
	Xanhla () ;
	gotoxy(60,46);
	cout<<"TONG TIEN: ";
	long double total=tinh_Tien_HD(nv->ds_HD.pHead);
	cout << std::setprecision(20);
	cout<<total;
	doc_So((int)total,125,46);
	cout<<"Dong Chan ";
	Normal();
	while(true)
	{
		gotoxy(50,3);
		cout<<currentpage<<"/"<<maxpage;
		int kbhit=getch();
		if(kbhit==27)
		{
			return;
		}
		if(kbhit==PD)
		{
			if(currentpage<maxpage)
			{
				xoa_Khung_Xuat3();
				currentpage++;
				hd = search_Hoa_Don_bysoHD(nv->ds_HD.pHead,arrtemp[currentpage-1]);
				show_Info_DTD(hd->HD);
				show_CTHD_Temp(a,hd,90,4);
				Xanhla () ;
				gotoxy(60,46);
				cout<<"TONG TIEN:                                                                                                                                ";
				long double total=tinh_Tien_HD(hd);
				gotoxy(71,46);
				cout << std::setprecision(20);
				cout<<total;
				doc_So((int)total,125,46);
				cout<<"Dong Chan ";
				Normal();
			}
		}
		if(kbhit==PU)
		{
			if(currentpage>1)
			{
				xoa_Khung_Xuat3();
				currentpage--;
				hd = search_Hoa_Don_bysoHD(nv->ds_HD.pHead,arrtemp[currentpage-1]);
				show_Info_DTD(hd->HD);
				show_CTHD_Temp(a,hd,90,4);
				Xanhla () ;
				gotoxy(60,46);
				cout<<"TONG TIEN:                                                                                                                                ";
				
				long double total=tinh_Tien_HD(hd);
				gotoxy(71,46);
				cout << std::setprecision(20);
				cout<<total;
				doc_So((int)total,125,46);
				cout<<"Dong Chan ";
				Normal();
			}
		}
	}
}
void show_Info_DTD(hoa_Don a)
{
	gotoxy(51,6);
	cout<<a.soHD;
	gotoxy(51+21,6);
	xuat_Ngay(a.ngay_Lap);
	gotoxy(51+34,6);
	if(a.loai=="N")
	{
		cout<<"Nhap";
	}
	else cout<<"Xuat";
}
// thong ke doanh thu cau i
void thong_Ke_Doanh_Thu(ds_Nhan_Vien b,ds_Vat_Tu a)
{
	
	//thong bao tren o note
	Vang_trang();
	gotoxy(7,36);
	cout<<"ESC     : THOAT                  ";
	gotoxy(7,37);
	cout<<"ENTER   :CHON VA XEM HD CUA THANG";
	Normal();
	
	
	xoa_Man_Hinh();
	HighLight2();
	gotoxy(95,2);
	cout<<"                                         ";
	gotoxy(95,3);
	cout<<"          DOANH THU THEO THANG           ";
	gotoxy(95,4);
	cout<<"                                         ";
	
	Normal();
	int tempnam;
	o_Nhap(79,14);
	gotoxy(80,15);
	cout<< "NAM           |                                                   ";
nhapnam:
	int kbhit=nhap_Int(tempnam,95,15);
	if(kbhit==27)
	{
		return;
	}
	if(kbhit==72||kbhit==80)
	{
		gotoxy(95,15);
		cout<<"                                                   ";
		gotoxy(95,15);
		cout<<"0";
		goto nhapnam;
	}

	Nocursortype();
	xoa_Man_Hinh2();
show:	
	HighLight2();
	gotoxy(95,5);
	cout<<"              NAM     "<<tempnam<<"               ";
	Normal();
	long double totalnam=0;
	long double totalthang[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	
	ve_Khung_Xuat_Doanhthu();
	tinh_Doanh_Thu( b, tempnam,  totalthang);
	show_Doanh_Thu( totalthang);
	
	tinh_Doanh_Thu_Nam( totalnam, totalthang);
	Xanhla () ;
	gotoxy(80,36);
	cout<<"DOANH THU NAM  ";
	gotoxy(80,37);
	cout<<"BANG CHU       ";
	gotoxy(102,36);
	cout << std::setprecision(20);
	cout<<totalnam;
	int doc=(int)totalnam;
	doc_So(doc,102,37);
	cout<<"Dong Chan ";
	Normal();
	int chonmonth;
	do
	{
		kbhit=getch();
	}
	while(kbhit!=enter&&kbhit!=Esc);
	if(kbhit==enter)
	{
		chonmonth=menu_Quanly(chon_CTHD,12,5);
		Normal();
	}
	else if(kbhit==Esc)
	{
		return;
	}
	else
	{
		goto show;
	}
	if(chonmonth>0)
	{
		int slHD=count_SHD_Month(b, chonmonth,tempnam);
		if(slHD==0)
		{
			gotoxy(wherex()-1,wherey());
			cout<<" ";
			Error("KHONG CO HOA DON NAO");
			
			goto show;
		}
		xoa_Man_Hinh();
		ve_Khung_Xuat_CTHD();
		
		string arrtemp[slHD];
		get_SHD_Month( b, arrtemp, chonmonth,tempnam);// lay cac so hoa don cua thang trong nam
		
		int curHD=0;
xemhd:
		while(true)
		{
		
			int vitrinv=search_id_NV_By_So_HD(b,arrtemp[curHD]);
			node_Hoa_Don* hoadon; 
			hoadon = search_So_HD(b,arrtemp[curHD]);
			if(hoadon!=NULL)
			{
				Normal();
				gotoxy(50,5);
				cout<<"         ";
				gotoxy(50,5);
				cout<<curHD+1<<"/"<<slHD;
				HighLight();
				gotoxy(50,6);
				cout<<"SO HOA DON   |                        ";
				gotoxy(64,6);
				cout<<arrtemp[curHD];
				gotoxy(50,8);
				cout<<"LOAI HOA DON |                        ";
				gotoxy(50,9);
				cout<<"NGAY LAP     |                        ";
				gotoxy(70,8);
				if(hoadon->HD.loai=="X")
				{
					cout<<"XUAT";
				}
				else
				{
					cout<<"NHAP";
				}
				gotoxy(50,10);
				cout<<"NGUOI LAP    |                        ";
				gotoxy(64,9);
				xuat_Ngay(hoadon->HD.ngay_Lap);
				gotoxy(64,10);
				cout<<b.ds[vitrinv]->ho<<" "<<b.ds[vitrinv]->ten;
				
				Nocursortype();
				HighLight6();
				gotoxy(125,2);
				cout<<"CHI TIET HOA DON      :   "<<arrtemp[curHD];
				HighLight();
				gotoxy(89,3);
				cout<<"|    Mavt           Ten           TT   So luong-Dvt      Don gia-VAT         Tri gia (dong)    SLtra  |";
				Normal();
				// xoa khung
				xoa_Khung_Xuat_CTHD_Month();
				show_CTHD_Temp(a,hoadon,90,3);
				Xanhla () ;
				gotoxy(90,45);
				cout<<"                                                                                                           ";
				gotoxy(90,45);
				cout<<"TONG TIEN: ";
				long double total=tinh_Tien_HD(hoadon);
				cout << std::setprecision(20);
				cout<<total;
				gotoxy(90,46);
				cout<<"                                                                                                           ";
				doc_So((int)total,90,46);
				cout<<"Dong Chan ";
				Normal();
				
			
			}
khongxuat://neu da o hai dau cua danh sach thi khong xuat nua
			do
			{
				kbhit= getch();
			}
			while(kbhit!=Esc&&kbhit!=PU&&kbhit!=PD);
			if(kbhit==Esc)
			{
				xoa_Man_Hinh();
				HighLight2();
				gotoxy(95,2);
				cout<<"                                         ";
				gotoxy(95,3);
				cout<<"          DOANH THU THEO THANG           ";
				gotoxy(95,4);
				cout<<"                                         ";
				
				Normal();
				
				goto show;
			}
			if(kbhit==PU)
			{
				if(curHD>0)
				{
					curHD--;
					goto xemhd;
				}
				else
				{
					goto khongxuat;
				}
			
			}
			else if(kbhit==PD)
			{
				if(curHD<slHD-1)
				{
					curHD++;
					goto xemhd;
				}
				else
				{
					goto khongxuat;
				}
			
			}
		}
			
		// in ra tat ca hoa don co trong thang do cua nam dang xem
		//++tim tat ca cac hoa don co cung thang va cung nam cho vao danh sachva tim duoc ma nhan vien
		//=> xuat ra theo tung nhan vien
		//
		
	}
	else
	{
		gotoxy(wherex()-1,wherey());
		cout<<" ";
		goto show;
	}
	Showcursortype();
}
int count_SHD_Month(ds_Nhan_Vien b,int month,int year)
{
	int dem=0;
	for(int i=0;i<b.n;i++)
	{
		if (b.ds[i]->ds_HD.pHead == NULL)
		{
			 continue;
		}
		else
		{
			for (node_Hoa_Don *k = b.ds[i]->ds_HD.pHead;k != NULL;k = k->pNext)
			{
				if(k->HD.ngay_Lap.nam==year)
				{
					if(k->HD.ngay_Lap.thang==month)
					{
						dem++;
					}
				}
			}
		}
	}
	return dem;	
}

void get_SHD_Month(ds_Nhan_Vien b,string arrtemp[],int month,int year)
{
	index=0;
	for(int i=0;i<b.n;i++)
	{
		if (b.ds[i]->ds_HD.pHead == NULL)
		{
			 continue;
		}
		else
		{
			for (node_Hoa_Don *k = b.ds[i]->ds_HD.pHead;k != NULL;k = k->pNext)
			{
				if(k->HD.ngay_Lap.nam==year)
				{
					if(k->HD.ngay_Lap.thang==month)
					{
						arrtemp[index]=k->HD.soHD;
						index++;
					}
				}
			}
		}
	}
	index=0;
}

void tinh_Doanh_Thu(ds_Nhan_Vien b,int tempnam,long double total[])
{
	for(int i=0;i<b.n;i++)
	{
		if (b.ds[i]->ds_HD.pHead == NULL)
		{
			 continue;
		}
		else
		{
			for (node_Hoa_Don *k = b.ds[i]->ds_HD.pHead;k != NULL;k = k->pNext)
			{
				if(k->HD.ngay_Lap.nam==tempnam)
				{
					if(k->HD.loai=="X")
					{
						total[k->HD.ngay_Lap.thang-1]+=tinh_Tien_HD(k);
					}
					else
					{
						total[k->HD.ngay_Lap.thang-1]-=tinh_Tien_HD(k);
					}
					
				}
			}
		}
	}
}
void tinh_Doanh_Thu_Nam(long double &totalnam,long double totalthang[])
{
	for(int i=0;i<12;i++)
	{
		totalnam+=totalthang[i];
	}
}
void show_Doanh_Thu(long double total[])
{
	int y=11;
	for(int i=0;i<24;i+=2)
	{
		gotoxy(102,y+i);
		cout << std::setprecision(20);
		cout<<total[i/2];
	}
}




























