#include "passgenerators/passtranslator.h"

std::unique_ptr<PassObject> PassTranslator::GetPassObject(GeneratorPass generatorEnum)
{

	switch (generatorEnum)
	{
	case GeneratorPass::PoissonPlateStartersPopulation:
		return std::make_unique<PoissonPlate>();
	}
	return nullptr;
}
