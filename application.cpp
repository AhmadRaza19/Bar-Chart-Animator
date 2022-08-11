// Ahmad Raza
// CS 251
// Project 3 - Animated Bar Chart

// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// Shanon Reckinger
// U. of Illinois, Chicago
// CS 251: Fall 2021
//

// The Creative Component for this project allows the user to type in a custom amount of time they would like each iteration to be AND allows the user to pause at a frame of their choice for however long they desire. The program will also ask the user which file they would like to use, how many bars they would like to see, and how many iterations they would like. It then proceeds to ask them how long they would like each iteration to be, also giving the default time at the bottom. Finally, it asks where the user would like to pause, if at all. It will throw an error if the numbers are out of bounds.

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;


int main() {
	string filename;
	cout << BLACK << "Please enter the filename you wish to use: " << endl;
	cin >> filename;
	
	ifstream file;
	file.open(filename);
	while (!file.is_open()) {
	    cout << BLACK << "Not a valid filename! Please try again: " << endl;
	    cin >> filename;
	    file.open(filename);
	}
	string title;
	getline(file, title);
	string xlabel;
	getline(file, xlabel);
	string source;
	getline(file, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!file.eof()) {
		bca.addFrame(file);
	}
	
	cout << BLACK << "Please enter how many bars you wish to see (top _ bars): " << endl;
	int top, iter;
	cin >> top;
	cout << BLACK << "Please enter how many iterations you wish to see (type -1 for all iterations): " << endl;
	cin >> iter;
	
	cout << BLACK << "Please enter how long you would like to pause for in between each iteration." << endl;
	cout << BLACK << "If you would like to type in microseconds, type 'a' followed by the amount." << endl;
	cout << BLACK << "If you would like to type in milliseconds, type 'b' followed by the amount." << endl;
	cout << BLACK << "If you would like to type in seconds, type 'c' followed by the amount." << endl;
	cout << BLACK << "example: a 100000 (100,000 microseconds)" << endl;
	cout << BLACK << "type 'a 150000' for the default time" << endl;
	int tme;
	char choice;
	cin >> choice >> tme;
	switch (choice) {
	    case 'a': tme = tme; break;
	    case 'b': tme = tme * 1000; break;
	    case 'c': tme = tme * 1000000; break;
	}
	cout << BLACK << "Please type which frame number you would like to pause at (0 for no frame): " << endl;
	int frameP;
	int tmeP;
	cin >> frameP;
	
	if (frameP > 0) {
	    cout << BLACK << "Please type how long you would like to pause for (in seconds): " << endl;
	    cin >> tmeP;
	}
	
	if (frameP < 0 || tme < 1 || tmeP < 1) {
	    throw out_of_range("Iteration time or Pause time was out of bounds, exiting");
	}
	
	bca.animate(cout, top, iter, tme, frameP, tmeP);
    
    file.close();
    return 0;
}
