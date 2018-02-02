#include <iostream>
#include <stdlib.h>
#include "ball.h"
#include "spells.h"

using namespace std;

int main(int argc, char *argv[]){
	ball * b;
	player * p1;
	player * p2;
	spell * s;
	int round = 0, score[2], penalty[2], N = -1, win = 0, srandN = time(NULL), res;
	bool gold = false, last = false;
	score[0] = 0;
	score[1] = 0;
	penalty[0] = 0;
	penalty[1] = 0;
	for(int a=0;a<argc;a++){
		if(!strcmp(argv[a], "-N"))
			N = atoi(argv[a+1]);
		if(!strcmp(argv[a], "-rand"))
			srandN = atoi(argv[a+1]);
	}
	srand(srandN);				/* Initializing the random numbers */
	do{
		round ++;
		/* Create 2 random players */
		switch (rand()%4){
			case 0:	p1 = new Chasers;
					break;
			case 1: p1 = new Beaters;
					break;
			case 2: p1 = new Keepers;
					break;
			case 3: p1 = new Seekers;
					break;
		}
		switch (rand()%4){
				case 0:	p2 = new Chasers;
						break;
				case 1: p2 = new Beaters;
							break;
				case 2: p2 = new Keepers;
						break;
				case 3: p2 = new Seekers;
						break;
		}
		/* Create 1 random ball */
		switch (rand()%3){
			case 0:	b = new Quaffle(p1, p2);
					break;
			case 1: b = new Bludger(p1, p2);
					break;
			case 2: b = new GoldenSnitch(p1, p2);
			/* Gold is the last ball if someone wins */
					gold = true;
					break;
		}
		/* Create 1 Random Spell */
		switch (rand()%4){
			case 0:	s = new InvalidSpell;
					break;
			case 1: s = new PenaltySpell;
					break;
			case 2: s = new BonusSpell;
					break;
			case 3: s = new JamSpell;
					break;
		}
		/* Spell targets a random player */
		switch(rand()%2){
			case 0: s->doSpell(p1);
					break;
			case 1: s->doSpell(p2);
					break;
		}
		res = b -> play();
		if(gold && res == 0)			/* If anyone won the gold ball, game continues */
			gold = false;
		if(res == -1){					/* result -1 means that team 1 won */
			score[0] += b -> getscore();
			penalty[1] += b -> getpenalty();
			if(gold)
				win = -1;
		}
		else if(res == 1){				/* result 1 means that team 2 won */
			score[1] += b -> getscore();
			penalty[0] += b -> getpenalty();
			if(gold)
				win = 1;
		}
		/* Print the round statistics */
		cout << "Round: " << round << endl;
		cout << "Team 1 Score: " << score[0] << endl;
		cout << "Team 1 Penalty: " << penalty[0] << endl;
		cout << "Team 2 Score: " << score[1] << endl;
		cout << "Team 2 Penalty: " << penalty[1] << endl;
		cout << "====================" << endl;
		/* if match is ended, calculate the winner */
		if(round >= N && N > 0 && !gold){
			if(score[0] > score[1])
				win = -1;
			else if(score[0] < score[1])
				win = 1;
			last = true;
		}
	}while(!gold && !last);
	/* Print the game statistics */
	if(win==-1)
		cout << "Winner: Team 1!" << endl;
	else if(win==1)
			cout << "Winner: Team 2!" << endl;
	else
			cout << "No Winner!" << endl;
	cout << "Number of rounds: " << round << endl;
	cout << "Team 1 Score: " << score[0] << endl;
	cout << "Team 1 Penalty: " << penalty[0] << endl;
	cout << "Team 2 Score: " << score[1] << endl;
	cout << "Team 2 Penalty: " << penalty[1] << endl;
	return 0;
}

