/*   
     Name:      Krishna rana
     Course:    CIS 160 ME1
     Date:      04/06/2016   
     Program:   Customer Bill at Hospital 
     Description:  This program will gentrate customer's bill based on the input of 
	 			   name,number of days in hospital, room used, phone use and tv access for St. Joseph's Hospital.
*/
#include <iostream>//Standard Input/output streams libary
#include <iomanip>// Header providing parametric manipulators
#include <cctype>//character heading functions

using namespace std;
//Function Prototype
void setdata(string&,int&);
float setroom(int&,string&);
float setphone(int&,string&);
float settv(int&,string&);
void print(string&,int,float,float,float, string&, string&, string&);
//Main() Function Defination
//This function runs the whole program setting step by step intruction written below.
//main() has declaration of string, int, float type of value.
//main() has calls and parameters of other function in the program.
int main()
{	//Declarlation/ Definations
	string name;
	string roomtype, phonetype, tvtype;
	int days;
    float roomcharges,phonecharges,tvcharges;
    // Fuction calls
	setdata(name,days);
	roomcharges = setroom(days,roomtype);
	phonecharges = setphone(days,phonetype);
	tvcharges = settv(days,tvtype);
  	print(name,days,roomcharges,phonecharges,tvcharges,roomtype,phonetype,tvtype); 
  
	cin.get();
	cin.ignore();
	return 0;
}
// Function getdata Definations
// this function is void type,it does not return any value. the use of this function is to get patients names
// and the number of days the patient stayed in hospital. the name and days setted from this function are 
// passed by reference. so it can be used by other functions.
void setdata(string& name,int& days)
{	//Local Definations/ Declarlations
	// Input Section to get name and Number of days in Hospital
	cout<<"Patient name: ";getline(cin,name);
	cout<<"Number of Days in Hospital: "; cin>>days;
}
// Function setroom Definations
// This function is a float type, it returns float value of roomcharges to main().
// This function has constants which are used in for calculation of roomcharges.
// days in this function is passed by reference from setdata(). which is also used to calculate roomcharges.
// This function has if statements which makes decision based on the choice from the menu.
// This function has string roomtype which is also passed by reference to print()..
float setroom(int& days,string& roomtype)
{	//Local Definations /Declartions
	//input section to get informantion about the type of room used
	// constant value declaration.
	const float SINGLE = 325.00;
	const float DOUBLE = 525.00;
	const float WARD = 550.00;
	int choice;
	float roomcharges;
		
	cout<<"\n\t   Room Used\n";
	cout<<"\t   _________\n\n";
	cout<<"\t1- Single room - one bed\n";
	cout<<"\t2- Double room - two beds\n";
	cout<<"\t3- Ward\n\n";
	cout<<"\t\tEnter Choice 1, 2, or 3: ";cin>>choice;// Get the choice from user.
	cout << fixed << showpoint << setprecision(2);//prints answers in 2 decimal spaces.
	// if condition statements based on the choice.
	if(choice == 1)
	{	// if user's choice is 1, he/she is using single room and will be charged on days he/she stayed
		// in hospital using the room.
		roomcharges = (days * SINGLE);
		roomtype = "single room";
	}
	
	else if (choice == 2)
	{	//if user's choice is 2, he/she is using double room and will be charged on days he/she stayed
		// in hospital using the room.
		roomcharges = (days * DOUBLE);
		roomtype = "Double room";
	}
	else if (choice == 3)
	{	//if user's choice is 3, he/she is using ward and will be charged on days he/she stayed 
		//in hospital using the room
		roomcharges = (days * WARD);
		roomtype = "Ward";
	}
		
	else if (choice !=3)
		//if user's choice is invaild and not from the choice he/she will be directed to start the program again.
		cout<<"The choice is invalid\nRun the program again and select one of the choices";
	// return the roomcharges to main() and store the value for further use,
	return roomcharges;
}
// Function setphone Definations
// This function is a float type, it returns float value of phonecharges to main().
// This function has constants which are used in for calculation of phonecharges.
// days in this function is passed by reference from setdata(). which is also used to calculate phonecharges.
// This function has if statements which makes decision based on the choice from the menu.
// This function has string phonetype which is also passed by reference to print().
float setphone(int& days,string& phonetype)
{	//Local Definations / Declarations
	//input section to get informantion if the customer used phone.
	// constant value declarations
	const float SHARED = 2.95;
	const float DEDICATED = 5.95;
	int choice;
	char ch;
	float phonecharges;
	// gets input from user if the customer used phone or denied access.
	cout<<"\nWould You like Phone Access (Y/N): ";cin>>ch;// get the choice from user
	ch = toupper (ch);// charcter heading function to make input captial.
	// if condition statement for if the person choice is yes, that the user used phone accesss.
	if (ch == 'Y')
	{	
		cout<<"\n\t   Phone Access\n";
		cout<<"\t   ____________\n\n";
		cout<<"\t1- Shared\n";
		cout<<"\t2- Dedicated\n";
		cout<<"\t\tEnter Choice 1 or 2: ";cin>>choice;// Get the choice from user.
		cout << fixed << showpoint << setprecision(2);//prints answers in 2 decimal spaces.
		
		if(choice == 1)
		{	// if the user's choice is 1, the phone access will be shared and will be charged on the days he stayed
			// in hospital using the phone service
			phonecharges = (days * SHARED);
			phonetype = "Shared";
		}
		else if (choice == 2)
		{	// if the user's choice is 2, the phone access will be Dedicated and will be charged on the days he stayed
			// in hospital using the phone service
			phonecharges = (days * DEDICATED);
			phonetype = "Dedicated";
		}
		else if (choice !=2)
			// if the user's choice invalid , user will be redirected to start the program and make correct choice.
			cout<<"The choice is invalid\nRun the program again and select one of the choices";
	}
	// if the user says no to the phone service, the phone charges will be $0 and phonetype will be set to none.
	else if (ch == 'N')
	{
		phonecharges = 0.00;
		phonetype = "None";
	}
	// return the phoneharges to main() and store the value for further use
	return phonecharges;
}
//Function settv definations
// This function is a float type, it returns float value of tvcharges to main().
// This function has constants which are used in for calculation of tvcharges.
// days in this function is passed by reference from setdata(). which is also used to calculate phonecharges.
// This function has if statements which makes decision based on the choice from the menu.
// This function has string tvtype which is also passed by reference to print().
float settv(int& days,string& tvtype)
{	//Local definations / Declarations
	//input section to get information if the user used tv access.
	// constant value declarations
	const float BASIC = 2.95;
	const float CABLE = 5.95;
	int choice;
	char ch;
	float tvcharges;
	// gets input from user if the customer used tv or denied access.
	cout<<"\nWould You like TV (Y/N): ";cin>>ch;// get the choice from user
	ch = toupper (ch);// charcter heading function to make input captial.
	// if condition statement for if the person choice is yes, that the user used tv accesss.
	if (ch == 'Y')
	{
		cout<<"\n\t   TV Usage\n";
		cout<<"\t   ________\n\n";
		cout<<"\t1- Basic Channels\n";
		cout<<"\t2- Cable channels\n";
		cout<<"\t\tEnter Choice 1 or 2: ";cin>>choice;// Get the choice from user.
		cout << fixed << showpoint << setprecision(2);//prints answers in 2 decimal spaces.
	
		if(choice == 1)
		{	// if the user's choice is 1, the tv access will be basic and will be charged on the days he stayed
			// in hospital using the tv service
			tvcharges = (days * BASIC);
			tvtype = "Basic";
		}
		else if (choice == 2)
		{	// if the user's choice is 2, the tv access will be cable and will be charged on the days he stayed
			// in hospital using the tv service
			tvcharges = (days * CABLE);
			tvtype = "Cable";
		}
		else if (choice !=2)
			// if the user's choice invalid , user will be redirected to start the program and make correct choice.
			cout<<"The choice is invalid\nRun the program again and select one of the choices";
	}
	// if the user says no to the tv service, the tv charges will be $0 and tvtype will be set to none.
	else if(ch == 'N')
	{
		tvcharges = 0.00;
		tvtype = "None";
	}
	// return the tvharges to main() and store the value for further use
	return tvcharges;
}
// Function print definations with heading, output and footing
// This function is a void type, it does not return any value. This function is used to output result from setdata(), setroom(),
// setphone() and settv().
// print() is an output function it uses name, roomtype, phonetype,and tvtype by reference for which the value are passed from setdata(),
// setroom(), setphone(), settv() respectively.
// print() has locally declared float sum which is used to calculate the total of room, phone, and tv charges.

