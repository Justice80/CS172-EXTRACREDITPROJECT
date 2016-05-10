#ifndef WORD_H_
#define WORD_H_

#include <string>

class Word {
private:
	std::string type;
	int frequency;
public:
	Word();
	Word(std::string);
	std::string getType() const;
	void setType(std::string);
	int getFrequency() const;
	void addFrequency();
};

#endif