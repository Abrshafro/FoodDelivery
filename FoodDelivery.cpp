#include <iostream>
#include <stdio.h>
#include <stdlib.h>    /* srand, rand */
#include <time.h>       /* time */
using namespace std;
 struct food
 {


// Storing list of foods in string type array "f menu"
string fmenu[25]=
  {
 "Shiro",
 "spaghetti",
 "Beyainatu",
 "Fuul ",
 "Gomen",
 "key Tibs",
 "Alcha Wot",
 "Firfir",
 "misr wot",
 "vegetable"};

// Storing prices of foods in integer type array "price"
int price[25] ={


  60,
  70,
  80,
  65,
  60,
  130,
  70,
  80,
  75,
  60
  };

int order[5] = { 0,0,0,0,0 }, quantity[5] = { 0,0,0,0,0 }, quant = 0, total = 0, county=0;} ored;

//variable for bank or tele birr deposit
int deposit;
//function which restrict the user to input only allowable values
int check(int n)
{
	int value;
	label:
	cin >> value;
	int sign = 0;

	if (value >= 1 && value <= n)
    {
		sign = value;
	}

	if (sign == 0)
	{
		cout << "enter the appropriate number among the choices 1 up to " << n << endl;
		goto label;
	}
	else {
		return sign;
	}
    }


//a function for taking order
int order_func()
{
	int i = 0;

	do
	{
		int no_or_yes = 0;
		ored.order[i] = check(10);
		cout << endl << endl;
		cout<<"How many " << ored.fmenu[ored.order[i] - 1] << " should we order for you?\n"<<endl;
        cout<<"you can have up to 5 order in total\n";
		adjust:
		ored.quantity[i] = check(5);
		ored.quant += ored.quantity[i];

		if (ored.quant < 5)
		{
			cout << "do you want another order\n";
			cout << "enter 0 if it is enough and any other number if it is not"<<endl;
			cin >> no_or_yes;
		}

		else if(ored.quant == 5)
		{
			break;
		}

		else
		{
			cout <<"you have ordered total of " << ored.quant << " foods.";
			cout<<" you can order up to only 5 foods, please adjust your quantity for ";
			cout<<ored.fmenu[ored.order[i] - 1]<<"\n";
			ored.quant -= ored.quantity[i];
            ored.quantity[i] = 0;

			goto adjust;
		}

		if (no_or_yes == 0)
		{
			break;
		}
		else
        {
			cout <<"\n you can select another order of your choice\n";
		}
		i++;

    }
    while (ored.quant <= 5);

	for (int i = 0; ored.order[i] != 0; i++)
	{
		ored.total += (ored.price[ored.order[i] - 1] * ored.quantity[i]);
	}

	cout << "we have taken your order, please provide delivery information";
	return 0;
    }

