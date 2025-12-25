#include <generators/tectonics/tectonic_plate.h>

TectonicPlate::TectonicPlate() {
	density = 0;
	type = OCEANIC;
	direction = NumpadDirections::NOONE;
}

TectonicPlate::~TectonicPlate() {
	// INTRODUCE RANDOMIZEE BEFORE RANDOMIZING THE PLATES
}
