#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Fuction to convert any string into Sentence Case
string ToSentence (const string& s)
{
    string result = s;
    for (size_t i = 0; i < s.length (); i++)
    {
        if (i == 0) {
            result[i] = toupper(s[i]);
        }
        else{
            result [i] = tolower (s [i]);
        }
    }
    return result;
}

//Map of month number and month name
struct Month {
    unsigned monthNum;
    string monthName;
    unsigned maxDays;
    Month(unsigned monthNum_, string monthName_, unsigned maxDays_)
        :monthNum(monthNum_), monthName(monthName_), maxDays(maxDays_)
    {}
};

//fucntion to create a map of all months with their corresponding numbers
vector<Month> CreateMonthMap() {
    vector<Month> tempMap;

    tempMap.push_back(Month(1, "January", 31));
    tempMap.push_back(Month(2, "February", 28));
    tempMap.push_back(Month(3, "March", 31));
    tempMap.push_back(Month(4, "April", 30));
    tempMap.push_back(Month(5, "May", 31));
    tempMap.push_back(Month(6, "June", 30));
    tempMap.push_back(Month(7, "July", 31));
    tempMap.push_back(Month(8, "August", 31));
    tempMap.push_back(Month(9, "Setpemeber", 30));
    tempMap.push_back(Month(10, "October", 31));
    tempMap.push_back(Month(11, "November", 30));
    tempMap.push_back(Month(12, "December", 31));

    return tempMap;

};

class Date {
    private:
        string monthName;
        unsigned month;
        unsigned day;
        unsigned year;

    public:
        Date();
        Date(unsigned m, unsigned d, unsigned y);
        Date(const string &mn, unsigned d, unsigned y);
        void printNumeric() const;
        void printAlpha() const;

    private:
        bool isLeap(unsigned y) const;
        unsigned daysPerMonth(unsigned m, unsigned y) const;
        string name(unsigned m) const;
        unsigned number(const string &mn) const;
};


// Implement the Date member functions here

Date::Date()
    :monthName("January"), month(1), day(1), year(2000)
{
}

Date::Date(unsigned m, unsigned d, unsigned y)
    :month(m), day(d), year(y)
{
    Month monthMatch(12, "Decemeber", 31);
    vector<Month> monthMap = CreateMonthMap();
    bool isValidDay = true;
    bool isValidMonth = true;

    if (isLeap(year)) {
        monthMap[1].maxDays = 29;
    }

    for (
        auto it = monthMap.begin();
        it != monthMap.end();
        it++
    )
    {
        if (it->monthNum == month)
        {
            monthMatch = *it;
            monthName = it->monthName;
        }
    }

    if (day == 0) {
        day = 1;
        isValidDay = false;
    }

    if (month == 0) {
        month = 1;
        monthName = "January";
        isValidMonth = false;
    }

    if(month > 12) {
        month = 12;
        monthName = "December";
        isValidMonth = false;
    }



    if (day > monthMatch.maxDays) {
        day = monthMatch.maxDays;
        isValidDay = false;
    }

    if (!isValidMonth) {
        cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }

    if (!isValidDay && isValidMonth) {
        cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }

}

Date::Date(const string &mn, unsigned d, unsigned y)
    :monthName(mn), day(d), year(y)
{   
    Month monthMatch(12, "January", 31);
    vector<Month> monthMap = CreateMonthMap();
    string monthNameSc = ToSentence(monthName);
    bool isValidMonth = false;
    bool isValidDay = true;

    if (isLeap(year)) {
        monthMap[1].maxDays = 29;
    }

    for(auto it = monthMap.begin(); it != monthMap.end(); ++it) {
        if (monthNameSc == it->monthName) {
            monthMatch = *it;
            monthName = monthNameSc;
            month = it->monthNum;
            isValidMonth = true;
            break;
        }
    }

    if (day == 0) {
        day = 1;
        isValidDay = false;
    }

    if (month == 0) {
        month = 1;
        monthName = "January";
        isValidDay = false;
    }

    if ((day > monthMatch.maxDays) && isValidMonth){
        day = monthMatch.maxDays;
        isValidDay = false;
    }

    if (!isValidMonth) {
        monthName = "January";
        day = 1;
        month = 1;
        year = 2000;
    }

    if (!isValidMonth) {
        cout << "Invalid month name: the Date was set to " << month << '/' << day << '/' << year << '.' << endl;
    }

    if (!isValidDay && isValidMonth) {
        cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }
}

void Date::printNumeric() const {
    cout << month << '/' << day << '/' << year;
}

void Date::printAlpha() const {
    cout << monthName << ' ' << day << ", " << year;
}

bool Date::isLeap(unsigned year_) const {
    bool isDecade = (year_ % 100 == 0) ? true : false;

    if (isDecade) {
        if (year_ % 400 == 0) 
            return true;
        else
            return false;
    }

    if (year_ % 4 == 0) {
        return true;
    }

    return false;
}

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}