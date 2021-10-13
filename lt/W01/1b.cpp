#include <iostream>

using namespace std;

struct Date{
    private:
        int day;
        int month;
        int year;

    public:
        bool setDate(int d, int m, int y);
        void getDate(int &d, int &m, int &y);
};

int main(){    

    Date date;

    return 0;
}