#include"./mylib/mystruct.h"

using namespace std;





// ====================================================KHAI BAO===================================================
// ====================================================KHAI BAO===================================================
string chon_Quyen [so_item_QL]= 		   {"             QUAN LY                 ",
			            		 			"             NHAN VIEN               ",
											"             THOAT                   ",};
						                    
string thucdon_Quanly [so_item_Quanly]=    {"    VAT TU                           ",
						                    "    NHAN VIEN                        ",
						                    "    LAP HOA DON                      ",
						                    "    TRA HANG                         ",
											"    HOA DON THEO SO HD               ",
											"    HOA DON CUA MOT NHAN VIEN        ",
											"    DOANH THU                        ",};
											
string menuVT[4]					=	   {"    --DANH SACH VAT TU               ",
											"    --THEM VAT TU                    ",
											"    --SUA VAT TU                     ",
						                    "    --XOA VAT TU                     ",};
						                    
string menuNV[4]					=	   {"    --DANH SACH NHAN VIEN            ",
											"    --THEM NHAN VIEN                 ",
						                    "    --SUA NHAN VIEN                  ",
						                    "    --XOA NHAN VIEN                  ",};
		                  
string thucdon_Nhanvien [so_item_Nhanvien]={"    DANH SACH VAT TU                 ",
						                    "    LAP HOA DON                      ",
						                    "    TRA HANG                         ",
											"    HOA DON THEO SO HD               ",
											"    HOA DON CUA BAN THAN             ",};

string chon_Vat_Tu [so_item_VT] ={ " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ", };


string chon_CTHD [so_item_CTHD] ={ " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ",};

string option[so_item_Option]=			   {"       SUA           ",
											"       XOA           ",
						                    "    LAP HOA DON      ",
											"    XEM HOA DON      ",};
// ====================================================KHAI BAO===================================================
// ====================================================KHAI BAO===================================================


// =================================================NGUYEN MAU HAM================================================
// =================================================NGUYEN MAU HAM================================================
// =================================================NGUYEN MAU HAM================================================
// =================================================NGUYEN MAU HAM================================================

//====================================================================
//====================================================================
// lay ngay hien tai
void getcurrentdate(date &);
//====================================================================
void draw();
void drawoff();
void loading();
// formats
int demso(int);// dem co bao nhieu so
int demsobo3(int);// dem co bao nhieu bo 3 so
void docsobo3(int);// doc 3 so
void doccham(int);// doc cham vidu : ty ,chuc ty,tram,....
int xoacham (int,int);// tach tung bo 3 de doc
void docmotdenmuoi(int );//doc cac so 
void doc_So(int,int ,int );

//

