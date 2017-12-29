#include <iostream>

using namespace std;

class maze{
//	private:
//	char pMaze[12][10];
	
	public:
	char pMaze[12][10];
	maze(){
		char iniMaze[12][11] = {
			"START*****",
			"* ********",
			"* **  ** *",
			"* *  **  *",
			"*        *",
			"* *  *** *",
			"* ** * ***",
			"* *  *   *",
			"* **     *",
			"*  * *** *",
			"******** *",
			"*******END"
		};
		for(int i = 0; i < 12; i++){
			for(int j = 0; j < 10; j++){
				pMaze[i][j] = iniMaze[i][j];
			}
		}
	}
};

class hero{
	public:
	hero(){
		HeroIs = 'H';
		heroLocation[0] = 1;
		heroLocation[1] = 1;
	}
	char HeroIs = 'H';
	int heroLocation[2];
};

class play{
	private:
	maze initial;
	hero H;
	
	public:
	play(){
		
		initial.pMaze[1][1] = H.HeroIs;
		
	}
	void printBoard(){
		for(int i = 0; i < 12; i++){
			for(int j = 0; j < 10; j++){
				cout << initial.pMaze[i][j];
			}
			cout << endl;
		}
	};
	bool isEmpty(char check){
		if(check == ' ') return true;
		else  return false;
	};
	void moveHero(int row, int col){
		initial.pMaze[H.heroLocation[0]][H.heroLocation[1]] = ' ';
		initial.pMaze[row][col] = H.HeroIs;
		H.heroLocation[0] = row;
		H.heroLocation[1] = col;
		printBoard();
	};
	void nextMove(char next){
		int temp[2];
		temp[0] = H.heroLocation[0];
		temp[1] = H.heroLocation[1];
		switch (next){
			case 'W': case 'w': {
				--temp[0];
				if(bool check = isEmpty(initial.pMaze[temp[0]][temp[1]])){
					moveHero(temp[0], temp[1]);
					break;
				}
				else break;
			}
			case 'Z': case 'z': {
				++temp[0];
				if(bool check = isEmpty(initial.pMaze[temp[0]][temp[1]])){
					moveHero(temp[0], temp[1]);
					break;
				}
				else break;
			}
			case 'A': case 'a': {
				--temp[1];
				if(bool check = isEmpty(initial.pMaze[temp[0]][temp[1]])){
					moveHero(temp[0], temp[1]);
					break;
				}
				else break;
			}
			case 'S': case 's': {
				++temp[1];
				if(bool check = isEmpty(initial.pMaze[temp[0]][temp[1]])){
					moveHero(temp[0], temp[1]);
					break;
				}
				else break;
			}
			default: {
				break;
			}
		}
	};
	char whatNext(){
		char next;
		cout << "Enter w, a, s or z:" << endl;
		cin >> next;
		return next;
	};
	bool isEnd(){
		if(H.heroLocation[0] == 10 && H.heroLocation[1] == 8){
			return false;
		}
		else return true;
	}
	
};

int main() {

	char next;
	play START;
	START.printBoard();
	do{
		next = START.whatNext();
		START.nextMove(next);
	}while(START.isEnd());
	cout << "Congrats! You won...." << endl;
	return 0;

}
