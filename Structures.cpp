#include <iostream>
#include <string>

struct Date {
	int day{ 1 };
	int month{ 1 };
	int year{ 1970 };
	std::string note = "empty";
};
void print_date(const Date& D) {   //передается константной ссылкой для экономии памяти и запрета изменения
	std::cout << D.day << '.' << D.month << '.' << D.year << " - " << D.note << std::endl;
}
Date enter_date() {
	Date result;
	std::cout << "Введите день -> ";
	std::cin >> result.day;
	std::cout << "Введите месяц -> ";
	std::cin >> result.month;
	std::cout << "Введите год -> ";
	std::cin >> result.year;
	std::cin.ignore();
	std::cout << "Введите запись -> ";
	std::getline(std::cin, result.note);
	return result;
}
void fill_date(Date& D) { // более правильная функция
	
	std::cout << "Введите день -> ";
	std::cin >> D.day;
	std::cout << "Введите месяц -> ";
	std::cin >> D.month;
	std::cout << "Введите год -> ";
	std::cin >> D.year;
	std::cin.ignore();
	std::cout << "Введите запись -> ";
	std::getline(std::cin, D.note);	
}

struct Date2 {
	int day{1};
	int month{1};
	int year{1970};
};
struct CoinsKeeper {
	std::string name{"noname"};
	Date2 birthday;
	int coins_number{ 0 };
	int* coins{ nullptr };
};
void print_keeper(const CoinsKeeper& CK) {
	std::cout << "Имя: " << CK.name << std::endl;
	std::cout << "Дата рождения: " << CK.birthday.day << '.' << CK.birthday.month << '.' << CK.birthday.year << '.' << std::endl;
	std::cout << "Монеты:{ ";
	for (int i = 0; i < CK.coins_number; i++)
		std::cout << CK.coins[i] << ", ";
	std::cout << "\b\b }\n";
}

inline int age(const CoinsKeeper& CK, int  year) {
	return (year - CK.birthday.year);
}

int cash(const CoinsKeeper& CK) {
	int sum = 0;
	for (int i = 0; i < CK.coins_number; i++)
		sum += CK.coins[i];
	return sum;
}



int main() {
	setlocale(LC_ALL, "ru");
	int n;
	// Структура - это описание множества, состоящего из одной или более переменных, возможно имеющих различные типы, объедененных под одним именем.
	//Является производным пользовательским типом данных, используемым для создания объектов.

	// Создание структуры
	
	struct Person {  
		std::string name; 
		int age;
		std::string job;
		int salary;
	}p4, p5, p6{}; // Второй способ

	Person p1; // Создание объекта структуры. Первый способ
	p1.name = "Thomas"; // поля объекта
	p1.age = 29;
	p1.job = "Proger";
	p1.salary = 60000;

	std::cout << "Имя: " << p1.name << std::endl;
	std::cout << "Возраст: " << p1.age << std::endl;
	std::cout << "Должность: " << p1.job << std::endl;
	std::cout << "Зарплата: " << p1.salary << std::endl;
	std::cout << "---------------------------------------\n";

	Person p2{
		"Rodion",
		30,
		"Director",
		12000
	};

	std::cout << "Имя: " << p2.name << std::endl;
	std::cout << "Возраст: " << p2.age << std::endl;
	std::cout << "Должность: " << p2.job << std::endl;
	std::cout << "Зарплата: " << p2.salary << std::endl;
	std::cout << "---------------------------------------\n";

	Person p3 = p1; // Копирование значений полей объекта р1 в поля объекта р3
	
	// Указатели на объекты
	
	Date d1{ 20,12,2023};
		
	Date* pd1 = &d1;
	std::cout << (*pd1).day << std::endl; //неудобно
	std::cout << pd1->day << std::endl; // удобно)) обращение к полю объекта чз указатель на сам объект
	
	print_date(d1);
	
	//Структуры и функции
	
	Date d2 = enter_date();
	print_date(d2);
	Date d3;
	fill_date(d3);
	print_date(d3);
	

	// Задача 1. Хранитель монет
	std::cout << "\tЗадача 1\n";
	CoinsKeeper ck{
		"Margot",
		{29,7,2013},
		6,
		new int[6] {1,2,5,10,50,100}
	};
	print_keeper(ck);
	std::cout << "Возраст: " << age(ck,2023) << std::endl;
	std::cout << "Общие сбережения: " << cash(ck) << std::endl;


	return 0;
}
