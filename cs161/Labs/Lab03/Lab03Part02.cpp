//Programmed by: Adam La Fleur
//Sources: None

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	double score1, score2, score3, score4, score5;
	double avgScore;
	ifstream dataFile;
	dataFile.open("Docs/Lab03ScoreData.txt");
	dataFile >> score1 >> score2 >> score3 >> score4 >> score5;
	dataFile.close();
	avgScore = (score1 + score2 + score3 + score4 + score5) / 5;
	cout << "The average test score of the five students is " << avgScore << "." << endl;
	ofstream outFile;
	outFile.open("Docs/Lab03AvgOutput.txt");
	outFile << "The average score for the 5 test scores is " << avgScore << "." << endl;
	outFile.close();
	//system("pause"); //Windows Only
	return 0;
}