/*-a function that checks the bank deposit of the costumer to see if they can afford
   the price of the food they ordered */
  int deposit_check(string a)
    {
	if (ored.county == 0)
    {
        srand(time(0));
        deposit = rand() % 19500 + 500;
        cout<<"your " <<a<<" Balance is: "<<deposit<<endl;
    }
	if(ored.county == 0)
        {

	if (deposit < ored.total)
		{
			cout << "your balance is insufficient to accommodate your order bill\n"<<endl;
			cout << "please try again";
			ored.county++;
			return 0;
		}

		}
	return 1;
        }

  int main()
   {
    system("color e");
	cout<<"\n\n";
	cout<<"##      ## ######## ##        ######   #######  ##     ## ########"<<endl;
	cout<<"##  ##  ## ##       ##       ##    ## ##     ## ###   ### ##      "<<endl;
	cout<<"##  ##  ## ##       ##       ##       ##     ## #### #### ##      "<<endl;
	cout<<"##  ##  ## ######   ##       ##       ##     ## ## ### ## ######  "<<endl;
	cout<<"##  ##  ## ##       ##       ##       ##     ## ##     ## ##      "<<endl;
	cout<<"##  ##  ## ##       ##       ##    ## ##     ## ##     ## ##      "<<endl;
	cout<<" ###  ###  ######## ########  ######   #######  ##     ## ########"<<endl;

	start:

	cout << "\n\t\t\tBIT STAFF LOUNGE\n" << endl;
	cout << "BIT Staff Lounge foods menu  - \n" << endl;

	for (int i = 0; i < 10; i++)
	{

		// Showing food menu to customer
		cout << i + 1 << ". " << ored.fmenu[i] << "\t\t\t" << ored.price[i] << endl;

	}
	// Storing payment methods in string type array "payment"
	string payment[25] =
	{

	  "BANK",
	  "TELE BIRR",
	};

	int cpayment;
	string no_or_yes;
	string name, contact, delivery, PIN_num, telebirr_account;


	cout << "Here is our menu, you can select order of your choice\n";

	// Taking order from customer
	order_func();

	cout << "\n\n\n\nDELIVERY DETAILS\n\n";

	// Taking delivery details from customer
	cout << "Enter Your Name : ";
	cin >> name;
	cout << "Enter Contact Number : ";
	cin >> contact;
	cout << "Enter Delivery Address : ";
	cin >> delivery;

	cout << "\n\n\t\t\tYOUR BILL\n\n";


	// Showing bill with customer details
	for (int i = 0; ored.order[i] != 0; i++)
	{
    cout << ored.fmenu[ored.order[i] - 1] << " = " << ored.quantity[i] << "\t\t\t";
    cout<< ored.price[ored.order[i] - 1] << " * " << ored.quantity[i] << endl;
	}

	cout << "\n------------------------------------------------------------"<<endl;
	cout << "------------------------------------------------------------\n";
	cout << "Total : " << "\t" << ored.total << " birr\n" << endl;
	cout <<"name:\t\t"<< name << endl;
	cout <<"contact:\t"<<contact << endl;
	cout <<"Delivery:\t"<< delivery << endl;

	cout << "\n\n\t\t\tPAYMENT INFORMATION\n\n";
	cout << "Dear customer we accept the payment in - \n\n";

	for (int i = 0; i < 2; i++)
	{

		// Showing payment options to customer
		cout << i + 1 << ". " << payment[i] << endl;

	}

	cout << "\nSelect your desired payment method : ";

	// Taking input from customer
	cpayment = check(2);
	if (cpayment == 1)
	{
		cout << "1.Commercial Bank of Ethiopia\n";
		cout << "2.Abbysinia Bank\n";
		cout << "3.Dashen Bank\n";
		cout << "4.Abay Bank\n";
		cout << "5.zemen Bank\n";
		cout << "6.Berhan Bank\n";
		cout << "7.Cooperative Bank of Oromia\n";
		cout << "8.Awash Bank\n";

		int bank;
		cout << "\nselect the bank you want to pay\n";
		which_bank:
		bank = check(8);
			cout << "\nEnter Your pin : " << endl;
			cin >> PIN_num;
			if(deposit_check("bank") == 0)
			{
					goto start;
			}
	}
	else
	{

		// Taking payment number from customer
		cout << "\nEnter Your telebirr account :" << endl;
		cin >> telebirr_account;

		if(deposit_check("tele_birr") == 0)
			{
				goto start;
			}
	}

	cout << endl<<"\nWe have received your order"<<endl;
	cout <<"\n we will deliver your order to your doorstep shortly \n";


	if (cpayment == 2 && ored.total > 150)
	{

		// Customers will get discount when orders more than 400 birr using tele birr
		cout << "\n Congratulations! You are eligible for birr 10% cash back" << endl;
		cout << "\n You got " << ored.total * 10 / 100 << " birr as cash back from BIT Staff Lounge" << endl;

	  }

	else if (ored.total > 300)
	  {

		// Customers will get discount when orders more than 600 birr
		cout << "\n Congratulations!You are eligible for birr 6% cash back";
		cout <<"You got " << ored.total * 6 / 100 << "birr as cash back from BIT Staff Lounge" << endl;

	   }

	//customer satisfaction
	cout << endl << endl<<"if you enjoy our service, please leave a comment and ratting\n";
	char comment[100];
	cout << endl << endl << "any comment or suggestion?" << endl;
	cin >> comment;
	float rating;
	cout << endl << "rating:  rate us from 1 to 5\n";
	rating = check(5);
	if (rating < 4)
        {
		cout << "thank you for the rating, we will try to improve our service\n";
	    }
	else
	    {
		cout << "we are glad to have you. thank you for choosing us \n\n";
		cout << "ENJOY YOUR MEAL\n\n";
	    }

	return 0;
  }

