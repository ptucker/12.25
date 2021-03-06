// HW 12.25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/*class Date {

public:
	Date() {
		year = 2018;
		month = 6;
		day = 12;
	}

	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	
	void setDay(int x) {
		day = x;

	}

	void setMonth(int m) {
		month = m;
	}

	void setYear(int y) {
		year = y;
	}

private:
	int day;
	int month;
	int year;

};*/

class Transaction {

public:

	Transaction(/*Date &o1,*/ char t, double a, double b, string d) {
		
		//o1.setDay(12);
		//o1.setMonth(6);
		//o1.setYear(2018);

		type = t;
		amount = a;
		balance = b;
		description = d;

	}

private:
	//Date(& o);
	char type;
	double amount;
	double balance;
	string description;
	






};

class Account {

public:
	Account() {
		id = 0;
		balance = 0;
		annualInterestRate = 0;
		name = "Bob";
	}

	Account(string n, int i, double b, double r) {
		name = n;
		id = i;
		balance = b;
		annualInterestRate = r;

	}

	void setID(int a) {
		id = a;
	}



	int getID() {

		return id;
	}

	void setName(string n) {
		name = n;
	}

	string getName() {
		return name;
	}

	void setBalance(double b) {
		balance = b;
	}

	double getBalance() {
		return balance;
	}

	void setRate(double c)
	{
		annualInterestRate = c;
	}

	double getRate() {
		return annualInterestRate;
	}

	double getMonthlyInterestRate() {
		return annualInterestRate * (1 / 12);
	}

	double initialwithdraw(double amount) {
		double set = balance - amount;

		transactions.push_back(set);
		
	}

	void withdraw(double amount, int i) {
		double withdraw2 = transactions[i - 1] - amount;

		transactions.push_back(withdraw2);
	}
	
	double test(int i) {

		return transactions[i];
	}

	void initialdeposit(double amount) {
		double depositset = balance + amount;
		
		transactions.push_back(depositset);

	}

	void deposit(double amount, int i) {
		double set2 = amount + transactions[i - 1];
			transactions.push_back(set2);
	}
private:
	int id;
	double balance;
	double  annualInterestRate;
	string name;
	vector<double> transactions;
};


int main()
{

	Account TestAccount;
	TestAccount.setBalance(1000);
	TestAccount.setID(1122);
	TestAccount.setRate(.015);
	TestAccount.setName("George");

	
	cout << "Account Holder Name " << "\t" << "Interest Rate " << "\t" << "Balance " << endl;
	cout << TestAccount.getName() << "          " << TestAccount.getRate() << "          " << TestAccount.getBalance() << endl;
	
	TestAccount.initialdeposit(30);
	cout << "A deposit of $30 changed the balance to " << TestAccount.test(0) << endl;
	
	TestAccount.deposit(40, 1);
	cout << "A deposit of $40 changed the balance to " << TestAccount.test(1) << endl;

	TestAccount.deposit(50, 2);
	cout << "A deposit of $50 changed the balance to " << TestAccount.test(2) << endl;

	TestAccount.withdraw(5, 3);
	cout << "A withdrawl of $5 changed this balance to " << TestAccount.test(3) << endl;

	TestAccount.withdraw(4, 4);
	cout << "A withdrawl of $4 changed this balance to " << TestAccount.test(4) << endl;

	TestAccount.withdraw(2, 5);
	cout << "A withdrawl of $2 changed this balance to " << TestAccount.test(5) << endl;




		return 0;
}

