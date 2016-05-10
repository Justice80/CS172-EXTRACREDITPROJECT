#include <iostream>
#include <fstream>
#include <string>
#include "Word.h"

Word::Word() {
	type = "";
	frequency = 0;
}

Word::Word(std::string s) {
	type = s;
	frequency = 1;
}

void Word::setType(std::string s) {
	type = s;
	addFrequency();
}

std::string Word::getType() const { return type; }
int Word::getFrequency() const { return frequency; }
void Word::addFrequency() { this-> frequency++; }