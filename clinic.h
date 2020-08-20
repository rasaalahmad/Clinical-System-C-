#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Name
{
	char* fname;
	char* lname;
public:
	Name()
	{
		fname = nullptr;
		lname = nullptr;
	}

	Name(const char* fn, const char* ln)
	{
		int i = 0;
		fname = new char[strlen(fn) + 2];
		while (fn[i] != '\0')
		{
			fname[i] = fn[i];
			i++;
		}
		fname[i] = '\0';
		i = 0;

		lname = new char[strlen(ln) + 2];
		while (ln[i] != '\0')
		{
			lname[i] = ln[i];
			i++;
		}
		lname[i] = '\0';
	}
	
	Name(const Name& p)
	{
		int i = 0;
		fname = new char[strlen(p.fname) + 2];
		while (p.fname[i] != '\0')
		{
			fname[i] = p.fname[i];
			i++;
		}
		fname[i] = '\0';
		i = 0;

		lname = new char[strlen(p.lname) + 2];
		while (p.lname[i] != '\0')
		{
			lname[i] = p.lname[i];
			i++;
		}
		lname[i] = '\0';
	}
	
	~Name()
	{
		if (fname != nullptr && lname != nullptr)
		{
			delete[]fname;
			delete[]lname;
		}
		fname = nullptr;
		lname = nullptr;
	}

	void set_fname(const char* fn)
	{
		int i = 0;

		fname = new char[strlen(fn) + 2];
		while (fn[i] != '\0')
		{
			fname[i] = fn[i];
			i++;
		}
		fname[i] = '\0';
	}

	void set_lname(const char* ln)
	{
		int i = 0;

		lname = new char[strlen(ln) + 2];
		while (ln[i] != '\0')
		{
			lname[i] = ln[i];
			i++;
		}
		lname[i] = '\0';
	}

	void get_fname()
	{
		cout << fname;
	}
	
	void get_lname()
	{
		cout << lname;
	}

	const char* get_fnames()
	{
		return fname;
	}

	const char* get_lnames()
	{
		return lname;
	}

	friend ostream& operator<<(ostream& out,const Name& n)
	{
		out << n.fname << " " << n.lname << endl;
		return out;
	}

	friend ofstream& operator<<(ofstream& out, const Name& n)
	{
		out << n.fname << " " << n.lname;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Name& p)
	{
		char fn[30];
		in.getline(fn, 30, ' ');
		int i = 0;
		p.fname = new char[strlen(fn) + 2];
		while (fn[i] != '\0')
		{
			p.fname[i] = fn[i];
			i++;
		}
		p.fname[i] = '\0';
		i = 0;

		char ln[30];
		in.getline(ln, 30, ' ');

		p.lname = new char[strlen(ln) + 2];
		while (ln[i] != '\0')
		{
			p.lname[i] = ln[i];
			i++;
		}
		p.lname[i] = '\0';
	}
};

class date
{
	int day;
	int month;
	int year;
public:
	date(int d = 0, int m = 0, int y = 0)
	{
		day = d;
		month = m;
		year = y;
	}
	
	date(const date& p)
	{
		day = p.day;
		month = p.month;
		year = p.year;
	}
	
	~date()
	{
	}

	void set_day(int d)
	{
		day = d;
	}
	
	void set_month(int m)
	{
		month = m;
	}
	
	void set_year(int y)
	{
		year = y;
	}
	
	void set_date(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
	
	int get_year()
	{
		return year;
	}
	
	int get_month()
	{
		return month;
	}
	
	int get_day()
	{
		return day;
	}
	

	friend ostream& operator<<(ostream& out, date& p)
	{
		out << p.get_day() << "/" << p.get_month() << "/" << p.get_year();
		return out;
	}

	friend ofstream& operator<<(ofstream& out, date& p)
	{
		out << p.get_day();
		out << " ";
		
		out << p.get_month();
		out << " ";
		
		out<< p.get_year();
		
		return out;
	}

	friend ifstream& operator>>(ifstream& in, date& p)
	{
		in >> p.day;
		in >> p.month;
		in >> p.year;
		
		return in;
	}

	friend istream& operator>>(istream& in, date& p)
	{
		while (true)
		{
			cout << "Enter day:";
			in >> p.day;
			if (p.day >= 0 && p.day < 31)
			{
				break;
			}
			else
			{
				cout << "\nInvalid date!!!";
			}
		}
		
		while (true)
		{
			cout << "Enter month:";
			in >> p.month;
			if (p.month >= 0 && p.month < 12)
			{
				break;
			}
			else
			{
				cout << "\nInvalid month!!!";
			}
		}
		
		cout << "Enter year:";
		in >> p.year;
		
		return in;
	}

	date& operator=(const date& p)
	{
		day = p.day;
		month = p.month;
		year = p.year;
		
		return *this;
	}

	bool operator==(const date& p)
	{
		if (day == p.day && month == p.month && year == p.year)
		{
			return true;
		}
		else
			return false;
	}

	bool operator==(const int p)
	{
		if (day == p && month == p && year == p)
		{
			return true;
		}
		else
			return false;
	}

};

class mtime
{
	int hour;
	int min;
	int sec;
public:
	mtime(int h = 0, int m = 0, int s = 0)
	{
		hour = h;
		min = m;
		sec = s;
	}
	
	mtime(const mtime& p)
	{
		hour = p.hour;
		min = p.min;
		sec = p.sec;
	}
	
	~mtime()
	{
	}

	void set_hour(int h)
	{
		hour = h;
	}
	
	void set_min(int m)
	{
		min = m;
	}
	
