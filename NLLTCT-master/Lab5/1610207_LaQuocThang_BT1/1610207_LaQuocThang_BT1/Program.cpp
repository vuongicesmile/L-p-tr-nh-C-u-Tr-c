#include <conio.h>
#include <iostream>

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
	int menu, soMenu=3;
	do
	{
		menu=ChonMenu(soMenu);
		XuLyMenu(menu);
	}
	while (menu>0);
}