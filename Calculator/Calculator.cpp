#include <iostream>
#include <string>
using namespace std;

class ArraySizeException
{
public:
    const char* what() const
    {
        return "Array size must be 4x4!";
    }
};

class ArrayDataException
{
private:
    string message;

public:
    ArrayDataException(int row, int column, string error)
    {
        message = "Invalid data at cell [" + to_string(row) + "][" + to_string(column) + "]. Error: " + error;
    }

    const char* what() const
    {
        return message.c_str();
    }
};

class ArrayValueCalculator
{
public:
    int doCalc(string arr[4][4])
    {
        int sum = 0;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                try
                {
                    sum += stoi(arr[i][j]);
                }
                catch (...)
                {
                    throw ArrayDataException(i, j, "Cannot convert string to int");
                }
            }
        }
        return sum;
    }
};

int main()
{
    string arr[4][4] =
    {
        {"1", "2", "3", "4"},
        {"5", "6", "7", "8"},
        {"9", "10", "11", "12"},
        {"13", "14", "15", "16"}
    };

    try
    {
        ArrayValueCalculator calculator;

        int result = calculator.doCalc(arr);

        cout << "Sum: " << result << endl;
    }
    catch (ArrayDataException& e)
    {
        cout << e.what() << endl;
    }
    catch (ArraySizeException& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}