	void set_sec(int s)
	{
		sec = s;
	}
	
	void set_time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	
	int get_sec()
	{
		return sec;
	}
	
	int get_min()
	{
		return min;
	}
	
	int get_hour()
	{
		return hour;
	}
	
	friend ostream& operator<<(ostream& out, mtime& p)
	{
		out << p.get_hour() << ":" << p.get_min() << ":" << p.get_sec();
	
		return out;
	}
	
	friend ofstream& operator<<(ofstream& out, mtime& p)
	{
		out << p.get_hour() << " " << p.get_min() << " " << p.get_sec();
		
		return out;
	}

	friend ifstream& operator>>(ifstream& in, mtime& p)
	{
		in >> p.hour;
		in >> p.min;
		in >> p.sec;
	
		return in;
	}

	friend istream& operator>>(istream& in, mtime& p)
	{
		while (true)
		{
			cout << "\nEnter hours:";
			in >> p.hour;
			if (p.hour >= 0 && p.hour < 24)
			{
				break;
			}
			else
			{
				cout << "\nInvalid hours!!\n";
			}
		}

		while (true)
		{
			cout << "Enter minutes:";
			in >> p.min;
			if (p.min >= 0 && p.min < 60)
			{
				break;
			}
			else
			{
				cout << "\nInvalid minutes!!\n";
			}
		}
		while (true)
		{
			cout << "Enter seconds:";
			in >> p.sec;
			if (p.sec >= 0 && p.sec < 60)
			{
				break;
			}
			else
			{
				cout << "\nInvalid seconds!!\n";
			}
		}
		return in;
	}



	mtime& operator=(const mtime& p)
	{
		hour = p.hour;
		min = p.min;
		sec = p.sec;
		
		return *this;
	}

	bool operator==(const int p)
	{
		if (hour == p && min == p && sec == p)
		{
			return true;
		}
		else
			return false;
	}

};

class Person {
	Name pname; 
	date dob;
	int age;
	int Nid;
public:
	Person()
	{
		age = 0;
		Nid = 0;
	}
	
	Person(const char* fn, const char* ln, int d, int m, int y, int ag, int id) :pname(fn, ln), dob(d, m, y)
	{
		age = ag;
		Nid = id;
	}
	
	Person(const Person& p) 
	{
		pname = p.pname;
		dob = p.dob;
		age = p.age;
		Nid = p.Nid;
	}
	
	~Person()
	{
	}

	void set_name(const char* fn, const char* ln)
	{
		pname.set_fname(fn);
		pname.set_lname(ln);
	}
	
	void set_dob(int d, int m, int y)
	{
		dob.set_day(d);
		dob.set_month(m);
		dob.set_year(y);
	}
	
	void set_age(int n)
	{
		age = n;
	}
	
	void set_nid(int n)
	{
		Nid = n;
	}

	void get_name()
	{
		pname.get_fname();
		cout << " ";
		pname.get_lname();
	}
	
	const char* get_fnam()
	{
		const char* a = pname.get_fnames();
		return a;
	}

	const char* get_lnam()
	{
		const char* a = pname.get_lnames();
		return a;
	}

	void get_dob()
	{
		cout << dob;
	}


	date get_DOB()
	{
		return dob;
	}

	int get_day()
	{
		return dob.get_day();
	}

	int get_month()
	{
		return dob.get_month();
	}

	int get_year()
	{
		return dob.get_year();
	}

	int get_age()
	{
		return age;
	}

	int get_nid()
	{
		return Nid;
	}
	
	friend ostream& operator<<(ostream& out, Person& p)
	{
		out << p.pname<<endl;
		out << p.dob;
		out << "Age:" << p.age;
		out << "\nNid:" << p.Nid;
		out << endl;
	
		return out;
	}


	friend ifstream& operator>>(ifstream& in, Person& p)
	{
		in >> p.pname;
		in >> p.dob;
		in >> p.age;
		in >> p.Nid;
		
		return in;
	}

};

class pRecord 
{
	char* DiseaseType;
	date   visDate;
	mtime  visTime;
	int    AssignedDoc;
	float  feepaid;
	int pid;

public:
	pRecord()
	{
		DiseaseType = nullptr;
		AssignedDoc = 0;
		feepaid = 0;
		pid = 0;
		
	}
	
	pRecord(const char* dis, int d, int m, int y, int h, int mm, int s, int doc, float fee, int p) :visDate(d, m, y), visTime(h, mm, s)
	{
		int i = 0;
		DiseaseType = new char[strlen(dis) + 2];
		while (dis[i] != '\0')
		{
			DiseaseType[i] = dis[i];
			i++;
		}
		DiseaseType[i] = '\0';

		AssignedDoc = doc;
		feepaid = fee;
		pid = p;

	}
	
	pRecord(const pRecord& p)
	{
		AssignedDoc = p.AssignedDoc;

		int i = 0;
		DiseaseType = new char[strlen(p.DiseaseType) + 2];
		while (p.DiseaseType[i] != '\0')
		{
			DiseaseType[i] = p.DiseaseType[i];
			i++;
		}
		DiseaseType[i] = '\0';

		feepaid = p.feepaid;

		visDate = p.visDate;
		visTime = p.visTime;
		pid = p.pid;
	}
	
	~pRecord()
	{
		if (DiseaseType != nullptr)
		{
			delete[] DiseaseType;
		}
		DiseaseType = nullptr;
	}
	
	void set_date(const date& d)
	{
		visDate = d;
	}
	
	void set_date(int d, int m, int y)
	{
		visDate.set_day(d);
		visDate.set_month(m);
		visDate.set_year(y);
	}
	
