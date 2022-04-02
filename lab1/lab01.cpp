// lab01.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Charles Phu

#include <iostream>
#include <string>
using namespace std;

/* PSEUDOCODE
Algorithm IsArrayPrimeIter( arr[], size)
    Algorithm checks if there is a prime in the given array
    Pre: arr - non empty array of integer numbers
         size - actual size of array
    Post:
    Return: true or false

    print entering function
    loop(i < array size){
        loop(j < arr[i] / 2) {
            if (arr[i] is 2)
                continue
            else if ( arr[i] is 1)
                print Leaving function
                return false
            else if (arr[i] is divisble by 0)
                print Leaving function
                return false
            end if
            j = j + 1
        end loop
        i = i + 1
    end loop
end IsArrayPrimeIter
*/
bool IsArrayPrimeIter(int arr[], int size) {
    cout << "Entering IsArrayPrimeIter" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 2; j <= sqrt(arr[i]); j++) {
            if (arr[i] == 2) {
                continue;
            }
            else if (arr[i] == 1) {
                cout << "Leaving IsArrayPrimeIter" << endl;
                return false;
            }
            else if (arr[i] % j == 0) {
                cout << "Leaving IsArrayPrimeIter" << endl;
                return false;
            }
        }
    }
    cout << "Leaving IsArrayPrimeIter" << endl;
    return true;
};

/* PSEUDOCODE
Algorithm IsPrimeRecur(num, dividingNum)
    Algorithm checks if the given integer number is prime
    Pre: num - a given integer number
         dividing num - integer number to divide num with
    Post:
    Return: true or false

    print Entering function
    if (num = 2)
        print leaving function
        return true
    else if (num = 1)
        print leaving functino
        return false
    else if dividngNum is less than divingNum / 2
        if (num % 2 = 0)
            print leaving function
            return false
        else
            print leaving function
            return Algorithm IsPrimeRecur
        end if
    else
        print leaving function
        return true
    end if
end IsPrimeRecur
*/
bool IsPrimeRecur(int num, int dividingNum = 2) {
    cout << "Entering IsPrimeRecur" << endl;
    if (num == 2) {
        cout << "Leaving IsPrimeRecur" << endl;
        return true;
    }
    else if (num == 1) {
        cout << "Leaving IsPrimeRecur" << endl;
        return false;
    }
    else if (dividingNum <= sqrt(num)) {
        if (num % dividingNum == 0) {
            cout << "Leaving IsPrimeRecur" << endl;
            return false;
        }
        else {
            cout << "Leaving IsPrimeRecur" << endl;
            return IsPrimeRecur(num, dividingNum + 1);
        }
        
    }
    else {
        cout << "Leaving IsPrimeRecur" << endl;
        return true;
    }
};

/* PSEUDOCODE
Algorithm IsArrayPrimeRecur(arr[], size, startingpoint)
    Algorithm checks if there is any integer number is prime in arr
    Pre: arr - non-empty array of integer number
         size - actual size of array
         startingpoint - current index of array
    Post:
    Return: true or false

    print entering function
    if (starting point < size)
        if (Algorithm IsPrimeRecur(arr[startingPoint]) = true)
            print leaving function
            return Algorithm IsArrayPrimeRecur(arr, size, startingPoint + 1)
        else
            print leaving function
            return false
        end if
    end if
end IsArrayPrimeRecur
*/
bool IsArrayPrimeRecur(int arr[], int size, int startingPoint = 0) {
    cout << "Entering IsArrayPrimeRecur" << endl;
    if (startingPoint < size) {
        if (IsPrimeRecur(arr[startingPoint])) {
            cout << "Leaving IsArrayPrimeRecur" << endl;
            return IsArrayPrimeRecur(arr, size, startingPoint + 1);
        }
        else {
            cout << "Leaving IsArrayPrimeRecur" << endl;
            return false;
        }
    }
    else {
        cout << "Leaving IsArrayPrimeRecur" << endl;
        return true;
    }
    
};

int main()
{
    int NumInts, start =0;
    string stringOfNum, temp ="";

    cout << "Enter number of elements in array: ";
    cin >> NumInts;

    if (NumInts >= 16) {
        NumInts = 16;
    };
    int *arr = new int[NumInts];
    cout << "Enter all array elements seperated by spaces: ";

    cin.ignore(256, '\n');
    getline(cin, stringOfNum);

    // takes string and converts it into int numbers that are put into array
    for (int i = 0; i < stringOfNum.size(); i++) {
        if (stringOfNum[i] != ' ') {
            temp += stringOfNum[i];
        }
        else {
            arr[start] = stoi(temp);
            temp = "";
            start++;
        }
        if (i == stringOfNum.size() - 1) {
            arr[start] = stoi(temp);
        }
    }

    //Function calls and printing out if array is prime or not
    if (IsArrayPrimeIter(arr, NumInts)) {
        cout << "Prime Array using iteration" << endl;
    }
    else {
        cout << "Not a Prime Array using iteration" << endl;
    }

    if (IsArrayPrimeRecur(arr, NumInts)) {
        cout << "Prime Array using recursion" << endl;
    }
    else {
        cout << "Not a Prime Array using recursion" << endl;
    }


    delete[] arr;
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
