#include <grid_elements/tile.h>

/* DEBUG checking the generation transfer to world level */
Tile::Tile(uint32_t x, uint32_t y, uint32_t seed, Tile*** tileset, uint32_t size_x, uint32_t size_y)
{
	coordinates.pos_x = x;
	coordinates.pos_y = y;
	level = OVERWORLD;
	srand(seed);
	int w_chance = rand() % 7;
	int m_chance = rand() % 3;
	int l_chance = rand() % 5;

	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (x > 0 && y > 0 && x < size_x-1 && y < size_y-1)
			{
				if (tileset[x+i][y+j] != NULL)
				{
					switch (tileset[x + i][y + j]->type)
					{
					case WATER:
						w_chance++;
						break;
					case LANDMASS:
						l_chance++;
						break;
					case MOUNTAIN:
						m_chance++;
						break;
					default:
						break;
					}
				}
			}
		}
	}
	
	if (w_chance > l_chance && w_chance > m_chance) 
	{
		type = WATER; 
	} 
	else if (l_chance > m_chance) 
	{
		type = LANDMASS; 
	}
	else
	{
		type = MOUNTAIN; 
	}
}

/* TODO TILE CREATOR - PROBABLY FACTORY THIS IS JUST A SAMPLE */
Tile::Tile()
{
	coordinates.pos_x = 0;
	coordinates.pos_y = 0;
	level = OVERWORLD;
	type = WATER;
}

Tile::~Tile()
{

}