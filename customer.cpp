#include"purchase.h"
#include"stock.h"
#include"customer.h"
void addcustomer(){
    cout << "\nEnter the Number Of Customer That You Wish To Add: ";
    int n;
    cin >> n;
    if (n > 0){
    for(int i=0; i<n; i++){
        customer cust;
        cust.set();
    }
    }else{
        cout << "ERRRO NUMBER OF CUSTOMER!"<< endl;
    }
    cout << "\n\nCustomer Updated!!";
}