	void set_time(int h, int m, int s)
	{
		visTime.set_hour(h);
		visTime.set_min(m);
		visTime.set_sec(s);
	}
	
	void set_disease(const char* dis)
	{
		int i = 0;
		DiseaseType = new char[strlen(dis) + 2];
		while (dis[i] != '\0')
		{
			DiseaseType[i] = dis[i];
			i++;
		}
		DiseaseType[i] = '\0';
	}
	
	void set_time(const mtime& m)
	{
		visTime = m;
	}
	
	void set_doc(int id)
	{
		AssignedDoc = id;
	}
	
	void set_fee(float f)
	{
		feepaid = f;
	}
	
	void get_date()
	{
		cout << visDate;
	}
	
	void get_time()
	{
		cout << visTime;
	}
	
	int get_docid()
	{
		return AssignedDoc;
	}
	
	float get_fee()
	{
		return feepaid;
	}
	
	void get_dis()
	{
		cout << DiseaseType;
	}
	
	int get_id()
	{
		return pid;
	}
	
	void set_pid(int n)
	{
		pid = n;
	}
	
	friend ostream& operator<<(ostream& out, pRecord& p)
	{
		out << "\n\n\tPatient history";
		out << "\nDisease type:";
		p.get_dis();
	
		out << endl;
		
		out << "\nDate:";
		p.get_date();
		
		out << endl;
		
		out << "\nTime:";
		p.get_time();
		
		out << endl;
		out <<"\nDoctor id:" <<p.get_docid() << endl <<"\nFee:"<< p.get_fee()<<endl;
		
		return out;
	}


	friend ofstream& operator<<(ofstream& out, pRecord& p)
	{
		out << p.pid << " " << p.DiseaseType << " ";
		
		out << p.visDate;
		
		out << " ";
		
		out << p.visTime;
		out << " " << p.get_docid() << " " << p.get_fee() << " ";
		
		return out;
	}


	friend ifstream& operator>>(ifstream& in, pRecord& p)
	{
		in >> p.pid;
		char dis[50];
		in.getline(dis, 50, ' ');
		
		int i = 0;
		p.DiseaseType = new char[strlen(dis) + 2];
		while (dis[i] != '\0')
		{
			p.DiseaseType[i] = dis[i];
			i++;
		}
		p.DiseaseType[i] = '\0';

		in >> p.visDate;
		
		in >> p.visTime;
		
		in >> p.AssignedDoc;
		
		in >> p.feepaid;

		return in;
	}


	bool operator!=(const int a)
	{
		if (pid == 0 && feepaid == 0 && AssignedDoc == 0)
		{
			return false;
		}
		else
			return true;
	}

};



class Patient : public Person 
{
	int pid; 
	bool status;
	
public:
	pRecord* history;
	int pcomming;
	Patient()
	{
		pid = 0;
		pcomming = 0;
		history = new pRecord [15];
		status = false;
	}

	Patient(const char* fn, const char* ln, int d, int m, int y, int ag, int ni, int his_times, bool stats, int pidd) :Person(fn, ln, d, m, y, ag, ni), history(new pRecord [his_times])
	{
		pid = pidd;
		pcomming = his_times;
		status = stats;
		history = new pRecord [15];
	}
	
	Patient(const Patient& p) :Person(p)
	{
		pcomming = p.pcomming;
		pid = p.pid;
		history = p.history;
		status = p.status;
	}

	~Patient()
	{
	}

	friend ostream& operator<<(ostream& out,Patient& p)
	{
		out << "\tPatient Deatils:-"<<endl;
		
		out << "\nPatient id:" << p.pid << endl;
		out << "\nName:";
		
		p.get_name();
		
		out << endl<<"\nDOB:";
		p.get_dob();
		
		out << endl<<"\nAge:";
		
		out<<p.get_age()<<endl<<"\nPatient Nation identity number:";
		out << p.get_nid();
		
		for (int i = 0; i < p.pcomming; i++)
		{
			if (p.history[i] != 0)
				cout << p.history[i];
			else
				break;
		}
		return out;
	}


	int get_pid()
	{
		return pid;
	}

	friend ifstream& operator>>(ifstream& in, Patient& p)
	{
		in >> p.pid;

		in.ignore();
		char fn[30];
		in.getline(fn, 30, ' ');

		char ln[30];
		in.getline(ln, 30, ' ');
		p.set_name(fn, ln);

		int d = 0, m = 0, y = 0;
		in >> d >> m >> y;
		p.set_dob(d, m, y);

		int ag = 0;
		in >> ag;
		p.set_age(ag);

		int nidd = 0;
		in >> nidd;
		p.set_nid(nidd);

		in >> p.status;

		return in;
	}


	friend istream& operator>>(istream& in, Patient& p)
	{
		cout << "\nEnter Patient Id:";
		in >> p.pid;
	

		cout << "\nEnter First Name:";
		char fn[30];
		in >> fn;

		char ln[30];
		cout << "\nEnter Last Name:";
		in >> ln;
		p.set_name(fn, ln);

		int d = 0, m = 0, y = 0;
		while (true)
		{
			cout << "\nEnter DOB (D/M/Y):";
			in >> d >> m >> y;
			
			if ((d >= 0 && d < 31) && (m >= 0 && m < 12))
			{
				break;
			}
			
			else 
			{
				cout << "\nInvalid Date!!!\nEnter again please!!\n";
			}
		}
		p.set_dob(d, m, y);
		int ag = 0;
		
		cout << "\nEnter age:";
		in >> ag;
		p.set_age(ag);

		int nidd = 0;
		cout << "\nEnter national identity number:";
		in >> nidd;
		p.set_nid(nidd);

		cout << "\nDefault status of apointment set to false." << endl;
		p.status = 0;

		return in;
	}

	

