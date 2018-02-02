#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>

using namespace std;

class player{
protected:
	int power;
	bool good;
public:
	player(){
		good = true;
	}
	int getpower() { return power; }
	virtual bool is_Chasers(){ return false; }
	virtual bool is_Beaters(){ return false; }
	virtual bool is_Keepers(){ return false; }
	virtual bool is_Seekers(){ return false; }
	void changePower(int k){
		power += k;
		return;
	}
	void drop(){ good = false; }
	bool canPlay(){ return good; }
};

class Chasers : public player{
private:
	static const int maxPower = 10;
	static const int minPower = 2;
public:
	Chasers(){
		power = rand()%(maxPower-minPower+1)+minPower;
	}
	bool is_Chasers(){ return true; }
};

class Beaters : public player{
private:
	static const int maxPower = 3;
	static const int minPower = 1;
public:
	Beaters(){
		power = rand()%(maxPower-minPower+1)+minPower;
	}
	bool is_Beaters(){ return true; }
};

class Keepers : public player{
private:
	static const int maxPower = 10;
	static const int minPower = 6;
public:
	Keepers(){
		power = rand()%(maxPower-minPower+1)+minPower;
	}
	bool is_Keepers(){ return true; }
};

class Seekers : public player{
private:
	static const int maxPower = 12;
	static const int minPower = 11;
public:
	Seekers(){
		power = rand()%(maxPower-minPower+1)+minPower;
	}
	bool is_Seekers(){ return true; }
};

#endif /* PLAYER_H_ */
