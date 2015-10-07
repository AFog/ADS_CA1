#pragma once
#include <vector>
#include <fstream>
#include <dirent.h>
#include "PlagiarismFile.h"
using namespace std;

class PlagiarismDetector
{
private:

	vector<string> dirFiles;
	vector<PlagiarismFile> fileObjects;
	string dirIn, fileName,input, fileChoice;
	ifstream inputStream;

public:

	PlagiarismDetector();
	~PlagiarismDetector();
	bool getDirFiles();
	//vector<string> getDirFiles();
	void clearVectors();
	void controlStatementCheck();
	void characterCheck();
	void displayFileInfo();
	void plagiarismCheck();
	//void plagiarismCheck(vector<string> dirFiles);

};