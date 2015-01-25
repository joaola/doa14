#include "ArrayC.h"

void main_recursive_array()
{
        
    int v1[12] = {1 , 4, 2, 8, 2, 10, 3, 15, 20, 21, 7, 6};
    double v2[] = {1.1 , 4.2, 2, 8, 2, 10, 3, 15, 20.5, 21.25, 7, 6};

    cout << "max v1 =" << Course::ArrayC::max(v1,0,11) << endl;
    cout << "max v2 =" << Course::ArrayC::max(v2,0,11) << endl;
    cout << "sum v1 =" << Course::ArrayC::sum(v1,0,11) << endl;
    cout << "sum v2 =" << Course::ArrayC::sum(v2,0,11) << endl;

}