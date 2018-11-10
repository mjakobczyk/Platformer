#ifndef ENTITY_H_
#define ENTITY_H_

// Klasa jednostki, okre�la jak ma wygl�d pojedynczy element gry
class Entity
{
protected:
	bool dead; // Okre�la czy dana jednostka mo�e funkcjonowa� w grze
	bool canMove; // Okre�la czy dana jednostka mo�e si� porusza�
	int ID; // Nadaje jednostce numer do przysz�ej ewentualnej identyfikacji

	sf::Clock clock; // S�u�y do odmierzania czasu mi�dzy interakcjami
	sf::Texture * texture; // Wska�nik na tekstur� postaci
	sf::Sprite sprite; // Do niego �adowana jest tekstura
	sf::Vector2i coords; // Okresla aktualn� pozycj� jednostki w wersji kafelkowej
	sf::Vector2f coordsFlt; // Okre�la aktualn� pozycj� jednostki w wersji rzeczywistej

public:
	Entity();
	virtual ~Entity();

	int getID() { return this->ID; } // Zwracana identyfikator jednostki
	sf::Clock getClock() { return this->clock; }
	sf::Texture * getTexture() { return this->texture; } // Zwraca wska�nik na tekstur� jendostki
	sf::Sprite getSprite() { return this->sprite; } // Zwraca sprite jednostki
	sf::Vector2i getCoords(); // Zwraca pozycj� jednostki w wersji kafelkowanej
	sf::Vector2f getPosition(); // Zwraca rzeczywist� pozycj� jednostki

	void setTexture(sf::Texture*); // Ustawia tekstur� jednostki
	void setPosition(sf::Vector2f); // Ustawia pozycj� jednostki
	void setCoords(sf::Vector2i); // Ustawia kafelkow� pozycj� jednostki

	bool isStable(); // Sprawdza, czy jednostka jest jednostk� sta��
	bool isMoveable(); // Sprawdza, czy jednostka jest jednostk� dynamiczn�
	bool isDead(); // Sprawdza, czy jednostka mo�e by� na mapie
	bool destroy(); // Niszczy obiekt

	virtual bool checkCollision(Entity *); // Sprawdza kolizje z inn� jednostk�, mo�e wygl�da� r�nie dla klas potomnych
	virtual bool collision(Entity *) = 0; // Okre�la co si� dzieje podczas kolizji
	virtual void update(float) = 0; // Spos�b aktualizacji jednostki
};

#endif