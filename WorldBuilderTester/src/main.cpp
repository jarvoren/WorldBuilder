#include "descriptors/enums.h"
#include <WorldBuilder.h>
#include <iostream>

int main() {
	WorldBuilder wb;
	if (wb.configure(ConfigData()) == ErrorCode::Succes)
		std::cout << "configured" << std::endl;
	return 0;
}
