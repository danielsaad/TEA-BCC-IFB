#include <iostream>
#include <iomanip> // setprecision
#include <map>

using namespace std;

int main(){
    map<string,double> m;
    m["banana"] = 3.14;
    m["maca"] = 9.28;
    m["limao"] = 1.72;

    // Se comprarmos 2 quilos de banana, um quilo e meio de maçã
    // e 5 quilos de limão, esse seria o resultado;
    double total = 2*m["banana"] + 1.5*m["maca"] + 5*m["limao"];
    cout << "Total sacolão: " << fixed << setprecision(2) << total << endl;
    return 0;
}