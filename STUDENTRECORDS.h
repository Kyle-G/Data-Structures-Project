#ifndef STUDENTRECORDS_H_INCLUDED
#define STUDENTRECORDS_H_INCLUDED
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class STUDENTRECORDS
{
private:

    string name;
    string address;
    string id;
    double GPA;
    int *testScore;

    int num;
    int size;

public:
    STUDENTRECORDS()
    {
        size = 10;
        testScore = new int [size];
    }

    void setName (string n)
    {
        name = n;
    }

    void setAddress (string a)
    {
        address = a;
    }

    void setID (string i)
    {
        id = i;
    }

    void setGPA (double gp)
    {
        GPA = gp;
    }

    void setTestScore (int index, int score)
    {
        testScore[index] = score;
    }

    string getName() const
    {
        return name;
    }

    string getAddress() const
    {
        return address;
    }

    string getID() const
    {
        return id;
    }

    double getGPA() const
    {
        return GPA;
    }

    int *getTestScore() const
    {
        return testScore;
    }


    void Display()
    {
        cout << name << " / ";
        cout << address << " / ";
        cout << id << " / ";
        cout << GPA;
        cout << endl;
    }

};




#endif // STUDENTRECORDS_H_INCLUDED
