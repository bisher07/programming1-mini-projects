/*
-----------Annual Sales Report ---------

ID      QT1       QT2     QT3     QT4     Total
12345   1892.00   0.00    494.00  322.00  2708.00
32214   343.00    892.00  9023.00 0.00    10258.00
23422   1395.00   1901.00 0.00    0.00    3296.00
57373   893.00    892.00  8834.00 0.00    10619.00
35864   2882.00   1221.00 0.00    1223.00 5326.00
54654   893.00    0.00    392.00  3420.00 4705.00
Total   8298.00   4906.00 18743.0 4965.00

Max Sale by SalesPerson: ID = 57373, Amount = $10619.00
Max Sale by Quarter: Quarter = 3, Amount = $18743.00

In this report, QT1 stands for quarter 1 (months 1 to 3), QT2 for quarter 2 (months
4 to 6), QT3 for quarter 3 (months 7 to 9), and QT4 for quarter 4 (months 10 to 12).
The salespeople’s IDs are stored in one file; the sales data is stored in another file.
The sales data is in the following form:
salesPersonID month saleAmount
.
.
.
Furthermore, the sales data is in no particular order; it is not ordered by ID.
A sample sales data is:
12345 1 893
32214 1 343
23422 3 903
57373 2 893
.
.
.

Let us write a program that produces the output in the specified format.

Input:
One file containing each salesperson’s ID and a second file containing
the sales data.

Output:
A file containing the annual sales report in the above format.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int no_Of_Sales_Person = 6;

enum quarters
{
    QT1 = 0,
    QT2 = 1,
    QT3 = 2,
    QT4 = 3
};

struct SalesPersonRecord
{
    string ID;

    double saleByQuarter[4] = {0.0, 0.0, 0.0, 0.0};

    double totalAmount = 0.0;

    void printRow(ofstream &outFile)
    {
        outFile << setw(7) << left << ID << setw(10) << left << saleByQuarter[QT1] << setw(10) << left << saleByQuarter[QT2] << setw(10) << left
                << saleByQuarter[QT3] << setw(10) << left << saleByQuarter[QT4] << setw(10) << left << totalAmount << endl;
    }
};

void init(ifstream &inID, SalesPersonRecord list[], int listSize, double salesByQuarter[]);
void getData(ifstream &inData, SalesPersonRecord list[], int listSize);
void totalSalesByQuarter(ofstream &outFile, SalesPersonRecord list[], int listsize, double salesByQuarter[]);
void maxSaleBySalePerson(ofstream &outFile, SalesPersonRecord list[], int listSize);
void maxSaleByQuarter(ofstream &outFile, double salesByQuarter[]);

int main()
{
    SalesPersonRecord list[no_Of_Sales_Person];
    double salesByQuarter[4];
    ifstream inFile;
    ofstream outFile;

    inFile.open("ID.txt");

    init(inFile, list, no_Of_Sales_Person, salesByQuarter);

    inFile.close();
    inFile.clear();
    inFile.open("Data.txt");
    outFile.open("Data Table.txt");
    outFile << showpoint << fixed << setprecision(2);

    getData(inFile, list, no_Of_Sales_Person);

    outFile << "-----------Annual Sales Report ---------" << endl
            << endl;
    outFile << setw(7) << left << "ID" << setw(10) << left << "QT1" << setw(10) << left << "QT2" << setw(10) << left << "QT3" << setw(10) << left << "QT4" << setw(10) << left
            << "Total" << endl;

    for (int i = 0; i < no_Of_Sales_Person; i++)
    {
        list[i].printRow(outFile);
    }

    totalSalesByQuarter(outFile, list, no_Of_Sales_Person, salesByQuarter);
    maxSaleBySalePerson(outFile, list, no_Of_Sales_Person);
    maxSaleByQuarter(outFile, salesByQuarter);

    inFile.close();
    outFile.close();

    return 0;
}

void init(ifstream &inID, SalesPersonRecord list[], int listSize, double salesByQuarter[])
{
    for (int i = 0; i < listSize; i++)
    {
        inID >> list[i].ID;
    }

    for (quarters quarter = QT1; quarter <= QT4; quarter = static_cast<quarters>(quarter + 1))
    {
        salesByQuarter[quarter] = 0.0;
    }
}

void getData(ifstream &inData, SalesPersonRecord list[], int listSize)
{
    string SalePersonID;
    int month;
    double amount;
    int index;

    while (inData >> SalePersonID)
    {
        index = -1;

        inData >> month >> amount;

        for (int i = 0; i < listSize; i++)
        {
            if (list[i].ID == SalePersonID)
            {
                index = i;
                break;
            }
        }

        if (index >= 0 && index < listSize)
        {
            if (month >= 1 && month <= 3 && amount >= 0)
            {
                list[index].saleByQuarter[QT1] += amount;
                list[index].totalAmount += amount;
            }
            else if (month > 3 && month <= 6 && amount >= 0)
            {
                list[index].saleByQuarter[QT2] += amount;
                list[index].totalAmount += amount;
            }
            else if (month > 6 && month <= 9 && amount >= 0)
            {
                list[index].saleByQuarter[QT3] += amount;
                list[index].totalAmount += amount;
            }
            else if (month > 9 && month <= 12 && amount >= 0)
            {
                list[index].saleByQuarter[QT4] += amount;
                list[index].totalAmount += amount;
            }
            else
                cout << "Invalid month/amount." << endl;
        }
        else
            cout << "Invalid salesperson's ID." << endl;
    }
}

void totalSalesByQuarter(ofstream &outFile, SalesPersonRecord list[], int listsize, double salesByQuarter[])
{
    for (int i = 0; i < listsize; i++)
    {
        for (quarters quarter = QT1; quarter <= QT4; quarter = static_cast<quarters>(quarter + 1))
        {
            salesByQuarter[quarter] += list[i].saleByQuarter[quarter];
        }
    }

    outFile << setw(7) << left << "Total  " << setw(10) << left << salesByQuarter[QT1] << setw(10) << left
            << salesByQuarter[QT2] << setw(10) << left << salesByQuarter[QT3]
            << setw(10) << left << salesByQuarter[QT4] << endl
            << endl;
}

void maxSaleBySalePerson(ofstream &outFile, SalesPersonRecord list[], int listSize)
{
    string ID = list[0].ID;
    double maxSaleByPerson = list[0].totalAmount;

    for (int i = 0; i < listSize - 1; i++)
    {
        if (list[i + 1].totalAmount > maxSaleByPerson)
        {
            maxSaleByPerson = list[i + 1].totalAmount;
            ID = list[i + 1].ID;
        }
    }

    outFile << "Max Sale by SalesPerson: ID = " << ID << " , Amount = AED" << maxSaleByPerson << endl;
}

void maxSaleByQuarter(ofstream &outFile, double salesByQuarter[])
{
    double maxSaleByQuarter = salesByQuarter[QT1];
    int index = QT1;

    for (quarters quarter = QT2; quarter <= QT4; quarter = static_cast<quarters>(quarter + 1))
    {
        if (salesByQuarter[quarter] > maxSaleByQuarter)
        {
            maxSaleByQuarter = salesByQuarter[quarter];
            index = quarter;
        }
    }

    outFile << "Max Sale by Quarter: Quarter = " << index + 1 << " , Amount = AED" << maxSaleByQuarter << endl;
}