void print(string& name,int days,float roomcharges,float phonecharges,float tvcharges,string& roomtype, string& phonetype, string& tvtype)
{	// Local definations/ Declarations
	//output section
	float sum = roomcharges + phonecharges + tvcharges;//Total of charges
	
	cout<<"\n\n\t\t\tSt. Joseph's Hospital\n\n";//heading
	cout<<name<<"\'s Billing statement\n\n";
	cout<<"\tNumber of days in hospital: "<<days<<"\t\t(in a "<<roomtype<<")\n\n";// will get valve from main() of days and roomtype
	cout<<"\tRoom Charges\t\t\t\t\t$"<<roomcharges<<endl<<endl;// gets the value from main() of roomcharges returned from getroom()
	cout<<"\tPhone Charges"<<"\t\t("<<phonetype<<")"<<"\t\t   $"<<phonecharges<<endl<<endl;//gets value from main() of phonehcarges
																							// returned from getphone()
	cout<<"\tTelevision Charges"<<"\t("<<tvtype<<")"<<"\t\t\t   $"<<tvcharges<<endl<<endl;//gets value from main() of tvcarges
																						// returned from gettv()
	cout<<"\tTotal Charges\t\t\t\t\t$"<<sum<<endl;// get the total of charges
	cout<<"\n\n\tHope you are satisfied with St.Joseph's Hospital services, Stay Well.";//footing
}
