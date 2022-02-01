#include "PrimitiveRenderer.h"

void PrimitiveRenderer::draw_rectangle(int x, int y, int size, Color color)
{
    al_draw_filled_rectangle(x, y, x + size, y + size, get_color(color));
}
void PrimitiveRenderer::draw_rectangle(int x, int y, int size, Color color, int frame_size)
{
    al_draw_rectangle(x + frame_size / 2, y + frame_size / 2, x + size - frame_size / 2, y + size - frame_size / 2, get_color(color), frame_size);
}

void PrimitiveRenderer::draw_rectangle(int x, int y, int size, Color color, int frame_size, Color frame_color)
{
    draw_rectangle(x, y, size, color);
    draw_rectangle(x, y, size, frame_color, frame_size);
}

void PrimitiveRenderer::draw_cirlce(int x, int y, int promien, Color kolor)
{
    al_draw_filled_circle(x, y, promien, get_color(kolor));
}

void PrimitiveRenderer::draw_cirlce(int x, int y, int promien, Color kolor, int frame_size)
{
   
    al_draw_circle(x, y, promien, get_color(kolor), frame_size);
}

void PrimitiveRenderer::draw_cirlce(int x, int y, int r, Color color, int frame_size, Color frame_color)
{
    draw_cirlce(x, y, r, color);
    draw_cirlce(x, y, r, frame_color, frame_size);
}

ALLEGRO_COLOR PrimitiveRenderer::get_color(enum Color kol)
{
    switch (kol)
    {
    case(BIALY):
        return al_map_rgb(255, 255, 255);
    case(SZARY_JASNY):
        return al_map_rgb(183, 183, 183);
    case(SZARY_CIEMNY):
        return al_map_rgb(120, 120, 120);
    case(CZARNY):
        return al_map_rgb(0, 0, 0);
    case(ZIELONY):
        return al_map_rgb(43, 255, 0);
    case(ZIELONY_JASNY):
        return al_map_rgb(145, 255, 0);
    case(ZIELONY_CIEMNY):
        return al_map_rgb(10, 112, 7);
    case(ROZOWY):
        return al_map_rgb(255, 0, 230);
    case(CZERWONY):
        return al_map_rgb(255, 0, 0);
    case(ZOLTY):
        return al_map_rgb(255, 255, 0);
    case(POMARANCZOWY):
        return al_map_rgb(255, 171, 0);
    case(NIEBIESKI):
        return al_map_rgb(0, 137, 255);
    case(NIEBIESKI_JASNY):
        return al_map_rgb(0, 247, 255);
    case(NIEBIESKI_CIEMNY):
        return al_map_rgb(0, 0, 255);
    case(FIOLETOWY):
        return al_map_rgb(145, 0, 255);
    case(BRAZOWY):
        return al_map_rgb(121, 80, 40);
    }
}
