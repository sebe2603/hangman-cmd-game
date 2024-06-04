#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>

class Word
{
private:
    std::string fword;
    std::vector<std::string> flist;
    std::random_device rd;
public:
    Word(const std::string& word = " ", const std::vector<std::string>& list = std::vector<std::string>()) : fword{ word }, flist{ list }
    {}
    std::string get_word(void) const { return fword; }
    void set_word(const std::string& word) { fword = word; }
    std::vector<std::string> LoadWords()
    {
        std::fstream file("C:\\words.txt");
        if (file.is_open())
        {
            while (std::getline(file, fword))
            {
                flist.push_back(fword); //odczytywanie wyrazow z pliku
            }
            file.close();
        }
        return flist;
    }
    std::string WordDraw()
    {
        LoadWords();
        std::uniform_int_distribution<int> random(0, flist.size() - 1);
        return fword = flist[random(rd)]; //losowanie jednego wyrazu
    }
};

class Game
{
private:
    char fletter;
    std::vector<char> fletters;
    std::string finput;
    std::vector<char> fdisplay;
    int fstrikes;
    int fword_size;
    int fcheck;
    int fwincheck;
    int finput_check;
public:
    Game(const char& letter = ' ', const std::vector<char>& letters = std::vector<char>(), const std::string& input = "", const std::vector<char>& display = std::vector<char>(), int strikes = 0, int word_size = 0, int check = 0, int wincheck = 0, int input_check = 0) : fletter{ letter }, fletters{ letters }, finput{ input }, fdisplay{ display }, fstrikes{ strikes }, fword_size{ word_size }, fcheck{ check }, fwincheck{ wincheck }, finput_check{ input_check }
    {}
    void print_vector(std::vector<char> v)
    {
        for (int x = 0; x < v.size(); x++)
        {
            std::cout << v[x]; //wypisywanie wektora
        }
    }
    std::vector<char> WordSelect(std::string word)
    {
        fword_size = word.size() - 1;
        for (int x = 0; x <= fword_size; x++)
        {
            fletters.push_back(word.front()); //zapisanie wybranego wyrazu jako wektor
            word.erase(0, 1);
        }
        return fletters;
    }
    void display()
    {
        for (int x = 0; x <= fword_size; x++)
        {
            fdisplay.push_back('_'); //wyswietlenie ilosci znakow w wyrazie
        }
    }
    void ui() //interfejs w konsoli
    {
        system("cls");
        std::cout << "           ";
        print_vector(fdisplay);
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        drawning();
        std::cout << "\n        strikes: " << fstrikes << "/10";
        if (finput_check != 0)
        {
            std::cout << "\n          wrong input";
        }
        std::cout << "\n      choose a letter: ";
    }
    int input()
    {
        std::getline(std::cin, finput);
        if (finput.size() == 1 && isalpha(finput.front()) == 2) //weryfikacja danych wejsciowych
        {
            fletter = finput.front();
            return 0;
        }
        else
        {
            finput_check++;
            return 1;
        }
    }
    void reset_checks() //reset wartosci weryfikacyjnych
    {
        fcheck = 0;
        fwincheck = 0;
        finput_check = 0;
    }
    void letter_compare()
    {
        for (int x = 0; x <= fword_size; x++)
        {
            if (fletter == fletters[x]) //sprawdzenie czy wpisana litera znajduje sie w wyrazie
            {
                fdisplay[x] = fletter; //odkrycie odganietej litery
                fcheck++;
            }
        }
    }
    void strikes()
    {
        if (fcheck == 0)
        {
            fstrikes++; //odganiecie blednej litery
        }
    }
    int win_check()
    {
        for (int x = 0; x <= fword_size; x++)
        {
            if (fdisplay[x] != fletters[x]) //sprawdzenie czy wszystkie litery zostaly zgadniete
            {
                fwincheck++;
            }
        }
        if (fwincheck == 0)
        {
            system("cls");
            std::cout << "           ";
            print_vector(fletters);
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            drawning();
            std::cout << "\n           you won!\n";
            return 1;
        }
        return 0;
    }
    int lose_check()
    {
        if (fstrikes == 10) //koniec gry
        {
            system("cls");
            std::cout << "           ";
            print_vector(fletters);
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            drawning();
            std::cout << "\n          you lost\n";
            return 1;
        }
        return 0;
    }
    void drawning() //rysunki wisielca
    {
        if (fstrikes == 0)
        {
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
        }
        if (fstrikes == 1)
        {
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "      -----------------\n";
            std::cout << "      |               | \n";
        }
        if (fstrikes == 2)
        {
            std::cout << "\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "      -----------------\n";
            std::cout << "      |               | \n";
        }
        if (fstrikes == 3)
        {
            std::cout << "              -------\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "      -----------------\n";
            std::cout << "      |               | \n";
        }
        if (fstrikes == 4)
        {
            std::cout << "              -------\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |     O\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "      -----------------\n";
            std::cout << "      |               | \n";
        }
        if (fstrikes == 5)
        {
            std::cout << "              -------\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |     O\n";
            std::cout << "              |     |\n";
            std::cout << "              |     |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "      -----------------\n";
            std::cout << "      |               | \n";
        }
        if (fstrikes == 6)
        {
            std::cout << "              -------\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |     O\n";
            std::cout << "              |    /|\n";
            std::cout << "              |     |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "      -----------------\n";
            std::cout << "      |               | \n";
        }
        if (fstrikes == 7)
        {
            std::cout << "              -------\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |     O\n";
            std::cout << "              |    /|\\ \n";
            std::cout << "              |     |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "      -----------------\n";
            std::cout << "      |               | \n";
        }
        if (fstrikes == 8)
        {
            std::cout << "              -------\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "              |     O\n";
            std::cout << "              |    /|\\ \n";
            std::cout << "              |     |\n";
            std::cout << "              |    / \n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "      -----------------\n";
            std::cout << "      |               | \n";
        }
        if (fstrikes == 9)
        {
            {
                std::cout << "              -------\n";
                std::cout << "              |\n";
                std::cout << "              |\n";
                std::cout << "              |     O\n";
                std::cout << "              |    /|\\ \n";
                std::cout << "              |     |\n";
                std::cout << "              |    / \\\n";
                std::cout << "              |\n";
                std::cout << "              |\n";
                std::cout << "      -----------------\n";
                std::cout << "      |               | \n";
            }
        }
        if (fstrikes == 10)
        {
            std::cout << "              -------\n";
            std::cout << "              |     |\n";
            std::cout << "              |     |\n";
            std::cout << "              |     O\n";
            std::cout << "              |    /|\\ \n";
            std::cout << "              |     |\n";
            std::cout << "              |    / \\\n";
            std::cout << "              |\n";
            std::cout << "              |\n";
            std::cout << "      -----------------\n";
            std::cout << "      |               | \n";
        }
    }
    void Play() //gra
    {
        display();
        while (1)
        {
            ui();
            if (input() == 1)
            {
                continue;
            }
            reset_checks();
            letter_compare();
            strikes();
            if (win_check() == 1)
            {
                break;
            }
            if (lose_check() == 1)
            {
                break;
            }
        }
    }
};

int main()
{
    Word w;
    Game g;
    w.WordDraw();
    g.WordSelect(w.get_word());
    g.Play();
    return 0;
}
