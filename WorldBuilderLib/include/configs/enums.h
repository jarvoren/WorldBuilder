#ifndef H_ENUMS_H
#define H_ENUMS_H

/* May be needed to have a tile work on overworld and all other levels of detail */
enum TileLevel
{
	OVERWORLD,
	PLACE,
	SPECIFIC_PLACE,
	MINIATURE
};

/* Temporary enum representing tile type - in future change to configurable one */

enum TileType
{
	WATER,
	LANDMASS,
	MOUNTAIN
};

/* Tileset type that decides which generator will be used and how grid will look like */
enum TilesetType
{
	SQUARE,
	HEXAGONAL,
	FREE_DRAW, /* In far future the generation of enviroments with unusual borders may be added */
	TRIANGLE /* Probably never gonna see that comeing */
};

#endif // H_ENUMS_H