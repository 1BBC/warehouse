//«читуванн€ з фал≥в 
void Read_Categories(vector<Categories> &categories)
{
	Categories temp;
	int i = 0;

	if (temp.count_File() != 0)
		while (i < temp.count_File())
		{
			temp.read(i);
			categories.push_back(temp);
			i++;
		}
}

void Read_Product(vector<Product> &product)
{
	Product temp;
	int i = 0;

	if (temp.count_File() != 0)
		while (i < temp.count_File())
		{
			temp.read(i);
			product.push_back(temp);
			i++;
		}
}

void Read_Company(vector<Company> &company)
{
	Company temp;
	int i = 0;

	if (temp.count_File() != 0)
		while (i < temp.count_File())
		{
			temp.read(i);
			company.push_back(temp);
			i++;
		}
}