	friend ofstream& operator<<(ofstream& out, Patient& p)
	{
		out << p.pid<<" ";
		
		out << p.get_fnam() << " " << p.get_lnam();
		
		out << " ";
		
		out << p.get_day();
		
		out << " ";
		
		out << p.get_month();
		
		out << " ";
		
		out << p.get_year();
		
		out << " ";
		
		out << p.get_age() << " ";
		
		out << p.get_nid() << " " << p.status << endl;


		return out;

	}

	void update_history(Patient* p, int size)
	{
		ofstream file;
		file.open("Patient - History.txt", ios::trunc);
		
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < p[i].pcomming; j++)
			{
				if (p[i].history[j] != 0)
				{
					file << p[i].history[j] << " ";
				}
			}
			file << endl;
		}

	}


	bool operator!=(const int p)
	{
		date d(get_DOB());

		if (pid == 0 && d == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}


	void set_pid(int n)
	{
		pid = n;
	}

};





class Doctor : public Person
{
	int did;
	char* specialization;
	int* patientvisited;
	int totvist;
public:
	Doctor()
	{
		did = 0;
		specialization = new char[50];
		patientvisited = new int [100];
		
		for (int i = 0; i < 100; i++)
		{
			patientvisited[i] = INT_MIN;
		}
		totvist = 0;
	}
	
	Doctor(const char* fn, const char* ln, int d, int m, int y, int ag, int id, int docid, const char* spec, const int* plist, int tvist) :Person(fn, ln, d, m, y, ag, id)
	{
		did = docid;
		specialization = new char[strlen(spec) + 2];
		int i = 0;
		while (spec[i] != '\0')
		{
			specialization[i] = spec[i];
			i++;
		}
		specialization[i] = '\0';
		totvist = tvist;
		patientvisited = new int[tvist];
		for (i = 0; i < tvist; i++)
		{
			patientvisited[i] = plist[i];
		}
	}
	
	Doctor(const Doctor& d) :Person(d)
	{
		did = d.did;
		specialization = new char[strlen(d.specialization) + 2];
		int i = 0;
		while (d.specialization[i] != '\0')
		{
			specialization[i] = d.specialization[i];
			i++;
		}
		specialization[i] = '\0';
		totvist = d.totvist;
		patientvisited = new int[totvist];
		for (i = 0; i < totvist; i++)
		{
			patientvisited[i] = d.patientvisited[i];
		}
	}

	~Doctor()
	{
	}

	void pvistors(Doctor* p, int size)
	{
		fstream file;
		file.open("Patients visited.txt");

		char** temp = new char* [size];

		for (int i = 0; i < size; i++)
		{
			temp[i] = new char[50];
		}
	
		for (int i = 0; i < size; i++)
		{
			file.getline(temp[i], 50);
		}

		file.close();

		int j = 0;
		int k = 0;

		int len = 0;

		

		for (int i = 0; i < size; i++)
		{
			len = (strlen(temp[i]) / 2) + 1;
			p[i].totvist = len;
			while (temp[i][j] != '\0')
			{
				if (temp[i][j] != ' ')
				{
					p[i].patientvisited[k] = (int)temp[i][j] - 48;
					k++;
				}
				j++;
			}
			k = 0;
			j = 0;
		}
		
	}


	friend ostream& operator<<(ostream& out, Doctor& p)
	{
		out << "\tDoctor details:" << endl;
		
		out << "\nID:" << p.did << endl;
		
		out << "\nName:";
		p.get_name();
		
		out << "\n\nAge:" << p.get_age();
		
		out << "\n\nDOB:";
		p.get_dob();
		
		out << "\n\nNID:" << p.get_nid();
		
		out << "\n\nSpecialization:" << p.specialization;
		
		out << "\n\nPatient Vistied Id's:";
		for (int j = 0; j < 100; j++)
		{
			if (p.patientvisited[j] != INT_MIN)
			{
				out << p.patientvisited[j] << " ";
			}
			else
			{
				break;
			}
		}
		out << endl;

		return out;
	}

	friend ofstream& operator<<(ofstream& out, Doctor& p)
	{

		out << p.did << " ";
		
		out << p.get_fnam() << " " << p.get_lnam();
		
		out << " " << p.get_day() << " " << p.get_month() << " " << p.get_year() << " ";
		
		out << p.get_age() << " ";
		
		out << p.get_nid() << endl;

		return out;
	}


	friend ifstream& operator>>(ifstream& in, Doctor& p)
	{
		in >> p.did;

		in.ignore();
		char fn[30];
		in.getline(fn, 30, ' ');

		char ln[30];
		in.getline(ln, 30, ' ');
		p.set_name(fn, ln);

		int d = 0, m = 0, y = 0;
		in >> d >> m >> y;
		p.set_dob(d, m, y);

		int ag = 0;
		in >> ag;
		p.set_age(ag);

		int nidd = 0;
		in >> nidd;
		p.set_nid(nidd);

		char spec[40];

		in.getline(spec, 40);

		p.specialization = new char[strlen(spec) + 2];
		int i = 0;
		while (spec[i] != '\0')
		{
			p.specialization[i] = spec[i];
			i++;
		}
		p.specialization[i] = '\0';

		return in;
	}

