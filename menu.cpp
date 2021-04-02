#include "hoadon.cpp"

// mystruct->nguyenmau->format->vattu->nhanvien->hoadon->menu->Quanlyvattu  
//====================================================================
//==========================MENU====================================
//====================================================================


int menu_Quanly(string thucdon_Quanly[],int soluong,int loaimn )	
{
	Nocursortype();
	/* loaimn 
	0== menu login
	1== menu nhap xuat in
	2== chon trong menu xuat vat tu va nhan vien
	3== chon trong menu nhap chi tiet hoa don
	4 chon trong goi i lap hoa don
	5 chon trong chi tiet doanh thu 
	6 trong menu option
	7 trong menu chon tra hang
	*/
	int cottemp=cot;
	int dongtemp=dong;
	Normal();
	
	  if(loaimn==0)
	  {
	  	system("cls");
	  	ve_Khung_login();
	  	cottemp=80;
	  	dongtemp=22;
	  }
	  else if(loaimn==1)
	  {
	  	xoa_Man_Hinh();
	  	cottemp=4;
	  	dongtemp=7;
	  }
	  else if(loaimn==2)
	  {
	  	cottemp=59;
	  	dongtemp=8;
	  }
	  else if(loaimn==3)
	  {
	  	cottemp=121;
	  	dongtemp=5;
	  }
	  else if(loaimn==4)
	  {
	  	cottemp=65;
	  	dongtemp=18;
	  }
	  else if(loaimn==5)
	  {
	  	cottemp=79;
	  	dongtemp=11;
	  }
	  else if(loaimn==6)
	  {
	  	cottemp=90;
	  	dongtemp=23;
	  	loaimn=2;
	  }
	  else if(loaimn==7)
	  {
	  	cottemp=115;
	  	dongtemp=5;
	  	loaimn=3;
	  }
	  int chon =0;
	  int i; 
	  for ( int j=0,i=0; i< soluong ;j++, i++)
	  { 
	  	if(loaimn==4)
	  	{
	  		gotoxy(cottemp, dongtemp +i);
	    	cout << thucdon_Quanly[i];
		}
		else
		{
			gotoxy(cottemp, dongtemp +i+j);
		    cout << thucdon_Quanly[i];
		    if(loaimn==1)
		    {
		    	text_VT(60,9);
		    	text_Choose(thucdon_Quanly[chon]);
			}
		    
		}
		
		  	
	  }
	  if((loaimn!=0)&&(loaimn!=1))
	  {
	  	HighLight3 ();
	  	gotoxy(cottemp,dongtemp+chon);
	  	cout <<char(175);
	  	
	  }
	  else
	  {
	  	HighLight6() ;
	  	o_Menu(cottemp,dongtemp+chon);
	  	gotoxy(cottemp,dongtemp+chon);
	  	HighLight8() ;
	  	cout <<char(175);
	  	HighLight() ;
		mau_Sac( thucdon_Quanly[chon],cottemp+1,dongtemp+chon*2) ;
		
		Normal();
	  	//gotoxy(cottemp,dongtemp+chon+1);
	  	//HighLight6() ;
	  	//cout << "                                       ";
	  }
	  
	  
	  char kytu;
	do 
	{
	  
	  kytu = getch();
	  
	  if (kytu==-32) kytu = getch();
	  switch (kytu) 
	   {
	    case Up :
	    		  if(loaimn==4)
	  			  	{
	  			  		if(chon==0)
	  			  		{
	  			  			gotoxy(cottemp,dongtemp+chon);
	  			  			cout<<" ";
	  			  			return -1;
						}
	  			  		Normal();
		              	gotoxy(cottemp,dongtemp+chon);	cout << thucdon_Quanly[chon];
		              	chon --;
		              	HighLight3 ();
		              	gotoxy(cottemp,dongtemp+chon); 	cout << char(175);
		              	break;
					}
				  if (chon >0)
	  			  {
	  			  	if((loaimn!=0)&&(loaimn!=1)&&(loaimn!=4))
	  			  	{
	  			  		Normal();
		              	gotoxy(cottemp,dongtemp+chon*2);	cout << thucdon_Quanly[chon];
		              	chon --;
		              	HighLight3();
		              	gotoxy(cottemp,dongtemp+chon*2); 	cout << char(175);
		              	break;
					}
					
	  		        Normal();
	  		        gotoxy(cottemp,dongtemp+chon*2-1);cout << "                                       ";
	              	gotoxy(cottemp,dongtemp+chon*2);cout << thucdon_Quanly[chon]<<"  ";
	              	gotoxy(cottemp,dongtemp+chon*2+1);cout << "                                       ";
	              	chon --;
	              	if(loaimn!=0)text_Choose(thucdon_Quanly[chon]);
	              	HighLight6() ;
	  				o_Menu(cottemp,dongtemp+chon*2);
	              	HighLight() ;
	              	gotoxy(cottemp,dongtemp+chon*2);    HighLight8() ; 
					  									cout<<char(175);
					  									HighLight() ; 
					  									mau_Sac( thucdon_Quanly[chon],cottemp+1,dongtemp+chon*2) ;
					  												
	  			  }
	  			  break;
	  	case Down :if (chon+1 <soluong)
	  			  {
	  			  	if((loaimn!=0)&&(loaimn!=1)&&(loaimn!=4))
	  			  	{
	  			  		Normal();
		              	gotoxy(cottemp,dongtemp+chon*2);	cout << thucdon_Quanly[chon];
		              	chon ++;
		              	HighLight3 ();
		              	gotoxy(cottemp,dongtemp+chon*2); 	cout << char(175);
		              	break;
					}
					if(loaimn==4)
	  			  	{
	  			  		Normal();
		              	gotoxy(cottemp,dongtemp+chon);	cout << thucdon_Quanly[chon];
		              	chon ++;
		              	HighLight3 ();
		              	gotoxy(cottemp,dongtemp+chon); 	cout << char(175);
		              	break;
					}
	  		        Normal();
	              	gotoxy(cottemp,dongtemp+chon*2-1);cout << "                                       ";
	              	gotoxy(cottemp,dongtemp+chon*2);cout << thucdon_Quanly[chon]<<"  ";
	              	gotoxy(cottemp,dongtemp+chon*2+1);cout << "                                       ";
	              	chon ++;
	              	if(loaimn!=0)text_Choose(thucdon_Quanly[chon]);
	              	HighLight6() ;
	  				o_Menu(cottemp,dongtemp+chon*2);
					HighLight() ;	
	              	gotoxy(cottemp,dongtemp+chon*2);    HighLight8() ; 
					  									cout <<char(175);
					  									HighLight() ; 
					  									mau_Sac( thucdon_Quanly[chon],cottemp+1,dongtemp+chon*2) ;
					  											
	              		
	  				
	  			  }
	  			  break;
	  	case Esc :
	  		{
	  			if(loaimn==0)
	  			{
	  				break;
				}
				else
				{
					return -1;
				}
	  		
			}
	  	case enter :
		  {
		  	if((loaimn==0)||(loaimn==1))
		  	{
		  		Normal();
	          	gotoxy(cottemp,dongtemp+chon*2-1);cout << "                                       ";
	          	gotoxy(cottemp,dongtemp+chon*2);cout<<" ";
	          	gotoxy(cottemp+36,dongtemp+chon*2);cout<<"   ";
	          	gotoxy(cottemp,dongtemp+chon*2+1);cout << "                                       ";
			}
			else
			{
//				Normal();
//				gotoxy(cottemp,dongtemp+chon*2);cout << " ";
			}
	  		  	
		  	return chon+1;
		  } 
		}  // end switch
	} while (1);
}
void menuvt(ds_Vat_Tu &a,ds_Nhan_Vien &b)
{
	int indexnvtemp ;// trong phan quyen 
	
lap:
	int choose;
	choose=menu_Quanly(chon_Quyen,3,0);// menu login
	if(choose==2)
	{
		xoa_Man_Hinh();
		//ve_Khung_Nhap(90,8);
nhapma:
		indexnvtemp = nhap_Ma_NV(b);
		if(indexnvtemp==-2)
		{
			goto lap;
		}
		else if(indexnvtemp==-1)
		{
			Error("MA NHAN VIEN KHONG TON TAI !");
			
			goto nhapma;
		}
	}
	int chon;  
	bool check=true;
    while  (check==true) 
	{
        if(choose==1)
        {
			ve_Khung(); 
			Normal();
        	chon=menu_Quanly(thucdon_Quanly, so_item_Quanly,1);// quan ly
        	
        	if(chon ==-1)
        	{
        		goto lap;
			}
		}
		else if(choose==2)
		{
			
			ve_Khung(); 
			Normal();

			{
				chon=menu_Quanly(thucdon_Nhanvien,so_item_Nhanvien,1);// nhan vien
				if(chon ==-1)
	        	{
	        		goto lap;
				}
				else
				{
					if(chon >2)
					{
						chon+=1;
					}
				}
				
			}
		}
		if(choose==3)
		{
			bool out =o_Thoat("BAN CO MUON THOAT KHONG",79,15);
			if(out==true)
			{
				return;
			}
			else
			{
				goto lap;
			}
			
		}
		Showcursortype();
		
        switch (chon) 
		{
	        case 1:
			{
				if(choose==2)
				{
					Nocursortype();
					xuat_Vat_Tu(a);
					break;
				}
				//
				xoa_o_Menu();
				gotoxy(21,3);
				SetColor(15);
				SetBGColor(0);
				cout<<"VAT TU";
				Normal();
			vt:
				int chon2=menu_Quanly(menuVT,4,1);//inside vat tu
				
				Showcursortype();
				switch(chon2)
				{
					case 1:
					{
						Nocursortype();
						xuat_Vat_Tu(a);
						xoa_Khung_HD();
						break;
					}
					case 2:
					{
						ve_Khung_Nhap(90,8);
						them_Vat_Tu(a);
						break;
					}
					case 3:
					{
						ve_Khung_Nhap(90,8);
						sua_Vat_Tu(a.ds);
						break;
					}
					case 4:
					{
						ve_Khung_Nhap(90,8);
						xoa_Vat_Tu(a);
						break;
					}	
					
				} 
				
				if(chon2==-1)
				{
					xoa_o_Menu();
					break;
				}
				else
				{
					goto vt;
				}
			}
			case 2:
			{
				if(choose==2)
				{
					Showcursortype();
					lap_Hoa_Don_in_DS(b,a, indexnvtemp);
					break;
				}
				xoa_o_Menu();
				gotoxy(20,3);
				SetColor(15);
				SetBGColor(0);
				cout<<"NHAN VIEN";
				Normal();
			nv:
				int chon2=menu_Quanly(menuNV,4,1);// inside nhan vien
				Showcursortype();
				switch(chon2)
				{
					case 1:
					{
						Nocursortype();
						xuat_Nhan_Vien(b,a);
						xoa_Khung_HD();
						break;
					}
					case 2:
					{
						ve_Khung_Nhap(90,8);
						them_Nhan_Vien(b);
						xoa_Khung_HD();
						break;
					}
					case 3:
					{
						ve_Khung_Nhap(90,8);
						sua_Nhan_Vien(b);
						xoa_Khung_HD();
						break;
					}
					case 4:
					{
						ve_Khung_Nhap(90,8);
						xoa_Nhan_Vien(b);
						xoa_Khung_HD();
						break;
					}
						
				} 
				if(chon2==-1)
				{
					xoa_o_Menu();
					break;
				}
				else
				{
					goto nv;
				}
			}
			case 3:
			{
				//ipt
				lap_Hoa_Don(b,a);
				xoa_Khung_HD();
				break;
			}
			case 4:
			{
				///
				ve_Khung_Nhap(90,8);
				tra_Hang( b, a);
				xoa_Khung_HD();
				//xuat_DS_HD(b);
				break;
			}
			case 5:
			{
				//in hoa don
				//
				ve_Khung_Nhap(90,8);
				in_Hoa_Don(b, a);
				//in hoa don
				break;
			}
			case 6:
			{
				//in hoa don cua 1 nhan vien trong 1 khoang thaoi gian
				if(choose==2)
				{
					in_HD_DTD_in_DS(b,a,b.ds[indexnvtemp]->ma_Nhan_Vien);
					break;
				}
				//
				ve_Khung_Nhap(90,8);
				in_HD_DTD(b ,a);
				
				break;
			}
			case 7:
			{
				//thong ke doanh thu
				thong_Ke_Doanh_Thu( b,a);
				xoa_Khung_HD();
				break;
			}
			case 0:
			{
				check=false;
				break;
			}
			
			default: break;
    	}
	}
}







