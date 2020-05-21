#include <iostream>

using namespace std;

const double secPerDay = 24 * 60 * 60;
const double secPerHour =  3600;
const double secPerMinute = 60;

class timetag {

public:
    timetag();
    timetag(float);
    void display();
    double getdays();
    double gethours();
    double getmin();
    double getsec();

private:
    double sec, min, hours, days, totalSec;

};

double timetag::getmin() { return min; }
double timetag::getsec() { return sec; }
double timetag::getdays() { return days; }
double timetag::gethours() { return hours; }


timetag::timetag() {
    sec = 0;
    min = 0;
    hours = 0;
    days = 0;
    totalSec = 0;
}

timetag::timetag(float psec) {

    totalSec = psec;



    double rseconds = 0;

    days = (double) ((int)psec / (int)secPerDay);
    //days = psec / secPerDay;

    rseconds = psec - days * secPerDay;

    hours = (double) ((int)rseconds / (int)secPerHour);
    //hours = rseconds / secPerHour;

    rseconds = rseconds - hours * secPerHour;

    min = (double) ((int)rseconds / (int)secPerMinute);
    //min = rseconds / secPerMinute;

    sec = rseconds - min * secPerMinute;

    // sec = psec;
    // min = 0;
    // hours = 0;
    // days = 0;
}

void timetag::display() {
    cout<<"days= "<<days<<", hours= "<<hours<<", minutes= "<<min<<", seconds= "<<sec<<endl;

}
int main() {
    timetag t1;
    t1.display();

    timetag t2(1345500.345602349256);
    t2.display();

    cout << t2.getdays() * 86400 + t2.gethours() * 3600 + t2.getmin() * 60 + t2.getsec()<<endl;


    return 0;
}
