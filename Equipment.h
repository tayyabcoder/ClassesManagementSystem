#include <fstream>
class Equipment{
	public:
		Classroom classroom;
		string equipment_type,colour,projector,board,chairs;
	Classroom getclassroom()
	{
		return classroom;
	}
	
	string getequipment_type(){
		return equipment_type;
	}
	string getcolour()
	{
		return colour;
	}

	void setclassroom(Classroom classroom)
	{
		this->classroom=classroom;
	}
	void setequipment_type(string equipment_type)
	{
		this-> equipment_type=equipment_type;
	}
	void setcolour(string colour)
	{
		this-> colour=colour;
		
	}

};
Equipment creatnewequipment(Classroom classroom)
{
	string equipment_type,colour,projector,board,chairs;
	cout<<"Enter type of Equipment"<<endl;
	cin>>equipment_type;
	cout<<"Colour of Equipment "<<endl;
	cin>>colour;
	Equipment E;
	E.setclassroom(classroom);
	E.setequipment_type(equipment_type);
	E.setcolour(colour);
	Equipment *pEq=&E;
	//writing into file
	fstream wrt;
	wrt.open("EQUIPMENT_DATA.dat",ios::out|ios::app);
	wrt.write((char*)pEq,sizeof(Equipment));
	wrt.close(); //finished writing
	return E;
}