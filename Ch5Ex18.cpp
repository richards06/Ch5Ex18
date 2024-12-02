/*
Program Title: Chapter5Ex18
Programmer: Josh Richards
Date: December 2, 2024
Requirements:

Write a program that produces a bar chart showing the population growth of Prairieville, a small town in the Midwest,
at 20-year intervals during the past 100 years.

The program should read in the population figures (rounded to the nearest 1,000 people) for 1900, 1920, 1940, 1960, 1980, and 2000 from a file.
For each year, it should display the date and a bar consisting of one asterisk for each 1,000 people.
The data can be found in the People.txt file.

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool readPopulationData(const string& People, vector<int>& populationData);
void displayBarChart(const vector<int>& populationData, const vector<int>& years);

int main() {
    vector<int> years = { 1900, 1920, 1940, 1960, 1980, 2000 };
    vector<int> populationData;

    if (!readPopulationData("People.txt", populationData)) {
        cerr << "Error reading population data!" << endl;
        return 1;
    }

    cout << "PRAIRIEVILLE POPULATION GROWTH" << endl;
    cout << "(each * represents 1,000 people)" << endl << endl;

    displayBarChart(populationData, years);

    return 0;
}

bool readPopulationData(const string& People, vector<int>& populationData) {
    ifstream inputFile("People.txt");

    if (!inputFile) {
        return false;
    }

    int population;
    while (inputFile >> population) {
        populationData.push_back(population);
    }

    inputFile.close();
    return true;
}

void displayBarChart(const vector<int>& populationData, const vector<int>& years) {
    for (size_t i = 0; i < populationData.size(); ++i) {
        cout << years[i] << ": ";
        int numAsterisks = populationData[i] / 1000;
        for (int j = 0; j < numAsterisks; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}