	friend istream& operator>>(istream& in, Doctor& p)
	{
		cout << "Enter Doctor ID:";
		in >> p.did;

		in.ignore();
		char fn[30];
		cout << "\n\nEnter First Name:";
		in >> fn;

		cout << "\nEnter last name:";
		char ln[30];
		in >> ln;
		p.set_name(fn, ln);

		int d = 0, m = 0, y = 0;
		while (true)
		{
			cout << "\nEnter DOB (D/M/Y):";
			in >> d >> m >> y;
			if ((d >= 0 && d < 31) && (m >= 0 && m < 12))
			{
				break;
			}
			else
			{
				cout << "\nInvalid Date!!!\nEnter again please!!\n";
			}
		}
		p.set_dob(d, m, y);

		int ag = 0;
		cout << "\nEnter age:";
		in >> ag;
		p.set_age(ag);

		cout << "\nEnter national identity number:";
		int nidd = 0;
		in >> nidd;
		p.set_nid(nidd);

		char spec[40];

		cout << "\nEnter Doctor Specialization:";
		in >> spec;
		
		p.specialization = new char[strlen(spec) + 2];
		int i = 0;
		while (spec[i] != '\0')
		{
			p.specialization[i] = spec[i];
			i++;
		}
		p.specialization[i] = '\0';

		return in;
	}

	int get_did()
	{
		return did;
	}

	void set_patientvisited(int id)
	{
		for (int j = 0; j < 100; j++)
		{
			if (patientvisited[j] == INT_MIN)
			{
				patientvisited[j] = id;
				break;
			}
		}
	}


	void update_visit_file(Doctor* d, int size)
	{
		ofstream file;
		file.open("Patients visited.txt", ios::trunc);
		
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < d[i].totvist; j++)
			{
				if (d[i].patientvisited[j] != INT_MIN)
				{

					file << d[i].patientvisited[j] << " ";
				}
			}
			file << endl;
		}

		file.close();
	}


	int get_docid()
	{
		return did;
	}


	bool operator!=(const int p)
	{
		date d(get_DOB());
		if (did == 0 && d == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}


	void set_did(int n)
	{
		did = n;
	}

};



class Appointment 
{
	char* DiseaseType;
	int    pId;
	int    dId;
	date   appDate;
	mtime  appTime;
	int    token_Number;
	float  fee;
	bool   status; // false for pending, true if complete
public:
	Appointment()
	{
		DiseaseType = new char[30];
		pId = 0;
		dId = 0;
		token_Number = 0;
		fee = 0;
		status = false;
	}
	
	Appointment(int d, int m, int y, int h, int mm, int s, const char* dis, int pid, int did, int tok, float fe, bool stats) :appDate(d, m, y), appTime(h, mm, s)
	{
		int i = 0;
		DiseaseType = new char[strlen(dis) + 2];
		while (dis[i] != '\0')
		{
			DiseaseType[i] = dis[i];
			i++;
		}
		DiseaseType[i] = '\0';

		pId = pid;
		dId = did;
		token_Number = tok;
		fee = fe;
		status = stats;
	}
	
	Appointment(const Appointment& p)
	{
		dId = p.dId;
		pId = p.pId;
		fee = p.fee;
		int i = 0;
		DiseaseType = new char[strlen(p.DiseaseType) + 2];
		while (p.DiseaseType[i] != '\0')
		{
			DiseaseType[i] = p.DiseaseType[i];
			i++;
		}
		DiseaseType[i] = '\0';
		appDate = p.appDate;
		appTime = p.appTime;
		token_Number = p.token_Number;
		status = p.status;
	}

	friend ifstream& operator>>(ifstream& in, Appointment& p)
	{
		char dis[50];
		in >> dis;
		int i = 0;
		p.DiseaseType = new char[strlen(dis) + 2];
		while (dis[i] != '\0')
		{
			p.DiseaseType[i] = dis[i];
			i++;
		}
		p.DiseaseType[i] = '\0';

		in >> p.pId >> p.dId;
		in >> p.appDate;
		in >> p.appTime;
		in >> p.token_Number;
		in >> p.fee;
		in >> p.status;

		return in;
	}



	friend istream& operator>>(istream& in, Appointment& p)
	{
		cout << "\nEnter Disease type:";
		char dis[50];
		in >> dis;
		int i = 0;
		p.DiseaseType = new char[strlen(dis) + 2];
		while (dis[i] != '\0')
		{
			p.DiseaseType[i] = dis[i];
			i++;
		}
		p.DiseaseType[i] = '\0';

		cout << "\nPatient Id:";
		in >> p.pId;
		cout << "\nEnter doctor Id:";
		in >> p.dId;
		cout << "\nEnter date of an appointment:" << endl;
		in >> p.appDate;
		cout << "\nEnter time of an appointment:\n";
		in >> p.appTime;
		cout << "\nEnter token number:";
		in >> p.token_Number;
		cout << "\nEnter fee:";
		in >> p.fee;
		
		cout << "\nDefault status of apointment set to false." <<endl;
		p.status = 0;

		return in;
	}


	friend ostream& operator<<(ostream& out, Appointment& p)
	{
		out << "\n\n\tAppointment details" << endl;
		out << "\nPatient id:" << p.pId<<"\n\nDoctor id:"<<p.dId<<"\n\nDisease type:"<<p.DiseaseType;
		out << "\n\nDate:" << p.appDate;
		out << "\n\nTime:" << p.appTime;
		out << "\n\nToken number:" << p.token_Number;
		out << "\n\nStatus:" << p.status;
		out << "\n\nFee:" << p.fee;

		return out;
	}


