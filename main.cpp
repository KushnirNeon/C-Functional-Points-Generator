//g++ compiler

#include <iostream>
#include <fstream>
#include <vector>
#include "FunctionalObject.h"

int main() 
{
    try 
    {
        ifstream inputFile ("input.txt");
        if (!inputFile)
        {
            throw runtime_error ("Unable to open input file");
        }

        int n;
        pair <double, double> x0;
        vector <pair <double, double>> basePoints;

        if (!(inputFile >> n) || (n <= 0)) 
        {
            throw runtime_error ("Incorrect number of points");
        }

        if (!(inputFile >> x0.first >> x0.second)) 
        {
            throw runtime_error ("Incorrect starting point coordinates");
        }

        double x, y;
        while (inputFile >> x >> y) 
        {
            if (inputFile.fail())
            {
                throw runtime_error("Problems with base point coordinates");
            }
            basePoints.push_back(make_pair(x, y));
        }

        inputFile.close();

        if (basePoints.empty()) 
        {
            throw runtime_error ("Problems with base point coordinates");
        }

        ofstream outputFile ("output.txt", ios::out);
        if (!outputFile) 
        {
            throw runtime_error ("Unable to open output file");
        }

        outputFile << x0.first << " " << x0.second;
        if (n > 1)
        {
            outputFile << endl;
            FunctionalObject functionalObject (x0, basePoints);
            for (int i = 0; i < n - 1; i++)
            {
                pair <double, double> point = functionalObject();
                outputFile << point.first << " " << point.second;
                if (i != n - 2)
                {
                    outputFile << endl;
                }
            }
        }

        outputFile.close();
    } 
    catch (const runtime_error & e) 
    {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
