#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class customer
{
    public:
    string name;
    float totalAmount;
    int makh;
    string sdt[10];
	string getName() const { return name; }
    float getTotalAmount() const { return totalAmount; }
    void withdraw();
    void set();
    void static set(string a);
    void static display();
    void static updatetotalamount(customer b);
    
};

void customer::set()
{
    ofstream fout("customer1.txt", ios::app);
    if (!fout.is_open()) {
        cout << "Error opening customer1.txt for writing." << endl;
        return;
    }
    customer::display();
    cout << "\nEnter customer ID: ";
    cin >> makh;
    cin.ignore();
    cout << "\nEnter customer name: ";
    getline(cin,name);
    cout << "\nEnter customer phone: ";
    string sdt1;
    cin >> sdt1;
    while(sdt1.length() != 10){
        cout<< "\nERROR PHONE, PLS ENTER AGAIN";
        cout << "\nEnter customer phone: ";
        cin >> sdt1;
    }
    fout << makh << " "  <<  name << ".0 "  <<  sdt1 << endl;
    fout.close();
}
void customer::set(string a)
{
    ofstream fout("customer1.txt", ios::app);
    if (!fout.is_open()) {
        cout << "Error opening customer1.txt for writing." << endl;
        return;
    }
    fout << a << ".0" << endl;
    fout.close();
}


void customer::display()
{
    cout << "\n\t\t\t\t\t\tCUSTOMERS\n\n";
    cout << left<< setw(30) << "ID"  << setw(30) << " NAME" << setw(30) << "TOTALAMOUNT" <<setw(30) << "PHONE";
    cout << "\n===================================================================================================\n";
    ifstream fin("customer1.txt");
    if (!fin.is_open()) {
        cout << "Error opening customers.txt for reading." << endl;
        return;
    }
    customer *cust= new customer[100000];
    for(int i=0;i<100000;i++){
        fin >> cust[i].makh;
        if (!getline(fin, cust[i].name,'.')) {
            break;
        }
        fin >> cust[i].totalAmount;
        fin >> cust[i].sdt[10];
        fin.ignore();
        cout  << left << setw(30) << cust[i].makh << setw(30) << cust[i].name << setw(30) << cust[i].totalAmount << setw(30) << cust[i].sdt[10] <<endl ;
    }
    delete[] cust;
}
