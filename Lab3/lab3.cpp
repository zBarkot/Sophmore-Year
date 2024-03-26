//Barkot Zeyohannes
//Aksh Patel 
//Jason Osai
//Marquzes Ford Jr

#include <iostream>
#include <cstdlib>

using namespace std;

class Mass
{
public:
    // setter functions
    void setMassAvoirdupoisPounds(double mass);
    void setMassTroyPounds(double mass);
    void setMassMetricGrams(double mass);

    double massAvoirdupoisGetter(void);
    double massTroyGetter(void);
    double massMetricGetter(void);

private:
    double massInDrams;
};

double Mass::massAvoirdupoisGetter(void)
{ // gets mass in drams and return mass is Avoirdupois
    return massInDrams * 256;
}
double Mass::massTroyGetter(void)
{ // get mass in drams and return mass is Troy
    return massInDrams * 96;
}
double Mass::massMetricGetter(void)
{ // gets mass in drams and return in grams
    return massInDrams / 1.7718451953125;
}

void Mass::setMassAvoirdupoisPounds(double mass)
{ // converts Avoirdupois to drams and stores it in private members variable massInDrams
    massInDrams = mass / 256;
}
void Mass::setMassMetricGrams(double mass)
{ // converts grams to drams and stores it in private members variable massInDrams
    massInDrams = mass * 1.7718451953125;
}
void Mass::setMassTroyPounds(double mass)
{ // converts Troy to drams and stores it in private members variable massInDramss
    massInDrams = mass / 96;
}
int main(void)
{

    Mass weight;
    int num;
    double mass;
    cout << "Please enter 1 to use Avoirdupois pouunds, 2 to use Troy pounds, 3 to use grams, or 0 to exit" << endl;
    cin >> num;

    switch (num)
    {
    case 0: //The user would like to exit the program

        exit(1);

    case 1: //the case in which the user would like to input mass in Avordioups
        cout << "Please enter a mass in Avoirdupois pounds: " << endl;
        cin >> mass;
        weight.setMassAvoirdupoisPounds(mass);
        cout << "Mass in Avoirdupois is " << mass << endl;
        cout << "Mass in troy pounds is " << weight.massTroyGetter() << endl;
        cout << "Mass in grams is " << weight.massMetricGetter() << endl;

        break;

    case 2: // The case in which one chooses to input mass in the troy 
        cout << "Please enter a mass in Troy pounds: " << endl;
        cin >> mass;
        weight.setMassTroyPounds(mass);
        cout << "Mass in Avoirdupois is " << weight.massAvoirdupoisGetter() << endl;
        cout << "Mass in troy pounds is " << mass << endl;
        cout << "Mass in grams is " << weight.massMetricGetter() << endl;

        break;

    case 3: // The case in which the user would like to input mass in grams

        cout << "Please enter a mass in grams " << endl;
        cin >> mass;
        weight.setMassMetricGrams(mass);
        cout << "Mass in Avoirdupois is " << weight.massAvoirdupoisGetter() << endl;
        cout << "Mass in troy pounds is " << weight.massTroyGetter() << endl;
        cout << "Mass in grams is " << mass << endl;
        break;

    default:
        cout << "faulty input exit code (1)"; // Took the short approach to input validation so I just take all irrogenous input and exit with error code
        exit(1);
    }

    return 0;
}