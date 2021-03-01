#pragma once
#include <cstdint>
#include <memory>
#include "Cartridge.h"
class jv2C02
{
public:
	jv2C02();
	~jv2C02();

private:
	uint8_t tblName[2][1024];
	uint8_t tblPalette[32];

public:
	// main Bus communication
	uint8_t cpuRead(uint16_t addr, bool rdonly = false);
	void cpuWrite(uint16_t addr, uint8_t data);

	// PPU Bus communication
	uint8_t ppuRead(uint16_t addr, bool rdonly = false);
	void ppuWrite(uint16_t addr, uint8_t data);


	//Interface 
	void ConnectCartridge(const std::shared_ptr<Cartridge>& cartridge);
	void clock();

private:
	//Cartridge
	std::shared_ptr<Cartridge> cart;
};

