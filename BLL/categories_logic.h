//Логіка категорії
void Add_Categories(vector<Categories>& categories)
{
	system("cls");
	cout << "\t Добавити категорію " << endl << endl;
	Categories temp;
	temp.add_category();
	temp.write();

	categories.push_back(temp);

	cout << "Категорію додано!" << endl;
	cout << "Щоб повернутися назад в меню нажміть будь-яку кнопку: ";
	_getch();
}

void Show_Categories(vector<Categories> categories, vector<Product> product)
{
	system("cls");
	cout << "\tКатегорії " << endl << endl;
	TextTable t( '-', '|', '+' );
	
	t.add( "#" );
    t.add( "Назва" );
    t.add( "Кількість товару" );
    t.add( "Загальна ціна товару" );
    t.endOfRow();
    
	int product_count, total_price = 0;
	
	for (int i(0); i < categories.size(); i++)
	{
		product_count = total_price = 0;
		
		for (int y(0); y < product.size(); y++)
		{
			if(strcmp(product[y].get_category(), categories[i].get_category()) == 0)
			{
				product_count++;
				total_price += product[y].get_price() * product[y].get_amount();
			}
		}
		
		t.add(to_string(i));
		t.add(categories[i].get_category());
    	t.add(to_string(product_count));
    	t.add(to_string(total_price));
    	t.endOfRow();
			
		//categories[i].show_categories(product_count, total_price);
	}
    
	cout << t << endl << "Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
	_getch();
}

void Delete_Categories(vector<Categories>& categories)
{
	system("cls");
    cout << "\tВидалити категорію" << endl << endl;
	int id;
    bool delete_check = false; 
	cout << ": ";
	cin >> id;
	cout << endl;

	int i = 0;

	if (id < categories.size())
	{
		delete_check = true;			
		categories.erase(categories.begin() + id);
		cout << "Категорію видалено!" << endl;
	}
	
	if(delete_check == true)
	{	
		categories[0].rewrite();
		i = 1;
		
		while (i < categories.size())
		{
			categories[i].write();
			i++;
		}
	}
	
	cout << "\nЩоб повернутися назад в меню нажміть будь-яку кнопку: ";
	_getch();
}

void Change_Categories(vector<Categories>& categories)
{
	system("cls");
    cout << "\tЗмінити категорію" << endl << endl;
    cout << ":";
    
    int id = 0;
 	cin >> id;
	cout << endl;
	
	if (id < categories.size())
	{	
	    categories[id].chg_category();	
	    categories[0].rewrite();
		int i = 1;
		
		while (i < categories.size())
		{
			categories[i].write();
			i++;
		}
		cout << "Категорію змінено!" << endl;
	}
	else
	{
		cout << "\nПід #" << id << " не знайдено категорію"<< endl;
	}
	
	cout << "\nЩоб повернутися назад в меню нажміть будь-яку кнопку: ";
	_getch();
}

void Search_Categories(vector<Categories> categories)
{
	system("cls");
    cout << "\tПошук категорії" << endl << endl;
	char query[30];
	cout << ": ";
	cin.ignore();
	cin.getline(query, sizeof(query));
	cout << endl;

	int i = 0;
	cout << "Результати: " << endl << endl;
	while (i < categories.size())
	{
		if (categories[i].search(query))
		{		
			cout << categories[i].get_category() << endl;
		}
		i++;
	}

	cout << "\nЩоб повернутися назад в меню нажміть будь-яку кнопку: ";
	_getch();
}
