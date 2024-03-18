#include"purchase.h"
#include"stock.h"
#include"customer.h"

template<typename T>
T check(T& z)
{
    while (cin.fail()) {
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter AGAIN: ";
        cin >> z;
    }
    return z; // Return the valid input
}
void withdraw() {
    system("cls");
    int numProducts;
    cout << "Nhap so luong san pham muon mua: ";
    cin >> numProducts;
    check(numProducts);
    cin.ignore();
    string tempname;
    float totalAmount2 = 0;
    system("cls");
    customer::display();
    cout <<"nhap ma khach hang mua san pham:"<< endl;
    int makh1;
    cin >> makh1;
    check(makh1);
    ifstream fin("customer1.txt");
    if (!fin.is_open()) {
        cout << "Error opening customers.txt for reading." << endl;
        return;
    }
    customer *cust=new customer[1000];
    int b;
    for(int i = 0; i<1000;i++){
        fin >> cust[i].makh;
        if (!getline(fin, cust[i].name,'.')) {
            break;
        }
        fin >> cust[i].totalAmount;
        fin >> cust[i].sdt[10];
        fin.ignore();
        if(cust[i].makh == makh1){
            b=i;
            break;
        }
    }
    fin.close();
    int productId;
    int qty;
    stock *st = new stock [100000];
    
    stock *stpurchase = new stock[100]; 
    int purchasedProductsCount = 0;
    fstream fio;
    int d=0;
    fio.open("stock.txt", ios::out | ios::in);
    if (!fio.is_open()) {
        cout << "Error opening customers.txt for reading." << endl;
        return;
    }
    for(int i=0;i <10000;i++){
        fio >> st[i].ma;
        if(!getline(fio, st[i].name,'.')){
            break;
        }
        fio >> st[i].type >> st[i].quant >> st[i].pr;
        d++;
    
    }
    fio.close();
    bool found = false;
    for (int a = 0; a < numProducts; ++a) {
        stock::display();
        cout << "\nNhap ma san pham thu " << a + 1 << ": ";
        cin >> productId;
        for(int i=0;i <10000;i++){
            if (st[i].ma == productId) {
                found = true;
                cout << "Gia cua san pham: " << st[i].pr << endl;
                cout << "Nhap so luong: ";
                cin >> qty;
                if (qty <= st[i].quant) {
                    float totalAmount1 = st[i].pr * qty;
                    cout << "Tong so tien: " << totalAmount1 << endl;
                    totalAmount2 += totalAmount1;
                    st[i].quant -= qty;
                    stpurchase[purchasedProductsCount].ma = st[i].ma;
                    stpurchase[purchasedProductsCount].name = st[i].name;
                    stpurchase[purchasedProductsCount].type = st[i].type;
                    stpurchase[purchasedProductsCount].quant = qty;
                    stpurchase[purchasedProductsCount].pr = totalAmount1;
                    purchasedProductsCount++;
                } else {
                    cout << "So luong khong du trong kho." << endl;
                }
            }
        }
        if (!found) {
            cout << "\nSan pham co ma " << productId << " khong tim thay." << endl;
        }
    }
        ofstream tempFile("temp.txt");
        if(found){
        purchase c;
        c.setvalue(cust[b] ,numProducts, totalAmount2);
        ofstream fout1("purchase1.txt", ios::app);
        if (!fout1.is_open()) {
        cout << "Error opening purchase.txt for writing." << endl;
        return;
    }
        fout1 << c.madon << cust[b].name << '.' << numProducts << ' ' << totalAmount2 << endl;
        for(int i = 0 ;i < numProducts; i++){
            fout1 << stpurchase[i].name << "."<< stpurchase[i].quant << " ";
        }
        fout1 << endl;
        fout1.close();
        

        for(int i=0; i< d;i++){
            tempFile << st[i].ma  << st[i].name << '.' << st[i].type << ' ' << st[i].quant << ' ' << st[i].pr <<endl;
        }
    }
    cout <<"TOTAL AMOUNT:"<< totalAmount2<< endl;
    int choice;
    cout << "Prinf purchase ? (y/n)"<< endl;
    choice:
    cout << "yes:1        no:0"<< endl;
    cin >> choice;
    check(choice);
    if(choice == 1){
    system("cls");
    cout << "====================PURCHASE=================="<<endl;
    cout <<"CUSTOMER NAME:"<< cust[b].name<<endl;
    cout <<"CUSTOMER PHONE:"<< cust[b].sdt[10]<<endl;
    cout << "\n=============================================="<<endl;
    cout <<setw(20)<<"Name Product"<<setw(20)<<"QUANLITY"<<setw(20)<<"TOTALALMOUT($)"<<endl;

    for(int i =0 ;i <purchasedProductsCount;i++){
        cout<<left<< setw(20)<< stpurchase[i].name << setw(20)<< stpurchase[i].quant << setw(20)<< stpurchase[i].pr << endl;
    }
    cout <<"TOTAL AMOUNT:                           "<< totalAmount2<<"$" <<endl;
    }else if(choice == 0) {
        cout << "no prinft"<< endl;
    }
    else{
        cout << "wrong choice" << endl;
        goto choice;
    }
    
    tempFile.close();
    remove("stock.txt");
    rename("temp.txt", "stock.txt");
    delete[] cust;
    delete[] st;
    delete[] stpurchase;
}

void addnew()
{
    cout << "\nEnter the No. of Products that you wish to add: ";
    int n;
    cin >> n;
    system("cls");
    if (n > 0){
    for(int i=0; i<n; i++){
            stock st;
            st.set();
            system("cls");
            cout << "\n\nStock Updated!!";
    }
    }else{
        cout << "No stock update"<< endl;
    }
    
}
void removeItem(int mahang) {
    ifstream fin("stock.txt");
    ofstream foutTemp("temp.txt");

    if (!fin.is_open() || !foutTemp.is_open()) {
        cout << "Error opening files for reading/writing." << endl;
        return;
    }

    stock *st = new stock [100000];
    
    int d=0;
    
    for(int i=0;i <10000;i++){
        fin >> st[i].ma;
        if(!getline(fin, st[i].name,'.')){
            break;
        }
        fin >> st[i].type >> st[i].quant >> st[i].pr;
        d++;
    }
    for(int i=0;i <d;i++){
            if (st[i].ma != mahang) {
            foutTemp << st[i].ma <<""<< st[i].name << "." << st[i].type << " " << st[i].pr << " " << st[i].quant << endl;
        }
        }
    foutTemp.close();
    fin.close();
    remove("stock.txt");
    rename("temp.txt", "stock.txt");
    cout << "\n\nItem removed successfully." << endl;
    cin.ignore();
    cin.get();
}
void remove() {
    system("close");
    int mahang;
    stock st;
    st.display();
    cout << "\nEnter the ma of the item you want to remove: ";
    cin.ignore();
    cin >> mahang;

    removeItem(mahang);
}
void searchitem(){
    stock st;
    string itemName;
            cout << "Enter the name of the item you want to search: ";
            getline(cin, itemName);
            st.searchByName(itemName);
}