	friend ofstream& operator<<(ofstream& out, Appointment& p)
	{
		out << p.DiseaseType << " ";
		out << p.pId << " ";
		out << p.dId << " ";
		out << p.appDate << " ";
		out << p.appTime << " ";
		out << p.token_Number << " ";
		out << p.fee << " ";
		out << p.status;

		return out;
	}


	const char* get_dis()
	{
		return DiseaseType;
	}

	float get_fee()
	{
		return fee;
	}

	int get_pid()
	{
		return pId;
	}

	int get_did()
	{
		return dId;
	}
	
	bool get_status()
	{
		return status;
	}

	date get_Date()
	{
		return appDate;
	}

	mtime get_time()
	{
		return appTime;
	}

	void set_status(bool a)
	{
		status = a;
	}

	Appointment& operator=(const Appointment& p)
	{

		if (this != &p)
		{
			dId = p.dId;
			pId = p.pId;
			appDate = p.appDate;
			appTime = p.appTime;
			token_Number = p.token_Number;
			fee = p.fee;
			status = p.status;
			DiseaseType = p.DiseaseType;
		}
		return *this;
	}

	bool operator!=(const int p)
	{
		if (fee == p && dId == p && appDate == p && appTime == p)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

};

class clinic
{
	Doctor* doc;
	Patient* pat;
	Appointment* app;
	static int no_of_doc;
	static int no_of_pat;
	static int no_of_app;

protected:

	void add_doctor()
	{
		cout << endl << endl;
		cin >> doc[no_of_doc];
		no_of_doc++;

		bool check = doctor_id_validity_check(doc[no_of_doc].get_did());


		int idd = 0;

		while (true)
		{
			if (check == false)
			{
				cout << "\n\nDoctor Id already taken!!\n\n";

				cout << "Enter Doctor id:";
				cin >> idd;

				doc[no_of_doc].set_did(idd);

				check = doctor_id_validity_check(doc[no_of_doc].get_did());
			}
			else
			{
				break;
			}
		}



		doctors_data_to_file();
		patient_visit_file_update();

		cout << "\nDcotor information successfull added" << endl;
		cout << endl << endl;
	}

	void set_pvisit(Appointment& p)
	{
		for (int i = 0; i < no_of_doc; i++)
		{
			if (p.get_did() == doc[i].get_did())
			{
				int n = p.get_pid();
				doc[i].set_patientvisited(n);
			}
		}
	}

	void add_patient()
	{
		cout << endl << endl;
		cin >> pat[no_of_pat];

		bool check = patient_id_validity_check(pat[no_of_pat].get_pid());


		int idd = 0;

		while (true)
		{
			if (check == false)
			{
				cout << "\n\nPatient Id already taken!!\n\n";
				
				cout << "Enter Patient id:";
				cin >> idd;
				
				pat[no_of_pat].set_pid(idd);
				
				check = patient_id_validity_check(pat[no_of_pat].get_pid());
			}
			else
			{
				break;
			}
		}

		no_of_pat++;

		patient_data_to_file();

		cout << "\nPatient information successfull added" << endl;
		cout << endl << endl;
	}
	
	void add_appointment()
	{
		cout << endl << endl;
		bool check = true;
		int t = 0;
		cout << "\n\nEnter Patient id:";
		cin >> t;
		for (int i = 0; i < no_of_pat; i++)
		{
			if (pat[i].get_pid() == t)
			{
				cout << "\nPatient ID found!\n\n\n";
				cin >> app[no_of_app];
				
				set_pvisit(app[no_of_app]);
				
				patient_visit_file_update();
				
				no_of_app++;
				
				app_data_to_file();
				
				check = false;
				cout << endl << endl;
				break;
			}
		}
		if (check)
		{
			cout << "\nPatient ID not found!\n";
		}



	}

	void print_by_date()
	{
		bool check = true;
		
		date d;
		cout << "\n\nEnter a date to Search patients:" << endl;
		cin >> d;
		
		int diid = 0;

		cout << "\n\nEnter Doctor Id:" << endl;
		cin >> diid;
		
		for (int i = 0; i < no_of_app; i++)
		{
			if (app[i].get_Date() == d && app[i].get_did() == diid)
			{
				int pidd = 0;
				pidd = app[i].get_pid();
		
				for (int j = 0; j < no_of_pat; j++)
				{
					if (pat[j].get_pid() == pidd)
					{
						cout << pat[j];
						cout << app[i];
						
						cout << endl << endl;
				
						check = false;
						break;
					}
				}
			}
		}
		if (check)
		{
			cout << "\nNot found!\n";
		}

	}

	void print_by_docid()
	{
		bool check = true;
		int diid = 0;
		
		cout << "\n\nEnter Doctor Id:" << endl;
		cin >> diid;
		
		for (int i = 0; i < no_of_app; i++)
		{
			if (app[i].get_did() == diid)
			{
				int pidd = 0;
				pidd = app[i].get_pid();
		
				for (int j = 0; j < no_of_pat; j++)
				{
					if (pat[j].get_pid() == pidd)
					{
						cout << pat[j];
						cout << app[i];
					
						cout << endl << endl;
						
						check = false;
						break;
					}
				}
			}
		}
		if (check)
		{
			cout << "\nNot found!\n";
		}
	}

	void print_by_pen_date()
	{
		bool check = true;
	
		date d;
		cout << "\n\nEnter a date to Search patients:" << endl;
		cin >> d;
	
		for (int i = 0; i < no_of_app; i++)
		{
			bool temp = app[i].get_status();
		
			if (app[i].get_Date() == d && temp == false)
			{
				int pidd = 0;
				pidd = app[i].get_pid();
			
				for (int j = 0; j < no_of_pat; j++)
				{
					if (pat[j].get_pid() == pidd)
					{
						cout << pat[j];
						cout << app[i];
					
						cout << endl << endl;
						check = false;
						
						break;
					}
				}
			}
		}
		if (check)
		{
			cout << "\nNot found!\n";
		}
	}

