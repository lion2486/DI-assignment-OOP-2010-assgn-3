#ifndef SPELLS_H_
#define SPELLS_H_

class spell{
public:
	virtual void doSpell(player *p) = 0;
};

class InvalidSpell : public spell{
public:
	void doSpell(player *p){
		return;
	}
};

class PenaltySpell : public spell{
public:
	void doSpell(player *p){
		p->changePower(-2);
		return;
	}
};

class BonusSpell : public spell{
public:
	void doSpell(player *p){
			p->changePower(2);
			return;
		}
};

class JamSpell : public spell{
public:
	void doSpell(player *p){
			p->drop();
			return;
		}
};

#endif /* SPELLS_H_ */
