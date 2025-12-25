#ifndef H_ENUMS_H
#define H_ENUMS_H

/* May be needed to have a tile work on overworld and all other levels of detail */
enum TileLevel { OVERWORLD, PLACE, SPECIFIC_PLACE, MINIATURE };

/* Temporary enum representing tile type - in future change to configurable one */

enum TileType { WATER, LANDMASS, MOUNTAIN };

/* Tileset type that decides which generator will be used and how grid will look like */
enum TilesetType {
	SQUARE,
	HEXAGONAL,
	FREE_DRAW, /* In far future the generation of enviroments with unusual borders may be added */
	TRIANGLE   /* Probably never gonna see that comeing */
};

/* Planet type de facto overwolrld overall theme. Used by generator in tileset creation */
enum WorldPlanetType {
	CARBON,
	CORELESS,
	DESERT,
	DWARF,
	EGGSHELL,
	HYCEAN,
	ICE,
	IRON,
	LAVA,
	OCEAN,
	EARTH,
	ISLAND
};

enum NumpadDirections {
	DOWNLEFT = 1,
	DOWN = 2,
	DOWNRIGHT = 3,
	LEFT = 4,
	NOONE = 5,
	RIGHT = 6,
	UPLEFT = 7,
	UP = 8,
	UPRIGHT = 9
};

enum ErrorCode {
	ERR_SUCCESS = 0,
	ERR_ILLEGAL_CONFIG_DATA = 1,
	ERR_POINT_OUTSIDE_OF_MAXIMUM_RANGE,
	ERR_POINTS_TOO_CLOSE_TO_EACH_OTHER
};

#endif // H_ENUMS_H