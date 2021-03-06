#include <list>
#ifndef CREATURES
#define CREATURES
/***************************/
struct trit
{
	int v;
	trit operator = (int param); 
	int operator + (int param);
	int operator - (int param);
	bool operator == (int param);
	int operator * (int param);
	operator int();
};
struct vect
{
	trit y,x;
	void swap();
	void turn(int dir);
	trit operator == (vect param);
	vect operator * (vect param);
	vect operator + (vect param);
	trit operator < (vect param);
	trit operator > (vect param);
};
struct tile
{
	tile();
	int y,x;
	virtual bool sameplace(int a,int b);
};
struct item:tile
{
	vect v;
	char appearance;
	int hue;
	virtual void appear();
	virtual void die();
	item(int a, int b,char c);
};
struct creature:item
{
	creature(char c);
	int hp,energy,speed;
	bool small; //doesn't block other creatures
	bool solid;	//can't walk through walls
	bool translucent;//looking
	virtual void move();
	virtual int directionblocked();
	virtual void act();
	virtual void choosemove1(int a);
	virtual bool dig();
	virtual void move2(int a);
	virtual bool avoidobstacles(int b);
	virtual void seek(int a, int b, int c);
	virtual void attacked (creature* attacker);
	virtual void attack(creature* victim);
	virtual void run(int distance);
};
/***************************/
struct me: creature
{
	virtual void act();
	me();
	virtual void attacked(creature* attacker);
};
struct cube: creature
{
	cube();
	virtual void attacked (creature* attacker);
	virtual int directionblocked();
	virtual void act();
};
struct larva: creature
{
	larva();
	virtual void attacked (creature* attacker);
	virtual int directionblocked();
	virtual void act();
};
struct crab: creature
{
	crab();
	virtual int directionblocked();
	virtual void act();
};
struct mole: creature
{
	mole();
	virtual int directionblocked();
	virtual void act();
};
/***************************/
#endif