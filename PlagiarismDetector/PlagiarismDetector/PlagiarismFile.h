#pragma once
#include <string>
using namespace std;

class PlagiarismFile
{
private:
	int charCount = 0, numIf = 0, numSwitch = 0,
		numFor = 0, numWhile = 0, numLines = 0, whitespace = 0,
		numOfNums = 0, numOfAlpa =0, numOfPunct = 0;
	static int fileCount;
	string dirfileName;

public:
	PlagiarismFile();
	PlagiarismFile(string nameIn);
	PlagiarismFile(string nameIn, int charCountIn, int numIfIn, int numSwitchIn,
		int numForIn, int numWhileIn, int numLinesIn, int whiteSpaceIn, int numOfNums,
		int numOfAlpaIn, int numOfPunct);

	~PlagiarismFile();
	string getDirFileName()const;
	int getCharCount()const;
	int getNumIf()const;
	int getnNumSwitch() const;
	int getNumFor() const;
	int getNumWhile() const;
	int getNumLines() const;
	int getWhiteSpaces() const;
	int getNumOfNums() const;
	int getNumOfAlpa() const;
	int getNumOfPunct() const;
	static int getfileCount();
	void setCharCount(int charCounttIn);
	void setNumIf(int numIfIn);
	void setnNumSwitch(int numSwitchIn);
	void setNumFor(int numForIn);
	void setNumWhile(int numWhileIn);
	void setNumLines(int numLinesIn);
	void setWhiteSpaces(int whiteSpaceIn);
	void setNumOfNums(int numOfNumsIn);
	void setNumOfAlpa(int numOfAlpaIn);
	void setNumOfPunct(int numOfPunctIn);
};