#include <fstream>
#include <ios>
#include <string>
#include <iostream>
#include <vector>

int main() {
	//open a file in append mode, on the desktop
	std::string dirPart1 = "C:\\Users\\Penny"; std::string dirPart2 = " "; std::string dirPart3 = "-"; std::string dirPart4 = " "; std::string dirPart5 = "Work\\Desktop";
	std::string fullDir = dirPart1 + dirPart2 + dirPart3 + dirPart4 + dirPart5;
	std::string noteTitle = "Things to Talk to Dimey about";
	//std::string fileName = fullDir + noteTitle;
	std::string fileName = "ThingsToTalkToDimeyAbout.txt";
	//std::fstream note(fileName.c_str(), std::ios::app);
	std::fstream note(fileName.c_str(), std::ios::in);
	if (note.fail()) {
		note.open(fileName.c_str(), std::ios::app);
		note << noteTitle << "\n\n\n";
	}
	note.close();
	//note.open(fileName.c_str(), std::ios::app);
	std::string userInput;
	std::string line;
	std::vector <std::string> lineStore;
	int lineNumber = 0;
	while (std::getline(std::cin, userInput)) {
		if (userInput == ":d") {
			note.open(fileName.c_str(), std::ios::in);
			while (std::getline(note, line)) {
				lineStore.push_back(line);
				for (int i = 0; i < size(lineStore); ++i) {
					std::cout << i + 1 << lineStore[i] << std::endl;
				}
			}
			std::cout << " Which line to delete?\n ";
			std::cin >> lineNumber;
			for (int i = 0; i < size(lineStore); ++i) {
				if (lineNumber = i) {
					std::getline(note, lineStore[lineNumber]);
					remove(lineStore[lineNumber]);
				}
			}

			
		

			
		}
		note << "-" << userInput << "\n\n";
	}
	note.close();
	
	system("pause");
}
