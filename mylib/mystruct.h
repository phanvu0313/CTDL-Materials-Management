#include <iostream>
#include<fstream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include "./mylib.h"
#include <ctime>
#include<string>
#define MAXLISTNV 100
#define MAXLISTCTHD 20
#include <stdlib.h>

//====================================================================
//============================QUAN LY VAT TU==========================
//====================================================================

const int so_item_Quanly = 7;
const int so_item_Nhanvien=5;
const int dong =10;
const int cot=3;
const int so_item_QL=3;
const int so_item_VT=37;
const int so_item_CTHD=20;
const int so_item_Option=4;
//
const int Up = 72;
const int Down = 80;
const int Left = 75;
const int Right = 77;
const int Esc = 27;
const int enter = 13;
const int PD = 81;
const int PU =  73;
const int RightA=39;
int index=0;
using namespace std;


//====================================================================
//============================STRUC & NGUYEN MAU HAM==================
//====================================================================
//struct ngay thang nam
struct date
{
	int ngay;
	int thang;
	int nam;
};
//vat tu cay nhi phan
// int used :neu co hoa don nao co vat tu trong do thi khogn the xoa vat tu moi lan lap hoa don used se ++ va moi lan tra het hang thi used se -- neu ==0 thi co the xoa
struct vat_Tu
{
	
	int used=0;
	string ma_Vat_Tu;
	string ten_Vat_Tu;
	string don_Vi_Tinh;
	float so_Luong_Ton;
	//node 
	struct vat_Tu *pLeft;
	struct vat_Tu *pRight;
};
typedef struct vat_Tu* tree ;
struct ds_Vat_Tu
{
	tree ds=NULL;
	int n=0;	
};
//ds chi tet hoa don danh sach tuyen tinh
// them float soluongtra de xem vat tu do co tra hay khong 
// long float tri gia de tinh toang tien cua hoa don
struct chi_Tiet_HD
{
	string ma_Vat_Tu;
	float so_Luong;
	float so_Luong_Tra=0;
	int don_Gia;
	float VAT;
	bool trang_Thai;
	long double tri_Gia;
};
struct ds_CT_HD
{
	struct chi_Tiet_HD ds[MAXLISTCTHD];
	int n=0;
};
//danh sach hoa don danh sach lien ket don 
struct hoa_Don
{
	string soHD;
	date ngay_Lap;
	string loai;
	//
	struct ds_CT_HD dsCTHD;
	
};
struct node_Hoa_Don
{
	struct hoa_Don HD;
	struct node_Hoa_Don *pNext;
}; 
struct ds_Hoa_Don
{
	node_Hoa_Don *pHead=NULL;
	int n=0;	
};
// nhan vien mang con tro
struct nhan_Vien
{
	int ma_Nhan_Vien;
	string ho;
	string ten;
	string phai;
	string so_CMND;
	ds_Hoa_Don ds_HD;
};
struct ds_Nhan_Vien
{
	nhan_Vien *ds[MAXLISTNV];
	int n=0;
};
























