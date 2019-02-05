//������ ����
int Main_Menu()
{
	system("cls");
	cout << "\t������� ����" << endl << endl;
	cout << "1. ������� " << endl;
	cout << "2. ������������� " << endl;
	cout << "3. ����� " << endl;		
	cout << endl << "0. �����" << endl;
	cout << endl << ": ";
	int item;
	cin >> item;
	return item;
}

//������� ����
void Categories_Menu(vector<Categories>& categories, vector<Product> product)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\t�������." << endl << endl;
		cout << "1. �� ������� " << endl;
		cout << "2. ������" << endl;
		cout << "3. ��������" << endl;
		cout << "4. ������" << endl;
		cout << "5. �����" << endl;
		cout << endl <<"0. ����� " << endl;
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
			cout << endl << "����������� ���!" << endl;
			cout << "��� ����� ������� ����, ������ ����-��� ������: ";
			_getch();
			continue;
		}
		}
	}
}

//������������ ����
void Company_Menu(vector<Company>& company, vector<Product> product)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\t�������������" << endl << endl;
		cout << "1. �� �������������" << endl;
		cout << "2. ������" << endl;
		cout << "3. ��������" << endl;
		cout << "4. ������" << endl;
		cout << "5. �����" << endl;
		cout << endl <<"0. ����� " << endl;
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
			cout << endl << "����������� ���!" << endl;
			cout << "��� ����� ������� ����, ������ ����-��� ������: ";
			_getch();
			continue;
		}
		}
	}
}

//������ ����
void Product_Menu(vector<Product>& product, vector<Categories>& categories, vector<Company>& company)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\t������" << endl << endl;
		cout << "1. �� ������" << endl;
		cout << "2. ������" << endl;
		cout << "3. ��������" << endl;
		cout << "4. ������" << endl;
		cout << "5. �����" << endl;
		cout << endl <<"0. ����� " << endl;
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
			cout << endl << "����������� ���!" << endl;
			cout << "��� ����� ������� ����, ������ ����-��� ������: ";
			_getch();
			continue;
		}
		}
	}
}
