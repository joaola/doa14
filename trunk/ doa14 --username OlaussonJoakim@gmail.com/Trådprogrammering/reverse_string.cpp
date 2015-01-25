#include <iostream>
using namespace std;

void Swap(char *p, char *q)
{
    char temp;
    temp = *p;
    *p = *q;
    *q = temp;
} //slut-Swap 


void Reverse(char *s, int j, int k)
{
    if (j < k) {
        Swap(&s[j], &s[k]);
        Reverse(s, j + 1, k - 1);
    }
} //slut-Reverse

void main_recursive_reverse_string()
{
    char str[99] = "VAD RÄ GAJ GITKUD .";
    cout << "Orginal: " << str << endl;
    Reverse(str, 4, 17);
    cout << "Vänd:    " << str << endl;
} //slut-main
