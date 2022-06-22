#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Classroom {
	public:
		int room_id,room_number,number_seats;
		string floor;
		int getroom_id()
		{
			return room_id;
		}
		int getroom_number()
		{
			return room_number;
		}
		int getnumber_seats()
		{
			return number_seats;
		}
		string getfloor()
		{
			return floor;	
		}
		void setroom_id(int room_id)
		{
			this->room_id=room_id;
		}
		void setroom_number(int room_number)
		{
			this->room_number=room_number;
		}
		void setnumber_seats(int number_seats)
		{
			this->number_seats=number_seats;
		}
		void setfloor(string floor)
		{
			this->floor=floor;
		}
		
};
Classroom creatnewclassroom()
{
	int room_id,room_number,number_seats;
	string floor;
	cout<<"Enter Class Room ID :"<<endl;
	cin>>room_id;
	cout<<"Enter Class Room Number : "<<endl;;
	cin>>room_number;
	cout<<"Enter Total number of seats in Classroom"<<endl;
	cin>>number_seats;
	cout<<"Enter Floor of Class:"<<endl;;
	cin>>floor;
	Classroom C ;
	C.setroom_id(room_id);
	C.setroom_number( room_number);
	C.setnumber_seats(number_seats);
	C.setfloor(floor);
	Classroom *pClass=&C;
	//writing into file
	fstream wrt;
	wrt.open("CLASSROOM_DATA.dat",ios::out|ios::app);
	wrt.write((char*)pClass,sizeof(Classroom));
	wrt.close(); //finished writing
	return C;
	
}

Classroom searchclass(int id){
	Classroom *c;
	//reading from file
	fstream file;
	file.open("CLASSROOM_DATA.dat");
	while(file.read((char*)c, sizeof(Classroom))) {
		if(c->room_id==id)
			break;
	}
	file.close();
	return *c;
}