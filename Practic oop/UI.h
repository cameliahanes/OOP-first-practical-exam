#pragma once
#include "Controller.h"
#include <iostream>

class UI {

public:
	UI(Controller c) {
		this->controller = c;
	}


	void print_menu() {
		cout << "\n\n";
		cout << "1. add task \n";
		cout << "2. swap 2 priorities\n";
		cout << "3. show all \n";
		cout << "4. show by priority - sorted \n";
		cout << "0. exit\n\n";
	}

	void add_menu() {
		cout << "Give description: ";
		string d;
		cin >> d;
		int dur;
		cout << "Give duration:  ";
		cin >> dur;
		cout << "Give priority: ";
		int p;
		cin >> p;

		bool a = this->controller.add_controller(Task(d, dur, p));
		if (a) {
			cout << "Successfully added task! \n";
		}
		else cout << "Could not add task!\n";
	}

	void print_all_menu() {
		vector<Task> t = this->controller.get_all_controller();
		for (int i = 0; i < t.size(); ++i) {
			cout << t[i].repr();
			cout << "\n";
		}
	}


	void print_by_priority_menu() {
		int p;
		cout << "Give priority: ";
		cin >> p;
		vector<Task> t = this->controller.get_by_priority(p);
		if (t.size() == 0) {
			cout << "No task with priority less than the g=value provided! \n\n";
			return;
		}

		for (int i = 0; i < t.size(); ++i) {
			cout << t[i].repr();
			cout << "\n";
		}
	}



	void swap_priorities_menu() {
		string p1, p2;
		cout << "Give first description: ";
		cin >> p1;
		cout << "Give second description: ";
		cin >> p2;

		if (p1 == p2) {
			cout << "Equal descriptions, can not change priority. \n";
			return;
		}

		bool answer = this->controller.swap_priority_controller(p1, p2);

		if (answer) cout << "Successfully swapped priorities! \n";
		return;
		cout << "Could not swap priorities! \n";
	}

	void run() {
		while (true)
		{
			print_menu();
			int op;
			cin >> op;
			switch (op)
			{

			case 1:
				add_menu();
				break;
			case 2:
				swap_priorities_menu();
				break;
			case 3:
				print_all_menu();
				break;
			case 4:
				print_by_priority_menu();
				break;
			case 0:
				exit(0);
			default:
				break;
			}


		}
	}


private:
	Controller controller;


};

