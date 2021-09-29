#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <list>
#include <algorithm>

using namespace std;

struct Task {
public:
	string name;
	float deadline, estimated;
	int getUrgency() const {
		return ceil(deadline - estimated);
	}
};

void newTask(Task task[], int n1) {
	for (int i = 0; i < n1; i++)
	{
		system("cls");
		cout << "Input task name: ";
		cin >> task[i].name;
		cout << "Input task deadline (in hours): ";
		cin >> task[i].deadline;
		cout << "Input task estimated work time (in hours): ";
		cin >> task[i].estimated;
	}
}

bool sortTaskByUrgency(const Task& lhs, const Task& rhs)
{
	return lhs.getUrgency() < rhs.getUrgency();
}

//Prints all task whether sorted or not
void printAll(Task task[], int n1) {
	system("cls");
	cout << "Name\tDeadline\tEstimated\tUrgency\n";
	for (int i = 0; i < n1; i++)
	{
		cout << task[i].name << "\t" << task[i].deadline << "\t\t" << task[i].estimated << "\t\t" << task[i].getUrgency() << endl;
	}
}

int main() {
	int n;
	cout << "How many task do you have? ";
	cin >> n;
	//Create number of object based on input n
	std::vector<Task> p(n);
	newTask(p.data(), n);
	std::list<Task> taskList;
	std::sort(p.begin(), p.end(), sortTaskByUrgency);
	printAll(p.data(), n);
	cin.ignore();
	return 0;
}