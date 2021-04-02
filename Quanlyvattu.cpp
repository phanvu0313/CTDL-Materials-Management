#include "menu.cpp"



int main()
{
	//khoa size
	lock_Resize();
	// mau nme:D
	//on
	loading();
	//nhap xuat file
	
	ifstream fin;
	ofstream fout;
	
	ds_Vat_Tu a;
	ds_Nhan_Vien b;
	read_VT(a, fin);
	read_NV(b,fin);
	//menu
	menuvt(a,b);
	//xuat file
	write_VT( a, fout);
	write_NV(b,fout);
	// off
	drawoff();
	return 0;
}







