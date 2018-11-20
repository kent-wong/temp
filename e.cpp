#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
	Employee(const string& name, const string& ssn);
	~Employee() {}
	const string& get_name() const;
	void print(ostream& out) const;
	void print(ostream& out, string& msg) const;
protected:
	string m_name;
	string m_ssn;
};

Employee::Employee(const string& name, const string& ssn): m_name(name), m_ssn(ssn) {

}

inline const string& Employee::get_name() const {
	return m_name;
}

void Employee::print(ostream& out) const {
	out << m_name << endl;
	out << m_ssn << endl;
}

void Employee::print(ostream& out, string& msg) const {
	out << msg << endl;
	print(out);
}


class Manager : public Employee {
public:
	Manager(const string& name, const string& ssn, const string& title);
	const string title_name() const;
	const string& get_title() const;
	void print(ostream& out) const;
	void set_title(const string& title);
private:
	string m_title;
};


Manager::Manager(const string& name, const string& ssn, const string& title): Employee(name, ssn), m_title(title) {

}

void Manager::print(ostream& out) const {
	Employee::print(out);
	out << m_title << endl;
}

const string& Manager::get_title() const {
	return m_title;
}

void Manager::set_title(const string& title) {
	m_title = title;
}

const string Manager::title_name() const {
	return string(m_title + ": " + m_name);
}

int main() {
	/*
	Employee bob("Bob Jones", "123456");
	Manager bill("Bill Smith", "666666", "VIP");

	string name = bill.get_name();
	cout << "bill name: " << name << endl;

	string bob_name = bob.get_name();
	cout << "bob name: " << bob_name << endl;

	cout << "bill title name: " << bill.title_name() << endl;

	bill.print(cout);
	bob.print(cout);
	string a = "Employee:";
	bob.print(cout, a);
	//bill.print(cout, a);
	*/


	Manager bill("Bill Smith", "666666", "VIP");
	bill.print(cout);

	Employee *p = &bill;
	p->print(cout);

	Employee& em = bill;
	em.print(cout);

	//bill.set_title("VVV");
	//bill.print(cout);






	return 0;
}