string chuan_Hoa(string &);
bool check_Num_In_Sring(string );
bool checkstring(string &,int );
bool check_CMND(string ,ds_Nhan_Vien ,int );
int nhap_String(string &,int ,int );
int nhap_MVT(string &,int ,int );
int nhap_Float(float &,int ,int );
int nhap_Int(int &,int ,int );
int nhap_Phai(string &,int ,int );
int nhap_Loai(string &,int ,int );
bool check_Date(date );
int count_Day(date );
void clearscl() ;
void Error (string );
void mau_Sac(string ,int ,int );
void Normal () ;
void Xanhla () ;
void HighLight () ;
void HighLight2 () ;
void HighLight3 () ;
void HighLight4 () ;
void HighLight5 () ;
void HighLight6() ;
void HighLight7();
void HighLight8() ;
void Vang_trang();
void ve_Khung_login();
void o_Chon_Menu(int ,int );
void xoa_o_Menu();
void o_Help(int ,int );
void ve_Khung();
void xoa_Man_Hinh();
void ve_o_Option(int x,int y);
int o_Option(string text,int x,int y,int loai);
void ve_o_Thoat(int ,int );
bool o_Thoat(string text,int ,int );
void xoa_Man_Hinh2();
void xoa_Khung_HD();
void ve_Khung_Xuat();
void ve_Khung_Xuat_NV();
void xoa_Trong_Khung_Xuat_NV();
void xoa_Trong_Khung_Xuat();
void ve_Khung_Xuat_CTHD1();
void xoa_Trong_Khung_Xuat_CTHD1();
void ve_Khung_Xuat_CTHD_Trahang();
void xoa_Trong_Khung_Xuat_CTHD_Trahang();
void ve_Khung_Xuat_CTHD();
void xoa_Khung_Xuat_CTHD_Month();
void ve_Khung_Xuat_CTHD3();
void xoa_Khung_Xuat3();
void ve_Khung_Xuat_Doanhthu();
void o_Nhap(int ,int );
void o_Ten_Menu(int ,int );
void o_Menu(int ,int );
void ve_Khung_Nhap(int ,int );
void xoa_Khung_Nhap(int );
void xoa_Khung_Nhapblue();
void ve_QLVT();
void text_VT(int ,int );
void text_Choose(string );
void Nocursortype();
void Showcursortype();
//====================================================================
//====================================================================
//====================================================================
// doc ghi file 
void read_VT(ds_Vat_Tu &a,ifstream &fin);
void write_VT(ds_Vat_Tu a,ofstream &fout);
void write_Tree(tree vt,ofstream &fout);
void read_NV(ds_Nhan_Vien &b,ifstream &fin);
void write_NV(ds_Nhan_Vien b,ofstream &fout);

//

//====================================================================
//====================================================================
//====================================================================
// vat tu

tree khoi_Tao_Vat_Tu();
bool nhap_Vat_Tu(tree &);
void them_Vat_Tu(ds_Vat_Tu &);
void them_node_Vat_Tu(tree &,tree );
void show_Vat_Tu(tree ,int );
void xuat_Vat_Tu(ds_Vat_Tu &);
void get_MVT(tree ,string* &);
int show_VT_Page(ds_Vat_Tu ,string* );
void show_A_Page_VT(ds_Vat_Tu ,string* ,int );
tree check_Vat_Tu(tree ,string );
void sua_Vat_Tu(tree &);
bool sua_Mot_Vat_Tu(tree &,string );
tree node_The(tree );
void xoa_Vat_Tu(ds_Vat_Tu &);
void xoa_Mot_Vat_Tu(tree& , string );
void search_Goi_Y_Ten_Vat_Tu(ds_Vat_Tu  ,string ,string arrtemp[2][5]);
void sap_Xep_Ten_Goi_Y(int ,string ,string arrtempten[],string arrtempmvt[]);
void get_Ten_VT(tree ,string arrtemp[],string arrtempmvt[]);
void show_Goi_Y(string arrtemp[2][5],int );
//trong danh sach
void sua_Vat_Tu_in_DS(tree &p,string);
void xoa_Vat_Tu_in_DS(ds_Vat_Tu &,string );
//====================================================================
//====================================================================
//====================================================================
// nhan vien

bool nhap_Nhan_Vien(ds_Nhan_Vien dsnv,nhan_Vien *);
void them_Nhan_Vien(ds_Nhan_Vien &);
void add_NV_Ten(ds_Nhan_Vien &,nhan_Vien *);
int compare_Ten(nhan_Vien *,nhan_Vien *);
void show_A_Page_NV(ds_Nhan_Vien ,int );
int show_Page_NV(ds_Nhan_Vien );
void xuat_Nhan_Vien(ds_Nhan_Vien &,ds_Vat_Tu &);
int check_Nhan_Vien(ds_Nhan_Vien , int ) ;
void xoa_Nhan_Vien(ds_Nhan_Vien &);
void sua_Nhan_Vien(ds_Nhan_Vien &);
// lap hoa don trong danh sach nhan vien
void lap_Hoa_Don_in_DS(ds_Nhan_Vien &,ds_Vat_Tu &,int );
void sua_Nhan_Vien_in_DS(ds_Nhan_Vien &,int );
void xoa_Nhan_Vien_in_DS(ds_Nhan_Vien &,int );
int nhap_Ma_NV(ds_Nhan_Vien );
//====================================================================
//====================================================================
//====================================================================
// hoa don

