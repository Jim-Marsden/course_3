#include "Date.h"
void print_date(int month, int day, int year){
    JimMarsden::Date(month, day, year).display();
}

int main(){
    print_date(1, 2, 1990);
    print_date(2, 29, 1990);
    print_date(2, 29, 2000);

    print_date(2, 1, 0000);
    print_date(2, 1, -1990);

    print_date(0, 1, 2000);
    print_date(13, 1, 1990);

}
