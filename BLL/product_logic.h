//Логіка товару
void Add_Product(vector<Product>& product, vector<Categories>& categories, vector<Company>& company)
{
	system("cls");
	cout << "\t Добавити товар " << endl << endl;
	Product temp;
	temp.add_product(categories, company);
	temp.write();
	
	product.push_back(temp);

	cout << "Товар додано!" << endl;
	cout << "Щоб повернутися назад в меню нажміть будь-яку кнопку: ";
	_getch();
}

void Show_Product(vector<Product>& product)
{
	system("cls");
	cout << "\tТовари " << endl << endl;
	
	TextTable t( '-', '|', '+' );
	
	t.add( "#" );
    t.add( "Назва" );
    t.add( "Категорія" );
    t.add( "Постачальник" );
    t.add( "Ціна" );
    t.add( "Кількість" );
    t.endOfRow();
    
	for (int i(0); i < product.size(); i++)
	{
		t.add(to_string(i));
		t.add(product[i].get_title());
    	t.add(product[i].get_category());
    	t.add(product[i].get_organisation());
    	t.add(to_string(product[i].get_price()));
    	t.add(to_string(product[i].get_amount()));
    	t.endOfRow();
    	
//		product[i].show_product();
	}

	cout << t << endl << "Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
	_getch();
}

void Delete_Product(vector<Product>& product)
{
	system("cls");
    cout << "\tВидалити товар" << endl << endl;
	int id;
    bool delete_check = false; 
	cout << ": ";
	cin >> id;
	cout << endl;

	int i = 0;

	if (id < product.size())
	{
		delete_check = true;			
		product.erase(product.begin() + id);
		cout << "Товар видалено!" << endl;
	}
	
	if(delete_check == true)
	{	
		product[0].rewrite();
		i = 1;
		
		while (i < product.size())
		{
			product[i].write();
			i++;
		}
	}
	
	cout << "\nЩоб повернутися назад в меню нажміть будь-яку кнопку: ";
	_getch();
}

void Change_Product(vector<Product>& product, vector<Categories>& categories, vector<Company>& company)
{
	system("cls");
    cout << "\tЗмінити данні товару" << endl << endl;
    cout << ":";
    
    int id = 0;
 	cin >> id;
	cout << endl;
	
	if (id < product.size())
	{	
	    product[id].chg_product(categories, company);	
	    product[0].rewrite();
		int i = 1;
		
		while (i < product.size())
		{
			product[i].write();
			i++;
		}
		cout << "Товар відредаговано!" << endl;
	}
	else
	{
		cout << "\nПід #" << id << " не знайдено товар"<< endl;
	}
	
	cout << "\nЩоб повернутися назад в меню нажміть будь-яку кнопку: ";
	_getch();
}

void Search_Product(vector<Product> product)
{
	system("cls");
    cout << "\tПошук товару" << endl << endl;
	char query[30];
	cout << ": ";
	cin.ignore();
	cin.getline(query, sizeof(query));
	cout << endl;

	int i = 0;
	cout << "Результати: " << endl << endl;
	while (i < product.size())
	{
		if (product[i].search(query))
		{
			product[i].show_product();
			cout << endl;
		}
		i++;
	}

	cout << "\nЩоб повернутися назад в меню нажміть будь-яку кнопку: ";
	_getch();
}

