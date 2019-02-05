class Categories 
{
protected:
	char category[50];
public:
	Categories()
	{
		strcpy(category, "�.�.");
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
		cout << "����� �������: ";
		cin.getline(category, sizeof(category));
	}
	
	void chg_category()
	{
		cin.ignore();
		cout << "����� �������(" << category << "): ";
		cin.getline(category, sizeof(category));
	}
		
	void show_categories(int product_count, int total_price)
	{
		cout << "�����: " << category << endl;
		cout << "ʳ������ ������: " << product_count << endl;
		cout << "�������� ���� ������: " << total_price << endl;
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
		strcpy(organisation, "�.�.");
		strcpy(fio, "�.�.");
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
		cout << "���: ";
		cin.getline(organisation, sizeof(organisation));
		cout << "�������: ";
		cin.getline(fio, sizeof(fio));
	}

	void chg_company()
	{
		cin.ignore();
		cout << "���(" << organisation << "): ";
		cin.getline(organisation, sizeof(organisation));
		cout << "�������(" << fio << "): ";
		cin.getline(fio, sizeof(fio));
	}
		
	void show_company(int product_count, int total_price)
	{
		cout << "���: " << organisation << endl;
		cout << "ϲ�: " << fio << endl;
		cout << "ʳ������ ������: " << product_count << endl;
		cout << "�������� ���� ������: " << total_price << endl;
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
		strcpy(title, "�.�.");
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
		cout << "�����: " << title << endl;
		cout << "��������: " << category << endl;
	    cout << "������������: " << organisation << endl;
		cout << "ֳ��: " << price << endl;
		cout << "ʳ������: " << amount << endl;	
	}
	
	void add_product(vector<Categories>& categories, vector<Company>& company)
	{
		cout << "�����: ";
		cin >> title;
		
		int i, id = 0;
		
		while (true)
		{           
			cout << "��������(";
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
				cout << "������� �����!" << endl;
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
			cout << "������������(";
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
				cout << "������� �����!" << endl;
			}
			else
			{
				strcpy(organisation, company[id].get_organisation());
				break;
			}
		}	
		
		cout << "ֳ��: ";
		cin >> price;
		cout << "ʳ������: ";
		cin >> amount;
	}
	
	void chg_product(vector<Categories>& categories, vector<Company>& company)
	{
		int i, id = 0;
		
		cin.ignore();
		cout << "�����(" << title << "): ";
		cin.getline(title, sizeof(title));
		
		while (true)
		{           
			cout << "��������(" << category << ")(";
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
				cout << "������� �����!" << endl;
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
			cout << "������������(" << organisation << ")(";
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
				cout << "������� �����!" << endl;
			}
			else
			{
				strcpy(organisation, company[id].get_organisation());
				break;
			}
		}	
		
		cout << "ֳ��(" << price << "): ";
		cin >> price;
		cout << "ʳ������(" << amount << "): ";
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
