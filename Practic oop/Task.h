#pragma once
#include <string>
using namespace std;

class Task {
public:
	Task(std::string& description, int duration, int priority) {
		this->description = description;
		this->duration = duration;
		this->priority = priority;
	}

	std::string get_description() {
		return description;
	}

	void set_description(std::string newd) {
		this->description = newd;
	}

	int get_duration() {
		return this->duration;
	}

	int get_priority() {
		return this->priority;
	}

	void set_priority(int new_p) {
		this->priority = new_p;
	}

	std::string repr() {
		return this->description + " " + to_string(this->duration) + " "  + to_string(this->priority);
	}

	bool operator==(Task& other) {
		return this->description == other.get_description();
	}

	bool compare(Task i, Task j) { return (i.get_priority() > j.get_priority()); }


private:
	std::string description;
	int duration;
	int priority;

};