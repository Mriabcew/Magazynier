#include <allegro5/allegro_primitives.h>
#include <iostream>

class PrimitiveRenderer{
private:


public:
        enum Color
        /*
            Baza kolorow
        */
        {
            BIALY, SZARY_JASNY, SZARY_CIEMNY, CZARNY, ZIELONY, ZIELONY_JASNY, ZIELONY_CIEMNY, ROZOWY, CZERWONY, ZOLTY,
            POMARANCZOWY, NIEBIESKI, NIEBIESKI_JASNY, NIEBIESKI_CIEMNY, FIOLETOWY, BRAZOWY
        };
        static void draw_rectangle(int, int, int, Color);
        static void draw_rectangle(int, int, int, Color, int);
        static void draw_rectangle(int, int, int, Color, int, Color);


        static void narysuj_kolo(int, int, int, Color);
        static void narysuj_kolo(int, int, int, Color, int);
        static void narysuj_kolo(int, int, int, Color, int, Color);


        static ALLEGRO_COLOR get_color(enum Color);
        /*
            Funkcja zwracajaca kolor w kodzie rgb
        */




};
