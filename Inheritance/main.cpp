#include<iostream>
#include<string>

using namespace std;

class Human
{
//protected:
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_first_name()const
	{
		return first_name;
	}
	const std::string& get_last_name()const
	{
		return last_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstrucror:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestrucror:\t" << endl;
	}
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " ���\n";
	}
};

class Student :public Human
{
	std::string speciality;
	std::string group;
	float rating;
	float attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	float get_rating()const
	{
		return rating;
	}
	float get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(float rating)
	{
		this->rating = rating;
	}
	void set_attendance(float attendance)
	{
		this->attendance = attendance;
	}
	Student
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, float rating, float attendance
	):Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestrucror:\t" << endl;
	}
	void print()const
	{
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};

class Teacher:public Human
{
	std::string speciality;
	unsigned int experiance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experiance()const
	{
		return experiance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experiance(unsigned int experiance)
	{
		this->experiance = experiance;
	}


	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, unsigned int experiance
	):Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experiance(experiance);
		cout << "TConstrucror:\t" << this << endl;
	}

	~Teacher()
	{
		cout << "TDestrucror:\t" << endl;
	}
	void print()const
	{
		Human::print();
		cout << speciality << " " << experiance << endl;
	}
};

class Graduate : public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, float rating, float attendance,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_subject(subject);
		cout << "GConstructor\t" << this << endl;
	}

	~Graduate()
	{
		cout << "GDestructor\t" << this << endl;
	}
	void print()const
	{
		Student::print();
		cout << subject << endl;
	}
};
//#define INHERITANCE_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef  INHERITANCE_CHECK
	
	Human human("�������", "�������", 18);
	human.print();

	Student student("������", "����", 20, "���", "SPD121", 10, 100);
	student.print();

	Teacher teacher("����","������", 50, "���", 20);
	teacher.print();

	Graduate graduate("�������", "�����", 35, "���", "SPD121", 1, 100, "������������� �������������");
	graduate.print();
#endif // INHERITANCE_CHECK
	Human* group[] =
	{
		new Student("������", "����", 20, "���", "SPD121", 10, 100),
		new Student("�������", "�������", 25, "���", "SPD121", 89, 65),
		new Teacher("����","������", 50, "���", 20),
		new Teacher("�������","�������", 55, "���", 40),
		new Graduate("�������", "�����", 35, "���", "SPD121", 1, 100, "������������� �������������")
	};
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->print();
		cout << "\n---------------------------------\n";
	}
}