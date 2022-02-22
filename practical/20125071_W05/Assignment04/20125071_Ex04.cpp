#include "savePrincess.h"

using namespace std;

int main() {
	Castle game;
	game.input();

	if (game.savePrincess()) {
		cout << "Congratulations! Save Princess successfully!";
	}
	else cout << "The prince can't save princess.";

	return 0;
}