#ifndef HERO_H_
#define HERO_H_

// Wyb�r mi�dzy mo�liwymi postaciami do gry
enum heroSpec { unknown = 0, warlock = 1, mage = 2, priest = 3 };

// Implementacja postaci w postaci bohatera gry, singleton
class Hero : public Character
{
protected:
	heroSpec spec; // Typ wyliczeniowy okre�laj�cy dokonany wyb�r klasy postaci
	bool spellCast; // Flaga ustawiana przy rzuceniu czaru
	sf::Clock lastCast; // Zegar umo�liwia odliczy� czas kiedy ostatnio rzucili�my czar

public:
	Hero(heroSpec);
	Hero(heroSpec, sf::Texture * texture, sf::Vector2u imageCount, float switchTime);
	virtual  ~Hero();

	void setSpec(heroSpec); // Ustawia specjalizacj� gracza 
	bool isSpecSet(); // Sprawdza czy specjalizacja zosta�a utworzona
	bool isSpellCast(); // Sprawdza czy zosta� rzucony jaki� czar
	float getLastCast(); // Pobiera czas ostatnio rzuconego czaru

	Hero * getHero(); // Zwraca wska�nik na bohatera

	virtual void update(float); // Aktualizacja gracza odbywa� si� b�dzie w podobny spos�b
								// pomi�dzy klasami pochodnymi, ale mog� zaj�� r�nice
	virtual bool castSpell() = 0;
	virtual Spell * getSpell() = 0;
	virtual void manaRefill() = 0;
};

//---------------------------------------------------------------------------------------

class Warlock : public Hero
{
	int spellPower;

public:
	Warlock();
	Warlock(sf::Texture * texture, sf::Vector2u imageCount, float switchTime);
	~Warlock() {}

	virtual bool castSpell() final;
	virtual Spell * getSpell() final;
	virtual void manaRefill() final;
};

//---------------------------------------------------------------------------------------

class Mage : public Hero
{
	int spellPower;

public:
	Mage();
	Mage(sf::Texture * texture, sf::Vector2u imageCount, float switchTime);
	~Mage() {}

	virtual bool castSpell() final;
	virtual Spell * getSpell() final;
	virtual void manaRefill() final;
};

//---------------------------------------------------------------------------------------

class Priest : public Hero
{
	int spellPower;

public:
	Priest();
	Priest(sf::Texture * texture, sf::Vector2u imageCount, float switchTime);
	~Priest() {}

	virtual bool castSpell() final;
	virtual Spell * getSpell() final;
	virtual void manaRefill() final;
};

//---------------------------------------------------------------------------------------

#endif