#pragma once

#include "Repository.h"
#include <algorithm>
#include <assert.h>

class Controller {
public:
	Controller(Repository repo) {
		this->repository = repo;
	}


	Controller(){}


	/// calls the repository to add the new task
	bool add_controller(Task t) {
		return this->repository.add_task(t);
	}

	vector<Task> get_all_controller() {
		return this->repository.get_all();
	}

	/// gets all tasks wih wanted priority
	/// retusn a vector containing those tasks
	/// using bubble sort to sort by priority
	/// inside the function
	vector<Task> get_by_priority(int p) {
		vector<Task> tk;
		vector<Task> T = get_all_controller();
		for (int i = 0; i < T.size(); ++i) {
			if (T[i].get_priority() < p) {
				tk.push_back(T[i]);
			}
		}

		int ok;
		do {
			ok = 0;
			for (int i = 0; i < tk.size() - 1; ++i) {
				if (tk[i].get_priority() < tk[i + 1].get_priority()) {
					swap(tk[i], tk[i + 1]);
					ok = 1;
				}
			}
		} while (ok == 1);
	
		return tk;
	
	}


	bool swap_priority_controller(string& d1, string& d2) {
		return this->repository.swap_priority(d1, d2);
	}

private:
	Repository repository;
};

