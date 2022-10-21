// Temperature_Conversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

//Initialize constant input. 
int const MAX_INPUT = 10;

void showMenu();
int getOption();
void showCelsius(double tempurature);
void showKelvin(double tempurature);
void displayData(double arr[][MAX_INPUT], int row, int col);
void convert(double arr[][MAX_INPUT], int row, int col);
double convertCelsius(double tempurature);
double convertKelvin(double tempurature);

int main() {
    int count = 0;
    int option = 1;
    double tempurature;
    double table[3][MAX_INPUT];

    while (option != 4) {
        showMenu();
        option = getOption();
        if (option == 1) {
            // Check over 10 inputs
            if (count == MAX_INPUT) {
                cout << "Error. User already enter 10 temperature inputs" << endl << endl;
                continue;
            }
            cout << "Enter a Fahrenheit temperature: ";
            cin >> tempurature;
            showCelsius(tempurature);

        }
        else if (option == 2) {
            // Check over 10 inputs?
            if (count == MAX_INPUT) {
                cout << "Error. User already enter 10 temperature inputs" << endl << endl;
                continue;
            }
            cout << "Enter a Fahrenheit temperature: ";
            cin >> tempurature;
            showKelvin(tempurature);
            while (convertKelvin(tempurature) < 0) {
                cout << "Error! Kelvin tempurature cannot be negative. Please try again." << endl;
                cout << "Enter a Fahrenheit temperature: ";
                cin >> tempurature;
                showKelvin(tempurature);
            }
            // Store data into 2D array
            table[0][count] = tempurature;
            convert(table, 3, count);
            count++;
        }
        else if (option == 3) {
            displayData(table, 3, count);
        }
        else {
            cout << "Quit Program" << endl;
        }
        cout << endl;


    }


    return 0;
}

void showMenu() {
    /*
1.	Convert Fahrenheit to Celsius (Centigrade)
2.	Convert Fahrenheit to Kelvin
3.	Display Data
4.	Quit Program
    */
    cout << "Select one of the following options:" << endl;
    cout << "\t1. Convert Fahrenheit to Celsius (Centigrade) " << endl;
    cout << "\t2. Convert Fahrenheit to Kelvin " << endl;
    cout << "\t3. Display Data " << endl;
    cout << "\t4. Quit Program " << endl;
}

int getOption() {
    // Get valid option 1-> 4
    int opt;
    cout << "Enter your choice: ";
    cin >> opt;
    // Validate
    while (opt != 1 && opt != 2 && opt != 3 && opt != 4) {
        cout << "Invalid choice! Please try again (1-4)" << endl;
        cout << "Enter your choice: ";
        cin >> opt;
    }
    return opt;
}

void showCelsius(double tempurature) {
    double Celsius = 0;
    //Convert degrees Fahrenheit to Celsius degrees.
    Celsius = ((double)5 / 9) * (tempurature - 32);
    //Print out Celsius.
    cout << setprecision(1) << fixed;
    cout << "\t" << tempurature << " Fahrenheit = " << Celsius << " Celsius" << endl;

}

void showKelvin(double tempurature) {
    double K = 0;

    //Calculate Kevin interm of Fahrenheit.
    K = ((double)5 / 9) * (tempurature - 32) + 273.15;
    if (K >= 0) {
        //Print out Kevin.
        cout << "\t" << tempurature << " Fahrenheit = " << K << " Kelvin" << endl;
    }
}


void displayData(double arr[][MAX_INPUT], int row, int col) {
    cout << "Data Entered:" << endl;
    cout << setprecision(1) << fixed;
    for (int i = 0; i < row; i++) {
        cout << setw(12) << left;
        if (i == 0) {
            cout << "Farenheit: ";
        }
        else if (i == 1) {
            cout << "Celsius: ";
        }
        else {
            cout << "Kelvin: ";
        }

        for (int j = 0; j < col; j++) {
            cout << setw(6) << right << arr[i][j] << "   ";
        }
        cout << endl;
    }
}


double convertCelsius(double tempurature) {
    double Celsius = 0;
    //Convert degrees Fahrenheit to Celsius degrees.
    Celsius = ((double)5 / (double)9) * (tempurature - 32);
    //Print out Celsius.
    return Celsius;
}

double convertKelvin(double tempurature) {
    double K = 0;

    //Calculate Kevin interm of Fahrenheit.
    K = ((double)5 / (double)9) * (tempurature - 32) + 273.15;
    //Print out Kevin.
    return K;
}

void convert(double arr[][MAX_INPUT], int row, int col) {
    // Handle Celsius
    for (int j = 0; j <= col; j++) {
        // Take F degree -> double 
        double F = arr[0][j];
        // Call fucntion convet F to C
        double C = convertCelsius(F);
        // Store C into suitable position in arr
        arr[1][j] = C;
    }

    // Handle Kevin
    for (int j = 0; j <= col; j++) {
        // Take F degree -> double 
        double F = arr[0][j];
        //Call function convert F to K.
        double K = convertKelvin(F);
        // Store K into suitable position in arr
        arr[2][j] = K;
    }

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
