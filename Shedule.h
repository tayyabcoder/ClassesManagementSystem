#include <fstream>
class Shedule{
	public:
		Classroom classroom;
		int date,time,year;
		string day ,month;
		
		Classroom getClassroom()
		{
			return classroom;
		}
		int getdate(){
			return date;
		}
		int gettime()
		{
			return time;
		}
		string getday()
		{
			return day;
			
		}
		string getmonth()
		{
			return month;
		}
		void setclassroom(Classroom classroom)
		{
			this-> classroom=classroom;
		}
		void setdate(int date)
		{
			this->date=date;
		}
		void settime(int time)
		{
			this->time=time;
		}
		void setday(string day)
		{
			this-> day=day;
		}
		void setmonth(string month)
		{
			this-> month=month;
		}
				
};
Shedule creatnewshedule(Classroom classroom)
{
	int date,time,year;
	string day ,month;
	cout<<"Set Date for Class :"<<endl;
	cin>>date;
	cout<<"Set Time For Class :"<<endl;
	cin>>time;
	cout<<"Set Day For Class"<<endl;
	cin>>day;
	cout<<"Set Month For Class"<<endl;
	cin>>month;
	Shedule S;
	S.setclassroom(classroom);
	S.setdate( date);
	S.settime(time);
	S.setday(day);
	S.setmonth(month);
	Shedule *pSh=&S;
	//writing into file
	fstream wrt;
	wrt.open("SCHEDULE_DATA.dat",ios::out|ios::app);
	wrt.write((char*)pSh,sizeof(Shedule));
	wrt.close(); //finished writing
	return S;
	
	
	
}
void showAllShedule(){
	cout<<"Class Number \t\tDate\tTime\ttDay\t\tMonth"<<endl;
	Shedule *pSh;
	//reading from file
	fstream file;
	file.open("SCHEDULE_DATA.dat");
	while(file.read((char*)pSh, sizeof(Shedule))) {
		cout<<pSh->classroom.room_number<<"\t\t\t\t\t"<<pSh->date<<"\t\t\t\t"<<pSh->time<<"\t\t\t\t"<<pSh->day<<"\t\t\t\t"<<pSh->month<<endl;
	}
	file.close();
}