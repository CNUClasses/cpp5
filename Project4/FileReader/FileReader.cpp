#include <iostream>
#include <fstream>
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"
using namespace std;
using namespace KP_FileReaderClass;

FileReader::FileReader() : filecontents("") { }



/*
	Public method for FileReader. Adds the contents to the file	
		to variable conents

	Input :
		String passed by value
		Reference to a string : contents

	Returns an int based on teh success of ReadTheWholeFile()
*/
int FileReader::getFileContents(const std::string filename, std::string &contents) {
	if (filename != "X") {
		int success = ReadTheWholeFile(filename);
		contents = getContents(); 
		return success;
	}
	else {
		return USER_CHOSE_TO_EXIT;
	}
}

/*
	Gets the contents of the file line by line
	Each line is delimited by a comma

	Input :
		Reference to a string : filename

	Returns an int SUCCEEDED:0, COULD_NOT_OPEN_FILE:-2
*/
int FileReader::ReadTheWholeFile(const std::string &filename) {
	ifstream file (filename);

	if (file.is_open()) {
		string line("");
		while (getline(file,line)) {
			addToContents(line);
		}
	} else {
		return COULD_NOT_OPEN_FILE;
	}
	return SUCCEEDED;
}

/*
	Retrives the file contents variable

	Returns the string stored in filecontents
*/
std::string FileReader::getContents() {
	return FileReader::filecontents;
}

/*
	Concatinates the data to the file content string

	Input :
		Reference to a string, data
*/
void FileReader::addToContents(std::string &data) {
	FileReader::filecontents += data;
}