	void print_by_pen_doc()
	{
		bool check = true;
		
		cout << "\n\nEnter Doc id:";
		int diid = 0;
		cin >> diid;
		
		for (int i = 0; i < no_of_app; i++)
		{
			bool temp = app[i].get_status();
		
			if (app[i].get_did() == diid && temp == false)
			{
				int pidd = 0;
			
				pidd = app[i].get_pid();
				
				for (int j = 0; j < no_of_pat; j++)
				{
					if (pat[j].get_pid() == pidd)
					{
						cout << pat[j] << endl;
						cout << app[i] << endl;
					
						cout << endl << endl;
						
						check = false;
						break;
					}
				}
			}
		}
		if (check)
		{
			cout << "\nNot found!\n";
		}
	}

	void update_status()
	{
		bool check = true;
		
		cout << "Enter Patient Id:";
		int pidd = 0;
		cin >> pidd;
		
		for (int i = 0; i < no_of_app; i++)
		{
			bool temp = app[i].get_status();
			if (temp == false)
			{
				for (int j = 0; j < no_of_pat; j++)
				{
					if (pat[j].get_pid() == pidd && pat[j].get_pid() == app[i].get_pid())
					{
						cout << "\n\nAppointment status is set to complete\n\n";
						
						app[i].set_status(true);
						
						set_history(app[i], pat[j]);
						
						patient_history_update();
						
						update_app_list(pidd);
						
						app_data_to_file();
						
						check = false;
						
						break;
					}
				}
			}
		}
		if (check)
		{
			cout << "\nPatient ID not found!\n";
		}
	}

	void update_app_list(int id)
	{
		Appointment* ap = new Appointment[100];
		int j = 0;
		
		for (int i = 0; i < no_of_app; i++)
		{
			if (app[i].get_pid() != id)
			{
				ap[j] = app[i];
				j++;
			}
		}
	
		delete[]app;
		
		app = new Appointment[100];
		
		no_of_app = j;
		
		int k = 0;

		for (int i = 0; i < no_of_app; i++)
		{
			if (ap[i] != 0)
			{
				app[i] = ap[i];
				k++;
			}
		}

		no_of_app = k;
	}

	void set_history(Appointment& p, Patient& aa)
	{
		const char* a = p.get_dis();
		aa.history[aa.pcomming].set_disease(a);
		
		int di = p.get_did();
		aa.history[aa.pcomming].set_doc(di);
		
		int fe = p.get_fee();
		aa.history[aa.pcomming].set_fee(fe);
		
		int pi = p.get_pid();
		aa.history[aa.pcomming].set_pid(pi);
		
		aa.history[aa.pcomming].set_date(p.get_Date());
		
		aa.history[aa.pcomming].set_time(p.get_time());
		
		aa.pcomming++;
	}

	void patient_data_from_file()
	{
		ifstream file;
		file.open("Patient.txt");

		for (int i = 0; !file.eof(); i++)
		{
			file >> pat[no_of_pat];
			no_of_pat++;
		}

		file.close();

		patient_history_data();
	}

	void patient_data_to_file()
	{
		ofstream file;
		file.open("Patient.txt", ios::trunc);

		for (int i = 0; i < no_of_pat; i++)
		{
			if (pat[i] != 0)
			{
				file << pat[i];
			}
		}

		file.close();

	}

	void doctors_data_from_file()
	{
		ifstream file;
		file.open("Doctor.txt");

		for (int i = 0; !file.eof(); i++)
		{
			file >> doc[no_of_doc++];
		}

		doc->pvistors(doc, no_of_doc);

		file.close();
	}

	void doctors_data_to_file()
	{
		ofstream file;
		file.open("Doctor.txt", ios::trunc);

		for (int i = 0; i < no_of_doc; i++)
		{
			if (doc[i] != 0)
			{
				file << doc[i];
			}
		}

		file.close();

		patient_visit_file_update();
	}

	void app_data_to_file()
	{
		ofstream file;
		file.open("Appointment.txt", ios::trunc);

		for (int i = 0; i < no_of_app; i++)
		{
			if (app[i] != 0)
			{
				file << app[i] << endl;
			}
		}

		file.close();
	}

	void app_data_from_file()
	{
		ifstream file;
		file.open("Appointment.txt");

		for (int i = 0; !file.eof(); i++)
		{
			file >> app[no_of_app++];
		}

		file.close();
	}

	void print_by_pid()
	{
		bool temp = true;
		int idd = 0;
		
		cout << "\n\nEnter an id for the details of particular patient:";
		cin >> idd;
		
		cout << endl << endl;
		
		for (int i = 0; i < no_of_pat; i++)
		{
			if (pat[i].get_pid() == idd)
			{
				temp = false;
				cout << pat[i];
		
				break;
			}
		}
		if (temp)
		{
			cout << "\nNot found!\n";
		}
	}

