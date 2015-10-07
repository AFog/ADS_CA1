#include "PlagiarismFile.h"
#include <string>
using namespace std;

PlagiarismFile::PlagiarismFile()
{
	dirfileName = "";
	charCount = 0;
	numIf = 0;
	numSwitch = 0;
	numFor = 0;
	numWhile = 0;
	numLines = 0;
	whitespace = 0;
	fileCount++;
}

PlagiarismFile::PlagiarismFile(string nameIn)
{
	dirfileName = nameIn;
	fileCount++;
}

PlagiarismFile::PlagiarismFile(string nameIn, int charCountIn, int numIfIn, int numSwitchIn,
	int numForIn, int numWhileIn, int numLinesIn, int whiteSpaceIn, int numOfNums,
	int numOfAlpaIn, int numOfPunctIn)
{
	dirfileName = nameIn;
	charCount = charCountIn;
	numIf = numIfIn;
	numSwitch = numSwitchIn;
	numFor = numForIn;
	numWhile = numWhileIn;
	numLines = numLinesIn;
	whitespace = whiteSpaceIn;
	numOfPunct = numOfPunctIn;
	fileCount++;
}

string PlagiarismFile::getDirFileName() const
{
	return dirfileName;
}

int PlagiarismFile::getCharCount() const
{
	return charCount;
}

int PlagiarismFile::getNumIf() const
{
	return numIf;
}

int PlagiarismFile::getnNumSwitch() const
{
	return numSwitch;
}

int PlagiarismFile::getNumFor() const
{
	return numFor;
}

int PlagiarismFile::getNumWhile() const
{
	return numWhile;
}

int PlagiarismFile::getNumLines() const
{
	return numLines;
}

int PlagiarismFile::getWhiteSpaces() const
{
	return whitespace;
}

int PlagiarismFile::getNumOfNums() const
{
	return numOfNums;
}

int PlagiarismFile::getNumOfAlpa() const
{
	return numOfAlpa;
}

int PlagiarismFile::getNumOfPunct() const
{
	return numOfPunct;
}

int PlagiarismFile::getfileCount()
{
	return fileCount;
}

void PlagiarismFile::setCharCount(int charCountIn) {
	charCount = charCountIn;
}
void PlagiarismFile::setNumIf(int numIfIn)
{
	numIf = numIfIn;
}
void PlagiarismFile::setnNumSwitch(int numSwitchIn)
{
	numSwitch = numSwitchIn;
}
void PlagiarismFile::setNumFor(int numForIn)
{
	numFor = numForIn;
}
void PlagiarismFile::setNumWhile(int numWhileIn)
{
	numWhile = numWhileIn;
}
void PlagiarismFile::setNumLines(int numLinesIn)
{
	numLines = numLinesIn;
}
void PlagiarismFile::setWhiteSpaces(int whiteSpaceIn)
{
	whitespace = whiteSpaceIn;
}
void PlagiarismFile::setNumOfNums(int numOfNumsIn)
{
	numOfNums = numOfNumsIn;
}
void PlagiarismFile::setNumOfAlpa(int numOfAlpaIn)
{
	numOfAlpa = numOfAlpaIn;
}
void PlagiarismFile::setNumOfPunct(int numOfPunctIn)
{
	numOfPunct = numOfPunctIn;
}
PlagiarismFile::~PlagiarismFile()
{
	//fileCount--;
}
int PlagiarismFile::fileCount = 0;