#include <iostream>
#include <fstream>
#include "STUDENTRECORDS.h"
#include <vector>
#include <iomanip>
using namespace std;

void showValues(vector<STUDENTRECORDS>);
void quickSort(vector<STUDENTRECORDS>&, int, int);
int partition(vector<STUDENTRECORDS>&, int, int);
void swap(vector<STUDENTRECORDS> &, int &);

int main()
{
    ifstream fin;
    fin.open("StudentInfo.txt");

    STUDENTRECORDS linkList;
    STUDENTRECORDS h;
    string hName;
    string hAddress;
    string hID;
    int hTestScore;
    double hGPA;

    vector<STUDENTRECORDS> records;

    cout << "Student Records in the Unsorted Vector (Name / Address / ID / GPA:" << endl;

    for(int i = 0; i < 15; i++)
    {
        double total = 0;

        getline(fin, hName);
        linkList.setName(hName);

        getline(fin, hAddress);
        linkList.setAddress(hAddress);

        getline(fin, hID);
        linkList.setID(hID);

        for(int a = 0; a < 10; a++)
        {
            fin >> hTestScore;
            linkList.setTestScore(a, hTestScore);
            total += hTestScore;

        }
        hGPA = total/10.0;

        linkList.setGPA(hGPA);

        records.push_back(linkList);


        fin.ignore();
    }

    showValues(records);
    cout << endl << endl;

    quickSort(records, 0, records.size()-1);

    cout << "Student Records in the Sorted Vector (Name / Address / ID / GPA:" << endl;
    for (int count = 0; count < records.size(); count++)
        {
            records[count].Display();
        }


    fin.close();
    return 0;
}

void showValues(vector<STUDENTRECORDS> vect)
{
    for (int count = 0; count < vect.size(); count++)
    {
        vect[count].Display();
    }
}

void quickSort (vector<STUDENTRECORDS>& vect, int start, int end)
{
    int pivotPoint;

    if (start < end)
    {
        pivotPoint = partition(vect, start, end);
        quickSort(vect, start, pivotPoint -1);
        quickSort(vect, pivotPoint + 1, end);
    }
}

int partition(vector<STUDENTRECORDS>& vect, int start, int end)
{
    double pivotValue;
    int pivotIndex, mid;

    mid = (start + end) / 2;
    swap(vect[start], vect[mid]);

    pivotIndex = start;
    pivotValue = vect[start].getGPA();

    for(int scan = start+1; scan <= end; scan++)
    {
        if(vect[scan].getGPA() < pivotValue)
        {
            pivotIndex++;
                swap(vect[pivotIndex], vect[scan]);
        }
    }
    swap(vect[start], vect[pivotIndex]);
    return pivotIndex;
}

void swap(vector<STUDENTRECORDS> &value1, vector<STUDENTRECORDS> &value2)
{
    vector<STUDENTRECORDS> temp = value1;
    value1 = value2;
    value2 = temp;
}