	void patient_history_data()
	{
		ifstream file;
		file.open("Patient - History.txt");
		
		while (!file.eof())
		{
			int idd = 0;
			
			file >> idd;
			
			for (int i = 0; i < no_of_pat; i++)
			{
				if (pat[i].get_pid() == idd)
				{
					pat[i].history[pat[i].pcomming].set_pid(idd);
					
					char dis[50];
					file >> dis;
					pat[i].history[pat[i].pcomming].set_disease(dis);
					
					date d;
					file >> d;
					pat[i].history[pat[i].pcomming].set_date(d);
					
					mtime m;
					file >> m;
					pat[i].history[pat[i].pcomming].set_time(m);
					
					int didd = 0;
					file >> didd;
					pat[i].history[pat[i].pcomming].set_doc(didd);
					
					int feee = 0;
					file >> feee;
					pat[i].history[pat[i].pcomming].set_fee(feee);
					
					pat[i].pcomming++;
					
					break;
				}
			}
		}
		file.close();
	}

	void patient_visit_file_update()
	{
		doc->update_visit_file(doc, no_of_doc);
	}

	void patient_history_update()
	{
		pat->update_history(pat, no_of_pat);
	}

	void print_by_did()
	{
		bool temp = true;
		int idd = 0;

		cout << "\n\nEnter an id for the details of particular doctor:";
		cin >> idd;

		cout << endl << endl;

		for (int i = 0; i < no_of_doc; i++)
		{
			if (doc[i].get_docid() == idd)
			{
				temp = false;
				cout << doc[i];

				break;
			}
		}
		if (temp)
		{
			cout << "\nNot found!\n";
		}
	}

	bool patient_id_validity_check(int idd)
	{
		for (int i = 0; i < no_of_pat; i++)
		{
			if (pat[i].get_pid() == idd)
			{
				return false;
			}
		}
		
		return true;
	}

	bool doctor_id_validity_check(int idd)
	{
		for (int i = 0; i < no_of_doc; i++)
		{
			if (doc[i].get_did() == idd)
			{
				return false;
			}
		}

		return true;
	}

public:

	clinic()
	{
		doc = new Doctor[15];
		pat = new Patient[50];
		app = new Appointment[100];
	}

	clinic(const clinic& c)
	{
		doc = c.doc;
		pat = c.pat;
		app = c.app;
	}

	inline void clinic_menu()
	{
		system("Color 4B");
		patient_data_from_file();
		
		doctors_data_from_file();
		
		app_data_from_file();

		int choice = 0;
		char choice2 = ' ';
		
		while (true)
		{
		
		menu:
			
			cout << "\n\t\t\t\tRasaal's clinic\n\n";

			cout << "\n--> Enter \t1\t to add new Doctor\n";

			cout << "\n--> Enter \t2\t to add new Patient\n";

			cout << "\n--> Enter \t3\t to add new appointment\n";

			cout << "\n--> Enter \t4\t to update the appointment status\n";

			cout << "\n--> Enter \t5\t to Print details of all patients, whom a doctor has visited on a particular date\n";

			cout << "\n--> Enter \t6\t to Print details of all patients who visited same doctor but on different days\n";

			cout << "\n--> Enter \t7\t to Print details of all pending appointments of a particular date\n";

			cout << "\n--> Enter \t8\t to Print details of all pending appointments of a particular doctor\n";

			cout << "\n--> Enter \t9\t to Print complete history of a patient, and doctor\n";

			cout << "\n--> Enter \t10\t to search patient by their id\n";

			cout << "\n--> Enter \t11\t to search doctors by their id\n";

			cout << "\n--> Enter \t-1\t to exit:";

			cin >> choice;

			if (choice == 1)
			{
				add_doctor();
			}

			else if (choice == 2)
			{
				add_patient();
			}

			else if (choice == 3)
			{
				add_appointment();
			}

			else if (choice == 4)
			{
				update_status();
			}

			else if (choice == 5)
			{
				print_by_date();
			}

			else if (choice == 6)
			{
				print_by_docid();
			}

			else if (choice == 7)
			{
				print_by_pen_date();
			}

			else if (choice == 8)
			{
				print_by_pen_doc();
			}

			else if (choice == 9)
			{

			all_details:
				
				cout << "\nEnter \tD\t to see tha details of all doctors\n";

				cout << "\nEnter \tP\t to see the details of all patients\n";

				cout << "\nEnter \tA\t to see only the appointments" << endl;

				cin >> choice2;

				if (choice2 == 'D' || choice2 == 'd')
				{
					for (int i = 0; i < no_of_doc; i++)
					{
						cout << endl << doc[i] << endl << endl;
					}
				}

				else if (choice2 == 'P' || choice2 == 'p')
				{
					for (int i = 0; i < no_of_pat; i++)
					{
						cout << endl << pat[i] << endl << endl;
					}
				}

				else if (choice2 == 'A' || choice2 == 'a')
				{
					for (int i = 0; i < no_of_app; i++)
					{
						if (app[i] != 0)
						{
							cout << endl << app[i] << endl << endl;
						}
					}
				}

				else if (choice2 != 'D' && choice2 != 'd' && choice2 != 'A' && choice2 != 'a' && choice2 != 'P' && choice2 != 'p')
				{
					cout << "\nInvalid input\n\n";
					goto all_details;
				}
			}

			else if (choice == 10)
			{
				print_by_pid();
			}

			else if (choice == 11)
			{
				print_by_did();
			}

			else if (choice == -1)
			{
				break;
			}

			else if (choice > 11 || choice < -1)
			{
				cout << "\n\n Invalid input\n\n";
				goto menu;
			}
			else if (choice == 0)
			{
				cout << "\n\n Invalid input\n\n";
				goto menu;
			}

		}
	}


	~clinic()
	{
		delete[]app;
		delete[]doc;
		delete[]pat;
	}

};


int clinic::no_of_doc = 0;
int clinic::no_of_pat = 0;
int clinic::no_of_app = 0;
