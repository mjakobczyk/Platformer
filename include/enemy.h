#ifndef ENEMY_H_
#define ENEMY_H_

#define ENEMIES_QUANTITY 1
#define OFFSET_MOVEMENT_4 4

class Enemy : public Character
{
protected:
	sf::Vector2f startPos; // Pozycja startowa przeciwnika
	sf::Vector2f endPos; // Pozycja ko�cowa, do kt�rej przeciwnik pod��a
	sf::Vector2f backPos; // Pozycja powrotu, do kt�rej kieruje si� przeciwnik po endPos

	float totalTime; // Ca�kowity czas zmiany tekstury, nie mo�e przekracza� switch time'u
	float switchTime; // Okre�la cz�sto�� zmian tekstury postaci
	int imageNumber; // Numer aktualnie wy�wietlanej klatki z tekstury

public:
	Enemy();
	Enemy(sf::Vector2u, float);
	Enemy(sf::Texture *, sf::Vector2u, float);
	virtual ~Enemy();

	void setStartPos(sf::Vector2f); // Ustawia pozycje startow�
	void setEndPos(sf::Vector2f); // Ustawia pozycj� ko�cow�
	void setBackPos(sf::Vector2f); // Ustawia pozycj� powrotu
	void setSize(sf::Vector2f); // Ustawia wielko�� przeciwnika
	void setDirection(bool); // Ustawia kierunek, w kt�rym ma si� porusza�
	void setMoveSpeed(float); // Ustawia pr�dko�� poruszania si� przeciwnika

	sf::Vector2f getStartPos(); // Pobiera pozycj� startow� przeciwnika
	sf::Vector2f getEndPos(); // Pobiera pozycj� ko�cow� przeciwnika
	sf::Vector2f getBackPos(); // Pobiera pozycj� powrotu przeciwnika

	//virtual void update(float); // Aktualizuje dane o postaci
};

//---------------------------------------------------------------------------------------

#define ZOMBIE_BONUS 500

class Zombie : public Enemy
{
public:
	Zombie();
	Zombie(sf::Vector2u, float);
	Zombie(sf::Texture *, sf::Vector2u, float);
	~Zombie();

	virtual void update(float); // Aktualizuje dane o postaci
};

//---------------------------------------------------------------------------------------

#define VILLAIN_BONUS 100

class Villain : public Enemy
{
public:
	Villain();
	Villain(sf::Vector2u, float);
	Villain(sf::Texture *, sf::Vector2u, float);
	~Villain();

	virtual void update(float); // Aktualizuje dane o postaci
};

//---------------------------------------------------------------------------------------

#endif