#pragma once
#include<cstdint>
#include <string>
#include <fstream>
#include <vector>
#include"Mapper_000.h"

class Cartridge
{
public:
	Cartridge(const std::string& fileName);
	~Cartridge();

	bool cpuRead(uint16_t addr, uint8_t& data);
	bool cpuWrite(uint16_t addr, uint8_t data);

	// PPU Bus communication
	bool ppuRead(uint16_t addr, uint8_t& data);
	bool ppuWrite(uint16_t addr, uint8_t data);

private:
	std::vector<uint8_t> PRGMemory;
	std::vector<uint8_t> CHRMemory;

	uint8_t mapperId = 0;
	uint8_t PRGBanks = 0;
	uint8_t CHRBanks = 0;
	std::shared_ptr<Mapper> mapper;
	
};

