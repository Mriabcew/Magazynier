#include "Engine.h"

Engine::Engine(bool dev)
{
	allegro_start();

	e = new Display();
	this->dev = dev;

	for(;;)
	{
		Menu *m = new Menu(e);
		if (m->get_opt() == 1)
		{
			Game* g = new Game(e,dev);
			g->loop();
		}
		else if (m->get_opt()==999)
		{
			return;
		}
	}
}


void Engine::allegro_start()
{
	if (!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL, "Nie udalo sie zainicjowac Allegro 5", NULL, NULL);
		cout << endl << "Nie udalo sie zainicjowac Allegro 5" << endl;
		return;
	}
	if (!al_init_primitives_addon())
	{
		cout << "Nie udalo sie dodac primitives_addon";
		return;
	}
	
	if (!al_init_image_addon())
	{
		al_show_native_message_box(NULL, NULL, NULL, "Nie udalo sie zainicjowac image_addon", NULL, NULL);
		cout << endl << "Nie udalo sie zainicjowac image_addon" << endl;
		return;
	}
}