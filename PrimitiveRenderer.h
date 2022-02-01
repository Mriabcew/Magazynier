#include <allegro5/allegro_primitives.h>
#include <iostream>

class PrimitiveRenderer{
private:


public:
        enum Color
        /**
        * Color base
        **/
        {
            BIALY, SZARY_JASNY, SZARY_CIEMNY, CZARNY, ZIELONY, ZIELONY_JASNY, ZIELONY_CIEMNY, ROZOWY, CZERWONY, ZOLTY,
            POMARANCZOWY, NIEBIESKI, NIEBIESKI_JASNY, NIEBIESKI_CIEMNY, FIOLETOWY, BRAZOWY
        };

        /**
        * draw_squere
        * @param int x (left corner x)
        * @param int y (left corner y) 
        * @param int size (size of squere)
        * @param Color color type from base
        * fuction draw rectangle(filled)
        **/
        static void draw_rectangle(int, int, int, Color);
        /**
        * draw_squere
        * @param int x (left corner x)
        * @param int y (left corner y)
        * @param int size (size of squere)
        * @param Color color type from base
        * @param int size of frame
        * fuction draw rectangle(not filled)
       **/
        static void draw_rectangle(int, int, int, Color, int);
        /**
        * draw_squere
        * @param int x (left corner x)
        * @param int y (left corner y)
        * @param int size (size of squere)
        * @param Color color type from base
        * @param int size of frame
        * @param Color color of the frame
        * fuction draw rectangle(filled with frame)
        **/
        static void draw_rectangle(int, int, int, Color, int, Color);

        /**
        * draw_circle
        * @param x
        * @param y
        * @param r
        * @param Color
        * function draw circle (filled)
        **/
        static void draw_cirlce(int, int, int, Color);
        /**
        * draw_circle
        * @param x
        * @param y
        * @param r
        * @param Color
        * @param frame_size
        * function draw circle (not filled) with frame
        **/
        static void draw_cirlce(int, int, int, Color, int);
        /**
        * draw_circle
        * @param x
        * @param y
        * @param r
        * @param Color
        * @param frame_size
        * @param frame_color
        * function draw circle (filled) with frame in different color
        **/
        
        static void draw_cirlce(int, int, int, Color, int, Color);

        /*
        * get_color
        * @param color name of color from base
        * return color in rgb allegro code
        */
        static ALLEGRO_COLOR get_color(enum Color);
};
