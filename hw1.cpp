#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ArgumentManager.h"
// Name: Othniel Udoh, Purpose: Practice recursion and using Linux Server, Date Started: 1/21/2020

void SD(string o[], int n, string b, int l, ofstream& Bib) {
	if (n == 1) {
		stringstream Lope;
		string hat;
		int indy = o[0].find(b.at(0));
		string nope;
		nope = o[0].substr(indy, b.size());
		bool match = true;
		for (int i = 0; i < b.length(); i++) {
			char a = nope.at(i);
			char d = b.at(i);
			char e = d - 32;
			char f = d + 32;
			if (!((a == d) || (a == e) || (a == f))) {
				match = false;
			}

		}
		if (match) {
			Lope << "Level " << l << ": " << o[0] << "}" << endl;
			getline(Lope, hat);
			cout << hat << endl;
			Bib << hat << endl;


		}

	}

	else {
		int li = 0, ri = 0;//Variables for the two new arrays mid

		string la[10], ra[10];//Left array and right array
		int count = 0;
		for (int i = 0; i < (n / 2); i++) {
			la[i] = o[i];
			li++;
			count++;
		}

		for (int i = 0; count < n; i++) {
			ra[i] = o[count];
			ri++;
			count++;
		}
		l++;



		SD(la, li, b, l, Bib);
		SD(ra, ri, b, l, Bib);

	}
}

int main(int argc, char* argv[]) {
	ArgumentManager am(argc, argv);
	string in = am.get("input");
	string com = am.get("command");
	string out = am.get("output");

	ifstream inFile, comFile;
	ofstream outFile;


	//inFile.open(in);
	inFile.open("input12.txt");
	//comFile.open(com);
	comFile.open("command12.txt");
	//outFile.open(out);
	outFile.open("output12.txt");

	//Need int n to keep track of number of lines in array
	int n = 0;
	//Need int l to keep track of level
	int l = 1;
	//Also need to store info in a string array
	string Nice[20];
	// Also need to keep track of number of line so we can clean up strings
	int count = 0;
	//Temporarily store strings and clean them up
	string Holder;
	while (getline(inFile, Holder, '}')) {
		int i = 0;
		string bat(Holder);
		i = Holder.find('{');
		int b = 0;
		for (i; i < bat.length(); i++) {
			if (Holder.at(i) != ' ') {
				bat.at(b) = Holder.at(i);
				b++;
			}
		}
		for (b; b < bat.length(); b++)
			bat.erase(b);

		Nice[n] = bat;
		n++;
	}
	n--;

	string Com;
	getline(comFile, Com);

	//Now that we have the string we can use SearchData tool
	SD(Nice, n, Com, l, outFile);
	outFile.close();
	inFile.close();
	comFile.close();

}

