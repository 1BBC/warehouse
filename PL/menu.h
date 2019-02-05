//Голвне меню
int Main_Menu()
{
	system("cls");
	cout << "\tГоловне меню" << endl << endl;
	cout << "1. Категорії " << endl;
	cout << "2. Постачальники " << endl;
	cout << "3. Товар " << endl;		
	cout << endl << "0. Вийти" << endl;
	cout << endl << ": ";
	int item;
	cin >> item;
	return item;
}

//Категорії меню
void Categories_Menu(vector<Categories>& categories, vector<Product> product)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\tКатегорії." << endl << endl;
		cout << "1. Всі категорії " << endl;
		cout << "2. Додати" << endl;
		cout << "3. Видалити" << endl;
		cout << "4. Змінити" << endl;
		cout << "5. Пошук" << endl;
		cout << endl <<"0. Назад " << endl;
		cout << endl << ": ";


		cin >> item;
		switch (item)
		{
		case 1: Show_Categories(categories, product); break;
		case 2: Add_Categories(categories); break;
		case 3: Delete_Categories(categories); break;
		case 4: Change_Categories(categories); break;
		case 5: Search_Categories(categories); break;
		case 0: return;
		default:
		{
			cout << endl << "Некоректний ввід!" << endl;
			cout << "Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
			_getch();
			continue;
		}
		}
	}
}

//Постачальник меню
void Company_Menu(vector<Company>& company, vector<Product> product)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\tПостачальники" << endl << endl;
		cout << "1. Всі постачальники" << endl;
		cout << "2. Додати" << endl;
		cout << "3. Видалити" << endl;
		cout << "4. Змінити" << endl;
		cout << "5. Пошук" << endl;
		cout << endl <<"0. Назад " << endl;
		cout << endl << ": ";


		cin >> item;
		switch (item)
		{
		case 1: Show_Company(company, product); break;
		case 2: Add_Company(company); break;
		case 3: Delete_Company(company); break;
		case 4: Change_Company(company); break;
		case 5: Search_Company(company); break;
		case 0: return;
		default:
		{
			cout << endl << "Некоректний ввід!" << endl;
			cout << "Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
			_getch();
			continue;
		}
		}
	}
}

//Товари меню
void Product_Menu(vector<Product>& product, vector<Categories>& categories, vector<Company>& company)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\tТовари" << endl << endl;
		cout << "1. Всі товари" << endl;
		cout << "2. Додати" << endl;
		cout << "3. Видалити" << endl;
		cout << "4. Змінити" << endl;
		cout << "5. Пошук" << endl;
		cout << endl <<"0. Назад " << endl;
		cout << endl << ": ";


		cin >> item;
		switch (item)
		{
		case 1: Show_Product(product); break;
		case 2: Add_Product(product, categories, company); break;
		case 3: Delete_Product(product); break;
		case 4: Change_Product(product, categories, company); break;
		case 5: Search_Product(product); break;
		case 0: return;
		default:
		{
			cout << endl << "Некоректний ввід!" << endl;
			cout << "Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
			_getch();
			continue;
		}
		}
	}
}
