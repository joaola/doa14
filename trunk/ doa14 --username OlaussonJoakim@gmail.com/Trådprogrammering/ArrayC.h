 /* 
 * File:   ArrayC.h
 * Author: kmo
 *
 * Created on January 1, 2013, 8:32 PM
 */

#ifndef ARRAYC_H
#define	ARRAYC_H

#include <iostream>
using namespace std;

namespace Course
{
    class ArrayC {
    public:
		ArrayC() {}
        ArrayC(const ArrayC& orig) {}

        virtual ~ArrayC() {}

        template<class T>
        static T max(T v[], int s, int e)
        {
            if ( s == e )
                return v[s];
            T m = v[s];
            T h = max(v,s+1,e);
            if ( m > h )
                return m;
            else
                return h;
        }
        
        template<class T>
        static T sum(T v[], int s, int e)
        {
            if ( s == e )
                return v[s];
            return v[s] + sum(v,s+1,e);
        }
        
        template<class T>
        static T product(T v[], int s, int e)
        {
            if ( s == e )
                return v[s];
            return v[s] * product(v,s+1,e);
        }

    private:
    };
}
#endif	/* ARRAYC_H */



