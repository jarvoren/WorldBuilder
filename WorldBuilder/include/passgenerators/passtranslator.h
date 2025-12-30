#include "descriptors/enums.h"
#include "passgenerators/passobject.h"
#include "passgenerators/poissonplate.h"
#include <memory>

class PassTranslator
{
  public:
	static std::unique_ptr<PassObject> GetPassObject(GeneratorPass generatorEnum);
};
