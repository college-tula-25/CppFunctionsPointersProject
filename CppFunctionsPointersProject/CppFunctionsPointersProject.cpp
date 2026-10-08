#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Employee
{
	char name[20];
	int age;
};

bool EmployeeAgeComparer(Employee a, Employee b);
bool EmployeeNameComparer(Employee a, Employee b);

template<typename T>
void ArraySort(T* array, 
	int size, 
	void(*sortAlgorithm)(T*, int, bool(*comparer)(T, T)), 
	bool(*comparer)(T, T));

template<typename T>
void ArraySortBubble(T* array, int size, bool(*comparer)(T, T));

template<typename T>
void ArraySortSelect(T* array, int size, bool(*comparer)(T, T));

template<typename T>
void Swap(T& a, T& b);

void EmployeesPrint(Employee* array, int size);



int main()
{
	srand(time(nullptr));

	int size{ 5 };
	Employee* employees = new Employee[size];
	strcpy(employees[0].name, "Sammy");
	strcpy(employees[1].name, "Jimmy");
	strcpy(employees[2].name, "Bobby");
	strcpy(employees[3].name, "Tommy");
	strcpy(employees[4].name, "Mikky");

	for (int i{}; i < size; i++)
		employees[i].age = 20 + rand() % 21;

	EmployeesPrint(employees, size);
	ArraySort(employees, size, ArraySortBubble, EmployeeAgeComparer);
	EmployeesPrint(employees, size);
	ArraySort(employees, size, ArraySortSelect, EmployeeNameComparer);
	EmployeesPrint(employees, size);
}




bool EmployeeAgeComparer(Employee a, Employee b)
{
	return a.age < b.age;
}

bool EmployeeNameComparer(Employee a, Employee b)
{
	return strcmp(a.name, b.name) < 0;
}

//void ArraySort(Employee* array, int size, bool(*comparer)(Employee, Employee))
//{
//	for (int top{}; top < size; top++)
//		for (int i{ size - 1 }; i > top; i--)
//			if (comparer(array[i], array[i - 1]))
//				Swap(array[i], array[i - 1]);
//}

void EmployeesPrint(Employee* array, int size)
{
	for (int i{}; i < size; i++)
		std::cout << array[i].name << " " << array[i].age << "\n";
	std::cout << "\n";
}

template<typename T>
void ArraySortBubble(T* array, int size, bool(*comparer)(T, T))
{
	for (int top{}; top < size; top++)
		for (int i{ size - 1 }; i > top; i--)
			if (comparer(array[i], array[i - 1]))
				Swap(array[i], array[i - 1]);
}

template<typename T>
void ArraySortSelect(T* array, int size, bool(*comparer)(T, T))
{
	for (int left{}; left < size; left++)
	{
		int min{ left };
		for (int i{ left + 1 }; i < size; i++)
			if (comparer(array[i], array[min]))
				min = i;
		Swap(array[left], array[min]);
	}
}


template<typename T>
void ArraySort(T* array, int size, void(*sortAlgorithm)(T*, int, bool(*comparer)(T, T)), bool(*comparer)(T, T))
{
	sortAlgorithm(array, size, comparer);
}

template<typename T>
void Swap(T& a, T& b)
{
	T temp{ a };
	a = b;
	b = temp;
}
