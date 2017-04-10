#pragma once
#include <vector>
#include "Task.h"
#include <fstream>
#include <assert.h>
class Repository{
public:

	Repository(){}



	Repository(std::string filename) {

		if (filename != "") {
			ifstream fin(filename);
			string line;
			while (getline(fin, line)) {
				vector<string> v;
				v.push_back("");
				for (int i = 0; i < line.size(); ++i) {
					if (line[i] != '|')
						v.back() += line[i];
					else v.push_back("");
				}

				int duration = 0;
				for (int i = 0; i < v[1].size(); ++i) {
					duration = duration * 10 + (v[1][i] - '0');
				}

				int priority = 0;
				for (int i = 0; i < v[2].size(); ++i)
					priority = priority * 10 + v[2][i] - '0';

				bool r = this->add_task(Task(v[0], duration, priority));

			}
		}
	}

	/// finds task by descripton given
	///returns the position or -1 if it was not found
	int find_task_by_description(std::string description) {
		for (int i = 0; i < tasks.size(); ++i) {
			if (tasks[i].get_description() == description)
				return i;
		}
		return -1;
	}

	/// function to add a new task
	/// returns true or faslse if the task was added or not
	/// searches for element with the same description and if it was not found then returns true and adds it to the repo
	/// otherwise retunrs false

	bool add_task(Task t) {
		int index = find_task_by_description(t.get_description());
		if (index != -1) return false;

		tasks.push_back(t);
		return true;

	}

	Task find_by_description2(std::string d) {
		vector<Task> t = this->get_all();
		for (int i = 0; i < t.size(); ++i) {
			if (t[i].get_description() == d)
				return t[i];
		}
		string dd = "";
		return Task(dd, -1, -1);
	}

	bool swap_priority(string& d1, string& d2){
		Task t1 = find_by_description2(d1);
		Task t2 = find_by_description2(d2);
	
		int pp1 = find_task_by_description(d1);
		int pp2 = find_task_by_description(d2);

		int aux = this->tasks[pp1].get_priority();
		this->tasks[pp1].set_priority(this->tasks[pp2].get_priority());
		this->tasks[pp2].set_priority(aux);
		return true;

		if (t1.get_priority() == t2.get_priority()) return false;

		t1.set_priority(t2.get_priority());
		t2.set_priority(aux);
		return true;
	}



	vector<Task> get_all() {
		return tasks;
	}


	void test_add() {
		Repository r("");
		string description = "work";
		Task t(description, 60, 1);
		r.add_task(t);
		assert(r.get_all().size() == 1);
	}

	void test_return_priority() {
		Repository r("");
		string description = "work";
		Task t(description, 60, 1);

		string d2 = "work2";
		Task t2(d2, 11, 3);

		r.add_task(t);
		r.add_task(t2);

		r.swap_priority(description, d2);
		assert(r.tasks[0].get_priority() == 3);

		assert(r.tasks[1].get_priority() == 1);

		assert(r.get_all().size() == 2);




	}




private:
	vector<Task> tasks;
};


 