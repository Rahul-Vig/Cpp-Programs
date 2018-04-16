#include <iostream>

using std::endl;

bool leapYear(int y){
  return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
}

int main(){
  std::cout << std::boolalpha;
    std::cout << leapYear(0) << endl;
    std::cout << leapYear(400) << endl;
    std::cout << leapYear(2012) << endl;
    std::cout << leapYear(2013) << endl;
    std::cout << leapYear(2014) << endl;
    std::cout << leapYear(2016) << endl;
    std::cout << leapYear(2020) << endl;
    std::cout << leapYear(2021) << endl;
    std::cout << leapYear(2024) << endl;
    std::cout << leapYear(2028) << endl;
    std::cout << leapYear(2032) << endl;
}
