#ifndef SPELL_H_
#define SPELL_H_

#define SPELL_COOLDOWN 1

class Spell : public Moveable
{
protected:
	int manaCost; // Koszt many czaru
	int power; // Si�a czaru
	float speed; // Pr�dko�� z jak� porusza si� czar
	float distance; // Aktualnie przebyty dystans przez czar
	float maxDistance; // Maksymalna odleg�o�� jak� mo�e przeby� czar
	bool isMovingRight; // Flaga okre�laj�ca w kt�r� stron� poziomo porusza si� czar

	Animation animation; // Animacja czaru
	bool first, second, third; // Stadia rozwoju animacji czaru
	int row; // Aktualnie wy�wietlany rz�d animacji
	sf::Vector2f startingPos; // Wsp�rz�dne nadawane podczas rzucania czaru

public:
	Spell();
	virtual ~Spell();

	void setDirection(bool); // Ustawia kierunek poruszania si� czaru
	void setStartingPos(sf::Vector2f); // Ustawia wsp�rz�dne pocz�tkowe czaru
	bool getDirection(); // Pobiera kierunek, w kt�rym porusza si� czar

	virtual void draw(sf::RenderWindow &); // Rysuje czar
	virtual bool collision(Entity *); // Reakcja czaru na zderzenie z obiektami
	virtual void update(float); // AKtualizacja czaru
};

//---------------------------------------------------------------------------------------

// Klasa kuli ognia
class Fireball : public Spell
{
public:
	Fireball();
	~Fireball();
};

//---------------------------------------------------------------------------------------

// Klasa kuli zimna
class Frostbolt : public Spell
{
public:
	Frostbolt();
	~Frostbolt();
};

//---------------------------------------------------------------------------------------

// Klasa kuli ciemno�ci
class Shadowbolt : public Spell
{
public:
	Shadowbolt();
	~Shadowbolt();
};

//---------------------------------------------------------------------------------------

#endif