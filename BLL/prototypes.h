//Прототипи функцій
//Меню
int Main_Menu();
void Categories_Menu(vector<Categories>&, vector<Product>);
void Company_Menu(vector<Company>&, vector<Product>);
void Product_Menu(vector<Product>&, vector<Categories>&, vector<Company>&);

//Категорії
void Read_Categories(vector<Categories>&);
void Add_Categories(vector<Categories> &);
void Delete_Categories(vector<Categories> &);
void Change_Categories(vector<Categories> &);
void Show_Categories(vector<Categories>, vector<Product>);
void Search_Categories(vector<Categories>);

//Постачальники
void Read_Company(vector<Company>&);
void Add_Company(vector<Company>&);
void Delete_Company(vector<Company>&);
void Change_Company(vector<Company>&);
void Show_Company(vector<Company>, vector<Product>);
void Search_Company(vector<Company>);

//Продукти
void Read_Product(vector<Product>&);
void Add_Product(vector<Product>&, vector<Categories>&, vector<Company>&);
void Change_Product(vector<Product>&, vector<Categories>&, vector<Company>&);
void Show_Product(vector<Product>&);
void Delete_Product(vector<Product>&);
void Search_Product(vector<Product>);
