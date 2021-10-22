#include "point.h"

using namespace std;
int main(){
    Point2D a, b(1,2);
    Point2D c(a,b);
    Point2D d(c);

    a.display();
    b.display();
    c.display();
    d.display();
    try{
        Point2D e("12.3,1.23");
        e.display();
    }
    catch(const char *msg){
        cerr << msg << "\n";
    }

    return 0;
}