void lap_Hoa_Don(ds_Nhan_Vien &,ds_Vat_Tu &);
bool update_Main_SLT(ds_Vat_Tu &,node_Hoa_Don* &);
node_Hoa_Don* khoi_Tao_Node_HD();
void them_Hoa_Don(node_Hoa_Don* &,node_Hoa_Don* );
bool nhap_Chi_Tiet_HD(chi_Tiet_HD &,ds_Vat_Tu );
node_Hoa_Don* search_Hoa_Don(node_Hoa_Don* ,string );
node_Hoa_Don* search_Hoa_Don_bysoHD(node_Hoa_Don* ,string );
bool them_Chi_Tiet_HD(node_Hoa_Don* &,ds_Vat_Tu &);
bool check_MVT_In_CTHD(node_Hoa_Don* ,string );
void show_CTHD_Temp(ds_Vat_Tu ,node_Hoa_Don* ,int ,int );
void show_CTHD_Trahang(ds_Vat_Tu ,node_Hoa_Don* ,int ,int );
void xoa_VT_of_CTHD(ds_CT_HD &,int );
bool check_So_Luong_Ton(chi_Tiet_HD ,tree ,string );
void update_So_Luong_Ton(node_Hoa_Don* ,tree &);
bool nhap_Ngay(date &,int ,int );
bool xuat_Ngay(date );
int check_Null_HD(ds_Nhan_Vien );
node_Hoa_Don* search_So_HD(ds_Nhan_Vien ,string );
int search_id_NV_By_So_HD(ds_Nhan_Vien ,string );
bool check_3_Ngay(date  ,date );
int day_Compare(date ,date );

void tra_Hang(ds_Nhan_Vien &,ds_Vat_Tu &);
void tra_Hang_CTHD(node_Hoa_Don* &,ds_Vat_Tu &,int );
void in_Hoa_Don(ds_Nhan_Vien ,ds_Vat_Tu );
long double tinh_Tien_HD(node_Hoa_Don* );


void update_Tra_Hang(ds_Hoa_Don &,node_Hoa_Don* &);
int find_VT_To_Del_in_Tra_Hang(ds_CT_HD );
void update_Tra_Hang_in_CTHD(ds_CT_HD &);
int find_SL_To_Del(ds_CT_HD );


void in_HD_DTD(ds_Nhan_Vien ,ds_Vat_Tu );
//trong ds
void in_HD_DTD_in_DS(ds_Nhan_Vien,ds_Vat_Tu ,int);
void compare_Date_In_DSCTHD(nhan_Vien* , ds_Vat_Tu ,date ,date );
bool find_Date_To_Date(node_Hoa_Don* ,string* &,date ,date );
void show_CTHD_Page_DTD(nhan_Vien* ,ds_Vat_Tu ,string* );
void show_Info_DTD(hoa_Don );
void thong_Ke_Doanh_Thu(ds_Nhan_Vien,ds_Vat_Tu  );
void tinh_Doanh_Thu(ds_Nhan_Vien ,int ,long double total[]);
void tinh_Doanh_Thu_Nam(long double &,long double totalthang[]);
void show_Doanh_Thu(long double total[]);
//tim hoa don trong thang cua nam
int count_SHD_Month(ds_Nhan_Vien ,int ,int );
void get_SHD_Month(ds_Nhan_Vien ,string arrtemp[],int ,int );
//====================================================================
//====================================================================
//====================================================================
// menu


int menu_Quanly(string thucdon_Quanly[],int ,int  );
void menuvt(ds_Vat_Tu &,ds_Nhan_Vien &);

//====================================================================
//====================================================================
//====================================================================
