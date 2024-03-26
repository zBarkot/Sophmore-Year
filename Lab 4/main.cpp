//Barkot
//Akash
//jason
//marquez
#include <iostream>
#include <string>

using namespace std;


// ***** Add your Date class definition and driver program at the end of this file
// (at about line 107). *****

// The Month class provided below is a "helper" class for your Date class.
// Note that although both classes are defined in this single compilation unit (file),
// we are not nesting the Month class in the Date class or vice versa.

class Month {
  friend class Date;

  friend ostream& operator<< (ostream&, Month);

  private:
    enum EMonth { Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

    Month() : _month(Jan) {} // default constructor
    Month(int im) : _month( static_cast<EMonth>(im) ) {} // value constructor

    void setMonth(string m) { _month = StringToEMonth(m); } // mutator functions
    void setMonth(int im) { _month = static_cast<EMonth>(im); }

    /* Private helper member functions */
    EMonth StringToEMonth(string);
    int MonthToInt() { return static_cast<int>(_month); }
    string MonthToString();
    string MonthToString2();

      EMonth _month;
};

/* Definitions of helper member functions for class Month */

Month::EMonth Month::StringToEMonth(string m) {
  if (m == "Jan") return Jan;
  else if (m == "Feb") return Feb;
  else if (m == "Mar") return Mar;
  else if (m == "Apr") return Apr;
  else if (m == "May") return May;
  else if (m == "Jun") return Jun;
  else if (m == "Jul") return Jul;
  else if (m == "Aug") return Aug;
  else if (m == "Sep") return Sep;
  else if (m == "Oct") return Oct;
  else if (m == "Nov") return Nov;
  else if (m == "Dec") return Dec;
  else {
    cerr << "Month::StringToMonth: Invalid input month \"" << m << "\"\n";
    exit(1);
  }
}

string Month::MonthToString() {
  switch (_month) {
    case Jan: return "Jan";
    case Feb: return "Feb";
    case Mar: return "Mar";
    case Apr: return "Apr";
    case May: return "May";
    case Jun: return "Jun";
    case Jul: return "Jul";
    case Aug: return "Aug";
    case Sep: return "Sep";
    case Oct: return "Oct";
    case Nov: return "Nov";
    case Dec: return "Dec";
    default:
      cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
      exit(1);
  }
}

string Month::MonthToString2() {
  switch (_month) {
    case Jan: return "January";
    case Feb: return "February";
    case Mar: return "March";
    case Apr: return "April";
    case May: return "May";
    case Jun: return "June";
    case Jul: return "July";
    case Aug: return "August";
    case Sep: return "September";
    case Oct: return "October";
    case Nov: return "November";
    case Dec: return "December";
    default:
      cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
      exit(1);
  }
}

/* Definition of friend function operator<< */

ostream& operator<< (ostream& out, Month m) {
  out << m.MonthToString2();
  return out;
}


// ***** Add your Date class definition and driver program below. *****
class Date{

public:
    Date();
    Date(int month, int iday, int iyear);
    Date(string imonth, int iday, int iyear);

    void changeMonth(int month);
    void outputDateAsInt(ostream&);
    void outputDateAsString(ostream&);

    friend ostream &operator<<(ostream &out, const Date &day);
    friend Date &operator++(Date &day);

private:
    Month month;
    int day;
    int year;
};

//a default constructor that sets the Date to the internal representation for January 1, 2018;
Date::Date() {
    month.setMonth(1);
    day = 1;
    year = 2018;
}
//a value constructor to set the Date, using an integer parameter to represent the month value (e.g.,12 for December);
Date::Date(int imonth, int iday, int iyear) {
    month.setMonth(imonth);
    day = iday;
    year = iyear;
}
//another value constructor to set the Date, using a string parameter containing the first three letters in the name of the month to represent the month value (e.g., “Dec” for December);
Date::Date(string imonth, int iday, int iyear) {
    month.setMonth(imonth);
    day = iday;
    year = iyear;
}
//a mutator member function that will change the value of the month in a Date, given a valid month value as an integer;
void Date::changeMonth(int imonth){
    month.setMonth(imonth);
}
//a member function outputDateAsInt(ostream&) that writes the Datbe to an output stream
//passed as an argument to the function, representing the month using an integer (e.g.,
//“12/31/2018”);
void Date::outputDateAsInt(ostream& out){
  out << month.MonthToInt() << "/" << day << "/" << year << endl;
}
//a member function outputDateAsString(ostream&)that writes the Date to an output
//stream passed as an argument to the function, representing the month using the first three letters in
//the name of the month (e.g., “Dec 31, 2018”);
void Date::outputDateAsString(ostream& out){
  out << month.MonthToString() << " " << day << ", "<< year << endl;
}
//an overloaded version of the insertion operator << (written as a non-member friend function) that
//writes the Date given as the right-hand operand of the insertion operator to the output stream given as the left-hand operand of the insertion operator, representing the date using the entire name of the month (e.g., “December 31, 2018”);
ostream &operator<<(ostream &out, const Date &day){
  out << day.month << " " << day.day << ", " << day.year;
  return out;
}
//an overloaded version of the pre-increment operator ++ (written as a member function) that retains the same month and day of month as the current Date, but increments the year number.
Date &operator++(Date &year){
  ++(year.day);
  return year;
}

int main() {
    Date d1, d2(2, 1, 2018), d3("Mar", 1, 2018);

    cout << "With the following declarations:" << endl;
    cout << "d1 == " << d1 << std::endl;
    cout << "d2 == " << d2 << std::endl;
    cout << "d3 == " << d3 << std::endl;

    d3.changeMonth(4);
    cout << "After d3.changeMonth(4):" << endl;
    cout << "d3 == " << d3 << endl;

    Date d4(12, 31, 2018);
    cout << "With the following declaration:" << std::endl;
    std::cout << "d4.outputDateAsInt(cout) outputs ";
    d4.outputDateAsInt(std::cout);
    cout << std::endl;
    cout << "d4.outputDateAsString(cout) outputs ";
    d4.outputDateAsString(std::cout);
    cout << std::endl;

    ++d4;
    std::cout << "++d4 == " << d4 << std::endl;

    return 0;
}