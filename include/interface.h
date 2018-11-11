#ifndef INTERFACE_H_
#define INTERFACE_H_

#define INTERFACE_BUTTONS_QUANTITY 8
#define INTERFACE_GRAPHICS_QUANTITY 3

// Klasa interfejsu gry, okre�la jak ma wygl�da� ekran podczas gry
class Interface
{
	sf::Font font; // Czciocnka wypisywanego tekstu
	Hero *& hero; // Uchwyt do oryginalnego gracza

	std::vector <Button*> buttons; // Wektor 1d przycisk�w
	std::vector <sf::Texture*> textures; // Wektor 1d u�ywanych tekstur
	std::vector <sf::Sprite> sprites; // Wektor 1d sprite'�w
	
public:
	Interface (Hero *&);
	~Interface();

	void draw(sf::RenderWindow &); // Rysuje interfejs
	void update(sf::Time, float); // Aktualizuje interfejs
};

#endif