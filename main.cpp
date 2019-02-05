#include <iostream>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <Windows.h>
#include <fstream>
#include <iomanip> 
#include "Table/TextTable.h"

using namespace std;

#include "BLL/classes.h"
#include "BLL/prototypes.h"

int main ()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color F0");
	
	//////////////////////////
	vector<Categories> categories;
	Read_Categories(categories);
	
	vector<Company> company;
	Read_Company(company);
	
	vector<Product> product;
	Read_Product(product);
	//////////////////////////
	
	while (true)
	{
		switch (Main_Menu())
		{
			case 1: Categories_Menu(categories, product); break;
			case 2: Company_Menu(company, product); break;
			case 3: Product_Menu(product, categories, company); break;
			case 0: exit(0);
			default:
			{
				cout << endl << "Некоректний ввід!" << endl;
				cout << "Щоб знову зроби вибір, нажміть будь-яку кнопку: ";
				_getch();
				continue;
			}
		}
	}

	_getch();
	return 0;
}

#include "PL/menu.h"
#include "DAL/file_read.h"

//Логіка категорії
#include "BLL/categories_logic.h"
//Логіка постачальника
#include "BLL/company_logic.h"
//Логіка товару
#include "BLL/product_logic.h"
