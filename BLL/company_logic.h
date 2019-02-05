//����� �������������
void Add_Company(vector<Company>& company)
{
	system("cls");
	cout << "\t �������� ������������� " << endl << endl;
	Company temp;
	temp.add_company();
	temp.write();

	company.push_back(temp);

	cout << "������������� ������!" << endl;
	cout << "��� ����������� ����� � ���� ������ ����-��� ������: ";
	_getch();
}

void Show_Company(vector<Company> company, vector<Product> product)
{
	system("cls");
	cout << "\t������������� " << endl << endl;
	TextTable t( '-', '|', '+' );
	
	t.add( "#" );
    t.add( "���" );
    t.add( "ϲ�" );
    t.add( "ʳ������ ������" );
    t.add( "�������� ���� ������" );
    t.endOfRow();
    
	int product_count, total_price = 0;
	
	for (int i(0); i < company.size(); i++)
	{
		product_count = total_price = 0;
		
		for (int y(0); y < product.size(); y++)
		{
			if(strcmp(product[y].get_organisation(), company[i].get_organisation()) == 0)
			{
				product_count++;
				total_price += product[y].get_price() * product[y].get_amount();
			}
		}
		
		t.add(to_string(i));
		t.add(company[i].get_organisation());
    	t.add(company[i].get_fio());
    	t.add(to_string(product_count));
    	t.add(to_string(total_price));
    	t.endOfRow();
				
//		company[i].show_company(product_count, total_price);
	}
    
	cout << t << endl << "��� ����� ������� ����, ������ ����-��� ������: ";
	_getch();	
} 

void Delete_Company(vector<Company>& company)
{
	system("cls");
    cout << "\t�������� �������������" << endl << endl;
	int id;
    bool delete_check = false; 
	cout << ": ";
	cin >> id;
	cout << endl;

	int i = 0;

	if (id < company.size())
	{
		delete_check = true;			
		company.erase(company.begin() + id);
		cout << "������������� ��������!" << endl;
	}
	
	if(delete_check == true)
	{	
		company[0].rewrite();
		i = 1;
		
		while (i < company.size())
		{
			company[i].write();
			i++;
		}
	}
	
	cout << "\n��� ����������� ����� � ���� ������ ����-��� ������: ";
	_getch();
}

void Change_Company(vector<Company>& company)
{
	system("cls");
    cout << "\t������ �������������" << endl << endl;
    cout << ":";
    
    int id = 0;
 	cin >> id;
	cout << endl;
	
	if (id < company.size())
	{	
	    company[id].chg_company();	
	    company[0].rewrite();
		int i = 1;
		
		while (i < company.size())
		{
			company[i].write();
			i++;
		}
		cout << "������������� ������!" << endl;
	}
	else
	{
		cout << "\nϳ� #" << id << " �� �������� �������������"<< endl;
	}
	
	cout << "\n��� ����������� ����� � ���� ������ ����-��� ������: ";
	_getch();
}

void Search_Company(vector<Company> company)
{
	system("cls");
    cout << "\t����� �������" << endl << endl;
	char query[30];
	cout << ": ";
	cin.ignore();
	cin.getline(query, sizeof(query));
	cout << endl;

	int i = 0;
	cout << "����������: " << endl << endl;
	while (i < company.size())
	{
		if (company[i].search(query))
		{
			company[i].get_organisation();
			cout << endl;
		}
		i++;
	}

	cout << "\n��� ����������� ����� � ���� ������ ����-��� ������: ";
	_getch();
}
