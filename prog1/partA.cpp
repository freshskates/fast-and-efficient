//Robert Cacho Ruiz
//This code is supposed to calculate the total check amount and display one by one in the console. 
#include <iostream>
using namespace std; 
#include <string>
#include <vector>
//last name, hours worked each day of the week, the hourly rate, and the pay for the week.
struct employee {
	string lastname;
	int hours[5];
	double total = 0.0;
	float rate; 
};
//prototypes
void init(vector<employee>& V, int n);
void compute(employee& E);
void compute(employee &E) {
	int hours = 0; 
	//foreach enchanced for loop to sum up 
	for (auto x : E.hours) {
		E.total += ((double)x * E.rate);
		hours += x; 
	}
	//branchless if
	E.total += ((hours > 40) * (E.rate * 1.5) * (hours - 40.0));
	printf("Paycheck: %s, $%.2f\n", E.lastname.c_str(), E.total);
}
void init(vector<employee> &V, int n) {
	//preferred to do this way because simpler instead of writing each cout
	string d[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
	cout << "Enter Info for " << n << " employees\n\n";
	for (int i = 0; i < n; i++) {
		employee temp;
		cout << i + 1 << " | Enter the last name of the employee: ";
		getline(cin, temp.lastname);
		cout << i + 1 << " | " << "Enter hourly pay rate: ";
		cin >> temp.rate; cin.ignore(1000, 10);
		//I hate doing two for loops inside each other but this is still O(n) because this amount of times iterated is constant(5) and does not increase with amount of employees
		for (int j = 0; j < 5; j++) {
			cout << i + 1 << " | " << "Enter hours worked on " << d[j] << ": ";
			cin >> temp.hours[j]; cin.ignore(1000, 10);
		}
		compute(temp);
		V.emplace_back(temp);
	}
}
int main() {	
	int n;
	//creating vector that will store employees
	vector<employee>E;
	do {
		cout << "Enter the amount of employees: ";
		cin >> n; cin.ignore(1000, 10);
	} while (n < 0);
	init(E, n);
}