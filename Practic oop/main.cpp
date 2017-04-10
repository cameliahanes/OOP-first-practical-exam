#include <iostream>
#include "UI.h"

int main() {
	Repository r("database.in");
	Controller c(r);
	UI ui(c);
	ui.run();
}