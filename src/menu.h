#ifndef MENU_H_
#define MENU_H_

#define MAIN_MENU_BUTTONS_QUANTITY 3
#define PLAY_BUTTONS_QUANTITY 5
#define OPTIONS_BUTTONS_QUANTITY 5
#define NEXT_LEVEL_BUTTONS_QUANTITY 2
#define GAMEOVER_BUTTONS_QUANTITY 1
#define ENDGAME_BUTTONS_QUANTITY 4

// Maszyna stanu Menu
enum MenuState { MAIN_MENU = 0, PLAY = 1, OPTIONS = 2, EXIT = 3, NEXT = 4, GAME_OVER = 5, OUT = 6};

// Klasa menu gry
class Menu
{
protected:
	int buttonId; // Numer aktualnie wybranego przycisku
	float deltaTime; // R�nica w czasie zczytywana pomi�dzy wyobrem opcji
	bool heroSpecSet; // Flaga przekazywana do silnika czy zosta�a wybrana specjalizacja gracza
	
	std::vector<Button*> buttons; // Wektor 1d przycisk�w
	sf::Texture backgroundT; // Tekstura t�a menu
	sf::Sprite backgroundS; // Sprite t�a menu
	sf::Font font; // Czcionka wykorzystywana przy wy�wietlaniu przycisk�w

	heroSpec whichSpecSet; // Typ wyliczeniowy na specjalizacj� gracza
	MenuState menuState; // Typ wyliczeniowy na stan menu

public:
	Menu();
	virtual ~Menu();

	int getButtonId(); // Pobiera ID wybranego przycisku
	sf::Font getFont(); // Pobiera wykorzystywan� czcionk�
	heroSpec getChosenSpec(); // Pobiera specjalizacj� bohatera
	MenuState getMenuState(); // Pobiera aktualny stan menu

	bool isSpecSet(); // Sprawdza czy zosta�a wybrana specjalizacja gracza
	void setMenuState(MenuState); // Ustawia stan menu

	virtual void moveUp(); // Przechodzi na przycisk wy�ej
	virtual void moveDown(int); // Przechodzi na przycisk ni�ej

	virtual void run(sf::RenderWindow &) = 0; // Rozpoczyna dzia�anie menu
	virtual void draw(sf::RenderWindow &) = 0; // Rysuje menu
};

//---------------------------------------------------------------------------------------

class MainMenu : public Menu
{
public:
	MainMenu();
	~MainMenu();

	virtual void run(sf::RenderWindow &) final; // Rozpoczyna dzia�anie menu
	virtual void draw(sf::RenderWindow &) final; // Rysuje menu
};

//---------------------------------------------------------------------------------------

class Play : public Menu
{
public:
	Play();
	~Play();

	virtual void moveUp();
	virtual void moveDown(int);

	virtual void run(sf::RenderWindow &) final;
	virtual void draw(sf::RenderWindow &) final;
};

//---------------------------------------------------------------------------------------

class Options : public Menu
{
public:
	Options();
	~Options();

	virtual void run(sf::RenderWindow &) final;
	virtual void draw(sf::RenderWindow &) final;
};

//---------------------------------------------------------------------------------------

class NextLevel : public Menu
{
	std::vector <Enemy*> visualisation;

public:
	NextLevel(int);
	~NextLevel();

	virtual void run(sf::RenderWindow &) final;
	virtual void draw(sf::RenderWindow &) final;
};

//---------------------------------------------------------------------------------------

class EndGame : public Menu
{
	std::vector <Stable*> stableObjects;

public:
	EndGame(int, float);
	~EndGame();

	virtual void run(sf::RenderWindow &) final;
	virtual void draw(sf::RenderWindow &) final;
};

//---------------------------------------------------------------------------------------

#endif