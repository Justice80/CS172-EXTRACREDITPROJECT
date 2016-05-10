#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Word.h"

void main() {
	//vector of word objects
	std::vector < Word > WordVectr;
	//open file
	std::ifstream input("C:\\Users\\Justice\\Desktop\\Tarzan.txt");
	std::string fileWord;
	//word counter
	int wordcount = 0;

	//To look through each word in the file
	while (input >> fileWord) {
		wordcount++;
		//boolean flag to check if its in the vector
		bool isInVctr = false;
		int index = 0;
		//Make every word all lower case
		for (int k = 0; k < fileWord.size(); k++) {
			fileWord[k] = tolower(fileWord[k]);
		}
		//make a word object for the file word
		Word word(fileWord);
		//show word count to see visual progress
		std::cout << wordcount << std::endl;
		//trigger flag if word is found in vector, break loop
		for (int i = 0; i < WordVectr.size(); i++) {
			if (WordVectr[i].getType() == word.getType()) {
				isInVctr = true;
				index = i;
				break;
			}
		}
		//if nothing is in the vector add word
		if (WordVectr.size() == 0) {
			WordVectr.push_back(word);
		}
		
		else {
			//if the word is in the vector add Frequency
			if (isInVctr == true){
				WordVectr[index].addFrequency();
			}
			//if word isnt already in the vector add it to vector
			else {
				WordVectr.push_back(word);
			}
		}
	}
	//close file
	input.close();

	Word temp;
	//sort vector of Words
	for (int m = 0; m < WordVectr.size(); m++) {
		for (int n = m + 1; n < WordVectr.size(); n++) {
			if (WordVectr[m].getFrequency() < WordVectr[n].getFrequency()) {
				temp = WordVectr[m];
				WordVectr[m] = WordVectr[n];
				WordVectr[n] = temp;
			}
		}
	}

	std::cout << "The top 10 words are:\n";
	//display top 10 words
	for (int z = 0; z < 10; z++) {
		std::cout << WordVectr[z].getType() << "     ";
		std::cout << WordVectr[z].getFrequency() << std::endl;
	}

	int wordCount2 = 0;
	//display amount of words that only have 1 appearance
	for (int b = WordVectr.size() - 1; b >= 0; b--) {
		if (WordVectr[b].getFrequency() == 1) {
			wordCount2++;
		}
	}

	std::cout << "There are " << wordCount2 << " words that appear once\n\n";

	double median = WordVectr.size() / 2;
	double lower = median - 5;
	double upper = median + 5;

	std::cout << "These words appeared near the median:\n";
	//display words around the median
	for (int p = 0; p < WordVectr.size(); p++) {
		if (p > lower && p < upper) {
			std::cout << WordVectr[p].getType() << std::endl;
		}
	}

}