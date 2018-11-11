#ifndef ANIMATION_H_
#define ANIMATION_H_

// Klasa animacji, wspomaga aktualizacje sprite'a w czasie dla obiektu
class Animation
{
protected:
	sf::Vector2u imageCount; // Okre�la rozmiar podawanej tekstury
	sf::Vector2u currentImage; // Okre�la aktualnie za�adowan� cz�� tekstury
	sf::IntRect uvRect; // Cz�� tekstury, kt�r� aktualnie potrzebujemy

	float totalTime; // Ca�kowity czas zmiany tekstury, nie mo�e przekracza� switch time'u
	float switchTime; // Okre�la cz�sto�� zmian tekstury postaci
	bool forward; // Okre�la czy animacja pobiera kolejne cz�ci tekstury w praw� stron�


public:
	Animation();
	Animation(sf::Texture*);
	Animation(sf::Vector2u, float);
	Animation(sf::Texture*, sf::Vector2u, float);
	~Animation();

	void setSwitchTime(float); // Ustawia cz�sto�� aktualizacji animacji
	void setSize(sf::Texture); // Ustawia rozmiar animacji na podstawie tekstury
	void setImageCount(sf::Vector2u); // Okre�la ilo�� podawanych klatek
	bool isForward(); // Sprawdza czy animacja pobiera klatki do przodu

	void update(int, float, bool); // Metoda aktualizuj�ca animacj�
	sf::IntRect getIntRect() { return this->uvRect; } // Metoda zwracaj�ca aktualn� cz�� tekstury
};

#endif