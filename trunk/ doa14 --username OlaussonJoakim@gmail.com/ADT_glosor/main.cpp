#include "glosor.h"
using namespace std;

int main(){
	string lang; //v�lj spr�k
	string word; //ord att �vers�tta
	glosor g;
	while (true){
		cout << "Tillg�ngliga spr�k: swe & eng" << endl << endl;
		cout << "Vilket spr�k vill du �vers�tta till? ";;
		cin >> lang;
		cout << "Ange ord att �vers�tta till " << lang << ": ";
		cin >> word;
		g.Translate(lang, word);
		cout << "�vers�ttning: ";
		g.PrintWord();
		system("PAUSE");
	}
	return 0;
}