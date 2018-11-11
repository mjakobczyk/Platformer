#ifndef WEKTOR_H_
#define WEKTOR_H_

template <typename T> std::ostream & operator<< (std::ostream & str, const Wektor<T> & w);

template <typename T>
class Wektor
{
	T * values;
	int size;
	int capacity;

public:
	Wektor();
	Wektor(int);
	Wektor(const Wektor &);
	~Wektor();

	int pobierzWielkosc() { return size; }
	void dodaj(T&);
	void dodaj(T*);
	int szukaj(const T&);
	bool usun(T&);
	bool zamien(T&, T&);
	bool zamien(T*&, T*&);
	bool czyPusty();

	Wektor & operator=(const Wektor&);
	T & operator[](int idx) const;

	friend std::ostream & operator<< <T> (std::ostream&, const Wektor<T>&);
};

//_______________________________________________________________________

// Konstruktor bezargumentowy
template <typename T>
Wektor<T>::Wektor()
{
	values = new T[16];
	size = 0;
	capacity = 16;
}

//_______________________________________________________________________

// Konstruktor z argumentem d�ugo�ci wektora
template <typename T>
Wektor<T>::Wektor(int val)
{
	T = new T(val);
	size = 0;
	capacity = val;
}

//_______________________________________________________________________

// Konstruktor inicjalizacuj�cy jeden wektor innym wektorem
template <typename T>
Wektor<T>::Wektor(const Wektor & w)
{
	this->size = w->size;
	this->capacity = w->capacity;
	for (int i = 0; i < this->size; ++i)
		this->values[i] = w->values[i];
}

//_______________________________________________________________________

// Destruktor
template <typename T>
Wektor<T>::~Wektor()
{
	delete[] values;
	values = nullptr;
	size = 0;
	capacity = 0;
}

//_______________________________________________________________________

// Metoda dodaj�ca nowy element do wektora
template <typename T>
void Wektor<T>::dodaj(T & val)
{
	// Je�eli w danym momencie rozmiar wektora przewy�sza jego mo�liwo�ci pod wzgl�dem
	// zaalokowanej pami�ci, to nale�y zwi�kszy� jego rozmiar. Za ka�dym razem zwi�kszany
	// jest on dwukrotnie powi�kszany. Aby mechanizm dzia�a� poprawnie, tworzymy tymczasow�
	// tablic� element�w, do kt�rej przepisujemy zawarto�� wektora, na rzecz kt�reg� jest
	// wywo�ywana metoda. Nast�pnie usuwamy star� zawarto�� i przypisujemy do wska�nika
	// 'values' 2-krotnie powiekszon� tablic�.
	if (size >= capacity && capacity > 0)
	{
		capacity = capacity * 2;
		T * temp = new T[capacity];
		for (int i = 0; i < size; ++i)
		{
			temp[i] = this->values[i];
		}
		if (values) delete[] values;
		values = temp;
	}

	values[size] = val;
	++size;

	return;
}

//_______________________________________________________________________

// Metoda dodaj�ca nowy element do wektora
template <typename T>
void Wektor<T>::dodaj(T * val)
{
	// Je�eli w danym momencie rozmiar wektora przewy�sza jego mo�liwo�ci pod wzgl�dem
	// zaalokowanej pami�ci, to nale�y zwi�kszy� jego rozmiar. Za ka�dym razem zwi�kszany
	// jest on dwukrotnie powi�kszany. Aby mechanizm dzia�a� poprawnie, tworzymy tymczasow�
	// tablic� element�w, do kt�rej przepisujemy zawarto�� wektora, na rzecz kt�reg� jest
	// wywo�ywana metoda. Nast�pnie usuwamy star� zawarto�� i przypisujemy do wska�nika
	// 'values' 2-krotnie powiekszon� tablic�.
	if (size >= capacity && capacity > 0)
	{
		capacity = capacity * 2;
		T * temp = new T[capacity];
		for (int i = 0; i < size; ++i)
		{
			temp[i] = this->values[i];
		}
		if (values) delete[] values;
		values = temp;
	}

	values[size] = *val;
	++size;

	return;
}

//_______________________________________________________________________

// Metoda wyszukuj�ca element zwraca jego indeks, je�li istnieje
template <typename T>
int Wektor<T>::szukaj(const T & val)
{
	// W p�tli iterujemy po wszystkich elementach wektora por�wnuj�c ich
	// warto�ci z warto�ci� podan� jako argument metody. Metoda zwraca
	// indeks elementu w przypadku jego znalezienia. Je�li element nie
	// zosta� znaleziony, to zwracan� warto�ci� jest -1.
	for (int i = 0; i < size; ++i)
	{
		if (values[i] == val)
			return i;
	}

	return -1;
}

//_______________________________________________________________________

