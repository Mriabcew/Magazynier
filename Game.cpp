#include "Game.h"

Game::Game(Display* display,bool dev)
{
	set_fps(60);
	this->display = display;
	this->dev = dev;
}

void Game::loop()
{
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / fps);
	al_install_keyboard();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display->get_display()));

	al_start_timer(timer);
	int style;
	
	int opt;
	do
	{
		cout << "select a level 1-6" << endl;
		cin >> opt;
	} while (opt < 1 || opt>6);

	string level = "poziom" + std::to_string(opt);

	if (dev == false)
	{
		do
		{
			cout << "Choose a texture style:" << endl;
			cout << "1.Dungeon" << endl;
			cout << "2.Space" << endl;
			cout << "3.Warehouse" << endl;
			cin >> style;
		} while (style < 1 || style>3);
	}
	else if (dev == true)
		style = 1;
	Map* map = new Map(display, style ,dev);

restart:
	
	map->load_map(level,display);
	
	while (1)
	{
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);


		if (events.type == ALLEGRO_EVENT_TIMER)
		{
			al_clear_to_color(PrimitiveRenderer::get_color(PrimitiveRenderer::CZARNY));
			map->draw();






			display->refresh();

			if (map->win())
			{
				if (al_show_native_message_box(display->get_display(), "WIN",
					"Congratulations",
					"Click Ok to contiunue or cencel to exit"
					, NULL, ALLEGRO_MESSAGEBOX_OK_CANCEL) == 2)
				{
					exit(0);
				}
				else
				{
					cout << "WIN" << endl;
					return;
				}
			}
		}
		else if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			exit(0);
		}
		else if (events.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_DOWN:
				map->make_move(Map::DOWN);
				break;
			case ALLEGRO_KEY_UP:
				map->make_move(Map::UP);
				break;
			case ALLEGRO_KEY_LEFT:
				map->make_move(Map::LEFT);
				break;
			case ALLEGRO_KEY_RIGHT:
				map->make_move(Map::RIGHT);
				break;
			case ALLEGRO_KEY_R:
				goto restart;
			case ALLEGRO_KEY_ESCAPE:
				return;

			}
		}
	}
	al_destroy_event_queue(event_queue);
	return;
}

void Game::set_fps(int fps)
{
	this->fps = fps;
}
