#include<conio.h>
#include<limits>
#include"customer.h"
#include"stock.h"
#include"purchase.h"
#include"stock.cpp"
#include"customer.cpp"
using namespace std;


int main()
{
	char pass[10],pass2[10];
	int i,j;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|====================== WELCOME TO STORE MANAGEMENT ========================|";
	getch();
    menu:
	system("cls");
	cout<<"\n\t\t   STORE MANAGEMENT SYSTEM\n";
    cout<<"\n\t\t   CODED BY HZ AND BAO \n";	
	cout<<"==========================================================================================";
	cout<<"\n\n\t\t   1. Dealer Menu\n\n\t\t   2. Customer Menu\n\n\t\t   3. Employee Menu\n\n\t\t   4.Exit   ";
	cout<<"\n\n=========================================================================================\n";
	cout<<"\n\nEnter Your Choice:";
	cin>>j;
    check(j);
	/* while (cin.fail()) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); i
        cout << "Invalid input. Please enter valid values: ";
        cin >> j;
    } */
    if(j==4)
    {
        system("cls");
	    cout<<"\n\n\n\t\t\tTHANK YOU";
	    getch();
         
	    exit(0);
    }
	else if(j==1)
	{
	
    system("cls");
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
	
	for(int z=0;z<6;z++)
	{
		pass[z]=getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	if(1)
	{
    /*cout<<"\n\n\nCongrats!!Access Granted!!\n\n";
    getch();*/
    system("cls");
	dealermenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    DEALER MENU\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Display history purchase\n6. Display purchase sort by customer\n7. Display Purchase Peach By Customer Name\n8. Back to Main menu \n9. Exit :";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
    check(i);
	/* while (cin.fail()) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter valid values: ";
        cin >>i;
    } */
	if(i==1)
	{
        addnew();
        getch();
         
	    goto dealermenu;
	}

	else if(i==2)
	{
	  system("cls");
      stock st;
      st.display();
      getch();
       
      goto dealermenu;
	}
	else if(i==3)
	{
		stock st;
        st.refil();
        goto dealermenu;
	}
	else if(i==4)
	{
	    remove();
        getch();
        goto dealermenu;
	}
	else if(i==5)
	{
		system("cls");
		purchase::display();
        getch();
        goto dealermenu;
	
	}
	else if(i==6)
	{
		system("cls");
		purchase::display1();
        getch();
        goto dealermenu;
	}
	else if(i==7)
    {
        system("cls");
        cout << "Nhap Ten Khach Hang:" << endl;
		string cusname;
		cin.ignore();
        getline(cin, cusname);
		purchase::SeachByName(cusname);
		getch();
        goto dealermenu;
    }
    else if(i==8)
    {
        system("cls");
        goto menu;
    }
	else if (i==9)
	{
		system("cls");
    	cout<<"\n\n\n\t\t\tTHANK YOU";
    	getch();
    	exit(0);
}

}
/*else
{
	cout<<"\n\n\nAuthorised Personnel Only\n\n";
	getch();
	getch();
	getch();
	getch();
	getch();
	getch();
	exit(0);
}*/
	}
	else if(j==2)
	{
		custmenu:
	system("cls");
	cout<<"==============================================================================";
	cout<<"\n\n\t\t\t    CUSTOMER MENU\n1. Purchase\n2. Display Stock\n3. Addcusstomers\n4.Display Customer\n5.Display Stock Search Name\n6.PriceSort\n7.Back to Main menu\n8.Exit \t ";
	cout<<"\n\n\n==========================END OF MENU===================================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
    check(i);
	/* while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter valid values: ";
        cin >> i;
    } */
	
	if (i==1)
	{
	    withdraw();
        getch();
        goto custmenu;
	}
	else if(i==2)
	{
		system("cls");
	    stock st;
        st.display();
        getch();
         
        goto custmenu;
	}
	
	else if(i==3)
	{
		system("cls");
		addcustomer();
		goto custmenu;
	}
	else if(i==4)
	{
		system("cls");
		customer cust;
        cust.display();
		getch();
        goto custmenu;
	}
   
    else if(i==5)
    {
		system("cls");
        string itemName;
            cout << "Enter the name of the item you want to search: ";
			cin.ignore();
            getline(cin , itemName);
			system("cls");
            stock st;
			st.searchByName(itemName);
        
        goto custmenu;
    }
    else if(i==6)
    {
		stock st;
         int priceChoice;
            cout << "Display Products by Price:\n";
            cout << "1. Low to High\n";
            cout << "2. High to Low\n";
            cout << "Enter your choice: ";
            cin >> priceChoice;
            check(priceChoice);

            switch (priceChoice) {
                case 1:
                    st.displayByPrice(true);
                    break;
                case 2:
                    st.displayByPrice(false);
                    break;
                default:
                    cout << "Invalid choice for sorting by price." << endl;
                    
            }
             
            goto custmenu;
    }
    
    else if(i==7)
    {
        system("cls");
         
        goto menu;
    }
    else if(i==8)
	{
		system("cls");
	    cout<<"\n\n\n\t\t\tTHANK YOU";
	    getch();
         
	    exit(0);
	}

    else 
    {
        cout << "Error!! . Please import the correct number ";
        system("cls");
         
        goto custmenu; 
    }
	
}
else if(j==3)

{
	system("cls");
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
	
	for(int z=0;z<3;z++)
	{
		pass2[z]=getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	if(1)
	{
	empmenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\tEMPLOYEE MENU\n1. Display stock\n2. Refill\n3. Display Purhchase By Customer Name\n4. Back to Main menu\n5. Exit  ";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
    check(i);
	/* while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter valid values: ";
        cin >> i;
    } */
	if(i==1)
	{
	system("cls");
	stock::display();
    getch();
     
    goto empmenu;
	}
	else if(i==2)
	{
		stock::refil();
        goto empmenu;
	}
    else if(i==3)
    {
        system("cls");
        cout << "Nhap Ten Khach Hang:" << endl;
		string cusname;
		cin.ignore();
        getline(cin, cusname);
		purchase::SeachByName(cusname);
		getch();
        goto empmenu;
    }
    else if(i==4)
    {
        system("cls");
        goto menu;
    }
    else if(i==5)
	{
	    system("cls");
	    cout<<"\n\n\n\t\t\tThank You!!";
	    getch();
	    exit(0);
    }
    else 
    {
        cout << "Error!! . Please import the correct number ";
        system("cls");
        goto empmenu; 
    }
}

}
else{
	cout << "ERROR Choice! Pls enter again!"<< endl;
	getch();
	goto menu;
	
}	
	getch();
}