// Metoda usuwaj�ca wyznaczony element z wektora
template <typename T>
bool Wektor<T>::usun(T & val)
{
	// Przed usuni�ciem elementu nale�y sprawdzi�, czy faktycznie nale�y
	// on do kontenera. Z tego powodu wywo�ywana jest metoda szukaj().
	if (szukaj(val) == -1) return false;

	// Je�li znaleziono element nast�puje jeszcze jedno sprawdzenie czy
	// indeks ten jest poprawny. W tym celu musi by� r�wny co najmniej 0,
	// a conajwy�ej tyle, co wielko�� kontenera - 1. Je�li sprawdzenie si�
	// powiedzie to nast�puje przepisanie wszystkich element�w o jedno
	// miejsce w lewo. Po wykonanych operacjach nast�puje dekrementacja
	// wielko�ci wektora.
	if (szukaj(val) >= 0 && szukaj(val) < size)
	{
		for (int i = szukaj(val) + 1; i < size; ++i)
			values[i - 1] = values[i];
		--size;
		return true;
	}

	// W ca�ej reszcie przypadk�w je�eli indeks si� nie zgadza, to metoda
	// zwraca fa�sz.
	return false;
}

//_______________________________________________________________________

// Metoda zamieniaj�ca miejscami dwa elementy wektora
template <typename T>
bool Wektor<T>::zamien(T & val1, T & val2)
{
	// Najpierw nast�puje sprawdzenie czy elementy nale�� do wektora.
	// Je�eli ich indeksy s� r�wne -1 to znaczy, �e nie s� elementami
	// kontera.
	if (szukaj(val1) <= -1 && szukaj(val2) <= -1) return false;

	T temp;

	// Je�eli indeksy po kolejnym sprawdzeniu si� zgadzaj�, to nast�puje
	// zamiana warto�ci element�w o podanych indeksach.
	if (szukaj(val1) >= 0 && szukaj(val1) < size &&
		szukaj(val2) >= 0 && szukaj(val2) < size)
	{
		temp = val1;
		values[szukaj(val1)] = val2;
		values[szukaj(val2)] = temp;

		return true;
	}

	// W ca�ej reszcie przypadk�w zwracamy fa�sz.
	return false;
}

//_______________________________________________________________________

// Metoda zamieniaj�ca miejscami dwa elementy wektora
template <typename T>
bool Wektor<T>::zamien(T * & val1, T * & val2)
{
	// Najpierw nast�puje sprawdzenie czy elementy nale�� do wektora.
	// Je�eli ich indeksy s� r�wne -1 to znaczy, �e nie s� elementami
	// kontera.
	if (szukaj(val1) <= -1 && szukaj(val2) <= -1) return false;

	T * temp = nullptr;

	// Je�eli indeksy po kolejnym sprawdzeniu si� zgadzaj�, to nast�puje
	// zamiana warto�ci element�w o podanych indeksach.
	if (szukaj(val1) >= 0 && szukaj(val1) < size &&
		szukaj(val2) >= 0 && szukaj(val2) < size)
	{
		*temp = *val1;
		*(values[szukaj(val1)]) = *val2;
		*(values[szukaj(val2)]) = *temp;

		return true;
	}

	// W ca�ej reszcie przypadk�w zwracamy fa�sz.
	return false;
}

//_______________________________________________________________________

// Metoda sprawdzaj�ca czy kontener zawiera jakie� dane
template <typename T>
bool Wektor<T>::czyPusty()
{
	if (size <= 0) return true;
	else return false;
}

//_______________________________________________________________________

// Operator= przypisuj�cy obiekt innemu obiektowi
template <typename T>
Wektor<T> & Wektor<typename T>::operator=(const Wektor & w)
{
	// Przypisuj�c jeden wektor do drugiego najpierw usuwamy star�
	// zawarto�� pierwszego z nich. Nast�pnie alokujemy tyle pami�ci, ile
	// jest potrzebnej do zapisania danych z drugiego wektora. Na koniec,
	// iteruj�c po nim, przypisujemy wszystkie warto�ci element�w.

	delete[] values;
	this->w = new T[w.size];
	this->size = w->size;

	for (int i = 0; i < size; ++i)
		this->values[i] = w->values[i];

	return *this;
}

//_______________________________________________________________________

// Operator[] indeksuj�cy elementy wektora
template <typename T>
T & Wektor<T>::operator[](int idx) const
{
	// Je�eli indeks jest poprawny, to zwracamy warto�� tego elementu.

	if (idx >= 0 && idx < size)
		return values[idx];
}

//_______________________________________________________________________

// Operator << do wypisywania zawarto�ci wektora
template <typename T>
std::ostream & operator<< (std::ostream & str, const Wektor<T> & w)
{
	for (int i = 0; i < w.size; ++i)
		str << i + 1 << ". " << w.values[i] << std::endl;
	str << std::endl;

	return str;
}

//_______________________________________________________________________
#endif