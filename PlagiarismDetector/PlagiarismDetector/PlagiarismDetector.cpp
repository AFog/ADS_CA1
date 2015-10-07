#include "PlagiarismDetector.h"
#include "PlagiarismFile.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>
#include <iomanip>
#include <ctype.h>
using namespace std;

PlagiarismDetector::PlagiarismDetector()
{
}

PlagiarismDetector::~PlagiarismDetector()
{
}

bool PlagiarismDetector::getDirFiles()//adds directory files to a vector(dirFiles) and creates PlagiariamFile objects and adds them to vector(fileObjects)
{


	bool validDir = true;

		cout << "Please enter a directory " << endl;
		cin >> dirIn;
		cout << "\n" << endl;

		DIR *directory;//pointer to directory
		struct dirent *inputDirectory;//dirent struct object

		if ((directory = opendir(dirIn.c_str())) != NULL) {

			while ((inputDirectory = readdir(directory)) != NULL) {// reads the files in the directory and puts them into the dirent struct (inputDirectory)

				fileName = dirIn + "\\" + inputDirectory->d_name;//concatenates directory path to the file name 
				dirFiles.push_back(fileName);//adds the file paths to the vector(dirFiles)
				fileObjects.push_back(PlagiarismFile(fileName));//adds a new PlagiarismFile object to the vector(fileObjects) with its file name

			}

			closedir(directory);

			dirFiles.erase(dirFiles.begin(), dirFiles.begin() + 2);//removes the . and .. added to the vector(dirFiles) by dirent
			fileObjects.erase(fileObjects.begin(), fileObjects.begin() + 2);
		}
		else {// could not open directory 
			//perror(" ");
			cout << "No such file or directory\n" << endl;
			validDir = false;
		}

	return validDir;
}

//vector<string> PlagiarismDetector::getDirFiles()//adds directory files to a vector(dirFiles) and creates PlagiariamFile objects and adds them to vector(fileObjects)
//{
//
//	cout << "Please enter a directory " << endl;
//	cin >> dirIn;
//	cout << "\n" << endl;
//
//	DIR *directory;//pointer to directory
//	struct dirent *inputDirectory;//dirent struct object
//
//	if ((directory = opendir(dirIn.c_str())) != NULL) {
//
//		while ((inputDirectory = readdir(directory)) != NULL) {// reads the files in the directory and puts them into the dirent struct (inputDirectory)
//
//			fileName = dirIn + "\\" + inputDirectory->d_name;//concatenates directory path to the file name 
//			dirFiles.push_back(fileName);//adds the file paths to the vector(dirFiles)
//			fileObjects.push_back(PlagiarismFile(fileName));//adds a new PlagiarismFile object to the vector(fileObjects) with its file name
//
//		}
//
//		closedir(directory);
//
//		dirFiles.erase(dirFiles.begin(), dirFiles.begin() + 2);//removes the . and .. added to the vector(dirFiles) by dirent
//		fileObjects.erase(fileObjects.begin(), fileObjects.begin() + 2);
//	}
//	else {// could not open directory 
//		  //perror(" ");
//		cout << "no such directory" << endl;
//	}
//	return dirFiles;
//
//}

void PlagiarismDetector::clearVectors() {// clears all vectors in PlagiarismDector class

	dirFiles.clear();
	fileObjects.clear();
}

