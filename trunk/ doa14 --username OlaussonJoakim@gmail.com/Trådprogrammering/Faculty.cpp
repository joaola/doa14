#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
using namespace std;

#include "Watch.h"
using namespace Course;

/**
 * 
 * @param n
 * @return 
 */
namespace Course {

    long RFac(long n) {
        if (n == 0)
            return 1;
        else
            return n * RFac(n - 1);
    }

    long IFac(long n) {
        long f = 1;
        for (int i = 2; i <= n; i++) {
            f = i*f;
        }

        return f;
    }
}

void main_recursive_faculty() {
    Watch w;
    Course::microseconds t0, t1, t2, t3;
    long nLoop = 1000000L;
    long x;
    
    cout << setw(5) << "n";
    cout << setw(15) << "RFac (ns)";
    cout << setw(15) << "IFac (ns)"  << endl;
    nLoop=1000000L;
    cout.precision(2);
    cout.setf(ios::fixed);
    
    for (int n = 1; n < 14; n++) {
        w.restart();
        for (int i = 0; i < nLoop; i++) {
            ;
        }
        t0 = w.elapsedUs();

        w.restart();
        for (int i = 0; i < nLoop; i++) {
            x = RFac(n);
        }
        t1 = w.elapsedUs();

        w.restart();
        for (int i = 0; i < nLoop; i++) {
            x = IFac(n);
        }
        t2 = w.elapsedUs();
        
        cout << setw(3)  << n << ": " << setw(15) << 1e3*double(t1.count()-t0.count())/nLoop;
        cout << setw(15) << 1e3*(t2.count()-t0.count())/ (double)nLoop << endl;
        
    }

}
