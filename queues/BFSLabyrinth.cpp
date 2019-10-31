// BFSLabyrinth.cpp : Defines the entry point for the console application.
//
 
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <Windows.h>
using namespace std;
 
HANDLE hConsole;
 
const int RED = 12, YELLOW = 14, GRAY = 8, WHITE = 15, DEFAULT = WHITE;

void setColor(int col) {
	SetConsoleTextAttribute(hConsole, col);
}

//The A, B, C and D don't really matter
vector< vector< char > > labyrinth = {
	{'A', '.', '.', '.', 'B'},
	{'.', '.', '.', '.', '#'},
	{'.', '.', '#', '#', '#'},
	{'.', '.', '#', '$', '#'},
	{'C', '.', '.', '.', 'D'}
};
 
struct ivec2 {
	int x, y;
	ivec2(int _x, int _y): x(_x), y(_y) {}
	ivec2 operator+(const ivec2& a) {
		return ivec2(x + a.x, y + a.y);
	}
};

const int movCount = 4;
const ivec2 movOffsets[movCount] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
 
class cell {
	int extraStatus=0;
	vector<int> playerDistances;
public:
	cell(int players): playerDistances(players) {}
	//Mark a cell as reached by <player> with a distance of <dist>
	//Returns false if unreachable
	bool reach(int player, int dist) {
		if (extraStatus == -1) return false;
		if (playerDistances.size() <= player) {
			playerDistances.resize(player+1, 0);
		}
		playerDistances[player] = dist;
		return true;
	}
	//Returns the distance if a cell has been reached by <player>, 0 if it hasn't, or -1 if it can't be reached at all.
	int isReached(int player) {
		if (extraStatus == -1) return -1;
		if (playerDistances.size() <= player) {
			playerDistances.resize(player + 1, 0);
		}
		return playerDistances[player];
	}
	bool isTreasure() {
		return extraStatus == 1;
	}
	void setUnreachable(){
		extraStatus = -1;
	}
	void setTreasure() {
		extraStatus = 1;
	}
	void print(int width=2) const {
		cout << "  [";
		cout << setw(width);
		switch (extraStatus) {
		case 1:
			setColor(YELLOW); break;
		case -1:
			setColor(RED); break;
		}
		for (int i = 0; i < playerDistances.size(); i++) {
			if ((playerDistances[i] == 0) && (extraStatus == 0)) {
				setColor(GRAY);
				cout << playerDistances[i];
				setColor(DEFAULT);
			} else {
				cout << playerDistances[i];
			}
			if (i < (playerDistances.size() - 1)) cout << setw(0) << ", " << setw(width);
		}
		setColor(DEFAULT);
		cout << "]  ";
	}
};
 
//[min, max]
bool bounded(ivec2 min, ivec2 max, ivec2 val) {
	return val.x >= min.x && val.y >= min.y && val.x <= max.x && val.y <= max.y;
}

//Returns if all queues of players' positions are empty
bool allEmpty(const vector<queue<ivec2> > &positions) {
	for (int i = 0; i < positions.size(); i++) {
		if (!positions[i].empty()) return false;
	}
	return true;
}
 
void printLabyrinth(const vector< vector< cell > > &fields) {
	for (int i = 0; i < fields.size(); i++) {
		for (int j = 0; j < fields[0].size(); j++) {
			fields[i][j].print(); cout << " ";
		}
		cout << endl;
	}
}

//Converts a char labyrinth to a matrix with special cells, defining them for <players> players
//Although things will still work if you use more players afterwards, they will liekly print ugly
vector< vector< cell > > convert(vector< vector< char > > labyrinth, int players) {
	vector< vector< cell > > res;
	for (int i = 0; i < labyrinth.size(); i++) {
		res.push_back(vector< cell >());
		for (int j = 0; j < labyrinth[0].size(); j++) {
			res[i].push_back(cell(players));
			switch (labyrinth[i][j]) {
			case '#':
				res[i][j].setUnreachable(); break;
			case '$':
				res[i][j].setTreasure(); break;
			}
		}
	}
	return res;
}


void BFS(vector< vector< char > > labyrinth_char, vector<ivec2> players) {

	const ivec2 labmin(0, 0), labmax(labyrinth_char.size()-1, labyrinth_char[0].size()-1);

	//Convert char to our cells
	vector< vector< cell > > labyrinth = convert(labyrinth_char, players.size());

	//Players' positions to spill into
	vector<queue<ivec2> > positions(players.size());
	//Initialize positions
	for (int i = 0; i < players.size(); i++) {
		positions[i].push(players[i]);
		labyrinth[players[i].x][players[i].y].reach(i, 1);
	}

	while (!allEmpty(positions)) {
		printLabyrinth(labyrinth);

		for (int i = 0; i < players.size(); i++) {
			//Tick each player who has positions to spill into
			if (!positions[i].empty()) {
				ivec2 pos = positions[i].front();
				positions[i].pop();
				if (labyrinth[pos.x][pos.y].isTreasure()) {
					//We found the trasure! stop looking everywhere else...
					//Or, if you want, delete this line and have them spill out everywhere.
					while (!positions[i].empty()) positions[i].pop();
				}else{
					for (int j = 0; j < movCount; j++) {
						ivec2 newpos = pos + movOffsets[j];
						if (bounded(labmin, labmax, newpos) && labyrinth[newpos.x][newpos.y].isReached(i) == 0) {
							labyrinth[newpos.x][newpos.y].reach(i, labyrinth[pos.x][pos.y].isReached(i) + 1);
							positions[i].push(newpos);
						}
					}
				}
			}
		}
		cout << "\n\n\n";
	}
	cout << "End result:\n\n";
	printLabyrinth(labyrinth);
}
 
int main() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	vector<ivec2> players;
	players.push_back(ivec2(0, 0));
	players.push_back(ivec2(4, 0));
	players.push_back(ivec2(0, 4));
	players.push_back(ivec2(4, 4));
 
	BFS(labyrinth, players);
	return 0;
}

