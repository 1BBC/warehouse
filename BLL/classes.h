class Categories 
{
protected:
	char category[50];
public:
	Categories()
	{
		strcpy(category, "н.д.");
	}
    Categories(char c_category[])
	{
		strcpy(category, c_category);
	}
	
    char* get_category() 
	{
		return category; 
	}
	
	void add_category()
	{
		cin.ignore();
		cout << "Назва категорії: ";
		cin.getline(category, sizeof(category));
	}
	
	void chg_category()
	{
		cin.ignore();
		cout << "Назва категорії(" << category << "): ";
		cin.getline(category, sizeof(category));
	}
		
	void show_categories(int product_count, int total_price)
	{
		cout << "Назва: " << category << endl;
		cout << "Кількість товару: " << product_count << endl;
		cout << "Загальна ціна товару: " << total_price << endl;
	}

	void read(int position = 0)
	{
		ifstream file("Categories.bin", ios::binary);
		if (file.is_open())
		{
			file.seekg(position * sizeof(*this));
			file.read((char*)this, sizeof(*this));
		}
		file.close();
	}
	
	void write()
	{
	    ofstream file("Categories.bin", ios::binary | ios::app);
		
		file.write((char*)this, sizeof(*this));
		file.close();
	}
	
	void rewrite()
	{
	    ofstream file("Categories.bin", ios::binary);
		
		file.write((char*)this, sizeof(*this));
		file.close();
	}
	
	int count_File()
	{
		ifstream file("Categories.bin", ios::binary);
		if (file.is_open())
		{
			file.seekg(0, ios::end);
			return (int)file.tellg() / sizeof(Categories);
		}
		else
			return 0;
	}
	
	bool search(char* query)
	{
		if (!strcmp(category, query))
			return true;
		else
			return false;
	}
	
	~Categories(){}
};

class Company 
{
protected:
	char organisation[50];
private:
	char fio[50];
public:
	Company()
	{
		strcpy(organisation, "н.д.");
		strcpy(fio, "н.д.");
	}
	
    Company(char c_organisation[], char c_fio[])
	{
		strcpy(organisation, c_organisation);
		strcpy(fio, c_fio);
	}
	
	char* get_organisation() 
	{
		return organisation; 
	}
	
	char* get_fio() 
	{
		return fio; 
	}
	
	void add_company()
	{
		cin.ignore();
		cout << "ТОВ: ";
		cin.getline(organisation, sizeof(organisation));
		cout << "Власник: ";
		cin.getline(fio, sizeof(fio));
	}

	void chg_company()
	{
		cin.ignore();
		cout << "ТОВ(" << organisation << "): ";
		cin.getline(organisation, sizeof(organisation));
		cout << "Власник(" << fio << "): ";
		cin.getline(fio, sizeof(fio));
	}
		
	void show_company(int product_count, int total_price)
	{
		cout << "ТОВ: " << organisation << endl;
		cout << "ПІБ: " << fio << endl;
		cout << "Кількість товару: " << product_count << endl;
		cout << "Загальна ціна товару: " << total_price << endl;
	}

	void read(int position = 0)
	{
		ifstream file("Company.bin", ios::binary);
		if (file.is_open())
		{
			file.seekg(position * sizeof(*this));
			file.read((char*)this, sizeof(*this));
		}
		file.close();
	}
	
	void write()
	{
	    ofstream file("Company.bin", ios::binary | ios::app);
		
		file.write((char*)this, sizeof(*this));
		file.close();
	}
	
	void rewrite()
	{
	    ofstream file("Company.bin", ios::binary);
		
		file.write((char*)this, sizeof(*this));
		file.close();
	}

	int count_File()
	{
		ifstream file("Company.bin", ios::binary);
		if (file.is_open())
		{
			file.seekg(0, ios::end);
			return (int)file.tellg() / sizeof(Company);
		}
		else
			return 0;
	}
	
	bool search(char* query)
	{
		if (!strcmp(organisation, query) || !strcmp(fio, query) )
			return true;
		else
			return false;
	}
	
	~Company(){}
};

class Product : protected Categories, protected Company
{
private:
	char title[30];
	int price;
	int amount;
public:
	Product() : amount(0), price(0)
	{
		strcpy(title, "н.д.");
	}
    Product(char* p_title, int p_amount, int p_price)
	{
		strcpy(title, p_title);
		amount = p_amount;
		price = p_price;
	}
	
