#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	PhanSo a, b;
	int menu, soMenu = 8;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, b);
	}
	while (menu > 0);
}