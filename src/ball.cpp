#include "ball.h"

Quaffle::Quaffle(player *pl1, player *pl2){
	score = 10;
	penalty = 0;
	p1 = pl1;
	p2 = pl2;
}

int Quaffle::play(){
	if((p1->getpower() > p2->getpower()) && !(p1->is_Keepers()) && p1->canPlay())
		return -1;
	if((p1->getpower() < p2->getpower()) && !(p2->is_Keepers()) && p1->canPlay())
		return 1;
	return 0;
}

Bludger::Bludger(player *pl1, player *pl2){
	score = 0;
	penalty = 2;
	p1 = pl1;
	p2 = pl2;
}

int Bludger::play(){
		if(!(p1->is_Beaters()) && !(p2->is_Beaters()))
			return 0;
		if(p1->is_Beaters() && p1->canPlay())
			if(p2->is_Beaters() && p2->canPlay())
				if(p1->getpower() > p2->getpower())
					return -1;
				else if(p1->getpower() < p2->getpower())
					return 1;
				else
					return 0;
			else
				return -1;
		else
			if(p2->is_Beaters() && p2->canPlay())
				return 1;
			else
				return 0;
	}

GoldenSnitch::GoldenSnitch(player *pl1, player *pl2){
	score = 150;
	penalty = 0;
	p1 = pl1;
	p2 = pl2;
}

int GoldenSnitch::play(){
	if(p1->is_Seekers() && p2->is_Seekers())
		if(p1->canPlay())
			if(p2->canPlay())
				if(p1->getpower() > p2->getpower())
					return -1;
				else if(p1->getpower() < p2->getpower())
					return 1;
				else
					return 0;
			else
				return -1;
		else
			if(p2->canPlay())
				return 1;
			else
				return 0;
	else
		if(p1->is_Seekers() && p1->canPlay())
			return -1;
		else if(p2->is_Seekers() && p2->canPlay())
			return 1;
		else
			return 0;
}
