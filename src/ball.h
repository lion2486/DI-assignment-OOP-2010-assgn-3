#ifndef BALL_H_
#define BALL_H_
#include <iostream>
#include "player.h"

using namespace std;

class ball{
protected:
	player *p1;
	player *p2;
	int score;
	int penalty;
public:
	virtual int play() = 0;
	int getscore(){ return score; }
	int getpenalty(){ return penalty; }
};

class Quaffle : public ball{
public:
	Quaffle(player *pl1, player *pl2);
	int play();
};

class Bludger : public ball{
public:
	Bludger(player *pl1, player *pl2);
	int play();
};

class GoldenSnitch : public ball{
public:
	GoldenSnitch(player *pl1, player *pl2);
	int play();
};

#endif /* BALL_H_ */
