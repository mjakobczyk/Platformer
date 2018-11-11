#ifndef STABLE_H_
#define STABLE_H_

enum Interaction { NONE = 0, STOP = 1, BONUS = 2, DAMAGE = 3, HEAL = 4, TELEPORT};

#define BONUS_POINTS 25

class Stable : public Entity
{
protected:
	bool collidable; // Flaga okre�laj�ca czy mo�na wej�� na obiekt
	bool interactable; // Flaga okre�laj�ca czy mo�na wej�� w interakcj� z obiektem
	Interaction interaction; // Typ wyliczeniowy okre�laj�cy spos�b interakcji

public:
	Stable();
	virtual ~Stable();

	bool isCollidable(); // Sprawdza czy mo�na wej�� na obiekt
	bool isInteractable(); // Sprawdza czy mo�na wej�� w interakcj� z obiektem

	virtual Interaction getInteraction(); // Zwraca rodzaj interakcji

	virtual void draw(sf::RenderWindow &); // Rysuje obiekt
	virtual bool collision(Entity *); // Efekt kolizji z obiektem
	virtual void update(float); // Aktualizacja obiektu
};

//---------------------------------------------------------------------------------------

// Klasa monety, bonus w trakcie rozgrywki
class Coin : public Stable
{

public:
	Coin();
	~Coin();

	virtual bool collision(Entity *);
};

//---------------------------------------------------------------------------------------

#endif