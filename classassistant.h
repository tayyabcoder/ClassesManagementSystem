#include<iostream>
#include<string>
#include <fstream>


class classassistant {
	public:
		Classroom classroom;
		string assistant_name,assistant_id;
		Classroom getClassroom() {
			return classroom;
		}

		string getassistant_name() {
			return assistant_name;
		}
		string getassistant_id() {
			return assistant_id;
		}
		void setclassroom(Classroom classroom) {
			this-> classroom=classroom;
		}
		void setassistant_name(string assistant_name) {
			this->assistant_name=assistant_name;
		}
		void setassistant_id(string assistant_id) {
			this->assistant_id=assistant_id;
		}

};
classassistant creatnewclassassistant(Classroom classroom) {
	string assistant_name,assistant_id,duty_class;
	int room_id;
	cout<<"Enter Class Assistant Name"<<endl;
	cin>>assistant_name;
	cout<<"Enter Class Assistant ID "<<endl;
	cin>>assistant_id;
	cout<<"Enter Class ID for Duty"<<endl;
	cin>>room_id;
	Classroom c=searchclass(room_id);
	classassistant A;
	A.setclassroom(c);
	A.setassistant_name( assistant_name);
	A.setassistant_id(assistant_id);
	A.setassistant_id(assistant_id);
	classassistant *pAs=&A;
	//writing into file
	fstream wrt;
	wrt.open("ASSISTANT_DATA.dat",ios::out|ios::app);
	wrt.write((char*)pAs,sizeof(classassistant));
	wrt.close(); //finished writing
	return A;
}
classassistant searchid(string id) {
	classassistant *A=new classassistant();
	//reading from file
	fstream file;
	file.open("ASSISTANT_DATA.dat");
	while(file.read((char*)A, sizeof(classassistant))) {
		if(A->assistant_id==id)
			break;
	}
	file.close();
	return *A;
} 