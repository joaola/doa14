#include "glosor.h"
using namespace std;

int main(){
	string lang; //välj språk
	string word; //ord att översätta
	glosor g;
	while (true){
		cout << "Tillgängliga språk: swe & eng" << endl << endl;
		cout << "Vilket språk vill du översätta till? ";;
		cin >> lang;
		cout << "Ange ord att översätta till " << lang << ": ";
		cin >> word;
		g.Translate(lang, word);
		cout << "Översättning: ";
		g.PrintWord();
		system("PAUSE");
	}
	return 0;
}