	char* get_title() 
	{
		return title; 
	}
	
	int get_price() 
	{
		return price; 
	}
	
	int get_amount() 
	{
		return amount; 
	}
	
	char* get_category() 
	{
		return category; 
	}
	
	char* get_organisation() 
	{
		return organisation; 
	}
	
	void show_product()
	{
		cout << "Назва: " << title << endl;
		cout << "Категорія: " << category << endl;
	    cout << "Постачальник: " << organisation << endl;
		cout << "Ціна: " << price << endl;
		cout << "Кількість: " << amount << endl;	
	}
	
	void add_product(vector<Categories>& categories, vector<Company>& company)
	{
		cout << "Назва: ";
		cin >> title;
		
		int i, id = 0;
		
		while (true)
		{           
			cout << "Категорія(";
			while (i < categories.size())
			{
				cout << i << " - "<< categories[i].get_category() ;
				i++;
				if(i != categories.size())
				{
					cout << ", ";
				}
			}
			cout << "): ";
			
			cin >> id;
			if (id < 0 && id >= categories.size())
			{
				cout << "Помилка вводу!" << endl;
			}
			else
			{
				strcpy(category, categories[id].get_category());
				break;
			}
		}	
		
		i = id = 0;
		
		while (true)
		{           
			cout << "Постачальник(";
			while (i < company.size())
			{
				cout << i << " - "<< company[i].get_organisation() ;
				i++;
				if(i != company.size())
				{
					cout << ", ";
				}
			}
			cout << "): ";
			
			cin >> id;
			if (id < 0 && id >= company.size())
			{
				cout << "Помилка вводу!" << endl;
			}
			else
			{
				strcpy(organisation, company[id].get_organisation());
				break;
			}
		}	
		
		cout << "Ціна: ";
		cin >> price;
		cout << "Кількість: ";
		cin >> amount;
	}
	
	void chg_product(vector<Categories>& categories, vector<Company>& company)
	{
		int i, id = 0;
		
		cin.ignore();
		cout << "Назва(" << title << "): ";
		cin.getline(title, sizeof(title));
		
		while (true)
		{           
			cout << "Категорія(" << category << ")(";
			while (i < categories.size())
			{
				cout << i << " - "<< categories[i].get_category() ;
				i++;
				if(i != categories.size())
				{
					cout << ", ";
				}
			}
			cout << "): ";
			
			cin >> id;
			if (id < 0 && id >= categories.size())
			{
				cout << "Помилка вводу!" << endl;
			}
			else
			{
				strcpy(category, categories[id].get_category());
				break;
			}
		}
		
		i = 0;
		
		while (true)
		{           
			cout << "Постачальник(" << organisation << ")(";
			while (i < company.size())
			{
				cout << i << " - "<< company[i].get_organisation() ;
				i++;
				if(i != company.size())
				{
					cout << ", ";
				}
			}
			cout << "): ";
			
			cin >> id;
			if (id < 0 && id >= company.size())
			{
				cout << "Помилка вводу!" << endl;
			}
			else
			{
				strcpy(organisation, company[id].get_organisation());
				break;
			}
		}	
		
		cout << "Ціна(" << price << "): ";
		cin >> price;
		cout << "Кількість(" << amount << "): ";
		cin >> amount;
	}
	
	void read(int position = 0)
	{
		ifstream file("Product.bin", ios::binary);
		if (file.is_open())
		{
			file.seekg(position * sizeof(*this));
			file.read((char*)this, sizeof(*this));
		}
		file.close();
	}
	
	void write()
	{
	    ofstream file("Product.bin", ios::binary | ios::app);
		
		file.write((char*)this, sizeof(*this));
		file.close();
	}
	
	void rewrite()
	{
	    ofstream file("Product.bin", ios::binary);
		
		file.write((char*)this, sizeof(*this));
		file.close();
	}
	
	int count_File()
	{
		ifstream file("Product.bin", ios::binary);
		if (file.is_open())
		{
			file.seekg(0, ios::end);
			return (int)file.tellg() / sizeof(Product);
		}
		else
			return 0;
	}

	bool search(char* query)
	{
		if (!strcmp(organisation, query) || !strcmp(category, query) || !strcmp(title, query)  )
			return true;
		else
			return false;
	}
	
	~Product(){}
};
