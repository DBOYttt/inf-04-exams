

#include <iostream>
#include <string>

/************************************************
 klasa: notatka1
 opis: Klasa reprezentująca notatkę z tytułem i treścią
 pola:
 title - przechowuje tytuł notatki
 note - przechowuje treść notatki
 licznik - statyczny licznik instancji klasy
 id - unikalny identyfikator notatki
 autor: DBOYttt
************************************************/


class notatka1 {
private:
    static int licznik;
    int id;
public:
    std::string title;
    std::string note;

    notatka1(const std::string& t, const std::string& n) : title(t), note(n) {
        id = ++licznik;
    }

    void wysnote() const {
        std::cout << "Tysul: " << title << "\nTresc: " << note << "\n";
    }

    void diagnostyka() const {
        std::cout << "ID: " << id << "; Tytuł: " << title << "; Treść: " << note << "; Licznik: " << licznik << std::endl;
    }

};

int notatka1::licznik = 0;

int main()
{
    notatka1 n1("title1", "note note1111");
    notatka1 n2("title2", "note note2222");

    std::cout << "Wyświetlam Notatke 1: \n" << "\n";
    n1.wysnote();
    std::cout << "diagnostic" << "\n";
    n1.diagnostyka();

    std::cout << "Wyświetlam Notatke 2: \n" << "\n";
    n2.wysnote();
    std::cout << "diagnostic" << "\n";
    n2.diagnostyka();

    return 0;
}
