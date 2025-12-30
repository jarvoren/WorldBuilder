#ifndef ENUMS_H
#define ENUMS_H

enum class GroundTag {
	Base = 1,
	Volcanic,
	Desert,
	Beach,
	Coral,
	BlackEarth

};

enum class GeneratorPass {
	PoissonPlateStartersPopulation,
};

enum class PlateDensity {
	High,
	Normal,
	Low,
};

enum class ErrorCode {
	Succes = 0,
	GeneralFailure,

};
#endif // ENUMS_H
