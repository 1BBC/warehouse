//����� ������
void Add_Product(vector<Product>& product, vector<Categories>& categories, vector<Company>& company)
{
	system("cls");
	cout << "\t �������� ����� " << endl << endl;
	Product temp;
	temp.add_product(categories, company);
	temp.write();
	
	product.push_back(temp);

	cout << "����� ������!" << endl;
	cout << "��� ����������� ����� � ���� ������ ����-��� ������: ";
	_getch();
}

void Show_Product(vector<Product>& product)
{
	system("cls");
	cout << "\t������ " << endl << endl;
	
	TextTable t( '-', '|', '+' );
	
	t.add( "#" );
    t.add( "�����" );
    t.add( "��������" );
    t.add( "������������" );
    t.add( "ֳ��" );
    t.add( "ʳ������" );
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

	cout << t << endl << "��� ����� ������� ����, ������ ����-��� ������: ";
	_getch();
}

void Delete_Product(vector<Product>& product)
{
	system("cls");
    cout << "\t�������� �����" << endl << endl;
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
		cout << "����� ��������!" << endl;
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
	
	cout << "\n��� ����������� ����� � ���� ������ ����-��� ������: ";
	_getch();
}

void Change_Product(vector<Product>& product, vector<Categories>& categories, vector<Company>& company)
{
	system("cls");
    cout << "\t������ ���� ������" << endl << endl;
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
		cout << "����� ������������!" << endl;
	}
	else
	{
		cout << "\nϳ� #" << id << " �� �������� �����"<< endl;
	}
	
	cout << "\n��� ����������� ����� � ���� ������ ����-��� ������: ";
	_getch();
}

void Search_Product(vector<Product> product)
{
	system("cls");
    cout << "\t����� ������" << endl << endl;
	char query[30];
	cout << ": ";
	cin.ignore();
	cin.getline(query, sizeof(query));
	cout << endl;

	int i = 0;
	cout << "����������: " << endl << endl;
	while (i < product.size())
	{
		if (product[i].search(query))
		{
			product[i].show_product();
			cout << endl;
		}
		i++;
	}

	cout << "\n��� ����������� ����� � ���� ������ ����-��� ������: ";
	_getch();
}

