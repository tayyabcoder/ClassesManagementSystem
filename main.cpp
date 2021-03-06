#include <iostream>
#include <string>
#include <fstream>
#include "Shedule.h"
#include "Equipment.h"
#include "Classassistant.h"
#include "Utils.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int role;
	do {
		cout<<"Press 1 for Admin\nPress 2 for Class Assistant\nPress 3 to Exit the program"<<endl;
		cin>>role;
		system("CLS");
		if(role==1) {
			//Admin
			if(checkUserNameAndPassword("admin", "admin")) { //change username & password
				int menu;
				do {
					cout<<"Press 1 to Add Class Room Details"<<endl;
					cout<<"Press 0 to go back"<<endl;
					cin>>menu;
					system("CLS");
					if(menu==1) {
						//Schedule Bus
						int menu2;
						do {
							menu2=0;
							cout<<"Press 1 to Set Class Room Features"<<endl;
							cout<<"Press 2 to Set Shedule Class"<<endl;
							cout<<"Press 3 to Class Equipment"<<endl;
							cout<<"Press 4 to Class Assistant "<<endl;
							cout<<"Press 0 to Go back"<<endl;
							cin>>menu2;
							system("CLS");
							if(menu2==1) {
								Classroom C =creatnewclassroom();

								cout<<"Class Room Id is :"<<C.getroom_id()<<".\n";
								showLoadingDots(5);
								cout<<endl;
								cout<<"Class Room is  Number is "<<	C.getroom_number()<<".\n";
								cout<<endl;
								cout<<"Total Seats in Class Room :"<<C.getnumber_seats()<<" .\n";
								cout<<"Floor of Class Room is :"<<C.getfloor()<<" .\n";
								showLoadingDots(3);
								cout<<endl;
								waitAnyKey();
							} else if(menu2==2) {
								int room_id;
								cout<<"Enter Class Room NUmber"<<endl;
								cin>>room_id;
								Classroom c=searchclass(room_id);

								Shedule S= creatnewshedule(c);
								cout<<"Admin Shedule Date for Class  : "<<S.getdate( )<<" .\n";
								cout<<"Admin Shedule Day for Class   : "<<S.getday()<<" .\n";
								cout<<"Admin Shedule Month for Class : "<<	S.getmonth()<<" .\n";
								cout<<"Admin Shedule Time  for Class : "<<S.gettime();
								showLoadingDots(3);
								cout<<endl;
								waitAnyKey();
							} else if(menu2==3) {
								int room_id;
								cout<<"Enter Class Room Number :"<<endl;
								cin>>room_id;
								Classroom c=searchclass(room_id);
								Equipment E= creatnewequipment(c);
								cout<<"Equipment Type is : "<<E.getequipment_type()<<" .\n";
								cout<<"Equipment Colour is : "<<E.getcolour()<<" .\n";
								showLoadingDots(3);
								cout<<endl;
								waitAnyKey();

							} else if(menu2==4) {
								classassistant cl=creatnewclassassistant();
								cout<<"Class Assistant Name is :"<<cl.assistant_name<<" .\n";
								cout<<"Class Assistant ID is :"<<cl.assistant_id<<" .\n";
								showLoadingDots(3);
								cout<<endl;
								waitAnyKey();
							}

							system("CLS");
							showValidOptionError(menu2, 0,4);
						} while(menu2!=0);
					}
					system("CLS");
					showValidOptionError(menu,0,1);
				} while(menu!=0);
			}
		} else if(role==2) {
			int menu;
			cout<<"Press 1 to show all Information/ Press 2 to search all information: "<<endl;
			cin>>menu;
			if(menu==1) {

				showAllShedule();
			} else if(menu==2) {


				string A;
				cout<<"Enter Assistant ID : "<<endl;
				cin>>A;
				classassistant ca= searchid(A);
				cout<<ca.assistant_id;
				cout<<ca.assistant_name;
				cout<<ca.classroom.room_number;
			}

		
		}
		showValidOptionError((role!=1 && role !=2 && role !=3));
	} while(role!=3);

	return 0;
}