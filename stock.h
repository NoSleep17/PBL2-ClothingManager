#pragma once

#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include"customer.h"


using namespace std;
class stock			
{
	public:  
    string type;
    int ma;
    string name;
    int quant;
    float pr;
    void set();
    void static display();
    int stchk(char nm[20]);
    void withd(int qty);
    void static refil();
    void searchByName(string itemName);
    void displayByPrice(bool lowToHigh);
    void searchByType(string itemType);
    void withdraw();
    bool checkDuplicateID(int mahang);
};

bool stock::checkDuplicateID(int mahang) {
    ifstream fin("stock.txt");
    if (!fin.is_open()) {
        cerr << "Error opening shop1.txt for reading." << endl;
        return true; // Assume duplicate to be safe
    }
    int d;
    bool found = false;
    stock *st= new stock[100];

    for(int i=0;i <10000;i++){
        fin >> st[i].ma;
        if(!getline(fin, st[i].name,'.')){
            break;
        }
        fin >> st[i].type >> st[i].quant >> st[i].pr;
        d = d +1;
    }for(int i=0; i< d;i++){
        if (st[i].ma == mahang) {
            found = true;
        }
    }
    delete[] st;

    fin.close();
    return found; // Item with the same ID does not exist
}
void stock::set()
{
    ofstream fout("stock.txt", ios::app);
    if (!fout.is_open()) {
        cerr << "Error opening stock.txt for writing." << endl;
        return;
    }
    stock::display();
    cout << "Enter total ID: ";
    cin >> ma;
    cin.ignore();
    while(checkDuplicateID(ma)){
        cout << "Error: Item with the same ID already exists. Please enter a different ID: ";
        cin >> ma;
        cin.ignore();
    }
    cout << "Enter stock name: ";
    getline(cin,name);
    cout << "Enter total type: ";
    cin >> type;
    cout << "Enter total quanlity: ";
    cin >> quant;
    cout << "Enter total price: ";
    cin >> pr;
    fout << ma << ' ' << name << '.' << type << ' ' << quant << ' ' << pr <<endl;
    fout.close();
}
void stock::display()
{
    cout << "\n==================================================================================================================================";
    cout << "\n\n======================================\tTHE STOCK ITEMS ARE\t==================================================================";
    cout << "\n\n==================================================================================================================================\n";
    cout << left <<setw(30)<< "\n\nID" << setw(30) << "PARTICULARS" << setw(30) <<"TYPE" << setw(30)<<"STOCK AVAILABLE"<< setw(30)<<"PRICE($)";
    cout << "\n\n==================================================================================================================================\n";

    ifstream fin("stock.txt");
    if (!fin.is_open()) {
        cout << "Error opening stock.txt for reading." << endl;
        return;
    }
    stock *st= new stock[100];
    for(int i=0;i<100;i++){
        fin >> st[i].ma;
        fin.ignore();
        if (!getline(fin, st[i].name,'.')) {
            break;
        }
        fin >> st[i].type >> st[i].quant >> st[i].pr;
        cout<< left <<setw(30)<<st[i].ma<< setw(30)<<st[i].name<<setw(30)<<st[i].type<<setw(30)<<st[i].quant<<setw(30)<<st[i].pr<< endl;
        
    }
    delete[] st;
}
void stock::refil() {
    system("cls");
    stock::display();
    cout << "nhap ma san pham:" << endl;
    int mahang;
    cin >> mahang;
    cout << "nhap so luong can them:" << endl;
    int qty;
    cin >> qty;
    ifstream fin("stock.txt");
    if (!fin.is_open()) {
        cerr << "Error opening stock.txt for reading." << endl;
        return;
    }

    ofstream fout("temp.txt");
    if (!fout.is_open()) {
        cout << "Error opening temp.txt for writing." << endl;
        fin.close();
        return;
    }
    
    bool found = false;

    stock *st= new stock[100];
    
    for(int i=0;i<100;i++){
        fin >> st[i].ma;
        if (!getline(fin, st[i].name,'.')) {
            break;
        }
        fin >> st[i].type >> st[i].quant >> st[i].pr;
         if (st[i].ma == mahang) {
            found = true;
            st[i].quant += qty;
        }
        fout << st[i].ma  << st[i].name << '.' << st[i].type << ' ' << st[i].quant << ' ' << st[i].pr << endl;
    }
    

    fin.close();
    fout.close();

    // Rename temp.txt to stock.txt
    if (found) {
        remove("stock.txt");
        rename("temp.txt", "stock.txt");
        cout << "Refill successful." << endl;
    } else {
        remove("temp.txt");
        cout << "Item not found." << endl;
        getch();
    }
    delete[] st;
}
void stock::searchByName(string itemName) {
    ifstream fin("stock.txt");
    bool found = false;

    if (!fin.is_open()) {
        cerr << "Error opening stock.txt for reading." << endl;
        return;
    }

    cout << "\n\nSearch Results for Product with Name \"" << itemName << "\":\n";
    cout << left <<setw(30)<< "\n\nID" << setw(30) << "PARTICULARS" << setw(30) <<"TYPE" << setw(30)<<"STOCK AVAILABLE"<< setw(30)<<"PRICE($)";
    cout << "\n\n==================================================================================================================================\n";


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
    for(int i=0; i< d;i++){
        if (st[i].name == " "+itemName) {
            cout<< left<<setw(30)<<st[i].ma<<setw(30)<<st[i].name<<setw(30)<<st[i].type<<setw(30)<<st[i].quant<<setw(30)<<st[i].pr<< endl;
            found = true;
        }
    }
 

    fin.close();

    if (!found) {
        cout << "Product with Name \"" << itemName << "\" not found." << endl;
    }

    cin.ignore();
}
void stock::displayByPrice(bool lowToHigh) {
    system("cls");
    ifstream fin("stock.txt");
    if (!fin.is_open()) {
        cout << "Error opening stock.txt for reading." << endl;
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
        d = d +1;
    }

    fin.close();

    // Sort the products by price
    for (int i = 0; i < d - 1; ++i) {
        for (int j = 0; j < d - i - 1; ++j) {
            if ((lowToHigh && st[j].pr > st[j + 1].pr) ||
                (!lowToHigh && st[j].pr < st[j + 1].pr)) {
                stock temp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = temp;
            }
        }
    }
    cout << left <<setw(30)<< "\n\nID" << setw(30) << "PARTICULARS" << setw(30) <<"TYPE" << setw(30)<<"STOCK AVAILABLE"<< setw(30)<<"PRICE($)";
    cout << "\n============================================================================================================================\n";

    // Display the sorted products
    for (int i = 0; i < d; ++i) {
        cout<< left<< setw(30)<<st[i].ma<<setw(30)<<st[i].name<<setw(30)<<st[i].type<<setw(30)<<st[i].quant<<setw(30)<<st[i].pr<< endl;
    }

    cin.ignore();
    cin.get();
}
void stock::searchByType(string itemType) {
    ifstream fin("stock.txt");
    bool found = false;

    if (!fin.is_open()) {
        cerr << "Error opening stock.txt for reading." << endl;
        return;
    }

    cout << "\n\nSearch Results for Products with Type \"" << itemType << "\":\n";
    cout << "\nID\t\t\tPARTICULARS\t\tTYPE\t\t\tSTOCK AVAILABLE\t\t\t PRICE";
    cout << "\n==================================================================\n";

    stock *st = new stock [100000];
    
    int d=0;
    fin.open("stock.txt");
    for(int i=0;i <10000;i++){
        fin >> st[i].ma;
        if(!getline(fin, st[i].name,'.')){
            break;
        }
        fin >> st[i].type >> st[i].quant >> st[i].pr;
        d++;
    }
    for(int i=0; i< d;i++){
        if (st[i].type ==itemType) {
            cout<<st[i].ma<<setw(30)<<st[i].name<<setw(30)<<st[i].type<<setw(30)<<st[i].quant<<setw(30)<<st[i].pr<< endl;
            found = true;
        }
    }
    

    fin.close();

    if (!found) {
        cout << "Product with Type \"" << itemType << "\" not found." << endl;
    }

    cin.ignore();
    cin.get();
}

