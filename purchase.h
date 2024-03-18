#pragma once
#include"customer.h"
#include"stock.h"
#include <cstdlib>
#include <unordered_map>
class purchase : public customer, public stock
{
    public:
    int soluong;
    int paid;
    int madon;
    customer cust1;
    stock st[100];
    void setvalue(customer cust,int soluong,int paid);
    void static set(purchase a);
    void static inhoadon(int number);
    void static display();
    int static checkDuplicateID();
    void static display1();
    void static SeachByName(string cusname);
};
int purchase::checkDuplicateID() {
    ifstream fin("purchase1.txt");
    if (!fin.is_open()) {
        cout << "Error opening purchase.txt for reading." << endl;
        return true; 
    }
    int d=0;
    int temp;
    purchase *pur= new purchase[10000];
    for(int i=0;i<10000;i++){
        fin >> pur[i].madon;
        if (!getline(fin, pur[i].cust1.name,'.')) {
            break;
        }
        fin >> pur[i].soluong >> pur[i].paid;
        fin.ignore();
        for(int j=0; j < pur[i].soluong;j++){
        getline(fin, pur[i].st[j].name,'.');
        fin >> pur[i].st[j].quant;
        fin.ignore();
        }
        d++;
    }
    temp = pur[d-1].madon + 1;
    delete[] pur;
    

    fin.close();
    return temp; // Item with the same name does not exist
}



void purchase::setvalue(customer cust,int soluong,int paid){

    cust1 = cust;
    soluong = soluong;
    paid = paid;
    madon = purchase::checkDuplicateID();

    // ofstream fout("purchase.txt", ios::app);
    // if (!fout.is_open()) {
    //     cout << "Error opening purchase.txt for writing." << endl;
    //     return;
    // }
    // fout << madon << cust1.name << '.' << soluong << ' ' << paid << endl;
    // fout.close();
   
}
void purchase::SeachByName(string cusname){
    ifstream fin("purchase1.txt");
    if (!fin.is_open()) {
        cout << "Error opening purchase.txt for reading." << endl;
        return;
    }
    int d=0;
    purchase *pur= new purchase[10000];
    cout << left << setw(30) << "ID" << setw(30) << "CUSTOMER" << setw(30) << "QUANLITY" <<setw(30) << "PAID($)";
    cout << "\n======================================================================================================\n";
    for(int i=0;i<1000;i++){
        fin >> pur[i].madon;
        if (!getline(fin, pur[i].cust1.name,'.')) {
            break;
        }
        fin >> pur[i].soluong >> pur[i].paid;
        fin.ignore();
        for(int j=0; j < pur[i].soluong;j++){
        getline(fin, pur[i].st[j].name,'.');
        fin >> pur[i].st[j].quant;
        fin.ignore();
        }
        
        d++;
    }

    for(int i =0; i< d;i++){
        if(pur[i].cust1.name == ' '+cusname){
        cout<< left<<setw(30)<<pur[i].madon<<setw(30)<<pur[i].cust1.name<<setw(30)<<pur[i].soluong<<setw(30)<<pur[i].paid<< endl;
        }
    }
    fin.close();
   
    cout << "Ban Co Muon In Hoa Don:" << endl;
    cout <<"1:yes\n" << "0:no"<< endl;
	int choice;
	cin >> choice;
	while(choice !=1 && choice != 0){
		cout << "Error Choice!\n" << "pls enter choice aganin!" << endl;
		cin >> choice;
	}
	if(choice=1){
		cout << "pls enter ID purchase for prinft" << endl;
        int ma;
        cin >> ma;
        
        for (int i=0; i< d ;i++){
        if(pur[i].madon == ma){
        cout << "====================PURCHASE=================="<<endl;
        cout <<"CUSTOMER NAME:"<< pur[i].cust1.name<<endl;
        cout <<"CUSTOMER PHONE:"<< pur[i].cust1.sdt[10];
            cout << "\n=============================================="<<endl;
        cout <<setw(20)<<"Name Product"<<setw(20)<<"QUANLITY"<<endl;

        for(int j=0 ;j < pur[i].soluong; j++){
        cout<<left<< setw(20)<< pur[i].st[j].name << setw(20)<< pur[i].st[j].quant << endl;
    }
    cout <<"TOTAL AMOUNT:       "<< pur[i].paid << "$"<< endl;
    }
    }
    delete[] pur;
    }
}
       


void purchase::display(){
    ifstream fin("purchase1.txt");
    if (!fin.is_open()) {
        cout << "Error opening purchase1.txt for reading." << endl;
        return;
    }
    int d=0;
    int doanhthu =0;
    purchase *pur= new purchase[10000];
    cout << left << setw(30) << "ID" << setw(30) << "CUSTOMER" << setw(30) << "QUANLITY" <<setw(30) << "PAID($)";
    cout << "\n======================================================================================================\n";
    for(int i=0;i<1000;i++){
        fin >> pur[i].madon;
        if (!getline(fin, pur[i].cust1.name,'.')) {
            break;
        }
        fin >> pur[i].soluong >> pur[i].paid;
        fin.ignore();
        for(int j=0; j < pur[i].soluong;j++){
        getline(fin, pur[i].st[j].name,'.');
        fin >> pur[i].st[j].quant;
        fin.ignore();
        }
        cout<< left<<setw(30)<<pur[i].madon<<setw(30)<<pur[i].cust1.name<<setw(30)<<pur[i].soluong<<setw(30)<<pur[i].paid<< endl;
        d++;
    }
    for(int i =0; i< d;i++){
        doanhthu+=pur[i].paid;
    }
    fin.close();
    cout <<"Tong Doanh thu:"<< doanhthu << "$"<<endl;
    delete[] pur;
}
void purchase::display1() {
    ifstream fin("purchase1.txt");
    if (!fin.is_open()) {
        cerr << "Error opening purchase.txt for reading." << endl;
        return;
    }

    int d = 0;
    purchase *pur = new purchase[10000];
    unordered_map<string, int> totalPaidByCustomer;

     for(int i=0;i<1000;i++){
        fin >> pur[i].madon;
        if (!getline(fin, pur[i].cust1.name,'.')) {
            break;
        }
        fin >> pur[i].soluong >> pur[i].paid;
        fin.ignore();
        for(int j=0; j < pur[i].soluong;j++){
        getline(fin, pur[i].st[j].name,'.');
        fin >> pur[i].st[j].quant;
        fin.ignore();
        }
        d++;
        totalPaidByCustomer[pur[d - 1].cust1.name] += pur[d - 1].paid;
    }

    for (int i = 0; i < d - 1; i++) {
        for (int j = i + 1; j < d; j++) {
            if (totalPaidByCustomer[pur[i].cust1.name] < totalPaidByCustomer[pur[j].cust1.name]) {
                swap(pur[i], pur[j]);
            }
        }
    }

    cout << left << setw(30) << " CUSTOMER" << setw(30) << "TOTAL PAID($)"<< endl;
    cout << "=====================================\n";
    for (int i = 0; i < d; i++) {
        if (totalPaidByCustomer[pur[i].cust1.name] > 0) {
            cout << left << setw(30) << pur[i].cust1.name << setw(30) << totalPaidByCustomer[pur[i].cust1.name] << endl;
            totalPaidByCustomer[pur[i].cust1.name] = 0; 
        }
    }
    fin.close();
    delete[] pur;
}