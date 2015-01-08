#include <math.h>
#pragma once
class sumCounter
{
private:
public:

	sumCounter(){
	}

	float sum_rek(int n){ // 3.1a)
		int i = 1;
		if (n <= i){
			return (1/sqrt(float(n)));
		}
		return (1/sqrt((float)n) + sum_rek(n-1));
	}

	float sum_it(int n){ //3.1b)
		float result = 0;
		for (int i = 1; i <= n; i++){
			result += (1 / sqrt(float(i)));
		}
		
		return result;
	}

	~sumCounter()
	{
	}
};

