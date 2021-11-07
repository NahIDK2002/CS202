#include "myString.h"

using namespace std;

int main(){
    MyString s1("s1"), s2("s2");
    MyString s3("s3");
    (s1=s2)=s3;

    s1.display();
    s2.display();
    s3.display();

    return 0;
}