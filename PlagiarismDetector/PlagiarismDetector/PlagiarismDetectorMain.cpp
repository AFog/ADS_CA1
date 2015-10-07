//http://softagalleria.net/dirent.php

#include "PlagiarismDetector.h"
#include <iostream>
using namespace std;

using namespace std;

int main() {

	//char loop = 'y';
	//PlagiarismDetector p;

	//while (loop == 'y' || loop == 'Y') {
	//	
	//	//p.plagiarismCheck();
	//	p.plagiarismCheck(p.getDirFiles());
	//	cout << "Would you like to enter another directory? y/n" << endl;
	//	
	//	cin >> loop;
	//}
	
	PlagiarismDetector p;
	p.plagiarismCheck();

	system("pause");
	return 0;
}