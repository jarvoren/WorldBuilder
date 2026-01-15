#ifndef ENUMS_H
#define ENUMS_H

enum class GroundTag
{
	Base = 1,
	Volcanic,
	Desert,
	Beach,
	Coral,
	BlackEarth,
	Last,

};

enum class GeneratorPass
{
	PoissonPlateStartersPopulation,
};

enum class PlateDensity
{
	High = 1,
	Normal,
	Low,
	Last,
};

enum class PlateType
{
	Major = 1,
	Minor
};

enum class ErrorCode
{
	Succes = 0,
	GeneralFailure,

};

enum class LogLevel
{
	INFO,
	WARNING,
	ERROR
};

#endif // ENUMS_H
