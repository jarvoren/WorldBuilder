#ifndef H_GENEREATOR_FACTORY_H
#define H_GENEREATOR_FACTORY_H

#include <generators/generator.h>
#include <generators/square_grid_generator.h>

Generator* GeneratorFactory(WorldConfig* cfg);

#endif // H_GENEREATOR_FACTORY_H