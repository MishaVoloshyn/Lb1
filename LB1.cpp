#include<iostream>
using namespace std;

class Student
{
	char* name;
	char* email;
	int age;
public:
	Student()
	{
		cout << "Constructor by def.\n";
		name = nullptr;
		email = nullptr;
		age = 0;
	}

	Student(const char* n, const char* e, int a)// Oleg 20
	{
		name = new char[strlen(n) + 1]; // выделяем память при создани  объекта !!
		strcpy_s(name, strlen(n) + 1, n);
		email = new char[strlen(e) + 1]; // выделяем память при создани  объекта !!
		strcpy_s(email, strlen(e) + 1, e);
		age = a;
		cout << "Constructor 3 params\n";
	}
	void Input()
	{
		char buffN[20];
		char buffE[50];
		cout << "Enter name: ";
		cin >> buffN;
		cout << "Enter email: ";
		cin >> buffE;
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "... \n";
			delete[]name;
		}
		if (email != nullptr)
		{
			cout << "Delete -> " << email << "... \n";
			delete[]email;
		}
		name = new char[strlen(buffN) + 1];
		strcpy_s(name, strlen(buffN) + 1, buffN);
		email = new char[strlen(buffE) + 1];
		strcpy_s(email, strlen(buffE) + 1, buffE);

		cout << "Enter age: ";
		cin >> age;
	}
	void Print()
	{
		cout << "Name: " << name << " Email: " << email << "\tAge: " << age << endl;
	}

	void SetN(const char* n)
	{
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "... \n";
			delete[]name;
		}
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	void SetE(const char* e)
	{
		if (email != nullptr)
		{
			cout << "Delete -> " << email << "... \n";
			delete[]email;
		}
		email = new char[strlen(e) + 1];
		strcpy_s(email, strlen(e) + 1, e);
	}
	void SetA(int a)
	{
		age = a;
	}
	char* GetN()
	{
		return name;
	}
	char* GetE()
	{
		return email;
	}
	int GetA()
	{
		return age;
	}
	~Student()
	{
		delete[] name; // явно освобождаем память при уничтожении объекта !!!!
		delete[] email; // явно освобождаем память при уничтожении объекта !!!!
		cout << "Destructor\n";
	}

	/* добавить:
	   * поле емайл(char*)
	   * конструктор  с 3я параметрами
	   * методы аксессоры
	   * удаление выделенной динамической памяти в деструкторе.
	*/

};

int main()
{
	Student a;
	a.SetN("Misha");
	a.SetE("Misha777@gmail.com");
	a.SetA(19);
	cout << " Name: " << a.GetN() << " Email: " << a.GetE() << " Age: " << a.GetA() << endl << endl;

	Student obj1("Oleg", "Oleg777@gmail.com", 20);
	obj1.Print();
	obj1.Input();
	obj1.Print();

	Student obj2;
	obj2.Input();
	obj2.Print();

}