void PlagiarismDetector::controlStatementCheck()//checks for if, switch, for and while statements
{
	int  numIf = 0, numSwitch = 0, numFor = 0, numWhile = 0, numLines = 0;

	for (size_t i = 0; i < dirFiles.size(); i++) {

		inputStream.open(dirFiles.at(i));

		if (!inputStream) {
			cout << "unable to find file\n";
		}
		else {

			//while (inputStream >> input) {
			while (getline(inputStream, input)) {

				++numLines;
				//cout << input << endl;

				if (input.find("if") != std::string::npos) {
					numIf++;
				}

				if (input.find("switch") != std::string::npos) {
					numSwitch++;
				}

				if (input.find("for") != std::string::npos) {
					numFor++;
				}

				if (input.find("while") != std::string::npos) {
					numWhile++;
				}

			}

			fileObjects[i].setNumIf(numIf);
			fileObjects[i].setnNumSwitch(numSwitch);
			fileObjects[i].setNumFor(numFor);
			fileObjects[i].setNumWhile(numWhile);
			fileObjects[i].setNumLines(numLines);
		}


		numIf = 0;
		numSwitch = 0;
		numFor = 0;
		numWhile = 0;
		numLines = 0;
		inputStream.close();
	}
	
}

void PlagiarismDetector::characterCheck()//Checks if characters are white spaces, digits, alphabethical or punctuations
{
	int charCount = 0, whiteSpaces = 0, numOfNums = 0, numOfAlpa = 0, numOfPunct = 0;

	for (size_t i = 0; i < dirFiles.size(); i++) {

		inputStream.open(dirFiles.at(i));

		if (!inputStream) {
			cout << "unable to find file\n";
		}
		else {

			

				char c;
				while (inputStream.get(c))
				{
					charCount++;

					if (isspace(c) != 0) {
						whiteSpaces++;
					}
					if (isalpha(c) != 0) {
						numOfAlpa++;
					}
					if (isdigit(c)!= 0) {
						numOfNums++;
					}
					if (ispunct(c) != 0) {
						numOfPunct++;
					}
				}
		}
		
		inputStream.close();
		fileObjects[i].setCharCount(charCount);
		fileObjects[i].setWhiteSpaces(whiteSpaces);
		fileObjects[i].setNumOfNums(numOfNums);
		fileObjects[i].setNumOfAlpa(numOfAlpa);
		fileObjects[i].setNumOfPunct(numOfPunct);

		charCount = 0;
		whiteSpaces = 0;
		numOfAlpa = 0;
		numOfNums = 0;
		numOfPunct = 0;
	}
}

void PlagiarismDetector::displayFileInfo()//displays all info of each object in vector(fileObjects)
{
	for (size_t i = 0; i < fileObjects.size(); i++)
	{
		cout << "\nFile name: " << fileObjects[i].getDirFileName() << endl;
		cout << "Number of If Statements: " << fileObjects[i].getNumIf() << endl;
		cout << "Number of switch Statements: " << fileObjects[i].getnNumSwitch() << endl;
		cout << "Number of for Statements: " << fileObjects[i].getNumFor() << endl;
		cout << "Number of while Statements: " << fileObjects[i].getNumWhile() << endl;
		cout << "Number of white Spaces: " << fileObjects[i].getWhiteSpaces() << endl;
		cout << "Number of alphabethical characters: " << fileObjects[i].getNumOfAlpa() << endl;
		cout << "Number of numbers characters: " << fileObjects[i].getNumOfNums() << endl;
		cout << "Number of punctuations: " << fileObjects[i].getNumOfPunct() << endl;
		cout << "Number of Lines of code: " << fileObjects[i].getNumLines() << endl;
		cout << "Character count: " << fileObjects[i].getCharCount() << "\n" << endl;
	}
}

//void PlagiarismDetector::plagiarismCheck(vector<string> dirFiles)//calls on all PlagiarismDetector class detection methods to run full check
//{
//		controlStatementCheck();
//		characterCheck();
//		displayFileInfo();
//}

void PlagiarismDetector::plagiarismCheck()//calls on all class PlagiarismDetector detection methods to run full check
{
	char loop = 'y';
	while (loop == 'y' || loop == 'Y') {

		if (getDirFiles()) {
			
			controlStatementCheck();
			characterCheck();
			displayFileInfo();
			
			loop = 'a';
		}
		 if (loop != 'y' || loop != 'Y') {
			
			cout << "Would you like to enter another directory? y/n" << endl;
			cin >> loop;
		}		
	}

}