//Написати клас Data(дата), що містить поля - день, місяць, рік.Реалізувати конструктори :конструктор по замовчуванню, що надає даті значення 01.01.1900;
//конструктор з параметрами, що отримує рядок типу char у вигляді дд.мм.рррр і ініціалізує відповідні поля;
//конструктор з параметрами, що отримує три цілі значення типу int(день, місяць, рік) і ініціалізує відповідні поля.
//Якщо під час ініціалізації дата не відповідає дійсності вивести "Error data..." і перехід на новий рядок.Якщо дата не правильна надає значення 01.01.1900; (Рік можливий від 0 до 2050).
//Реалізувати методи які :void setDay(int) - який змінює значення дати класу;void setMonth(int) - який змінює значення місяця;void setYear(int) - який змінює значення року класу;
//bool verifikation() - яка перевіряє коректність дати і повертає(true / false) відповідно(правильна / неправильна).І якщо дата не правильна надає значення 01.01.1900;
//void OutDataddmmyy() - виводить дату у форматі дд.мм.рр, наприклад 02.03.19;void OutDataddmmyyyy() - виводить дату у форматі дд.мм.рррр, наприклад 02.03.2019;
//void OutDataddMonthyyyy() - виводить дату у форматі дд місяць рррр, наприклад 02 March 2019.
//Місяці виводити англійською мовою відповідно :January, February, March, April, May, June, July, August, September, October, November, December.
#include <iostream>
#include<Windows.h>
#include <cmath>

using namespace std;

class Data
{
private:
	int day;
	int month;
	int year;
	const char* mont[12]={ "January"," February"," March", "April"," May", "June", "July", "August", "September"," October", "November", "December" };
public:
	Data() {//конструктор по замовчуванні
		day = 1;
		month =1;
		year = 1900;
	}
	Data(int iDay, int iMonth, int iYear) {//конструктор з параметрами
	        this->day = iDay;
			this->month = iMonth;
			this->year = iYear;
			if (verifikation() == false) {
				cout << "Error data..." << endl;
				this->day = 1;
				this->month = 1;
				this->year = 1900;
			}
	}
	Data(const char* str, const char* str1, const char* str2, const char* str3, const char* str4) {
		int a = atoi(str);
		int b = atoi(str2);
		int c = atoi(str4);
		this->day = a;
		this->month = b;
		this->year = c;
		if (verifikation() == false) {
			cout << "Error data..." << endl;
			this->day = 1;
			this->month = 1;
			this->year = 1900;
		}
	}
	
	void setDay(int anothDay) {//змінюєм день 
		day = anothDay;
		if (verifikation() == false) {
			cout << "Error data..." << endl;
			this->day = 1;
			this->month = 1;
			this->year = 1900;
		}
	}
	void setMonth(int anothMonth) {//змінюєм місяць 
		month = anothMonth;
		if (verifikation() == false) {
			cout << "Error data..." << endl;
			this->day = 1;
			this->month = 1;
			this->year = 1900;
		}
	}
	void setYear(int anothYear){//змінюєм рік
		year= anothYear;
		if (verifikation() == false) {
			cout << "Error data..." << endl;
			this->day = 1;
			this->month = 1;
			this->year = 1900;
		}
	}
	bool verifikation() {//+-
		if ((this->day > 31 or this->day < 1) || (this->month > 12 or this->month < 1) || (this->year < 0 or this->year>2050)) {//перевірка меж введення
			this->day = 1;
			this->month = 1;
			this->year = 1900;
			return false;
		}
		else if (this->day == 29 && this->month == 2 && (this->year % 4) != 0 or this->day==30 ) {//перевірка лютого
			this->day = 1;
			this->month = 1;
			this->year = 1900;
			return false;
		}
		else if (this->day == 30 &&(this->month % 2) != 0) {//перевірка місяця на 30 днів
			this->day = 1;
			this->month = 1;
			this->year = 1900;
			return false;
		}
		else if (this->day == 31 && (this->month % 2 )== 0) {//перевірка місяця на 31 день 
			this->day = 1;
			this->month = 1;
			this->year = 1900;
			return false;
		}
		else {
			return true;
		}
	}
	void OutDataddmmyy() {//дд.мм.рр, наприклад 02.03.19;
		int a=0;
		if (this->day > 9) {
			cout << day << ".";
		}
		else if (this->day <= 9) {
			cout << "0" << day << ".";
		}

		if (this->month > 9) {
			cout << month << ".";
		}
		else if (this->month <= 9) {
			cout << "0" << month << ".";
		}
		if (this->year >= 100 && this->year%100!=0) {
				a = this->year % 100;		
				if (a > 9) {
					cout << a ;
				}
				else if (a <= 9) {
					cout << "0" << a;
				}				
		}	
		else if (this->year < 10){
			cout <<"0"<< year;
		}		
		else {
			cout << year;
		}
    }
	void OutDataddmmyyyy() {//виводить дату у форматі дд.мм.рррр
		if (this->day > 9) {
			cout << day << ".";
		}
		else if (this->day <= 9) {
			cout << "0" << day << ".";
		}

		if (this->month > 9) {
			cout << month << ".";
		}
		else if (this->month <= 9) {
			cout << "0" << month << ".";
		}
		cout << year;
	}
	void OutDataddMonthyyyy() {	//виводить дату у форматі дд місяць рррр, наприклад 02 March 2019.
		if (this->day > 9) {
			cout << day << " ";
		}
		else if (this->day <= 9) {
			cout << "0" << day << " ";
		}
		cout << mont[this->month-1] << " ";		
		cout << year;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int d = 0, m = 0, y = 0;
	int d1 = 0, m1 = 0, y1 = 0;
	cout << "\tEnter a date next form : dd mm yyyy" << endl;
	cin >> d >> m >> y;

	Data first(d, m, y);
	first.OutDataddmmyy();
	cout << endl;
	first.OutDataddmmyyyy();
	cout << endl;
	first.OutDataddMonthyyyy();
	cout << endl;
	//////////////////////////////////////////////////////////////////////////////////
	cout << "\n\tEnter a new day next form :dd" << endl;
	cin >> d1;
	first.setDay(d1);
	first.OutDataddmmyy();
	cout << endl;
	first.OutDataddmmyyyy();
	cout << endl;
	first.OutDataddMonthyyyy();
	cout << endl;
	//////////////////////////////////////////////////////////////////////////////////
	cout << "\n\tEnter a new month next form :mm" << endl;
	cin >> m1;
	first.setMonth(m1);
	first.OutDataddmmyy();
	cout << endl;
	first.OutDataddmmyyyy();
	cout << endl;
	first.OutDataddMonthyyyy();
	cout << endl;
	//////////////////////////////////////////////////////////////////////////////////
	cout << "\n\tEnter a new year next form :yy" << endl;
	cin >> y1;
	first.setYear(y1);
	first.OutDataddmmyy();
	cout << endl;
	first.OutDataddmmyyyy();
	cout << endl;
	first.OutDataddMonthyyyy();
	cout << endl<<endl;
	//////////////////////////////////////////////////////////////////////////////////	
	cout << "\n\tconst char date" << endl;
	Data second("02",".","03",".","2004");	
	second.OutDataddmmyy();
	cout << endl;
	second.OutDataddmmyyyy();
	cout << endl;
	second.OutDataddMonthyyyy();
	cout << endl;
}