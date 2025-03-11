#include<iostream>
#include<iomanip>
using namespace std;
int main(){
//	int Balance=1000;
//	int NewBalance;
//	int RemainBalance;
//	int Exit;
//	while(1){
//		int choise;
//	cout<<"\n choose from the following"<<endl;
//	cout<<" 1 for Deposit Money\n";
//	cout<<" 2 for withdraw Money\n";
//	cout<<" 3 for check Balance\n";
//	cout<<" 4 for Exit\n";
//	cin>>choise;
//		
//		switch(choise){
//			case 1:
//				int deposit;
//				cout<<"\n how much you want to deposet?\n ";
//				cin>>deposit;
//				Balance=Balance+deposit;
//				cout<<deposit<<" Deposet Successfuly !\n"<<endl;
//				break;
//			case 2:
//				int withdraw;
//				cout<<"\n how much you want to withdraw?\n";
//				cin>>withdraw;
//				Balance=Balance-withdraw;                            
//				cout<<withdraw<<" Withdraw Successfuly !\n"<<endl;
//				break;
//			case 3:
//			    cout<<"\nYour Current Balance is: "<<Balance<<endl;
//				break; 
//
//			case 4:
//				cout<<" Thanks for using our ATM !\n";
//				return 0;
//				break;
//		}
//		
//	}

	
	//print up to N
	
//	int n;
//	int a=0;
//	cout<<"\n\nEnter a number up to which you want to print all the numbers :";
//	cin>>n;
//	cout<<"\nThe numbers you want are\n\n";
//	while(a<n){
//		a++;
//		cout<<"\t "<< a;
//	}
	
	
	//table of given unmber
	
//	int x;
//	int y=1;
//	cout<<"/nEnter a number of which table is requred :";
//	cin>>x;
//	while(y<20){
//		y++;
//		cout<<x<<" X "<<y<<" = "<<x*y<<endl;
//	}
	
	//positive number
	
	
//	int a;
//	cout<<" Enter a positive number :";
//	cin>>a;
//	while(a<=0){
//		cout<<"     Error !\n\t The number you have entered is not positive\n"; 
//		cout<<" Enter a positive number :";
//		cin>>a;
//		
//		
//	}
//	cout<<" You entered "<<a<<endl;


	//sum of 5 numbers
	
	
//	int a=1;
//	int sum;
//	while(a<5){
//		a++;
//	sum+=a;	
//	
//	}
//		cout<<sum;
  
  
  
  
  
  
  
	//Restaurant bill calculation
	

	cout<<endl<<setw(75)<<setfill('*')<<"Well Come TO Kashmiri Restaurant\n"<<endl;
	char MainMenu,ch;
	int subMenu;
	double amount, Total;
	do{
		
		cout<<setw(50)<<setfill('*')<<"\t\t press B for Breackfast\n";
		cout<<setw(50)<<setfill('*')<<"\t\t press L for Lunch \n";
		cout<<setw(50)<<setfill('*')<<"\t\t press D for Dinner \n: ";
		cin>>MainMenu;
		switch(MainMenu){
			case 'B':
			case 'b':
				cout<<"\n\t\t\t\t\t For Breakfast We Have following Menu:";
				cout<<"\n\t\t\t\t\t 1 for Anda Paratha (RS.40)";
				cout<<"\n\t\t\t\t\t 2 for Nan Channy (RS.60)";
				cout<<"\n\t\t\t\t\t 3 for Siri Paye (RS.150)";
				cout<<"\n\t\t\t\t\t 4 for Tea (RS.15)"<<endl;
				cin>>subMenu;
				switch(subMenu){
					case 1:
						cout<<setw(70)<<setfill('*')<<"how much Anda Paratha you need?"<<endl;
						cin>>amount;
						Total+= amount*40;
						break;
					case 2:
						cout<<setw(70)<<setfill('*')<<"how much Nan Channy you need?"<<endl;
						
						cin>>amount;
						Total+=amount*60;
						break;
					case 3:
					
						cout<<setw(70)<<setfill('*')<<"how much Siri Paye you need?"<<endl;
					
						cin>>amount;
						Total+=amount*150;
						break;
					case 4:
						cout<<setw(70)<<setfill('*')<<"how much Tea you need?"<<endl;
						cin>>amount;
						Total+=amount*15;
						break;
					
			}
				break;
			case 'L':
			case 'l':
				cout<<"\n\t\t\t\t\t For Lunch We Have following Menu:";
				cout<<"\n\t\t\t\t\t 1 for Chicken Karahi (RS.1050/kg)";
				cout<<"\n\t\t\t\t\t 2 for Mutton Karahi (RS.1800/kg)";
				cout<<"\n\t\t\t\t\t 3 for Egg Fried Rice (RS.450/plate)";
				cout<<"\n\t\t\t\t\t 4 for BBQ (RS.1050/dozen)"<<endl;
				cin>>subMenu;
				switch(subMenu){
					case 1:
						cout<<setw(70)<<setfill('*')<<" What amount of Chicken Karahi would you like to order :"<<endl;
						cin>>amount;
						Total+=amount*1050;
						break;
					case 2:
						cout<<setw(70)<<setfill('*')<<" what amount of Mutton Karahi would you like to order :"<<endl;
						cin>>amount;
						Total+=amount*1050;
						break;
					case 3:
						cout<<setw(70)<<setfill('*')<<" What amount of Egg Fried Rice would you like to order :"<<endl;
						cin>>amount;
						Total+=amount*450;
						break;
					case 4:
						cout<<setw(70)<<setfill('*')<<" What amount of BBQ would you like to order :"<<endl;
						cin>>amount;
						Total+=amount*1050;
						break;
				}		
				break;
			case 'D':
			case  'd':
				cout<<"\n\t\t\t\t\t For Dinner We Have Following Menu: ";
				cout<<"\n\t\t\t\t\t 1 for Chicken Karahi (RS.1050/kg)";
				cout<<"\n\t\t\t\t\t 2 for Mutton Karahi (RS.1800/kg)";
				cout<<"\n\t\t\t\t\t 3 for Egg Fried Rice (RS.450/plate)";
				cout<<"\n\t\t\t\t\t 4 for BBQ (RS.1050/dozen)";
				cout<<"\n\t\t\t\t\t 5 for Saji (RS.800/kg)"<<endl;
				cin>>subMenu;
				switch(subMenu){
					case 1:
						cout<<setw(70)<<setfill('*')<<" What amout of Chicken Karahi would you like to order :"<<endl;
						cin>>amount;
						Total+=amount*1050;
						break;
					case 2:
						cout<<setw(70)<<setfill('*')<<" what amount of Mutton Karahi would you like to order :"<<endl;
						cin>>amount;
						Total+=amount*1050;
						break;
					case 3:
						cout<<setw(70)<<setfill('*')<<" What amount of Egg Fried Rice would you like to order :"<<endl;
						cin>>amount;
						Total+=amount*450;
						break;
					case 4:
						cout<<setw(70)<<setfill('*')<<"What amount of BBQ would you like to order :"<<endl;
						cin>>amount;
						Total+=amount*1050;
						break;
					case 5:
						cout<<setw(70)<<setfill('*')<<"What amount of Saji would you like to order :"<<endl;
						cin>>amount;
						Total+=amount*800;
						break;
						}
						break;
			default:
				cout<<" \n\n\t\t\t Invalid data !!!\n \t\t\t please enter correct data."<<endl;
					return 0;
		}
		
		cout<<" \t\t\t\t\t Do you want to order somting else ?";
		cout<<"\n\t\t\t\t\t press y for (yes), n for (no) :";
		cin>>ch;
		cout<<endl;
		cout<<endl;
	}
	while(ch!='n');
	
	cout<<setw(70)<<setfill('*')<<" Your Total bill is ="<<Total<<endl;
	cout<<"\n";
	cout<<"\n";
	
	
	
	
	//password system by do while loop
	
//	int password ;
//	
//	do{
//		cout<<" Enter password :";
//	cin>>password;
//		cout<<" worng password"<<endl;
//	}
//	while(password!=1234);
//	
//		cout<<" successfully loged in";
	
		
	
	
}
